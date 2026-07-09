// Simulation object class header file. This is the object that interacts with the Application for the game loop.
#pragma once

#include <vector>
#include <memory>
#include "simulation/configs/SimulationConfig.h"
#include "simulation/SimulationState.h"
#include "simulation/fields/Field.h"
#include "simulation/grid/Grid2D.h"
#include "simulation/solvers/WaveSolver.h"
#include "simulation/sources/WaveSource.h"

namespace sim {

class Simulation
{
public:
    explicit Simulation(const SimulationConfig& config);

    void update(float dt);
    void reset();

    const SimulationState& getState() const { return state_; }
    const Field& getField() const { return field_; }

private:
    SimulationConfig config_;
    SimulationState state_;

    Grid2D grid_;
    Field field_;

    WaveSolver solver_;

    std::vector<std::unique_ptr<WaveSource>> sources_;
};

}