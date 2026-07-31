// WaveSolver source file.

#include "simulation/solvers/WaveSolver.h"
#include <cstddef>
#include <raylib.h>
#include "simulation/fields/Field.h"
#include "core/MathUtils.h"

namespace sim {

    float WaveSolver::computeLaplacian(Field field, std::size_t x, std::size_t y) const
    {
        // Amplitudes relative to the provided coordinate
        float center = field.at(x, y).amplitude;
        float right = field.at(x + 1, y).amplitude;
        float left = field.at(x - 1, y).amplitude;
        float up = field.at(x, y + 1).amplitude;
        float down = field.at(x, y - 1).amplitude;

        // Actual amplitude laplacian calculation
        return right + left + up + down - 4.0f * center;
    }

    void WaveSolver::applyFixedDirichletBoundary(Field& field) const
    {
        std::size_t lastX = field.getWidth() - 1;
        std::size_t lastY = field.getHeight() - 1;

        for (std::size_t x = 0; x <= lastX; ++x) {
            field.at(x, 0).amplitude = 0;
            field.at(x, lastY).amplitude = 0;
        }
        for (std::size_t y = 1; y < lastY; ++y) {
            field.at(0, y).amplitude = 0;
            field.at(lastX, y).amplitude = 0;
        }
    }

    void WaveSolver::solve(Field& field, float dt)
    {
        Field nextField = field;

        for (std::size_t y = 1; y < field.getHeight() - 1; ++y) {
            for (std::size_t x = 1; x < field.getWidth() - 1; ++x) {
                
                Cell& currentCell = field.at(x, y);
                Cell& newCell = nextField.at(x, y);

                // if (currentCell.isSource) 
                //     currentCell.amplitude

                float laplacian = computeLaplacian(field, x, y);
                float damping = getDampingCoefficient();

                newCell.amplitude = 
                    (2.0f - damping * dt) * currentCell.amplitude
                    - (1.0f - damping * dt) * currentCell.previousAmplitude
                    + math::square(getWaveSpeed() * dt) * laplacian;

                newCell.previousAmplitude = currentCell.amplitude;
            }
        }

        field = std::move(nextField);

        applyFixedDirichletBoundary(field);
    }

}