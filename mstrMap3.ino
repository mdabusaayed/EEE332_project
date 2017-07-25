void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()
{
  int mois = analogRead(A0);
  int soil1 = map(mois, 285, 1024, 100, 0);
  Serial.print("Moisture: ");
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

  

  
  delay(2000);
}
