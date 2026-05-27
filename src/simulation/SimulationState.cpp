// SimulationState class definition file.

#include "simulation/SimulationState.h"

namespace sim {

SimulationState::SimulationState(const SimulationConfig& config) :
    gridWidth_(config.gridWidth),
    gridHeight_(config.gridHeight)
{}

void SimulationState::reset()
{
    time_ = 0.0f;
}

}