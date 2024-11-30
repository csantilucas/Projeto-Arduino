int portLed = 12;
int luz = 500;
void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(portLed, OUTPUT);
}

void loop() {

  luz = analogRead(A0);
  if(luz > 200)
    digitalWrite(13, HIGH );
  else
    digitalWrite(13, LOW);
}
