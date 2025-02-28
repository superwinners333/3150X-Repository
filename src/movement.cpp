#include "vex.h"

#include "math.h"
#include "screen_gui.hpp"
#include "helper_functions.hpp"
#include "movement.hpp"

#include <iostream>

using namespace vex;

int turninverse=-1;//change this to -1 if turning is inversed

int JB;
int PB;
int PX;
int JX;

//General Sect;
//This section includes all general codes for drive and auto


/** Resets the robot's drive train and inertial sensor
 * 
 * @param dist the 
 * @param HDG the
 */
void Zeroing(bool dist, bool HDG)
{
  if(dist){
  LF.resetPosition();
  LM.resetPosition();
  LB.resetPosition();
  RF.resetPosition();
  RM.resetPosition();
  RB.resetPosition();
  }
  if(HDG){
    Gyro.setHeading(0,degrees);
  }
}

ChassisDataSet ChassisUpdate()
{
  ChassisDataSet CDS;
  CDS.Left=get_dist_travelled((LF.position(degrees)+LM.position(degrees)+LB.position(degrees))/3.0);
  CDS.Right=get_dist_travelled((RF.position(degrees)+RM.position(degrees)+RB.position(degrees))/3.0);
  CDS.Avg=(CDS.Left+CDS.Right)/2;
  CDS.Diff=CDS.Left-CDS.Right;
  CDS.HDG=Gyro.heading(degrees);

  return CDS;
}

void Move(int left, int right)
{
LF.setMaxTorque(100,percent);
LM.setMaxTorque(100,percent);
LB.setMaxTorque(100,percent);
RF.setMaxTorque(100,percent);
RM.setMaxTorque(100,percent);
RB.setMaxTorque(100,percent);

LF.spin(forward,(double)left/100.0*11,volt);
LM.spin(forward,(double)left/100.0*11,volt);
LB.spin(forward,(double)left/100.0*11,volt);
RF.spin(forward,(double)right/100.0*11,volt);
RM.spin(forward,(double)right/100.0*11,volt);
RB.spin(forward,(double)right/100.0*11,volt);
}

void BStop()
{
LF.setStopping(brake);
LM.setStopping(brake);
LB.setStopping(brake);
RF.setStopping(brake);
RM.setStopping(brake);
RB.setStopping(brake);

LF.stop();
LM.stop();
LB.stop();
RF.stop();
RM.stop();
RB.stop();
}

void CStop()
{
LF.setStopping(coast);
LM.setStopping(coast);
LB.setStopping(coast);
RF.setStopping(coast);
RM.setStopping(coast);
RB.setStopping(coast);

LF.stop();
LM.stop();
LB.stop();
RF.stop();
RM.stop();
RB.stop();
}


void RunRoller(int val)
{
Roller.setMaxTorque(100,percent);
Roller.spin(forward,(double)val/100.0*12,volt);
}

// =================================================================================== //
int ColourIntakeSpeed = 0;
bool AutoSort = false;
void ColourSort(int colour)
{
  int pauser = 0;
  int Eject = 0;
  float olddegree = 0;
  bool isColour;
  while (AutoSort) {
    // Improved color detection logic
    Csen.setLight(ledState::on);
    Csen.setLightPower(100, percent);
    int hue = Csen.hue();

    if (colour == 0){ // red
      isColour = (hue >= 0 && hue <= 48);
    }
    if (colour == 1){ // blue
      isColour = (hue >= 205 && hue <= 220);
    }
    else { // also red
      isColour = (hue >= 0 && hue <= 48);
    }

    // Check if an object is detected and it's the desired color
    if (isColour && Csen.isNearObject() == 1 && Eject == 0) {
      olddegree = Roller.position(degrees) + 440; // 410
      Eject = 1;
      pauser = 1;
    }

    if (Eject == 0) {
      RunRoller(ColourIntakeSpeed);
    }

    // Eject mechanism to launch the ring
    while (Eject == 1) {
      while (Roller.position(degrees) < olddegree){
        RunRoller(100);
      }
      if (pauser == 1){
        olddegree = Roller.position(degrees) - 170;
        pauser = 0;
      }

      while (Roller.position(degrees) > olddegree && Eject == 1){
        RunRoller(-20);
        if (Roller.position(degrees) <= olddegree) {
          RunRoller(0);
          Eject = 0;
        }
      }
    }

    // Small delay to prevent CPU overload
    wait(10, msec);
  }
}
// ========================================================================================= //

