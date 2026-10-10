#pragma once

#include <Arduino.h>
#include "esp_camera.h"

struct CameraFrame {
  camera_fb_t* fb = nullptr;
};

bool cameraBegin();
bool cameraCapture(CameraFrame& frame);
void cameraRelease(CameraFrame& frame);
