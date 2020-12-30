#pragma once
#include "../common/texture/texture-utils.h"
#include <string>

class samplerClass
{
    GLuint sampler;
    GLenum magnification_filter = GL_LINEAR, minification_filter = GL_LINEAR_MIPMAP_LINEAR;
    GLenum wrap_s = GL_REPEAT, wrap_t = GL_REPEAT;
    glm::vec4 border_color = {1,1,1,1};
    GLfloat max_anisotropy = 1.0f;


    public:
    samplerClass()
    {}
    void setSampler()
    {
        glGenSamplers(1, &(this->sampler));
        glSamplerParameteri((this->sampler), GL_TEXTURE_MAG_FILTER, magnification_filter);
        glSamplerParameteri((this->sampler), GL_TEXTURE_MIN_FILTER, minification_filter);
        glSamplerParameteri((this->sampler), GL_TEXTURE_WRAP_S, wrap_s);
        glSamplerParameteri((this->sampler), GL_TEXTURE_WRAP_T, wrap_t);
        glSamplerParameterfv((this->sampler), GL_TEXTURE_BORDER_COLOR, glm::value_ptr(border_color));
        glSamplerParameterf((this->sampler), GL_TEXTURE_MAX_ANISOTROPY_EXT, max_anisotropy);
    }
    GLuint getSampler()
    {
        return (this->sampler);
    }
    void setOptions(GLenum in_magnification_filter,GLenum in_minification_filter,GLenum in_wrap_s, GLenum in_wrap_t,
    glm::vec4 in_border_color,GLfloat in_max_anisotropy)
    {
        magnification_filter = in_magnification_filter;
        minification_filter = in_minification_filter;
        wrap_s = in_wrap_s;
        wrap_t = in_wrap_t;
        border_color = in_border_color;
        max_anisotropy = in_max_anisotropy;
    }


    samplerClass(samplerClass const &) = delete;
    samplerClass &operator=(samplerClass const &) = delete;

};



//global function to bind will be written in material class 

void texturesamplerBind(GLuint texture, GLuint sampler)
{
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBindSampler(0, sampler);
        //send the sampler as a uniform to the shader
        //program.set("sampler", 0);
}