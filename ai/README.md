# AI workspace

Model training should initially happen on a laptop/desktop. The final model must be small enough for the exact ESP32-CAM board and runtime.

## Suggested order

1. Start with a pretrained person detector that has a compatible ESP32 deployment path.
2. Collect representative `light_on` and `light_off` images.
3. Collect representative `ac_on` and `ac_off` images.
4. Train compact image classifiers on a computer.
5. Evaluate false positives/false negatives.
6. Convert/quantize models to the format supported by the selected embedded inference runtime.
7. Test memory usage and latency on the physical board.

Do not assume TensorFlow/Keras, Ultralytics YOLO, or a desktop model can be installed directly on the ESP32-CAM. The ESP32 firmware needs a compatible embedded inference implementation.
