#include "MainLoopCommandReplaceState.h"
#include <stdexcept>
#include "../IMainLoopGetter.h"
#include "../IState.h"

void MainLoopCommandReplaceState::initialize(std::stack<IState *> *stateStack, IState *stateToEmplaceWith,
                                             IMainLoopGetter *mainLoopGetter) noexcept
{
    this->stateStack = stateStack;
    this->stateToEmplaceWith = stateToEmplaceWith;
    this->mainLoopGetter = mainLoopGetter;
}

void MainLoopCommandReplaceState::execute() const
{
    IState *state;

    if (this->stateStack == nullptr || this->stateToEmplaceWith == nullptr || mainLoopGetter == nullptr)
        throw std::runtime_error("Command was not initialized.");
    if (this->stateStack->empty())
        throw std::runtime_error("State stack is empty. Nothing to replace.");
    this->stateToEmplaceWith->initialize(this->mainLoopGetter);
    this->stateToEmplaceWith->loadResources();
    state = this->stateStack->top();
    state->destroy();
    this->stateStack->pop();
    delete state;
    this->stateStack->push(this->stateToEmplaceWith);
}
