# Rashid Project — ESP32-CAM Energy-Waste Detection

This repository contains the starter structure for a camera-based module that will later be integrated into a robot.

## Goal

Use an ESP32-CAM to inspect a room and identify:

- whether a person is visible;
- whether a light appears to be ON;
- whether an air conditioner (AC) appears to be ON;
- whether to send an energy-waste notification to an existing website.

**Alert rule:** `no_person AND (light_on OR ac_on)`

> Important: the ESP32-CAM is resource-constrained. Do not assume a standard YOLO model will run on it. First verify the exact board, PSRAM, framework, and available inference runtime. This starter code intentionally uses placeholder detection functions until a compatible model is selected and deployed.

## Current development plan

1. Confirm the exact camera board and available memory.
2. Flash and test camera capture.
3. Choose and test an on-device person-detection approach.
4. Collect labelled images and train compact light/AC classifiers on a computer.
5. Convert/deploy compatible models to the board.
6. Add alert decision logic and Wi-Fi notification delivery.
7. Test and document results before robot integration.

## Repository layout

```text
Rashed project/
├── README.md
├── .gitignore
├── LICENSE
├── platformio.ini
├── firmware/
│   └── src/
│       ├── main.cpp
│       ├── config.example.h
│       ├── camera_module.h
│       ├── camera_module.cpp
│       ├── detection.h
│       ├── detection.cpp
│       ├── decision_logic.h
│       ├── decision_logic.cpp
│       ├── notification_client.h
│       └── notification_client.cpp
├── ai/
│   ├── README.md
│   ├── requirements.txt
│   ├── dataset/
│   │   ├── README.md
│   │   └── .gitkeep
│   ├── training/
│   │   └── README.md
│   └── models/
│       └── README.md
├── docs/
│   ├── WORKFLOW.md
│   ├── DATA_COLLECTION.md
│   ├── MODEL_DEPLOYMENT.md
│   └── WEBSITE_API.md
└── tests/
    └── decision_logic_test_cases.md
```

## Safety and privacy

- Do not commit Wi-Fi passwords, API tokens, or private server URLs.
- Do not commit private images or identifiable people without permission.
- The camera's output is a visual estimate, not proof of electrical power state.
- Keep the alert rule and notification cooldown configurable.
