#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
char matrix_display[10];
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.readBytes(matrix_display,5);
    lcd.init(); 
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print(matrix_display);
//    lcd.print("MATRIX:-");
//    lcd.setCursor(0,1);
//    for(int i=0;i<4;i++){
//      lcd.setCursor(i+4,1);
//      lcd.print(matrix_display[i]);
//    }]
delay(1000);
    
}
