#include "MainLoopCommandPushState.h"
#include <stdexcept>
#include "../../UserInterfaces/IUserInputGetter.h"
#include "../IState.h"

void MainLoopCommandPushState::initialize(std::stack<IState *> *stateStack, IState *stateToPush,
                                          size_t maximumStates, IMainLoopGetter *mainLoopGetter) noexcept
{
    this->stateStack = stateStack;
    this->stateToPush = stateToPush;
    this->maximumStates = maximumStates;
    this->mainLoopGetter = mainLoopGetter;
}

void MainLoopCommandPushState::execute() const
{
    if (this->stateStack == nullptr || this->stateToPush == nullptr || mainLoopGetter == nullptr)
        throw std::runtime_error("Command was not initialized.");
    if (this->stateStack->size() >= maximumStates)
        throw std::runtime_error("Maximum state number exceeded (" + std::to_string(this->maximumStates) + ").");
    this->stateToPush->initialize(this->mainLoopGetter);
    this->stateToPush->loadResources();
    this->stateStack->push(stateToPush);
}
