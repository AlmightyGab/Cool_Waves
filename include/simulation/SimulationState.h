// Simulation's state data file.
#pragma once

namespace sim {

    class SimulationState 
    {
    public:
        explicit SimulationState() = default;

        void reset() { time_ = 0.0f; }

        float time_ = 0.0f;
        unsigned frame_ = 0;

        bool paused = false;

    };

}