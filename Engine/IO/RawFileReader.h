#ifndef SDL2OPENGL_RAWFILEREADER_H
#define SDL2OPENGL_RAWFILEREADER_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <string>
#include <sstream>
#include "IIO.h"

/// @brief Basic IO file reader independent from any library.
class RawFileReader : public virtual IIO
{
public:
    RawFileReader() = default;

    /// @brief Reads whole file from disk as array of bytes.
    /// @throw IOException if file is not readable.
    /// @param path Path to file on disk.
    /// @return std::vector of bytes.
    /// @todo Optimize.
    std::vector<GLbyte> readWholeFileAsByteArray(const std::string &path) override;
    /// @brief Reads whole file from disk as std::string.
    /// @throw IOException if file is not readable.
    /// @param path Path to file on disk.
    /// @return File interpreted as std::string.
    std::string readWholeFileAsString(const std::string &path) override;
    /// @brief Reads whole file from disk as std::stringstream.
    /// @throw IOException if file is not readable.
    /// @param path Path to file on disk.
    /// @return File interpreted as std::stringstream.
    std::stringstream readWholeFileAsAsStringStream(const std::string &path) override;
    /// @brief Reads whole file from disk as std::ostringstream.
    /// @throw IOException if file is not readable.
    /// @param path Path to file on disk.
    /// @return File interpreted as std::ostringstream.
    std::ostringstream readWholeFileAsAsOutputStringStream(const std::string &path) override;
private:

};

#endif //SDL2OPENGL_RAWFILEREADER_H
