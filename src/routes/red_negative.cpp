#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// make sure that heading stays the same between turns
// or not if u think you can do it without

void red_negative() 
{
    PIDDataSet TestPara={1.5,0.1,0.15};

    RunArms(100);
    wait(140,msec);
    StopArms();
    MoveEncoderPID(TestPara, 100, -11, 0.4, 0,true); // drives most of the way to mogo
    MoveEncoderPID(TestPara, 50, -4, 0.4, 0,true); // goes rest of the way to mogo
   
    wait(100,msec);
    Clamp.set(true); // activates clamp
    wait(100,msec);
    TurnMaxTimePID(TestPara, 140, 0.4, true); // turns to face rings
    RunRoller(90); // activates intake
    MoveEncoderPID(TestPara, -100, -20, 0.4, 140 ,true); // drives towards rings and intakes it
    wait(50,msec);
    MoveEncoderPID(TestPara, 100, -3, 0.4, 110, true); // moves back and rotates towards next ring
    wait(50,msec);
    MoveEncoderPID(TestPara, -100, -10, 0.4, 110, true); // moves to second ring
    wait(50,msec);
    MoveEncoderPID(TestPara, 100, -3, 0.4, 110, true); // backs away
    wait(50,msec);
    TurnMaxTimePID(TestPara, 20, 0.4, true); // rotates to next ring
    MoveEncoderPID(TestPara, -100, -13, 0.4, 20, true); // goes to next ring
    // TurnMaxTimePID(TestPara, 30, 1, true); // turns to corner
    wait(100,msec);
    MoveEncoderPID(TestPara, -100, -36, 0.4, 25, true); // drives towards corner
    wait(100,msec);
    // Pistake.set(true);
    MoveEncoderPID(TestPara, 100, -10, 0.4, 25, true); // drives away from corner
    TurnMaxTimePID(TestPara, -70, 0.4, true);
    MoveEncoderPID(TestPara, -100, -20, 0.4, -70, true); // drives away from corner
    TurnMaxTimePID(TestPara, -90, 0.4, true);
    Pistake.set(true);
    MoveEncoderPID(TestPara, -100, -14, 0.4, -90, true); // drives towards stacked rings

}