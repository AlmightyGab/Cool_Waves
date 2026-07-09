// Hardcoded test config for the  point sources.
#pragma once

#include <cstddef>

namespace sim {

    struct PointSourceConfig
    {
        std::size_t x = 200;
        std::size_t y = 200;

        float amplitude = 1.0f;
        float frequency = 10.0f;
        float phase = 0.0f;

    };

}