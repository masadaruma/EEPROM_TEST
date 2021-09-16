int button_input(){
int x=analogRead(A0);
 if (x < 60) {//Right 4
   Serial.println ("Right ");
   while(analogRead(A0)>800){}
   return 4;
 }
 else if (x < 300) {//Up 2
   Serial.println ("Up    ");
   while(analogRead(A0)>800){}
   return 2;
 }
 else if (x < 500){//Down 3
   Serial.println ("Down  ");
   while(analogRead(A0)>800){}
   return 3;
 }
 else if (x < 700){//Left 1
   Serial.println ("Left  ");
   while(analogRead(A0)>800){}
   return 1;
 }
 else if (x < 900){//Select 0 cancel
   Serial.println ("Select");
   while(analogRead(A0)>800){}
   return 0;
 }else{
     return 5;
 }
 }

bool password_input(){
   pass_start:
     unsigned char input_pass[8],pass_check=0;
     lcd.clear();lcd.setCursor(0,0);lcd.print("Password?");
     for(int i=0;i<8;i++){
        switch (KEYPAD.getKeyChar())//数字の入力
             {
             case '#'://文字消去
             while(1){
                  if(KEYPAD.getKeyChar()!='#')break;
                }
                for(int j=0;j<8;j++){
                  input_pass[j]=0;
                }
                lcd.clear();lcd.setCursor(0,0);lcd.print("Password?");
                i=-1;
                break;
             case '9':
                while(1){
                  if(KEYPAD.getKeyChar()!='9')break;
                }
                input_pass[i]=9;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("9");
                 break;
             case '8':
             while(1){
                  if(KEYPAD.getKeyChar()!='8')break;
                }
                input_pass[i]=8;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("8");
                 break;
             case '7':
             while(1){
                  if(KEYPAD.getKeyChar()!='7')break;
                }
                input_pass[i]=7;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("7");
                 break;
             case '6':
             while(1){
                  if(KEYPAD.getKeyChar()!='6')break;
                }
                input_pass[i]=6;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("6");
                 break;
             case '5':
             while(1){
                  if(KEYPAD.getKeyChar()!='5')break;
                }
                input_pass[i]=5;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("5");
                 break;
             case '4':
             while(1){
                  if(KEYPAD.getKeyChar()!='4')break;
                }
                input_pass[i]=4;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("4");
                 break;
             
             case '3':
             while(1){
                  if(KEYPAD.getKeyChar()!='3')break;
                }
                input_pass[i]=3;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("3");
                 break;

             case '2':
             while(1){
                  if(KEYPAD.getKeyChar()!='2')break;
                }
                input_pass[i]=2;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("2");
                 break;

             case '1':
             while(1){
                  if(KEYPAD.getKeyChar()!='1')break;
                }
                input_pass[i]=1;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("1");
                 break;
                 
             case '0':
             while(1){
                  if(KEYPAD.getKeyChar()!='0')break;
                }
             Serial.println("0");
                input_pass[i]=0;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("1");
                 break;
            default:
                i--;
                break;
             }
     }
     for(int k=0;k<8;k++){
        if(input_pass[k]==password[k])pass_check++;
        Serial.print(input_pass[k]);Serial.print("==");Serial.println(password[k]);
     }
     Serial.println(pass_check);
     if(pass_check==8){//パスワードが合っているなら
       lcd.clear();lcd.setCursor(0,0);lcd.print("Correct pass.");
       delay(1000);
       return 1;
     }else{
       lcd.clear();lcd.setCursor(0,0);lcd.print("Wrong pass.");
       delay(1000);
       goto pass_start;
     }
 }

 void password_EEPROM_write(){
   for(int i=0;i<8;i++){
     EEPROM.write(i,password[i]);
   }
 }

 void password_EEPROM_read(){
   for(int i=0;i<8;i++){
     password[i]=EEPROM.read(i);
   }
 }

