// Ponctual source object header file.
#pragma once

#include <cstddef>

#include "simulation/sources/WaveSource.h"

namespace sim {
    class Field;
    class PointSourceConfig;

    class PointSource : public WaveSource
    {
    public:
        PointSource(const PointSourceConfig& config, Field& field);
        PointSource(std::size_t x, std::size_t y, float amplitude, float frequency, float phaseOffset, Field& field);
        virtual ~PointSource();

        void apply(Field& field, float time, float dt) override;
    
    private:
        std::size_t x_, y_;
        float amplitude_; 
        float frequency_;
        float phaseOffset_;

        Field& field_;

    };

}