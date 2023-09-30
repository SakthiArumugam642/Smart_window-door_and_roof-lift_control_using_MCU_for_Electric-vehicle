// C++ code
#include <dht.h>// Include library
#define outPin 4
dht DHT; 
void setup()
{
  pinMode(12, OUTPUT);//+ve  motor
  pinMode(13,OUTPUT);//-ve   motor
  pinMode(5, OUTPUT);//+ve ac
  pinMode(6,OUTPUT);//-ve  ac
  pinMode(A1,INPUT);//rain drop sensor
  pinMode(8,OUTPUT);//Buzzer 
  pinMode(2, OUTPUT); //enA
  pinMode(3, OUTPUT); //enB
  Serial.begin(9600);
  
}

void loop()
{ 
  
//code for raindrop sensor
    int sensorValue = analogRead(A1);
    Serial.println(sensorValue);//threshold value 900
  
  //code for dht11 sensor
    int readData = DHT.read11(outPin);
    int temp= DHT.temperature;        // Read temperature
	  Serial.println(temp);
	  delay(2000);
   
  //motor initially in off condition
     digitalWrite(13,HIGH);
     digitalWrite(12,HIGH);
  //for ac motor
     digitalWrite(5,HIGH);
     digitalWrite(6,HIGH);
  
  
  //condition(control) part
  
  if(temp>25)//condition for temperature alone
  {    
      //code for buzzer
      tone(8, 50);
      delay(100);
      noTone(8);
      delay(100);
      
      //code for turning on ac motor and window door/roof lift
    analogWrite(2, 255);
    analogWrite(3, 255);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    delay(2000);
     digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);

}
  if(temp<25)//special joint condition for turning off ac with rain and temperature condition
  {
     analogWrite(2, 255);
     analogWrite(3, 255);
     digitalWrite(5,HIGH);
     digitalWrite(6,HIGH);
  }
  if(sensorValue<490)//condition for rain alone
  {
      //code for buzzer
      tone(8, 100);
      delay(100);
      noTone(8);
      delay(100);
      
      //code for turning on window door/roof lift
      analogWrite(2, 255);
      analogWrite(3, 255);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      delay(3000);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
  }
  if(temp>25 && sensorValue<490) //condition for rain and temperature
  {
      //code for buzzer
      tone(8, 50);
      delay(100);
      noTone(8);
      delay(100);

    //code for turning on ac motor and window door/roof lift
     analogWrite(2, 255);
     analogWrite(3, 255);

    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    delay(2000);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);

  }
     
 

}
