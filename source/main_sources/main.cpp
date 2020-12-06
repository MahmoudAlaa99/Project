#include <application.hpp>
#include "../main_sources/State_management/state.hpp"
#include "../main_sources/State_management/cube_state.hpp"
#include "../main_sources/State_management/animation_state.hpp"

int main(int argc, char **argv)
{
    Project::Application call;
    AnimationState animation;
    CubeState cube;
    bool x = false;
    call.goToState(&animation);
    call.goToState(&cube);
    return call.run();  
}
