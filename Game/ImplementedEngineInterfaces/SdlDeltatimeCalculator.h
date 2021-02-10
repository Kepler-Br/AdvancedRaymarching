#ifndef ADVANCEDRAYMARCHING_SDLDELTATIMECALCULATOR_H
#define ADVANCEDRAYMARCHING_SDLDELTATIMECALCULATOR_H

#include "Engine/UserInterfaces/IDeltatimeCalculator.h"

class SdlDeltatimeCalculator : public virtual IDeltatimeCalculator
{
public:

private:

public:
    void calculate() noexcept override;
    GLfloat get() const noexcept override;
private:

};


#endif //ADVANCEDRAYMARCHING_SDLDELTATIMECALCULATOR_H
