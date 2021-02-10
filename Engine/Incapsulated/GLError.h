#ifndef SDL2OPENGL_GLERROR_H
#define SDL2OPENGL_GLERROR_H

#include <GL/glew.h>
#include "GLErrorException.h"


/// @brief Utility class. Converts glGetError result to string and
/// throws exception if result is not GL_NO_ERROR.
class GLError
{
private:
    GLError() = default;

public:
    /// Converts OpenGL error enum to std::string.
    /// Example:
    /// GL_INVALID_ENUM would be std::string("GL_INVALID_ENUM").
    /// @param errorCode OpenGL error code that should be converted to std::string.
    /// @return converted OpenGL error enum to string.
    static std::string toString(GLenum errorCode);
    /// @brief Throw GLErrorException if glGetError returns not GL_NO_ERROR
    /// @param message Message which will be thrown.
    /// @throw GLErrorException if glGetError returns not GL_NO_ERROR.
    /// @see Khronos OpenGL reference:<br/>
    /// <a href="https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glGetError.xhtml">glGetError</a>
    static void throwExceptionIfGLError(const std::string &message = "");
};

#endif //SDL2OPENGL_GLERROR_H