int RunArms(int val)
{
  Wall.setMaxTorque(100,percent);
  Wall.spin(forward,(double)val/100.0*12,volt);
  Wall.setStopping(hold);
  return 0;
}
void StopArms(void)
{
  Wall.setStopping(hold);
  Wall.stop();
}
void RestrictArms(void)
{
  if(abs(LiftSensor.position(degrees)) > 25)
  {
    Wall.stop();
  } 
}

// ========================================================================================= //

void Macro(void)
{
  int MacroActiv = 1;

  while(MacroActiv==1) {
    
    if(abs(LiftSensor.position(degrees)) < 24.5) { // 32
      RunArms(40);
      if(abs(LiftSensor.position(degrees)) > 19.5) { // 25
        MacroActiv = 0;
        StopArms();
      }
    } 
    else if(abs(LiftSensor.position(degrees)) > 24.5) { // 25
      RunArms(-40);
      if(abs(LiftSensor.position(degrees)) <  19.5) { // 32
        MacroActiv = 0;
        StopArms();
      }
    } 
  }
}

void PID_Macro(void) {
  int targetPosition = 21.5;  // Desired position between 324 and 342 degrees
  double integral = 0.0;     // Integral term
  double previousError = 0.0; // Previous error for derivative calculation
  double Kp = -0.5;           // Proportional gain (adjust as needed)
  double Ki = 0.1;            // Integral gain (adjust as needed)
  double Kd = 0.1;            // Derivative gain (adjust as needed)
  bool MacroActiv2 = true;

  while (MacroActiv2) {
    int currentPos = abs(LiftSensor.position(degrees));
    double error = targetPosition - currentPos;

    // Calculate integral term
    integral += error;

    // Calculate derivative term
    double derivative = error - previousError;

    // PID calculation
    double liftPower = Kp * error + Ki * integral + Kd * derivative;

    // Limit the power to within motor capabilities
    if (liftPower > 100) liftPower = 100;
    if (liftPower < -100) liftPower = -100;

    // Ensure minimum power to overcome static friction
    if (liftPower > 0 && liftPower < 40) liftPower = 40;
    if (liftPower < 0 && liftPower > -40) liftPower = -40;

    RunArms(-liftPower);

    // Stop the lift when close enough to the target
    if (abs(error) <= 2) {
      RunArms(0);
      MacroActiv2 = false;
    }

    // Update previous error
    previousError = error;

  }
  // Prevent CPU overload
  wait(10, msec);
}



int PrevE;//Error at t-1

/** Moves the robot forward or backward. Negative speed moves
 * the robot forward. Positive value moves it backward. (Ik it's fucked up)
 * @param KVals the PID constants
 * @param Speed the speed, from -100 to 100
 * @param dist distance travelled, in inches
 * @param AccT time to max speed (s)
 * @param ABSHDG absolute heading of the robot
 * @param brake Brake at end, or coast
 */
void MoveEncoderPID(PIDDataSet KVals, int Speed, double dist,double AccT, double ABSHDG,bool brake){
  double CSpeed=0;
  Zeroing(true,false);
  ChassisDataSet SensorVals;
  SensorVals=ChassisUpdate();
  double PVal=0;
  double IVal=0;
  double DVal=0;
  double LGV=0;//define local gyro variable.
  PrevE=0;
  double Correction=0;
  Brain.Screen.clearScreen();

  while(fabs(SensorVals.Avg) <= fabs(dist))
  {
    //std::cout << SensorVals.Avg << " " << dist << std::endl;
if(fabs(CSpeed)<fabs((double)Speed))
{
  CSpeed+=Speed/AccT*0.02;
}

  SensorVals=ChassisUpdate();
  LGV=SensorVals.HDG-ABSHDG;
  if(LGV>180) LGV=LGV-360;
  PVal=KVals.kp*LGV;
  IVal=IVal+KVals.ki*LGV*0.02;
  DVal=KVals.kd*(LGV-PrevE);

  Correction=PVal+IVal+DVal/0.02;

  Move(CSpeed+Correction,CSpeed-Correction);
  PrevE=LGV;
  wait(20, msec);
  }
  if(brake){
    BStop();
    wait(120,msec);
  }
  else CStop();
}

