#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     switch(results.value)
     {
       case 0xFF02FD:
       {
         Serial.println("POWER");
         digitalWrite(12, LOW);
         digitalWrite(8,LOW);
         digitalWrite(9, LOW);
         digitalWrite(10,LOW);
       }
         break;
       case 0xFF52AD:
       {
         Serial.println("UP");
         digitalWrite(12,LOW);
         digitalWrite(8,HIGH);
       }
       break;
       
       case 0xFF7887:
       {
         Serial.println("DOWN");
         digitalWrite(12,HIGH);
         digitalWrite(8,LOW);
       }
         break;
         
       case 0xFFB847:
       {
         Serial.println("RIGHT");
         digitalWrite(9,HIGH);
         digitalWrite(10,LOW);
       }
         break;
       
       case 0xFF42BD:
       {
         Serial.println("LEFT");
         digitalWrite(10,HIGH);
         digitalWrite(9,LOW);
       }
         break;
       case 0xFFC23D:
       {
         Serial.println("FRONT_LEFT");
         
         digitalWrite(9,LOW);
         digitalWrite(10,HIGH);
         
         digitalWrite(12,LOW);
         digitalWrite(8,HIGH);
         
         delay(400);
         digitalWrite(8,LOW);
       }
         break;
       
       case 0xFF629D:
       {
         Serial.println("FRONT_RIGHT");
         digitalWrite(12,LOW);
         digitalWrite(8,HIGH);
         digitalWrite(10,LOW);
         digitalWrite(9,HIGH);
         delay(400);
         digitalWrite(8,LOW);
       }
         break;
         
       case 0xFFF807:
       {
         Serial.println("REAR_LEFT");
         digitalWrite(12,HIGH);
         digitalWrite(8,LOW);
         digitalWrite(10,HIGH);
         digitalWrite(9,LOW);
         delay(400);
         digitalWrite(12,LOW);
       }
         break;
       
       case 0xFF38C7:
       {
         Serial.println("REAR_RIGHT");
         digitalWrite(12,HIGH);
         digitalWrite(8,LOW);
         digitalWrite(10,LOW);
         digitalWrite(9,HIGH);
         delay(400);
         digitalWrite(12,LOW);
       }
         break;
       
       /*default:
       {
         Serial.println("DEFAULT");
         digitalWrite(12,LOW);
         digitalWrite(8,LOW);
         digitalWrite(11,LOW);
         digitalWrite(10,LOW);
       }*/
     }
     irrecv.resume(); // Receive the next value
    }
}


