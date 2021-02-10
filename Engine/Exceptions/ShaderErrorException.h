#ifndef SDL2OPENGL_SHADERERROREXCEPTION_H
#define SDL2OPENGL_SHADERERROREXCEPTION_H

#include "GLErrorException.h"

/// @brief Thrown every time Shader compilation or link process fails.
class ShaderErrorException : public GLErrorException
{
    using GLErrorException::GLErrorException;
};

#endif //SDL2OPENGL_SHADERERROREXCEPTION_H
