// Wave Source base object header file.
#pragma once

namespace sim {
    class Field;

    class WaveSource 
    {
    public:
        explicit WaveSource() = default;
        virtual ~WaveSource() = default;

        virtual void apply(Field& field, float time, float dt) = 0;
    };

}