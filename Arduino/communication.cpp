//
#include <Wire.h>
#include "communication.h"

void Communication::receiveData(int byteCount)
{
    while(Wire.available()) {
        int number = Wire.read();
    }
    uint8_t version[] = {0,0};
    Wire.write(version, sizeof(version));
}

