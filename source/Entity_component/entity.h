#include "component.h"

class Entity
{
    //define array of components for each entity
    Component components[];

public:
  Entity();
  ~Entity();
  virtual void onInitialize();
  virtual void onUpdate();
  virtual void onDestroy();
};
