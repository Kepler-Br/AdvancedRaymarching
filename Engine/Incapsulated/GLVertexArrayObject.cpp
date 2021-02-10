#include "GLVertexArrayObject.h"
#include "../Bindings/GLBufferBindings.h"

GLVertexArrayObject::GLVertexArrayObject()
{
    this->object = GLBufferBindings::generateVertexArray();
}

void GLVertexArrayObject::bind() const noexcept
{
    glBindVertexArray(this->object);
}

void GLVertexArrayObject::unbind() const noexcept
{
    glBindVertexArray(0);
}
