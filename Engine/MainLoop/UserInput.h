#ifndef SDL2OPENGL_USERINPUT_H
#define SDL2OPENGL_USERINPUT_H

#include <GL/glew.h>
#include <GL/gl.h>
#include "IUserInput.h"
#include "IUserInputSetter.h"

/// @brief UserInput is used to get keyboard or other's controller input from the system.
class UserInput: public virtual IUserInput, public virtual IUserInputSetter
{
public:

private:

public:
    /// @brief Whether button is pressed at the moment.
    /// @param button Button id.
    /// @return If True then button is pressed at the moment.
    /// Otherwise not.
    GLboolean isButtonPressed(GLint button) noexcept override;
    /// @brief Whether button is just pressed.
    /// Indicates if button was pressed by user at the current MainLoop's cycle.
    /// @param button Button id.
    /// @return If True then button is pressed at the current cycle.
    /// Otherwise not.
    GLboolean isButtonJustPressed(GLint button) noexcept override;
    /// @brief Whether button is just released.
    /// Indicates if button was released by user at the current MainLoop's cycle.
    /// @param button Button id.
    /// @return If True then button is released at the current cycle.
    /// Otherwise not.
    GLboolean isButtonJustReleased(GLint button) noexcept override;
    /// @brief Indicates that button is pressed by user.
    /// @param button Button id.
    void pressButton(GLint button) noexcept override;
    /// @brief Indicates that button is released by user.
    /// @param button Button id.
    void releaseButton(GLint button) noexcept override;
    /// @brief Update internal state of the class.
    /// For example update justPressed and justReleased buttons array.
    void update(GLint button) override;

private:

};

#endif //SDL2OPENGL_USERINPUT_H
