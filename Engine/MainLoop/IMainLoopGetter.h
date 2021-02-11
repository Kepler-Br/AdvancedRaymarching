#ifndef ADVANCEDRAYMARCHING_IMAINLOOPGETTER_H
#define ADVANCEDRAYMARCHING_IMAINLOOPGETTER_H

#include <GL/glew.h>
#include <GL/gl.h>

class IStateWindow;
class IUserInputGetter;
class IStateHolder;

/// @todo Think about new name.
class IMainLoopGetter
{
public:
    /// @return Cycles since MainLoop start.
    virtual size_t getTicksSinceStart() const noexcept = 0;
    /// @return How much IState::fixedUpdate was executed.
    virtual size_t getFixedUpdateTicksSinceStart() const noexcept = 0;
    /// @return Cycles per second.
    virtual GLfloat getFramesPerSecond() const noexcept = 0;
    /// @return How much time a cycle takes.
    virtual GLfloat getDeltatime() const noexcept = 0;
    /// @return Get user safe window.
    virtual IStateWindow *getWindow() const noexcept = 0;
    /// @return Get unmutable user input class.
    virtual IUserInputGetter *getUserInputInstance() const noexcept = 0;
    /// @return get state holder. User will be able to say to MainLoop that User needs to change state.
    virtual IStateHolder *getStateHolder() noexcept = 0;
};

#endif //ADVANCEDRAYMARCHING_IMAINLOOPGETTER_H
