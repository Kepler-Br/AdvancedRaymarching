#include "Framebuffer.h"
#include "../Bindings/GLFramebufferBindings.h"

Framebuffer::Framebuffer(const GLuint width, const GLuint height, GLboolean unbind)
{
    this->initialize(width, height, unbind);
}

Framebuffer::Framebuffer(const glm::ivec2 resolution, GLboolean unbind)
{
    this->initialize(resolution, unbind);
}

void Framebuffer::initialize(const GLuint width, const GLuint height, GLboolean unbind)
{
    this->resolution = {width, height};
    this->colorTexture = Texture2D(width, height, nullptr,
                                   GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, GL_FALSE);
    this->depthStencilTexture = Texture2D(width, height, nullptr,
                                          GL_DEPTH24_STENCIL8, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, GL_TRUE);
    this->framebufferPointer = GLFramebufferBindings::generateFramebuffer();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                           GL_TEXTURE_2D, this->colorTexture.getPointer(), 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                           GL_TEXTURE_2D, this->depthStencilTexture.getPointer(), 0);
}

void Framebuffer::initialize(const glm::ivec2 resolution, GLboolean unbind)
{
    this->initialize(resolution.x, resolution.y, unbind);
}

const GLuint Framebuffer::getPointer() const
{
    if (framebufferPointer == 0)
        throw std::runtime_error("Framebuffer is not initialized.");
    return this->framebufferPointer;
}

const glm::ivec2 Framebuffer::getResolution() const
{
    if (framebufferPointer == 0)
        throw std::runtime_error("Framebuffer is not initialized.");
    return this->resolution;
}
