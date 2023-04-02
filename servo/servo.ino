#include "Servo.h"

Servo ser1, ser2;


void setup(){
  ser1.attach(2);
  ser2.attach(3);

  ser1.write(0);
  ser2.write(0);
  delay(2000);
}

void loop(){
  
  // for(int i =0; i < 180; i++){
  //   ser1.write(i);
  //   ser2.write(i);
  //   delay(20);
  // } 

  // for(int j = 0; j < 180; j++){
  //   ser1.write(j);
  //   ser2.write(j);
  //   delay(20);
  // }

}
