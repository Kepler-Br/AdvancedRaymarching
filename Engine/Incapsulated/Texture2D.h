#ifndef SDL2OPENGL_GLTEXTURE2D_H
#define SDL2OPENGL_GLTEXTURE2D_H

#include "../Bindings/GLTextureBindings.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec2.hpp>
#include <vector>
#include <tuple>

/// @brief Encapsulation over OpenGL texture routine.
class  Texture2D
{
public:

private:
    GLuint texturePointer = 0;

public:
    /// @see Texture2D::initialize.
    Texture2D(const GLsizei width, const GLsizei height, const GLvoid *textureData, const GLenum internalPixelFormat,
              const GLenum texturePixelFormat, const GLenum dataType = GL_UNSIGNED_BYTE,
              const GLboolean unbind = GL_TRUE);
    /// @see Texture2D::initialize.
    Texture2D(const std::tuple<glm::ivec2, std::vector<GLbyte>> &data, const GLenum internalPixelFormat, const GLenum texturePixelFormat,
              const GLenum dataType = GL_UNSIGNED_BYTE, const GLboolean unbind = GL_TRUE);
    Texture2D() = default;

    /// @brief Generate mipmap for this texture.
    /// @throw GLErrorException if OpenGL was unable to generate mipmap.
    /// @see GLTextureBindings::generateMipmap.
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGenerateMipmap.xhtml">glGenerateMipmap</a>
    void generateMipmap() const;
    /// @brief Sets wrap mode for current texture.
    /// @param wrapMode Texture wrap mode. Should be GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER, GL_MIRRORED_REPEAT,
    /// GL_REPEAT, or GL_MIRROR_CLAMP_TO_EDGE.
    /// @param rebind Whether member function should bind texture before setting wrap mode and unbind it after.
    /// @throw GLErrorException if OpenGL was unable to set wrap mode due to incorrect wrapMode or
    /// internal OpenGL errors.
    /// @see GLTextureBindings::setParameterInt<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexParameter.xhtml">glTexParameteri</a>
    void setWrap(const GLint wrapMode, const GLboolean rebind = GL_TRUE) const;
    /// @brief Sets what OpenGL should do when texture is supersampled.
    /// @param filterType The texture magnification function is used whenever the level-of-detail function used
    /// when sampling from the texture determines that the texture should be magified.
    /// Should be GL_NEAREST or GL_LINEAR.
    /// @param rebind Whether member function should bind texture before setting wrap mode and unbind it after.
    /// @throw GLErrorException if OpenGL was unable to set filter type.
    /// @see GLTextureBindings::setParameterInt<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexParameter.xhtml">glTexParameteri</a>
    void setMagnifyingFilter(const GLint filterType, const GLboolean rebind = GL_TRUE) const;
    /// @brief Sets what OpenGL should do when texture is subsampled.
    /// @param filterType The texture minifying function is used whenever the level-of-detail function used
    /// when sampling from the texture determines that the texture should be minified.
    /// Should be GL_NEAREST or GL_LINEAR.
    /// @param rebind Whether member function should bind texture before setting wrap mode and unbind it after.
    /// @throw GLErrorException if OpenGL was unable to set filter type.
    /// @see GLTextureBindings::setParameterInt<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexParameter.xhtml">glTexParameteri</a>
    void setMinifyingFilter(const GLint filterType, const GLboolean rebind = GL_TRUE) const;
    /// @brief Bind this texture to OpenGL.
    /// @throw GLErrorException If texture is uninitialized.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBindTexture.xhtml">glBindTexture</a>
    void bind() const;
    /// @brief Unbind this texture from OpenGL. Other words binds texture 0.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBindTexture.xhtml">glBindTexture</a>
    void unbind() const;
    /// @brief Destroys texture in GPU.
    /// @throw std::runtime_error texture was uninitialized.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glDeleteTextures.xhtml">glDeleteTextures</a>
    void destroy();
    /// @brief Initialize OpenGL texture with given parameters.
    /// @param width Texture width in pixels.
    /// @param height Texture height in pixels.
    /// @param textureData Texture raw pixels.
    /// @param internalPixelFormat Specifies the number of color components in the texture.
    /// @param texturePixelFormat Specifies the format of the pixel data. Should be GL_RED, GL_RG, GL_RGB,
    /// GL_BGR, GL_RGBA, GL_BGRA, GL_RED_INTEGER, GL_RG_INTEGER, GL_RGB_INTEGER, GL_BGR_INTEGER,
    /// GL_RGBA_INTEGER, GL_BGRA_INTEGER, GL_STENCIL_INDEX, GL_DEPTH_COMPONENT, GL_DEPTH_STENCIL.
    /// @param dataType Specifies the data type of the pixel data. Should be GL_UNSIGNED_BYTE, GL_BYTE,
    /// GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_HALF_FLOAT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2,
    /// GL_UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4,
    /// GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV,
    /// GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2,
    /// GL_UNSIGNED_INT_2_10_10_10_REV.
    /// @param unbind Specifies whether texture should be unbound after initialization.
    /// @throw std::runtime_error if texture was already initialized.
    /// @throw GLErrorException if OpenGL was unable to upload texture or set texture parameters.
    /// @see GLTextureBindings::uploadTexture2D<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGenTextures.xhtml">glGenTextures</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexImage2D.xhtml">glTexImage2D</a>
    void initialize(const GLsizei width, const GLsizei height, const GLvoid *textureData,
                    const GLenum internalPixelFormat, const GLenum texturePixelFormat,
                    const GLenum dataType = GL_UNSIGNED_BYTE, const GLboolean unbind = GL_TRUE);
    /// @brief Initialize OpenGL texture with given parameters.
    /// @param data Texture resolution with texture pixels as vector(In that order).
    /// @param internalPixelFormat Specifies the number of color components in the texture.
    /// @param texturePixelFormat Specifies the format of the pixel data. Should be GL_RED, GL_RG, GL_RGB,
    /// GL_BGR, GL_RGBA, GL_BGRA, GL_RED_INTEGER, GL_RG_INTEGER, GL_RGB_INTEGER, GL_BGR_INTEGER,
    /// GL_RGBA_INTEGER, GL_BGRA_INTEGER, GL_STENCIL_INDEX, GL_DEPTH_COMPONENT, GL_DEPTH_STENCIL.
    /// @param dataType Specifies the data type of the pixel data. Should be GL_UNSIGNED_BYTE, GL_BYTE,
    /// GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_HALF_FLOAT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2,
    /// GL_UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4,
    /// GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV,
    /// GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2,
    /// GL_UNSIGNED_INT_2_10_10_10_REV.
    /// @param unbind Specifies whether texture should be unbound after initialization.
    /// @throw std::runtime_error if texture was already initialized.
    /// @throw GLErrorException if OpenGL was unable to upload texture or set texture parameters.
    /// @see GLTextureBindings::uploadTexture2D<br/>
    /// Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGenTextures.xhtml">glGenTextures</a>,
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexImage2D.xhtml">glTexImage2D</a>
    void initialize(const std::tuple<glm::ivec2, std::vector<GLbyte>> &data, const GLenum internalPixelFormat,
                    const GLenum texturePixelFormat, const GLenum dataType = GL_UNSIGNED_BYTE,
                    const GLboolean unbind = GL_TRUE);

private:
};

#endif //SDL2OPENGL_GLTEXTURE2D_H
