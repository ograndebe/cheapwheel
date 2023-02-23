#include <WiFi.h>
#include <WebServer.h>

const char *SSID = "drogon";
const char *PWD = "oterrornegro";

WebServer server(80);

//https://microcontrollerslab.com/esp32-rest-api-web-server-get-post-postman/
void setup_routing() {     
  server.on("/home", getHome);
          
  server.begin();    
}

void getHome() {
  Serial.println("Get home");
  server.send(200, "application/json", "Hi I'm home!");
}
void setupWifi() {
    Serial.print("Connecting to Wi-Fi");
    WiFi.begin(SSID, PWD);
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
  
    Serial.print("Connected! IP Address: ");
    Serial.println(WiFi.localIP());
}

void setup()
{
 	Serial.begin(115200);
  setupWifi();
  setup_routing();    
}

void loop() {
 	// Serial.print("[Server Connected] ");
 	// Serial.println(WiFi.softAPIP());
  server.handleClient();  
 	// delay(500);
}