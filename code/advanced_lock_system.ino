#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <ESP32Servo.h>

Servo myservo;

#define IR_Sensor 23

char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[4] = {13, 12, 14, 27};   
byte pin_column[4] = {26, 25, 33, 32}; 

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, 4, 4 );

int IR;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int cursorColumn = 0;


SoftwareSerial mySerial(16, 17); 

bool state1;

int otp;
String otpstring="";

int q;

void setup()
{
  myservo.attach(15);
  myservo.write(10);
  lcd.init();
  lcd.backlight();
  lcd.print("Hello");
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(4, INPUT);
  pinMode(19, INPUT);
  digitalWrite(19, PULLDOWN);
  pinMode(IR_Sensor, INPUT); 
  
  Serial.begin(9600);
  
  
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); 

  
  mySerial.println("AT+CMGF=1"); 

  mySerial.println("AT+CNMI=1,2,0,0,0"); 

}

void loop()
{
  if (mySerial.available()) {
    String message = readMessage(); 
    Serial.println("Received Message: " + message);
    if(message.indexOf("INR 1.0") != -1){
      digitalWrite(2, HIGH); 
      delay(100);
      digitalWrite(2, LOW);
      q=10;
      otp=random(1000,9999);
      otpstring = String(otp);
      sendSMS();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" OTP Sent to");
      lcd.setCursor(0, 1);
      lcd.print(" Your Mobile"); 
      delay(2000);
      lcd.clear();
      getotp();
      lcd.print("Hello");
      
    }


    if(message.indexOf("INR 2.0") != -1){
      digitalWrite(2, HIGH); 
      delay(100);
      digitalWrite(2, LOW);
      q=20;
      otp=random(1000,9999);
      otpstring = String(otp);
      sendSMS();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" OTP Sent to");
      lcd.setCursor(0, 1);
      lcd.print(" Your Mobile"); 
      delay(2000);
      lcd.clear();
      getotp();
      lcd.print("hello");
      
    }


    if(message.indexOf("INR 3.0") != -1){
      digitalWrite(2, HIGH); 
      delay(100);
      digitalWrite(2, LOW);
      q=30;
      otp=random(1000,9999);
      otpstring = String(otp);
      sendSMS();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" OTP Sent to");
      lcd.setCursor(0, 1);
      lcd.print(" Your Mobile"); 
      delay(2000);
      lcd.clear();
      getotp();
      lcd.print("hello");
      
    }
  }
}


void getotp(){
  
  
  int z=1;
  while(z<4){
    lcd.setCursor(0, 0);
    lcd.print("Enter the OTP");
    String y = "";
    int a = y.length();
    while (a < 4) {
    char customKey = keypad.getKey();
    if (customKey) {
      lcd.setCursor(0, 1);
      y = y + customKey;
      lcd.print(y);
      a = y.length();
    }
    }
    if (y == otpstring) 
    {
        
        
        lcd.clear();
        lcd.setCursor(0, 1);
        
        lcd.print("Correct OTP");
        z=5;
        myservo.write(110);
        delay(1500);
        lcd.clear();
        
        int i;
        i=0;
        while(i<=10*q){
          
          lcd.setCursor(0, 0);
          lcd.print("Locks In");
          
          lcd.setCursor(0, 1);
          int x=q-(i/10);
          lcd.print(x);
          lcd.print(" seconds");
          delay(75);
          lcd.setCursor(0, 1);
          lcd.print("");
          
        
          int state;
          state=digitalRead(4);
          if(state==HIGH)
          {
            int x=1;
            myservo.write(0);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Locked");
            myservo.write(10);
            delay(1000);
            i=1000;
          }

          state1=digitalRead(19);
          if(state1==HIGH)
          {
            myservo.write(0);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Paused");
            myservo.write(10);
            delay(3000);
            lcd.clear();
            lcd.print("Enter OTP ");
            delay(1000);
            int c;
            for(c=1;c<=1000;c++){
            int j=1;
            while(j<4){
              String y = "";
              int a = y.length();
              while (a < 4) {
              char customKey = keypad.getKey();
              if (customKey) {
              lcd.setCursor(0, 1);
              y = y + customKey;
              lcd.print(y);
              a = y.length();
              int b=1;
              if(b==1){
              if (y == otpstring) 
             {
              myservo.write(110);
              c=1010;
              y="";
              b==0;
             }
              }
              lcd.setCursor(0,1);
              lcd.print("");
              }
              }

             
             j=j+1;
            }

              
              delay(50);
            }
          }



          i=i+1;
        }


        IR=digitalRead(IR_Sensor);
        if(IR==LOW)
        {
          int time=0;
          int charge=0;
          int d=0;
          int e=0;
          lcd.clear();
          for(int s=1;s<1000;s++){
          lcd.setCursor(12,0);
          lcd.print(charge);
          lcd.setCursor(0,0);
          lcd.print("Charges = Rs");
          if(d%100==0){
            charge=charge+1;
          }
          lcd.setCursor(3,1);
          lcd.print("seconds");
          lcd.setCursor(0,1);
          lcd.print(time);
          if(e%10==0){
           time=time+1;
          }
          delay(100);
          d=d+1;
          e=e+1;
          int state;
          state=digitalRead(4);
          if(state==HIGH)
          {
            myservo.write(0);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Locked");
            myservo.write(10);
            delay(1000);hjng
            s=1001;
          }
         }
        }
          myservo.write(10);
          delay(1000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Thank You");
          delay(3000);
          lcd.clear();
        
      } 
      else {
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Incorrect");
        lcd.setCursor(0, 1);
        lcd.print("OTP");
        delay(2000);
        lcd.clear();
        
        z++;
        
      }
   }
   
}



String readMessage() {
  String message = "" ;
  while (mySerial.available()) {
    char c = mySerial.read();
    message += c;
    delay(10);
  }
  return message;
}



void sendSMS() {
  mySerial.println("AT+CMGF=1"); 
  delay(1000);
  mySerial.println("AT+CMGS=\"+918999782908\"");
  delay(1000);
  mySerial.println(otp);
  delay(1000);
  mySerial.println((char)26); 
  delay(1000);
}
