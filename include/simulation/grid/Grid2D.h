// 2D spatial grid object class header file.
#pragma once

#include <cstddef>
#include <vector>
#include <raylib.h>
#include "simulation/grid/Cell.h"

namespace sim {

class Grid2D
{
public:
    Grid2D(std::size_t width, std::size_t height);
    ~Grid2D() = default;

    void update();

    const Cell& getCell(std::size_t x, std::size_t y) const;

    std::size_t getWidth() const { return width_; }
    std::size_t getHeight() const { return height_; }

private:
    std::size_t width_;
    std::size_t height_;
    std::vector<Cell> cells_;
};

}