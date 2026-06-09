// GridRenderer class definition file.

#include "graphics/GridRenderer.h"
#include <raylib.h>

namespace graphics {

void GridRenderer::render(const sim::Grid2D& grid)
{
    const unsigned cellSize = grid.getCellSize();
    const unsigned gridPixelWidth = grid.getWidth();
    const unsigned gridPixelHeight = grid.getHeight();

    const unsigned xOffset = (GetScreenWidth() - gridPixelWidth) / 2;
    const unsigned yOffset = (GetScreenHeight() - gridPixelHeight) / 2;

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
                xOffset + x * grid.getCellSize(),
                yOffset + y * grid.getCellSize(),
                cellSize,
                cellSize,
                color
            );
        }
    }
}

}