// Simple grid rendering class header file.
#pragma once

namespace sim {
    class Field;
}

namespace graphics {

    class FieldRenderer
    {
    public: 
        void render(const sim::Field& field);
    };

}