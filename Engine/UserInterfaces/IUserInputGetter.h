#ifndef SDL2OPENGL_IUSERINPUT_H
#define SDL2OPENGL_IUSERINPUT_H

#include <GL/glew.h>
#include <GL/gl.h>

/// @brief User input getter. Used only for getting input. Primary used in classes that inherit IState interface.
class IUserInputGetter
{
public:
    /// @brief Whether button is pressed at the moment.
    /// @param button Button id.
    /// @return If True then button is pressed at the moment.
    virtual GLboolean isButtonPressed(GLint button) const noexcept = 0;
    /// @brief Whether button is just pressed.
    /// Indicates if button was pressed by user at the current MainLoop's cycle.
    /// @param button Button id.
    /// @return If True then button is pressed at the current cycle.
    virtual GLboolean isButtonJustPressed(GLint button) const noexcept = 0;
    /// @brief Whether button is just released.
    /// Indicates if button was released by user at the current MainLoop's cycle.
    /// @param button Button id.
    /// @return If True then button is released at the current cycle.
    virtual GLboolean isButtonJustReleased(GLint button) const noexcept = 0;
};

#endif //SDL2OPENGL_IUSERINPUT_H
