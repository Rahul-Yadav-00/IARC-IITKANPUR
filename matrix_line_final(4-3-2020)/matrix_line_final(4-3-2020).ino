//working with pwm
//remove enble to run on different motor driver
// speed=100 and delay=315 is working fine 
int IR_1=A5;
int IR_2=A4;
int IR_3=A3;
int IR_4=A2;
int IR_5=A1;
int IR_6=A0;
int IR_7=13;
int IR_8=12;
int IR_9=11;
int EN_R=5;
int EN_L=6;

int extra_high1 = 12;
int extra_high2 = 10;
//int extra_low = 13;
int count=0;
int LM_F=8;
int LM_R=9;
int RM_F=3;
int RM_R=4;
//
//int GIR_8=42;
//int GIR_9=44;
//int PIR_8=48;
//int PIR_9=50; 
int arr[4];
      void setup() 
        {
                pinMode(extra_high1,OUTPUT);
                pinMode(extra_high2,OUTPUT);
//                pinMode(extra_low,OUTPUT);
                digitalWrite(extra_high1,HIGH);
                digitalWrite(extra_high2,HIGH);
//                digitalWrite(extra_low,LOW);
                pinMode(IR_1,INPUT);
                pinMode(IR_2,INPUT);
                pinMode(IR_3,INPUT);
                pinMode(IR_4,INPUT);
                pinMode(IR_5,INPUT);
                pinMode(IR_6,INPUT);
                pinMode(IR_7,INPUT);
                pinMode(LM_F,OUTPUT);
                pinMode(LM_R,OUTPUT);
                pinMode(RM_F,OUTPUT);
                pinMode(RM_R,OUTPUT);
                    pinMode(IR_8,INPUT);
                  pinMode(IR_9,INPUT);
//                   pinMode(GIR_8,OUTPUT);
//                    pinMode(GIR_9,OUTPUT);
//                     pinMode(PIR_8,OUTPUT);
//                      pinMode(PIR_9,OUTPUT);
                pinMode(EN_R,OUTPUT);
                pinMode(EN_L,OUTPUT);
                Serial.begin(9600);
          
        } 
      void stope()
        {
              digitalWrite(LM_F,LOW);
              digitalWrite(LM_R,LOW);
              digitalWrite(RM_F,LOW);
              digitalWrite(RM_R,LOW);
              Serial.println("stop"); 
        }
      void forward()
        {
              digitalWrite(LM_F,HIGH);
              digitalWrite(RM_F,HIGH);
              digitalWrite(LM_R,LOW);
              digitalWrite(RM_R,LOW);
              Serial.println("forward");
        }
      void left()
        {
//          analogWrite(EN_R,50);
//        analogWrite(EN_L,7.50);
              digitalWrite(LM_F,LOW);
              digitalWrite(LM_R,HIGH);
              digitalWrite(RM_F,HIGH);
              digitalWrite(RM_R,LOW);
              Serial.println("left");
         }
            void leftturn()
        {
//          analogWrite(EN_R,50);
//        analogWrite(EN_L,50);
              digitalWrite(LM_F,LOW);
              digitalWrite(LM_R,HIGH);
              digitalWrite(RM_F,HIGH);
              digitalWrite(RM_R,LOW);
              Serial.println("left");
         }
      void right()
        {
//          analogWrite(EN_R,50);
//        analogWrite(EN_L,50);
              digitalWrite(LM_F,HIGH);
              digitalWrite(LM_R,LOW);
              digitalWrite(RM_F,LOW);
              digitalWrite(RM_R,HIGH);
              Serial.println("right");
        }
         void rightturn()
        {
//          analogWrite(EN_R,50);
//        analogWrite(EN_L,50);
              digitalWrite(LM_F,HIGH);
              digitalWrite(LM_R,LOW);
              digitalWrite(RM_F,LOW);
              digitalWrite(RM_R,HIGH);
              Serial.println("right");
        }
     void backward()
        {
              digitalWrite(LM_F,LOW);
              digitalWrite(RM_F,LOW);
              digitalWrite(LM_R,HIGH);
              digitalWrite(RM_R,HIGH);
              Serial.println("forward");
        }
        void matrix(){
          
          stope();
          delay(2000);
////      if((digitalRead(IR_2) == digitalRead(IR_3)) && (digitalRead(IR_4) == digitalRead(IR_5)) ){
           Serial.print(digitalRead(IR_3));
      Serial.print(digitalRead(IR_4));
      arr[0] = digitalRead(IR_3);
      arr[1] = digitalRead(IR_4);
//       Serial.println();
////       stope();
       delay(100);
      Serial.print(digitalRead(IR_8));
      Serial.print(digitalRead(IR_9));
//      arr[2] = digitalRead(IR_8);
//      arr[3] = digitalRead(IR_9);
//       Serial.println();
////      } else{
////        Serial.println("NO same1");
////      }
      stope();
      delay(1000);
////      forward();
////      delay(50);
////      stope();
////      delay(1000);
////      if((digitalRead(IR_2) == digitalRead(IR_3)) && (digitalRead(IR_4) == digitalRead(IR_5)) ){
//
////      }
////      else{
////        Serial.println("NO same2");
////      }
//
//       
//             for(int i=0;i<4;i++){
//        Serial.print(arr[i]);
//      }
//      Serial.println("");
//           stope();
//
//      delay(10000);
////      stope();
} 



