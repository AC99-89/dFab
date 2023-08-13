#include <ESP32Servo.h>
#include "WiFi.h"
#include <esp_now.h>
#define SERVO_PIN 19 // ESP32 pin GPIO26 connected to servo motor
#define SERVO_PIN2 33
Servo servoMotor;
Servo servoMotor2;

String success;

byte incomingByte;
byte outgoingByte;

bool buttonPressed = false;


uint8_t broadcastAddress[] =  {0x34, 0x85, 0x18, 0x00, 0x8F, 0xC0};    //thiboard no 1.
//uint8_t broadcastAddress[] =  {0x24, 0x62, 0xAB, 0xB0, 0x34, 0x8C};  this is ///board no 2

typedef struct struct_message {
  bool buttonPressed;

} struct_message; // Recieves the data from Xiao
struct_message myData;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  if (status ==0){
    success = "Delivery Success :)";
  }
  else{
    success = "Delivery Fail :(";
  }
}

// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&incomingByte, incomingData, sizeof(incomingByte));
  Serial.print("Bytes received: ");
  Serial.println(len);
}

void setup() {
  // Init Serial Monitor
  Serial.begin(115200);


  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }



  // Register for a callback function that will be called when data is received
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  esp_now_peer_info_t peerInfo;
  memset(&peerInfo, 0, sizeof(peerInfo));
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;

// void OnDataRecv(uint8_t * mac, const uint8_t *incomingData, bool buttonPressed) {
//   memcpy(&myData, incomingData, sizeof(myData));
//   Serial.print("Bool: ");
//   Serial.println(myData.buttonPressed);
//   Serial.println();
// }

// void setup() {
//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA);
//   if (esp_now_init() != ESP_OK) {
//     Serial.println("Error initializing ESP-NOW");
//     return;
//   }
//   servoMotor.attach(SERVO_PIN);  // attaches the servo on ESP32 pin
//   servoMotor2.attach(SERVO_PIN2);


// }

//  esp_now_register_recv_cb(OnDataRecv);
}
void loop() {
  if (buttonPressed == true){
// rotates from 0 degrees to 180 degrees
    for (int pos = 0; pos <= 180; pos += 1) {
    // in steps of 1 degree
      servoMotor.write(pos);
      servoMotor2.write(pos);
      delay(15); // waits 15ms to reach the position
  }

  // rotates from 180 degrees to 0 degrees
    for (int pos = 180; pos >= 0; pos -= 1) {
      servoMotor.write(pos);
      servoMotor2.write(pos);
      delay(15); // waits 15ms to reach the position
  }
  }
  
}