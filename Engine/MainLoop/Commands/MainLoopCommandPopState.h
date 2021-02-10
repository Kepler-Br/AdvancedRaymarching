#ifndef SDL2OPENGL_MAINLOOPCOMMANDPOPSTATE_H
#define SDL2OPENGL_MAINLOOPCOMMANDPOPSTATE_H

#include "IMainLoopCommand.h"
#include <stack>

class MainLoop;
class IState;

class MainLoopCommandPopState : public virtual IMainLoopCommand
{
public:

private:
    std::stack<IState *> *stateStack = nullptr;

public:
    void initialize(std::stack<IState *> *stateStack);
    void execute() override;

private:

};

#endif //SDL2OPENGL_MAINLOOPCOMMANDPOPSTATE_H