void line_follower()
      {
        Serial.print(digitalRead(IR_1));
        Serial.print(" ");
        Serial.print(digitalRead(IR_2));
        Serial.print(" ");
        Serial.print(digitalRead(IR_3));
        Serial.print(" ");
        Serial.print(digitalRead(IR_4));
        Serial.print(" ");
        Serial.print(digitalRead(IR_5));
        Serial.print(" ");
        Serial.print(digitalRead(IR_6));
        Serial.print(" ");
        Serial.print(digitalRead(IR_7));
        Serial.print(" ");
        Serial.println(" ");
//     FORWARD ONLY
          if((digitalRead(IR_1)==0)&&(digitalRead(IR_2)==0)&&(digitalRead(IR_3)==1)&&(digitalRead(IR_4)==1)&&(digitalRead(IR_5)==0)&&(digitalRead(IR_6)==0))
                {
                  forward();
                  Serial.println("Forward");

                }
//        
//                  //RIGHT ONLY     
////                  delay(25);
                else if((digitalRead(IR_1)==0)&&(digitalRead(IR_2)==0)&&(digitalRead(IR_4)==1)&&(digitalRead(IR_5)==1)&&(digitalRead(IR_6)==1)&&(digitalRead(IR_7)==0))
                      { 
                        delay(200);
//                        stope();
//                        delay(500);
                        while((digitalRead(IR_3)==0)||(digitalRead(IR_4)==0))
//                        while(digitalRead(IR_7)==0)
                          {
                            rightturn();
                          }
                          
//                          stope();
//                          delay(500);
//                          forward();
//                          delay(100);
                        Serial.println("RIGHT");    
                      }
//              //LEFT ONLY
                  else if((digitalRead(IR_1)==1)&&(digitalRead(IR_2)==1)&&(digitalRead(IR_3)==1)&&(digitalRead(IR_5)==0)&&(digitalRead(IR_6)==0)&&(digitalRead(IR_7)==0))
                      { 
                        delay(180);
//                        stope();
//                        delay(500);
                        while((digitalRead(IR_3)==0)||(digitalRead(IR_4)==0))
//                        while(digitalRead(IR_7)==0)
                          {
                            leftturn();
                          }

                        Serial.println("LEFT");    
                      }
////              //LEFT AND FORWARD
//                  else if((digitalRead(IR_1)==1)&&(digitalRead(IR_2)==1)&&(digitalRead(IR_3)==1)&&(digitalRead(IR_5)==0)&&(digitalRead(IR_6)==0)&&(digitalRead(IR_7)==1))
//                      {
//                        delay(280);
//                        stope();
//                        delay(500);
//                        left();
//                        delay(80);
//                        while(digitalRead(IR_7)==0)
//                          {
//                            Serial.println("LEFT AND FORWARD");  
//                            leftturn();
//                          }
//                 
//                      }
//              //RIGHT AND FORWARD
//                    else if((digitalRead(IR_1)==0)&&(digitalRead(IR_2)==0)&&(digitalRead(IR_4)==1)&&(digitalRead(IR_5)==1)&&(digitalRead(IR_6)==1)&&(digitalRead(IR_7)==1))
//                        {
//                          forward();
//                          Serial.println("RIGHT and FORWARD");    
//                        }
//              //RIGHT AND LEFT
//                    else if((digitalRead(IR_1)==1)&&(digitalRead(IR_2)==1)&&(digitalRead(IR_3)==1)&&(digitalRead(IR_4)==1)&&(digitalRead(IR_5)==1)&&(digitalRead(IR_6)==1)&&(digitalRead(IR_7)==0))
//                        {
//                          delay(280);
//                          stope();
//                          delay(500);
//                          while(digitalRead(IR_7)==0)
//                            {
//                              Serial.println("LEFT AND RIGHT");  
//                              leftturn();
//                            }
//                 
//                        }
              //PLUS SIGN
                    else if((digitalRead(IR_1)==1)&&(digitalRead(IR_2)==1)&&(digitalRead(IR_3)==1)&&(digitalRead(IR_4)==1)&&(digitalRead(IR_5)==1)&&(digitalRead(IR_6)==1)&&(digitalRead(IR_7)==1))
                        {
                          
                           delay(150);
//                           stope();
//                           delay(1000);
                           leftturn();
                           delay(150);
//                           stope();
//                           delay(1000);
                           while(digitalRead(IR_7)==0)
                            {
                              Serial.println("PLUS");  
                              leftturn();
                            }
                 
                        }
              //PATH END
                  else if((digitalRead(IR_1)==0)&&(digitalRead(IR_2)==0)&&(digitalRead(IR_3)==0)&&(digitalRead(IR_4)==0)&&(digitalRead(IR_5)==0)&&(digitalRead(IR_6)==0)&&(digitalRead(IR_7)==0))
                    {  
                      delay(150);
                      while(digitalRead(IR_7)==0)
                        {
                          left();
                        }
                      Serial.println("dead end");
                    }
////                matrix
//forward path calibration
             else if((digitalRead(IR_1)==0)&&(digitalRead(IR_2)==1)&&(digitalRead(IR_3)==1)&&(digitalRead(IR_5)==0)&&(digitalRead(IR_6)==0))
                {
                  
                  Serial.println("caliberation left");
//                  while((digitalRead(IR_3)==0))
                  while(digitalRead(IR_2)==1)
                  left();
                }

             else if((digitalRead(IR_1)==0)&&(digitalRead(IR_2)==0)&&(digitalRead(IR_4)==1)&&(digitalRead(IR_5)==1)&&(digitalRead(IR_6)==0))
                {
                   
                  Serial.println("caliberation right");
//                  if((digitalRead(IR_7)==1)&&(digitalRead(IR_9)==1))
//                  {
                  while((digitalRead(IR_5)==1))
                  right();
                }
            else if((digitalRead(IR_1)==0)&&(digitalRead(IR_6)==0)&&(digitalRead(IR_2)==digitalRead(IR_3))&&(digitalRead(IR_4)==digitalRead(IR_5))&&(digitalRead(IR_7)==1)){
                  matrix();
                }         
}
      


//      }
void loop() {
      if(count==0)
        {
          delay(2000);
          count=count+1;
        }
//          digitalWrite(PIR_8,HIGH);
//        digitalWrite(PIR_9,HIGH);
//        digitalWrite(GIR_8,LOW);
//        digitalWrite(GIR_9,LOW);
        analogWrite(EN_R,120);
        analogWrite(EN_L,120);
//         Serial.print(digitalRead(IR_3));
//      Serial.print(digitalRead(IR_4));
////      Serial.println("");
//      Serial.print(digitalRead(IR_8));
//      Serial.print(digitalRead(IR_9));
//      Serial.println("");
      line_follower();
//        test_forword();


    }
