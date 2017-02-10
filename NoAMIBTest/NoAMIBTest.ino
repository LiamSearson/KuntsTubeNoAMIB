#include <FlexyStepper.h>

const byte stepPinNumber = 34;
const byte directionPinNumber = 35;
const byte enablePinNumber = 33;

FlexyStepper stepper;

void setup() {
  stepper.connectToPins(stepPinNumber, directionPinNumber, enablePinNumber);
  
  stepper.setSpeedInStepsPerSecond(100);
  stepper.setAccelerationInStepsPerSecondPerSecond(100);
  
  stepper.enableStepper();
}

void loop() {
  stepper.setTargetPositionRelativeInSteps(100);
  while(!stepper.motionComplete()){
    stepper.processMovement();
  }
  
  stepper.setTargetPositionRelativeInSteps(-100);
  while(!stepper.motionComplete()){
    stepper.processMovement();
  }

}
