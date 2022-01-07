#include <ESP8266WiFi.h>

#define redLed D3
#define yellowLed D4

WiFiClient client;
WiFiServer server(80);

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
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
}

void loop() {
    client=server.available();
    if(client==1){
      String request = client.readStringUntil('\n');
      request.trim();
      Serial.println(request);

      if(request=="GET /r1 HTTP/1.1"){
    digitalWrite(redLed,HIGH);
  }
  if(request=="GET /y1 HTTP/1.1"){
    digitalWrite(yellowLed,HIGH);
  }
    if(request=="GET /r2 HTTP/1.1"){
    digitalWrite(redLed,LOW);
  }
  if(request=="GET /y2 HTTP/1.1"){
    digitalWrite(yellowLed,LOW);
  }
    }       
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<a href=\"/r1\"\"><button>Red ON</button></a>");
    client.println("<a href=\"/y1\"\"><button>Yellow ON</button></a>");
    client.println("<a href=\"/r2\"\"><button>Red OFF</button></a>");
    client.println("<a href=\"/y2\"\"><button>Yellow OFF</button></a>");
    client.println("</html>");

    
  
 
}
