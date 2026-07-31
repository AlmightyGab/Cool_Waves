// Cell data struct header file.
#pragma once


namespace sim {

struct Cell 
{
    float amplitude = 0.0f;
    float previousAmplitude = 0.0f;

    bool isSource = false;

    Cell& operator=(const Cell& other)
    {
        if (this != &other) {
            amplitude = other.amplitude;
            previousAmplitude = other.previousAmplitude;
            isSource = other.isSource;
        }

        return *this;
    }
};

}