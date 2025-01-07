# Relógio de Mesa com ESP32, OLED, DHT22 e RTC

Este projeto implementa um relógio de mesa digital utilizando uma placa ESP32. Ele exibe data, hora e temperatura em um display OLED, sendo ideal para aplicações domésticas ou educacionais. 

## Componentes do Sistema

- **ESP32**: Placa microcontroladora que executa o código.
- **Display OLED SSD1306**: Exibe informações de data, hora e temperatura.
- **Sensor DHT22**: Mede a temperatura do ambiente.
- **Módulo RTC DS3231**: Garante o controle preciso de data e hora.

## Funcionalidades

1. **Exibição de Data e Hora**:
   - Data formatada no canto superior esquerdo.
   - Hora centralizada com tamanho de fonte maior.

2. **Medição de Temperatura**:
   - Temperatura ambiente exibida no canto inferior direito.

3. **Atualização dos Dados**:
   - Dados atualizados automaticamente a cada segundo.

## Componentes Necessários

- 1 Placa ESP32
- 1 Display OLED SSD1306 (128x64 pixels)
- 1 Sensor de temperatura e umidade DHT22
- 1 Módulo RTC DS3231
- Jumpers e Protoboard

## Diagrama de Conexões

| Componente       | Pino no Componente | Pino no ESP32 |
|-------------------|---------------------|---------------|
| **OLED SSD1306** | SDA                 | GPIO 21       |
|                  | SCL                 | GPIO 22       |
| **RTC DS3231**   | SDA                 | GPIO 21       |
|                  | SCL                 | GPIO 22       |
| **DHT22**        | DATA                | GPIO 5        |
|                  | VCC                 | 3.3V          |
|                  | GND                 | GND           |

> **Nota**: O display OLED e o RTC compartilham o barramento I2C (SDA e SCL).

## Instalação e Configuração

### Pré-requisitos

1. Instale a **IDE Arduino**.
2. Adicione o suporte para a placa ESP32 na IDE Arduino (se ainda não tiver).
3. Instale as bibliotecas necessárias:
   - Adafruit GFX Library
   - Adafruit SSD1306
   - RTClib
   - DHT Sensor Library