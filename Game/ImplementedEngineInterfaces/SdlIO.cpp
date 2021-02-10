#include "SdlIO.h"
#include <cstring>
#include <fstream>
#include <SDL2/SDL.h>
#include "Engine/Exceptions/IOException.h"


std::vector<GLbyte> SdlIO::readWholeFileAsByteArray(const std::string &path) const
{
    const std::ostringstream outputStringStream = this->readWholeFileAsAsOutputStringStream(path);
    const std::string string = outputStringStream.str();
    std::vector<GLbyte> byteArray(string.begin(), string.end());

    return byteArray;
}

std::string SdlIO::readWholeFileAsString(const std::string &path) const
{
    return this->readWholeFileAsAsStringStream(path).str();
}

std::stringstream SdlIO::readWholeFileAsAsStringStream(const std::string &path) const
{
    std::ifstream fileToRead(path, std::ios::binary);
    std::stringstream stringStream;

    if(!fileToRead.is_open())
    {
        std::stringstream errorStringStream;
        errorStringStream << "File could not be opened: ";
        errorStringStream << path;
        throw IOException(errorStringStream.str());
    }
    stringStream << fileToRead.rdbuf();
    return stringStream;
}

std::ostringstream SdlIO::readWholeFileAsAsOutputStringStream(const std::string &path) const
{
    std::ifstream fileToRead(path, std::ios::binary);
    std::ostringstream outputStringStream;

    if(!fileToRead.is_open())
    {
        std::stringstream errorStringStream;
        errorStringStream << "File could not be opened: ";
        errorStringStream << path;
        throw IOException(errorStringStream.str());
    }
    outputStringStream << fileToRead.rdbuf();
    return outputStringStream;
}

std::tuple<glm::ivec2, std::vector<GLbyte>> SdlIO::readBmpTexture(const std::string &path) const
{
    SDL_Surface *surface;
    size_t pixelCount;
    size_t bytesTotal;
    glm::ivec2 resolution;
    std::vector<GLbyte> pixels;

    surface = SDL_LoadBMP(path.c_str());
    if (surface == nullptr)
        throw IOException("Cannot read texture: " + path);
    resolution = glm::ivec2(surface->w, surface->h);
    pixelCount = surface->w * surface->h;
    bytesTotal = pixelCount * surface->format->BytesPerPixel * sizeof(GLbyte);
    pixels.resize(bytesTotal);
    std::memcpy(pixels.data(), surface->pixels, bytesTotal);
    SDL_FreeSurface(surface);
    return std::make_tuple(resolution, pixels);
}

std::tuple<glm::ivec2, std::vector<GLbyte>> SdlIO::readPngTexture(const std::string &path) const
{
    throw std::runtime_error("readJpegTexture is not implemented.");
}

std::tuple<glm::ivec2, std::vector<GLbyte>> SdlIO::readJpegTexture(const std::string &path) const
{
    throw std::runtime_error("readJpegTexture is not implemented.");
}
