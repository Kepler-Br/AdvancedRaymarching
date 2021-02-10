#include "GLShaderBindings.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include "../Incapsulated/GLError.h"
#include "../Exceptions/ShaderErrorException.h"

void GLShaderBindings::printGLShaderLogIfAny(GLuint shaderId)
{
    GLint logLength = 0;
    GLchar *log;

    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);
    GLError::throwExceptionIfGLError("printGLShaderLogIfAny glGetShaderiv");
    if (logLength == 0)
        return;
    log = new GLchar[logLength];
    glGetShaderInfoLog(shaderId, logLength, &logLength, log);
    GLError::throwExceptionIfGLError("printGLShaderLogIfAny glGetShaderInfoLog");
    std::cout << log << std::endl;
    delete log;
}

void GLShaderBindings::deleteProgram(GLuint shaderProgramPointer)
{
    glDeleteProgram(shaderProgramPointer);
    GLError::throwExceptionIfGLError("glDeleteProgram");
}

GLuint GLShaderBindings::createProgram()
{
    GLuint shaderProgram;

    shaderProgram = glCreateProgram();
    if (shaderProgram == 0)
        throw GLErrorException("glCreateProgram returned 0.");
    return shaderProgram;
}

void GLShaderBindings::useProgram(const GLuint shaderProgramPointer)
{
    glUseProgram(shaderProgramPointer);
    GLError::throwExceptionIfGLError("glUseProgram");
}

GLuint GLShaderBindings::createShader(const GLenum shaderType)
{
    const GLuint shader = glCreateShader(shaderType);

    if (shader == 0)
        throw GLErrorException("glCreateShader shader object pointer is zero.");
    GLError::throwExceptionIfGLError("glCreateShader");
    return shader;
}

void GLShaderBindings::uploadSource(const GLuint shaderObjectPointer, const std::string &source)
{
    const char *cSource = source.c_str();
    glShaderSource(shaderObjectPointer, 1, &cSource, nullptr);
    GLError::throwExceptionIfGLError("glShaderSource");
}

void GLShaderBindings::compileShader(GLuint shaderObjectPointer, GLenum shaderType)
{
    GLint success = GL_FALSE;

    glCompileShader(shaderObjectPointer);
    GLError::throwExceptionIfGLError("glCompileShader");
    glGetShaderiv(shaderObjectPointer, GL_COMPILE_STATUS, &success);
    GLError::throwExceptionIfGLError("glGetShaderiv");
    if (success == GL_FALSE)
    {
        GLShaderBindings::printGLShaderLogIfAny(shaderObjectPointer);
        if (shaderType == GL_FRAGMENT_SHADER)
            throw ShaderErrorException("Cannot compile fragment shader.");
        else if (shaderType == GL_VERTEX_SHADER)
            throw ShaderErrorException("Cannot compile vertex shader.");
        else
            throw ShaderErrorException("Cannot compile UNK shader.");
    }
}

void GLShaderBindings::attachShader(const GLuint shaderProgramPointer, const GLuint shaderPointer, const GLenum shaderType)
{
    glAttachShader(shaderProgramPointer, shaderPointer);
    if (shaderType == GL_VERTEX_SHADER)
        GLError::throwExceptionIfGLError("glAttachShader vertex");
    else if (shaderType == GL_FRAGMENT_SHADER)
        GLError::throwExceptionIfGLError("glAttachShader fragment");
    GLError::throwExceptionIfGLError("glAttachShader other");
}

void GLShaderBindings::deleteShader(const GLuint shaderObjectPointer, const GLenum shaderType)
{
    glDeleteShader(shaderObjectPointer);
    if (shaderType == GL_VERTEX_SHADER)
        GLError::throwExceptionIfGLError("glDeleteShader vertex");
    else if (shaderType == GL_FRAGMENT_SHADER)
        GLError::throwExceptionIfGLError("glDeleteShader fragment");
    else
        GLError::throwExceptionIfGLError("glDeleteShader UNK");
}

void GLShaderBindings::linkProgram(const GLuint shaderProgramPointer)
{
    GLint isLinked = 1;

    glLinkProgram(shaderProgramPointer);
    GLError::throwExceptionIfGLError("glLinkProgram");
    glGetProgramiv(shaderProgramPointer, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE)
    {
        GLShaderBindings::printGLShaderLogIfAny(shaderProgramPointer);
        throw ShaderErrorException("Shader link failure.");
    }
}

GLuint GLShaderBindings::getAttributeLocation(const GLuint shaderProgramPointer, const std::string &attributeName)
{
    const GLint attributeLocation = glGetAttribLocation(shaderProgramPointer, attributeName.c_str());
    if (attributeLocation == -1)
        throw GLErrorException("glGetAttribLocation returned -1.");
    GLError::throwExceptionIfGLError("glGetAttribLocation");
    return attributeLocation;
}

GLuint GLShaderBindings::getUniformLocation(const GLuint shaderProgramPointer, const std::string &uniformName)
{
    const GLint uniformLocation = glGetUniformLocation(shaderProgramPointer, uniformName.c_str());
    if (uniformLocation == -1)
        throw GLErrorException("glGetUniformLocation returned -1.");
    GLError::throwExceptionIfGLError("glGetUniformLocation");
    return uniformLocation;
}


void GLShaderBindings::setUniform(const GLint uniformPointer, const GLint value)
{
    glUniform1i(uniformPointer, value);
    GLError::throwExceptionIfGLError("Cannot set value(GLint) from undefined uniform location");
}

void GLShaderBindings::setUniform(const GLint uniformPointer, const GLfloat value)
{
    glUniform1f(uniformPointer, value);
    GLError::throwExceptionIfGLError("Cannot set value(GLfloat) from undefined uniform location");
}

void GLShaderBindings::setUniform(const GLint uniformPointer, const GLdouble value)
{
    glUniform1d(uniformPointer, value);
    GLError::throwExceptionIfGLError("Cannot set value(GLdouble) from undefined uniform location");
}

void GLShaderBindings::setUniformMatrix4(const GLint uniformPointer, const glm::mat4 &value, const GLboolean shouldTranspose)
{
    static const GLsizei matricesCount = 1;

    glUniformMatrix4fv(uniformPointer, matricesCount, shouldTranspose, glm::value_ptr(value));
    GLError::throwExceptionIfGLError("Cannot set value(glm::mat4) from undefined uniform location");
}
