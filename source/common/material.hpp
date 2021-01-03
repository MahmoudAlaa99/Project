#pragma once
#include <application.hpp>
#include "../common/sampler.hpp"
#include "../common/texture2D.hpp"
#include "../Entity_component/transform_component.hpp"
class Material
{
     public:
        Project::ShaderProgram cubeShader;
        Project::ShaderProgram lightShader;
        texture2D monarch;
        //uniforms
        glm::vec4 tint = glm::vec4(1,1,1,1);
        int shaderNumber;



    Material(int materialShader){
        this->shaderNumber= materialShader;
    }
    void setTint(glm::vec4 in)
    {
        tint = in;
    }
    // void setTransform(glm::mat4 in_transform)
    // {
    //     transform = in_transform;
    // }
    // glm::mat4 getTransform()
    // {
    //     return transform;
    // }
    void setCubeShader()
    {
        std::string vertex = "assets/shaders/phase_3/transform.vert";
        std::string frag = "assets/shaders/phase_3/texture.frag";
        cubeShader.create();
        cubeShader.attach(vertex, GL_VERTEX_SHADER);
        cubeShader.attach(frag, GL_FRAGMENT_SHADER);
        cubeShader.link();
        //cubeShader.set("tint",tint);
    }
    void setLightShader()
    {
        lightShader.create();
        lightShader.attach("assets/shaders/phase_3/light_transform.vert", GL_VERTEX_SHADER);
        lightShader.attach("assets/shaders/phase_3/light_array.frag", GL_FRAGMENT_SHADER);
        lightShader.link();
    }
    void setMonarchtexture()
    {
        monarch.setTexture("assets/images/monarch.png");
    }
  

    Project::ShaderProgram& getShaderByNumber()
    {
        if(shaderNumber == 1)
            return this->cubeShader;
        else if (shaderNumber == 2)
            return this->lightShader;
        else
            this->cubeShader;
        
    }



};


