#pragma once
#include "../common/texture/texture-utils.h"
#include <string>

class texture2D
{
    GLuint texture;

    public:
    texture2D()
    {}
    void setTexture(const char* fileName)
    {
        glGenTextures(1, &texture);
        Project::texture_utils::loadImage(texture,fileName);
    }
    GLuint getTexture()
    {
        return texture;
    }
    texture2D(texture2D const &) = delete;
    texture2D &operator=(texture2D const &) = delete;

};