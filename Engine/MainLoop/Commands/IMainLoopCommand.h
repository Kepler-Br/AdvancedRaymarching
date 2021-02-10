#ifndef SDL2OPENGL_IMAINLOOPCOMMAND_H
#define SDL2OPENGL_IMAINLOOPCOMMAND_H

#include <stack>

/// @brief Interface that each MainLoop state class should implement.
class IMainLoopCommand
{
public:
    /// @brief Starts the command. Alters MainLoop internal state stack.
    virtual void execute() const = 0;
};

#endif //SDL2OPENGL_IMAINLOOPCOMMAND_H
