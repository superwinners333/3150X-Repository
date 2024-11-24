#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
// left drivetrain
motor LF = motor(PORT8, ratio6_1, false);
motor LM = motor(PORT9, ratio6_1, false);
motor LB = motor(PORT10, ratio6_1, false);
// right drivetrain
motor RF = motor(PORT5, ratio6_1, true);
motor RM = motor(PORT6, ratio6_1, true);
motor RB = motor(PORT7, ratio6_1, true);
// other motors
motor Roller = motor(PORT12, ratio6_1, false);
motor Wall = motor(PORT15, ratio36_1, false);
digital_out Pistake = digital_out(Brain.ThreeWirePort.C);
digital_out Doinker = digital_out(Brain.ThreeWirePort.B);
digital_out Clamp = digital_out(Brain.ThreeWirePort.A);
rotation LiftSensor = rotation(PORT15, true);
int LiftAngle = LiftSensor.angle(); // IMPORTANT

inertial Gyro = inertial(PORT2);
// Important variables
const double wheelDiam = 2.75;
const double wheelToMotorRatio = 36.0/48;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}