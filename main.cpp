#include <SDL2/SDL.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <iostream>
#include "States/LoadingScreenState.h"
#include "States/MainState.h"
#include "./Engine/MainLoop/MainLoop.h"


static const GLuint WIDTH = 960;
static const GLuint HEIGHT = 544;

int main(int argc, char **argv)
{
    SDL_GLContext gl_context;
    SDL_Window *window;
    MainLoop *mainLoop;

    std::cout << "Init SDL..." << std::endl;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(__FILE__, 0, 0,
                              WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    gl_context = SDL_GL_CreateContext(window);
    glewInit();
    std::cout << "Done." << std::endl;

    mainLoop = new MainLoop(glm::ivec2(WIDTH, HEIGHT), window);
    mainLoop->pushState(new LoadingScreenState(new MainState));
    mainLoop->run();
    delete mainLoop;

    std::cout << "Destroying SDL." << std::endl;
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}