// Wave Equation Solver object class header file.
#pragma once

#include <cstddef>

namespace sim {
    class Field;

    class WaveSolver 
    {
    public:
        WaveSolver() = default;
        ~WaveSolver() = default;

        void solve(Field& field, float dt);
        
        void setWaveSpeed(float speed) { waveSpeed_ = speed; }
        float getWaveSpeed() const { return waveSpeed_; }

        void setDamping(float damping) { damping_ = damping; }
        float getDamping() const {return damping_; }

    private:
        float computeLaplacian(
            Field field,
            std::size_t x,
            std::size_t y
        ) const;

        float computeAcceleration(
            Field& field,
            std::size_t x,
            std::size_t y
        ) const;

        void applyFixedDirichletBoundary(Field& field) const;
        
        // Arbitrary values 
        float waveSpeed_ = 10.0f;
        float damping_ = 0.995f;
    };

}