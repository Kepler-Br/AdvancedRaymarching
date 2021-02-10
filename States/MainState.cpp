#include "MainState.h"

#include <SDL2/SDL.h>
#include "../IO/Sdl2IO.h"
#include "GLShaderBindings.h"
#include "../MainLoop/IStateHolder.h"

void MainState::initialize(IStateHolder *stateHolder, IUserInput *userInput, glm::ivec2 &resolution)
{
    this->stateHolder = stateHolder;
    this->userInput = userInput;
    this->resolution = resolution;
}

void MainState::destroy()
{
    this->shader.destroy();
    this->loadingTexture.destroy();
    this->vertexBuffer.destroy();
    this->textureBuffer.destroy();
    delete this->io;
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

    if (this->resourcesLoaded)
        return;
    std::cout << "MainState: Loading resources." << std::endl;
    this->io = new Sdl2IO;
    this->resourcesLoaded = GL_TRUE;
    this->loadingTexture.initialize(this->io->readBmpTexture("./textures/skeletor.bmp"), GL_RGB,
                                    GL_BGR, GL_UNSIGNED_BYTE, GL_FALSE);
    this->loadingTexture.setWrap(GL_REPEAT, GL_FALSE);
    this->loadingTexture.setMagnifyingFilter(GL_NEAREST, GL_FALSE);
    this->loadingTexture.setMinifyingFilter(GL_NEAREST, GL_FALSE);
    this->loadingTexture.unbind();
    this->vertexBuffer.initialize(vertices, 8, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
    this->textureBuffer.initialize(texCoords, 8, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
    this->shader.initialize("./Shaders/vertex.vert", "./Shaders/fragment.frag");
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
    if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        this->stateHolder->popAllStates();
}

void MainState::first()
{

}


void MainState::last()
{

}

