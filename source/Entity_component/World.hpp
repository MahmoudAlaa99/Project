#ifndef WORLD_HPP
#define WORLD_HPP

#include "Entity.hpp"
#include "transform_component.hpp"
#include "camera_component.hpp"
#include "fly_camera_controller_component.hpp"
#include "../Entity_component/mesh_render_component.hpp"
#include <vector>


class RenderSystem {
  private:
  std::vector<Entity*> EntityList;
  glm::mat4 camera_matrix;
  public:

  void returnCameraMat(Entity* cameraEntity)
  {
      camera_matrix = cameraEntity->returnCameraComp()->getVPMatrix();
  }

  void setManualCamera(glm::mat4 manualCam)
  {
      camera_matrix =manualCam;
  }
  
  void renderDraw()
  {
        for(const auto& object : EntityList) {
        object->returnMeshRendererComp()->meshDraw( camera_matrix * (object->returnTransformComp()->getTransform()) );
        }
  }

  void addToEntityList(Entity* E)
  {
      EntityList.push_back(E);
  }

};



// //camera entity (only has camera component)
// Entity cameraEntity;
// CameraComponent* cameraComp = new CameraComponent(); //camera must have default constructor 
// cameraEntity.addComponent(cameraComp);


// //test entity
// Entity sphereEntity;
// TransformComponent* sphereTransformComp = new TransformComponent(); //default constructor
// mesh_renderer* sphereMEshRenderer = new mesh_renderer(); //default constructors
// sphereEntity.addComponent(sphereTransformComp);
// sphereEntity.addComponent(sphereMEshRenderer);

// //render system obj
// RenderSystem render;
// render.addToEntityList(&sphereEntity); 





#endif //WORLD_HPP


// TransformComponent transformComp;
// CameraComponent cameraComp;
// FlyCameraControllerComponent cameraControllerComp;


// //cameraEntity.addComponent(transformComp);
// // cameraEntity.addComponent(cameraComp);
// // cameraEntity.addComponent(cameraControllerComp);
// glm::vec3 position = cameraEntity.components[2].getPosition();
// float yaw = cameraEntity.components[2].getYaw();
// float pitch = cameraEntity.components[2].getPitch();
// float roll = 0;     //Temp value

// glm::vec3 rotation = {yaw,pitch,roll};
// cameraEntity.components[0].setRotation(rotation);
// glm::mat4 transfromMatrix = cameraEntity.components[0].getTransform();
// cameraEntity.components[1].setTransform(transformMatrix);

// glm::vec4 eyeVec = {0,0,0,1};
// glm::vec4 directionVec = {0,0,-1,0};
// glm::vec4 upVec = {0,1,0,0};

// cameraEntity.components[1].setEye(eyeVec);
// cameraEntity.components[1].setDirection(directionVec);
// cameraEntity.components[1].setUp(upVec);

// class World{
// private:

// std::vector<Entity> EntityList;
// public:

// void addEntity(Entity E){

//   EntityList.push_back(E);
// }
// };