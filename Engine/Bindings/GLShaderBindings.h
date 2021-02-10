#ifndef SDL2OPENGL_GLSHADERBINDINGS_H
#define SDL2OPENGL_GLSHADERBINDINGS_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/mat4x4.hpp>
#include <string>

/// @brief Everything that is related to OpenGL shader operations.
class GLShaderBindings
{
public:

private:

public:
    /// @brief Deletes the shader program object.
    /// @throw GLErrorException OpenGL was unable to delete shader program object.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_VALUE is generated if program is not a value generated by OpenGL.
    /// @param shaderProgramPointer Pointer to shader program object.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glDeleteProgram.xhtml">glDeleteProgram</a>
    static void deleteProgram(GLuint shaderProgramPointer);
    /// @brief Creates the shader program object.
    /// @throw GLErrorException OpenGL was unable to create shader program object.<br/>
    /// Possible reasons:<br/>
    /// OpenGL returned 0 as pointer.
    /// @return Shader program object pointer.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glCreateProgram.xhtml">glCreateProgram</a>
    static GLuint createProgram();
    /// @brief Makes shader program as current shader program.
    /// @throw GLErrorException OpenGL was unable to bind shaderProgramPointer to OpenGL state.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_VALUE is generated if shaderProgramPointer is neither 0 nor a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer is not a program object.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer could not be made part of current state.<br/>
    /// GL_INVALID_OPERATION is generated if transform feedback mode is active.
    /// @param shaderProgramPointer shader object type. Should be GL_VERTEX_SHADER, GL_FRAGMENT_SHADER
    /// or anything that OpenGL can digest.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUseProgram.xhtml">glUseProgram</a>
    static void useProgram(const GLuint shaderProgramPointer);
    /// @brief Creates shader object pointer.
    /// @throw GLErrorException OpenGL was unable to create shader object pointer.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_ENUM is generated if shaderType is not an accepted value.
    /// @throw GLErrorException OpenGL returned 0 as shader object pointer.<br/>
    /// @param shaderType shader object type. Should be GL_VERTEX_SHADER, GL_FRAGMENT_SHADER
    /// or anything that OpenGL can digest.
    /// @return Shader object pointer.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glCreateShader.xhtml">glCreateShader</a>
    static GLuint createShader(const GLenum shaderType);
    /// @brief Uploads shader object's source code to OpenGL.
    /// @throw GLErrorException OpenGL was unable to upload source.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_VALUE is generated if shaderObjectPointer is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderObjectPointer is not a shader object.
    /// @param shaderObjectPointer OpenGL pointer to shader object.
    /// @param source Shader object source code.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glShaderSource.xhtml">glShaderSource</a>
    static void uploadSource(const GLuint shaderObjectPointer, const std::string &source);
    /// @brief Compile shader object(Do not confuse with shader program)
    /// @throw ShaderErrorException if OpenGL was unable to compile shader object.
    /// @throw GLErrorException if glCompileShader errored(Unable to compile shader)<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_VALUE is generated if shaderObjectPointer is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderObjectPointer is not a shader object.
    /// @throw GLErrorException if glGetShaderiv errored(Unable to get compilation status)<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_VALUE is generated if shader is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shader does not refer to a shader object.
    /// @param shaderObjectPointer OpenGL pointer to shader object.
    /// @param shaderType OpenGL shader object type. Should be GL_FRAGMENT_SHADER, GL_VERTEX_SHADER
    /// or anything OpenGL can digest.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glCompileShader.xhtml">glCompileShader</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetShader.xhtml">glGetShaderiv</a>
    static void compileShader(GLuint shaderObjectPointer, GLenum shaderType);
    /// @brief Attach shader to shader program.
    /// @throw GLErrorException if OpenGL was unable to attach shader to shader program.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_VALUE is generated if either shaderProgramPointer or shaderPointer is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer is not a program object.<br/>
    /// GL_INVALID_OPERATION is generated if shaderPointer is not a shader object.<br/>
    /// GL_INVALID_OPERATION is generated if shaderPointer is already attached to program.
    /// @param shaderProgramPointer OpenGL pointer to shader program.
    /// @param shaderPointer OpenGL pointer to shader(Do not confuse with shader program)
    /// @param shaderType Shader type. May be GL_VERTEX_SHADER, GL_FRAGMENT_SHADER or other if OpenGL can digest it.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glAttachShader.xhtml">glAttachShader</a>.
    static void attachShader(const GLuint shaderProgramPointer, const GLuint shaderPointer, const GLenum shaderType);
    /// @brief Delete OpenGL shader object(Do not confuse with shader program)
    /// @throw GLErrorException if shaderObjectPointer is invalid.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_VALUE is generated if shaderObjectPointer is not a value generated by OpenGL.
    /// @param shaderObjectPointer Pointer to a shader program(Do not confuse with shader which is part of shader program).
    /// @param shaderType Shader type(Do not confuse with shader program). Should be GL_VERTEX_SHADER,
    /// GL_FRAGMENT_SHADER or anything else if OpenGL would digest it.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glDeleteShader.xhtml">glDeleteShader</a>.
    static void deleteShader(const GLuint shaderObjectPointer, const GLenum shaderType);
    /// @brief Get pointer to OpenGL attribute location in shader.
    /// @throw GLErrorException if shaderProgramPointer is invalid
    /// (for <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glLinkProgram.xhtml">
    /// glLinkProgram
    /// </a>):<br/>
    /// GL_INVALID_VALUE is generated if shaderProgramPointer is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer is not a program object.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer is the currently active program object and transform feedback mode is active.
    /// @throw GLErrorException if OpenGL was unable to get link status.(for <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetProgram.xhtml">
    ///  glGetProgramiv
    ///  </a>):<br/>
    /// GL_INVALID_VALUE is generated if shaderProgramPointer is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer does not refer to a program object.
    /// @param shaderProgramPointer Pointer to a shader program(Do not confuse with shader object which is part of shader program).
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glLinkProgram.xhtml">glLinkProgram</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetProgram.xhtml">glGetProgramiv</a>.
    static void linkProgram(const GLuint shaderProgramPointer);
    /// @brief Get pointer to OpenGL attribute location in shader.
    /// @throw GLErrorException if returned attribute location is -1(Not found)
    /// @throw GLErrorException if OpenGL was unable to get attribute location.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer is not a program object.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer has not been successfully linked.
    /// @param shaderProgramPointer Pointer to a shader program(Do not confuse with shader object which is part of shader program).
    /// @param attributeName Name of attribute variable in shader source.
    /// @return Pointer to attribute location in shader.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetAttribLocation.xhtml">glGetAttribLocation</a>.
    static GLuint getAttributeLocation(const GLuint shaderProgramPointer, const std::string &attributeName);
    /// @brief Get pointer to OpenGL uniform location in shader.
    /// @throw GLErrorException if returned uniform location is -1(Not found)
    /// @throw GLErrorException if OpenGL was unable to get uniform location.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_VALUE is generated if shaderProgramPointer is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer is not a program object.<br/>
    /// GL_INVALID_OPERATION is generated if shaderProgramPointer has not been successfully linked.
    /// @param shaderProgramPointer Pointer to a shader program(Do not confuse with shader object which is part of shader program)
    /// @param uniformName Name of uniform variable in shader source.
    /// @return Pointer to unifrom location in shader.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetUniformLocation.xhtml">glGetUniformLocation</a>.
    static GLuint getUniformLocation(const GLuint shaderProgramPointer, const std::string &uniformName);
    /// @brief Upload a GLint to the shader uniform(aka global) variable.
    /// @throw GLErrorException if uniform variable upload fails.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_OPERATION is generated if there is no current program object.<br/>
    /// GL_INVALID_OPERATION is generated if the size of the uniform variable declared in the shader does not match the
    /// size indicated by the glUniform command.<br/>
    /// GL_INVALID_OPERATION is generated if uniformPointer is an invalid uniform location for the current program
    /// object and location is not equal to -1.<br/>
    /// List of errors may not be complete. Refer to the
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUniform.xhtml">Khronos documentation page</a>.
    /// @param uniformPointer Pointer to shader uniform location.
    /// @param value Value that should be uploaded.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUniform.xhtml">glUniform1i</a>.
    static void setUniform(const GLint uniformPointer, const GLint value);
    /// @brief Upload a GLfloat to the shader uniform(aka global) variable.
    /// @throw GLErrorException if uniform variable upload fails.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_OPERATION is generated if there is no current program object.<br/>
    /// GL_INVALID_OPERATION is generated if the size of the uniform variable declared in the shader does not match
    /// the size indicated by the glUniform command.<br/>
    /// GL_INVALID_OPERATION is generated if uniformPointer is an invalid uniform location for the current program
    /// object and location is not equal to -1.<br/>
    /// List of errors may not be complete. Refer to the
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUniform.xhtml">Khronos documentation page</a>.
    /// @param uniformPointer Pointer to shader uniform location.
    /// @param value Value that should be uploaded.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUniform.xhtml">glUniform1d</a>.
    static void setUniform(const GLint uniformPointer, const GLfloat value);
    /// @brief Upload a GLdouble to the shader uniform(aka global) variable.
    /// @throw GLErrorException if uniform variable upload fails.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_OPERATION is generated if there is no current program object.<br/>
    /// GL_INVALID_OPERATION is generated if the size of the uniform variable declared in the shader does not
    /// match the size indicated by the glUniform command.<br/>
    /// GL_INVALID_OPERATION is generated if uniformPointer is an invalid uniform location for the current
    /// program object and location is not equal to -1.<br/>
    /// List of errors may not be complete. Refer to the
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUniform.xhtml">Khronos documentation page</a>.
    /// @param uniformPointer Pointer to shader uniform location.
    /// @param value Value that should be uploaded.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUniform.xhtml">glUniform1d</a>.
    static void setUniform(const GLint uniformPointer, const GLdouble value);
    /// @brief Upload a Matrix 4x4 to the shader uniform(aka global) variable.
    /// @throw GLErrorException if uniform variable upload fails.<br/>
    /// Possible reasons:<br/>
    /// GL_INVALID_OPERATION is generated if there is no current program object.<br/>
    /// GL_INVALID_OPERATION is generated if the size of the uniform variable declared in the shader does not match the size indicated by the glUniform command.<br/>
    /// GL_INVALID_OPERATION is generated if uniformPointer is an invalid uniform location for the current program object and location is not equal to -1.<br/>
    /// List of errors may not be complete. Refer to the <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUniform.xhtml">Khronos documentation page</a>.
    /// @param uniformPointer Pointer to shader uniform location.
    /// @param value Matrix 4x4 that should be uploaded to shader.
    /// @param shouldTranspose Should matrix be transposed.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glUniform.xhtml">glUniformMatrix4fv</a>.
    static void setUniformMatrix4(const GLint uniformPointer, const glm::mat4 &value, const GLboolean shouldTranspose);
private:
    GLShaderBindings() = default;

    /// @brief Prints shader log if there is generated log by OpenGL.
    /// @throw std::bad_alloc If log allocation fails.
    /// @throw GLErrorException if glGetShaderiv or glGetShaderInfoLog ends with error.<br/>
    /// glGetShaderiv:<br/>
    /// GL_INVALID_VALUE is generated if shaderId is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderId does not refer to a shader object.<br/>
    /// glGetShaderInfoLog:<br/>
    /// GL_INVALID_VALUE is generated if shaderId is not a value generated by OpenGL.<br/>
    /// GL_INVALID_OPERATION is generated if shaderId is not a shader object.<br/>
    /// GL_INVALID_VALUE is generated if maxLength is less than 0.<br/>
    /// @param shaderId OpenGL pointer to shader object(Do not confuse with shader program)
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetShaderInfoLog.xhtml">glGetShaderInfoLog</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetShader.xhtml">glGetShaderiv</a>.
    static void printGLShaderLogIfAny(GLuint shaderId);

};

#endif //SDL2OPENGL_GLSHADERBINDINGS_H
