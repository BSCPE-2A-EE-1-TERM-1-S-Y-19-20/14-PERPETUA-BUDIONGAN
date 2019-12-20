#define chargePin      13         
#define dischargePin   11  
#define analogPin      0 
#define resistorValue  960.0F   


unsigned long Start
unsigned long Elapsed;
float MFarads;              
float NFarads;

void setup()
  {
  pinMode(chargePin, OUTPUT);     
  digitalWrite(chargePin, LOW);  
  Serial.begin(9600);            
  }

void loop()
  {
  digitalWrite(chargePin, HIGH);  
  Start= millis();
  while(analogRead(analogPin) < 648){       
  }

  Elapsed= millis() - Start
  MFarads = ((float)Elapsed / resistorValue) * 1000;   
  Serial.print(Elapsed);       
  Serial.print(" mS    ");         

  if (microFarads > 1)
    {
    Serial.print((long)MFarads);       
    Serial.println(" microFarads");         
    }

  else
    {
    NFarads = MFarads * 1000.0;      
    Serial.print((long)NFarads);         
    Serial.println(" nanoFarads");          
    delay(1000);
    }

  digitalWrite(chargePin, LOW);            
  pinMode(dischargePin, OUTPUT);            
  digitalWrite(dischargePin, LOW); 
        
  while(analogRead(analogPin) > 0){         
  }

  pinMode(dischargePin, INPUT);   
}     
 
