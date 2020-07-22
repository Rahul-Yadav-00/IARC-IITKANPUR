int LM_F=8;
int LM_R=9;
int EN_L=6;
int EN_R=5;
int RM_F=3;
int RM_R=4;
void setup() {
  // put your setup code here, to run once:
  pinMode(LM_F,OUTPUT);
  pinMode(LM_R,OUTPUT);
  pinMode(EN_L,OUTPUT);
  pinMode(EN_R,OUTPUT);
  pinMode(RM_F,OUTPUT);
  pinMode(RM_R,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(EN_L,200);
  analogWrite(EN_R,50);
  digitalWrite(LM_F,HIGH);
  digitalWrite(LM_R,LOW);
  digitalWrite(RM_F,HIGH);
  digitalWrite(RM_R,LOW);
}
