// Hardcoded test config for the  point sources.
#pragma once

#include "simulation/configs/SimulationConfig.h"
#include <cmath>
#include <cstddef>

namespace sim {

    struct PointSourceConfig
    {
        std::size_t x = floor(SimulationConfig::gridWidth / 2);
        std::size_t y = floor(SimulationConfig::gridHeight / 2);

        float amplitude = 10.0f;
        float frequency = 5.0f;
        float phaseOffset = 0.0f;

    };

}