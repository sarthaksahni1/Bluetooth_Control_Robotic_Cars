int enableL = 6;
int enableR = 7;
int LmotorUp = 2; //initialising Arduino port 10 be be called as LmotorUp
int LmotorDn = 3; //initialising Arduino port 11 be be called as LmotorDn
int RmotorUp = 4;  //initialising Arduino port 8 be be called as RmotorUp
int RmotorDn = 5;  //initialising Arduino port 9 be be called as RmotorDn

void setup()
{
  Serial.begin(9600);
  pinMode(enableL, OUTPUT);
  pinMode(enableR, OUTPUT);
  pinMode(LmotorUp,OUTPUT);//Setting ports as OUTPUTS as they 
  pinMode(LmotorDn,OUTPUT);//supply signal values to motor driver
  pinMode(RmotorUp,OUTPUT);
  pinMode(RmotorDn,OUTPUT);
  Serial.println("<Robot name> Welcomes you"); //begining statement because i can :P
  delay(1000);
} 
  

void loop()
{
  digitalWrite(enableL, HIGH);
  digitalWrite(enableR, HIGH);
  delay(1000);
  
  if(Serial.available()>0)//Checking is Serial data available
  {
    int input = Serial.read(); //Storing value of read data into variable assigned
    switch(input)
    {
     case 'w' : MoveF(); //Calling respective functions if mathced with case label 
     break;
     case 's' : MoveB(); // here is it important to use '' as that stores the ASCII value is the letter in the variable
     break;
     case 'a' : MoveL(); // and hence we can use the int keyword
     break;
     case 'd' : MoveR();
     break;
     case 'x' : Stp();
     break;
     default : break;
    }
  } 
  delay(50);
}

void MoveF()
{
  Serial.println("<Robot Name> Forward");
  digitalWrite(LmotorUp,HIGH); //As said in video we are writing a Digital HIGH to the upper left pin of the motor driver
  digitalWrite(LmotorDn,LOW); //As said in video we are writing a Digital LOW to the lower left pin of the motor driver
  digitalWrite(RmotorUp,HIGH); //As said in video we are writing a Digital HIGH to the upper right pin of the motor driver
  digitalWrite(RmotorDn,LOW); //As said in video we are writing a Digital LOW to the lower right pin of the motor driver
   // As a result the robot will move forward
  delay(2000);
}

void MoveB()
{
  Serial.println("<Robot Name> Backward");
  digitalWrite(LmotorUp,LOW); //Reverse logic of above
  digitalWrite(LmotorDn,HIGH);
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,HIGH);
  delay(2000);
}

void MoveL()
{
  Serial.println("<Robot Name> Left");
  digitalWrite(LmotorUp,LOW); //we are completely stopping the left motor and allowing the right motor to move forward
  digitalWrite(LmotorDn,LOW); //this will cause the robot to move left
  digitalWrite(RmotorUp,HIGH);
  digitalWrite(RmotorDn,LOW);
  delay(1000);
}

void MoveR()
{
  Serial.println("<Robot Name> Right");
  digitalWrite(LmotorUp,HIGH);//we are completely stopping the right motor and allowing the left motor to move forward
  digitalWrite(LmotorDn,LOW);//this will cause the robot to move right
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,LOW);
  delay(1000);
}

void Stp()
{
  Serial.println("<Robot Name> Stop");
  digitalWrite(LmotorUp,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
  digitalWrite(LmotorDn,LOW);
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,LOW);
}

