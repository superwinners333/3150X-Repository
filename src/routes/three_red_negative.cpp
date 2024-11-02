#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// make sure that heading stays the same between turns
// or not if u think you can do it without

void three_red_negative() 
{
    PIDDataSet TestPara={1.5,0.1,0.15};

    MoveEncoderPID(TestPara, 100, -18, 0.4, 0,true); // drives most of the way to mogo
    MoveEncoderPID(TestPara, 40, -5, 0.4, 0,true); // goes rest of the way to mogo

    wait(250,msec);
    Clamp.set(true); // activates clamp
    wait(100,msec);
    TurnMaxTimePID(TestPara, 133, 0.4, true); // turns to face rings
    wait(50,msec);
    RunRoller(100); // activates intake
    MoveEncoderPID(TestPara, -100, -14, 0.4, 133 ,true); // drives towards rings and intakes it
    wait(350,msec);
    MoveEncoderPID(TestPara, 80, -2, 0.4, 140, true); // moves back and rotates towards next ring
    wait(350,msec);
    MoveEncoderPID(TestPara, -100, -7, 0.4, 120, true); // moves to second ring
    wait(150,msec);
    MoveEncoderPID(TestPara, 100, -3, 0.4, 90, true); // backs away
    wait(150,msec);
    MoveEncoderPID(TestPara, -100, -2, 0.4, 90, true); // moves forward
    TurnMaxTimePID(TestPara, 0, 1, true); // rotates to next ring
    MoveEncoderPID(TestPara, -100, -13, 0.4, 0, true); // goes to next ring
    wait(100,msec);
    TurnMaxTimePID(TestPara, 60, 1, true); // turns to ladder
    wait(500,msec);
    // RunRoller(0);
    MoveEncoderPID(TestPara, 100, -12, 0.4, 60, true); // drive backwards to ladder
    RunRoller(0);
    wait(100,msec);
    MoveEncoderPID(TestPara, 100, -10, 0.4, 60, true); // finishes drive to ladder
    // ------------------------------------------------------------------------------
    // wait(200,msec);;
    // Clamp.set(false); // deactivates the clamp
    // wait(100,msec);
    // MoveEncoderPID(TestPara, -100, -7, 0.4, 110, true);
    // wait(150, msec);
    // TurnMaxTimePID(TestPara, 50, 1, true);
    // wait(150, msec);
    // MoveEncoderPID(TestPara, 50, -23, 0.4, 45, true);
    // wait(100, msec);
    // Clamp.set(true); // activates the clamp
    // wait(100, msec);
    // MoveEncoderPID(TestPara, 100, -5, 0.4, 45, true);
    // wait(100, msec);
    // TurnMaxTimePID(TestPara, -90, 1, true);
    // wait(150,msec);
    // MoveEncoderPID(TestPara, -100, -18, 0.4, -90, true);
    // wait(100, msec);
    // MoveEncoderPID(TestPara, 100, -15, 0.4, -90, true);
    // wait(100, msec);
    // TurnMaxTimePID(TestPara, -45, 1, true);
    // RunRoller(0);
    // wait(50, msec);
    // MoveEncoderPID(TestPara, 100, -7, 0.4, -45, true);

    // old code, making new one above
    // wait(250,msec);
    // TurnMaxTimePID(TestPara, 90, 1, true); // turns to face stacked rings
    // wait(200,msec);
    // MoveEncoderPID(TestPara, -100, -25, 0.4, 90 ,true); // drives towards stacked rings
    // wait(150,msec);
    // MoveEncoderPID(TestPara, 100, -65, 0.4, 110, true);
    // wait(200,msec);
    // Clamp.set(false); // deactivates the clamp
    // wait(100,msec);
    // MoveEncoderPID(TestPara, -100, -7, 0.4, 110, true);
    // wait(150, msec);
    // TurnMaxTimePID(TestPara, 50, 1, true);
    // wait(150, msec);
    // MoveEncoderPID(TestPara, 50, -23, 0.4, 45, true);
    // wait(100, msec);
    // Clamp.set(true); // activates the clamp
    // wait(100, msec);
    // MoveEncoderPID(TestPara, 100, -5, 0.4, 45, true);
    // wait(100, msec);
    // TurnMaxTimePID(TestPara, -90, 1, true);
    // wait(150,msec);
    // MoveEncoderPID(TestPara, -100, -18, 0.4, -90, true);
    // wait(100, msec);
    // MoveEncoderPID(TestPara, 100, -15, 0.4, -90, true);
    // wait(100, msec);
    // TurnMaxTimePID(TestPara, -45, 1, true);
    // RunRoller(0);
    // wait(50, msec);
    // MoveEncoderPID(TestPara, 100, -7, 0.4, -45, true);
}