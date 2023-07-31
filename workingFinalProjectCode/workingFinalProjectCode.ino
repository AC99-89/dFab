/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <ESP32Servo.h>
#include <esp_now.h>
#include <WiFi.h>
#define SERVO_PIN 19 // servo 1
#define SERVO_PIN2 33 // servo 2

Servo servoMotor;
Servo servoMotor2;

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    bool d;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.print("Bool: ");
  Serial.println(myData.d);
  Serial.println();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  servoMotor.attach(SERVO_PIN); // attaches first servo
  servoMotor2.attach(SERVO_PIN2);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {
  if (myData.d == true){
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