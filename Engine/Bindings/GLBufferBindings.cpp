#include "GLBufferBindings.h"

GLuint GLBufferBindings::generateBuffer()
{
    GLuint bufferPointer;

    glGenBuffers(1, &bufferPointer);
    GLError::throwExceptionIfGLError("glGenBuffers");
    return bufferPointer;
}

void GLBufferBindings::deleteBuffer(const GLuint bufferPointer)
{
    glDeleteBuffers(1, &bufferPointer);
    GLError::throwExceptionIfGLError("glDeleteBuffers");
}

void GLBufferBindings::enableAttribute(GLuint attribute)
{
    glEnableVertexAttribArray(attribute);
    GLError::throwExceptionIfGLError("glEnableVertexAttribArray");
}

void GLBufferBindings::disableAttribute(GLuint attribute)
{
    glDisableVertexAttribArray(attribute);
    GLError::throwExceptionIfGLError("glDisableVertexAttribArray");
}

void GLBufferBindings::setupAttributePointer(const GLuint vertexAttributeIndex, const GLint vertexComponentCount,
                                             const GLenum dataType, const GLboolean shouldBeNormalized,
                                             const GLsizei dataStride, const GLvoid *dataOffset)
{
    glVertexAttribPointer(vertexAttributeIndex, vertexComponentCount, dataType,
                          shouldBeNormalized, dataStride, dataOffset);
    GLError::throwExceptionIfGLError("glVertexAttribPointer");
}

GLuint GLBufferBindings::generateVertexArray() {
    GLuint Vao;

    glGenVertexArrays(1, &Vao);
    GLError::throwExceptionIfGLError("glGenVertexArrays");
    return Vao;
}

void GLBufferBindings::bindVertexArray(const GLuint Vao) {
    glBindVertexArray(Vao);
    GLError::throwExceptionIfGLError("glBindVertexArray");
}
