#ifndef SDL2OPENGL_SDL2IO_H
#define SDL2OPENGL_SDL2IO_H

#include "IIO.h"
#include "RawFileReader.h"
#include <glm/vec2.hpp>
#include <tuple>

/// @brief Encapsulation over SDL2 IO functions.
/// Inherits RawFileReader which gives us basic file read capabilities.
class Sdl2IO : public RawFileReader, public virtual IIO
{
public:
    /// @brief Reads BMP texture using SDL2 instruments and converts it to vector byte array.
    /// @throw IOException If SDL2 failed to read texture from file.
    /// @param path Path to texture file.
    /// @return Tuple that contains texture resolution as first component and byte array as second.
    std::tuple<glm::ivec2, std::vector<GLbyte>> readBmpTexture(const std::string &path) override;
    /// @brief Reads PNG texture using SDL2 instruments and converts it to vector byte array.
    // @throw IOException If SDL2 failed to read texture from file.
    /// @param path Path to texture file.
    /// @return Tuple that contains texture resolution as first component and byte array as second.
    /// @warning Not implemented.
    std::tuple<glm::ivec2, std::vector<GLbyte>> readPngTexture(const std::string &path) override;
    /// @brief Reads JPEG texture using SDL2 instruments and converts it to vector byte array.
    // @throw IOException If SDL2 failed to read texture from file.
    /// @param path Path to texture file.
    /// @return Tuple that contains texture resolution as first component and byte array as second.
    /// @warning Not implemented.
    std::tuple<glm::ivec2, std::vector<GLbyte>> readJpegTexture(const std::string &path) override;
private:

};

#endif //SDL2OPENGL_SDL2IO_H
