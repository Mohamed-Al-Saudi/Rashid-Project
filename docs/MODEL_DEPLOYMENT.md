# Model deployment checklist

Before selecting a model, record:
- exact board name/revision;
- ESP32 chip type;
- PSRAM available and amount;
- camera sensor;
- Arduino-ESP32 or ESP-IDF version;
- inference runtime/framework;
- maximum acceptable inference time;
- available flash/RAM after camera initialization.

Then:
1. Choose a model with a documented path to that runtime.
2. Resize/normalize input exactly as during training.
3. Convert and quantize if supported.
4. Test model output on saved images before using live frames.
5. Measure latency, peak RAM, and stability over an extended run.
6. Test false alarms in the real room.
7. Only then enable website alerts.

The common ESP32-CAM has limited resources. If the combined models do not fit or run fast enough, discuss a compatible ESP32-S3 camera board or external compute with the team before promising on-device inference.
