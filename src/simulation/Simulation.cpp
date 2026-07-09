//Simulation object class definition file.

#include "simulation/Simulation.h"
#include "simulation/configs/SimulationConfig.h"
#include "simulation/fields/Field.h"
#include "simulation/grid/Grid2D.h"

#include <iostream>

namespace sim {

    Simulation::Simulation(const SimulationConfig& config) :
        config_(config),
        state_(config),
        grid_(config),
        field_(grid_)
    {
        // Debugging print; TO REMOVE
        std::cout << "Simulation construction succesful." << std::endl;
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