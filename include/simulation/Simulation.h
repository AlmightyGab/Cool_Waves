// Simulation object class header file. This is the object that interacts with the Application for the game loop.
#pragma once

// #include <memory>
#include "SimulationConfig.h"
#include "SimulationState.h"
class Solver;

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
    // std::unique_ptr<Solver> mSolver_;
};

}