#include "MainLoop.h"
#include <stdexcept>
#include <memory>
#include "Commands/MainLoopCommandPopState.h"
#include "Commands/MainLoopCommandPushState.h"
#include "Commands/MainLoopCommandPopAllStates.h"
#include "Commands/MainLoopCommandReplaceState.h"
#include "Commands/IMainLoopCommand.h"

MainLoop::MainLoop(glm::ivec2 screenResolution, SDL_Window *window)
{
    this->screenResolution = screenResolution;
    this->window = window;
}

void MainLoop::run()
{
    IState *topState;
    GLfloat timeSinceLastFixedUpdate = 0.0f;

    this->executeCommands();
    if (stateStack.empty())
        throw std::runtime_error("Cannot run MainLoop without start state.");
    this->isRunning = GL_TRUE;
    while (this->isRunning)
    {
        this->calculateDeltatime();
        timeSinceLastFixedUpdate += this->deltatime;
        topState = this->stateStack.top();
        topState->first();
        topState->input(this->deltatime);
        topState->update(this->deltatime);
        while (timeSinceLastFixedUpdate > MainLoop::timePerFixedUpdate)
        {
            topState->fixedUpdate(MainLoop::timePerFixedUpdate);
            timeSinceLastFixedUpdate -= MainLoop::timePerFixedUpdate;
        }
        topState->preDraw();
        topState->draw();
        topState->postDraw();
        SDL_GL_SwapWindow(this->window);
        topState->last();
        this->executeCommands();
        if (this->stateStack.empty())
            this->isRunning = GL_FALSE;
    }
}

void MainLoop::pushState(IState *state)
{
    auto *command = new MainLoopCommandPushState;

    command->initialize(&this->stateStack, state, (IStateHolder *)this, MainLoop::maximumStates,
                        this->screenResolution, (IUserInput *)&this->userInput);
    this->commandQueue.push(std::unique_ptr<IMainLoopCommand>(command));
}

void MainLoop::popState()
{
    auto *command = new MainLoopCommandPopState;

    command->initialize(&this->stateStack);
    this->commandQueue.push(std::unique_ptr<IMainLoopCommand>(command));
}

void MainLoop::replaceState(IState *state)
{
    auto *command = new MainLoopCommandReplaceState;

    command->initialize(&this->stateStack, state, (IStateHolder *)this,
                        this->screenResolution, (IUserInput *)&this->userInput);
    this->commandQueue.push(std::unique_ptr<IMainLoopCommand>(command));
}

void MainLoop::popAllStates()
{
    auto *command = new MainLoopCommandPopAllStates;

    command->initialize(&this->stateStack);
    this->commandQueue.push(std::unique_ptr<IMainLoopCommand>(command));
}

void MainLoop::executeCommands()
{
    while (!this->commandQueue.empty())
    {
        this->commandQueue.front()->execute();
        this->commandQueue.pop();
    }
}

void MainLoop::calculateDeltatime()
{
    this->deltatime = 1.0f;
}
