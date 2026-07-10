// Field object class header file. (Physical meaning using the sim::Grid2D container.
#pragma once

#include <raylib.h>
#include <cstddef>
#include "simulation/grid/Grid2D.h"

namespace sim {

    class Field
    {
    public:
        explicit Field(Grid2D& grid) : grid_(&grid) {}
        virtual ~Field() = default;

        Cell& at(std::size_t x, std::size_t y) { return grid_->getCell(x, y); }
        const Cell& at(std::size_t x, std::size_t y) const { return grid_->getCell(x, y); }

        std::size_t getWidth() const { return grid_->getWidth(); }
        std::size_t getHeight() const { return grid_->getHeight(); }

        float getCellSize() const { return grid_->getCellSize(); }

        void resetSources() { grid_->resetSources(); }

        Field& operator=(const Field& other) {
            if (this != &other)
                grid_ = other.grid_;

            return *this;
        }

    private:
        Grid2D* grid_;
        
    };

}