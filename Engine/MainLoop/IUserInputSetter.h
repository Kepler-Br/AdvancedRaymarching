#ifndef SDL2OPENGL_IUSERINPUTSETTER_H
#define SDL2OPENGL_IUSERINPUTSETTER_H

#include <GL/glew.h>
#include <GL/gl.h>

/// @brief Interface for UserInput.
class IUserInputSetter
{
public:
    /// @brief Indicates that button is pressed by user.
    /// @param button Button id.
    virtual void pressButton(GLint button) = 0;
    /// @brief Indicates that button is released by user.
    /// @param button Button id.
    virtual void releaseButton(GLint button) = 0;
    /// @brief Update internal state of the class.
    /// This function should update justPressed and justReleased maps.
    virtual void update(GLint button) = 0;
};


#endif //SDL2OPENGL_IUSERINPUTSETTER_H
