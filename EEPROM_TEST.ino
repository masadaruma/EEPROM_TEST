#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <AE_KEYPAD4X3.h>
#include <Servo.h>

AE_KEYPAD4X3 KEYPAD = AE_KEYPAD4X3(13, 12, 11, 3, 2, A3, A4); //キーパッド設定
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);						  //lcd設定
Servo servo;
unsigned char password[8] = {1, 2, 3, 4, 5, 6, 7, 8}; //パスワード一時保存用の配列

void setup()
{
	Serial.begin(9600);
	servo.attach(A2);
	KEYPAD.Init();
	lcd.begin(16, 2);
	lcd.clear();
	lcd.home();
	lcd.print("hello");
	password_EEPROM_read();
	if(EEPROM.read(10)){//ロックされてるなら
		servo.write(EEPROM.read(8));
	}else if(EEPROM.read(10)==false){//アンロックされてるなら
		servo.write(EEPROM.read(9));
	}
	/*初期化用
	for(int i=0;i<15;i++){
		EEPROM.write(i,0);
	}
	*/
}

void loop()
{
	main_menu();
}
