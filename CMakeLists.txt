cmake_minimum_required(VERSION 3.16)
project(AdvancedRaymarching)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")


include_directories(
        .
)
add_executable(AdvancedRaymarching
        Game/main.cpp
        Engine/Incapsulated/Shader.h
        Engine/Incapsulated/Shader.cpp
        Engine/Exceptions/ShaderErrorException.h
        Engine/Incapsulated/GLError.h
        Engine/Incapsulated/GLBuffer.h
        Engine/Exceptions/GLErrorException.h
        Engine/Bindings/GLShaderBindings.h
        Engine/Bindings/GLShaderBindings.cpp
        Engine/Incapsulated/GLError.cpp
        Engine/Incapsulated/GLVertexArrayObject.h
        Engine/Bindings/GLBufferBindings.h
        Engine/Bindings/GLBufferBindings.cpp
        Engine/Incapsulated/GLVertexArrayObject.cpp
        Engine/Incapsulated/GLTexture2D.h
        Engine/Bindings/GLTextureBindings.h
        Engine/Bindings/GLTextureBindings.cpp
        Engine/UserInterfaces/IIO.h
        Engine/Incapsulated/GLTexture2D.cpp
        Engine/MainLoop/MainLoop.h
        Engine/MainLoop/MainLoop.cpp
        Engine/MainLoop/IStateHolder.h
        Engine/MainLoop/IState.h
        Engine/UserInterfaces/IUserInputGetter.h
        Engine/UserInterfaces/IUserInputSetter.h
        Engine/MainLoop/Commands/IMainLoopCommand.h
        Engine/MainLoop/Commands/MainLoopCommandPopState.h
        Engine/MainLoop/Commands/MainLoopCommandPopState.cpp
        Engine/MainLoop/Commands/MainLoopCommandPushState.h
        Engine/MainLoop/Commands/MainLoopCommandPushState.cpp
        Engine/MainLoop/Commands/MainLoopCommandPopAllStates.h
        Engine/MainLoop/Commands/MainLoopCommandPopAllStates.cpp
        Engine/MainLoop/Commands/MainLoopCommandReplaceState.h
        Engine/MainLoop/Commands/MainLoopCommandReplaceState.cpp
        Game/States/LoadingScreenState.cpp
        Game/States/LoadingScreenState.h
        Game/States/MainState.cpp
        Game/States/MainState.h
        Engine/Incapsulated/GLFramebuffer.cpp
        Engine/Incapsulated/GLFramebuffer.h
        Engine/Exceptions/IOException.h
        Engine/UserInterfaces/IWindow.h
        Engine/UserInterfaces/IDeltatimeCalculator.h
        Engine/UserInterfaces/IUserInput.h
        Engine/UserInterfaces/IStateWindow.h
        Game/ImplementedEngineInterfaces/OpenGLSdlWindow.h
        Game/ImplementedEngineInterfaces/OpenGLSdlWindow.cpp Game/ImplementedEngineInterfaces/SdlUserInput.cpp Game/ImplementedEngineInterfaces/SdlUserInput.h Game/ImplementedEngineInterfaces/SdlDeltatimeCalculator.cpp Game/ImplementedEngineInterfaces/SdlDeltatimeCalculator.h Engine/IO/IO.h Game/ImplementedEngineInterfaces/SdlIO.cpp Game/ImplementedEngineInterfaces/SdlIO.h Engine/IO/IO.cpp)
target_link_libraries(${PROJECT_NAME}
        GLEW
        SDL2
        GL
        )