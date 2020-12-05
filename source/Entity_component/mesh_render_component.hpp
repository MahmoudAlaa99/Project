#pragma once 

#include <application.hpp>
#include <shader.hpp>
#include <imgui-utils/utils.hpp>

#include <mesh/mesh.hpp>
#include <mesh/mesh-utils.hpp>

#include <glm/gtx/euler_angles.hpp>
#include "../Entity_component/component.hpp"
#include <string>

class mesh_renderer : public Component{

    private:
    Project::ShaderProgram* pointer_to_shader;
    Project::Mesh* pointer_to_mesh;
    public:
    mesh_renderer() {}
    mesh_renderer(Project::ShaderProgram* pointer_to_shader_in ,Project::Mesh* pointer_to_mesh_in )
    {
        this->pointer_to_shader = pointer_to_shader_in;
        this->pointer_to_mesh = pointer_to_mesh_in;

        Ctype = MeshRenderer;
    }

    void initialize(std::string vert , std::string frag)//shaders as input string
    {
        this->pointer_to_shader->create();
        this->pointer_to_shader->attach(vert, GL_VERTEX_SHADER);
        this->pointer_to_shader->attach(frag, GL_FRAGMENT_SHADER);
        this->pointer_to_shader->link();

        //our::mesh_utils::Cuboid(model, true); //hab3at model da lel mesh renderer 

    }

    void meshDraw(glm::mat4 cameraXtransform)  
    {
        glUseProgram(*pointer_to_shader);

        pointer_to_shader->set("tint", glm::vec4(1,1,1,1));
        pointer_to_shader->set("transform",cameraXtransform);
        pointer_to_mesh->draw();

    }


};