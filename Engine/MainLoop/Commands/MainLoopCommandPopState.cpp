#include "MainLoopCommandPopState.h"
#include "../IState.h"
#include <stdexcept>

void MainLoopCommandPopState::initialize(std::stack<IState *> *stateStack) noexcept
{
    this->stateStack = stateStack;
}

void MainLoopCommandPopState::execute() const
{
    IState *state;

    if (this->stateStack == nullptr)
        throw std::runtime_error("Command was not initialized.");
    if (this->stateStack->empty())
        throw std::runtime_error("State stack is empty. Cannot pop state.");
    state = this->stateStack->top();
    state->destroy();
    this->stateStack->pop();
    delete state;
}
