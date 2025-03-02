/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

//#include "STDLib.cpp"
#include "vex.h"

#include "screen_gui.hpp"
#include "movement.hpp"
#include "routes/routes.hpp"
#include "math.h"

#include <iostream>
using namespace vex;


// A global instance of competition
competition Competition;


// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

bool SP;
bool EXIT;
void pre_auton(void) {
   EXIT=false;
  Doinker.set(false);
  Clamp.set(false);
  Pistake.set(false);
  RightDoinker.set(false);
  PX=0;
  JX=0;
  AutoSelectorVal=0;
  OtherCodes=false; // wack
  SP=false;
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
Gyro.calibrate();
LiftSensor.setPosition(1.0, degrees);

//Ensure Robot Launch Position is set before auto proceeds, once plugged into field control,
//start program and do not temper bot under all circumstances

//1. IF ANY ADJUSTMENT IS NEEDED, QUIT PROGRAM, THEN ADJUST, RESTART PROGRAM AFTER ADJUSTMENTS COMPLETED
//2. DO NOT START PROGRAM BEFORE PLUGGING IN FIELD CONTROL, THIS MAY DISABLE AUTO
//3. ONLY SIGNAL JUDGES TO BEGIN MATCH AFTER THE ZEROING PROMPT ON SCREEN HAS CLEARED

//Print precautionary message
Brain.Screen.drawRectangle(0,0,500,500);

Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.setCursor(2,10);
Brain.Screen.print("FLIR TIMEOUT");


waitUntil(!Gyro.isCalibrating());


Zeroing(true,true);
DisplayAutoSelector();
DisplayWords();

//task AutoSelTask=task(ScreenSelMain);
  while(!EXIT)
{
if(Brain.Screen.xPosition()<100)
{
if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=1;
else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=3;
else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=5;
}
else if(Brain.Screen.xPosition()>375)
{
if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=2;
else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=4;
else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=6;
}

if(Brain.Screen.xPosition()>187&&Brain.Screen.xPosition()<287)
{
  if(Brain.Screen.yPosition()<55&&Brain.Screen.yPosition()>5) EXIT=true;

  else if(Brain.Screen.yPosition()>125&&Brain.Screen.yPosition()<225) // SKETCHY STUFF BELOW
  {
    AutoSelectorVal=7;
    if (OtherCodes)
    {
      OtherCodes = false;
    }
    else OtherCodes = true;
  }
}

if(Brain.Screen.pressing()&&!SP) UpdateDynamic();

SP=Brain.Screen.pressing();

}

Brain.Screen.clearScreen();
// ---------------------------------------------------------------- //
if(AutoSelectorVal==1){ // Blue Positive and Blue Corner Clear
  if (!OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Blue Positive");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE+");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Blue Corner Clear");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE+");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==2){ // Blue Solo AWP and Blue Ring Rush
  if (!OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Solo AWP");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE-");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Blue Ring Rush");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE-");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FFC0CB");
  }

}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==3){ // Blue Negative and Blue "Six" Ring
  if (!OtherCodes) {
  Brain.Screen.setFillColor(black);
  Brain.Screen.setFont(monoXL);
  Brain.Screen.setPenColor("#FFC0CB");
  Brain.Screen.setCursor(3,10);
  Brain.Screen.print("Blue Negative");
  Brain.Screen.setCursor(4,10);
  Brain.Screen.print("BLUE-");
  Brain.Screen.setFont(monoM);  
  Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes) {
  Brain.Screen.setFillColor(black);
  Brain.Screen.setFont(monoXL);
  Brain.Screen.setPenColor("#FFC0CB");
  Brain.Screen.setCursor(3,10);
  Brain.Screen.print("Six Blue");
  Brain.Screen.setCursor(4,10);
  Brain.Screen.print("BLUE-");
  Brain.Screen.setFont(monoM);  
  Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==4){ // Red Positive and Red Corner Clear
  if (!OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Red Positive");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED+");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Red Corner Clear");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED+");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
  
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==5){ // Red Negative and Red "Six" Ring
  if (!OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Red Negative");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED-");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB"); 
  }
  if (OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Six Red");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED-");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==6){ // Red Solo AWP and Red Ring Rush
  if (!OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Solo AWP");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED-");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Red Ring Rush");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED-");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==7){
  Brain.Screen.setFillColor(black);
  Brain.Screen.setFont(monoXL);
  Brain.Screen.setPenColor("#FFC0CB");
  Brain.Screen.setCursor(3,10);
  Brain.Screen.print("SKILLS");
  Brain.Screen.setCursor(4,10);
  Brain.Screen.print("SKILLS");
  Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#FFC0CB");
}

Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.setCursor(5,10);
Brain.Screen.print("AUTO CONFIRMED");



  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

