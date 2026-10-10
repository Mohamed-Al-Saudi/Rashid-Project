#include <Arduino.h>
#include "camera_module.h"
#include "detection.h"
#include "decision_logic.h"
#include "notification_client.h"

// TODO 1: Copy config.example.h to config.h and fill in your Wi-Fi/API settings.
// TODO 2: Confirm the exact ESP32-CAM board and its camera pin mapping.
// TODO 3: Replace placeholder detection functions with real on-device inference.

static const unsigned long SAMPLE_INTERVAL_MS = 2000;
static const unsigned long ALERT_COOLDOWN_MS = 60000;

unsigned long lastSampleMs = 0;
unsigned long lastAlertMs = 0;
String currentLocation = "UNKNOWN_LOCATION"; // TODO: update after QR decoding is implemented

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.println("Rashed Project starting...");

  if (!cameraBegin()) {
    Serial.println("ERROR: camera initialization failed.");
    while (true) {
      delay(1000);
    }
  }

  // TODO: initialize Wi-Fi after config.h is created and included safely.
  // TODO: add QR-code scanning to set currentLocation.
  // TODO: connect Wi-Fi and verify API endpoint with the website team.
}

void loop() {
  const unsigned long now = millis();
  if (now - lastSampleMs < SAMPLE_INTERVAL_MS) {
    delay(10);
    return;
  }
  lastSampleMs = now;

  CameraFrame frame;
  if (!cameraCapture(frame)) {
    Serial.println("WARN: failed to capture frame.");
    return;
  }

  DetectionResult result = runDetections(frame);
  const bool wasteDetected = shouldAlert(result);

  Serial.printf("Location=%s person=%s light=%s ac=%s waste=%s\n",
                currentLocation.c_str(),
                result.personDetected ? "YES" : "NO",
                result.lightOn ? "ON" : "OFF",
                result.acOn ? "ON" : "OFF",
                wasteDetected ? "YES" : "NO");

  if (wasteDetected && (now - lastAlertMs >= ALERT_COOLDOWN_MS)) {
    AlertPayload payload;
    payload.location = currentLocation;
    payload.personDetected = result.personDetected;
    payload.lightOn = result.lightOn;
    payload.acOn = result.acOn;
    payload.wasteDetected = true;

    if (sendAlert(payload)) {
      lastAlertMs = now;
      Serial.println("Alert submitted.");
    } else {
      Serial.println("WARN: alert submission failed.");
    }
  }

  cameraRelease(frame);
}
