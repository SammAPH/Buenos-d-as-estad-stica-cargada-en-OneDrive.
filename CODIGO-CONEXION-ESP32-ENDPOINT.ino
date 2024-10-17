#include <WiFi.h>
#include <HTTPClient.h>

// Reemplaza con tu SSID y contraseña
const char* ssid = "Samm&";
const char* password = "DinoPulido2023";

const int RX_PIN = 16;  // Pin RX del ESP32
const int TX_PIN = 17;  // Pin TX del ESP32

// URL del endpoint expuesto por ngrok
const char* ngrokURL = "https://5640-181-155-230-183.ngrok-free.app/figures"; // Cambia esto por tu URL ngrok

unsigned long previousMillis = 0; // Almacena el último momento en que se realizó una solicitud
const long interval = 2000;      // Intervalo de 5 segundos

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);  // Configura el puerto Serial2 a 9600 baudios
  
  // Conexión a la red Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("\nConectado a la red Wi-Fi");
}

void loop() {
  unsigned long currentMillis = millis(); // Obtiene el tiempo actual

  // Realiza la solicitud al endpoint cada 5 segundos
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Actualiza el tiempo anterior
    consumeEndpoint();              // Realiza la solicitud al endpoint
  }
}

void consumeEndpoint() {
  if (WiFi.status() == WL_CONNECTED) { // Verifica si estás conectado a WiFi
    HTTPClient http;
    
    http.begin(ngrokURL); // Inicia la conexión con la URL
    int httpResponseCode = http.GET(); // Envía la solicitud GET
    
    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.println("Respuesta del servidor:");
      Serial.println(payload);
      
      // Enviar JSON completo directamente al Arduino
      sendDataToArduino(payload);
      
    } else {
      Serial.print("Error en la solicitud GET: ");
      Serial.println(httpResponseCode);
    }
    
    http.end(); // Finaliza la conexión
  } else {
    Serial.println("Error: No conectado a WiFi");
  }
}

void sendDataToArduino(const String &jsonData) {
  // Envía el JSON completo por Serial2 al Arduino
  Serial2.println(jsonData);  // Envía el JSON completo tal cual
  Serial.print("Enviado al Arduino - JSON: ");
  Serial.println(jsonData);  
}
