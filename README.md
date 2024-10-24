# Proyecto ESP32 y Arduino - Consumo de Endpoint con WiFi

Este proyecto utiliza un ESP32 para conectarse a una red WiFi, consumir datos de un endpoint expuesto por ngrok, y enviar esos datos a un Arduino a través de comunicación serial.

## Descripción

El ESP32 se conecta a una red WiFi y, cada 2 segundos, realiza una solicitud GET a un endpoint configurado. La respuesta en formato JSON obtenida del servidor se envía directamente al Arduino a través del puerto serial 2. El Arduino puede entonces utilizar estos datos para tomar decisiones o controlar otros dispositivos.

### Características principales

- Conexión a una red WiFi utilizando el ESP32.
- Consumo de datos desde un endpoint RESTful a través de HTTP.
- Comunicación serial entre el ESP32 y el Arduino para enviar datos.
- Intervalo de 2 segundos entre cada solicitud al endpoint.

## Requisitos

- **ESP32**
- **Arduino**
- **Conexión a internet** (para que el ESP32 se conecte a la red WiFi)
- **ngrok** o cualquier otro servicio que exponga el endpoint a través de internet.

## Instalación

1. **Clonar el repositorio:**

   ```bash
   git clone https://github.com/tu_usuario/tu_repositorio.git
