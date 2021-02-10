#include "MainLoopCommandReplaceState.h"
#include "../IState.h"
#include <stdexcept>
#include "../IStateHolder.h"

void MainLoopCommandReplaceState::initialize(std::stack<IState *> *stateStack, IState *stateToEmplaceWith,
                                             IStateHolder *stateHolder, glm::ivec2 &screenResolution,
                                             IUserInput *userInput)
{
    this->stateStack = stateStack;
    this->stateToEmplaceWith = stateToEmplaceWith;
    this->stateHolder = stateHolder;
    this->screenResolution = screenResolution;
    this->userInput = userInput;
}

void MainLoopCommandReplaceState::execute()
{
    this->stateHolder->popState();
    this->stateToEmplaceWith->initialize(this->stateHolder,
                                         this->userInput,
                                       this->screenResolution);
    this->stateToEmplaceWith->loadResources();
    this->stateHolder->pushState(this->stateToEmplaceWith);
}
