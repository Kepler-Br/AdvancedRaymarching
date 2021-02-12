#ifndef SDL2OPENGL_IUSERINPUTSETTER_H
#define SDL2OPENGL_IUSERINPUTSETTER_H

#include <GL/glew.h>
#include <GL/gl.h>

/// @brief User input setter. Used primary in MainLoop for processing user input.
class IUserInputSetter
{
public:
    /// @brief Indicates that button is pressed by user.
    /// @param button Button id.
    virtual void pressButton(const GLint button) noexcept = 0;
    /// @brief Indicates that button is released by user.
    /// @param button Button id.
    virtual void releaseButton(const GLint button) noexcept = 0;
    /// @brief Update internal state of the class.<br/>
    /// This function should update internal state.
    virtual void update() noexcept = 0;
    /// @brief Update mouse current position.
    /// @param newPosition New mouse position.
    virtual void setMouseCurrentPosition(const glm::ivec2 newPosition) noexcept = 0;
};


#endif //SDL2OPENGL_IUSERINPUTSETTER_H
