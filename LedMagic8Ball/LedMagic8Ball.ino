const int button = 13;
const int green  =  9;
const int red    = 10;
const int blue   = 11;
int result = 2;

void setup() {
  pinMode(button, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red,   OUTPUT);
  pinMode(blue,  OUTPUT);
}

void loop() {
  while(digitalRead(button)){
    result = random(3);
    
    analogWrite(green, random(255));
    analogWrite(red, random(255));
    analogWrite(blue, random(255));
    delay(50);
  }
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  
  switch(result){
    case 0:
      digitalWrite(red, HIGH);
      break;
    
    case 1:
      digitalWrite(green, HIGH);
      break;
      
    case 2:
      digitalWrite(blue, HIGH);
      break;
  }
}