//Do not change the below
PIDDataSet TestPara={4,0.1,0.2};
Zeroing(true,true);

//can start editing if nessary
//Put Auto route function into if statements to use autoselector
if(AutoSelectorVal==1)// Blue 4 Ring
{
  if (!OtherCodes) blue_positive();
  else if (OtherCodes) blue_corner_clear();
}

if(AutoSelectorVal==2)// Blue Solo AWP
{
  if (!OtherCodes) blue_solo_awp();
  else if (OtherCodes) blue_rush();
}

if(AutoSelectorVal==3)// Blue 5 / 6 Ring
{
  if (!OtherCodes) blue_negative();
  else if (OtherCodes) six_blue();
} 

if(AutoSelectorVal==4)// Red 4 Ring
{
  if (!OtherCodes) red_positive();
  else if (OtherCodes) red_corner_clear();
}

if(AutoSelectorVal==5)// Red 5 / 6 Ring
{
  if (!OtherCodes) red_negative();
  else if (OtherCodes) six_red();
}


if(AutoSelectorVal==6)// Red Solo AWP
{
  if (!OtherCodes) red_solo_awp();
  else if (OtherCodes) red_rush();
}


if(AutoSelectorVal==7)//temporary prog skills
{ 
  prog_skills();
}
//MoveTimePID(TestPara, -100, 0.5,0.1,-40,true);//score 2nd triball
//(PID Parameters, motor speed -100 - 100, time for travel 0 - inf, time to accelerate to full speed, Absolute Heading, Braking?)

    // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
CStop();
}
int RV;
int LV;
bool driving = true;
int ButtonPressingDown, DownTaskActiv;
bool firstClick=true;
bool Running=false;
bool LastStat;
bool BackwardsToggle = false;
ChassisDataSet SensorVals2;

int DriveTask(void){
  while(true)
  {
    EXIT=true;
    // if(Controller1.ButtonDown.pressing()) BackwardsToggle = true;
    // else if(!Controller1.ButtonDown.pressing() && BackwardsToggle) {
    //   BackwardsToggle = false;
    //   Move(60,60);
    //   wait(150,msec);
    //   Move(0,0);
    // }

    // if(Controller1.ButtonDown.pressing()||Running) {

    //     if(!LastStat&&!Running)
    //     {Zeroing(true,true);
    //       firstClick=false;
    //     }
    //     SensorVals2=ChassisUpdate();
    //     if(fabs(SensorVals2.Avg) <= fabs(4.5))//Tune the number in fabs()
    //     {
    //       Running=true;
    //       SensorVals2=ChassisUpdate();
    //       //std::cout << SensorVals.Avg << " " << dist << std::endl;    
      
    //     Move(100,100);
    //     }
    //     else{
    //       Running=false;
    //       Move(0,0);
    //     firstClick=true;}
       
    // }

    // else{
    RV=-Controller1.Axis3.position(percent)+Controller1.Axis1.position(percent);
    LV=-Controller1.Axis3.position(percent)-Controller1.Axis1.position(percent);
    Move(LV,RV); 
    // }
    LastStat=Controller1.ButtonDown.pressing();
  }

return 0;
}
int V;

int ATask(void)
{
  double pow;
    while(true)
  {
    pow=((Controller1.ButtonR2.pressing()-Controller1.ButtonR1.pressing())*100);//Calculate intake power, if button pressed, button.pressing returns 1
    RunRoller(-pow);

  //RunPuncher((Controller1.ButtonB.pressing())*100);
  }
  return 0;
}

float olddegree = 0;
int Eject = 0;
int pauser = 0;
bool Csort = true;

