#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* pass = "";

unsigned const long interval = 2000;
unsigned long zero = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println(".");
  }
  Serial.println("WiFi Connected!");
  Serial.println(WiFi.localIP());
  
  pinMode(LED_BUILTIN, OUTPUT); 
}

void loop() {
  if (millis() - zero > interval) {
    HTTPClient http;
    http.begin("https://s-m.com.sa/l.html");
    int httpResponCode = http.GET();
    Serial.println(httpResponCode);
    if (httpResponCode > 0) {
      String payload = http.getString();
      payload.trim(); 
      Serial.print(payload);

      if (payload == "S" || payload.equalsIgnoreCase("stop")) {
        // Action for S: Turn LED off
        Serial.println("Action: Stop (LED OFF)");
        digitalWrite(LED_BUILTIN, LOW);
      } else if (payload == "F" || payload.equalsIgnoreCase("forward")) {
        // Action for F: Turn LED on
        Serial.println("Action: Move Forward (LED ON)");
        digitalWrite(LED_BUILTIN, HIGH);
      } else if (payload == "B" || payload.equalsIgnoreCase("backward")) {
        // Action for B: Blink LED
        Serial.println("Action: Move Backward (LED BLINK)");
        for (int i = 0; i < 5; i++) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(200);
          digitalWrite(LED_BUILTIN, LOW);
          delay(200);
        }
      } else if (payload == "R" || payload.equalsIgnoreCase("right")) {
        // Action for R: Blink LED rapidly
        Serial.println("Action: Turn Right (LED FAST BLINK)");
        for (int i = 0; i < 10; i++) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(100);
          digitalWrite(LED_BUILTIN, LOW);
          delay(100);
        }
      } else if (payload == "L" || payload.equalsIgnoreCase("left")) {
        // Action for L: Blink LED slowly
        Serial.println("Action: Turn Left (LED SLOW BLINK)");
        for (int i = 0; i < 3; i++) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
        }
      } else {
        Serial.println("Unknown command");
      }
    } else {
      Serial.print("Error: ");
      Serial.println(httpResponCode);
    }

    zero = millis();
  }
}
