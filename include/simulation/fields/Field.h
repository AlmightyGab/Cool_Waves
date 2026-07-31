// Field object class header file. (Physical meaning using the sim::Grid2D container.
#pragma once

#include <raylib.h>
#include <cstddef>

#include "simulation/grid/Grid2D.h"

namespace sim {

    class Field
    {
    public:
        explicit Field() = default;
        explicit Field(Grid2D& other);
        explicit Field(const Field&);
        Field(Field&&) = default;

        virtual ~Field() = default;

        Cell& at(std::size_t x, std::size_t y);
        const Cell& at(std::size_t x, std::size_t y) const;

        std::size_t getWidth() const;
        std::size_t getHeight() const;

        float getCellSize() const;

        Field& operator=(const Field&) = default;
        Field& operator=(Field&&) = default;

        void swap(Field& other);

    private:
        Grid2D grid_;
        
    };

}