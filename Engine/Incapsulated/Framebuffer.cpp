#include "Framebuffer.h"
#include "../Bindings/GLFramebufferBindings.h"

void Framebuffer::initializeTextures()
{
    this->colorTexture = Texture2D(this->resolution.x, this->resolution.y, nullptr,
                                   GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, GL_FALSE);
    this->colorTexture.setMagnifyingFilter(GL_NEAREST, GL_FALSE);
    this->colorTexture.setMinifyingFilter(GL_NEAREST, GL_FALSE);
    this->depthStencilTexture = Texture2D(this->resolution.x, this->resolution.y, nullptr,
                                          GL_DEPTH24_STENCIL8, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, GL_TRUE);
    this->depthStencilTexture.setMagnifyingFilter(GL_NEAREST, GL_FALSE);
    this->depthStencilTexture.setMinifyingFilter(GL_NEAREST, GL_FALSE);
    GLTextureBindings::bindTexture(GL_TEXTURE_2D, 0);
}

Framebuffer::Framebuffer(const GLuint width, const GLuint height, const GLboolean unbind)
{
    this->initialize(width, height, unbind);
}

Framebuffer::Framebuffer(const glm::ivec2 resolution, const GLboolean unbind)
{
    this->initialize(resolution, unbind);
}

void Framebuffer::initialize(const GLuint width, const GLuint height, const GLboolean unbind)
{
    this->resolution = {width, height};
    this->initializeTextures();
    this->framebufferPointer = GLFramebufferBindings::generate();
    this->bind();
    GLFramebufferBindings::attachTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                                           GL_TEXTURE_2D, this->colorTexture.getPointer(), 0);
    GLFramebufferBindings::attachTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                                           GL_TEXTURE_2D, this->depthStencilTexture.getPointer(), 0);
    if (unbind)
        this->unbind();
}

void Framebuffer::initialize(const glm::ivec2 resolution, const GLboolean unbind)
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

void Framebuffer::bind() const
{
    GLFramebufferBindings::bind(GL_FRAMEBUFFER, this->framebufferPointer);
}

void Framebuffer::unbind() const
{
    GLFramebufferBindings::bind(GL_FRAMEBUFFER, 0);
}
