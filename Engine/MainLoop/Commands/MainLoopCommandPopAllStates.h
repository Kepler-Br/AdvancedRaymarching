#ifndef SDL2OPENGL_MAINLOOPCOMMANDPOPALLSTATES_H
#define SDL2OPENGL_MAINLOOPCOMMANDPOPALLSTATES_H

#include "IMainLoopCommand.h"
#include <stack>

class IState;

/// @brief Command pattern that will pop all available states in MainLoop.
class MainLoopCommandPopAllStates : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;

public:
    /// @brief Command constructor.
    void initialize(std::stack<IState *> *stateStack) noexcept;
    /// @see IMainLoopCommand.
    void execute() const override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDPOPALLSTATES_H
