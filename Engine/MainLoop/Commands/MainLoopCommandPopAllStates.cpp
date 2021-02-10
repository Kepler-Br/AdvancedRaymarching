#include "MainLoopCommandPopAllStates.h"
#include "../IState.h"
#include <stdexcept>

void MainLoopCommandPopAllStates::initialize(std::stack<IState *> *stateStack)
{
    this->stateStack = stateStack;
}

void MainLoopCommandPopAllStates::execute()
{
    IState *state;

    if (this->stateStack->empty())
        throw std::runtime_error("State stack is empty. Cannot pop all states.");
    while (!this->stateStack->empty())
    {
        state = this->stateStack->top();
        state->destroy();
        this->stateStack->pop();
        delete state;
    }
}
