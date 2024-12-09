#include <WiFi.h>
#include <WebServer.h>

// Access point credentials
const char* ssid = "ESP32_Test_Network"; // Wi-Fi network name
const char* password = "password1234";   // Wi-Fi password

// Creating an HTTP server on port 80
WebServer server(80);

// Function handling the main page
void handleRoot() {
  server.send(200, "text/html", "<h1>Welcome to the ESP32 Network!</h1><p>The ESP32 is operating as an access point.</p>");
}

// Function handling the list of devices connected to the AP
void handleDevices() {
  String deviceList = "<h1>Connected Devices</h1><ul>";
  wifi_sta_list_t wifi_sta_list;
  tcpip_adapter_sta_list_t adapter_sta_list;

  esp_wifi_ap_get_sta_list(&wifi_sta_list);
  tcpip_adapter_get_sta_list(&wifi_sta_list, &adapter_sta_list);

  for (int i = 0; i < adapter_sta_list.num; i++) {
    tcpip_adapter_sta_info_t station = adapter_sta_list.sta[i];
    char macStr[18];
    sprintf(macStr, "%02X:%02X:%02X:%02X:%02X:%02X",
            station.mac[0], station.mac[1], station.mac[2],
            station.mac[3], station.mac[4], station.mac[5]);
    deviceList += "<li>" + String(macStr) + "</li>";
  }

  deviceList += "</ul>";
  server.send(200, "text/html", deviceList);
}

// Function handling ESP32 restart
void handleRestart() {
  server.send(200, "text/plain", "Restarting ESP32...");
  delay(1000);
  ESP.restart();
}

void setup() {
  // Initializing serial port
  Serial.begin(115200);

  // Initializing Access Point mode
  WiFi.softAP(ssid, password);
  Serial.println("Wi-Fi network created");
  Serial.print("Network name: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);

  // ESP32 IP address in Access Point mode
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Registering paths handled by the HTTP server
  server.on("/", handleRoot);                 // Main page
  server.on("/devices", handleDevices);       // List of devices
  server.on("/restart", handleRestart);       // Restart ESP32

  // Starting the HTTP server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handling HTTP requests
  server.handleClient();
}
#include <WiFi.h>
#include <WebServer.h>

// Access point credentials
const char* ssid = "ESP32_Test_Network"; // Wi-Fi network name
const char* password = "password1234";   // Wi-Fi password

// Creating an HTTP server on port 80
WebServer server(80);

// Function handling the main page
void handleRoot() {
  server.send(200, "text/html", "<h1>Welcome to the ESP32 Network!</h1><p>The ESP32 is operating as an access point.</p>");
}

// Function handling the list of devices connected to the AP
void handleDevices() {
  String deviceList = "<h1>Connected Devices</h1><ul>";
  wifi_sta_list_t wifi_sta_list;
  tcpip_adapter_sta_list_t adapter_sta_list;

  esp_wifi_ap_get_sta_list(&wifi_sta_list);
  tcpip_adapter_get_sta_list(&wifi_sta_list, &adapter_sta_list);

  for (int i = 0; i < adapter_sta_list.num; i++) {
    tcpip_adapter_sta_info_t station = adapter_sta_list.sta[i];
    char macStr[18];
    sprintf(macStr, "%02X:%02X:%02X:%02X:%02X:%02X",
            station.mac[0], station.mac[1], station.mac[2],
            station.mac[3], station.mac[4], station.mac[5]);
    deviceList += "<li>" + String(macStr) + "</li>";
  }

  deviceList += "</ul>";
  server.send(200, "text/html", deviceList);
}

// Function handling ESP32 restart
void handleRestart() {
  server.send(200, "text/plain", "Restarting ESP32...");
  delay(1000);
  ESP.restart();
}

void setup() {
  // Initializing serial port
  Serial.begin(115200);

  // Initializing Access Point mode
  WiFi.softAP(ssid, password);
  Serial.println("Wi-Fi network created");
  Serial.print("Network name: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);

  // ESP32 IP address in Access Point mode
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Registering paths handled by the HTTP server
  server.on("/", handleRoot);                 // Main page
  server.on("/devices", handleDevices);       // List of devices
  server.on("/restart", handleRestart);       // Restart ESP32

  // Starting the HTTP server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handling HTTP requests
  server.handleClient();
}
