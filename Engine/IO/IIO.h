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
    /// @brief Should read whole file as array of bytes.
    virtual std::vector<GLbyte> readWholeFileAsByteArray(const std::string &path) = 0;
    /// @brief Should read whole file as std::string.
    virtual std::string readWholeFileAsString(const std::string &path) = 0;
    /// @brief Should read whole file as std::stringstream.
    virtual std::stringstream readWholeFileAsAsStringStream(const std::string &path) = 0;
    /// @brief Should read whole file as std::ostringstream.
    virtual std::ostringstream readWholeFileAsAsOutputStringStream(const std::string &path) = 0;
    /// @brief Should read BMP texture from disk.
    virtual std::tuple<glm::ivec2, std::vector<GLbyte>> readBmpTexture(const std::string &path) = 0;
    /// @brief Should read PNG texture from disk.
    virtual std::tuple<glm::ivec2, std::vector<GLbyte>> readPngTexture(const std::string &path) = 0;
    /// @brief Should read JPEG texture from disk.
    virtual std::tuple<glm::ivec2, std::vector<GLbyte>> readJpegTexture(const std::string &path) = 0;

    virtual ~IIO() = default;

private:

};

#endif //SDL2OPENGL_IIO_H
