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
    bool direction;
    

    TransformComponent()
    {
            translation = glm::vec3{0.5,0.5,0.5};
            rotation = glm::vec3{0,0,0};
            scale = glm::vec3{5,5,5};
            Ctype = Transformation;
            direction = false;
            parent = NULL;
    }
    TransformComponent(glm::vec3 translationI ,glm::vec3 rotationI,glm::vec3 scaleI )
    {
            translation = translationI;
            rotation = rotationI;
            scale = scaleI;
            Ctype = Transformation;
            parent = NULL;
    }
    void setParent(TransformComponent *parentIn)
    {
        std::cout << "xx";
        parent = parentIn;
    }
    TransformComponent * getParent(){
        return parent;
        }
    glm::mat4 getTransform() const {
        if (parent == NULL)
        {
            return glm::translate(glm::mat4(1.0f), translation) *
               glm::yawPitchRoll(rotation.y, rotation.x, rotation.z) *
               glm::scale(glm::mat4(1.0f), scale);
        }
        else {
            return (parent->getTransform())*(glm::translate(glm::mat4(1.0f), translation) *
               glm::yawPitchRoll(rotation.y, rotation.x, rotation.z) *
               glm::scale(glm::mat4(1.0f), scale));
        }
    }
    void getPosition()
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
    void updateSphere(Project::Application* app,double delta_time){
        
           if(translation.y > 8.5) direction = true;
           if(direction == true) translation.y -= 0.5;
           else translation.y += 0.5;
           if(translation.y < -20) direction = false;
           rotation.z+= 0.05;
        
    }
    void updateCube(Project::Application* app,double delta_time){
        
           if(translation.x > 11) direction = true;
           if(direction == true) translation.x -= 0.5;
           else translation.x += 0.5;
           if(translation.x < -30) direction = false;
           rotation.z+= 0.05;
        
    }
};
