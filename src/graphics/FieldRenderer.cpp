// GridRenderer class definition file.

#include "graphics/FieldRenderer.h"
#include <raylib.h>
#include <iostream>

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
            float amplitude = field.at(x, y).amplitude;
            float normalized = 0.5f + 0.5f * (amplitude / 10.0f);

            std::cout << amplitude << std::endl;

            unsigned char r = (unsigned char)(255 * normalized);
            unsigned char g = 0;
            unsigned char b = (unsigned char)(255 * (1.0f - normalized));
            Color color = { r, g, b, 255 };

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