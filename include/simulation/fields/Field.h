// Field object class header file. (kind of like a 2D memory wrapper)
#pragma once

#include <raylib.h>
#include <cstddef>
#include <vector>
#include "simulation/grid/Grid2D.h"

namespace sim {

class Field
{
public:
    explicit Field(const Grid2D& grid);
    virtual ~Field() = default;

    void clear();
    void fill(float value);
    float getValue(std::size_t x, std::size_t y) const;
    void setValue(std::size_t x, std::size_t y, float value);

    std::size_t getWidth() const noexcept { return width_; }
    std::size_t getHeight() const noexcept { return height_; }

    bool isValidPosition(std::size_t x, std::size_t y) const noexcept;

private:
    std::size_t index(std::size_t x, std::size_t y) const;

    std::size_t width_ = 0;
    std::size_t height_ = 0;

    std::vector<float> values_;
};

}