const int trigpin_front=4;
const int echopin_front=5;
const int trigpin_side_front=6;
const int echopin_side_front=7;
int motor_enable_left=2;
int motor_enable_right=3;
const int trigpin_side_back=8;
const int echopin_side_back=9;
//unsigned int t1=0;// intial time 
//unsigned int t2=0;// second var for time 
//int test; // to be calculated
int ir_sensor7;//front sensor
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigpin_front,OUTPUT);
  pinMode(echopin_front,OUTPUT);
  //pinMode(3,HIGH);
  pinMode(trigpin_side_front,OUTPUT);
  pinMode(echopin_side_front,INPUT);
  pinMode(trigpin_side_back,OUTPUT);
  pinMode(echopin_side_back,INPUT);
  pinMode(motor_enable_left,OUTPUT);
  pinMode(motor_enable_right,OUTPUT);
}
int side_front_uv(){
  digitalWrite(trigpin_side_front,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin_side_front,HIGH);
  delayMicroseconds(8);

  float duration1,distance1;
  duration1=pulseIn(echopin_side_front,HIGH);
  distance1=(duration1*0.0343)/2;
  Serial.print("distance1: ");
  Serial.println(distance1);
  delay(1000);
  return distance1;
}
int side_second_uv(){
  digitalWrite(trigpin_side_back,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin_side_back,HIGH);
  delayMicroseconds(8);

  float duration2,distance2;
  duration2=pulseIn(echopin_side_back,HIGH);
  distance2=(duration2*0.0343)/2;
  Serial.print("distance2: ");
  Serial.println(distance2);
  delay(1000);
  return distance2;
}
int front_uv(){
  digitalWrite(trigpin_front,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin_front,HIGH);
  delayMicroseconds(8);

  float duration0,distance0;
  duration0=pulseIn(echopin_front,HIGH);
  distance0=(duration0*0.0343)/2;
  Serial.print("distance0: ");
  Serial.println(distance0);
  delay(1000);
  return distance0;
}

void loop() {
  // put your main code here, to run repeatedly:
  float distance1,distance2,distance0;
 distance0=front_uv();
  distance1=side_front_uv();
  distance2=side_second_uv();
 if(distance0>10)
 {
  if(6<=distance1<=10 && 6<=distance2<=10) //test to be calculated
  { 
    Serial.print("distance 1 ==:");
    Serial.print(distance1);
    Serial.print("      ");
    Serial.print("distance2=");
    Serial.println(distance2);
    if(distance1>distance2)
    {
      analogWrite(motor_enable_left,150);
      analogWrite(motor_enable_right,125);
      Serial.println("taking slight right");
      }
    else if(distance1<distance2){
      analogWrite(motor_enable_left,125);
      analogWrite(motor_enable_right,150);
      Serial.println("taking slight left");
    }
    else{
      analogWrite(motor_enable_left,125);
      analogWrite(motor_enable_right,125);
      Serial.println("no error");
    }
  } 
}
}
