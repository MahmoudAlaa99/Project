#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <vector>
#include <memory>

#include "../Entity_component/mesh_render_component.hpp"
#include "../Entity_component/camera_component.hpp"

#include "../Entity_component/fly_camera_controller_component.hpp"
#include "../Entity_component/transform_component.hpp"
#include  "../Entity_component/fly_camera_controller_component.hpp"

class Entity
{
  std::vector<Component *> components;
  //unsigned int ID;

public:
  Entity()
  {}
  void addComponent(Component *C)
  {
    components.push_back(C);
  }
  
  CameraComponent *returnCameraComp()
  {

    std::vector<Component *>::iterator i;
    for (i = components.begin(); i != components.end(); i++)
    {
      if ((*i)->Ctype == Camera)
      {
        return (CameraComponent *)(*i);
      }
    }
    return NULL;
  }
  FlyCameraControllerComponent *returnControllerComp()
  {
    std::vector<Component *>::iterator i;
    for (i = components.begin(); i != components.end(); i++)
    {
      if ((*i)->Ctype == CameraController)
      {
        return (FlyCameraControllerComponent *)(*i);
      }
    }
    return NULL;
  }

  TransformComponent *returnTransformComp()
  {
    std::vector<Component *>::iterator i;
    for (i = components.begin(); i != components.end(); i++)
    {
      if ((*i)->Ctype == Transformation)
        return (TransformComponent *)(*i);
    }
    return NULL;
  }

  mesh_renderer *returnMeshRendererComp()
  {
    std::vector<Component *>::iterator i;
    for (i = components.begin(); i != components.end(); i++)
    {
      if ((*i)->Ctype == MeshRenderer)
      {
        return (mesh_renderer *)(*i);
      }
    }
    return NULL;
  }
};

#endif //ENTITY_HPP