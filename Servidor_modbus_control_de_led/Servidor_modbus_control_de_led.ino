#ifdef ESP8266
 #include <ESP8266WiFi.h>
#else //ESP32
 #include <WiFi.h>
#endif
#include <ModbusIP_ESP8266.h>

//REGISTRO MODBUS
const int LED_COIL = 0;

//PIN LED
const int ledPin = 13; 

ModbusIP mb;

void setup() {
  
  Serial.begin(115200);
  WiFi.begin("Wifi", "12345678");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");  
  Serial.println("Direccion IP: ");
  Serial.println(WiFi.localIP()); 

  mb.server();

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  mb.addCoil(LED_COIL);

}

void loop() {

  mb.task();
  
  digitalWrite(ledPin,mb.Coil(LED_COIL));
  
  delay(10);
  
}
