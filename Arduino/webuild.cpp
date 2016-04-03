/**
 *
 * We Build Robots Team Balp
 *
 *
 */

#include <Wire.h>
#include <RedBot.h>

#include "communication.h"

#define SLAVE_ADDRESS 0x04

RedBotMotors motors;
Communication communication;

void receiveData(int byteCount) {
  communication.receiveData(byteCount);
}

void sendData() {
  communication.sendData();
}

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600); 
  Wire.begin(SLAVE_ADDRESS);

  //  motors.drive(255);   // Turn on Left and right motors at full speed forward.
  //  delay(2000);         // Waits for 2 seconds
  //  motors.stop();       // Stops both motors

  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  Serial.println("Ready!");

}

void loop()
{
}
