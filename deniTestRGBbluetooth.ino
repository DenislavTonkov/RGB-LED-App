#include "Arduino.h"
#include <SoftwareSerial.h>

// LED PINs
int whitePin = 12; 
int greenPin = 10;
int redPin = 11;

const byte rxPin = 9;
const byte txPin = 8;
//RX = pin on which to receive serial data | TX = pin on which to transmit serial data
SoftwareSerial BTSerial(rxPin, txPin);

void setup() {
  // defining pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  BTSerial.begin(9600);
//  Serial.begin(9600); 

  // defining pin modes for the RGB LED:
  pinMode(whitePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(BTSerial.available() > 0){
        
    // Read the RGB values from the Serial Buffer
    int whiteValue = BTSerial.parseInt();
    int greenValue = BTSerial.parseInt();
    int redValue = BTSerial.parseInt();

    if (whiteValue == 0 && greenValue == 0 && redValue == 0){
      ledsOff();
    }else if ((whiteValue == (255)) && (greenValue == 255) && (redValue == (255))){
      for (int i = 0; i < 5; i++){
        bgFlafFastCycle();
      }
    }
    else{
      setColor(whiteValue, greenValue, redValue);
    }
    serialFlush();
  }

}

void setColor(int white, int green, int red){
  analogWrite(whitePin, white);
  analogWrite(greenPin, green);
  analogWrite(redPin, red);
}

void ledsOff(){
  digitalWrite(whitePin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, LOW);
}

void serialFlush(){
  while(BTSerial.available() > 0){
    BTSerial.read();
  }
}

void bgFlafFastCycle(){
  setColor(255,255,255); // WHITE
  delay(500);
  ledsOff();
  setColor(0,255,0); // GREEN
  delay(500);
  ledsOff();
  setColor(255,0,0); // RED
  delay(500);
  ledsOff();
}
