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

    float accumulator = 0.0f;
    constexpr float SIM_DT = 0.01f;

    while (!WindowShouldClose()) {

        Time::update();

        accumulator += Time::deltaTime;

        while (accumulator >= SIM_DT) {
            simulation_.update(SIM_DT);
            accumulator -= SIM_DT;
        }

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
    simulation_.update(dt);
 }

 void Application::render()
 {
    BeginDrawing();
    ClearBackground(BLANK);
    fieldRenderer_.render(simulation_.getField());
    EndDrawing();
 }

}