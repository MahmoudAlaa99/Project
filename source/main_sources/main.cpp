#include <application.hpp>
#include "../main_sources/State_management/state.hpp"
#include "../main_sources/State_management/cube_state.hpp"
#include "../main_sources/State_management/animation_state.hpp"

#include "../common/texture2D.hpp"
#include "../common/sampler.hpp"
//#include "../main_sources/State_management/light_state.hpp"

int main(int argc, char **argv)
{
    Project::Application call;
    //AnimationState animation;
    CubeState cube;
    bool x = false;
    //call.goToState(&animation);
    call.goToState(&cube);
    return call.run();  
}
// int main(int argc, char** argv) {
//     return LightApplication().run();
// }
