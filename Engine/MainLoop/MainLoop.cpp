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
    if (window == nullptr)
        throw std::runtime_error("IWindow pointer is nullptr.");
    if (userInput == nullptr)
        throw std::runtime_error("IUserInput pointer is nullptr.");
    if (deltatimeCalculator == nullptr)
        throw std::runtime_error("IDeltatimeCalculator pointer is nullptr.");
    this->window = window;
    this->userInput = userInput;
    this->deltatimeCalculator = deltatimeCalculator;
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
        this->deltatimeCalculator->calculate();
        timeSinceLastFixedUpdate += this->getDeltatime();
        topState = this->stateStack.top();
        topState->first();
        this->userInput->update();
        topState->input(this->getDeltatime());
        topState->update(this->getDeltatime());
        while (timeSinceLastFixedUpdate > MainLoop::timePerFixedUpdate)
        {
            topState->fixedUpdate(MainLoop::timePerFixedUpdate);
            timeSinceLastFixedUpdate -= MainLoop::timePerFixedUpdate;
            this->fixedUpdateTicks++;
        }
        this->window->clear();
        topState->preDraw();
        topState->draw();
        topState->postDraw();
        this->window->swapBuffers();
        topState->last();
        this->executeCommands();
        if (this->stateStack.empty())
            this->isRunning = GL_FALSE;
        this->ticksSinceStart++;
    }
}

void MainLoop::pushState(IState *state)
{
    auto *command = new MainLoopCommandPushState;

    command->initialize(&this->stateStack, state, MainLoop::maximumStates, this);
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

    command->initialize(&this->stateStack, state, this);
    this->commandQueue.push(std::unique_ptr<IMainLoopCommand>(command));
}

void MainLoop::popAllStates()
{
    auto *command = new MainLoopCommandPopAllStates;

    command->initialize(&this->stateStack);
    this->commandQueue.push(std::unique_ptr<IMainLoopCommand>(command));
}

size_t MainLoop::getTicksSinceStart() const noexcept
{
    return ticksSinceStart;
}

size_t MainLoop::getFixedUpdateTicksSinceStart() const noexcept
{
    return fixedUpdateTicks;
}

GLfloat MainLoop::getFramesPerSecond() const noexcept
{
    return 1.0f/this->deltatimeCalculator->get();
}

GLfloat MainLoop::getDeltatime() const noexcept
{
    return this->deltatimeCalculator->get();
}

IStateWindow *MainLoop::getWindow() const noexcept
{
    return this->window;
}

IUserInputGetter *MainLoop::getUserInputInstance() const noexcept
{
    return this->userInput;
}

IStateHolder *MainLoop::getStateHolder() noexcept
{
    return this;
}

void MainLoop::executeCommands()
{
    while (!this->commandQueue.empty())
    {
        this->commandQueue.front()->execute();
        this->commandQueue.pop();
    }
}
