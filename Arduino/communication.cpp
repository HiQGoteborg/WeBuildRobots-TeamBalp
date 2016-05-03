//
#include <Wire.h>
#include "communication.h"



void Communication::receiveData(int byteCount)
{
    while(Wire.available()) {
        int number = Wire.read();
        printf("... %d\n", number);
        if(_state == cmd) {
            switch (number) {
                case 0:
                    _state = data;
                    _cmd = version;
                    break;
                case 1:
                    _state = data;
                    _cmd = drive;
                    break;
                case 2:
                    _state = data;
                    _cmd = right;
                    break;
                case 3:
                    _state = data;
                    _cmd = left;
                    break;
                case 4:
                    _state = data;
                    _cmd = stop;
                    break;
            }
        } else {
            switch (_cmd) {
                case version:
                    {
                    uint8_t version[] = {0,0};
                    Wire.write(version, sizeof(version));
                    }
                    break;
                case drive:
                    {
                    _motors->drive(number);
                    printf("*** drive %p %d\n", _motors, number);
                    uint8_t version[] = {0,0};
                    Wire.write(version, sizeof(version));
                    }
                    break;
                case right:
                    {
                    _motors->rightMotor(number);
                    printf("*** rightMotor %p %d\n", _motors, number);
                    uint8_t version[] = {0,0};
                    Wire.write(version, sizeof(version));
                    }
                    break;
                case left:
                    {
                    _motors->leftMotor(number);
                    printf("*** leftMotor %p %d\n", _motors, number);
                    uint8_t version[] = {0,0};
                    Wire.write(version, sizeof(version));
                    }
                    break;
                case stop:
                    {
                    _motors->stop();
                    printf("*** stop %p %d\n", _motors, number);
                    uint8_t version[] = {0,0};
                    Wire.write(version, sizeof(version));
                    }
                    break;
            }
        }
    }
}

