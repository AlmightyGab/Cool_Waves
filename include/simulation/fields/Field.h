// Field object class header file. (kind of like a 2D memory wrapper)
#pragma once

#include <raylib.h>

class Grid2D;

namespace field {

class Field
{
public:
    Field(Grid2D* grid);
    virtual ~Field();

    Vector2 getSize() const { return size_; }

    float get();

private:
    Vector2 size_;
};

}