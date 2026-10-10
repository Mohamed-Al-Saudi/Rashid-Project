# Dataset instructions

Keep private/raw images out of Git unless your team has permission to share them.

Suggested local folder structure:

```text
dataset/
├── person/
│   ├── person_present/
│   └── no_person/
├── light/
│   ├── light_on/
│   └── light_off/
└── ac/
    ├── ac_on/
    └── ac_off/
```

Capture images using the same camera angle and environment planned for deployment. Include variation in daylight, darkness, distance, occlusion, and room conditions. Split by recording session/scene rather than placing near-identical frames in both train and test sets.
