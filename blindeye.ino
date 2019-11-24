int trig = 4;
int echo =5;
int buzzer =11;
int Time;
int distance;
void setup() {
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
Time= pulseIn(echo,HIGH);
distance=0.034*Time/2;
if(distance<50&&distance>30){
  Serial.print('O');
  digitalWrite(buzzer,HIGH);
  delay(900);
  digitalWrite(buzzer,LOW);
  delay(50);
}
else if(distance<30&&distance>20){
  Serial.print('O');
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(50);
}
else if(distance<20){
  Serial.print('O');
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(50);
}
else{
  digitalWrite(buzzer,LOW);
}
}
