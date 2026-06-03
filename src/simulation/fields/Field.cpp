// Field object class definitions.

#include "simulation/fields/Field.h"
#include <algorithm>
#include <cassert>
#include <cstddef>

namespace sim {

Field::Field(const Grid2D& grid) :
    width_(grid.getWidth()),
    height_(grid.getHeight())
{
    values_.reserve(width_ * height_);
}

void Field::fill(float value)
{
    std::fill(
        values_.begin(),
        values_.end(),
        value
    );
}

void Field::clear()
{
    fill(0.0f);
}

bool Field::isValidPosition(std::size_t x, std::size_t y) const noexcept
{
    return x < width_ && y < height_;
}

float Field::getValue(std::size_t x, std::size_t y) const
{
    assert(isValidPosition(x, y));
    
    return values_[index(x, y)];
}

void Field::setValue(std::size_t x, std::size_t y, float value)
{
    assert(isValidPosition(x, y));

    values_[index(x, y)] = value;
}

std::size_t Field::index(std::size_t x, std::size_t y) const
{
    return y * width_ + x;
}

}