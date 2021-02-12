#include "LoadingScreenState.h"
#include "Engine/IO/IO.h"
#include "Engine/Bindings/GLShaderBindings.h"
#include "Engine/MainLoop/IStateHolder.h"

LoadingScreenState::LoadingScreenState(IState *stateToLoad)
{
    this->stateToLoad = stateToLoad;
}

void LoadingScreenState::initialize(IMainLoopGetter *mainLoopGetter)
{
    this->mainLoopGetter = mainLoopGetter;
}

void LoadingScreenState::destroy()
{
    this->shader.destroy();
    this->loadingTexture.destroy();
    this->vertexBuffer.destroy();
    this->textureBuffer.destroy();
}

void LoadingScreenState::loadResources()
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

    std::cout << "LoadingScreenState: Loading resources." << std::endl;
    if (this->resourcesLoaded)
        return;
    this->resourcesLoaded = GL_TRUE;
    this->loadingTexture.initialize(io->readBmpTexture("./Resources/Textures/loading.bmp"), GL_RGB,
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
    std::cout << "LoadingScreenState: Done loading resources." << std::endl;
}

void LoadingScreenState::fixedUpdate(const GLfloat deltatime)
{

}

void LoadingScreenState::update(const GLfloat deltatime)
{

}

void LoadingScreenState::preDraw()
{

}

void LoadingScreenState::draw()
{
    this->loadingTexture.bind();
    shader.use();
    GLuint uniformLocation = shader.getUniformLocation("tex");
    GLShaderBindings::setUniform(uniformLocation, 0);
    vao.bind();
    glDrawArrays(GL_QUADS, 0, 8);
    vao.unbind();
}

void LoadingScreenState::postDraw()
{

}

void LoadingScreenState::input(const GLfloat deltatime)
{
}

void LoadingScreenState::first()
{
    IStateHolder *stateHolder = this->mainLoopGetter->getStateHolder();

    if(this->cyclesPassed > 10)
    {
        this->stateToLoad->loadResources();
        stateHolder->replaceState(this->stateToLoad);
    }
}


void LoadingScreenState::last()
{
    this->cyclesPassed++;
}
