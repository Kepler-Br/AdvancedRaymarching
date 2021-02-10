#ifndef SDL2OPENGL_IOEXCEPTION_H
#define SDL2OPENGL_IOEXCEPTION_H

#include <stdexcept>

/// @brief Thrown every time when IO fails to read/write.
class IOException : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};


#endif //SDL2OPENGL_IOEXCEPTION_H
