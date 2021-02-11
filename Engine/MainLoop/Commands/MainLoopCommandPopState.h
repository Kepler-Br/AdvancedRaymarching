#ifndef SDL2OPENGL_MAINLOOPCOMMANDPOPSTATE_H
#define SDL2OPENGL_MAINLOOPCOMMANDPOPSTATE_H

#include "IMainLoopCommand.h"
#include <stack>

class MainLoop;
class IState;

/// @brief Command pattern that will pop one state from MainLoop.
/// @see IMainLoopCommand.
class MainLoopCommandPopState : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;

public:
    /// @brief Command constructor.
    void initialize(std::stack<IState *> *stateStack) noexcept;
    /// @throw std::runtime_error if state stack is empty.
    /// @throw std::runtime_error if command was not initialized.
    void execute() const override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDPOPSTATE_H
