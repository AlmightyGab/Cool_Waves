// Input binding management file.
#pragma once

#include <raylib.h>

class Input 
{
public:
    static bool pausePressed() { return IsKeyPressed(KEY_SPACE); }
};