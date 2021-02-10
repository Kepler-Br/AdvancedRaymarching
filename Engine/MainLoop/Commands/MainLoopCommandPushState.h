#ifndef SDL2OPENGL_MAINLOOPCOMMANDPUSHSTATE_H
#define SDL2OPENGL_MAINLOOPCOMMANDPUSHSTATE_H

#include "IMainLoopCommand.h"
#include <stack>
#include <glm/vec2.hpp>

class MainLoop;
class IState;
class IUserInput;
class IStateHolder;

class MainLoopCommandPushState : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;
    IUserInput *userInput = nullptr;
    IState *stateToPush = nullptr;
    IStateHolder *stateHolder;
    glm::ivec2 screenResolution;
    size_t maximumStates;

public:
    void initialize(std::stack<IState *> *stateStack, IState *stateToPush, IStateHolder *stateHolder,
                    size_t maximumStates, glm::ivec2 &screenResolution, IUserInput *userInput);
    void execute() override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDPUSHSTATE_H
