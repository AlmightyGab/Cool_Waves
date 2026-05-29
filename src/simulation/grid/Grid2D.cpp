// Grid2D definition file.

#include "simulation/grid/Grid2D.h"

#include <cstddef>
#include <raylib.h>
#include <stdexcept>

namespace grid {

Grid2D::Grid2D(std::size_t width, std::size_t height) :
    width_(width),
    height_(height)
{
    cells_.reserve(width_ * height_);
}

void Grid2D::update()
{

}

const Cell& Grid2D::getCell(std::size_t x, std::size_t y) const
{
    if (x >= width_ || y >= height_)
        throw std::out_of_range("Grid2D::getCell : Invalid position passed as argument.");

    std::size_t index = y * width_ + x;
    return cells_[index];
}

Vector2 Grid2D::getDimensions() const
{
    return {static_cast<float>(width_), static_cast<float>(height_)};
}

}