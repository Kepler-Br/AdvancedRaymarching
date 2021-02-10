#ifndef SDL2OPENGL_MAINLOOPCOMMANDPUSHSTATE_H
#define SDL2OPENGL_MAINLOOPCOMMANDPUSHSTATE_H

#include "IMainLoopCommand.h"
#include <stack>
#include <glm/vec2.hpp>

class MainLoop;
class IState;
class IUserInputGetter;
class IStateHolder;

/// @brief Command pattern that will push one state to MainLoop.
class MainLoopCommandPushState : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;
    IUserInputGetter *userInput = nullptr;
    IState *stateToPush = nullptr;
    IStateHolder *stateHolder;
    glm::ivec2 screenResolution;
    size_t maximumStates;

public:
    /// @brief Command constructor.
    void initialize(std::stack<IState *> *stateStack, IState *stateToPush, IStateHolder *stateHolder,
                    size_t maximumStates, glm::ivec2 screenResolution, IUserInputGetter *userInput) noexcept;
    /// @see IMainLoopCommand.
    /// @throw std::runtime_error if maximum state number exceeded such in MainLoop.
    void execute() const override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDPUSHSTATE_H
