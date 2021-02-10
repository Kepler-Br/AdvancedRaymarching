#include <tuple>
#include "../Exceptions/ShaderErrorException.h"
#include "Shader.h"
#include "../Bindings/GLShaderBindings.h"
#include "../IO/IO.h"

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath)
{
    this->initialize(vertexPath, fragmentPath);
}

void Shader::initialize(const std::string &vertexPath, const std::string &fragmentPath)
{
    const IIO *io = IO::getInstance();
    const std::string vertexSource = io->readWholeFileAsString(vertexPath);
    const std::string fragmentSource = io->readWholeFileAsString(fragmentPath);

    if (this->shaderProgram != 0)
        throw std::runtime_error("Cannot initialize shader twice.");
    this->shaderProgram = GLShaderBindings::createProgram();
    this->vertexShader = Shader::compile(vertexSource, GL_VERTEX_SHADER);
    this->fragmentShader = Shader::compile(fragmentSource, GL_FRAGMENT_SHADER);
    Shader::link();
    GLShaderBindings::deleteShader(this->vertexShader, GL_VERTEX_SHADER);
    GLShaderBindings::deleteShader(this->fragmentShader, GL_FRAGMENT_SHADER);
}

void Shader::destroy()
{
    glUseProgram(0);
    if (this->shaderProgram == 0)
        throw std::runtime_error("Shader is not initialized.");
    GLShaderBindings::deleteProgram(this->shaderProgram);
    std::tie(this->vertexShader, this->fragmentShader, this->shaderProgram) = std::make_tuple(0, 0, 0);
}

void Shader::use() const
{
    GLShaderBindings::useProgram(this->shaderProgram);
}

GLuint Shader::getShaderProgram() const noexcept
{
    return this->shaderProgram;
}

GLint Shader::getAttributeLocation(const std::string &attributeName)
{
    const auto &foundAttributeLocation = this->attributeLocations.find(attributeName);
    GLint attributeLocation;

    if (foundAttributeLocation != this->attributeLocations.end())
        return foundAttributeLocation->second;
    attributeLocation = GLShaderBindings::getAttributeLocation(this->shaderProgram, attributeName);
    if (attributeLocation == -1)
        throw GLErrorException("Cannot find shader attribute with name " + attributeName);
    this->attributeLocations[attributeName] = attributeLocation;
    return attributeLocation;
}

GLuint Shader::compile(const std::string &source, const GLenum shaderType)
{
    const GLuint shaderId = GLShaderBindings::createShader(shaderType);

    if (shaderType != GL_FRAGMENT_SHADER && shaderType != GL_VERTEX_SHADER)
        throw std::runtime_error("Cannot compile shader of unknown type.");
    GLShaderBindings::uploadSource(shaderId, source);
    GLShaderBindings::compileShader(shaderId, shaderType);
    return shaderId;
}

void Shader::link() const
{
    GLShaderBindings::attachShader(this->shaderProgram, this->vertexShader, GL_VERTEX_SHADER);
    GLShaderBindings::attachShader(this->shaderProgram, this->fragmentShader, GL_FRAGMENT_SHADER);
    GLShaderBindings::linkProgram(this->shaderProgram);
}

GLint Shader::getUniformLocation(const std::string &uniformName)
{
    const auto &foundUniformLocation = this->uniformLocations.find(uniformName);
    GLint uniformLocation;

    if (foundUniformLocation != this->uniformLocations.end())
        return foundUniformLocation->second;
    uniformLocation = GLShaderBindings::getUniformLocation(this->shaderProgram, uniformName);
    this->uniformLocations[uniformName] = uniformLocation;
    return uniformLocation;
}