/** Moves the robot forward or backward. Negative speed moves
 * the robot forward. Positive value moves it backward. (Ik it's fucked up)
 * @param KVals the PID constants
 * @param DeltaAngle the absolute heading to turn to
 * @param TE time to calculate turn (not time to turn)
 * @param brake Brake at end, or coast
 */
void TurnMaxTimePID(PIDDataSet KVals,double DeltaAngle,double TE, bool brake){
  double CSpeed=0;
  Zeroing(true,false);
  ChassisDataSet SensorVals;
  SensorVals=ChassisUpdate();
  double PVal=0;
  double IVal=0;
  double DVal=0; 
  double LGV=0;
  PrevE=0;
  double Correction=0;
  Brain.Timer.reset();

  while(Brain.Timer.value() <= TE)
  {
  SensorVals=ChassisUpdate();
  LGV=SensorVals.HDG-DeltaAngle;
  if(LGV>180) LGV=LGV-360;
  PVal=KVals.kp*LGV;
  IVal=IVal+KVals.ki*LGV*0.02;
  DVal=KVals.kd*(LGV-PrevE);

  Correction=PVal+IVal+DVal/0.02;

  Move(CSpeed+Correction,CSpeed-Correction);
  PrevE=LGV;
  wait(20, msec);
  }
  if(brake){BStop();
  wait(180,msec);}
  else CStop();
}

void MaxTimePIDTurnOneSide(PIDDataSet KVals,double DeltaAngle,double TE, bool brake){
  double CSpeed=0;
  Zeroing(true,false);
  ChassisDataSet SensorVals;
  SensorVals=ChassisUpdate();
  double PVal=0;
  double IVal=0;
  double DVal=0;
  double LGV=0;
  PrevE=0;
  double Correction=0;
  double LV,RV;
  Brain.Timer.reset();

  while(Brain.Timer.value() <= TE)
  {
  SensorVals=ChassisUpdate();
  LGV=SensorVals.HDG-DeltaAngle;
  if(LGV>180) LGV=LGV-360;
  PVal=KVals.kp*LGV;
  IVal=IVal+KVals.ki*LGV*0.02;
  DVal=KVals.kd*(LGV-PrevE);

  Correction=PVal+IVal+DVal/0.02;
LV=-CSpeed-Correction;
RV=-CSpeed+Correction;
if(LV>=0)LV=0;
if(RV>=0)RV=0;
  Move(LV,RV);
  PrevE=LGV;
  wait(20, msec);
  }
  if(brake){BStop();
  wait(200,msec);}
  else CStop();
}


void MoveTimePID(PIDDataSet KVals, int Speed, double TE,double AccT,double ABSHDG, bool brake){
  double CSpeed=0;
  Zeroing(true,false);
  ChassisDataSet SensorVals;
  SensorVals=ChassisUpdate();
  double PVal=0;
  double IVal=0;
  double DVal=0;
  double LGV=0;
  PrevE=0;
  double Correction=0;
  Brain.Timer.reset();

  while(Brain.Timer.value() <= TE)
  {
if(fabs(CSpeed)<fabs((double)Speed))
{
  CSpeed+=Speed/AccT*0.02;
}

  SensorVals=ChassisUpdate();
    LGV=SensorVals.HDG-ABSHDG;
  if(LGV>180) LGV=LGV-360;
  PVal=KVals.kp*LGV;
  IVal=IVal+KVals.ki*LGV*0.02;
  DVal=KVals.kd*(LGV-PrevE);

  Correction=PVal+IVal+DVal/0.02;

  Move(-CSpeed+Correction,-CSpeed-Correction);
  PrevE=LGV;
  wait(20, msec);
  }
  if(brake){BStop();
  wait(200,msec);}
  else CStop();
}
