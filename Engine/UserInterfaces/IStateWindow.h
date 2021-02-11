#ifndef ADVANCEDRAYMARCHING_ISTATEWINDOW_H
#define ADVANCEDRAYMARCHING_ISTATEWINDOW_H

#include <glm/vec2.hpp>
#include <string>

/// @brief Window interface that will be passed to IState heirs.<br/>
/// Should only contain methods that user can call without unexpected consequences.
class IStateWindow
{
public:
    /// @brief Should return window screen resolution.
    /// @return Window resolution.
    virtual glm::ivec2 getResolution() const noexcept = 0;
    /// @brief Decides whether IWindow should execute IWindow::clean.
    virtual void setClean(GLboolean shouldCleanWindow) noexcept = 0;
    /// @brief Changes window title.
    virtual void setTitle(const std::string &newTitle) noexcept = 0;
};

#endif //ADVANCEDRAYMARCHING_ISTATEWINDOW_H
