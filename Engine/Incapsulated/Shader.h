#ifndef SDL2OPENGL_SHADER_H
#define SDL2OPENGL_SHADER_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <map>

/// @brief Encapsulation over OpenGL shader routine.
class Shader
{
public:

private:
    GLuint shaderProgram = 0;
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;
    std::map<std::string, GLint> uniformLocations;
    std::map<std::string, GLint> attributeLocations;

public:
    /// @see Shader::initialize.
    Shader(const std::string &vertexPath, const std::string &fragmentPath);
    Shader() = default;
    /// @brief Load, compile and link shader program.
    /// @param vertexPath Path to vertex shader.
    /// @param fragmentPath Path to fragment shader.
    /// @throw std::runtime_error if shader was already initialized.
    /// @throw std::runtime_error if class was unable to read shader from the disk.
    /// @throw GLErrorException if OpenGL was unable to compile or link shader program.
    /// @see GLShaderBindings::createProgram, GLShaderBindings::deleteShader, GLShaderBindings::uploadSource,
    /// GLShaderBindings::uploadSource, GLShaderBindings::compileShader, GLShaderBindings::attachShader,
    /// GLShaderBindings::linkProgram, GLShaderBindings::deleteShader<br/>
    /// Shader::compile, Shader::link<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glDeleteShader.xhtml">glDeleteShader</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glCreateShader.xhtml">glCreateShader</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glCreateProgram.xhtml">glCreateProgram</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glShaderSource.xhtml">glShaderSource</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glCompileShader.xhtml">glCompileShader</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetShader.xhtml">glGetShaderiv</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glLinkProgram.xhtml">glLinkProgram</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetProgram.xhtml">glGetProgramiv</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glAttachShader.xhtml">glAttachShader</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glDeleteShader.xhtml">glDeleteShader</a>
    void initialize(const std::string &vertexPath, const std::string &fragmentPath);
    /// @brief Deletes OpenGL shader program.
    /// @throw std::runtime_error if shader was not initialized.
    /// @see GLShaderBindings::deleteProgram<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glDeleteProgram.xhtml">glDeleteProgram</a>
    void destroy();
    /// @brief Tells OpenGL that we want to use current shader.
    /// @throw GLErrorException if shader program pointer is invalid.
    /// @see GLShaderBindings::useProgram<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUseProgram.xhtml">glUseProgram</a>
    void use() const;
    /// @brief Returns OpenGL pointer to the shader program.
    /// @return OpenGL pointer to the shader program.
    GLuint getShaderProgram() const noexcept;
    /// @brief Returns OpenGL attribute pointer to corresponding variable name in the shader. Cached.
    /// @param attributeName Attribute variable name in the shader.
    /// @return OpenGL pointer to that attribute location.
    /// @throw GLErrorException if attribute name was not found in the shader.
    /// @see GLShaderBindings::getAttributeLocation<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetAttribLocation.xhtml">getAttributeLocation</a>
    GLint getAttributeLocation(const std::string &attributeName);
    /// @brief Returns OpenGL uniform pointer to corresponding variable name in the shader. Cached.
    /// @param uniformName Uniform (aka global) variable name in the shader.
    /// @return OpenGL pointer to that uniform location.
    /// @throw GLErrorException if uniform name was not found in the shader or other OpenGL error.
    /// @see GLShaderBindings::getUniformLocation.<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetUniformLocation.xhtml">glGetUniformLocation</a>
    GLint getUniformLocation(const std::string &uniformName);


private:
    /// @brief Returns OpenGL uniform pointer to corresponding variable name in the shader. Cached.
    /// @param source Shader (fragment or vertex) source code.
    /// @param shaderType Shader type. Should be GL_FRAGMENT_SHADER or GL_VERTEX_SHADER.
    /// Otherwise exception will be thrown.
    /// @return OpenGL pointer to shader(Do not confuse with shader program. It's just a part of shader program.).
    /// @throw std::runtime_error if shaderType is unknown type(Not GL_FRAGMENT_SHADER or GL_VERTEX_SHADER).
    /// @throw GLErrorException if either GLShaderBindings::createShader,
    /// GLShaderBindings::uploadSource or GLShaderBindings::compileShader fails.
    /// @see GLShaderBindings::uploadSource, GLShaderBindings::compileShader, GLShaderBindings::createShader<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glCreateShader.xhtml">glCreateShader</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glShaderSource.xhtml">glShaderSource</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glCompileShader.xhtml">glCompileShader</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetShader.xhtml">glGetShaderiv</a>
    static GLuint compile(const std::string &source, GLenum shaderType);
    /// @brief Links vertex shader and fragment shader together.
    /// @throw GLErrorException if either GLShaderBindings::attachShader or GLShaderBindings::linkProgram fails.
    /// @see GLShaderBindings::attachShader, GLShaderBindings::linkProgram<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glAttachShader.xhtml">glAttachShader</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glLinkProgram.xhtml">glLinkProgram</a>
    void link() const;
};

#endif //SDL2OPENGL_SHADER_H
