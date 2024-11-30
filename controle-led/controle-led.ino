void setup() {
  pinMode(13, OUTPUT); //define a prota do led
  Serial.begin(9600);
}


char c;
void loop() {
  if (Serial.available() > 0){
    c = Serial.read(); //le o valor derial

    if (c == '1'){ // checa o valor serial
      digitalWrite (13,HIGH); //led liga
    }

    if (c == '0'){
      digitalWrite(13,LOW); // led desliga
    }
  }                   
}
