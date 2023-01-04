//AtomFly2 Telemetry
#include <Arduino.h>
#include <M5Atom.h>
#include <WiFi.h>
#include <esp_now.h>

uint8_t data[1];

void dataRecv(const uint8_t *addr, const uint8_t *data, int datasize) {
  //データ受信時に実行したい内容をここに書く。
  float a;
  uint8_t *dummy;
  dummy=(uint8_t*)&a;
  
  for (uint8_t i=0; i<(datasize/4); i++)
  {
    dummy[0]=data[i*4];
    dummy[1]=data[i*4+1];
    dummy[2]=data[i*4+2];
    dummy[3]=data[i*4+3];
    Serial.printf("%9.4f ", a);
  }
  Serial.printf("\r\n");
}


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  WiFi.mode(WIFI_STA); //Wi-Fi機能をステーションモードで起動
  WiFi.disconnect(); //初期化前にWi-Fi接続を切断
  Serial.printf("MAC ADDRESS: %s\r\n", (WiFi.macAddress()).c_str());
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESP-Now Init Success");
  }
  esp_now_register_recv_cb(dataRecv);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1);
}