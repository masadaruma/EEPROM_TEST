int button_input()
{
	int x = analogRead(A0);
	if (x < 60)
	{ //Right 4
		Serial.println("Right ");
		while (analogRead(A0) < 800)
		{
		}
		return 4;
	}
	else if (x < 300)
	{ //Up 2
		Serial.println("Up    ");
		while (analogRead(A0) < 800)
		{
		}
		return 2;
	}
	else if (x < 500)
	{ //Down 3
		Serial.println("Down  ");
		while (analogRead(A0) < 800)
		{
		}
		return 3;
	}
	else if (x < 700)
	{ //Left 1
		Serial.println("Left  ");
		while (analogRead(A0) < 800)
		{
		}
		return 1;
	}
	else if (x < 900)
	{ //Select 0 cancel
		Serial.println("Select");
		while (analogRead(A0) < 900)
		{
		}
		return 0;
	}
	else
	{
		return 5;
	}
}

bool password_input()
{
pass_start:
	unsigned char input_pass[8], pass_check = 0;
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Password?");
	for (int i = 0; i < 8; i++)
	{
		switch (KEYPAD.getKeyChar()) //数字の入力
		{
		case '#': //文字消去
			while (1)
			{
				if (KEYPAD.getKeyChar() != '#')
					break;
			}
			for (int j = 0; j < 8; j++)
			{
				input_pass[j] = 0;
			}
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Password?");
			i = -1;
			break;
		case '9':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '9')
					break;
			}
			input_pass[i] = 9;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("9");
			break;
		case '8':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '8')
					break;
			}
			input_pass[i] = 8;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("8");
			break;
		case '7':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '7')
					break;
			}
			input_pass[i] = 7;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("7");
			break;
		case '6':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '6')
					break;
			}
			input_pass[i] = 6;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("6");
			break;
		case '5':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '5')
					break;
			}
			input_pass[i] = 5;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("5");
			break;
		case '4':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '4')
					break;
			}
			input_pass[i] = 4;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("4");
			break;

		case '3':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '3')
					break;
			}
			input_pass[i] = 3;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("3");
			break;

		case '2':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '2')
					break;
			}
			input_pass[i] = 2;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("2");
			break;

		case '1':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '1')
					break;
			}
			input_pass[i] = 1;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("1");
			break;

		case '0':
			while (1)
			{
				if (KEYPAD.getKeyChar() != '0')
					break;
			}
			Serial.println("0");
			input_pass[i] = 0;
			lcd.setCursor(i + 4, 1);
			lcd.print('*');
			Serial.println("1");
			break;
		default:
			i--;
			break;
		}
	}
	for (int k = 0; k < 8; k++)
	{
		if (input_pass[k] == password[k])
			pass_check++;
		Serial.print(input_pass[k]);
		Serial.print("==");
		Serial.println(password[k]);
	}
	Serial.println(pass_check);
	if (pass_check == 8)
	{ //パスワードが合っているなら
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Correct pass.");
		delay(1000);
		return 1;
	}
	else
	{
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Wrong pass.");
		delay(1000);
		goto pass_start;
	}
}

void password_EEPROM_write()
{
	for (int i = 0; i < 8; i++)
	{
		EEPROM.write(i, password[i]);
	}
}

void password_EEPROM_read()
{
	for (int i = 0; i < 8; i++)
	{
		password[i] = EEPROM.read(i);
	}
}

