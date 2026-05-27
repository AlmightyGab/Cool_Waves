// Application object class header file.
#pragma once

namespace core {

class Application 
{
public:
    Application() = default;
    ~Application() = default;
    void run();

private:
    void initialize();
    void update(float dt);
    void render();
    void shutdown();
};

}