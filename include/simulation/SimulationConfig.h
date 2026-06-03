// Simulation Configuration data file.
#pragma once

#include <cstddef>

namespace sim {

struct SimulationConfig{
    std::size_t gridWidth = 200;
    std::size_t gridHeight = 200;

    float cellSize = 1.0f; // Square cells (pixels)
    float timeStep = 0.016f;
    float simulationSpeed = 1.0f;
};

}