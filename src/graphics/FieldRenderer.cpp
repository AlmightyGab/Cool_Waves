// GridRenderer class definition file.

#include <raylib.h>
#include <iostream>

#include "graphics/FieldRenderer.h"
#include "simulation/grid/Cell.h"
#include "simulation/fields/Field.h"

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

                float maxAmplitude = 10.0f;
                float minAmplitude = -10.0f;
                float normalized = (amplitude - minAmplitude) / (maxAmplitude - minAmplitude);

                std::cout << normalized << std::endl;

                // unsigned char r = (unsigned char)(255 * normalized);
                // unsigned char g = 0;
                // unsigned char b = (unsigned char)(255 * (1.0f - normalized));
                // Color color = { r, g, b, 255 };
                // if (normalized < 0.5f && normalized > 0.0f ||
                //     normalized < 0.0f && normalized > -0.5f)
                //     color = RAYWHITE;

                Color color;
                if (normalized > 0.5f)
                    color = {255, 0,0, 255};
                else if (normalized < -0.5f)
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