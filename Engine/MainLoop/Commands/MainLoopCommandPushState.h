#ifndef SDL2OPENGL_MAINLOOPCOMMANDPUSHSTATE_H
#define SDL2OPENGL_MAINLOOPCOMMANDPUSHSTATE_H

#include "IMainLoopCommand.h"
#include <stack>

class MainLoop;
class IState;
class IUserInputGetter;
class IMainLoopGetter;
class IStateHolder;

/// @brief Command pattern that will push one state to MainLoop.
/// @see IMainLoopCommand.
class MainLoopCommandPushState : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;
    IMainLoopGetter *mainLoopGetter = nullptr;
    IState *stateToPush = nullptr;
    size_t maximumStates;

public:
    /// @brief Command constructor.
    void initialize(std::stack<IState *> *stateStack, IState *stateToPush,
                    size_t maximumStates, IMainLoopGetter *mainLoopGetter) noexcept;
    /// @throw std::runtime_error if maximum state number exceeded such in MainLoop.
    /// @throw std::runtime_error if command was not initialized.
    /// @warning May throw anything that state throws during initialization or resource loading.
    void execute() const override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDPUSHSTATE_H
