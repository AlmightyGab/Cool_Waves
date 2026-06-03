// Grid2D definition file.

#include "simulation/grid/Grid2D.h"
#include "simulation/SimulationConfig.h"

#include <cstddef>
#include <raylib.h>
#include <stdexcept>

namespace sim {

Grid2D::Grid2D(const SimulationConfig& config) :
    width_(config.gridWidth),
    height_(config.gridHeight),
    cellSize_(config.cellSize)
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

}