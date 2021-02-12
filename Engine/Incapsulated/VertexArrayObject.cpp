#include "VertexArrayObject.h"
#include "../Bindings/GLBufferBindings.h"

VertexArrayObject::VertexArrayObject()
{
    this->object = GLBufferBindings::generateVertexArray();
}

void VertexArrayObject::bind() const noexcept
{
    glBindVertexArray(this->object);
}

void VertexArrayObject::unbind() const noexcept
{
    glBindVertexArray(0);
}
