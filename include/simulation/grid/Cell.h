// Cell data struct header file.
#pragma once


namespace sim {

struct Cell 
{
    float amplitude = 0.0f;
    float previousAmplitude = 0.0f;

    bool isSource = false;
};

}