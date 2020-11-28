#include "component.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>

class TransformComponent : public Component
{
public:
    glm::mat4 position;
    glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
    TransformComponent *parent;
    

    TransformComponent(
            const glm::vec3& translation = {0,0,0},
            const glm::vec3& rotation = {0,0,0},
            const glm::vec3& scale = {1,1,1}
            ): translation(translation), rotation(rotation), scale(scale) {}

    glm::mat4 to_mat4() const {
        return glm::translate(glm::mat4(1.0f), translation) *
               glm::yawPitchRoll(rotation.y, rotation.x, rotation.z) *
               glm::scale(glm::mat4(1.0f), scale);
    }
    glm::mat4 getPosition()
    {
        position*= to_mat4();
    }

};
