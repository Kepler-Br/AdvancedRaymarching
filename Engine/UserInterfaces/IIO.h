#ifndef SDL2OPENGL_IIO_H
#define SDL2OPENGL_IIO_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <vector>
#include <glm/vec2.hpp>

/// @brief Interface that should be implemented by any IO class.
class IIO
{
public:
    /// @brief Reads whole file from disk as array of bytes.
    /// @throw IOException if file is not readable.
    /// @param path Path to file on disk.
    /// @return std::vector of bytes.
    virtual std::vector<GLbyte> readWholeFileAsByteArray(const std::string &path) const = 0;
    /// @brief Reads whole file from disk as std::string.
    /// @throw IOException if file is not readable.
    /// @param path Path to file on disk.
    /// @return File interpreted as std::string.
    virtual std::string readWholeFileAsString(const std::string &path) const = 0;
    /// @brief Reads whole file from disk as std::stringstream.
    /// @throw IOException if file is not readable.
    /// @param path Path to file on disk.
    /// @return File interpreted as std::stringstream.
    virtual std::stringstream readWholeFileAsAsStringStream(const std::string &path) const = 0;
    /// @brief Reads whole file from disk as std::ostringstream.
    /// @throw IOException if file is not readable.
    /// @param path Path to file on disk.
    /// @return File interpreted as std::ostringstream.
    virtual std::ostringstream readWholeFileAsAsOutputStringStream(const std::string &path) const = 0;
    /// @brief Reads Bmp texture and converts it to vector byte array.
    /// @throw IOException If failed to read texture from file.
    /// @param path Path to texture file.
    /// @return Tuple that contains texture resolution as first component and byte array as second.
    virtual std::tuple<glm::ivec2, std::vector<GLbyte>> readBmpTexture(const std::string &path) const = 0;
    /// @brief Reads PNG texture and converts it to vector byte array.
    /// @throw IOException If failed to read texture from file.
    /// @param path Path to texture file.
    /// @return Tuple that contains texture resolution as first component and byte array as second.
    virtual std::tuple<glm::ivec2, std::vector<GLbyte>> readPngTexture(const std::string &path) const = 0;
    /// @brief Reads JPEG texture and converts it to vector byte array.
    /// @throw IOException If failed to read texture from file.
    /// @param path Path to texture file.
    /// @return Tuple that contains texture resolution as first component and byte array as second.
    virtual std::tuple<glm::ivec2, std::vector<GLbyte>> readJpegTexture(const std::string &path) const = 0;
};

#endif //SDL2OPENGL_IIO_H
