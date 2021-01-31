#include <TimerFreeTone.h>

const int buzzer = 0; // ATTiny pin 0
const int led = 1; // ATTiny pin 1
const int button = 2; // ATTiny pin 2

int microwaveNoises[] = {50, 2200, 0, 2200, 0, 2200, 0, 2200, 0, 2200, 0};
int duration[] = {10000, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500};

int buttonState = 1; 

void setup(){
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop(){
  buttonState = digitalRead(button);

  if (buttonState == LOW) { 
    digitalWrite(led, HIGH);
    for (int thisNote = 0; thisNote < 11; thisNote++) { 
      if (thisNote == 1) {
        digitalWrite(led, LOW);
      }
      TimerFreeTone(buzzer, microwaveNoises[thisNote], duration[thisNote]); 
    }   
  }
}                         
