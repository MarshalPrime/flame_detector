#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#define FLAME 9 // define flame input
#define ALARM 8 // define alarm output

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("Fire Module Test");
  pinMode(FLAME, INPUT);//define FLAME input pin
  pinMode(ALARM, OUTPUT);//define ALARM output pin
}
void loop() {
 int fire = digitalRead(FLAME);// read FLAME sensor
 if( fire == HIGH) ///// if flame sensor detect fire
  {
    digitalWrite(ALARM,HIGH);// set the buzzer ON
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Fire! Fire! Evacuation");// Prints string "fire for evacuation" on the LCD
    lcd.setCursor(0,1);
    lcd.print(analogRead(A0)); // Prints the flame value from the sensor
    lcd.print(" cm");
    Serial.println("Fire! Fire! Evacuation");
    Serial.println(analogRead(A0));
  }else{//////else no flame detected no alarm
    digitalWrite(ALARM,LOW); // Set the buzzer OFF
    lcd.print("No Flame In the Zone");
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("No Flame In the Zone"); // Prints string "safe Zone" on the LCD
    lcd.setCursor(0,1);
    lcd.print(analogRead(A0)); // Prints the flame value from the sensor
    lcd.print(" cm");

  }

 delay(100);///// delay
}
