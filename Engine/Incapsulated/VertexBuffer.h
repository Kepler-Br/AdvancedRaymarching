#ifndef SDL2OPENGL_GLBUFFER_H
#define SDL2OPENGL_GLBUFFER_H

#include <GL/glew.h>
#include <vector>
#include <cstring>
#include <stdexcept>
#include "VertexBuffer.h"
#include "GLError.h"
#include "../Bindings/GLBufferBindings.h"

/// @brief Encapsulated OpenGL's Vertex Buffer Object capable of uploading data to GPU.
/// @tparam T should only be simple types like int, double, float.
template <typename T>
class VertexBuffer
{
private:
    GLenum target = 0;
    GLuint glBufferPointer = 0;
    T *array = nullptr;

public:
    /// @see VertexBuffer::initialize
    VertexBuffer(std::vector<T> array, const GLenum target, const GLenum usage, GLboolean unbind = GL_TRUE)
    {
        this->initialize(array, target, usage);
    }

    /// @see VertexBuffer::initialize
    VertexBuffer(const T *array, const size_t arraySize, const GLenum target, const GLenum usage, GLboolean unbind = GL_TRUE)
    {
        this->initialize(array, arraySize, target, usage);
    }

    VertexBuffer() = default;

    /// @brief Initialize internal array from input array and upload it to GPU.
    /// @param array Input array that should be uploaded to GPU.
    /// @param arraySize Size of the input array.
    /// @param target Specifies the target to which the buffer object is bound. Example: GL_ARRAY_BUFFER.
    /// @param usage Specifies the expected usage pattern of the data store. Example: GL_STATIC_DRAW, GL_STREAM_DRAW.
    /// @param unbind Indicates whether this member function should unbind GPU array after uploading data.
    /// @see GLBufferBindings::generateBuffer, GLBufferBindings::uploadDataToBuffer<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGenBuffers.xhtml">glGenBuffers</a>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBufferData.xhtml">glBufferData</a><br/>
    /// @throw std::runtime_error if buffer was already initialized.<br/>
    /// @throw GLErrorException from GLBufferBindings::generateBuffer and GLBufferBindings::uploadDataToBuffer.
    void initialize(const T *array, const size_t arraySize, const GLenum target, const GLenum usage, GLboolean unbind = GL_TRUE)
    {
        if (this->array != nullptr)
            throw std::runtime_error("Cannot initialize VertexBuffer twice.");
        this->target = target;
        this->array = new T[arraySize];
        std::memcpy(this->array, array, arraySize * sizeof(T));
        this->glBufferPointer = GLBufferBindings::generateBuffer();
        this->bind();
        GLBufferBindings::uploadDataToBuffer<T>(this->array, arraySize * sizeof(T), target, usage);
        if (unbind)
            this->unbind();
    }

    /// @brief Initialize internal array from input vector and upload it to GPU.
    /// @param array Input vector that should be uploaded to GPU.
    /// @param target Specifies the target to which the buffer object is bound. Example: GL_ARRAY_BUFFER.
    /// @param usage Specifies the expected usage pattern of the data store. Example: GL_STATIC_DRAW, GL_STREAM_DRAW.
    /// @param unbind Indicates whether this member function should unbind GPU array after uploading data.
    /// @see GLBufferBindings::generateBuffer, GLBufferBindings::uploadDataToBuffer<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGenBuffers.xhtml">glGenBuffers</a>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBufferData.xhtml">glBufferData</a><br/>
    /// @throw std::runtime_error if buffer was already initialized.<br/>
    /// @throw GLErrorException from GLBufferBindings::generateBuffer and GLBufferBindings::uploadDataToBuffer.
    void initialize(std::vector<T> array, const GLenum target, const GLenum usage, GLboolean unbind = GL_TRUE)
    {
        const size_t arraySize = array.size();

        if (this->array != nullptr)
            throw std::runtime_error("Cannot initialize VertexBuffer twice.");
        this->target = target;
        this->array = new T[arraySize];
        std::memcpy(this->array, array.data(), arraySize);
        this->glBufferPointer = GLBufferBindings::generateBuffer();
        this->bind();
        GLBufferBindings::uploadDataToBuffer<T>(this->array, arraySize * sizeof(T), target, usage);
        if (unbind)
            this->unbind();
    }

    /// @brief Bind this buffer to OpenGL.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBindBuffer.xhtml">glBindBuffer</a>
    /// @throw GLErrorException from GLError::throwExceptionIfGLError.
    void bind() const
    {
        glBindBuffer(target, this->glBufferPointer);
        GLError::throwExceptionIfGLError();
    }

    /// @brief Unbind this buffer from OpenGL. In other words bind buffer 0.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBindBuffer.xhtml">glBindBuffer</a>
    void unbind() const noexcept
    {
        glBindBuffer(target, 0);
    }

    /// @brief Delete array, GPU buffer and reset member variables.
    /// @see GLBufferBindings::deleteBuffer<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glDeleteBuffers.xhtml">glDeleteBuffers</a>
    /// @throw std::runtime_error if VertexBuffer#array is nullptr. In other words instance is not initialized.<br>
    /// @throw GLErrorException from GLBufferBindings::deleteBuffer.
    void destroy()
    {
        if (this->array == nullptr)
            throw std::runtime_error("Cannot destroy VertexBuffer twice.");
        delete[] this->array;
        this->array = nullptr;
        GLBufferBindings::deleteBuffer(this->glBufferPointer);
        this->glBufferPointer = 0;
    }
};

#endif //SDL2OPENGL_GLBUFFER_H
