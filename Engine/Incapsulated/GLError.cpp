#include "GLError.h"
#include <sstream>
#include <string>
#include <memory>

std::string GLError::toString(GLenum errorCode)
{
    switch (errorCode)
    {
        case GL_NO_ERROR:
            return "GL_NO_ERROR";
        case GL_INVALID_ENUM:
            return "GL_INVALID_ENUM";
        case GL_INVALID_VALUE:
            return "GL_INVALID_VALUE";
        case GL_INVALID_OPERATION:
            return "GL_INVALID_OPERATION";
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            return "GL_INVALID_FRAMEBUFFER_OPERATION";
        case GL_OUT_OF_MEMORY:
            return "GL_OUT_OF_MEMORY";
        case GL_STACK_UNDERFLOW:
            return "GL_STACK_UNDERFLOW";
        case GL_STACK_OVERFLOW:
            return "GL_STACK_OVERFLOW";
        default:
            return "INVALID ERROR CODE";
    }
}

void GLError::throwExceptionIfGLError(const std::string &message)
{
    const GLenum error = glGetError();

    if (error == GL_NO_ERROR)
        return;
    // Allocate stringstream only when we need it.
    std::unique_ptr<std::stringstream> stringStream(new std::stringstream);
    if (message.length() == 0)
        *stringStream << "glGetError returns";
    else
        *stringStream << message;
    *stringStream << ": ";
    *stringStream << GLError::toString(error);
    throw GLErrorException(stringStream->str());
}