// Simulation Configuration data file.
#pragma once

#include <cstddef>

namespace sim {

    struct SimulationConfig
    {
        inline static std::size_t gridWidth = 400;
        inline static std::size_t gridHeight = 400;

        float cellSize = 1.0f; // Square cells (pixels)
        float timeStep = 0.016f;
        float simulationSpeed = 1.0f;

        
    };

}