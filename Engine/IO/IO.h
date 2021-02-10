#ifndef ADVANCEDRAYMARCHING_IO_H
#define ADVANCEDRAYMARCHING_IO_H

#include <stdexcept>
#include "../UserInterfaces/IIO.h"

/// @brief Class that provides access to platform dependent IO implementation.
/// @warning Yes, it's singleton. Be careful.
class IO
{
public:

private:
    static IIO *IOInterface;

public:
    /// @brief Set platform dependent IO implementation.
    /// @param IOInterface Platform dependent IO implementation
    /// @warning You probably should not touch it inside IState heirs.
    static void setInstance(IIO *IOInterface) noexcept;

    /// @brief Returns platform dependent IO implementation.
    /// @throw std::runtime_error if implementation was not set.
    /// @return Platform dependent IO implementation
    static const IIO *getInstance();
private:

};

#endif //ADVANCEDRAYMARCHING_IO_H
