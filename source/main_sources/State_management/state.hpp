#pragma once
// class Project::Application;
#include <application.hpp>
class State
{
    public:
    Project::Application* app;
    virtual void onInitialize(Project::Application* appToUse) {}
    virtual void onDraw(double deltaTime) {}
    virtual void onDestroy() {}
};