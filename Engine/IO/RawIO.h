#ifndef SDL2OPENGL_RAWIO_H
#define SDL2OPENGL_RAWIO_H
#include <tuple>
#include <vector>
#include <glm/vec2.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include "IIO.h"
#include "RawFileReader.h"

/// @brief Texture IO that is independent from other libraries.
class RawIO : public RawFileReader, public virtual IIO
{
public:
    RawIO() = default;

    /// @brief Reads BMP texture and converts it to vector byte array.
    /// @throw IOException If failed to read texture from file.
    /// @param path Path to texture file.
    /// @return Tuple that contains texture resolution as first component and byte array as second.
    /// @warning Not implemented.
    std::tuple<glm::ivec2, std::vector<GLbyte>> readBmpTexture(const std::string &path) override;
    /// @brief Reads PNG texture and converts it to vector byte array.
    /// @throw IOException If failed to read texture from file.
    /// @param path Path to texture file.
    /// @return Tuple that contains texture resolution as first component and byte array as second.
    /// @warning Not implemented. Probably never will.
    std::tuple<glm::ivec2, std::vector<GLbyte>> readPngTexture(const std::string &path) override;
    /// @brief Reads JPEG texture and converts it to vector byte array.
    /// @throw IOException If failed to read texture from file.
    /// @param path Path to texture file.
    /// @return Tuple that contains texture resolution as first component and byte array as second.
    /// @warning Not implemented. Probably never will.
    std::tuple<glm::ivec2, std::vector<GLbyte>> readJpegTexture(const std::string &path) override;
};

#endif //SDL2OPENGL_RAWIO_H
