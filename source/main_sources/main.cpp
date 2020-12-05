

#include <application.hpp>
#include <shader.hpp>
#include <imgui-utils/utils.hpp>

#include <mesh/mesh.hpp>
#include <mesh/mesh-utils.hpp>

#include <glm/gtx/euler_angles.hpp>

#include "../Entity_component/mesh_render_component.hpp"
#include "../Entity_component/camera_component.hpp"

#include "../Entity_component/fly_camera_controller_component.hpp"
#include "../Entity_component/World.hpp"
#include "../Entity_component/transform_component.hpp"
#include "../Entity_component/fly_camera_controller_component.hpp"
#include <string>

class CameraProjectionApplication : public Project::Application
{
    CameraComponent *cameraComp = new CameraComponent();
    FlyCameraControllerComponent *controllerComp = new FlyCameraControllerComponent(); 
    Project::ShaderProgram program;
    Project::Mesh model;
    Project::Mesh model1;
    Project::Mesh model2;
    mesh_renderer *obj1;
    mesh_renderer *obj2;
    mesh_renderer *obj3;
    mesh_renderer *sphereMEshRenderer;
    Entity *cameraEntity = new Entity();
    Entity* sphereEntity = new Entity();;
    RenderSystem render;

    Project::WindowConfiguration getWindowConfiguration() override
    {
        return {"Projection", {1280, 720}, false};
    }


    void onInitialize() override
    {
        std::string vertex = "assets/shaders/phase_1/transform.vert";
        std::string frag = "assets/shaders/phase_1/tint.frag";

        // Project::mesh_utils::Cuboid(model, true);
        Project::mesh_utils::Sphere(model1, {32, 16}, true);
        // Project::mesh_utils::Plane(model2, {1, 1}, true);

        Project::Mesh *ptr01 = &model1;
        glClearColor(0, 0, 0, 0);

        Project::ShaderProgram *shaderPtr = &program;
         int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        cameraComp->setEyePosition({10, 10, 10});
        cameraComp->setTarget({0, 0, 0});
        cameraComp->setUp({0, 1, 0});
        cameraComp->setupPerspective(glm::pi<float>()/2, static_cast<float>(width)/height, 0.1f, 100.0f);

        Component *cameraTemp = cameraComp;
        cameraEntity->addComponent(cameraTemp);

        Component* controllerTemp = controllerComp;
        cameraEntity->addComponent(controllerTemp);
        CameraComponent* CC = cameraEntity->returnCameraComp();
        cameraEntity->returnControllerComp()->initialize(this, CC );

//////////////// byresm el entity /////////////////////////////////
        TransformComponent *sphereTransformComp = new TransformComponent(); 
        sphereMEshRenderer = new mesh_renderer(shaderPtr, ptr01);  
        Component *temp01 = sphereTransformComp;
        Component *temp02 = sphereMEshRenderer;          
        sphereEntity->addComponent(temp01);
        sphereEntity->addComponent(temp02);
        sphereEntity->returnMeshRendererComp()->initialize(vertex , frag);
        render.addToEntityList(sphereEntity);
        render.returnCameraMat(cameraEntity);  //comment to run manual camera
////////////////////////////////////////////////

    }
    void onDraw(double deltaTime) override
    {

        glClear(GL_COLOR_BUFFER_BIT);
        cameraEntity->returnControllerComp()->update(deltaTime);
        //glm::mat4 VP = cameraEntity->returnCameraComp()->getVPMatrix();
       
       render.returnCameraMat(cameraEntity);

        render.renderDraw();
    }

    void onDestroy() override
    {
        program.destroy();
        model.destroy();
        model1.destroy();
        model2.destroy();
    }
};

int main(int argc, char **argv)
{

    return CameraProjectionApplication().run();
}
