#ifndef SDL2OPENGL_ISTATEHOLDER_H
#define SDL2OPENGL_ISTATEHOLDER_H


class IState;

/// @brief Interface is used for passing MainLoop to states
/// without giving state too much power over MainLoop cycle.
/// @see IState
class IStateHolder
{
public:
    /// @brief Push new state to MainLoop's stateStack.
    /// @param state New state to push.
    virtual void pushState(IState *state) = 0;
    /// @brief Pop state from MainLoop's stateStack.
    virtual void popState() = 0;
    /// @brief Replaces old state with new one.
    /// @param state State to replace with.
    virtual void replaceState(IState *state) = 0;
    /// @brief Pop all states in MainLoop's stateStack.
    /// Indicates that we want to exit application if no other states pushed.
    virtual void popAllStates() = 0;

};

#endif //SDL2OPENGL_ISTATEHOLDER_H
