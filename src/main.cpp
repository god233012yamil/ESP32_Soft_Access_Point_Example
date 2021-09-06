// Main include file for the Arduino SDK
#include <Arduino.h>
// Include file to support esp32 Wifi.
#include <WiFi.h>

// Global variables declaration and initialization.
const char *ssid = "SSID";
const char *password = "Password";
IPAddress ip = {0, 0, 0, 0};

//testing
// Callback for WiFi events. This function will be called when a WiFi event takes place.
void WiFiEvent(WiFiEvent_t event, WiFiEventInfo_t info){  
    switch(event) {
        case SYSTEM_EVENT_AP_START:
            // Get the Access Point interface IP address.
            ip = WiFi.softAPIP();
            Serial.printf("\nAP started, IP address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
            break;
        
        case SYSTEM_EVENT_AP_STOP:
            Serial.println("AP stopped.");
            break;  
        
        case SYSTEM_EVENT_AP_STACONNECTED:
            Serial.printf("A station has connected.");             
            break; 
        
        case SYSTEM_EVENT_AP_STADISCONNECTED:
            Serial.println("A station has disconnected.");
            break;   

        case SYSTEM_EVENT_STA_GOT_IP: 
            Serial.println("A station got its IP.");
            break;             
        
        case SYSTEM_EVENT_STA_START:
        case SYSTEM_EVENT_STA_CONNECTED:
        case SYSTEM_EVENT_AP_STA_GOT_IP6:           
        case SYSTEM_EVENT_STA_DISCONNECTED: 
        default:
            break;
    }
}

void setup() {
  // Set a callback for WiFi events.
  WiFi.onEvent(WiFiEvent);
  // Setup WiFi to soft-AP mode .
  WiFi.mode(WIFI_MODE_AP);
  // ssid: name for the access point – maximum of 63 characters;
  // password: minimum of 8 characters; set to NULL if you want the access point to be open;
  WiFi.softAP(ssid, password);
  // Start Serial (UART0).
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
}