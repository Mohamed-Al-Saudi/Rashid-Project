#pragma once

#include "camera_module.h"

struct DetectionResult {
  bool personDetected = false;
  bool lightOn = false;
  bool acOn = false;
  float personConfidence = 0.0f;
  float lightConfidence = 0.0f;
  float acConfidence = 0.0f;
};

// Placeholder only. These defaults are NOT AI predictions.
// Replace with compatible inference code and return real model outputs.
DetectionResult runDetections(const CameraFrame& frame);
