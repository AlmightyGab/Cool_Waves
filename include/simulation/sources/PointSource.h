// Ponctual source object header file.
#pragma once

#include "simulation/configs/PointSourceConfig.h"
#include "simulation/sources/WaveSource.h"
#include <cstddef>
#include "simulation/fields/Field.h"

namespace sim {

    class PointSource : public WaveSource
    {
    public:
        PointSource(const PointSourceConfig& config, Field& field);
        PointSource(std::size_t x, std::size_t y, float amplitude, float frequency, float phaseOffset, Field& field);
        ~PointSource() { field_.at(x_, y_).isSource = false; }

        void apply(Field& field, float time, float dt) override;
    
    private:
        std::size_t x_, y_;
        float amplitude_; 
        float frequency_;
        float phaseOffset_;

        Field& field_;

    };

}