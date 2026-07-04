// Field object class header file. (Physical meaning using the sim::Grid2D container.
#pragma once

#include <optional>
#include <raylib.h>
#include <cstddef>
#include "simulation/grid/Grid2D.h"

namespace sim {

    class Field
    {
    public:
        explicit Field(Grid2D grid);
        virtual ~Field() = default;

        Cell& at(std::size_t x, std::size_t y) { return grid_.getCell(x, y); }
        const Cell& at(std::size_t x, std::size_t y) const { return grid_.getCell(x, y); }

        // float amplitude(std::size_t x, std::size_t y) { return grid_.getCell(x, y).amplitude; }
        // const float amplitude(std::size_t x, std::size_t y) const { return grid_.getCell(x, y).amplitude; }

        // float velocity(std::size_t x, std::size_t y) { return grid_.getCell(x, y).velocity; }
        // const float velocity(std::size_t x, std::size_t y) const { return grid_.getCell(x, y).velocity; }
        
        std::size_t getWidth() const { return grid_.getWidth(); }
        std::size_t getHeight() const { return grid_.getHeight(); }

    private:
        Grid2D grid_;
        
    };

}