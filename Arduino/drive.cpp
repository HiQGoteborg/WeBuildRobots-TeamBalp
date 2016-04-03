#include "Arduino.h"
#include "timer.h"

static int debug = 0;

Timer timerHandler;

void setup()
{
#ifdef __AVR__
    Serial.begin(9600);
    Serial.println("setup(): println");
#endif
}

void loop()
{
    int timeout = timerHandler.handleTimeouts();
    if(debug) Serial.print("loop(): delay ");
    if(debug) Serial.println(timeout);
    if(timeout < 0) {
        timeout = 100;
    }
    delay(timeout);
}
