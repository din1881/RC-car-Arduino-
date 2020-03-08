//3rd--->right

char t=' ';
#define trigPin 8
#define echoPin 7
long duration;
long distance;
int maximumRange = 55; // Maximum range needed
int minimumRange = 0; // Minimum range needed
int flag_l=0;
int flag_r=0;

int flag=0;

#define R_S 13 //sincer R
#define S_S 4 //sincer S
#define L_S 2 //sincer L

void forward_ir(){
  analogWrite(5,65);
  analogWrite(3,60); 
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  }
 


  void left_ir()
{
      analogWrite(5,45);
  analogWrite(3,65);
   digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  }

  

    void right_ir()
  {
      analogWrite(5,65);
  analogWrite(3,30);
    digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
    }


void stop_m()
   {
        analogWrite(5,0);
  analogWrite(3,0);
    digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
    }
 
 void forward(){

  digitalWrite(9,HIGH  );
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  analogWrite(5,127);
  analogWrite(3,127);
  }

  void reverse() {
      digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
    analogWrite(5,127);
  analogWrite(3,127);
      }

      void right()
  {
    digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  analogWrite(5,100);
  analogWrite(3,40);  
    }

    void left()
{
   digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
    analogWrite(5,75);
  analogWrite(3,100);
  }

    
void setup() {
  
pinMode(9,OUTPUT);   //left motors forward
pinMode(10,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(12,OUTPUT);   //right motors reverseg
pinMode(5,OUTPUT);
pinMode(3,OUTPUT);

pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);

 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 
Serial.begin(9600);
 
}

void loop() {

if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == '1'){ //move forward(all motors rotate in forward direction)
  

  forward();
  digitalWrite(trigPin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
  duration= pulseIn(echoPin,HIGH);
  distance = duration / 58 ;
  Serial.println(distance);

  if (!(distance > maximumRange || distance < minimumRange))
{
    digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
    analogWrite(5,127);
  analogWrite(3,127);
  delay(400);

  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  analogWrite(5,127);
  analogWrite(3,127);
  delay(400);
  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
    analogWrite(5,255);
  analogWrite(3,255); 
} 
}
 


 
else if(t == '2'){      //move reverse (all motors rotate in reverse direction)

  reverse();
}
 
else if(t == '3'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  right();
  digitalWrite(trigPin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
  duration= pulseIn(echoPin,HIGH);
  distance = duration / 58 ;
  Serial.println(distance);

  if (!(distance > maximumRange || distance < minimumRange))
{
    digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
    analogWrite(5,127);
  analogWrite(3,127);
  delay(400);

  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  analogWrite(5,127);
  analogWrite(3,127);
  delay(400);
  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
    analogWrite(5,255);
  analogWrite(3,255); 
} 
}
 
else if(t == '4'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
 left();
 digitalWrite(trigPin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
  duration= pulseIn(echoPin,HIGH);
  distance = duration / 58 ;
  Serial.println(distance);

  if (!(distance > maximumRange || distance < minimumRange))
{
    digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
    analogWrite(5,127);
  analogWrite(3,127);
  delay(400);

  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  analogWrite(5,127);
  analogWrite(3,127);
  delay(400);
  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
    analogWrite(5,255);
  analogWrite(3,255); 
} 
}
 
else if(t == '5'){      //STOP (all motors stop)

  stop_m();
}
//delay(100);

//    r sensor code 
if (t=='6'){

if ((digitalRead(L_S) ==HIGH)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == HIGH))
{forward_ir(); }


else if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S)==LOW)&&(digitalRead(R_S) == HIGH))
{
  left_ir(); 
  flag_l=1;
  flag_r=0; 

  }



else if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) ==HIGH)&&(digitalRead(R_S) == HIGH)) 
{
  left_ir();
  flag_l=1;
  flag_r=0;
  }


else if ( (digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == LOW) && (digitalRead(R_S) == LOW) )

{
  right_ir(); 
  flag_r=1;
  flag_l=0; 
  
  }


else if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == LOW))
{
  right_ir();
  flag_r=1;
  flag_l=0; 
  }

/*if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == LOW)){forward_2();}
if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == HIGH)){forward_2();}*/
//else if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == LOW) &&(flag=2)){ right_ir(); flag=0;}

if((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == HIGH) && (flag_l==1))
{

      analogWrite(5,0);
  analogWrite(3,55);
   digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH); 
}


if((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == HIGH) && (flag_r==1))
{

      analogWrite(5,60);
  analogWrite(3,0);
   digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH); 
}

//else if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == HIGH)&&(flag=2)){ right_ir(); flag=0;  }


//else if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == HIGH)){stop_m();}
} 
}
