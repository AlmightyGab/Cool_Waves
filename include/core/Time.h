// Time system header file.
#pragma once

#include <raylib.h>

namespace core {

class Time 
{
public:
    Time() = default;
    ~Time() = default;

    static float deltaTime;
    static float totalTime;

    static void update()
    {
        deltaTime = GetFrameTime();
        totalTime += deltaTime;
    }
};

}