#pragma once
#include "../Entity_component/component.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>

class TransformComponent : public Component
{
public:
    glm::mat4 position;
    glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
    TransformComponent *parent;
    

    TransformComponent()
    {
            translation = glm::vec3{0,0,0};
            rotation = glm::vec3{0,0,0};
            scale = glm::vec3{5,5,5};
            Ctype = Transformation;
    }
    TransformComponent(glm::vec3 translationI ,glm::vec3 rotationI,glm::vec3 scaleI )
    {
            translation = translationI;
            rotation = rotationI;
            scale = scaleI;
            Ctype = Transformation;
    }

    glm::mat4 getTransform() const {
        return glm::translate(glm::mat4(1.0f), translation) *
               glm::yawPitchRoll(rotation.y, rotation.x, rotation.z) *
               glm::scale(glm::mat4(1.0f), scale);
    }
    glm::mat4 getPosition()
    {
        position*= getTransform();
    }
    void setRotation(glm::vec3 R){
        rotation = R;
    }
    void setTranslation(glm::vec3 T){
        translation = T;
    }
    void setScale(glm::vec3 S){
        scale = S;
    }

};
