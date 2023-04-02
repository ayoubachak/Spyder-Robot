#include "Leg.h" 

class Spyder {
  private:
    LeftLeg left_legs[3];
    RightLeg right_legs[3];

    // Move the legs in a way that the Spyder moves forward
    LeftLeg middle_left_leg;
    RightLeg front_right_leg;
    RightLeg back_right_leg;

    RightLeg middle_right_leg;
    LeftLeg front_left_leg;
    LeftLeg back_left_leg;

    ForwardServo middle_left_FS;
    ForwardServo front_right_FS;
    ForwardServo back_right_FS;

    ForwardServo middle_right_FS;
    ForwardServo front_left_FS;
    ForwardServo back_left_FS;

    HeightServo middle_left_HS;
    HeightServo front_right_HS;
    HeightServo back_right_HS;

    HeightServo middle_right_HS;
    HeightServo front_left_HS;
    HeightServo back_left_HS;
  public:
    float speed;
    float height;
    bool started = false;
    String direction;
    Spyder () {};
    Spyder(LeftLeg spyder_left_legs[], RightLeg spyder_right_legs[]) {
      for (int i = 0; i < 3; i++) {
        left_legs[i] = spyder_left_legs[i];
        right_legs[i] = spyder_right_legs[i];
      }

      // Move the legs in a way that the Spyder moves forward
      middle_left_leg = left_legs[1];
      front_right_leg = right_legs[0];
      back_right_leg = right_legs[2];

      middle_right_leg = right_legs[1];
      front_left_leg = left_legs[0];
      back_left_leg = left_legs[2];

      // first we have to go forward with the leg up
      middle_left_FS = middle_left_leg.get_forward_servo();
      front_right_FS = front_right_leg.get_forward_servo();
      back_right_FS = back_right_leg.get_forward_servo();

      // seconds we get the height servos
      middle_left_HS = middle_left_leg.get_height_servo();
      front_right_HS = front_right_leg.get_height_servo();
      back_right_HS = back_right_leg.get_height_servo();
      
      // first we have to go forward with the leg up
      middle_right_FS = middle_right_leg.get_forward_servo();
      front_left_FS = front_left_leg.get_forward_servo();
      back_left_FS = back_left_leg.get_forward_servo();

      // seconds we get the height servos
      middle_right_HS = middle_right_leg.get_height_servo();
      front_left_HS = front_left_leg.get_height_servo();
      back_left_HS = back_left_leg.get_height_servo();



    }
    
    void init(){
       // set the positions to middle
      // forward servos 
      middle_left_FS.set_position_middle();
      front_right_FS.set_position_middle();
      back_right_FS.set_position_middle();
      delay(1000);
      // height servos
      middle_left_HS.set_position_middle();
      front_right_HS.set_position_middle();
      back_right_HS.set_position_middle();
      delay(1000);
      // forward servos 
      middle_right_FS.set_position_middle();
      front_left_FS.set_position_middle();
      back_left_FS.set_position_middle();
      delay(1000);
      // height servos
      middle_right_HS.set_position_middle();
      front_left_HS.set_position_middle();
      back_left_HS.set_position_middle();
      delay(1000);

    }
    void g1_forward(int val = 5){
      while ( (abs(middle_left_FS.get_pos() - middle_left_FS.get_max()) > 1) ||  (abs(front_right_FS.get_pos() - front_right_FS.get_max()) > 1) || (abs(back_right_FS.get_pos() - back_right_FS.get_max()) > 1) ){
        middle_left_FS.forward(val);
        front_right_FS.forward(val);
        back_right_FS.forward(val);
      }
    }

    void g1_down(int val = 5){
      while ( (abs(middle_left_HS.get_pos() - middle_left_HS.get_min()) > 1) ||  (abs(front_right_HS.get_pos() - front_right_HS.get_max()) > 1) || (abs(back_right_HS.get_pos() - back_right_HS.get_max()) > 1)){
        middle_left_HS.down(val);
        front_right_HS.up(val);
        back_right_HS.up(val);
      }
    }

  void g1_backwards(int val = 5){
      while ((abs(middle_left_FS.get_pos() - middle_left_FS.get_min()) > 1) ||  (abs(front_right_FS.get_pos() - front_right_FS.get_min()) > 1) || (abs(back_right_FS.get_pos() - back_right_FS.get_min()) > 1)){
        middle_left_FS.backwards(val);
        front_right_FS.backwards(val);
        back_right_FS.backwards(val);
      }
  }
  void g1_up(int val = 5){
      while ((abs(middle_left_HS.get_pos() - middle_left_HS.get_max()) > 1) ||  (abs(front_right_HS.get_pos() - front_right_HS.get_min()) > 1) || (abs(back_right_HS.get_pos() - back_right_HS.get_min()) > 1)){
        middle_left_HS.up(val);
        front_right_HS.down(val);
        back_right_HS.down(val);
      }
  }

  
    void g2_forward(int val = 5){
      while ( (abs(middle_right_FS.get_pos() - middle_right_FS.get_max()) > 1) ||  (abs(front_left_FS.get_pos() - front_left_FS.get_max()) > 1) || (abs(back_left_FS.get_pos() - back_left_FS.get_max()) > 1) ){
        middle_right_FS.forward(val);
        front_left_FS.forward(val);
        back_left_FS.forward(val);
      }
    }

    void g2_up(int val = 5){
      while ( (abs(middle_right_HS.get_pos() - middle_right_HS.get_min()) > 1) ||  (abs(front_left_HS.get_pos() - front_left_HS.get_max()) > 1) || (abs(back_left_HS.get_pos() - back_left_HS.get_max()) > 1) ){
        middle_right_HS.down(val);
        front_left_HS.up(val);
        back_left_HS.up(val);
      }
    }

  void g2_backwards(int val = 5){
      while ((abs(middle_right_FS.get_pos() - middle_right_FS.get_min()) > 1) ||  (abs(front_left_FS.get_pos() - front_left_FS.get_min()) > 1) || (abs(back_left_FS.get_pos() - back_left_FS.get_min()) > 1)){
        middle_right_FS.backwards(val);
        front_left_FS.backwards(val);
        back_left_FS.backwards(val);
      }    
  }
  void g2_down(int val = 5){
      while ((abs(middle_right_HS.get_pos() - middle_right_HS.get_max()) > 1) ||  (abs(front_left_HS.get_pos() - front_left_HS.get_min()) > 1) || (abs(back_left_HS.get_pos() - back_left_HS.get_min()) > 1)){
        middle_right_HS.up(val);
        front_left_HS.down(val);
        back_left_HS.down(val);
      }
  }

    void init_forward(int val = 5){
      g1_up(val);
      Serial.println("G1 up..");
      g1_forward(val);
      Serial.println("G1 forward..");

    }
    void move_forward(int val = 5) { 
      // init_forward();
      g1_down(val);
      Serial.println("G1 down..");
      g2_up(val);
      Serial.println("G2 up..");
      g1_backwards(val);
      Serial.println("G1 backwards..");
      g2_forward(val);
      Serial.println("G2 forward..");
      g2_down(val);
      Serial.println("G2 down..");
      g1_up(val);
      Serial.println("G1 up..");
      g2_backwards(val);
      Serial.println("G2 backwards..");
      g1_down(val);
      Serial.println("G1 down..");
    }

};
