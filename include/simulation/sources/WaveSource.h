// Wave Source object header file.
#pragma once

namespace sim {

    class WaveSource 
    {
    public:
        WaveSource() = default;
        virtual ~WaveSource() = default;

        virtual void apply();
    };

}