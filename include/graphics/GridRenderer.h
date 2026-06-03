// Simple grid rendering class header file.
#pragma once

#include "simulation/grid/Grid2D.h"

namespace graphics {

class GridRenderer
{
public: 
    void render(const sim::Grid2D& grid);
};

}