#ifndef SDL2OPENGL_IUSERINPUT_H
#define SDL2OPENGL_IUSERINPUT_H

#include <GL/glew.h>
#include <GL/gl.h>

/// @brief Should be implemented by UserInput.
class IUserInput
{
public:
    /// @brief Whether button is pressed at the moment.
    /// @param button Button id.
    /// @return If True then button is pressed at the moment.
    /// Otherwise not.
    virtual GLboolean isButtonPressed(GLint button) = 0;
    /// @brief Whether button is just pressed.
    /// Indicates if button was pressed by user at the current MainLoop's cycle.
    /// @param button Button id.
    /// @return If True then button is pressed at the current cycle.
    /// Otherwise not.
    virtual GLboolean isButtonJustPressed(GLint button) = 0;
    /// @brief Whether button is just released.
    /// Indicates if button was released by user at the current MainLoop's cycle.
    /// @param button Button id.
    /// @return If True then button is released at the current cycle.
    /// Otherwise not.
    virtual GLboolean isButtonJustReleased(GLint button) = 0;
};

#endif //SDL2OPENGL_IUSERINPUT_H
