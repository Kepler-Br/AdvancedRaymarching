#ifndef SDL2OPENGL_MAINSTATE_H
#define SDL2OPENGL_MAINSTATE_H

#include <iostream>
#include "Engine/MainLoop/IState.h"
#include "Engine/Incapsulated/Texture2D.h"
#include "Engine/Incapsulated/VertexBuffer.h"
#include "Engine/Incapsulated/Shader.h"
#include "Engine/Incapsulated/VertexArrayObject.h"
#include "Engine/UserInterfaces/IIO.h"
#include "Engine/MainLoop/IMainLoopGetter.h"

class MainState : public virtual IState
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

public:
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


#endif //SDL2OPENGL_MAINSTATE_H
