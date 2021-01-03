#pragma once
#include <application.hpp>
#include <shader.hpp>
#include <imgui-utils/utils.hpp>
#include <mesh/mesh.hpp>
#include <mesh/mesh-utils.hpp>
#include <glm/gtx/euler_angles.hpp>
#include "../../Entity_component/mesh_render_component.hpp"
#include "../../Entity_component/camera_component.hpp"
#include "../../Entity_component/fly_camera_controller_component.hpp"
#include "../../Entity_component/World.hpp"
#include "../../Entity_component/transform_component.hpp"
#include <string>
#include "../State_management/state.hpp"
#include "../common/texture2D.hpp"
#include "../common/sampler.hpp"
#include "../common/material.hpp"
#include "../Entity_component/light_component.hpp"
struct Vertex {
    glm::vec3 position;
    glm::vec<4, glm::uint8, glm::defaultp> color;
    glm::vec2 tex_coord;
};

class CubeState : public State
{
    CameraComponent *cameraComp = new CameraComponent();
    LightComponent *lightComp = new LightComponent();
    FlyCameraControllerComponent *controllerComp = new FlyCameraControllerComponent(); 
    Project::ShaderProgram program;
    Project::Mesh model;
    mesh_renderer *cubeMeshRenderer;
    Entity *cameraEntity = new Entity();
    Entity* cubeEntity = new Entity();
    Entity* lightEntity = new Entity();
    RenderSystem render;
    texture2D tex;
    samplerClass sampler;
    Material* mat = new Material(1);

    void onInitialize(Project::Application* appToUse) override
    {
        app = appToUse;
        mat->setCubeShader();
        mat->setMonarchtexture();
        Project::mesh_utils::Cuboid(model, true);
        Project::Mesh *ptr = &model;
        glClearColor(0, 0, 0, 0);

        //tex.setTexture("assets/images/monarch.png");
        sampler.setSampler();
        Project::ShaderProgram* shaderPtr =&(mat->cubeShader);

         int width, height;

        glfwGetFramebufferSize(app->getWindow(), &width, &height);

        cameraComp->setEyePosition({10, 10, 10});
        cameraComp->setTarget({0, 0, 0});
        cameraComp->setUp({0, 1, 0});
        cameraComp->setupPerspective(glm::pi<float>()/2, static_cast<float>(width)/height, 0.1f, 100.0f);

        Component *cameraTemp = cameraComp;
        cameraEntity->addComponent(cameraTemp);

        Component* controllerTemp = controllerComp;
        cameraEntity->addComponent(controllerTemp);
        CameraComponent* CC = cameraEntity->returnCameraComp();
        cameraEntity->returnControllerComp()->initialize(app, CC );
        render.returnCameraMat(cameraEntity);


////////////////Initializing Cube ////////////////////////////////////////////
TransformComponent *cubeTransformComp = new TransformComponent(); 
        cubeMeshRenderer = new mesh_renderer(shaderPtr, ptr,mat);  
        Component *temp03 = cubeTransformComp;
        Component *temp04 = cubeMeshRenderer;          
        cubeEntity->addComponent(temp03);
        cubeEntity->addComponent(temp04);
        //cubeEntity->returnMeshRendererComp()->initialize(vertex , frag);
        render.addToEntityList(cubeEntity);
    }
    void onDraw(double deltaTime) override
    {
        glClear(GL_COLOR_BUFFER_BIT);

        GLuint texture = mat->monarch.getTexture();
        //texturesamplerBind(texture , sampler.getSampler());
        //cubeEntity->returnTransformComp()->updateCube(app, deltaTime);
        cameraEntity->returnControllerComp()->update(deltaTime);
        //glm::mat4 VP = cameraEntity->returnCameraComp()->getVPMatrix();
       
       render.returnCameraMat(cameraEntity);

        render.renderDraw();
    }

    void onDestroy() override
    {
        mat->cubeShader.destroy();
        model.destroy();
    }
};