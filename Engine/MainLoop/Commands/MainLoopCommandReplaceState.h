#ifndef SDL2OPENGL_MAINLOOPCOMMANDREPLACESTATE_H
#define SDL2OPENGL_MAINLOOPCOMMANDREPLACESTATE_H

#include "IMainLoopCommand.h"
#include <stack>

class IState;
class IStateHolder;
class IUserInputGetter;
class IMainLoopGetter;

/// @brief Command pattern that will replace top state in MainLoop.
/// @see IMainLoopCommand.
class MainLoopCommandReplaceState : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;
    IState *stateToEmplaceWith = nullptr;
    IMainLoopGetter *mainLoopGetter = nullptr;

public:
    /// @brief Command constructor.
    void initialize(std::stack<IState *> *stateStack, IState *stateToEmplaceWith,
                    IMainLoopGetter *mainLoopGetter) noexcept;
    /// @throw std::runtime_error if state stack is empty.
    /// @throw std::runtime_error if command was not initialized.
    /// @warning May throw anything that state throws during initialization or resource loading.
    void execute() const override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDREPLACESTATE_H
