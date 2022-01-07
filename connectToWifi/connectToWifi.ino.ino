#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);
  WiFi.begin("Redmi","anukul152");
  Serial.print("[!] Trying to make connection");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print('.');
    delay(200);
  }
  Serial.println();
  Serial.println("Connected Successfully!");
  Serial.print(WiFi.localIP());
}

void loop() {
                   
}
