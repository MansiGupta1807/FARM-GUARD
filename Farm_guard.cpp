// C++ code
#include <LiquidCrystal.h>
#include <Wire.h>


LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

//for soil moisture sensor
int moisture;
int moisture2;
int motor = 8;
const int btnPin1 = 6;
const int btnPin2 = 7;
bool val1;
bool val2;

//for buzzer and sensor

int buzzer = 9;
int echoPin = 10;
int trigPin = 11;
float cm;
float inch;
int distance;
int duration;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(115200);
   //printing message on lcd
  // lcd.scrollDisplayLeft();
  lcd.setCursor(0, 0);
  lcd.print("Welcome In ");
  lcd.setCursor(0, 1);
  lcd.print("Automation World");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smart Farm Guard");
  lcd.setCursor(0, 1);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Project by: ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gajendra");
  lcd.setCursor(0, 1);
  lcd.print("1910DMBCSE05987");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Abhishek");
  lcd.setCursor(0, 1);
  lcd.print("1910DMBCSE05974");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mansi");
  lcd.setCursor(0, 1);
  lcd.print("1910DMBCSE05989");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sanskriti");
  lcd.setCursor(0, 1);
  lcd.print("1910DMBCSE06000");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Start Detecting");
  delay(1000);
  lcd.clear();
  Wire.setClock(10000);
 
  //for soil moisture sensor 
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(115200);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);  
  pinMode(motor, OUTPUT);
 
  //for soil moisture sensor
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //For seasson Selection
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void loop()
{
  
  //value reading for season selection
  val1 = digitalRead(btnPin1);
  val2 = digitalRead(btnPin2);
  
  // Apply power to the soil moisture sensor
  moisture = analogRead(A1);
  moisture2 = analogRead(A3); 
  
 
  
  delay(10); // Wait for 10 millisecond(s)
  
 
  //both value are true conflict condition
  if (val1 == HIGH && val2 == HIGH )
  {
    Serial.println( val1);
    Serial.println( val2);
    analogWrite(A5, 0);
    analogWrite(A4, 0);
    analogWrite(A0, 0);
    analogWrite(A2, 0);
    digitalWrite(motor, LOW);
    
  lcd.setCursor(0,0);
  lcd.print(" Please OFF one  ");
  lcd.setCursor(0,1);
  lcd.print(" Button  ");
  delay(1000);
    lcd.clear();
  }
  
  // First button value HIGH
  if (val1 == HIGH && val2 == LOW ) 
    {
     
     analogWrite(A4, 255);
     Serial.print( "moisture ");
     Serial.println( moisture);
     Serial.print("moisture2 ");
     Serial.println( moisture2);
    
    // Lcd print season and moisture
  lcd.setCursor(0,0);
  lcd.print("  Summer Season ");
  lcd.setCursor(0,1);
  lcd.print("  Auto mode ON");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Moisture Level:- ");
    delay(1000);
     lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FirstSensor: ");
  lcd.println(moisture);
  lcd.setCursor(0,1);
  lcd.print("SecondSensor:");
  lcd.println(moisture2);
    delay(1000);
     lcd.clear();
     
    // First sensor  
     if (moisture > 400 ) {
         digitalWrite(A0, HIGH );
        } else {
          digitalWrite(A0, LOW);
        }
    //second sensor
     if (moisture2 > 400) {
          digitalWrite(A2, HIGH);
        } else  {
           digitalWrite(A2, LOW);
        }  
    // Pump Configuration
    if(moisture > 400 || moisture2 > 400){
         digitalWrite(motor, HIGH );
      lcd.setCursor(0,0);
      lcd.print("Pump ON ");
        Serial.println(" pum no");
      delay(1000);
      lcd.clear();
        } else {
          digitalWrite(motor, LOW);
          lcd.setCursor(0,0);
          lcd.print("Pump OFF ");
            Serial.println( "Pum off");
          lcd.clear();
        }
      }
  
  //first Button off
  if (val1 == LOW){
    analogWrite(A4, 0); 
    
  }
  
  // second button value HIGH
  if (val2 == HIGH &&  val1 == LOW) 
    {
        analogWrite(A5, 255);
       Serial.print( "moisture ");
       Serial.println( moisture);
       Serial.print("moisture2 ");
       Serial.println( moisture2);
    
  lcd.setCursor(0,0);
  lcd.print("  Winter Season ");
  lcd.setCursor(0,1);
  lcd.print("  Auto mode ON");
    delay(1000);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moisture Level:- ");
    delay(1000);
     lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FirstSensor: ");
  lcd.println(moisture);
  lcd.setCursor(0,1);
  lcd.print("SecondSensor:");
  lcd.println(moisture2);
    delay(1000);
     lcd.clear();
  
    //first sensor
   if (moisture > 200 ) {
         digitalWrite(A0, HIGH );
        } else {
          digitalWrite(A0, LOW);
        }
    // Second Sensor
     if (moisture2 > 200) {
          digitalWrite(A2, HIGH);
        } else  {
           digitalWrite(A2, LOW);
        }  
    // Pump Configuration
    if(moisture > 200 || moisture2 > 200){
         digitalWrite(motor, HIGH );
      lcd.setCursor(0,0);
      lcd.print("Pump ON ");
        Serial.println( "pump on");
      delay(1000);
      lcd.clear();
        } else {
          digitalWrite(motor, LOW);
          lcd.setCursor(0,0);
          lcd.print("Pump OFF ");
            Serial.println("Pump off");
          lcd.clear();
        }
    }
  
  // Second Button Off
  if (val2 == LOW){
    analogWrite(A5, 0); 
  }
  
  //Both button are off
  if (val1 == LOW && val2 == LOW )
  {
    Serial.println( val1);
    Serial.println( val2);
    analogWrite(A5, 0);
    analogWrite(A4, 0);
    analogWrite(A0, 0);
    analogWrite(A2, 0);
    digitalWrite(motor, 0);
  // LCD print
  lcd.setCursor(0,0);
  lcd.print(" Please Select ");
  lcd.setCursor(0,1);
  lcd.print("     Season.. ");
  delay(1000);
    lcd.clear();
  }
 
  //Buzzzer COnditions
 // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration * 0.034) / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // if distance is less than 130cm, buzzer turns on
  if (distance < 180) 
    
  {
   //digitalWrite(buzzer,HIGH); 
      tone(buzzer,1000);
  lcd.setCursor(0,0);
  lcd.print("Buzzer ON ");
  delay(500);
     lcd.clear();
  }
  else
    
  {
    //digitalWrite(buzzer,LOW); 
    noTone(buzzer);
  lcd.setCursor(0,0);
  lcd.print("Buzzer OFF ");
  delay(500);
     lcd.clear();
  }
  
  delay(100);
}
