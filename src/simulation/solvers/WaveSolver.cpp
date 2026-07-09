// WaveSolver source file.

#include "simulation/solvers/WaveSolver.h"
#include <cstddef>
#include "simulation/fields/Field.h"

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

    float WaveSolver::computeAcceleration(Field& field, std::size_t x, std::size_t y) const
    {
        return getWaveSpeed() * getWaveSpeed() * computeLaplacian(field, x, y);
    }
    
    void WaveSolver::applyFixedDirichletBoundary(Field& field) const
    {
        std::size_t lastX = field.getWidth() - 1;
        std::size_t lastY = field.getHeight() - 1;

        for (std::size_t x = 0; x <= lastX; ++x) {
            field.at(x, 0).amplitude = 0;
            field.at(x, 0).velocity = 0;
            field.at(x, lastY).amplitude = 0;
            field.at(x, lastY).velocity = 0;
        }
        for (std::size_t y = 1; y < lastY; ++y) {
            field.at(0, y).amplitude = 0;
            field.at(0, y).velocity = 0;
            field.at(lastX, y).amplitude = 0;
            field.at(lastX, y).velocity = 0;
        }
    }

    void WaveSolver::solve(Field& field, float dt)
    {
        for (std::size_t y = 1; y < field.getHeight() - 1; ++y) {
            for (std::size_t x = 1; x < field.getWidth() - 1; ++x) {
                float acc = computeAcceleration(field, x, y);
                Cell& cell = field.at(x, y);

                cell.velocity += acc * dt;
                cell.velocity *= getDamping();

                cell.amplitude += cell.velocity * dt;
            }
        }

        applyFixedDirichletBoundary(field);
    }

}