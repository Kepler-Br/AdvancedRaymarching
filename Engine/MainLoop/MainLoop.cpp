#include "MainLoop.h"
#include <stdexcept>
#include <memory>
#include "Commands/MainLoopCommandPopState.h"
#include "Commands/MainLoopCommandPushState.h"
#include "Commands/MainLoopCommandPopAllStates.h"
#include "Commands/MainLoopCommandReplaceState.h"
#include "Commands/IMainLoopCommand.h"

MainLoop::MainLoop(IWindow *window, IUserInput *userInput, IDeltatimeCalculator *deltatimeCalculator)
{
    this->window = window;
    this->userInput = userInput;
    this->deltatimeCalculator = deltatimeCalculator;
}

void MainLoop::run()
{
    IState *topState;
    GLfloat timeSinceLastFixedUpdate = 0.0f;
    GLfloat deltatime = 1.0f;

    this->executeCommands();
    if (stateStack.empty())
        throw std::runtime_error("Cannot run MainLoop without start state.");
    this->isRunning = GL_TRUE;
    while (this->isRunning)
    {
        this->window->clear();
        this->deltatimeCalculator->calculate();
        deltatime = this->deltatimeCalculator->get();
        timeSinceLastFixedUpdate += deltatime;
        topState = this->stateStack.top();
        topState->first();
        this->userInput->update();
        topState->input(deltatime);
        topState->update(deltatime);
        while (timeSinceLastFixedUpdate > MainLoop::timePerFixedUpdate)
        {
            topState->fixedUpdate(MainLoop::timePerFixedUpdate);
            timeSinceLastFixedUpdate -= MainLoop::timePerFixedUpdate;
        }
        topState->preDraw();
        topState->draw();
        topState->postDraw();
        topState->last();
        this->window->swapBuffers();
        this->executeCommands();
        if (this->stateStack.empty())
            this->isRunning = GL_FALSE;
    }
}

void MainLoop::pushState(IState *state)
{
    auto *command = new MainLoopCommandPushState;

    command->initialize(&this->stateStack, state, (IStateHolder *)this, MainLoop::maximumStates,
                        this->window->getResolution(), (IUserInputGetter *)&this->userInput);
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
                        this->window->getResolution(), (IUserInputGetter *)&this->userInput);
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
