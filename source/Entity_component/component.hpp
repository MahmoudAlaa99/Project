#pragma once
enum ComponentType{
  Camera,
  Transformation,
  MeshRenderer,
  my
};

class Component
{
public:
  ComponentType Ctype;
  Component() {
    Ctype = my;
  };
  ~Component() {};
  // virtual void onInitialize();
  // virtual void onUpdate();
  // virtual void onDestroy();
};
