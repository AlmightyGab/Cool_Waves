// Application object class header file.
#pragma once

#include "simulation/Simulation.h"
#include "graphics/GridRenderer.h"

namespace core {

class Application 
{
public:
    Application();
    ~Application() = default;
    void run();

private:
    void initialize();
    void update(float dt);
    void render();
    void shutdown();

    sim::Simulation simulation_;
    graphics::GridRenderer gridRenderer_;
};

}