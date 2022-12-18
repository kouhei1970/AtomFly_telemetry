#include <Arduino.h>
#include <M5Atom.h>
#include <WiFi.h>
#include <esp_now.h>

uint8_t data[1];

void dataRecv(const uint8_t *addr, const uint8_t *data, int dataSize) {
  //データ受信時に実行したい内容をここに書く。
  Serial.printf("%d\r\n", data[0]);
}


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  WiFi.mode(WIFI_STA); //Wi-Fi機能をステーションモードで起動
  WiFi.disconnect(); //初期化前にWi-Fi接続を切断
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESP-Now Init Success");
  }
  esp_now_register_recv_cb(dataRecv);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1);
}