#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// make sure that heading stays the same between turns
// or not if u think you can do it without

void blue_negative() 
{
    // NEGATIVE IS TO THE LEFT
    PIDDataSet TestPara={1.5,0.1,0.15};

    Pistake.set(true);
    MoveEncoderPID(TestPara, 90, -10, 0.5, -0,true); // drives most of the way to mogo
    MoveEncoderPID(TestPara, 35, -5, 0.6, -0,true); // goes rest of the way to mogo

    wait(100,msec);
    Clamp.set(true); // activates clamp
    wait(100,msec);
    TurnMaxTimePID(TestPara, -135, 0.4, true); // turns to face rings
    RunRoller(100); // activates intake
    MoveEncoderPID(TestPara, -80, -16, 0.6, -135 ,true); // drives towards rings and intakes it
    wait(150,msec);
    MoveEncoderPID(TestPara, 80, -4, 0.6, -110, true); // moves back and rotates towards second ring
    wait(150,msec);
    MoveEncoderPID(TestPara, -80, -7, 0.6, -105, true); // moves to second ring
    wait(150,msec);
    // MoveEncoderPID(TestPara, 100, -3, 0.4, 110, true); // backs away
    // wait(50,msec);

    TurnMaxTimePID(TestPara, 12, 0.4, true); // rotates to next ring
    MoveEncoderPID(TestPara, -90, -27, 0.6, 12, true); // goes to next ring
    wait(150,msec);
    // MoveEncoderPID(TestPara, -60, -36, 0.8, 30, true); // drives towards corner
    // wait(100,msec);
    // MoveEncoderPID(TestPara, 80, -12, 0.4, 30, true); // drives away from corner

    TurnMaxTimePID(TestPara, 90, 0.4, true);
    MoveEncoderPID(TestPara, -100, -12, 0.4, 90, true);
    Pistake.set(false);
    MoveEncoderPID(TestPara, -80, -12, 0.8, 90, true);
    wait(50,msec);
    MoveEncoderPID(TestPara, 80, -2, 0.4, 90, true); // drives backwards
    TurnMaxTimePID(TestPara, -180, 0.4, true);
    MoveEncoderPID(TestPara, -100, -4, 0.4, 180, false); // goes towards tower
    
}