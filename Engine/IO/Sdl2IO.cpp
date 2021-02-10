#include "Sdl2IO.h"
#include <SDL2/SDL.h>
#include <stdexcept>
#include <vector>
#include <cstring>
#include "../Exceptions/IOException.h"

std::tuple<glm::ivec2, std::vector<GLbyte>> Sdl2IO::readBmpTexture(const std::string &path)
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

std::tuple<glm::ivec2, std::vector<GLbyte>> Sdl2IO::readPngTexture(const std::string &path)
{
    throw std::runtime_error("readPngTexture is not implemented.");
}

std::tuple<glm::ivec2, std::vector<GLbyte>> Sdl2IO::readJpegTexture(const std::string &path)
{
    throw std::runtime_error("readJpegTexture is not implemented.");
}
