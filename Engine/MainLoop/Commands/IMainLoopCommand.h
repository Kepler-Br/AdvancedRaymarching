#ifndef SDL2OPENGL_IMAINLOOPCOMMAND_H
#define SDL2OPENGL_IMAINLOOPCOMMAND_H

#include <stack>

class IMainLoopCommand
{
public:
    virtual void execute() = 0;
};

#endif //SDL2OPENGL_IMAINLOOPCOMMAND_H
