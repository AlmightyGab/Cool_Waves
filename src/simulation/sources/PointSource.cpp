// PointSource class source file.

#include "simulation/sources/PointSource.h"

#include <cmath>
#include <numbers>
#include <cstddef>
#include "simulation/configs/PointSourceConfig.h"
#include "simulation/fields/Field.h"
#include "simulation/grid/Cell.h"

namespace sim {
    
    PointSource::PointSource(const PointSourceConfig& config) :
        x_(config.x),
        y_(config.y),
        amplitude_(config.amplitude),
        frequency_(config.frequency),
        phaseOffset_(config.phaseOffset)
    {
    }

    PointSource::PointSource(std::size_t x, std::size_t y, float amplitude, float frequency, float phaseOffset) :
        x_(x),
        y_(y),
        amplitude_(amplitude),
        frequency_(frequency),
        phaseOffset_(phaseOffset)
    {
    }

    void PointSource::apply(Field& field, float time, float dt) 
    {
        Cell& cell = field.at(x_, y_);
    
        cell.source += amplitude_ * std::sin(2.0f * std::numbers::pi_v<float> * frequency_ * time + phaseOffset_);
    }

}