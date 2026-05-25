// Application object class header file.
#pragma once

class Application 
{
public:
    void run();

private:
    void initialize();
    void update(float dt);
    void render();
    void shutdown();
};