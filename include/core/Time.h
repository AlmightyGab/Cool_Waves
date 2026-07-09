// Time system header file.
#pragma once

#include <raylib.h>

namespace core {

class Time 
{
public:
    inline static float deltaTime;
    inline static float totalTime;

    static void update()
    {
        deltaTime = GetFrameTime();
        totalTime += deltaTime;
    }
};

}