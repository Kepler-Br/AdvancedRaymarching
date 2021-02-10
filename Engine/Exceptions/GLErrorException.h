#ifndef SDL2OPENGL_GLERROREXCEPTION_H
#define SDL2OPENGL_GLERROREXCEPTION_H

#include <stdexcept>

/// @brief Thrown every time glGetError is not GL_NO_ERROR in the OpenGL bindings.
class GLErrorException : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

#endif //SDL2OPENGL_GLERROREXCEPTION_H
