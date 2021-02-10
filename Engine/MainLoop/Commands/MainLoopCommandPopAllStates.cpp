#include "MainLoopCommandPopAllStates.h"
#include "../IState.h"
#include <stdexcept>

void MainLoopCommandPopAllStates::initialize(std::stack<IState *> *stateStack) noexcept
{
    this->stateStack = stateStack;
}

void MainLoopCommandPopAllStates::execute() const
{
    IState *state;

    while (!this->stateStack->empty())
    {
        state = this->stateStack->top();
        state->destroy();
        this->stateStack->pop();
        delete state;
    }
}
