// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonPushFormerState=0;
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button


// this constant won't change:
const int  buttonPin = 3;    // the pin that the pushbutton is attached to
const int ledPin = 4;       // the pin that the LED is attached to



void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode (ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

 digitalWrite(2, HIGH);
 //Serial.println(digitalRead(3) );

 // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      //buttonPushFormerState = buttonPushCounter;
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
      digitalWrite(ledPin,HIGH);
      
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
     
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;




//  // turns on the LED every four button pushes by checking the modulo of the
//  // button push counter. the modulo function gives you the remainder of the
//  // division of two numbers:
//if (buttonPushCounter> buttonPushFormerState ) {
//   digitalWrite(ledPin, HIGH);
//} else {
//    digitalWrite(ledPin, LOW);
// }


 

 
}
