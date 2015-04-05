/*

  LED Magic 8 Ball
  (C) 2015 Thijs van Beers

*/

//Pins of the pushbutton and RGB LED
const int button = 13;
const int green  =  9;
const int red    = 10;
const int blue   = 11;

//Value to store the result
int result = 2;

void setup() {
  //The pushbutton is an input, the RGB LED is an output
  pinMode(button, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red,   OUTPUT);
  pinMode(blue,  OUTPUT);
}

void loop() {
  while(digitalRead(button)){
    //When the button is being pressed, keep changing the result and color of the RGB LED
    result = random(3);
    
    analogWrite(green, random(255));
    analogWrite(red, random(255));
    analogWrite(blue, random(255));
    delay(50);
  }
  
  //When the button is no longer being pressed, first turn off the RGB LED
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  
  //Then turn it to the color for the result
  switch(result){
    case 0:
      digitalWrite(red, HIGH);
      //Red for no
      break;
    
    case 1:
      digitalWrite(green, HIGH);
      //Green for yes
      break;
      
    case 2:
      digitalWrite(blue, HIGH);
      //Blue for maybe
      break;
  }
}