int ITask(void) {
  
  double pow;
  using namespace std;

  while (Csort) {

      // Improved color detection logic
      Csen.setLight(ledState::on);
      Csen.setLightPower(100, percent);
      int hue = Csen.hue();
      bool isRed = (hue >= 0 && hue <= 48);
      bool isBlue = (hue >= 205 && hue <= 220);

      // Check if an object is detected and it's the desired color
      if (isRed && Csen.isNearObject() == 1 && Eject == 0) {
        olddegree = Roller.position(degrees) + 440; // 410
        Eject = 1;
        pauser = 1;
        std::cout << Roller.position(degrees) << endl;
        std::cout << olddegree << endl;
      }

      if (Eject == 0) {
        pow = ((Controller1.ButtonR2.pressing() - Controller1.ButtonR1.pressing()) * 100);
        RunRoller(-pow);
      }

      // Eject mechanism to "yeet" the ring
      while (Eject == 1 && Csort) {
        while (Roller.position(degrees) < olddegree && Csort){
          RunRoller(100);
        }
        if (pauser == 1){
          olddegree = Roller.position(degrees) - 170;
          pauser = 0;
        }
        
        std::cout << Roller.position(degrees) << endl;
        std::cout << olddegree << endl;

        while (Roller.position(degrees) > olddegree && Eject == 1 && Csort){
          RunRoller(-20);
          if (Roller.position(degrees) <= olddegree || Csort == false) {
            RunRoller(0);
            Eject = 0;
          }
        }
        // if (Csort) Eject = 0;
      }

      // std::cout << Roller.position(degrees) << endl;
      // std::cout << olderdegree << endl;

      // Small delay to prevent CPU overload
      wait(10, msec);
  }
  return 0;
}
// -----------------------------------------------------------------------------------------------


int ButtonPressingX,XTaskActiv;
int ButtonPressingY,YTaskActiv;
int ButtonPressingA,ATaskActiv;
int ButtonPressingB,BTaskActiv;
int ButtonPressingUp,UpTaskActiv;

int ButtonPressingLeft, LeftTaskActiv;
int ButtonPressingRight, RightTaskActiv;

bool MacroToggle = false;
int ArmDistance;

// bool Csort = true;

int PTask(void)
{
  while(true)
  {
    // TOGGLES CLAMP ---------------------------------------------------------------
    if(XTaskActiv==0&&Controller1.ButtonX.pressing()&&ButtonPressingX==0)
    {
      ButtonPressingX=1;
      XTaskActiv=1;
      Clamp.set(true);
    }

    else if(!Controller1.ButtonX.pressing()) ButtonPressingX=0;

    else if(XTaskActiv==1&&Controller1.ButtonX.pressing()&&ButtonPressingX==0)
    {
      ButtonPressingX=1;
      XTaskActiv=0;
      Clamp.set(false);
    }

    // TOGGLES DOINKER ---------------------------------------------------------------
    if(BTaskActiv==0&&Controller1.ButtonB.pressing()&&ButtonPressingB==0)
    {
      ButtonPressingB=1;
      BTaskActiv=1;
      Doinker.set(true);
    }

    else if(!Controller1.ButtonB.pressing()) ButtonPressingB=0;

    else if(BTaskActiv==1&&Controller1.ButtonB.pressing()&&ButtonPressingB==0)
    {
      ButtonPressingB=1;
      BTaskActiv=0;
      Doinker.set(false);
    }

    // TOGGLES COLOUR SORT ---------------------------------------------------------------
    if(UpTaskActiv==0&&Controller1.ButtonUp.pressing()&&ButtonPressingUp==0)
    {
      ButtonPressingUp=1;
      UpTaskActiv=1;
      Csort = true;

      Controller1.Screen.clearLine(1);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("SORT ON");
    }

    else if(!Controller1.ButtonUp.pressing()) ButtonPressingUp=0;

    else if(UpTaskActiv==1&&Controller1.ButtonUp.pressing()&&ButtonPressingUp==0)
    {
      ButtonPressingUp=1;
      UpTaskActiv=0;
      Csort = false;
      Controller1.rumble(".");

      Controller1.Screen.clearLine(1);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("SORT OFF");
    }

    // RIGHT DOINKER BUTTON ------------------------------------------------------------------
    if(RightTaskActiv==0&&Controller1.ButtonRight.pressing()&&ButtonPressingRight==0)
    {
      ButtonPressingRight=1;
      RightTaskActiv=1;
      RightDoinker.set(true);
    }

    else if(!Controller1.ButtonRight.pressing()) ButtonPressingRight=0;

    else if(RightTaskActiv==1&&Controller1.ButtonRight.pressing()&&ButtonPressingRight==0)
    {
      ButtonPressingRight=1;
      RightTaskActiv=0;
      RightDoinker.set(false);
    }

    // SHUT DOWN ALL AUTON THINGS ---------------------------------------------------------
    if(LeftTaskActiv==0&&Controller1.ButtonLeft.pressing()&&ButtonPressingLeft==0)
    {
      ButtonPressingLeft=1;
      LeftTaskActiv=1;
      // RightDoinker.set(false);
      AutoSort = false;
      Pistake.set(false);
    }

    else if(!Controller1.ButtonLeft.pressing()) ButtonPressingLeft=0;

    else if(LeftTaskActiv==1&&Controller1.ButtonLeft.pressing()&&ButtonPressingLeft==0)
    {
      ButtonPressingLeft=1;
      LeftTaskActiv=0;
      RightDoinker.set(false);
      AutoSort = false;
      Pistake.set(false);
    }

  }
}

