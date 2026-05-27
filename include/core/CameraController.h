// CameraController class header file.
#pragma once

class Camera2D;

namespace core{

class CameraController
{
public:
    CameraController() = default;
    ~CameraController() = default;

    void update(Camera2D& camera);
};

}