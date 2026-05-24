// Application object class definition file.

#include "../../include/core/Application.h"

void Application::run()
{
    // TO MODIFY WITH PROPER DATA
    float dt;

    initialize();

    while (isRunning_) {
        update(dt);
        render();
    }

    shutdown()
}

void Application::initialize()
{

}
 void Application::shutdown()
 {

 }

 void Application::update(float dt)
 {

 }

 void Application::render()
 {

 }