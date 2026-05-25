// CameraController class definition file.

#include <raylib.h>
#include "../../include/core/CameraController.h"

void CameraController::update(Camera2D& camera)
{
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        Vector2 delta = GetMouseDelta();
        
        float scaling = -1.0f / camera.zoom;
        delta.x *= scaling;
        delta.y *= scaling;

        camera.target.x += delta.x;
        camera.target.y += delta.y;
    }

    float mouseWheel = GetMouseWheelMove();
    if (mouseWheel != 0) {
        camera.offset = GetMousePosition();
        camera.target = GetScreenToWorld2D(GetMousePosition(), camera);
        camera.zoom += (mouseWheel * 0.125f);
        if (camera.zoom < 0.1f)
            camera.zoom = 0.1f;
    }
}