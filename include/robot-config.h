using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LF;
extern motor LM;
extern motor RF;
extern motor RM;
extern motor LB;
extern motor RB;
extern motor Roller;
extern motor Wall;
extern digital_out Doinker;
extern digital_out Clamp;
extern digital_out Pistake;
extern motor PU;
extern inertial Gyro;

extern rotation LiftSensor;
extern optical Csen;
extern double LiftAngle;

extern const double wheelDiam;
extern const double wheelToMotorRatio;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );