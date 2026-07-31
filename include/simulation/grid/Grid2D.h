// 2D spatial grid object class header file.
#pragma once

#include <cstddef>
#include <vector>

namespace sim {
    class SimulationConfig;
    class Cell;

    class Grid2D
    {
    public:
        Grid2D() = default;
        Grid2D(const Grid2D& other);
        Grid2D(const SimulationConfig& config);
        virtual ~Grid2D() = default;

        const Cell& getCell(std::size_t x, std::size_t y) const;
        Cell& getCell(std::size_t x, std::size_t y);

        std::size_t getWidth() const { return width_; }
        std::size_t getHeight() const { return height_; }

        float getCellSize() const { return cellSize_; }

        Grid2D& operator=(const Grid2D& other);

    private:
        std::size_t width_;
        std::size_t height_;
        std::vector<Cell> cells_;
        float cellSize_;
    };

}