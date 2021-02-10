#define GLEW_STATIC
#include <string>
#include "./States/LoadingScreenState.h"
#include "./States/MainState.h"
#include "Engine/MainLoop/MainLoop.h"
#include "ImplementedEngineInterfaces/OpenGLSdlWindow.h"
#include "ImplementedEngineInterfaces/SdlUserInput.h"
#include "ImplementedEngineInterfaces/SdlDeltatimeCalculator.h"
#include "ImplementedEngineInterfaces/SdlIO.h"
#include "Engine/IO/IO.h"

int main(int argc, char **argv)
{
    MainLoop *mainLoop;
    OpenGLSdlWindow *window;
    SdlUserInput *userInput;
    SdlDeltatimeCalculator *deltatimeCalculator;
    SdlIO *IOImplementation;

    window = new OpenGLSdlWindow(960, 544, "Advanced raymarching");
    userInput = new SdlUserInput;
    deltatimeCalculator = new SdlDeltatimeCalculator;
    IOImplementation = new SdlIO;
    IO::setInstance(IOImplementation);

    mainLoop = new MainLoop(window, userInput, deltatimeCalculator);
    mainLoop->pushState(new LoadingScreenState(new MainState));
    mainLoop->run();

    delete mainLoop;
    delete window;
    delete userInput;
    delete deltatimeCalculator;
    delete IOImplementation;
    return 0;
}