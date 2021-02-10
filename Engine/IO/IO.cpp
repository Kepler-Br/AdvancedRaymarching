#include "IO.h"

IIO *IO::IOInterface = nullptr;

void IO::setInstance(IIO *IOInterface) noexcept
{
    IO::IOInterface = IOInterface;
}

const IIO *IO::getInstance()
{
    if (IOInterface == nullptr)
        throw std::runtime_error("IO implementation was not set.");
    return IO::IOInterface;
}