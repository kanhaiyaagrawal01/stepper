#include "Arduino.h"
#include "Steppershield.h"

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
void Stepper::setSpeed(long whatSpeed)
{
  this->step_delay=60L*1000L*1000L/this->number_of_steps/whatSpeed;
}
void Stepper::step(int steps_to_move)
{
  int steps_left=abs(steps_to_move);
  if((steps_to_move>0 && stepSpeed>0)||(steps_to_move<0 && stepSpeed<0))
    this->direction=1;
  if((steps_to_move>0 && stepSpeed<0)||(steps_to_move<0 && stepSpeed>0))
    this->direction=0;
  while(steps_left>0)
  {
    unsigned long now=micros();
    if( now - this->last_step_time >= this->step_delay)
    {
      this->last_step_time=now;
      if(this->direction==1)
      {
        this->step_number++;
        if(this->step_number == this->number_of_steps)
          this->step_number=0;
      }
      else
      {
        if(this->step_number==0)
          this->step_number=this->number_of_steps;
        this->step_number--;
      }
      steps_left--;
      stepMotor(this->step_number%4);
    }
  }
}
void Stepper::stepMotor(int thisStep)
{
  switch(thisStep)
  {
    case 0:
      digitalWrite(motor_pin_1,LOW);
      digitalWrite(motor_pin_2,LOW);
      break;
    case 1:
      digitalWrite(motor_pin_1,HIGH);
      digitalWrite(motor_pin_2,LOW);
      break;
    case 2:
      digitalWrite(motor_pin_1,HIGH);
      digitalWrite(motor_pin_2,HIGH);
      break;
    case 3:
      digitalWrite(motor_pin_1,LOW);
      digitalWrite(motor_pin_2,HIGH);
      break;
  }
}
