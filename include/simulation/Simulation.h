// Simulation object class header file. This is the object that interacts with the Application for the game loop.
#pragma once

// #include <memory>
#include "simulation/SimulationConfig.h"
#include "simulation/SimulationState.h"
#include "simulation/fields/Field.h"
#include "simulation/grid/Grid2D.h"

namespace sim {

class Simulation
{
public:
    explicit Simulation(const SimulationConfig& config);

    void update(float dt);
    void reset();

    const SimulationState& getState() const { return state_; }

private:
    SimulationConfig config_;
    SimulationState state_;
    Grid2D grid_;
};

}