#ifndef SDL2OPENGL_LOADINGSCREENSTATE_H
#define SDL2OPENGL_LOADINGSCREENSTATE_H

#include <iostream>
#include "../../Engine/MainLoop/IState.h"
#include "../../Engine/Incapsulated/GLTexture2D.h"
#include "../../Engine/Incapsulated/GLBuffer.h"
#include "../../Engine/Incapsulated/Shader.h"
#include "../../Engine/Incapsulated/GLVertexArrayObject.h"
#include "Engine/UserInterfaces/IIO.h"

class LoadingScreenState : public virtual IState
{
public:

private:
    GLboolean resourcesLoaded = GL_FALSE;
    GLTexture2D loadingTexture;
    GLBuffer<GLfloat> vertexBuffer;
    GLBuffer<GLfloat> textureBuffer;
    Shader shader;
    GLVertexArrayObject vao;
    IStateHolder *stateHolder;
    IUserInputGetter *userInput;
    IState *stateToLoad;
    glm::ivec2 resolution;
    GLuint cyclesPassed = 0;

public:
    LoadingScreenState(IState *stateToLoad);

    void initialize(IStateHolder *stateHolder, IUserInputGetter *userInput, const glm::ivec2 resolution) override;
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