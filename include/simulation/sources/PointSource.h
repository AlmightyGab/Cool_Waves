// Ponctual source object header file.
#pragma once

#include "simulation/sources/WaveSource.h"
#include <cstddef>

namespace sim {
    class Field;

    class PointSource : public WaveSource
    {
    public:
        PointSource(std::size_t x, std::size_t y, float impulse, float frequency, float phase);
        ~PointSource() = default;

        void apply(Field& field, float time, float dt) override;
    
    private:
        std::size_t x_, y_;
        float amplitude_; 
        float frequency_;
        float phase_;

    };

}