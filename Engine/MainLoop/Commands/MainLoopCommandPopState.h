#ifndef SDL2OPENGL_MAINLOOPCOMMANDPOPSTATE_H
#define SDL2OPENGL_MAINLOOPCOMMANDPOPSTATE_H

#include "IMainLoopCommand.h"
#include <stack>

class MainLoop;
class IState;

/// @brief Command pattern that will pop one state from MainLoop.
class MainLoopCommandPopState : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;

public:
    /// @brief Command constructor.
    void initialize(std::stack<IState *> *stateStack) noexcept;
    /// @see IMainLoopCommand.
    /// @throw std::runtime_error if state stack is empty.
    void execute() const override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDPOPSTATE_H
