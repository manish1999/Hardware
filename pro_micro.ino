

int ldr= A2;//Set A2(Analog Input) for LDR.
int ldr_value=0;
int waterLevel= A1; //Set A1 for water level sensor
int WL_Value = 0;
int R1=5;
int R2=4;
void setup() 
{
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  pinMode(waterLevel,INPUT);
  pinMode(R1,OUTPUT);// relay for ldr
  pinMode(R2,OUTPUT);//relay for water level sensor
}

void loop() 
{
    ldr_value=analogRead(ldr);//Reads the Value of LDR(light).
    WL_Value=analogRead(waterLevel);//Reads the value from water level sensor.
   
Serial.println(ldr_value);
Serial.println(WL_Value);
    if(ldr_value<40)
    {
      digitalWrite(R1,LOW);//Makes the LED glow in Dark.
    }
    else
    {
      digitalWrite(R1,HIGH);//Turns the LED OFF in Light.
    }
    if(WL_Value > 600)
    {
      digitalWrite(R2,HIGH);//Turns the motor off
      
    }
    else
    {
      digitalWrite(R2,LOW);//Turns the motor on.
    }
}
