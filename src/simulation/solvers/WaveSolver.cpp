// WaveSolver source file.

#include "simulation/solvers/WaveSolver.h"
#include <cstddef>
#include "simulation/grid/Grid2D.h"

namespace sim {

    float WaveSolver::computeLaplacian(const Grid2D& grid, std::size_t x, std::size_t y) const
    {
        // Amplitudes relative to the provided coordinate
        float center = grid.getCell(x, y).amplitude;
        float right = grid.getCell(x + 1, y).amplitude;
        float left = grid.getCell(x - 1, y).amplitude;
        float up = grid.getCell(x, y + 1).amplitude;
        float down = grid.getCell(x, y - 1).amplitude;

        // Actual amplitude laplacian calculation
        return right + left + up + down - 4.0f * center;
    }

    float WaveSolver::computeAcceleration(Grid2D& grid, std::size_t x, std::size_t y) const
    {
        return getWaveSpeed() * getWaveSpeed() * computeLaplacian(grid, x, y);
    }
    
    void WaveSolver::applyFixedDirichletBoundary(Grid2D& grid) const
    {
        std::size_t lastX = grid.getWidth() - 1;
        std::size_t lastY = grid.getHeight() - 1;

        for (std::size_t x = 0; x <= lastX; ++x) {
            grid.getCell(x, 0).amplitude = 0;
            grid.getCell(x, 0).velocity = 0;
            grid.getCell(x, lastY).amplitude = 0;
            grid.getCell(x, lastY).velocity = 0;
        }
        for (std::size_t y = 1; y < lastY; ++y) {
            grid.getCell(0, y).amplitude = 0;
            grid.getCell(0, y).velocity = 0;
            grid.getCell(lastX, y).amplitude = 0;
            grid.getCell(lastX, y).velocity = 0;
        }
    }

    void WaveSolver::step(Grid2D& grid, float dt)
    {
        for (std::size_t x = 0; x <= grid.getWidth(); ++x) {
            for (std::size_t y = 0; y <= grid.getHeight(); ++y) {
                float acc = computeAcceleration(grid, x, y);
                Cell& cell = grid.getCell(x, y);

                cell.velocity += acc * dt;
                cell.velocity *= getDamping();

                cell.amplitude += cell.velocity * dt;
            }
        }

        applyFixedDirichletBoundary(grid);
    }

}