int forward_1=10;
int reverse_1=9;
int forward_2=8;
int reverse_2=7;
int state=0;
int flag=0;
int trigpin=12;
int echopin=13;
float pingtime;
float targetdistance;
float speedofsound=776.5;
void setup(){
  pinMode(forward_1,OUTPUT);
  pinMode(reverse_1,OUTPUT);
  pinMode(forward_2,OUTPUT);
  pinMode(reverse_2,OUTPUT);
  Serial.begin(38400);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}
void loop(){
  if(Serial.available()>0){
    state=NULL;
    state=Serial.read();
    flag=0;
    if(state=='0' or state=='F'){
      digitalWrite(forward_1,HIGH);
      digitalWrite(reverse_1,LOW);
      digitalWrite(forward_2,HIGH);
      digitalWrite(reverse_2,LOW);
      if(flag==0){
        Serial.println("Forward");
        flag=1;
      }
    }
    else if(state=='1' or state=='R'){
      digitalWrite(forward_1,LOW);
      digitalWrite(reverse_1,HIGH);
      digitalWrite(forward_2,LOW);
      digitalWrite(reverse_2,HIGH);
      if(flag==0){
        Serial.println("Reverse");
        flag=1;
      }
     }
    else if(state=='2' or state=='L'){
      digitalWrite(forward_1,HIGH);
      digitalWrite(reverse_1,LOW);
      digitalWrite(forward_2,LOW);
      digitalWrite(reverse_2,HIGH);
      if(flag==0){
        Serial.println("LEFT");
        flag=1;
        }
      }
    else if(state=='3' or state=='R'){
      digitalWrite(forward_1,LOW);
      digitalWrite(reverse_1,HIGH);
      digitalWrite(forward_2,HIGH);
      digitalWrite(reverse_2,LOW);
      if(flag==0){
        Serial.println("RIGHT");
        flag=1;
        }
      }
    else if(state=='5' or state=='S'){
      digitalWrite(trigpin,LOW);
      delayMicroseconds(2000);
      digitalWrite(trigpin,HIGH);
      delayMicroseconds(15);
      digitalWrite(trigpin,LOW);
      pingtime=pulseIn(echopin,HIGH);
      pingtime=pingtime/1000000;
      pingtime=pingtime/3600;

      targetdistance=speedofsound*pingtime;
      targetdistance=targetdistance/2;
      targetdistance=targetdistance*63360;
      Serial.print("The distance of the target is :");
      Serial.print(targetdistance);
      if(targetdistance<=2.5 and targetdistance!=0){
        digitalWrite(forward_1,HIGH);
        digitalWrite(reverse_1,LOW);
        digitalWrite(forward_2,LOW);
        digitalWrite(reverse_2,HIGH);
        delay(1000);
        }
      digitalWrite(forward_1,HIGH);
      digitalWrite(reverse_1,LOW);
      digitalWrite(forward_2,HIGH);
      digitalWrite(reverse_2,LOW);

      delay(1000);
      if(flag==0){
        Serial.println("RIGHT TURN");
        flag=1;
        }
      }
     else if(state=='4'){
      digitalWrite(forward_1,LOW);
      digitalWrite(forward_2,LOW);
      digitalWrite(reverse_1,LOW);
      digitalWrite(rueverse_2,LOW);
      if(flag==0){
        Serial.println("STOP");
        flag=1;
        }
     }
  }

}