bool password_setting()
{
	if (password_input())
	{
	start:
		unsigned char input_pass[8], new_pass[8], pass_check = 0;
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("New Password?");
		for (int i = 0; i < 8; i++)
		{
			switch (KEYPAD.getKeyChar()) //数字の入力
			{
			case '#': //文字消去
				while (1)
				{
					if (KEYPAD.getKeyChar() != '#')
						break;
				}
				for (int j = 0; j < 8; j++)
				{
					input_pass[j] = 0;
				}
				lcd.clear();
				lcd.setCursor(0, 0);
				lcd.print("New Password?");
				i = -1;
				break;
			case '9':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '9')
						break;
				}
				input_pass[i] = 9;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("9");
				break;
			case '8':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '8')
						break;
				}
				input_pass[i] = 8;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("8");
				break;
			case '7':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '7')
						break;
				}
				input_pass[i] = 7;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("7");
				break;
			case '6':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '6')
						break;
				}
				input_pass[i] = 6;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("6");
				break;
			case '5':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '5')
						break;
				}
				input_pass[i] = 5;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("5");
				break;
			case '4':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '4')
						break;
				}
				input_pass[i] = 4;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("4");
				break;

			case '3':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '3')
						break;
				}
				input_pass[i] = 3;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("3");
				break;

			case '2':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '2')
						break;
				}
				input_pass[i] = 2;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("2");
				break;

			case '1':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '1')
						break;
				}
				input_pass[i] = 1;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("1");
				break;

			case '0':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '0')
						break;
				}
				Serial.println("0");
				input_pass[i] = 0;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("1");
				break;
			default:
				i--;
				break;
			}
		}
		for (int l = 0; l < 8; l++)
		{
			new_pass[l] = input_pass[l]; //パスワードを移す
		}
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("enter again");
		for (int i = 0; i < 8; i++)
		{
			switch (KEYPAD.getKeyChar()) //数字の入力
			{
			case '#': //文字消去
				while (1)
				{
					if (KEYPAD.getKeyChar() != '#')
						break;
				}
				for (int j = 0; j < 8; j++)
				{
					input_pass[j] = 0;
				}
				lcd.clear();
				lcd.setCursor(0, 0);
				lcd.print("enter again");
				i = -1;
				break;
			case '9':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '9')
						break;
				}
				input_pass[i] = 9;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("9");
				break;
			case '8':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '8')
						break;
				}
				input_pass[i] = 8;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("8");
				break;
			case '7':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '7')
						break;
				}
				input_pass[i] = 7;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("7");
				break;
			case '6':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '6')
						break;
				}
				input_pass[i] = 6;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("6");
				break;
			case '5':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '5')
						break;
				}
				input_pass[i] = 5;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("5");
				break;
			case '4':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '4')
						break;
				}
				input_pass[i] = 4;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("4");
				break;

			case '3':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '3')
						break;
				}
				input_pass[i] = 3;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("3");
				break;

			case '2':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '2')
						break;
				}
				input_pass[i] = 2;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("2");
				break;

			case '1':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '1')
						break;
				}
				input_pass[i] = 1;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("1");
				break;

			case '0':
				while (1)
				{
					if (KEYPAD.getKeyChar() != '0')
						break;
				}
				Serial.println("0");
				input_pass[i] = 0;
				lcd.setCursor(i + 4, 1);
				lcd.print('*');
				Serial.println("1");
				break;
			default:
				i--;
				break;
			}
		}
		for (int k = 0; k < 8; k++)
		{
			if (input_pass[k] == new_pass[k])
				pass_check++;
			Serial.print(input_pass[k]);
			Serial.print("==");
			Serial.println(new_pass[k]);
		}
		if (pass_check == 8)
		{
			for (int i = 0; i < 8; i++)
			{
				password[i] = new_pass[i];
			}
			password_EEPROM_write();
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("set new password");
			delay(1000);
			lcd.clear();
			return 0;
		}
		goto start;
	}
}

void degree_input()
{
	byte locking_deg = EEPROM.read(8);
	byte unlocking_deg = EEPROM.read(9);
	bool flag = false;
	password_input();
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(" Locking Degree?");
	lcd.setCursor(12, 1);
	lcd.print(locking_deg);
	servo.write(locking_deg);
	while (1)
	{
		if (flag)
			break;
		switch (button_input())
		{
		case 0: //select
			break;
		case 1: //left
			break;
		case 2: //up
			if (locking_deg <= 170)
			{
				locking_deg += 10;
			}
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print(" Locking Degree?");
			lcd.setCursor(12, 1);
			lcd.print(locking_deg);
			servo.write(locking_deg);
			break;
		case 3: //down
			if (locking_deg >= 10)
			{
				locking_deg -= 10;
			}
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print(" Locking Degree?");
			lcd.setCursor(12, 1);
			lcd.print(locking_deg);
			servo.write(locking_deg);
			break;
		case 4: //Right
			EEPROM.write(8, locking_deg);
			flag = true;
			break;
		}
	}
	flag = false;
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Unlocking Degree?");
	lcd.setCursor(12, 1);
	lcd.print(unlocking_deg);
	servo.write(unlocking_deg);
	while (1)
	{
		if (flag)
			break;
		switch (button_input())
		{
		case 0: //select
			break;
		case 1: //left
			break;
		case 2: //up
			if (unlocking_deg <= 170)
			{
				unlocking_deg += 10;
			}
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Unlocking Degree?");
			lcd.setCursor(12, 1);
			lcd.print(unlocking_deg);
			servo.write(unlocking_deg);
			break;
		case 3: //down
			if (unlocking_deg >= 10)
			{
				unlocking_deg -= 10;
			}
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Unlocking Degree?");
			lcd.setCursor(12, 1);
			lcd.print(unlocking_deg);
			servo.write(unlocking_deg);
			break;
		case 4: //Right
			EEPROM.write(9, unlocking_deg);
			flag = true;
			break;
		}
	}
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("close door");
	lcd.setCursor(0, 1);
	lcd.print("press any button");
	while (1)
	{
		if (button_input() < 5)
		{
			servo.write(locking_deg);
			break;
		}
	}
}

