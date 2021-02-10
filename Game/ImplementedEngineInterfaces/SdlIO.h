#ifndef ADVANCEDRAYMARCHING_SDLIO_H
#define ADVANCEDRAYMARCHING_SDLIO_H

#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec2.hpp>
#include "Engine/UserInterfaces/IIO.h"

class SdlIO : public virtual IIO
{
public:
    std::vector<GLbyte> readWholeFileAsByteArray(const std::string &path) const override;
    std::string readWholeFileAsString(const std::string &path) const override;
    std::stringstream readWholeFileAsAsStringStream(const std::string &path) const override;
    std::ostringstream readWholeFileAsAsOutputStringStream(const std::string &path) const override;
    std::tuple<glm::ivec2, std::vector<GLbyte>> readBmpTexture(const std::string &path) const override;
    std::tuple<glm::ivec2, std::vector<GLbyte>> readPngTexture(const std::string &path) const override;
    std::tuple<glm::ivec2, std::vector<GLbyte>> readJpegTexture(const std::string &path) const override;
};


#endif //ADVANCEDRAYMARCHING_SDLIO_H
