#ifndef ADVANCEDRAYMARCHING_IWINDOW_H
#define ADVANCEDRAYMARCHING_IWINDOW_H

#include "IStateWindow.h"

/// @brief Interface to be implemented by platform dependent window class.
class IWindow : public virtual IStateWindow
{
public:
    /// @brief Swap double buffer.
    virtual void swapBuffers() noexcept = 0;
    /// @brief Clear window viewport.
    virtual void clear() noexcept = 0;
};

#endif //ADVANCEDRAYMARCHING_IWINDOW_H
