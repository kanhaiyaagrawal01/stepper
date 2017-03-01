#include "Arduino.h"
#include "Stepper.h"

Stepper::Stepper(int number_of_steps,int motor_pin_1,int motor_pin_2)
{
  this->step_number=0;
  this->direction=0;
  this->last_step_time=0;
  this->number_of_steps=number_of_steps;
  this->motor_pin_1=motor_pin_1;
  this->motor_pin_2=motor_pin_2;
  pinMode(this->motor_pin_1,OUTPUT);
  pinMode(this->motor_pin_2,OUTPUT);
}
