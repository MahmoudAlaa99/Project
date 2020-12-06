// #include <application.hpp>
// #include <shader.hpp>
// #include "../../source/Entity_component/transform_component.hpp"

// int flag = 0;
// class UniformsApplication : public Project::Application {

//     Project::ShaderProgram pacmanProgram;  //for pacman
//     GLuint vertex_array = 0;

//     Project::ShaderProgram smileProgram;  //for smile
//     GLuint vertex_array1 = 0;

//     Project::ShaderProgram heartProgram;  //for heart
//     GLuint vertex_array2 = 0;


//     Project::Mouse & mouse = this->getMouse(); //to handle mouse movement
//     Project::Keyboard & keyboard = this->getKeyboard(); // to handle keyboard input

//     Project::WindowConfiguration getWindowConfiguration() override {
//         return { "Phase 1", {1280, 720}, false };
//     }

//     void onInitialize() override {
        
//         //for smile
//         smileProgram.create();
//         smileProgram.attach("assets/shaders/phase_1/phase_1_quad.vert", GL_VERTEX_SHADER);
//         smileProgram.attach("assets/shaders/phase_1/phase1_draw_smile.frag", GL_FRAGMENT_SHADER);
//         smileProgram.link();


//         //for pacman
//         pacmanProgram.create();
//         pacmanProgram.attach("assets/shaders/phase_1/phase_1_quad.vert", GL_VERTEX_SHADER);
//         pacmanProgram.attach("assets/shaders/phase_1/phase_1_draw_pacman.frag", GL_FRAGMENT_SHADER);
//         pacmanProgram.link();

//         //for heart
//         heartProgram.create();
//         heartProgram.attach("assets/shaders/phase_1/phase_1_quad.vert", GL_VERTEX_SHADER);
//         heartProgram.attach("assets/shaders/phase_1/phase_1_draw_heart.frag", GL_FRAGMENT_SHADER);
//         heartProgram.link();

//         glGenVertexArrays(1, &vertex_array);
//         glGenVertexArrays(1, &vertex_array1);
//         glGenVertexArrays(1, &vertex_array2);
//         glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//     }

//     void onDraw(double deltaTime) override {
//         glClear(GL_COLOR_BUFFER_BIT);
//         if(keyboard.isPressed(GLFW_KEY_1))
//             flag =1;
//         else if(keyboard.isPressed(GLFW_KEY_2))
//             flag =2;
//         else if(keyboard.isPressed(GLFW_KEY_3))
//             flag =3;
            

//         if(flag == 1)
//         {
//             glUseProgram(pacmanProgram);
//             GLuint mouse_uniform_location1 = glGetUniformLocation(pacmanProgram, "mousePosition");
//             glUniform2f(mouse_uniform_location1, mouse.getMousePosition().x, mouse.getMousePosition().y);
//             glBindVertexArray(vertex_array1);
//             glDrawArrays(GL_TRIANGLES, 0, 6);
//             glBindVertexArray(0);
//         }
//         else if (flag == 2)
//         {
//             glUseProgram(smileProgram);
//             GLuint mouse_uniform_location2 = glGetUniformLocation(smileProgram, "mousePosition");
//             glUniform2f(mouse_uniform_location2, mouse.getMousePosition().x, mouse.getMousePosition().y);
//             glBindVertexArray(vertex_array2);
//             glDrawArrays(GL_TRIANGLES, 0, 6);
//             glBindVertexArray(0);
//         }
//         else if (flag == 3)
//         {
//             glUseProgram(heartProgram);
//             GLuint mouse_uniform_location = glGetUniformLocation(heartProgram, "mousePosition");
//             glUniform2f(mouse_uniform_location, mouse.getMousePosition().x, mouse.getMousePosition().y);
//             glBindVertexArray(vertex_array2);
//             glDrawArrays(GL_TRIANGLES, 0, 6);
//             glBindVertexArray(0);
//         }
//     }

//     void onDestroy() override {
//         if(flag ==1)
//         {
//         pacmanProgram.destroy();
//         glDeleteVertexArrays(1, &vertex_array1);
//         }
//         else if (flag ==2)
//         {
//         smileProgram.destroy();
//         glDeleteVertexArrays(1, &vertex_array2);
//         }
//         else if(flag == 3)
//         {
//         heartProgram.destroy();
//         glDeleteVertexArrays(1, &vertex_array);
//         }
//     }

// };

// int main(int argc, char** argv) {
//     return UniformsApplication().run();
// }