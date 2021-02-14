#ifndef SDL2OPENGL_GLFRAMEBUFFER_H
#define SDL2OPENGL_GLFRAMEBUFFER_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec2.hpp>
#include "Texture2D.h"

/// @todo Write documentation.
class Framebuffer
{
private:
    GLuint framebufferPointer = 0;
    Texture2D colorTexture;
    Texture2D depthStencilTexture;
    glm::ivec2 resolution;

public:

private:

public:
    Framebuffer(const GLuint width, const GLuint height)
    {

    }

    Framebuffer(const glm::ivec2 resolution)
    {

    }

    Framebuffer() = default;

    void initialize(const GLuint width, const GLuint height)
    {
        this->resolution = {width, height};
        this->colorTexture = Texture2D(width, height, nullptr,
                                       GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, GL_FALSE);
        this->depthStencilTexture = Texture2D(width, height, nullptr,
                                              GL_DEPTH24_STENCIL8, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, GL_TRUE);
        glGenFramebuffers(1, &this->framebufferPointer);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                               GL_TEXTURE_2D, this->colorTexture.getPointer(), 0);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                               GL_TEXTURE_2D, this->depthStencilTexture.getPointer(), 0);
    }

    void initialize(const glm::ivec2 resolution)
    {
        this->initialize(resolution.x, resolution.y);
    }

    const GLuint getPointer() const
    {
        if (framebufferPointer == 0)
            throw std::runtime_error("Framebuffer is not initialized.");
        return this->framebufferPointer;
    }

    const glm::ivec2 getResolution() const
    {
        if (framebufferPointer == 0)
            throw std::runtime_error("Framebuffer is not initialized.");
        return this->resolution;
    }

};


#endif //SDL2OPENGL_GLFRAMEBUFFER_H
