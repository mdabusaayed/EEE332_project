#include <AFMotor.h>
#include <dht.h>
#include <Servo.h>
Servo name_servo; 

int servo_position = 0 ;

#define dht_dpin A1
dht DHT;

AF_DCMotor motorA(1);
AF_DCMotor motorB(2);

void setup() 
{
  Serial.begin(9600);
  delay(700);
  
  motorA.setSpeed(150);
  motorB.setSpeed(150);

  name_servo.attach (10);
  
}

void loop() 
{
//Servo begin
  
  for (servo_position = 0; servo_position <=180; servo_position +=1){

    name_servo.write(servo_position);
    delay(10);
  }
  
//Servo end

  
// temp begin
  DHT.read11(dht_dpin);

    Serial.print("\n Air Humidity= ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Temp= ");
    Serial.print(DHT.temperature); 
    Serial.println("°C  ");
  delay(3000);
// temp end


//moisture begin
  int mois = analogRead(A1);
  int soil1 = map(mois, 285, 1024, 100, 0);
  Serial.print("Soil Moisture: ");
  Serial.print(soil1);
  Serial.print("%  value:");
  Serial.print(mois);
  Serial.print(" - ");
  
  if(mois >= 1000) {
   Serial.println("Sensor is not in the Soil or DISCONNECTED");
  }
  
  if(mois < 1000 && mois >= 600) { 
   Serial.println("Soil is DRY");
  }
  
  if(mois < 600 && mois >= 370) {
   Serial.println("Soil is HUMID"); 
  }
  
  if(mois < 370) {
   Serial.println("Sensor in WATER");
  }
  delay(3000);

//moisture end



//Servo begin

  for (servo_position=180; servo_position >= 0; servo_position -=1){

    name_servo.write(servo_position);
    delay(10);
  }
  
//Servo end




  //Forward
  Serial.println("Forward");
  motorA.run(FORWARD);
  motorB.run(FORWARD);
  delay(5000);
 
   //stop
  Serial.println("Stop");
  motorA.run(RELEASE);
  motorB.run(RELEASE);
  delay(1000);
  
  //right
  Serial.println("Right");
  motorA.run(FORWARD);
  motorB.run(BACKWARD);
  delay(600); 

  //stop
  Serial.println("Stop");
  motorA.run(RELEASE);
  motorB.run(RELEASE);
  delay(1000);
  
  //back
  Serial.println("Backward");
  motorA.run(BACKWARD);
  motorB.run(BACKWARD);
  delay(5000);

  //stop
  Serial.println("Stop");
  motorA.run(RELEASE);
  motorB.run(RELEASE);
  delay(1000);
   
  //left
  Serial.println("Left");
  motorA.run(BACKWARD);
  motorB.run(FORWARD);
  delay(600);  
  
  //stop
  Serial.println("Stop");
  motorA.run(RELEASE);
  motorB.run(RELEASE);
  delay(1000);
}
