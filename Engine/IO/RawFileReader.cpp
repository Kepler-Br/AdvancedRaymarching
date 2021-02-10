#include "RawFileReader.h"
#include <fstream>
#include "../Exceptions/IOException.h"

std::vector<GLbyte> RawFileReader::readWholeFileAsByteArray(const std::string &path)
{
    const std::ostringstream outputStringStream = this->readWholeFileAsAsOutputStringStream(path);
    const std::string string = outputStringStream.str();
    std::vector<GLbyte> byteArray(string.begin(), string.end());

    return byteArray;
}

std::string RawFileReader::readWholeFileAsString(const std::string &path)
{
    return this->readWholeFileAsAsStringStream(path).str();
}

std::stringstream RawFileReader::readWholeFileAsAsStringStream(const std::string &path)
{
    std::ifstream fileToRead(path, std::ios::binary);
    std::stringstream stringStream;

    if(!fileToRead.is_open())
    {
        std::stringstream errorStringStream;
        errorStringStream << "File could not be opened: ";
        errorStringStream << path;
        throw IOException(errorStringStream.str());
    }
    stringStream << fileToRead.rdbuf();
    return stringStream;
}

std::ostringstream RawFileReader::readWholeFileAsAsOutputStringStream(const std::string &path)
{
    std::ifstream fileToRead(path, std::ios::binary);
    std::ostringstream outputStringStream;

    if(!fileToRead.is_open())
    {
        std::stringstream errorStringStream;
        errorStringStream << "File could not be opened: ";
        errorStringStream << path;
        throw IOException(errorStringStream.str());
    }
    outputStringStream << fileToRead.rdbuf();
    return outputStringStream;
}
