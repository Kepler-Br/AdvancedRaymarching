#ifndef SDL2OPENGL_MAINLOOP_H
#define SDL2OPENGL_MAINLOOP_H

#include <stack>
#include <queue>
#include <memory>
#include "./Commands/IMainLoopCommand.h"
#include "../UserInterfaces/IUserInput.h"
#include "../UserInterfaces/IDeltatimeCalculator.h"
#include "../UserInterfaces/IWindow.h"
#include "IStateHolder.h"
#include "IMainLoopGetter.h"
#include "IState.h"

/// @brief MainLoop is the class that is used to start main cycle.
/// Will throw an error if state is not pushed in state stack.
/// @see MainLoop::pushState to push your first state.
/// @see IMainLoopGetter, IStateHolder.
class MainLoop : public virtual IStateHolder, public virtual IMainLoopGetter
{
public:

private:
    std::stack<IState *> stateStack;
    std::queue<std::unique_ptr<IMainLoopCommand>> commandQueue;
    GLboolean isRunning;
    IUserInput *userInput;
    IWindow *window;
    IDeltatimeCalculator *deltatimeCalculator;
    size_t ticksSinceStart = 0;
    size_t fixedUpdateTicks = 0;

    static constexpr size_t maximumStates = 10;
    static constexpr GLfloat timePerFixedUpdate = 5.0f;

public:
    MainLoop(IWindow *window, IUserInput *userInput, IDeltatimeCalculator *deltatimeCalculator);

    /// @brief Start MainLoop's cycle.
    /// @throw std::runtime_error if stateStack is empty.
    void run();

    // IStateHolder
    /// @brief Push whatever new state passed to this member function.
    /// Inside creates command MainLoopCommandPushState and pushes it to the commandQueue.
    /// State stack is not affected at function call.
    /// @param state New state to be pushed.
    /// @see IStateHolder, MainLoopCommandPushState.
    void pushState(IState *state) override;
    /// @brief Pop top state.
    /// Inside creates command MainLoopCommandPopState and pushes it to the commandQueue.
    /// State stack is not affected at function call.
    /// @see IStateHolder, MainLoopCommandPopState.
    void popState() override;
    /// @brief Replace top state with new state.
    /// Inside creates command MainLoopCommandReplaceState and pushes it to the commandQueue.
    /// State stack is not affected at function call.
    /// @param state State to be used to replace top state.
    /// @see IStateHolder, MainLoopCommandReplaceState.
    void replaceState(IState *state) override;
    /// @brief Pop every state at the MainLoop's state stack.
    /// Indicates MainLoop that we should exit cycle.
    /// State stack is not affected at function call.
    /// @see IStateHolder, MainLoopCommandPopAllStates.
    void popAllStates() override;

    // IMainLoopInfo
    /// @see IMainLoopGetter.
    size_t getTicksSinceStart() const noexcept override;
    /// @see IMainLoopGetter.
    size_t getFixedUpdateTicksSinceStart() const noexcept override;
    /// @see IMainLoopGetter.
    GLfloat getFramesPerSecond() const noexcept override;
    /// @see IMainLoopGetter.
    GLfloat getDeltatime() const noexcept override;
    /// @see IMainLoopGetter.
    IStateWindow *getWindow() const noexcept override;
    /// @see IMainLoopGetter.
    IUserInputGetter *getUserInputInstance() const noexcept override;
    /// @see IMainLoopGetter.
    IStateHolder *getStateHolder() noexcept override;

private:
    /// @brief Execute every command, that is related to state stack, in the command queue.
    /// @see IMainLoopCommand.
    /// @throw May throw any exception that is thrown during command execution.
    void executeCommands();
};

#endif //SDL2OPENGL_MAINLOOP_H