int BTask(void) {
  int pow1 = 0;
  int targetPosition = 21.5;  // Desired position between 324 and 342 degrees
  double integral = 0.0;     // Integral term
  double previousError = 0.0; // Previous error for derivative calculation
  double Kp = -0.5;           // Proportional gain (adjust as needed)
  double Ki = 0.1;            // Integral gain (adjust as needed)
  double Kd = 0.1;            // Derivative gain (adjust as needed)

  while (true) {
    if (YTaskActiv == 1) {
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
        YTaskActiv = 0;
      }

      // Update previous error
      previousError = error;

    } else {
      // Invert manual control power
      pow1=(Controller1.ButtonL1.pressing()-Controller1.ButtonL2.pressing())*100;

      if (pow1 == 0) {
        Wall.setStopping(hold);
        Wall.stop();
      } else {
        if((pow1 < 0 && abs(LiftSensor.position(degrees)) < 4) || (pow1 > 0 && abs(LiftSensor.position(degrees)) > 250)){
          Wall.setStopping(hold);
          Wall.stop();
        }
        else {
          RunArms(pow1);
        }   
      }
    }

    // Handle Button A presses
    if (Controller1.ButtonY.pressing() && ButtonPressingY == 0) {
      ButtonPressingY = 1;
      YTaskActiv = 1;
    } else if (!Controller1.ButtonY.pressing()) {
      ButtonPressingY = 0;
    }

    // Override if BTaskActiv is active
    if (YTaskActiv == 1 && Controller1.ButtonY.pressing() && ButtonPressingY == 0) {
      ButtonPressingY = 1;
      YTaskActiv = 0;
      RunArms(0);
    }

    // Prevent CPU overload
    wait(10, msec);
  }
  return 0;
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


void usercontrol(void) {
  EXIT=true;//Force Exit Autosel once drivercontrol began.
  // User control code here, inside the loop
  Brain.Timer.clear(); // resets brain timer
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    
    
    // if (Csort == true) {
    //   task Itask=task(ITask);
    // }
    // else {
    //   task Atask=task(ATask);
    // }
    // task Ptask=task(PTask);
    // task Btask=task(BTask);
    
    task Dtask=task(DriveTask);

    if (Csort == true) {
      task Itask=task(ITask);
    }
    else {
      task Atask=task(ATask);
    }
    task Ptask=task(PTask);
    task Btask=task(BTask);
    
    // task Dtask=task(DriveTask);
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................


    wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//


int main() {
  
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // Run the pre-autonomous function.
  pre_auton();
  

  // Prevent main from exiting with an infinite loop.
  using namespace std;
  while (true) {
    wait(100, msec);
    
    // std::cout << "BLOU" << endl;
    std::cout << LiftSensor.position(degrees) << endl;
    

  }
}
  