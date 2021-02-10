#ifndef ADVANCEDRAYMARCHING_SDLUSERINPUT_H
#define ADVANCEDRAYMARCHING_SDLUSERINPUT_H

#include <GL/glew.h>
#include <GL/gl.h>
#include "Engine/UserInterfaces/IUserInput.h"


class SdlUserInput : public virtual IUserInput
{
public:
    // IUserInputGetter implementation.
    GLboolean isButtonPressed(GLint button) const noexcept override;
    GLboolean isButtonJustPressed(GLint button) const noexcept override;
    GLboolean isButtonJustReleased(GLint button) const noexcept override;
    // IUserInputSetter implementation.
    void pressButton(GLint button) noexcept override;
    void releaseButton(GLint button) noexcept override;
    void update() noexcept override;
};

#endif //ADVANCEDRAYMARCHING_SDLUSERINPUT_H
