// Grid2D definition file.

#include <cstddef>
#include <ratio>
#include <raylib.h>
#include <stdexcept>
#include <vector>

#include "simulation/configs/SimulationConfig.h"
#include "simulation/grid/Cell.h"
#include "simulation/grid/Grid2D.h"

namespace sim {

    Grid2D::Grid2D(const Grid2D& other) : 
        width_(other.width_),
        height_(other.height_),
        cells_(other.cells_),
        cellSize_(other.cellSize_)
    {}

    Grid2D::Grid2D(const SimulationConfig& config) :
        width_(config.gridWidth),
        height_(config.gridHeight),
        cellSize_(config.cellSize)
    {
        cells_.resize(width_ * height_);
    }

    const Cell& Grid2D::getCell(std::size_t x, std::size_t y) const
    {
        if (x >= width_ || y >= height_)
            throw std::out_of_range("Grid2D::getCell : Invalid position passed as argument.");

        std::size_t index = y * width_ + x;
        return cells_[index];
    }

    Cell& Grid2D::getCell(std::size_t x, std::size_t y) 
    {
        if (x >= width_ || y >= height_)
            throw std::out_of_range("Grid2D::getCell : Invalid position passed as argument.");

        std::size_t index = y * width_ + x;
        return cells_[index];
    }

    Grid2D& Grid2D::operator=(const Grid2D& other)
    {
        if (this != &other) {
            width_ = other.width_;
            height_ = other.height_;
            cells_ = std::move(other.cells_);
            cellSize_ = other.cellSize_;
        }

        return *this;
    }

}