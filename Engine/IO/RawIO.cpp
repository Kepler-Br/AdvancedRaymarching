#include "RawIO.h"
#include <stdexcept>

std::tuple<glm::ivec2, std::vector<GLbyte>> RawIO::readBmpTexture(const std::string &path)
{
    throw std::runtime_error("readBmpTexture is not implemented.");
}

std::tuple<glm::ivec2, std::vector<GLbyte>> RawIO::readPngTexture(const std::string &path)
{
    throw std::runtime_error("readPngTexture is not implemented.");
}

std::tuple<glm::ivec2, std::vector<GLbyte>> RawIO::readJpegTexture(const std::string &path)
{
    throw std::runtime_error("readJpegTexture is not implemented.");
}
