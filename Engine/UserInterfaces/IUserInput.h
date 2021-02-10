#ifndef ADVANCEDRAYMARCHING_IUSERINPUT_H
#define ADVANCEDRAYMARCHING_IUSERINPUT_H

#include "IUserInputGetter.h"
#include "IUserInputSetter.h"

/// @brief Interface to be implemented by platform dependent user input class.
class IUserInput : public virtual IUserInputGetter, public virtual IUserInputSetter
{};

#endif //ADVANCEDRAYMARCHING_IUSERINPUT_H
