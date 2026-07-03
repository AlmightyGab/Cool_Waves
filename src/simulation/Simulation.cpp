//Simulation object class definition file.

#include "simulation/Simulation.h"
#include "simulation/SimulationConfig.h"
#include "simulation/grid/Grid2D.h"

namespace sim {

Simulation::Simulation(const SimulationConfig& config) :
    config_(config),
    state_(config),
    grid_(config)
{
}

void Simulation::update(float dt) 
{
    // physics go here.
    
}

void Simulation::reset()
{
    state_.reset();
}

}