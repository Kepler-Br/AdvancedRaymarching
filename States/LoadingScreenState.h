#ifndef SDL2OPENGL_LOADINGSCREENSTATE_H
#define SDL2OPENGL_LOADINGSCREENSTATE_H

#include <iostream>
#include "../MainLoop/IState.h"
#include "../Incapsulated/GLTexture2D.h"
#include "../Incapsulated/GLBuffer.h"
#include "../Incapsulated/Shader.h"
#include "../Incapsulated/GLVertexArrayObject.h"
#include "../IO/IIO.h"

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
    IIO *io;
    IStateHolder *stateHolder;
    IUserInput *userInput;
    IState *stateToLoad;
    glm::ivec2 resolution;
    GLuint cyclesPassed = 0;

public:
    LoadingScreenState(IState *stateToLoad);

    void initialize(IStateHolder *stateHolder, IUserInput *userInput, glm::ivec2 &resolution) override;
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
