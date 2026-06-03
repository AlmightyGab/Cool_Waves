// GridRenderer class definition file.

#include "graphics/GridRenderer.h"
#include <raylib.h>

namespace graphics {

void GridRenderer::render(const sim::Grid2D& grid)
{
    for (std::size_t x = 0; x < grid.getWidth(); ++x) {
        for (std::size_t y = 0; y < grid.getHeight(); ++y) {
            auto target = grid.getCell(x, y);
            Color color;
            if (target.amplitude > 0)
                color = {255, 0, 0, 255};
            else if (target.amplitude < 0)
                color = {0, 0, 255, 255};
            else
                color = RAYWHITE;

            DrawRectangle(
                x * grid.getCellSize(),
                y * grid.getCellSize(),
                grid.getCellSize(),
                grid.getCellSize(),
                color
            );
        }
    }
}

}