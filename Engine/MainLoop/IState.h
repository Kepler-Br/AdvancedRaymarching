#ifndef SDL2OPENGL_ISTATE_H
#define SDL2OPENGL_ISTATE_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec2.hpp>

class IStateHolder;
class IUserInputGetter;

/// @brief Interface used for states that would be passed to MainLoop.
class IState
{
public:
    /// @brief It's like constructor. Every other heir must implement this.
    /// MainLoop will call this method before pushing it to stack.
    /// @param stateHolder Pointer to MainLoop.
    /// IStateHolder restricts usage of MainLoop only to stateStack manipulation.
    /// @param userInput Pointer to UserInput class.
    /// IUserInputGetter restricts usage of UserInput to only getting input information, not setting.
    /// @param resolution Window/viewport resolution.
    virtual void initialize(IStateHolder *stateHolder, IUserInputGetter *userInput, const glm::ivec2 resolution) = 0;
    /// Destructor. Should unload resources and free heap memory.
    virtual void destroy() = 0;
    /// There you should load every resource that your state uses.
    virtual void loadResources() = 0;
    /// fixedUpdate Called every N milliseconds. If MainLoop updates is too slow
    /// it will be called several times.
    /// @param deltatime This deltatime is time every fixedUpdate should happen.
    /// Every N milliseconst. N is passed to this parameter.
    virtual void fixedUpdate(const GLfloat deltatime) = 0;
    /// update Called every frame.
    /// @param deltatime Time passed since last frame render.
    virtual void update(const GLfloat deltatime) = 0;
    /// draw Frame render should happen here.
    virtual void draw() = 0;
    /// preDraw Everything that (should) relates to rendering frame and must
    /// be done before rendering.
    virtual void preDraw() = 0;
    /// postDraw Everything that (should) relates to rendering frame and must
    /// be done after rendering.
    virtual void postDraw() = 0;
    /// first First is called at the beginning of every MainLoop cycle.
    virtual void first() = 0;
    /// last Last is called at the end of every MainLoop cycle.
    virtual void last() = 0;
    /// input Everything that relates to input stuff.
    /// @param deltatime Time passed since last frame render.
    virtual void input(const GLfloat deltatime) = 0;

    virtual ~IState() = default;
};

#endif //SDL2OPENGL_ISTATE_H
