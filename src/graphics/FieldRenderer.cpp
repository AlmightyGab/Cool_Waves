// GridRenderer class definition file.

#include "graphics/FieldRenderer.h"
#include <raylib.h>

namespace graphics {

void FieldRenderer::render(const sim::Field& field)
{
    const unsigned cellSize = field.getCellSize();
    const unsigned gridPixelWidth = field.getWidth();
    const unsigned gridPixelHeight = field.getHeight();

    const unsigned xOffset = (GetScreenWidth() - gridPixelWidth) / 2;
    const unsigned yOffset = (GetScreenHeight() - gridPixelHeight) / 2;

    for (std::size_t x = 0; x < field.getWidth(); ++x) {
        for (std::size_t y = 0; y < field.getHeight(); ++y) {
            auto target = field.at(x, y);
            Color color;
            if (target.amplitude > 0)
                color = {255, 0, 0, 255};
            else if (target.amplitude < 0)
                color = {0, 0, 255, 255};
            else
                color = RAYWHITE;

            DrawRectangle(
                xOffset + x * field.getCellSize(),
                yOffset + y * field.getCellSize(),
                cellSize,
                cellSize,
                color
            );
        }
    }
}

}