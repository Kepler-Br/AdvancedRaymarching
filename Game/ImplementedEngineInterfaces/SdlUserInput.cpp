#include "SdlUserInput.h"

GLboolean SdlUserInput::isButtonPressed(const GLint button) const noexcept
{
    return GL_FALSE;
}

GLboolean SdlUserInput::isButtonJustPressed(const GLint button) const noexcept
{
    return GL_FALSE;
}

GLboolean SdlUserInput::isButtonJustReleased(const GLint button) const noexcept
{
    return GL_FALSE;
}

glm::ivec2 SdlUserInput::getMouseDelta() const noexcept
{
    return {0.0f, 0.0f};
}

glm::ivec2 SdlUserInput::getMouseCurrentPosition() const noexcept
{
    return {0.0f, 0.0f};
}

void SdlUserInput::pressButton(const GLint button) noexcept
{

}

void SdlUserInput::releaseButton(const GLint button) noexcept
{

}

void SdlUserInput::update() noexcept
{

}

void SdlUserInput::setMouseCurrentPosition(const glm::ivec2 newPosition) noexcept
{

}
