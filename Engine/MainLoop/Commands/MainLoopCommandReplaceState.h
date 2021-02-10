#ifndef SDL2OPENGL_MAINLOOPCOMMANDREPLACESTATE_H
#define SDL2OPENGL_MAINLOOPCOMMANDREPLACESTATE_H

#include "IMainLoopCommand.h"
#include <stack>
#include <glm/vec2.hpp>

class IState;
class IStateHolder;
class IUserInput;

class MainLoopCommandReplaceState : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;
    IState *stateToEmplaceWith = nullptr;
    IStateHolder *stateHolder = nullptr;
    IUserInput *userInput = nullptr;
    glm::ivec2 screenResolution;

public:
    void initialize(std::stack<IState *> *stateStack, IState *stateToEmplaceWith, IStateHolder *stateHolder,
                    glm::ivec2 &screenResolution, IUserInput *userInput);
    void execute() override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDREPLACESTATE_H
