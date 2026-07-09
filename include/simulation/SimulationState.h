// Simulation's state data file.
#pragma once

#include "simulation/configs/SimulationConfig.h"

namespace sim {

    class SimulationState 
    {
    public:
        explicit SimulationState(const SimulationConfig& config);

        void reset();

        float getTime() const { return time_; }

    private:
        float time_ = 0.0f;

        std::size_t gridWidth_ = 0;
        std::size_t gridHeight_ = 0;
    };

}