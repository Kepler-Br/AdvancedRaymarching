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
    Framebuffer(const GLuint width, const GLuint height, GLboolean unbind = GL_TRUE);

    Framebuffer(const glm::ivec2 resolution, GLboolean unbind = GL_TRUE);

    Framebuffer() = default;

    void initialize(const GLuint width, const GLuint height, GLboolean unbind = GL_TRUE);

    void initialize(const glm::ivec2 resolution, GLboolean unbind = GL_TRUE);

    const GLuint getPointer() const;

    const glm::ivec2 getResolution() const;

};


#endif //SDL2OPENGL_GLFRAMEBUFFER_H
