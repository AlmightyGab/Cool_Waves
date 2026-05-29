// Solver abstract object class header file.
#pragma once

class Grid2D;
class Field;

class Solver
{
public:
    Solver() = default;
    virtual ~Solver() = default;

    virtual void step(Field& field, Grid2D& grid, float dt) = 0;
};