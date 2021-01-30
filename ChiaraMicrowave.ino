const int buzzer = 11; //buzzer to arduino pin 11
const int led = 9;
const int button = 12;

int buttonState = 0; 

void setup(){
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop(){

  buttonState = digitalRead(button);
  Serial.println(buttonState);

  if (buttonState == HIGH) { 
    digitalWrite(led, HIGH);
    tone(buzzer, 50); // Send 1KHz sound signal...
    delay(10000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    digitalWrite(led, LOW);
    for(int i = 0; i < 5; i++) {
      tone(buzzer, 2200); // Send 1KHz sound signal...
      delay(500);        // ...for 1sec
      noTone(buzzer);     // Stop sound...
      delay(500);        // ...for 1sec
    }
  }
}
