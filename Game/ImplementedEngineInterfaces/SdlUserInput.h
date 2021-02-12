#ifndef ADVANCEDRAYMARCHING_SDLUSERINPUT_H
#define ADVANCEDRAYMARCHING_SDLUSERINPUT_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec2.hpp>
#include "Engine/UserInterfaces/IUserInput.h"


class SdlUserInput : public virtual IUserInput
{
public:
    // IUserInputGetter implementation.
    GLboolean isButtonPressed(const GLint button) const noexcept override;
    GLboolean isButtonJustPressed(const GLint button) const noexcept override;
    GLboolean isButtonJustReleased(const GLint button) const noexcept override;
    glm::ivec2 getMouseDelta() const noexcept override;
    glm::ivec2 getMouseCurrentPosition() const noexcept override;
    // IUserInputSetter implementation.
    void pressButton(const GLint button) noexcept override;
    void releaseButton(const GLint button) noexcept override;
    void update() noexcept override;
    void setMouseCurrentPosition(const glm::ivec2 newPosition) noexcept override;
};

#endif //ADVANCEDRAYMARCHING_SDLUSERINPUT_H