void lock_unlock()
{ //ロック用
    byte input;
	while (1)
	{
		if (EEPROM.read(10) == false)
		{ //開いているなら
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("   &UnLocked&");
			lcd.setCursor(0, 1);
			lcd.print("   Push button");
		}
		else if (EEPROM.read(10) == true)
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("    #Locked#");
			lcd.setCursor(0, 1);
			lcd.print("   Push button");
		}
		while (1)
		{
			input = button_input();
			if (input != 1 && input < 5)
			{
				if (EEPROM.read(10) == false)
				{								 //開いているなら
					servo.write(EEPROM.read(8)); //ロック
					EEPROM.write(10, true);
					break;
				}
				else if (EEPROM.read(10) == true)
				{ //しまっているなら
					password_input();
					servo.write(EEPROM.read(9)); //アンロック
					EEPROM.write(10, false);
					break;
				}
			}
			else if (input == 1)break;
		}
		if(input==1)break;
	}
}

void reset()
{ //リセット用
	bool reset_flag = false;
	password_input();
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("  RESET?");
	lcd.setCursor(0, 1);
	lcd.print("   Yes >No");
	while (1)
	{
		switch (button_input())
		{
		case 1: //left
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("  RESET?");
			lcd.setCursor(0, 1);
			lcd.print("  >Yes  No");
			reset_flag = true;
			break;
		case 4: //right
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("  RESET?");
			lcd.setCursor(0, 1);
			lcd.print("   Yes >No");
			reset_flag = false;
			break;
		case 0: //select
			if (reset_flag == true)
			{
				for (int i = 0; i < 10; i++)
				{
					EEPROM.write(i, 0);
				}
				lcd.clear();
				lcd.setCursor(4, 0);
				lcd.print("RESETTED");
				delay(1000);
				goto EXIT;
			}
			else if (reset_flag == false)
			{
				//ここで脱出
				goto EXIT;
			}
		default:
			break;
		}
	}
EXIT:;
}

void dsp(byte disp, byte pos)
{
	switch (disp)
	{
	case 1: //hello
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Hello");
		lcd.setCursor(0, 1);
		lcd.print("");
		break;
	case 2: //Lock or Setting
		switch (pos)
		{
		case 1:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("> Lock");
			lcd.setCursor(0, 1);
			lcd.print("  Setting");
			break;
		case 2:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("  Lock");
			lcd.setCursor(0, 1);
			lcd.print("> Setting");
			break;
		}
		break;
	case 3: //Setting(RESET,Password,Degree)
		switch (pos)
		{
		case 1:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("> RESET");
			lcd.setCursor(0, 1);
			lcd.print("  Password");
			break;
		case 2:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("  RESET");
			lcd.setCursor(0, 1);
			lcd.print("> Password");
			break;
		case 3:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("> Password");
			lcd.setCursor(0, 1);
			lcd.print("  Degree");
			break;
		case 4:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("  Password");
			lcd.setCursor(0, 1);
			lcd.print("> Degree");
			break;
		}
		break;
	case 4: //locked or unlocked
		break;
	case 5: //RESET
		reset();
		break;
	case 6: //password setting
		password_setting();
		break;
	case 7: //Degree
		degree_input();
		break;
	}
}

void menu_manage()
{
	byte menu_limit[8] = {1, 2, 4};
}
