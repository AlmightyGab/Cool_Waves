//Simulation object class definition file.

#include "simulation/Simulation.h"
#include "simulation/configs/PointSourceConfig.h"
#include "simulation/configs/SimulationConfig.h"
#include "simulation/fields/Field.h"
#include "simulation/grid/Grid2D.h"
#include "simulation/solvers/WaveSolver.h"
#include "simulation/sources/PointSource.h"
#include "simulation/sources/WaveSource.h"

#include <iostream>
#include <memory>

namespace sim {

    Simulation::Simulation(const SimulationConfig& config) :
        config_(config),
        state_(),
        grid_(config),
        field_(grid_)
    {
        // Hardcoded source to test; TO REMOVE
        PointSourceConfig sourceConfig;
        sources_.push_back(std::make_unique<PointSource>(PointSource(sourceConfig, field_)));

        // Debugging print; TO REMOVE
        std::cout << "Simulation construction succesful." << std::endl;
    }

    void Simulation::update(float dt) 
    {
        // Update sim state
        state_.time_ += dt;
        ++state_.frame_;

        // Solve each cells
        solver_.solve(field_, dt);

        // Apply wave sources
        for (auto& source : sources_) 
            source->apply(field_, state_.time_, dt);
        
    }

    void Simulation::reset()
    {
        state_.reset();
    }

}