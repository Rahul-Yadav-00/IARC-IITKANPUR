#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
const int s0=3;
const int s1=4;
const int s2=5;
const int s3=6;
const int out=7;
const int vcc=8;
const int led=9;
int red,green,blue;
int x;

void setup() {
  // put your setup code here, to run once:
    pinMode(11,HIGH);
  pinMode(2,LOW);
  pinMode(13,LOW);
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  pinMode(vcc,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  digitalWrite(vcc,HIGH);
  digitalWrite(led,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.init();                      // initialize the lcd 
//  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HARSHIT");
}
