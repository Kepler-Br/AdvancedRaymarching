#ifndef SDL2OPENGL_MAINLOOPCOMMANDPOPALLSTATES_H
#define SDL2OPENGL_MAINLOOPCOMMANDPOPALLSTATES_H

#include "IMainLoopCommand.h"
#include <stack>

class IState;

class MainLoopCommandPopAllStates : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;

public:
    void initialize(std::stack<IState *> *stateStack);
    void execute() override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDPOPALLSTATES_H
