//Simulation object class definition file.

#include "simulation/Simulation.h"
#include "simulation/configs/SimulationConfig.h"
#include "simulation/fields/Field.h"
#include "simulation/grid/Grid2D.h"
#include "simulation/solvers/WaveSolver.h"
#include "simulation/sources/WaveSource.h"

#include <iostream>

namespace sim {

    Simulation::Simulation(const SimulationConfig& config) :
        config_(config),
        state_(),
        grid_(config),
        field_(grid_)
    {
        // Debugging print; TO REMOVE
        std::cout << "Simulation construction succesful." << std::endl;
    }

    void Simulation::update(float dt) 
    {
        // Update sim state
        state_.time_ += dt;
        ++state_.frame_;

        // Apply wave sources
        for (auto& source : sources_) 
            source->apply(field_, state_.time_, dt);
        
        // Solve each cells
        solver_.solve(field_, dt);
    }

    void Simulation::reset()
    {
        state_.reset();
    }

}