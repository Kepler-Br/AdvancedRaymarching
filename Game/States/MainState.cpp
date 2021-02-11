#include "MainState.h"
#include <SDL2/SDL.h>
#include "Engine/IO/IO.h"
#include "Engine/Bindings/GLShaderBindings.h"
#include "../../Engine/MainLoop/IStateHolder.h"

void MainState::initialize(IMainLoopGetter *mainLoopGetter)
{
    this->mainLoopGetter = mainLoopGetter;
}

void MainState::destroy()
{
    this->shader.destroy();
    this->loadingTexture.destroy();
    this->vertexBuffer.destroy();
    this->textureBuffer.destroy();
}

void MainState::loadResources()
{
    static GLfloat vertices[] = {
            -1.0,  -1.0,
            -1.0, 1.0,
            1.0, 1.0,
            1.0, -1.0,
    };
    static GLfloat texCoords[] = {
            0.0,  0.0,
            0.0, 1.0,
            1.0, 1.0,
            1.0, 0.0,
    };
    const IIO *io = IO::getInstance();

    if (this->resourcesLoaded)
        return;
    std::cout << "MainState: Loading resources." << std::endl;
    this->resourcesLoaded = GL_TRUE;
    this->loadingTexture.initialize(io->readBmpTexture("./Resources/Textures/skeletor.bmp"), GL_RGB,
                                    GL_BGR, GL_UNSIGNED_BYTE, GL_FALSE);
    this->loadingTexture.setWrap(GL_REPEAT, GL_FALSE);
    this->loadingTexture.setMagnifyingFilter(GL_NEAREST, GL_FALSE);
    this->loadingTexture.setMinifyingFilter(GL_NEAREST, GL_FALSE);
    this->loadingTexture.unbind();
    this->vertexBuffer.initialize(vertices, 8, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
    this->textureBuffer.initialize(texCoords, 8, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
    this->shader.initialize("./Resources/Shaders/vertex.vert", "./Resources/Shaders/fragment.frag");
    this->vao.bind();
    this->vertexBuffer.bind();
    GLint attributeTextureCoords = shader.getAttributeLocation("texCoord");
    GLint attributeCoords = shader.getAttributeLocation("coord2d");
    GLBufferBindings::setupAttributePointer(attributeCoords, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    GLBufferBindings::enableAttribute(attributeCoords);
    this->textureBuffer.bind();
    GLBufferBindings::setupAttributePointer(attributeTextureCoords, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    GLBufferBindings::enableAttribute(attributeTextureCoords);
    vao.unbind();
    std::cout << "MainState: Done loading resources." << std::endl;
}

void MainState::fixedUpdate(const GLfloat deltatime)
{

}

void MainState::update(const GLfloat deltatime)
{

}

void MainState::draw()
{
    this->loadingTexture.bind();
    shader.use();
    GLuint uniformLocation = shader.getUniformLocation("inputTexture");
    GLShaderBindings::setUniform(uniformLocation, 0);
    vao.bind();
    glDrawArrays(GL_QUADS, 0, 8);
    vao.unbind();
}

void MainState::preDraw()
{

}

void MainState::postDraw()
{

}

void MainState::input(const GLfloat deltatime)
{
    SDL_Event event;
    IStateHolder *stateHolder = this->mainLoopGetter->getStateHolder();

    if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        stateHolder->popAllStates();
}

void MainState::first()
{

}


void MainState::last()
{

}

