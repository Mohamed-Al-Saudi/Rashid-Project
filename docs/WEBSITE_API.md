# Website API integration

Ask the website/backend developer for:
- exact endpoint URL and HTTP method;
- required JSON fields;
- authentication/token method;
- expected success response/status;
- duplicate-event handling;
- whether the API is HTTPS;
- whether the device can reach the server on the robot's Wi-Fi/network.

Suggested request body:

```json
{
  "device_id": "rashed-cam-01",
  "location": "ROOM_101",
  "person_detected": false,
  "light_on": true,
  "ac_on": false,
  "waste_detected": true
}
```

Do not invent the endpoint or credentials. The sample route in `config.example.h` is a placeholder.
