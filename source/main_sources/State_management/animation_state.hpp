// #pragma once
// #include <application.hpp>
// #include <shader.hpp>
// #include <imgui-utils/utils.hpp>
// #include <mesh/mesh.hpp>
// #include <mesh/mesh-utils.hpp>
// #include <glm/gtx/euler_angles.hpp>
// #include "../../Entity_component/mesh_render_component.hpp"
// #include "../../Entity_component/camera_component.hpp"
// #include "../../Entity_component/fly_camera_controller_component.hpp"
// #include "../../Entity_component/World.hpp"
// #include "../../Entity_component/transform_component.hpp"
// #include <string>
// #include "../State_management/state.hpp"
// #include "../common/texture2D.hpp"


// class AnimationState : public State
// {
//     CameraComponent *cameraComp = new CameraComponent();
//     FlyCameraControllerComponent *controllerComp = new FlyCameraControllerComponent(); 
//     Project::ShaderProgram program;
//     Project::Mesh model;
//     Project::Mesh model1;
//     Project::Mesh model2;
//     mesh_renderer *cubeMeshRenderer;
//     mesh_renderer *cubeMeshRenderer01;
//     mesh_renderer *sphereMeshRenderer;
//     Entity *cameraEntity = new Entity();
//     Entity* sphereEntity = new Entity();
//     Entity* cubeEntity = new Entity();
//     RenderSystem render;
//     texture2D tex;

//     void onInitialize(Project::Application* appToUse) override
//     {
//         app = appToUse;
//         // std::string vertex = "assets/shaders/phase_1/transform.vert";
//         // std::string frag = "assets/shaders/phase_1/tint.frag";
//         std::string vertex = "assets/shaders/phase_3/transform.vert";
//         std::string frag = "assets/shaders/phase_3/texture.frag";
//         Project::mesh_utils::Cuboid(model, true);
//         Project::mesh_utils::Cuboid(model2, true);
//         Project::mesh_utils::Sphere(model1, {32, 16}, true);

//         Project::Mesh *ptr = &model;
//         Project::Mesh *ptr01 = &model1;
//         Project::Mesh *ptr02 = &model2;
//         glClearColor(0, 0, 0, 0);
//         tex.setTexture("assets/images/monarch.png");
//         Project::ShaderProgram *shaderPtr = &program;
//          int width, height;

//         glfwGetFramebufferSize(app->getWindow(), &width, &height);

//         cameraComp->setEyePosition({10, 10, 10});
//         cameraComp->setTarget({0, 0, 0});
//         cameraComp->setUp({0, 1, 0});
//         cameraComp->setupPerspective(glm::pi<float>()/2, static_cast<float>(width)/height, 0.1f, 100.0f);

//         Component *cameraTemp = cameraComp;
//         cameraEntity->addComponent(cameraTemp);

//         Component* controllerTemp = controllerComp;
//         cameraEntity->addComponent(controllerTemp);
//         CameraComponent* CC = cameraEntity->returnCameraComp();
//         cameraEntity->returnControllerComp()->initialize(app, CC );

// //////////////// Initializing Sphere /////////////////////////////////
//         TransformComponent *sphereTransformComp = new TransformComponent(); 
//         sphereMeshRenderer = new mesh_renderer(shaderPtr, ptr01);  
//         Component *temp01 = sphereTransformComp;
//         Component *temp02 = sphereMeshRenderer;          
//         sphereEntity->addComponent(temp01);
//         sphereEntity->addComponent(temp02);
//         sphereEntity->returnMeshRendererComp()->initialize(vertex , frag);
//         render.addToEntityList(sphereEntity);
//         render.returnCameraMat(cameraEntity);  //comment to run manual camera
// ////////////////////////////////////////////////


// ////////////////Initializing Cube ////////////////////////////////////////////
// TransformComponent *cubeTransformComp = new TransformComponent(); 
//         cubeMeshRenderer = new mesh_renderer(shaderPtr, ptr);  
//         Component *temp03 = cubeTransformComp;
//         Component *temp04 = cubeMeshRenderer;          
//         cubeEntity->addComponent(temp03);
//         cubeEntity->addComponent(temp04);
//         cubeEntity->returnMeshRendererComp()->initialize(vertex , frag);
//         render.addToEntityList(cubeEntity);

// /////////////////////2nd cube///////////////////////////////////////
//     }

//     void onDraw(double deltaTime) override
//     {

//         glClear(GL_COLOR_BUFFER_BIT);
//         GLuint texture = tex.getTexture();
//         sphereEntity->returnTransformComp()->updateSphere(app, deltaTime);
//         cubeEntity->returnTransformComp()->updateCube(app, deltaTime);
//         //cubeEntity01->returnTransformComp()->updateSphere(app, deltaTime);
//         cameraEntity->returnControllerComp()->update(deltaTime);
       
//         render.returnCameraMat(cameraEntity);

//         render.renderDraw();
//     }

//     void onDestroy() override
//     {
//         program.destroy();
//         model.destroy();
//         model1.destroy();
//         model2.destroy();
//     }
// };



