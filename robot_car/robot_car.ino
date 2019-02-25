int LmotorUp = 10; //initialising Arduino port 10 be be called as LmotorUp
int LmotorDn = 11; //initialising Arduino port 11 be be called as LmotorDn
int RmotorUp = 8;  //initialising Arduino port 8 be be called as RmotorUp
int RmotorDn = 9;  //initialising Arduino port 9 be be called as RmotorDn
int lights  = 7;  //Leds connected to Arduino UNO Pin 12
int buzzer = 5 ;   //Buzzer / Speaker to Arduino UNO Pin 3
String readString;

void setup() 
{
  Serial.begin(9600);
  pinMode(LmotorUp,OUTPUT);//Setting ports as OUTPUTS as they 
  pinMode(LmotorDn,OUTPUT);//supply signal values to motor driver
  pinMode(RmotorUp,OUTPUT);
  pinMode(RmotorDn,OUTPUT);
  pinMode(lights, OUTPUT); 
  pinMode(buzzer, OUTPUT); // buzz pin is output to control buzzering
}

void loop() 
{
  while(Serial.available())
  {
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0)
  {
    Serial.println(readString);
    if (readString =="FORWARD")
    {
      digitalWrite(LmotorUp,HIGH); //As said in video we are writing a Digital HIGH to the upper left pin of the motor driver
      digitalWrite(LmotorDn,LOW); //As said in video we are writing a Digital LOW to the lower left pin of the motor driver
      digitalWrite(RmotorUp,HIGH); //As said in video we are writing a Digital HIGH to the upper right pin of the motor driver
      digitalWrite(RmotorDn,LOW); //As said in video we are writing a Digital LOW to the lower right pin of the motor driver
      // As a result the robot will move forward
      delay(500);
    }
    if (readString =="BACKWARD")
    {
      digitalWrite(LmotorUp,LOW); //Reverse logic of above
      digitalWrite(LmotorDn,HIGH);
      digitalWrite(RmotorUp,LOW);
      digitalWrite(RmotorDn,HIGH);
      delay(500);
    }
    if (readString =="LEFT")
    {
      digitalWrite(LmotorUp,LOW); //we are completely stopping the left motor and allowing the right motor to move forward
      digitalWrite(LmotorDn,LOW); //this will cause the robot to move left
      digitalWrite(RmotorUp,HIGH);
      digitalWrite(RmotorDn,LOW);
      delay(250);
    }
    if (readString =="RIGHT")
    {
      digitalWrite(LmotorUp,HIGH);//we are completely stopping the right motor and allowing the left motor to move forward
      digitalWrite(LmotorDn,LOW);//this will cause the robot to move right
      digitalWrite(RmotorUp,LOW);
      digitalWrite(RmotorDn,LOW);
      delay(250);
    }
    if (readString =="STOP")
    {
      digitalWrite(LmotorUp,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
      digitalWrite(LmotorDn,LOW);
      digitalWrite(RmotorUp,LOW);
      digitalWrite(RmotorDn,LOW);
      delay(500);
    }
    if (readString =="LIGHTS")
    {
      digitalWrite(lights, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }
    if (readString =="HORN")
    {
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
    }

    readString="";
  }
}
