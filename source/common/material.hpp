#pragma once
#include <application.hpp>
#include "../common/sampler.hpp"
#include "../common/texture.hpp"
#include "../Entity_component/transform_component.hpp"
class Material
{
    //must be a member for every texture,shader, or sampler used
        //shader program pointers
        Project::ShaderProgram* cubeShader;
        //uniform value "first approach"
        std::vec4 tint;
        samplerClass* testsampler;
        texture2D* monarch;
        //render state pointer
        ////// /////////////////
        //transform component pointer
        TransformComponent* trans;

 
    void setCubeShader()
    {
        std::string vertex = "assets/shaders/phase_3/transform.vert";
        std::string frag = "assets/shaders/phase_3/texture.frag";
        this->cubeShader->create();
        this->cubeShader->attach(vert, GL_VERTEX_SHADER);
        this->cubeShader->attach(frag, GL_FRAGMENT_SHADER);
        this->cubeShader->link();
    }

    Project::ShaderProgram* getCubeShader()
    {
        return cubeShader;
    }

    void setMonarchtexture()
    {
        monarch->setTexture("assets/images/monarch.png");
    }

    texture2D getMonarchTexture()
    {
        return monarch;
    }

    void setDefaultSampler()
    {
        testsampler->setSampler();
    }

    samplerClass getDefaultSampler()
    {
        return testsampler;
    }   



};



for(int i=0; i<meshEntities.size(); i++){

        std::shared_ptr<MeshRenderer> meshRenderer= meshEntities[i]->getComp<MeshRenderer>();
        std::shared_ptr<Material> materialPtr = meshRenderer->getMaterial();
        std::shared_ptr<ShaderProgram> shaderProgram = materialPtr->getShaderProgram();
        glUseProgram(*shaderProgram);
        shaderProgram->set("camera_position", glm::vec3(ctptr->get_position()[3]));
        shaderProgram->set("view_projection",viewProjection);

        // We will go through all the lights and send the enabled ones to the shader.
        int light_index = 0;
        const int MAX_LIGHT_COUNT = 16;
        for(const auto& lightEntity : lights) {
            std::shared_ptr<Light> light = lightEntity->getComp<Light>();
            std::shared_ptr<Transform> lightTransform = lightEntity->getComp<Transform>();
            if(!light->enabled) continue;
            std::string prefix = "lights[" + std::to_string(light_index) + "].";

            shaderProgram->set(prefix + "type", static_cast<int>(light->lightType));
            shaderProgram->set(prefix + "color", light->color);

            switch (light->lightType) {
                case LightType::DIRECTIONAL:
                    shaderProgram->set(prefix + "direction", glm::normalize(glm::vec3(lightTransform->get_rotation()[0])));
                    break;
                case LightType::POINT:
                    shaderProgram->set(prefix + "position", glm::vec3(lightTransform->get_position()[3]));
                    shaderProgram->set(prefix + "attenuation_constant", light->attenuation.constant);
                    shaderProgram->set(prefix + "attenuation_linear", light->attenuation.linear);
                    shaderProgram->set(prefix + "attenuation_quadratic", light->attenuation.quadratic);
                    break;
                case LightType::SPOT:
                    shaderProgram->set(prefix + "position", glm::vec3(lightTransform->get_position()[3]));
                    shaderProgram->set(prefix + "direction", glm::vec3(lightTransform->get_rotation()[0]));
                    shaderProgram->set(prefix + "attenuation_constant", light->attenuation.constant);
                    shaderProgram->set(prefix + "attenuation_linear", light->attenuation.linear);
                    shaderProgram->set(prefix + "attenuation_quadratic", light->attenuation.quadratic);
                    shaderProgram->set(prefix + "inner_angle", light->spot_angle.inner);
                    shaderProgram->set(prefix + "outer_angle", light->spot_angle.outer);
                    break;
            }
            light_index++;
            if(light_index >= MAX_LIGHT_COUNT) break;
            // Since the light array in the shader has a constant size, we need to tell the shader how many lights we sent.

        }
        shaderProgram->set("light_count", light_index);
    }
