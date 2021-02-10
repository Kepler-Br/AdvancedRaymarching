#include "MainLoopCommandPushState.h"
#include <stdexcept>
#include "../IStateHolder.h"
#include "../../UserInterfaces/IUserInputGetter.h"
#include "../IState.h"

void MainLoopCommandPushState::initialize(std::stack<IState *> *stateStack, IState *stateToPush,
                                          IStateHolder *stateHolder, size_t maximumStates,
                                          glm::ivec2 screenResolution, IUserInputGetter *userInput) noexcept
{
    this->stateStack = stateStack;
    this->stateToPush = stateToPush;
    this->stateHolder = stateHolder;
    this->maximumStates = maximumStates;
    this->screenResolution = screenResolution;
    this->userInput = userInput;
}

void MainLoopCommandPushState::execute() const
{
    if (this->stateStack->size() >= maximumStates)
        throw std::runtime_error("Maximum state number exceeded (" + std::to_string(this->maximumStates) + ").");
    this->stateToPush->initialize(this->stateHolder,
                                  this->userInput,
                                this->screenResolution);
    this->stateToPush->loadResources();
    this->stateStack->push(stateToPush);
}
