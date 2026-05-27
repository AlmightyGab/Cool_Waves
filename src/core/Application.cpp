// Application object class definition file.

#include <raylib.h>
#include "core/Application.h"
#include "core/Config.h"
#include "core/Time.h"

namespace core {

void Application::run()
{
    initialize();

    while (!WindowShouldClose()) {
        // update(Time::deltaTime);
        // render();
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
    ClearBackground(RAYWHITE);
    EndDrawing();
 }

}