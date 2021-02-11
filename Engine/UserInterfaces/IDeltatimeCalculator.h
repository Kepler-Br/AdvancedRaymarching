#ifndef ADVANCEDRAYMARCHING_IDELTATIMECALCULATOR_H
#define ADVANCEDRAYMARCHING_IDELTATIMECALCULATOR_H

#include <GL/glew.h>
#include <GL/gl.h>

/// @brief Interface to be implemented by platform dependent delta time calculation class.
class IDeltatimeCalculator
{
public:
    /// @brief Should calculate deltatime every time it's called.
    virtual void calculate() noexcept = 0;
    /// @return Calculated deltatime.
    virtual const GLfloat get() const noexcept = 0;
};

#endif //ADVANCEDRAYMARCHING_IDELTATIMECALCULATOR_H
