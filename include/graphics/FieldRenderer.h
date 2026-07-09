// Simple grid rendering class header file.
#pragma once

#include "simulation/fields/Field.h"

namespace graphics {

class FieldRenderer
{
public: 
    void render(const sim::Field& field);
};

}