cmake_minimum_required(VERSION 3.16)
project(AdvancedRaymarching)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")


include_directories(
        Engine/Exceptions
        Engine/Bindings
)
add_executable(AdvancedRaymarching main.cpp Engine/Incapsulated/Shader.h Engine/Incapsulated/Shader.cpp Engine/Exceptions/ShaderErrorException.h Engine/Incapsulated/GLError.h Engine/Incapsulated/GLBuffer.h Engine/Exceptions/GLErrorException.h Engine/Bindings/GLShaderBindings.h Engine/Bindings/GLShaderBindings.cpp Engine/Incapsulated/GLError.cpp Engine/Incapsulated/GLVertexArrayObject.h Engine/Bindings/GLBufferBindings.h Engine/Bindings/GLBufferBindings.cpp Engine/Incapsulated/GLVertexArrayObject.cpp Engine/Incapsulated/GLTexture2D.h Engine/Bindings/GLTextureBindings.h Engine/Bindings/GLTextureBindings.cpp Engine/IO/IIO.h Engine/IO/Sdl2IO.h Engine/IO/RawIO.h Engine/IO/Sdl2IO.cpp Engine/IO/RawIO.cpp Engine/IO/RawFileReader.h Engine/IO/RawFileReader.cpp Engine/Incapsulated/GLTexture2D.cpp Engine/MainLoop/MainLoop.h Engine/MainLoop/MainLoop.cpp Engine/MainLoop/IStateHolder.h Engine/MainLoop/IState.h Engine/MainLoop/UserInput.h Engine/MainLoop/IUserInput.h Engine/MainLoop/IUserInputSetter.h Engine/MainLoop/Commands/IMainLoopCommand.h Engine/MainLoop/Commands/MainLoopCommandPopState.h Engine/MainLoop/Commands/MainLoopCommandPopState.cpp Engine/MainLoop/Commands/MainLoopCommandPushState.h Engine/MainLoop/Commands/MainLoopCommandPushState.cpp Engine/MainLoop/Commands/MainLoopCommandPopAllStates.h Engine/MainLoop/Commands/MainLoopCommandPopAllStates.cpp Engine/MainLoop/Commands/MainLoopCommandReplaceState.h Engine/MainLoop/Commands/MainLoopCommandReplaceState.cpp States/LoadingScreenState.cpp States/LoadingScreenState.h Engine/MainLoop/UserInput.cpp States/MainState.cpp States/MainState.h Engine/Incapsulated/GLFramebuffer.cpp Engine/Incapsulated/GLFramebuffer.h Engine/Exceptions/IOException.h)
target_link_libraries(${PROJECT_NAME}
        GLEW
        SDL2
        GL
        )