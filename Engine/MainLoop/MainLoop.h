#ifndef SDL2OPENGL_MAINLOOP_H
#define SDL2OPENGL_MAINLOOP_H

#include "IStateHolder.h"
#include "IState.h"
#include "UserInput.h"
#include <stack>
#include <queue>
#include <memory>
#include <SDL2/SDL.h>
#include "./Commands/IMainLoopCommand.h"

/// @brief MainLoop is the class that is used to start main cycle.
/// Will throw an error if state is not pushed in state stack.
/// @see MainLoop::pushState to push your first state.
class MainLoop : public virtual IStateHolder
{
public:

private:
    std::stack<IState *> stateStack;
    std::queue<std::unique_ptr<IMainLoopCommand>> commandQueue;
    glm::ivec2 screenResolution;
    UserInput userInput;
    GLboolean isRunning;
    GLfloat deltatime;
    SDL_Window *window;

    static constexpr GLsizei maximumStates = 10;
    static constexpr GLfloat timePerFixedUpdate = 5.0f;

public:
    MainLoop(glm::ivec2 screenResolution, SDL_Window *window);

    /// @brief Start MainLoop's cycle.
    /// @throw std::runtime_error if stateStack is empty.
    void run();
    /// @brief Push whatever new state passed to this member function.
    /// Inside creates command MainLoopCommandPushState and pushes it to the commandQueue.
    /// State stack is not affected at function call.
    /// @param state New state to be pushed.
    void pushState(IState *state) override;
    /// @brief Pop top state.
    /// Inside creates command MainLoopCommandPopState and pushes it to the commandQueue.
    /// State stack is not affected at function call.
    void popState() override;
    /// @brief Replace top state with new state.
    /// Inside creates command MainLoopCommandReplaceState and pushes it to the commandQueue.
    /// State stack is not affected at function call.
    /// @param state State to be used to replace top state.
    /// @see MainLoopCommandReplaceState
    void replaceState(IState *state) override;
    /// @brief Pop every state at the MainLoop's state stack.
    /// Indicates MainLoop that we should exit cycle.
    /// State stack is not affected at function call.
    void popAllStates() override;

private:
    /// @brief Execute every command, that is related to state stack, in the command queue.
    /// @throw May throw any exception that is thrown during command execution.
    void executeCommands();
    /// @brief Calculate time since last cycle.
    void calculateDeltatime();
};

#endif //SDL2OPENGL_MAINLOOP_H
