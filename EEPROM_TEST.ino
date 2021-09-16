#include<EEPROM.h>
#include<LiquidCrystal.h>
#include<AE_KEYPAD4X3.h>

AE_KEYPAD4X3 KEYPAD = AE_KEYPAD4X3(13,12,11,3,2,A3,A4);
LiquidCrystal lcd( 8, 9, 4, 5, 6, 7);
unsigned char password[8]={1,2,3,4,5,6,7,8};

void setup(){
    Serial.begin(9600);
    KEYPAD.Init();
    lcd.begin(16,2);
    lcd.clear();lcd.home();lcd.print("hello");
    password_EEPROM_read();
    /*EEPROM.write(0,1);
    EEPROM.write(1,2);
    EEPROM.write(2,3);
    EEPROM.write(3,4);
    EEPROM.write(4,5);
    EEPROM.write(5,6);
    EEPROM.write(6,7);
    EEPROM.write(7,8);*/
}

void loop(){
    password_input();
    password_setting();  
}