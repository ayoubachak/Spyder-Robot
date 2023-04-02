#include "Spyder.h"



// height servos 
int min_right_servo_height = 70; // 0;
int max_right_servo_height = 110; // 110;
int mid_right_servo_height = 90;//( max_right_servo_height + min_right_servo_height ) / 2;

int min_left_servo_height = 70;  // 15;
int max_left_servo_height = 110; // 125;
int mid_left_servo_height = 90;//( max_left_servo_height + min_left_servo_height ) / 2;


int min_right_servo_forward = 70; // 0;
int max_right_servo_forward = 110; // 250;
int mid_right_servo_forward = 90;//( min_right_servo_forward + max_right_servo_forward ) / 2;

int min_left_servo_forward = 70; // 250;
int max_left_servo_forward = 110; // 0;
int mid_left_servo_forward = 90;//( min_left_servo_forward + max_left_servo_forward ) / 2;






RightLeg rleg1 = RightLeg(
  ForwardServo(
    7,
    mid_right_servo_forward,
    min_right_servo_forward,
    max_right_servo_forward), 
  HeightServo(
    1,
    mid_left_servo_height,
    min_left_servo_height,
    max_left_servo_height)
    );

RightLeg rleg2 = RightLeg(
  ForwardServo(
    8,
    mid_right_servo_forward,
    min_right_servo_forward,
    max_right_servo_forward), 
  HeightServo(
    2,
    mid_right_servo_height,
    min_right_servo_height,
    max_right_servo_height)
  );
RightLeg rleg3 = RightLeg(
  ForwardServo(
    9,
    mid_right_servo_forward, 
    min_right_servo_forward, 
    max_right_servo_forward), 
    HeightServo(
    3, 
    mid_right_servo_height, 
    min_right_servo_height, 
    max_right_servo_height)
  );
LeftLeg lleg1 =  LeftLeg(
  ForwardServo(
    10,
    mid_left_servo_forward,
    min_left_servo_forward,
    max_left_servo_forward ) , 
  HeightServo(
    4,
    mid_left_servo_height,
    min_left_servo_height,
    max_left_servo_height)
    );
LeftLeg lleg2  = LeftLeg(
  ForwardServo(
    11,    
    mid_left_servo_forward,
    min_left_servo_forward,
    max_left_servo_forward), 
  HeightServo(
    5,
    mid_left_servo_height,
    min_left_servo_height,
    max_left_servo_height)    
    );

LeftLeg lleg3  = LeftLeg(
  ForwardServo(
    12,    
    mid_left_servo_forward,
    min_left_servo_forward,
    max_left_servo_forward), 
  HeightServo(
    6,
    mid_left_servo_height,
    min_left_servo_height,
    max_left_servo_height)    
    );
LeftLeg left_legs[3] = {lleg1, lleg2, lleg3};
RightLeg right_legs[3] = {rleg1, rleg2, rleg3};
Spyder spydy = Spyder(left_legs, right_legs); 
HeightServo sevo = lleg1.get_height_servo();

void setup() {
  // init the serial
  Serial.begin(9600);
  Serial.println("working");


 /* Initialise the library and set it to 'servo mode' */ 
  MotorDriver.Init(SERVO_MODE);
  /* Wake the device up */
  MotorDriver.Sleep(false);

  spydy.init();


  
}


// move forward
void forward(){
  Serial.println("Forward function executed.");
}

// move backwards
void backwards(){
  Serial.println("Backwards function executed.");
}

// move left 
void left(){
  Serial.println("Left function executed.");
}

// move right
void right(){
  Serial.println("Right function executed.");
}

// climb
void climbing(){
  Serial.println("Climbing function executed.");
}

// slide
void sliding(){
  Serial.println("Sliding function executed.");
}

// grass walk
void grasswalk(){
  Serial.println("Grass Walk function executed.");
}

// inclined walk
void inclinedwalk(){
  Serial.println("Inclined Walk function executed.");
}

// normal walk
void normal(){
  Serial.println("Normal function executed.");
}

// set speed to speed 1
void speed1(){
  Serial.println("Speed 1 function executed.");
}

// set speed to speed 2
void speed2(){
  Serial.println("Speed 2 function executed.");
}

// set speed to speed 3
void speed3(){
  Serial.println("Speed 3 function executed.");
}

// move the arm up
void up(){
  Serial.println("Up function executed.");
}

// move the arm down
void down(){
  Serial.println("Down function executed.");
}

// lock the magnet in place
void lock(){
  Serial.println("Lock function executed.");
}

void receive_input(){
  if (Serial.available() > 0) {
    String data = Serial.readString();
    if (data == "F") {
      // Execute forward function
      forward();
    } else if (data == "B") {
      // Execute backwards function
      backwards();
    } else if (data == "L") {
      // Execute left function
      left();
    } else if (data == "R") {
      // Execute right function
      right();
    } else if (data == "C") {
      // Execute climbing function
      climbing();
    } else if (data == "S") {
      // Execute sliding function
      sliding();
    } else if (data == "GW") {
      // Execute grass walk function
      grasswalk();
    } else if (data == "IW") {
      // Execute inclined walk function
      inclinedwalk();
    } else if (data == "N") {
      // Execute normal function
      normal();
    } else if (data == "1") {
      // Execute speed 1 function
      speed1();
    } else if (data == "2") {
      // Execute speed 2 function
      speed2();
    } else if (data == "3") {
      // Execute speed 3 function
      speed3();
    } else if (data == "U") {
      // Execute up function
      up();
    } else if (data == "D") {
      // Execute down function
      down();
    } else if (data == "LK") {
      // Execute lock function
      lock();
    }
  }
}


 


void loop() {
  // first thing to do
  receive_input();
  // sevo.test();
  spydy.init_forward(5);
  spydy.move_forward(5);
}
