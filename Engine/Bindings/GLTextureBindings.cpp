#include "GLTextureBindings.h"

GLuint GLTextureBindings::generateTexture()
{
    static const GLsizei textureNumber = 1;
    GLuint texturePointer;

    glGenTextures(textureNumber, &texturePointer);
    GLError::throwExceptionIfGLError("Cannot generate texture pointer");
    return texturePointer;
}

void GLTextureBindings::bindTexture(GLenum target, GLuint texturePointer)
{
    glBindTexture(target, texturePointer);
    GLError::throwExceptionIfGLError("Cannot generate texture pointer");
}

void GLTextureBindings::uploadTexture2D(const GLenum target, const GLint levelOfDetail, GLenum internalTextureColorFormat,
                                        const GLsizei width, const GLsizei height, const GLenum textureColorFormat,
                                        const GLenum dataType, const GLvoid *data)
{
    static const GLint border = 0;

    glTexImage2D(target, levelOfDetail, internalTextureColorFormat,
                 width, height, border, textureColorFormat, dataType, data);
    GLError::throwExceptionIfGLError("Cannot upload texture to GPU");
}

void GLTextureBindings::generateMipmap(const GLenum textureTarget)
{
    glGenerateMipmap(textureTarget);
    GLError::throwExceptionIfGLError("Cannot generate Mipmap");
}

void GLTextureBindings::setParameterInt(const GLenum textureTarget, const GLenum parameterName, const GLint parameter)
{
    glTexParameteri(textureTarget, parameterName, parameter);
    GLError::throwExceptionIfGLError("Cannot set texture parameter");
}
