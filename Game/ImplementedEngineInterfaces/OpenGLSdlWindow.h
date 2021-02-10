#ifndef ADVANCEDRAYMARCHING_WINDOW_H
#define ADVANCEDRAYMARCHING_OPENGLSDLWINDOW_H

#include <string>
#include <glm/vec2.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "Engine/UserInterfaces/IWindow.h"

class OpenGLSdlWindow : public virtual IWindow
{
public:

private:
    glm::ivec2 resolution;
    std::string title;
    GLboolean isCleanEnabled = GL_TRUE;
    SDL_GLContext glContext;
    SDL_Window *window;

public:
    OpenGLSdlWindow(const GLuint width, const GLuint height, const std::string &title = "");
    ~OpenGLSdlWindow();
    // IStateWindow implementation.
    glm::ivec2 getResolution() const noexcept override;
    void disableClean() noexcept override;
    void enableClean() noexcept override;
    void setTitle(const std::string &newTitle) noexcept override;
    // IWindow implementation.
    void swapBuffers() noexcept override;
    void clear() noexcept override;
private:
    void initialize();
};

#endif //ADVANCEDRAYMARCHING_WINDOW_H
