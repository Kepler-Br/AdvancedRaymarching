#include "OpenGLSdlWindow.h"

OpenGLSdlWindow::OpenGLSdlWindow(const GLuint width, const GLuint height, const std::string &title)
{
    this->title = title;
    this->resolution = glm::ivec2(width, height);
    this->initialize();
}

OpenGLSdlWindow::~OpenGLSdlWindow()
{
    SDL_GL_DeleteContext(this->glContext);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

glm::ivec2 OpenGLSdlWindow::getResolution() const noexcept
{
    return resolution;
}

void OpenGLSdlWindow::setClean(GLboolean shouldCleanWindow) noexcept
{
    this->isCleanEnabled = shouldCleanWindow;
}

void OpenGLSdlWindow::setTitle(const std::string &newTitle) noexcept
{
    this->title = newTitle;
    SDL_SetWindowTitle(this->window, this->title.c_str());
}

void OpenGLSdlWindow::swapBuffers() noexcept
{
    SDL_GL_SwapWindow(this->window);
}

void OpenGLSdlWindow::clear() noexcept
{
    if (this->isCleanEnabled)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLSdlWindow::initialize()
{
    SDL_Init(SDL_INIT_VIDEO);
    this->window = SDL_CreateWindow(this->title.c_str(), 0, 0,
                                    this->resolution.x, this->resolution.y, SDL_WINDOW_OPENGL);
    this->glContext = SDL_GL_CreateContext(window);
    glewInit();
}
