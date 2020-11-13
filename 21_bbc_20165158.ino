// Arduino pin assignment
#include <Servo.h>
#define PIN_SERVO 10
#define PIN_IR A0

Servo myservo;

void setup() {
  myservo.attach(PIN_SERVO); 
  
// initialize serial port
  Serial.begin(9600);

}

float ir_distance(void){ // return value unit: mm
  float val;
  float volt = float(analogRead(PIN_IR));
  val = ((6762.0/(volt-9.0))-4.0) * 10.0;
  return val;
}

void loop() {
  float raw_dist = ir_distance();
  Serial.print("min:0,max:500,dist:");
  Serial.println(raw_dist);
//  myservo.writeMicroseconds(1400);  while(1){}
  if(raw_dist > 255){
    myservo.writeMicroseconds(900); //  upper the board
    delay(1000);
  }
  else{
    myservo.writeMicroseconds(1400); // flatten the board
    delay(1000);
    myservo.writeMicroseconds(1800); // lower the board
    delay(1000);
  }
}
