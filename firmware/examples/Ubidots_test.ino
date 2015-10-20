// This #include statement was automatically added by the Particle IDE.
#include "ATDUbidots.h"

//Include "HttpClient/HttpClient.h"!!!!

float lightLevel = 0;

ATDUbidots ubidots("YourVariableID","YourToken");

void setup() {
    
    pinMode(A0, INPUT);
    ubidots.connect();
}

void loop() {

    lightLevel = analogRead(A0);

    ubidots.sendValue(lightLevel);

    delay(1000);
}
