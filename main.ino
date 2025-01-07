// DISPLAY OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//RTC
#include "RTClib.h"
//DHT
#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT22

// Configuração do display OLED
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
// Configuração do RTC
RTC_DS3231 rtc;
// Configyração do DHT
DHT dht(DHTPIN, DHTTYPE);


void inicializarDispositivos(){
   // Inicializa o display OLED
   oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   oled.clearDisplay();
   oled.display();
   // Inicializa o RTC
   rtc.begin();
   // Inicializa o sensor DHT
   dht.begin();
}

// Função para exibir texto no OLED
void exibirTexto(const String texto, int x, int y, int tamanhoFonte) {
    oled.setCursor(x, y);        // Define a posição do texto
    oled.setTextSize(tamanhoFonte); // Define o tamanho do texto
    oled.setTextColor(WHITE);    // Define a cor do texto
    oled.print(texto);           // Exibe o texto
}

// Função para exibir Data e Hora
void exibirDataHora(){
  DateTime now = rtc.now();
  // Exibe a data no canto esquerdo
  exibirTexto(String(now.day()) + "/" + String(now.month()), 0, 0, 1);
  // Exibe a hora no meio da tela com texto maior
  exibirTexto(String(now.hour()) + ":" + String(now.minute()), 40, 20, 2);
}

// Função para exibir Temperatura
void exibirTemperatura(){
  float temperatura = dht.readTemperature();
  exibirTexto(String(temperatura, 1) + " C", 90, 50, 1);
}

void setup() {
  inicializarDispositivos(); // Inicializa todos os dispositivos
}

void loop() {
  oled.clearDisplay();  // Limpa o display para atualizar os dados

  exibirDataHora();
  exibirTemperatura();

  oled.display(); // Atualiza o display com os novos dados
  delay(1000); // Aguarda 1 segundo
}