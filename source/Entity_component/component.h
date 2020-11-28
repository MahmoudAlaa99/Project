
class Component
{

public:
  Component();
  ~Component();
  virtual void onInitialize();
  virtual void onUpdate();
  virtual void onDestroy();
};
