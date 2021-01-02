#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "component.hpp"

enum class LightType {
    DIRECTIONAL,
    POINT,
    SPOT
};

class LightComponent : public Component{
  private:
    LightType type;
    bool enabled;
    glm::vec3 color;
  public:
  LightComponent()
  {
      Ctype = Light;
  }
  struct {
        float constant, linear, quadratic;
    } attenuation;                              // Used for Point and Spot Lights only
    struct {
        float inner, outer;
    } spot_angle;                              // Used for Spot Lights only
};



#endif //LIGHT_HPP