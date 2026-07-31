// 2D spatial grid object class header file.
#pragma once

#include <cstddef>
#include <vector>
#include <raylib.h>

#include "simulation/configs/SimulationConfig.h"
#include "simulation/grid/Cell.h"

namespace sim {

class Grid2D
{
public:
    Grid2D(const SimulationConfig& config);
    ~Grid2D() = default;

    const Cell& getCell(std::size_t x, std::size_t y) const;
    Cell& getCell(std::size_t x, std::size_t y);

    std::size_t getWidth() const { return width_; }
    std::size_t getHeight() const { return height_; }

    float getCellSize() const { return cellSize_; }

private:
    std::size_t width_;
    std::size_t height_;
    std::vector<Cell> cells_;
    float cellSize_;
};

}