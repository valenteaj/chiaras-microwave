#include <TimerFreeTone.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

const int buzzer = 0; // ATTiny pin 0
const int led = 1; // ATTiny pin 1
const int button = 2; // ATTiny pin 2

int microwaveNoises[] = {50, 2400, 0, 2400, 0, 2400, 0, 2400, 0, 2400, 0};
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
    doMicrowaveThings();
  }
  enterSleep();
}

void doMicrowaveThings() {
  digitalWrite(led, HIGH);
  for (int thisNote = 0; thisNote < 11; thisNote++) { 
    if (thisNote == 1) {
      digitalWrite(led, LOW);
    }
    TimerFreeTone(buzzer, microwaveNoises[thisNote], duration[thisNote]); 
  }   
}

void enterSleep() {
  GIMSK |= _BV(PCIE);                     // Enable Pin Change Interrupts
  PCMSK |= _BV(PCINT2);                   // Use PB2 as interrupt pin
  ADCSRA &= ~_BV(ADEN);                   // ADC off
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);    // replaces above statement
  sleep_enable();                         // Sets the Sleep Enable bit in the MCUCR Register (SE BIT)
  sei();                                  // Enable interrupts
  sleep_cpu();                            // sleep
  cli();                                  // Disable interrupts
  PCMSK &= ~_BV(PCINT2);                  // Turn off PB2 as interrupt pin
  sleep_disable();                        // Clear SE bit
  ADCSRA |= _BV(ADEN);                    // ADC on
  sei();                                  // Enable interrupts
}

ISR(PCINT0_vect) {

}
