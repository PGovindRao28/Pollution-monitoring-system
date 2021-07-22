/*
 https://thestempedia.com/tutorials/interfacing-mq-4-gas-sensor-evive/#Arduino_IDE_code


 resource from where conversion to ppm from sensor value; i got
 */




#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//defining MQ2,MQ5,,MQ7,MQ135,DHT11
int sensor_mq2 =A0;
int sensor_mq5 =A1;
int sensor_mq7 =A2;
int sensor_mq135 =A3;

//ouput device
int buzzer=8;


//defining initial value
float sensorvalue_mq2 =0;
float sensorvalue_mq5 =0;
float sensorvalue_mq7 =0;
float sensorvalue_mq135 =0;

float m = -0.318;     //Slope 
float b = 1.133;     //Y-Intercept 

void setup()
{
  // initialize the LCD
  lcd.begin();
  pinMode(sensor_mq2,INPUT);
  pinMode(sensor_mq5,INPUT);
  pinMode(sensor_mq7,INPUT);
  pinMode(sensor_mq135,INPUT);
  
  pinMode(buzzer,OUTPUT);
  
  digitalWrite(buzzer,LOW);  
}

void loop()
{
  
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Air Quality");
  
  lcd.print("Detector");
  lcd.clear();

  
  
  
  
  //mq2 sensor
  float sensor_volt_mq2;                             //Define variable for sensor voltage 
  float RS_air_mq2;                                 //Define variable for sensor resistance
  float R0_mq2;                                    //Define variable for R0
  float sensorValue_mq2;                          //Define variable for analog readings 
  for(int x = 0 ; x < 500 ; x++)             //Start for loop 
  {
    sensorValue_mq2 = sensorValue_mq2 + analogRead(A0); //Add analog values of sensor 500 times 
  }
  sensorValue_mq2 = sensorValue_mq2/500.0;            //Take average of readings
  sensor_volt_mq2 = sensorValue_mq2*(5.0/1023.0);    //Convert average to voltage
  sensorValue_mq2 = sensorValue_mq2/500.0;            //Take average of readings
  sensor_volt_mq2 = sensorValue_mq2*(5.0/1023.0);    //Convert average to voltage 
  RS_air_mq2 = ((5.0*10.0)/sensor_volt_mq2)-10.0;   //Calculate RS in fresh air 
  R0_mq2 = RS_air_mq2/4.4;                         //Calculate R0

  float ratio_mq2;                  //Define variable for ratio
  sensorValue_mq2 = analogRead(A0);    //Read analog values of sensor  
  sensor_volt_mq2 = sensorValue_mq2*(5.0/1023.0);       //Convert analog values to voltage 
  RS_air_mq2 = ((5.0*10.0)/sensor_volt_mq2)-10.0;      //Get value of RS in a gas
  ratio_mq2 = RS_air_mq2/R0_mq2;                          // Get ratio RS_gas/RS_air


  double ppm_log_mq2 = (log10(ratio_mq2)-b)/m;     //Get ppm value in linear scale according to the the ratio value  
  double ppm_mq2 = pow(10, ppm_log_mq2);          //Convert ppm value to log scale 
  Serial.print("ppm_mq2 :");
  Serial.println(ppm_mq2);
  double percentage_mq2 = ppm_mq2/10000;      //Convert to percentage
  if(ppm_mq2>2000)
     { 
      //Check if ppm value is greater than 2000 
      digitalWrite(buzzer, HIGH); //Turn Buzzer on 
     }
  else
    {
     digitalWrite(buzzer,LOW); 
    }
  delay(5000);
  digitalWrite(buzzer, LOW);


//mq5 sensor
  float sensor_volt_mq5;                             //Define variable for sensor voltage 
  float RS_air_mq5;                                 //Define variable for sensor resistance
  float R0_mq5;                                    //Define variable for R0
  float sensorValue_mq5;                          //Define variable for analog readings 
  for(int x = 0 ; x < 500 ; x++)             //Start for loop 
  {
    sensorValue_mq5 = sensorValue_mq5 + analogRead(A0); //Add analog values of sensor 500 times 
  }
  sensorValue_mq5 = sensorValue_mq5/500.0;            //Take average of readings
  sensor_volt_mq5 = sensorValue_mq5*(5.0/1023.0);    //Convert average to voltage
  sensorValue_mq5 = sensorValue_mq5/500.0;            //Take average of readings
  sensor_volt_mq5 = sensorValue_mq5*(5.0/1023.0);    //Convert average to voltage 
  RS_air_mq5 = ((5.0*10.0)/sensor_volt_mq5)-10.0;   //Calculate RS in fresh air 
  R0_mq5 = RS_air_mq5/4.4;                         //Calculate R0

  float ratio_mq5;                  //Define variable for ratio
  sensorValue_mq5 = analogRead(A0);    //Read analog values of sensor  
  sensor_volt_mq5 = sensorValue_mq5*(5.0/1023.0);       //Convert analog values to voltage 
  RS_air_mq5 = ((5.0*10.0)/sensor_volt_mq5)-10.0;      //Get value of RS in a gas
  ratio_mq5 = RS_air_mq5/R0_mq5;                          // Get ratio RS_gas/RS_air


  double ppm_log_mq5 = (log10(ratio_mq5)-b)/m;     //Get ppm value in linear scale according to the the ratio value  
  double ppm_mq5 = pow(10, ppm_log_mq5);          //Convert ppm value to log scale 
  Serial.print("ppm_mq5 :");
  Serial.println(ppm_mq5);
  double percentage_mq5 = ppm_mq5/10000;      //Convert to percentage
  if(ppm_mq5>3000)
     { 
      //Check if ppm value is greater than 2000 
      digitalWrite(buzzer, HIGH); //Turn Buzzer on 
     }
  else
    {
     digitalWrite(buzzer,LOW); 
    }
  delay(5000);
  digitalWrite(buzzer, LOW);


  //mq7 sensor
  float sensor_volt_mq7;                             //Define variable for sensor voltage 
  float RS_air_mq7;                                 //Define variable for sensor resistance
  float R0_mq7;                                    //Define variable for R0
  float sensorValue_mq7;                          //Define variable for analog readings 
  for(int x = 0 ; x < 500 ; x++)             //Start for loop 
  {
    sensorValue_mq7 = sensorValue_mq7 + analogRead(A0); //Add analog values of sensor 500 times 
  }
  sensorValue_mq7 = sensorValue_mq7/500.0;            //Take average of readings
  sensor_volt_mq7 = sensorValue_mq7*(5.0/1023.0);    //Convert average to voltage
  sensorValue_mq7 = sensorValue_mq7/500.0;            //Take average of readings
  sensor_volt_mq7 = sensorValue_mq7*(5.0/1023.0);    //Convert average to voltage 
  RS_air_mq7 = ((5.0*10.0)/sensor_volt_mq7)-10.0;   //Calculate RS in fresh air 
  R0_mq7 = RS_air_mq7/4.4;                         //Calculate R0

  float ratio_mq7;                  //Define variable for ratio
  sensorValue_mq7 = analogRead(A0);    //Read analog values of sensor  
  sensor_volt_mq7 = sensorValue_mq7*(5.0/1023.0);       //Convert analog values to voltage 
  RS_air_mq7 = ((5.0*10.0)/sensor_volt_mq7)-10.0;      //Get value of RS in a gas
  ratio_mq7 = RS_air_mq7/R0_mq7;                          // Get ratio RS_gas/RS_air


  double ppm_log_mq7 = (log10(ratio_mq7)-b)/m;     //Get ppm value in linear scale according to the the ratio value  
  double ppm_mq7 = pow(10, ppm_log_mq7);          //Convert ppm value to log scale 
  Serial.print("ppm_mq7 :");
  Serial.println(ppm_mq7);
  double percentage_mq7 = ppm_mq7/10000;      //Convert to percentage
  if(ppm_mq7>4000)
     { 
      //Check if ppm value is greater than 2000 
      digitalWrite(buzzer, HIGH); //Turn Buzzer on 
     }
  else
    {
     digitalWrite(buzzer,LOW); 
    }
  delay(5000);
  digitalWrite(buzzer, LOW);


  //mq 135 sensor
  float sensor_volt_mq135;                             //Define variable for sensor voltage 
  float RS_air_mq135;                                 //Define variable for sensor resistance
  float R0_mq135;                                    //Define variable for R0
  float sensorValue_mq135;                          //Define variable for analog readings 
  for(int x = 0 ; x < 500 ; x++)             //Start for loop 
  {
    sensorValue_mq135 = sensorValue_mq135 + analogRead(A0); //Add analog values of sensor 500 times 
  }
  sensorValue_mq135 = sensorValue_mq135/500.0;            //Take average of readings
  sensor_volt_mq135 = sensorValue_mq135*(5.0/1023.0);    //Convert average to voltage
  sensorValue_mq135 = sensorValue_mq135/500.0;            //Take average of readings
  sensor_volt_mq135 = sensorValue_mq135*(5.0/1023.0);    //Convert average to voltage 
  RS_air_mq135 = ((5.0*10.0)/sensor_volt_mq135)-10.0;   //Calculate RS in fresh air 
  R0_mq135 = RS_air_mq135/4.4;                         //Calculate R0

  float ratio_mq135;                  //Define variable for ratio
  sensorValue_mq135 = analogRead(A0);    //Read analog values of sensor  
  sensor_volt_mq135 = sensorValue_mq135*(5.0/1023.0);       //Convert analog values to voltage 
  RS_air_mq135 = ((5.0*10.0)/sensor_volt_mq135)-10.0;      //Get value of RS in a gas
  ratio_mq135 = RS_air_mq135/R0_mq135;                          // Get ratio RS_gas/RS_air


  double ppm_log_mq135 = (log10(ratio_mq135)-b)/m;     //Get ppm value in linear scale according to the the ratio value  
  double ppm_mq135 = pow(10, ppm_log_mq135);          //Convert ppm value to log scale 
  Serial.print("ppm_mq135 :");
  Serial.println(ppm_mq135);
  double percentage_mq135 = ppm_mq135/10000;      //Convert to percentage
  if(ppm_mq135>5000)
     { 
      //Check if ppm value is greater than 2000 
      digitalWrite(buzzer, HIGH); //Turn Buzzer on 
     }
  else
    {
     digitalWrite(buzzer,LOW); 
    }
  delay(5000);
  digitalWrite(buzzer, LOW);



  //DHT11 sensor
  









  
}
   
