#include "LegServo.h"
class Leg {
  private:

  public:
    ForwardServo servox;
    HeightServo servoy;
    Leg(ForwardServo servo1, HeightServo servo2) {
      servox = servo1;
      servoy = servo2;
    }
    void move(int x_pos, int y_pos) {
      int current_x = servox.get_pos();
      int current_y = servoy.get_pos();
      
      int delta_x = x_pos - current_x;
      int delta_y = y_pos - current_y;

      int increment_x = delta_x > 0 ? 1 : -1;
      int increment_y = delta_y > 0 ? 1 : -1;

      while (current_x != x_pos || current_y != y_pos) {
        if (current_x != x_pos) {
          current_x += increment_x;
          servox.set_pos(current_x);
          servox.move();
        }
        if (current_y != y_pos) {
          current_y += increment_y;
          servoy.set_pos(current_y);
          servoy.move();
        }
      }
    }
    void forward(int val = 1){
      int forward_pos = servox.get_pos();
      while ( abs(forward_pos - servox.get_max()) > 1 ){
          servox.forward(val);
          delay(5);
      }
    }
    void up(int val = 1){
      int height_pos = servoy.get_pos();
      while( abs(height_pos - servoy.get_max()) > 1) {
        servoy.up(val);
        delay(5);
      }
    }
    void backwards(int val = 1){
      int backwards_pos = servox.get_pos();
      while ( abs(backwards_pos - servox.get_min()) > 1){
          servox.backwards(val);
          delay(5);
      }
    }

    void down(int val = 1){
      int height_pos = servoy.get_pos();
      while(abs(height_pos != servoy.get_min()) > 1) {
        servoy.down(val);
        delay(5);
      }
    }

    ForwardServo get_forward_servo(){
      return servox;
    }

    HeightServo get_height_servo(){
      return servoy;
    }

    void insta_move(int x_pos, int y_pos){
      servox.set_pos(x_pos).move();
      servoy.set_pos(y_pos).move();
    }
};

class LeftLeg : public Leg {
  public:
    LeftLeg():Leg(ForwardServo(), HeightServo()) {};
    LeftLeg(ForwardServo servo1, HeightServo servo2) : Leg(servo1, servo2) {}
    void move(int x_pos, int y_pos) {
      int current_x = servox.get_pos();
      int current_y = servoy.get_pos();
      
      int delta_x = x_pos - current_x;
      int delta_y = y_pos - current_y;

      int increment_x = delta_x > 0 ? 1 : -1;
      int increment_y = delta_y > 0 ? 1 : -1;

      while (current_x != x_pos || current_y != y_pos) {
        if (current_x != x_pos) {
          current_x += increment_x;
          servox.set_pos(current_x).move();
        }
        if (current_y != y_pos) {
          current_y += increment_y;
          servoy.set_pos(current_y).move();
        }
      }
    }
  

};

class RightLeg : public Leg {
  public:
    RightLeg():Leg(ForwardServo(), HeightServo()) {};
    RightLeg(ForwardServo servo1, HeightServo servo2) : Leg(servo1, servo2) {}
    void move(int x_pos, int y_pos) {
      int current_x = servox.get_pos();
      int current_y = servoy.get_pos();
      
      int delta_x = x_pos - current_x;
      int delta_y = y_pos - current_y;

      int increment_x = delta_x > 0 ? 1 : -1;
      int increment_y = delta_y > 0 ? 1 : -1;

      while (current_x != x_pos || current_y != y_pos) {
        if (current_x != x_pos) {
          current_x -= increment_x;
          servox.set_pos(current_x).move();
        }
        if (current_y != y_pos) {
          current_y -= increment_y;
          servoy.set_pos(current_y).move();
        }
      }
    }
};