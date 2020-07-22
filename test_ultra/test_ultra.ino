const int trig_pin_front=2;
const int echo_pin_front=3;
const int trig_pin_sidefront=4;
const int echo_pin_sidefront=5;
int int1=6;
int int2=9;
int int3=12;
int int4=13;
int motor1_enable=10;
int motor2_enable=11;
const int trig_pin_sideback=7;
const int echo_pin_sideback=8;
void setup(){
  Serial.begin(9600);
  pinMode(trig_pin_front,OUTPUT);
  pinMode(echo_pin_front,INPUT);
  pinMode(trig_pin_sidefront,OUTPUT);
  pinMode(echo_pin_sidefront,INPUT);
  pinMode(int1,OUTPUT);
  pinMode(trig_pin_sideback,OUTPUT);
  pinMode(echo_pin_sideback,INPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  pinMode(motor1_enable,OUTPUT);
  pinMode(motor2_enable,OUTPUT);
}
int front_uv(){
  digitalWrite(trig_pin_front,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_front,HIGH);
  delayMicroseconds(8);
  digitalWrite(trig_pin_front,LOW);
  
  float duration0,distance0;
  duration0=pulseIn(echo_pin_front,HIGH);
  distance0=(duration0*0.0343)/2;
  Serial.print("distance0: ");
  Serial.println(distance0);
  delay(1000);
  return distance0;
}

int side_first_uv(){
  digitalWrite(trig_pin_sidefront,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_sidefront,HIGH);
  delayMicroseconds(8);
  digitalWrite(trig_pin_sidefront,LOW);
  
  float duration1,distance1;
  duration1=pulseIn(echo_pin_sidefront,HIGH);
  distance1=(duration1*0.0343)/2;
  Serial.print("distance1: ");
  Serial.println(distance1);
  delay(1000);
  return distance1;
}


int side_second_uv(){
  digitalWrite(trig_pin_sideback,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_sideback,HIGH);
  delayMicroseconds(8);
  digitalWrite(trig_pin_sideback,LOW);

  float duration2,distance2;
  duration2=pulseIn(echo_pin_sideback,HIGH);
  distance2=(duration2*0.0343)/2;
  Serial.print("distance2: ");
  Serial.println(distance2);
  delay(1000);
  return distance2;
}
void loop(){
  float distance0, distance1,distance2;
  distance0=front_uv();
  distance1=side_first_uv();
  distance2=side_second_uv();
  digitalWrite(int1,HIGH);
  digitalWrite(int2,LOW);
  digitalWrite(int3,HIGH);
  digitalWrite(int4,LOW);
  if(6<=distance1<=10 && 6<=distance2<=10)
  { Serial.print("distance 1 ==:");
  Serial.print(distance1);
  Serial.print("      ");
  Serial.print("distance2=");
  Serial.println(distance2);
    if(distance1>distance2){
      analogWrite(motor1_enable,150);
      analogWrite(motor2_enable,125);
      Serial.println("taking slight right");
    }
    else if(distance1<distance2){
      analogWrite(motor2_enable,150);
      analogWrite(motor1_enable,125);
      Serial.println("taking slight left");
    }
    else{
      analogWrite(motor1_enable,125);
      analogWrite(motor2_enable,125);
      Serial.println("no error");
    }
  }
}
