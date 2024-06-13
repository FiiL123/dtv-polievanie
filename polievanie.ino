// C++ code

int moisture = 0;
int pumpPin = 3;
int bluePin = 5;
int yellowPin = 6;
int redPin = 7;
void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
//  pinMode(pumpPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  
}

void loop() {
  digitalWrite(A0, HIGH);
  delay(10);
  moisture = 1024 - analogRead(A1);
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(bluePin, LOW);
  analogWrite(pumpPin, 0);



  if( moisture < 400){
    // turn on pump
  	analogWrite(pumpPin, 250);
    Serial.print("Pump turned ON : ");
    delay(1000);
    digitalWrite(redPin, HIGH);
  }else{
    if (moisture < 600){
      digitalWrite(yellowPin, HIGH);
    }
    else{
      digitalWrite(bluePin, HIGH);
  }
  }

  delay(2000);

  

}
