#include <freertos_wrapper.h>
#include <WiFi.h>
#include <parameters.h>
#include "wifi_handler.h"
#include <logger.h>

void connectToWiFi()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  log_message("Verbinden met Wi-Fi");

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 30)
  {
    vTaskDelay(pdMS_TO_TICKS(500));
    log_message(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    log_message("\n Verbonden met Wi-Fi!");
  }
  else
  {
    log_message("\n Verbinding mislukt!");
  }
}

void disconnectWiFi()
{
  WiFi.disconnect(true); // true = vergeet netwerk
  WiFi.mode(WIFI_OFF);   // schakel Wi-Fi hardware uit
  log_message("Wi-Fi is uitgeschakeld en netwerk vergeten");
}

bool isWiFiConnected()
{
  return (WiFi.status() == WL_CONNECTED);
}
