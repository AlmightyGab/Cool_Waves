// Application object class definition file.

#include <raylib.h>
#include "core/Application.h"
#include "core/Config.h"
#include "core/Time.h"
#include "simulation/Simulation.h"
#include "simulation/configs/SimulationConfig.h"

namespace core {

Application::Application() :
    simulation_(sim::SimulationConfig())
{
}

void Application::run()
{
    initialize();
    while (!WindowShouldClose()) {
        // update(Time::deltaTime);
        render();
    }

    shutdown();
}

void Application::initialize()
{
    InitWindow(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, Config::TITLE);
    SetTargetFPS(Config::FRAMERATE);
}

 void Application::shutdown()
 {
    CloseWindow();
 }

 void Application::update(float dt)
 {

 }

 void Application::render()
 {
    BeginDrawing();
    ClearBackground(BLANK);
    fieldRenderer_.render(simulation_.getField());
    EndDrawing();
 }

}