bool password_setting(){
    if(password_input()){
      start:
     unsigned char input_pass[8],new_pass[8],pass_check=0;
     lcd.clear();lcd.setCursor(0,0);lcd.print("New Password?");
     for(int i=0;i<8;i++){
        switch (KEYPAD.getKeyChar())//数字の入力
             {
             case '#'://文字消去
             while(1){
                  if(KEYPAD.getKeyChar()!='#')break;
                }
                for(int j=0;j<8;j++){
                  input_pass[j]=0;
                }
                lcd.clear();lcd.setCursor(0,0);lcd.print("New Password?");
                i=-1;
                break;
             case '9':
                while(1){
                  if(KEYPAD.getKeyChar()!='9')break;
                }
                input_pass[i]=9;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("9");
                 break;
             case '8':
             while(1){
                  if(KEYPAD.getKeyChar()!='8')break;
                }
                input_pass[i]=8;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("8");
                 break;
             case '7':
             while(1){
                  if(KEYPAD.getKeyChar()!='7')break;
                }
                input_pass[i]=7;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("7");
                 break;
             case '6':
             while(1){
                  if(KEYPAD.getKeyChar()!='6')break;
                }
                input_pass[i]=6;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("6");
                 break;
             case '5':
             while(1){
                  if(KEYPAD.getKeyChar()!='5')break;
                }
                input_pass[i]=5;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("5");
                 break;
             case '4':
             while(1){
                  if(KEYPAD.getKeyChar()!='4')break;
                }
                input_pass[i]=4;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("4");
                 break;
             
             case '3':
             while(1){
                  if(KEYPAD.getKeyChar()!='3')break;
                }
                input_pass[i]=3;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("3");
                 break;

             case '2':
             while(1){
                  if(KEYPAD.getKeyChar()!='2')break;
                }
                input_pass[i]=2;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("2");
                 break;

             case '1':
             while(1){
                  if(KEYPAD.getKeyChar()!='1')break;
                }
                input_pass[i]=1;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("1");
                 break;
                 
             case '0':
             while(1){
                  if(KEYPAD.getKeyChar()!='0')break;
                }
             Serial.println("0");
                input_pass[i]=0;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("1");
                 break;
            default:
                i--;
                break;
             }
     }
     for(int l=0;l<8;l++){
       new_pass[l]=input_pass[l];//パスワードを移す
     }
     lcd.clear();lcd.setCursor(0,0);lcd.print("enter again");
     for(int i=0;i<8;i++){
        switch (KEYPAD.getKeyChar())//数字の入力
             {
             case '#'://文字消去
             while(1){
                  if(KEYPAD.getKeyChar()!='#')break;
                }
                for(int j=0;j<8;j++){
                  input_pass[j]=0;
                }
                lcd.clear();lcd.setCursor(0,0);lcd.print("enter again");
                i=-1;
                break;
             case '9':
                while(1){
                  if(KEYPAD.getKeyChar()!='9')break;
                }
                input_pass[i]=9;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("9");
                 break;
             case '8':
             while(1){
                  if(KEYPAD.getKeyChar()!='8')break;
                }
                input_pass[i]=8;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("8");
                 break;
             case '7':
             while(1){
                  if(KEYPAD.getKeyChar()!='7')break;
                }
                input_pass[i]=7;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("7");
                 break;
             case '6':
             while(1){
                  if(KEYPAD.getKeyChar()!='6')break;
                }
                input_pass[i]=6;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("6");
                 break;
             case '5':
             while(1){
                  if(KEYPAD.getKeyChar()!='5')break;
                }
                input_pass[i]=5;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("5");
                 break;
             case '4':
             while(1){
                  if(KEYPAD.getKeyChar()!='4')break;
                }
                input_pass[i]=4;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("4");
                 break;
             
             case '3':
             while(1){
                  if(KEYPAD.getKeyChar()!='3')break;
                }
                input_pass[i]=3;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("3");
                 break;

             case '2':
             while(1){
                  if(KEYPAD.getKeyChar()!='2')break;
                }
                input_pass[i]=2;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("2");
                 break;

             case '1':
             while(1){
                  if(KEYPAD.getKeyChar()!='1')break;
                }
                input_pass[i]=1;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("1");
                 break;
                 
             case '0':
             while(1){
                  if(KEYPAD.getKeyChar()!='0')break;
                }
             Serial.println("0");
                input_pass[i]=0;
                lcd.setCursor(i+4,1);lcd.print('*');
                Serial.println("1");
                 break;
            default:
                i--;
                break;
             }
     }
     for(int k=0;k<8;k++){
        if(input_pass[k]==new_pass[k])pass_check++;
        Serial.print(input_pass[k]);Serial.print("==");Serial.println(new_pass[k]);
     }
     if(pass_check==8){
       for(int i=0;i<8;i++){
         password[i]=new_pass[i];
       }
       password_EEPROM_write();
       lcd.clear();lcd.setCursor(0,0);lcd.print("set new password");
        delay(1000);
        lcd.clear();
        return 0;
     }
     goto start;
     }
    }

