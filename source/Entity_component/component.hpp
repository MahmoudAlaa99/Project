#pragma once
enum ComponentType{
  Camera,
  Transformation,
  MeshRenderer,
  Default,
  CameraController
};

class Component
{
public:
  ComponentType Ctype;
  Component() {
    Ctype = Default;
  };
  ~Component() {};
  // virtual void onInitialize();
  // virtual void onUpdate();
  // virtual void onDestroy();
};
