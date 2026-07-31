// PointSource class source file.

#include "simulation/sources/PointSource.h"

#include <cmath>
#include <numbers>
#include <cstddef>
#include "simulation/configs/PointSourceConfig.h"
#include "simulation/fields/Field.h"
#include "simulation/grid/Cell.h"

namespace sim {
    
    PointSource::PointSource(const PointSourceConfig& config, Field& field) :
        x_(config.x),
        y_(config.y),
        amplitude_(config.amplitude),
        frequency_(config.frequency),
        phaseOffset_(config.phaseOffset),
        field_(field)
    {
        field_.at(config.x, config.y).isSource = true;
    }

    PointSource::PointSource(std::size_t x, std::size_t y, float amplitude, float frequency, float phaseOffset, Field& field) :
        x_(x),
        y_(y),
        amplitude_(amplitude),
        frequency_(frequency),
        phaseOffset_(phaseOffset),
        field_(field)
    {
        field_.at(x, y).isSource = true;
    }

    PointSource::~PointSource()
    { 
        field_.at(x_, y_).isSource = false; 
    }

    void PointSource::apply(Field& field, float time, float dt) 
    {
        Cell& cell = field.at(x_, y_);

        float omega = 2.0f * std::numbers::pi_v<float> * frequency_;
    
        cell.amplitude = amplitude_ * std::sin(omega * time + phaseOffset_);
        cell.previousAmplitude = cell.amplitude;
    }

}