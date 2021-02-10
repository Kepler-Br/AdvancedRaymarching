#ifndef SDL2OPENGL_MAINLOOPCOMMANDREPLACESTATE_H
#define SDL2OPENGL_MAINLOOPCOMMANDREPLACESTATE_H

#include "IMainLoopCommand.h"
#include <stack>
#include <glm/vec2.hpp>

class IState;
class IStateHolder;
class IUserInputGetter;

/// @brief Command pattern that will replace top state in MainLoop.
class MainLoopCommandReplaceState : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;
    IState *stateToEmplaceWith = nullptr;
    IStateHolder *stateHolder = nullptr;
    IUserInputGetter *userInput = nullptr;
    glm::ivec2 screenResolution;

public:
    /// @brief Command constructor.
    void initialize(std::stack<IState *> *stateStack, IState *stateToEmplaceWith, IStateHolder *stateHolder,
                    glm::ivec2 screenResolution, IUserInputGetter *userInput) noexcept;
    /// @see IMainLoopCommand.
    /// @throw std::runtime_error if state stack is empty.
    void execute() const override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDREPLACESTATE_H
