// Wave Equation Solver object class header file.
#pragma once

#include <cstddef>

namespace sim {
    class Grid2D;

    class WaveSolver 
    {
    public:
        WaveSolver() = default;
        ~WaveSolver() = default;

        void step(Grid2D& grid, float dt);
        
        void setWaveSpeed(float speed) { waveSpeed_ = speed; }
        float getWaveSpeed() const { return waveSpeed_; }

        void setDamping(float damping) { damping_ = damping; }
        float getDamping() const {return damping_; }

    private:
        float computeLaplacian(
            const Grid2D& grid,
            std::size_t x,
            std::size_t y
        ) const;

        float computeAcceleration(
            Grid2D& grid,
            std::size_t x,
            std::size_t y
        ) const;

        void applyFixedDirichletBoundary(Grid2D& grid) const;
        
        float waveSpeed_;
        float damping_;
    };

}