// Field object class header file. (Physical meaning using the sim::Grid2D container.
#pragma once

#include <cstddef>

namespace sim {
    class Grid2D;
    class Cell;

    class Field
    {
    public:
        explicit Field() = default;
        explicit Field(Grid2D& grid);
        explicit Field(const Field& other);
        virtual ~Field();

        Cell& at(std::size_t x, std::size_t y);
        const Cell& at(std::size_t x, std::size_t y) const;

        std::size_t getWidth() const;
        std::size_t getHeight() const;

        float getCellSize() const;

        void move(Field& other);

        Field& operator=(const Field& other);

    private:
        Grid2D* grid_;
        
    };

}