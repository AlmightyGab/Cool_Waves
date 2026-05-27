// Input binding management file.
#pragma once

#include <raylib.h>

namespace core {

class Input 
{
public:
    Input() = default;
    ~Input() = default;

    static bool pausePressed() { return IsKeyPressed(KEY_SPACE); }
};

}