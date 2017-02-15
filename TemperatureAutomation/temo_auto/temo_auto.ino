#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 7
#define motor_pin1 8
#define motor_pin2 9
#define light_pin 10


void motor_on(){
digitalWrite(motor_pin1, HIGH);
digitalWrite(motor_pin2, LOW);
}

void motor_off(){
digitalWrite(motor_pin1, LOW);
digitalWrite(motor_pin2, LOW);
}
void light_on(){
  digitalWrite(light_pin,HIGH);
}
void light_off(){
  digitalWrite(light_pin,LOW);
}
void setup(){
  lcd.begin(16, 2);
  pinMode(motor_pin1,OUTPUT);
  pinMode(motor_pin2,OUTPUT);
  pinMode(light_pin,OUTPUT);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  float T=DHT.temperature;
  float H=DHT.humidity;
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Temp=");
  lcd.print(T);
  lcd.print(" c");
  lcd.setCursor(0,1);
  lcd.print("Humidity=");
  lcd.print(H);
  lcd.print("%");
  delay(1000);
  
  if(T > 27 && H > 85){
  motor_on();
  }
  else{
  motor_off();
  }
  if(T < 27 && H < 85){
    light_on();
  }
   else{
    light_off();
    }
    

}
