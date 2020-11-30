#ifndef WORLD_HPP
#define WORLD_HPP

#include "Entity.hpp"
#include "transform_component.hpp"
#include "camera_component.hpp"
#include "fly_camera_controller_component.hpp"
#include <vector>

class World{
private:

std::vector<Entity> EntityList;
public:

void addEntity(Entity E){

  EntityList.push_back(E);
}
};
Entity cameraEntity;
TransformComponent transformComp;
CameraComponent cameraComp;
FlyCameraControllerComponent cameraControllerComp;


cameraEntity.addComponent(transformComp);
cameraEntity.addComponent(cameraComp);
cameraEntity.addComponent(cameraControllerComp);
glm::vec3 position = cameraEntity.components[2].getPosition();
float yaw = cameraEntity.components[2].getYaw();
float pitch = cameraEntity.components[2].getPitch();
float roll = 0;     //Temp value

glm::vec3 rotation = {yaw,pitch,roll};
cameraEntity.components[0].setRotation(rotation);
glm::mat4 transfromMatrix = cameraEntity.components[0].getTransform();
cameraEntity.components[1].setTransform(transformMatrix);

glm::vec4 eyeVec = {0,0,0,1};
glm::vec4 directionVec = {0,0,-1,0};
glm::vec4 upVec = {0,1,0,0};

cameraEntity.components[1].setEye(eyeVec);
cameraEntity.components[1].setDirection(directionVec);
cameraEntity.components[1].setUp(upVec);

#endif //WORLD_HPP