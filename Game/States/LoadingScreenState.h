#ifndef SDL2OPENGL_LOADINGSCREENSTATE_H
#define SDL2OPENGL_LOADINGSCREENSTATE_H

#include <iostream>
#include "Engine/MainLoop/IState.h"
#include "Engine/Incapsulated/Texture2D.h"
#include "Engine/Incapsulated/VertexBuffer.h"
#include "Engine/Incapsulated/Shader.h"
#include "Engine/Incapsulated/VertexArrayObject.h"
#include "Engine/UserInterfaces/IIO.h"
#include "Engine/MainLoop/IMainLoopGetter.h"
#include "Engine/UserInterfaces/IStateWindow.h"

class LoadingScreenState : public virtual IState
{
public:

private:
    GLboolean resourcesLoaded = GL_FALSE;
    Texture2D loadingTexture;
    VertexBuffer<GLfloat> vertexBuffer;
    VertexBuffer<GLfloat> textureBuffer;
    Shader shader;
    VertexArrayObject vao;
    IMainLoopGetter *mainLoopGetter;
    IState *stateToLoad;
    GLuint cyclesPassed = 0;

public:
    LoadingScreenState(IState *stateToLoad);

    void initialize(IMainLoopGetter *mainLoopGetter) override;
    void destroy() override;
    void loadResources() override;
    void fixedUpdate(const GLfloat deltatime) override;
    void update(const GLfloat deltatime) override;
    void draw() override;
    void preDraw() override;
    void postDraw() override;
    void input(const GLfloat deltatime) override;
    void first() override;
    void last() override;
private:

};


#endif //SDL2OPENGL_LOADINGSCREENSTATE_H
