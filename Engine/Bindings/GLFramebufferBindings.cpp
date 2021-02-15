#include "GLFramebufferBindings.h"
#include "../Incapsulated/GLError.h"

const GLuint GLFramebufferBindings::generateFramebuffer()
{
    GLuint pointer;

    glGenFramebuffers(1, &pointer);
    GLError::throwExceptionIfGLError("glGenFramebuffers");
    return pointer;
}

void GLFramebufferBindings::attachTexture2D(const GLenum target, const GLenum attachment, const GLenum textureTarget,
                                            const GLuint texturePointer, const GLint mipmapLevel)
{
    glFramebufferTexture2D(target, attachment, textureTarget, texturePointer, mipmapLevel);
    GLError::throwExceptionIfGLError("glFramebufferTexture2D");
}
