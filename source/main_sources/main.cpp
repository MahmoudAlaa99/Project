

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



    struct
    {
        glm::vec3 eye;
        glm::vec3 center;
        glm::vec3 up;
    } camera_view;

    struct
    {
        bool is_perspective;
        // Common camera projection properties
        float near, far;
        float aspect_ratio;
        // "Perspective camera"-only properties
        float vertical_field_of_view_angle;
        // "Orthographic camera"-only properties
        float orthographic_height;
    } camera_projection;

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

        // Project::Mesh *ptr0 = &model;
        Project::Mesh *ptr01 = &model1;
        // Project::Mesh *ptr02 = &model2;

        /////////if you want to use manual camera ///////////////////
        camera_view.eye = {10, 10, 10};
        camera_view.center = {0, 0, 0};
        camera_view.up = {0, 1, 0};

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        camera_projection.is_perspective = true;
        camera_projection.near = 0.1f;
        camera_projection.far = 100.0f;
        camera_projection.aspect_ratio = static_cast<float>(width)/height;
        camera_projection.vertical_field_of_view_angle = glm::pi<float>()/2;
        camera_projection.orthographic_height = 20.0f;

        glClearColor(0, 0, 0, 0);
////////////////////////////////////////////////////////////////////////
        Project::ShaderProgram *shaderPtr = &program;


//camera controller componenet
        FlyCameraControllerComponent *controllerComp = new FlyCameraControllerComponent(); 
        glm::vec3 camera_position = controllerComp->getPosition();
        float yaw = controllerComp->getYaw();
        float pitch = controllerComp->getPitch();
        glm::vec3 rotation = {yaw,pitch,0};

        Component *temp03 = controllerComp;
        cameraEntity->addComponent(temp03);

//camera transform componenet
        TransformComponent *cameraTransformComp = new TransformComponent(); 
        cameraTransformComp->setRotation(rotation);
        //set translation
        //set scale
        Component *temp04 = cameraTransformComp;
        cameraEntity->addComponent(temp04);

        glm::mat4 cameraTransformMat = cameraTransformComp->getTransform();

//camera component
        CameraComponent *cameraComp = new CameraComponent(); 
        cameraComp->setTransform(cameraTransformMat);
        cameraComp->setEye();
        cameraComp->setDirection();
        cameraComp->setUp();
        Component *temp = cameraComp;
        cameraEntity->addComponent(temp);


//////////////// byresm el entity /////////////////////////////////
        TransformComponent *sphereTransformComp = new TransformComponent(); 
        sphereMEshRenderer = new mesh_renderer(shaderPtr, ptr01);  
        Component *temp01 = sphereTransformComp;
        Component *temp02 = sphereMEshRenderer;          
        sphereEntity->addComponent(temp01);
        sphereEntity->addComponent(temp02);
        sphereEntity->returnMeshRendererComp()->initialize(vertex , frag);
        render.addToEntityList(sphereEntity);
       // render.returnCameraMat(cameraEntity);  //comment to run manual camera
////////////////////////////////////////////////

    }
    void onDraw(double deltaTime) override
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 view_matrix = glm::lookAt(camera_view.eye, camera_view.center, camera_view.up);
        glm::mat4 projection_matrix;
        if (camera_projection.is_perspective)
        {
            projection_matrix = glm::perspective(camera_projection.vertical_field_of_view_angle, camera_projection.aspect_ratio, camera_projection.near, camera_projection.far);
        }
        else
        {
            float half_height = camera_projection.orthographic_height * 0.5f;
            float half_width = camera_projection.aspect_ratio * half_height;
            projection_matrix = glm::ortho(-half_width, half_width, -half_height, half_height, camera_projection.near, camera_projection.far);
        }

        glm::mat4 camera_matrix = projection_matrix * view_matrix;
        render.setManulCamera(camera_matrix); //uncomment to use manual camera 

        render.renderDraw();
        //sphereMEshRenderer->meshDraw(camera_matrix *to_mat4());
        // for(const auto& object : objects) {
        // obj3->meshDraw((camera_matrix * objects[0].to_mat4()));
        // obj2->meshDraw((camera_matrix * objects[1].to_mat4()));
        // obj1->meshDraw((camera_matrix * objects[2].to_mat4()));
        //model.draw();
        // }
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
