#include "notification_client.h"

bool sendAlert(const AlertPayload& payload) {
  // TODO:
  // - Include WiFi.h and HTTPClient.h.
  // - Connect to Wi-Fi using private config.h values.
  // - POST JSON to the agreed API endpoint.
  // - Use HTTPS where supported and follow the website's authentication rules.
  // - Check HTTP status code and return true only on success.
  //
  // Do not print passwords or API tokens to Serial.
  (void)payload;
  Serial.println("Notification client is not implemented yet.");
  return false;
}
