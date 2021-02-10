#ifndef SDL2OPENGL_GLVERTEXARRAYOBJECT_H
#define SDL2OPENGL_GLVERTEXARRAYOBJECT_H

#include <GL/glew.h>
#include <GL/gl.h>

/// @brief Encapsulation over OpenGL Vertex Array Object.
class GLVertexArrayObject
{
public:

private:
    GLuint object;

public:
    /// @brief Constructor that generates OpenGL VAO.
    /// @throw GLErrorException if VAO generation was unsuccessful.
    /// @see GLBufferBindings::generateVertexArray<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGenVertexArrays.xhtml">glGenVertexArrays</a>
    GLVertexArrayObject();

    /// @brief Bind VAO to OpenGL.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBindVertexArray.xhtml">glBindVertexArray</a>
    void bind() const noexcept;
    /// @brief Unbind VAO from OpenGL. In other words bind VAO number 0.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBindVertexArray.xhtml">glBindVertexArray</a>
    void unbind() const noexcept;
private:

};

#endif //SDL2OPENGL_GLVERTEXARRAYOBJECT_H
