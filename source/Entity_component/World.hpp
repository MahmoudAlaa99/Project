#ifndef WORLD_HPP
#define WORLD_HPP

#include "Entity.hpp"
#include "transform_component.hpp"
#include "camera_component.hpp"
#include "fly_camera_controller_component.hpp"
#include "../Entity_component/mesh_render_component.hpp"
#include <vector>
#include "../common/material.hpp"
#include "../common/shader.hpp"
#include "../Entity_component/light_component.hpp"


class RenderSystem {
  private:
  std::vector<Entity*> EntityList;
  glm::mat4 camera_matrix;
  std::vector<Entity*> Lights;
  public:

  void returnCameraMat(Entity* cameraEntity)
  {
      camera_matrix = cameraEntity->returnCameraComp()->getVPMatrix();
  }

  void setManualCamera(glm::mat4 manualCam)
  {
      camera_matrix =manualCam;
  }
  void getLights()
  {
      for(int i=0; i<EntityList.size(); i++){
        if(EntityList[i]->returnLightComp() != NULL)
        {
            Lights.push_back(EntityList[i]);
        }
      }
  }
//   void drawNode(const std::shared_ptr<Transform>& node, const glm::mat4& parent_transform_matrix){
//         glm::mat4 transform_matrix = parent_transform_matrix * node->to_mat4();
//         if(node->mesh.has_value()){
//             auto it = meshes.find(node->mesh.value());
//             if(it != meshes.end()) {
//                 program.set("tint", node->tint);
//                 program.set("transform", transform_matrix);
//                 it->second->draw();
//             }
//         }
//         for(auto& [name, child]: node->children){
//             drawNode(child, transform_matrix);
//         }
//     }
  void renderDraw()
  {

        for(int i=0; i<EntityList.size(); i++){

        mesh_renderer* meshRenderer= EntityList[i]->returnMeshRendererComp();
        Material* materialPtr = meshRenderer->getMaterial();

        Project::ShaderProgram* shaderProgram = &(materialPtr->getShaderByNumber());
        glUseProgram(*shaderProgram);
        ///////
        shaderProgram->set("camera_position", glm::vec3({1,1,1}));
        shaderProgram->set("view_projection",camera_matrix);
        ///////
        // We will go through all the lights and send the enabled ones to the shader.
        int light_index = 0;
        const int MAX_LIGHT_COUNT = 16;
        for(const auto& lightEntity : Lights) {
            LightComponent* light = lightEntity->returnLightComp();
            TransformComponent* lightTransform = lightEntity->returnTransformComp();
            if(!(light->enabled)) continue;
            std::string prefix = "lights[" + std::to_string(light_index) + "].";

            shaderProgram->set(prefix + "type", static_cast<int>(light->lightType));
            shaderProgram->set(prefix + "color", light->color);

            switch (light->lightType) {
                case LightType::DIRECTIONAL:
                    shaderProgram->set(prefix + "direction", glm::normalize(glm::vec3(lightTransform->rotation)));
                    break;
                case LightType::POINT:
                    shaderProgram->set(prefix + "position", glm::vec3(lightTransform->position));
                    shaderProgram->set(prefix + "attenuation_constant", light->attenuation.constant);
                    shaderProgram->set(prefix + "attenuation_linear", light->attenuation.linear);
                    shaderProgram->set(prefix + "attenuation_quadratic", light->attenuation.quadratic);
                    break;
                case LightType::SPOT:
                    shaderProgram->set(prefix + "position", glm::vec3(lightTransform->position));
                    shaderProgram->set(prefix + "direction", glm::vec3(lightTransform->rotation));
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
        for(const auto& object : EntityList) {
        object->returnMeshRendererComp()->meshDraw( camera_matrix * (object->returnTransformComp()->getTransform()) );
        }
    //     for (unsigned int i = 0; i < EntityList.size(); ++i)
	// {
    //     std:: shared_ptr<TransformComponent> tptr = EntityList[i]->returnTransformComp();
    //     //Call this recursive function only on parent nodes
    //     if(tptr->getParent() == nullptr){

    //         this->drawNode(tptr,viewProjection);
    //     }

    // }
  }

  void addToEntityList(Entity* E)
  {
      EntityList.push_back(E);
  }

};


#endif //WORLD_HPP
