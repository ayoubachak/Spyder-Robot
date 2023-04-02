#include <HCPCA9685.h>

#define I2CAdd 0x40

/* Create an instance of the library */
HCPCA9685 MotorDriver(I2CAdd);

class LegServo {
  protected:
    int pin;
    int pos;
    int min_pos = 0;
    int max_pos = 250;
    int middle_pos = (min_pos + max_pos) / 2;
    int init_pos = 0;

  public:
    LegServo() {}

    LegServo(int servo_pin) {
      pin = servo_pin;
      pos = min_pos;
      // initialize the servo object and set the initial position to 0
    }

    LegServo(int servo_pin, int servo_init_pos) {
      pin = servo_pin;
      pos = servo_init_pos;
      // initialize the servo object and set the initial position to 0
      reset_pos();
    }

    LegServo(int servo_pin, int servo_pos, int servo_min_pos, int servo_max_pos) {
      pin = servo_pin;
      pos = servo_pos;
      min_pos = servo_min_pos;
      max_pos = servo_max_pos;
      // initialize the servo object with the given position, minimum and maximum positions
    }
    void move() {
      // max position means the reach ( if it's about height, it means the max height, if it's about direction it means the max angle forward )
      if(min_pos < max_pos){
        if ( pos > max_pos ){
          pos = max_pos;
        }else if ( pos < min_pos ){
          pos = min_pos;
        }
      }else{
        if (pos > min_pos) {
          pos = min_pos;
        } else if (pos < max_pos) {
          pos = max_pos;

        }
      }
      // Serial.print("Moving pin : ");Serial.println(pin);
      MotorDriver.Servo(pin, pos);
      delay(100);
    }
    

    void reset_pos() {
      // pos = init_pos;
      // move();
    }

    int get_pos() { return pos; }

    int get_pin() { return pin; }

    int get_min() { return min_pos; }
    
    int get_max() { return max_pos; }

    LegServo set_pos(int position) { pos = position;  return this;}

    void set_position_middle(){
      set_pos(( get_min()+ get_max())/2 );
      move();
    }

    void set_position_max(){
      if (max_pos > min_pos ){
        set_pos( get_max() );
      }else{
        set_pos( get_min() );
      }
      move();
    }

    void set_position_min(){
      if (max_pos < min_pos ){
        set_pos( get_max() );
      }else{
        set_pos( get_min() );
      }
      move();
    }
};

class HeightServo : public LegServo {
  public:
    HeightServo() {}

    HeightServo(int servo_pin) : LegServo(servo_pin) {}

    HeightServo(int servo_pin, int servo_init_pos) : LegServo(servo_pin, servo_init_pos) {}

    HeightServo(int servo_pin, int servo_pos, int servo_min_pos, int servo_max_pos)
        : LegServo(servo_pin, servo_pos, servo_min_pos, servo_max_pos) {}


    void up(int delta){
      if(min_pos < max_pos){ // if the order is correct we just move normally 
        pos+=delta;
      }else{
        pos-=delta; 
      }
      move();
    }

    void down(int delta){
      if(min_pos < max_pos){ // if the order is correct we just move normally  
        pos-=delta;
      }else{
        pos+=delta; 
      }
      move();
    }    
    void test(){
      Serial.println("testing...");
      while ( abs(pos - get_max()) > 1 ){
        up(5);
        Serial.println("up...");
        delay(10);
      }
      delay(1000);
      while ( abs(pos - get_min()) > 1 ){
        down(5);
        Serial.println("down...");
        delay(10);
      }
      delay(1000);
    }
};

class ForwardServo : public LegServo {
  public:
    ForwardServo() {}

    ForwardServo(int servo_pin) : LegServo(servo_pin) {}

    ForwardServo(int servo_pin, int servo_init_pos) : LegServo(servo_pin, servo_init_pos) {}

    ForwardServo(int servo_pin, int servo_pos, int servo_min_pos, int servo_max_pos)
        : LegServo(servo_pin, servo_pos, servo_min_pos, servo_max_pos) {}

    
    void forward(int delta){
      if(min_pos < max_pos){ // if the order is correct we just move normally 
        pos+=delta;
      }else{
        pos-=delta; 
      }
      move();
    }

    void backwards (int delta){
      if(min_pos < max_pos){ // if the order is correct we just move normally  
        pos-=delta;
      }else{
        pos+=delta; 
      }
      move();
    }

    void test(){
      Serial.println("testing...");
      while ( abs(pos - get_max()) > 1 ){
        forward(10);
        Serial.println("forward...");
        delay(1000);
      }
      delay(2000);
      while ( abs(pos - get_min()) > 1 ){
        backwards(10);
        Serial.println("backwards...");
        delay(1000);
      }
      delay(2000);
    }
};
