#pragma once

#include <Arduino.h>

struct AlertPayload {
  String location;
  bool personDetected = false;
  bool lightOn = false;
  bool acOn = false;
  bool wasteDetected = false;
};

// Placeholder. Implement only after the website team confirms the API contract.
bool sendAlert(const AlertPayload& payload);
