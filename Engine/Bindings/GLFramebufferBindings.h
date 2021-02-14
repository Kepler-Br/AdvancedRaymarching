#ifndef ADVANCEDRAYMARCHING_GLFRAMEBUFFERBINDINGS_H
#define ADVANCEDRAYMARCHING_GLFRAMEBUFFERBINDINGS_H

#include <GL/glew.h>
#include <GL/gl.h>

/// @todo Write documentation.
class GLFramebufferBindings {
private:
    GLFramebufferBindings() = default;

public:
    static const GLuint generateFramebuffer()
    {
        GLuint pointer;

        glGenFramebuffers(1, &pointer);
        GLError::throwExceptionIfGLError("glGenFramebuffers");
    }
};


#endif //ADVANCEDRAYMARCHING_GLFRAMEBUFFERBINDINGS_H
