#include <LiquidCrystal.h>
#include <Servo.h>
#define unpress_angle 90
#define press_angle 82
#define timer 3


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 
Servo myservo;  // create servo object to control a servo
bool trig=true;
int whiteInt;
int blackInt;
int threshold;

void setWhite() { 
  lcd.setCursor(0, 0);
  lcd.print("set white in:");
  delay(1000);
  lcd.setCursor(0,1);  
  for (int i=timer;i>=0;i--) {
    lcd.print(i);
    delay(1000);
  lcd.setCursor(0,1);
  }
  lcd.clear();
whiteInt = analogRead(A0);
 lcd.setCursor(0, 0);
 lcd.print("white number is:");
  lcd.setCursor(0,1);
 lcd.print(String(whiteInt));
 delay(3000);
 lcd.clear();
 lcd.setCursor(0,0);

}

void setBlack() { 
  lcd.setCursor(0, 0);
  lcd.print("set black in:");
  delay(1000);
  lcd.setCursor(0,1);  
  for (int i=timer;i>=0;i--) {
    lcd.print(i);
    delay(1000);
  lcd.setCursor(0,1);
  }
  lcd.clear();
 blackInt = analogRead(A0);
 lcd.setCursor(0, 0);
 lcd.print("black number is:");
  lcd.setCursor(0,1);
 lcd.print(String(blackInt));
 delay(3000);
 lcd.clear();
 lcd.setCursor(0,0);
}

void setup() {   
  Serial.begin(9600);   
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(unpress_angle);   
  analogWrite(6,120); // Generate PWM signal at pin D11, value of 100 (out of 255)
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
  setWhite();
  setBlack();
  threshold=blackInt+whiteInt;
  threshold/=2;
  lcd.print("play");
} 

void loop() {
 myservo.write(unpress_angle);              // unpress the button
 int value = analogRead(A0);
 Serial.print(String(value) + "\n");
 if(value < threshold)
 {
    myservo.write(press_angle);          // press the button
    delay(500);                       // waits 100ms for the servo to reach the position         
 }  

}