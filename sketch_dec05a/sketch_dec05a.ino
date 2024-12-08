#include <WiFi.h>
#include <WebServer.h>

// Dane punktu dostępu
const char* ssid = "ESP32_Test_Network"; // Nazwa sieci WiFi
const char* password = "password1234";   // Hasło do sieci WiFi

// Tworzenie serwera HTTP na porcie 80
WebServer server(80);

// Funkcja obsługująca stronę główną
void handleRoot() {
  server.send(200, "text/html", "<h1>Witaj w sieci ESP32!</h1><p>ESP32 działa jako punkt dostępu.</p>");
}

// Funkcja obsługująca listę urządzeń podłączonych do AP
void handleDevices() {
  String deviceList = "<h1>Podłączone urządzenia</h1><ul>";
  wifi_sta_list_t wifi_sta_list;
  adapter_sta_list_t adapter_sta_list;

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

// Funkcja obsługująca restart ESP32
void handleRestart() {
  server.send(200, "text/plain", "Restartowanie ESP32...");
  delay(1000);
  ESP.restart();
}

void setup() {
  // Inicjalizacja portu szeregowego
  Serial.begin(115200);

  // Inicjalizacja trybu Access Point
  WiFi.softAP(ssid, password);
  Serial.println("Sieć WiFi utworzona");
  Serial.print("Nazwa sieci: ");
  Serial.println(ssid);
  Serial.print("Hasło: ");
  Serial.println(password);

  // Adres IP ESP32 w trybie Access Point
  Serial.print("Adres IP: ");
  Serial.println(WiFi.softAPIP());

  // Rejestrowanie obsługiwanych ścieżek w serwerze HTTP
  server.on("/", handleRoot);                 // Strona główna
  server.on("/devices", handleDevices);       // Lista urządzeń
  server.on("/restart", handleRestart);       // Restart ESP32

  // Start serwera HTTP
  server.begin();
  Serial.println("Serwer HTTP uruchomiony");
}

void loop() {
  // Obsługa żądań HTTP
  server.handleClient();
}
