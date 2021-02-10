#include "GLTexture2D.h"

GLTexture2D::GLTexture2D(const GLsizei width, const GLsizei height, const GLvoid *textureData,
                        const GLenum internalPixelFormat, const GLenum texturePixelFormat,
                        const GLenum dataType, const GLboolean unbind)
{
    this->initialize(width, height, textureData, internalPixelFormat, texturePixelFormat, dataType, unbind);
}

GLTexture2D::GLTexture2D(const std::tuple<glm::ivec2, std::vector<GLbyte>> &data, const GLenum internalPixelFormat,
                         const GLenum texturePixelFormat, const GLenum dataType, const GLboolean unbind)
{
    this->initialize(data, internalPixelFormat, texturePixelFormat, dataType, unbind);
}

void GLTexture2D::generateMipmap() const
{
    GLTextureBindings::generateMipmap(GL_TEXTURE_2D);
}

void GLTexture2D::setWrap(const GLint wrapMode, const GLboolean rebind) const
{
    if(rebind)
        this->bind();
    GLTextureBindings::setParameterInt(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    GLTextureBindings::setParameterInt(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    if(rebind)
        this->unbind();
}

void GLTexture2D::setMagnifyingFilter(const GLint filterType, const GLboolean rebind) const
{
    if(rebind)
        this->bind();
    GLTextureBindings::setParameterInt(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterType);
    if(rebind)
        this->unbind();
}

void GLTexture2D::setMinifyingFilter(const GLint filterType, const GLboolean rebind) const
{
    if(rebind)
        this->bind();
    GLTextureBindings::setParameterInt(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterType);
    if(rebind)
        this->unbind();
}

void GLTexture2D::bind() const
{
    GLTextureBindings::bindTexture(GL_TEXTURE_2D, this->texturePointer);
}

void GLTexture2D::unbind() const
{
    if (this->texturePointer == 0)
        throw std::runtime_error("Cannot destroy already destroyed texture.");
    glBindTexture(GL_TEXTURE_2D, 0);
}

void GLTexture2D::destroy()
{
    if (this->texturePointer == 0)
        throw std::runtime_error("Cannot destroy already destroyed texture.");
    glDeleteTextures(1, &this->texturePointer);
    this->texturePointer = 0;
}

void GLTexture2D::initialize(const GLsizei width, const GLsizei height, const GLvoid *textureData,
                             const GLenum internalPixelFormat, const GLenum texturePixelFormat,
                             const GLenum dataType, const GLboolean unbind)
{
    static const GLint levelOfDetail = 0;
    // Should be 0. Dunno why. Legacy.
    static const GLint border = 0;

    if (this->texturePointer != 0)
        throw std::runtime_error("Trying to initialize texture twice.");
    this->texturePointer = GLTextureBindings::generateTexture();
    this->bind();
    GLTextureBindings::uploadTexture2D(GL_TEXTURE_2D, levelOfDetail, internalPixelFormat,
                                       width, height, texturePixelFormat, dataType, textureData);
    if (unbind)
        this->unbind();
}

void GLTexture2D::initialize(const std::tuple<glm::ivec2, std::vector<GLbyte>> &data, const GLenum internalPixelFormat,
                             const GLenum texturePixelFormat, const GLenum dataType, const GLboolean unbind)
{
    glm::ivec2 resolution;
    std::vector<GLbyte> pixels;

    std::tie(resolution, pixels) = data;
    this->initialize(resolution.x, resolution.y, pixels.data(), internalPixelFormat, texturePixelFormat, dataType, unbind);
}
