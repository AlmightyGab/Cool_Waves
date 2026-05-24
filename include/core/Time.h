// Time system header file.
#pragma once

#include <raylib.h>
class Time 
{
public:
    static float deltaTime;
    static float totalTime;

    static void update()
    {
        deltaTime = GetFrameTime();
        totalTime += deltaTime;
    }
};