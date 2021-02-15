#ifndef ADVANCEDRAYMARCHING_GLFRAMEBUFFERBINDINGS_H
#define ADVANCEDRAYMARCHING_GLFRAMEBUFFERBINDINGS_H

#include <GL/glew.h>
#include <GL/gl.h>

/// @todo Write documentation.
class GLFramebufferBindings {
private:
    GLFramebufferBindings() = default;

public:
    static const GLuint generateFramebuffer();
    static void attachTexture2D(const GLenum target, const GLenum attachment, const GLenum textureTarget,
                                const GLuint texturePointer, const GLint mipmapLevel);
};


#endif //ADVANCEDRAYMARCHING_GLFRAMEBUFFERBINDINGS_H
