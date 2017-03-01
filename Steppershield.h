#ifndef Steppershield_h
#define Steppershield_h

class Stepper
{
  public:
    Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2);
    void setSpeed(long whatSpeed);
    void step(int number_of_steps;
    void stepMotor(int this_step);
  private:
    int direction;
    unsigned long step_delay;
    int number_of_steps;
    int pin_count;
    int step_number;
    int motor_pin_1;
    int motor_pin_2;
    unsigned long last_step_time;
  };
  #endif
