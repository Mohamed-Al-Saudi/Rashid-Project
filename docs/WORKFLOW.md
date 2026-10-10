# End-to-end workflow

1. ESP32-CAM captures a frame.
2. Inference produces `person_detected`, `light_on`, and `ac_on`.
3. Decision rule: `!person_detected && (light_on || ac_on)`.
4. Confirm the condition over several consecutive samples.
5. Send one event to the website API.
6. Apply a cooldown/deduplication rule so one continuing event does not create repeated alerts.

## Suggested event JSON

```json
{
  "device_id": "rashed-cam-01",
  "location": "ROOM_101",
  "person_detected": false,
  "light_on": true,
  "ac_on": false,
  "waste_detected": true,
  "timestamp": "2026-01-01T12:00:00Z"
}
```

The timestamp above is only an example. Use a real timestamp source if required. Agree with the website team on field names and authentication before implementation.
