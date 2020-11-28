#include "component.hpp"
#include <vector>
#include <memory>
class Entity
{
    //define array of components for each entity
    std::vector<Component> components;
    unsigned int ID;

public:
  Entity();
  ~Entity();
  virtual void onInitialize();
  virtual void onUpdate();
  virtual void onDestroy();

  bool hasComponents();
  bool removeComponent();
  std::shared_ptr<Component> addComp();

};
