#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void two_red_negative() 
{
    PIDDataSet TestPara={1.5,0.1,0.15};

    MoveEncoderPID(TestPara, 100, -18, 0.4, 0,true); // drives most of the way to mogo
    MoveEncoderPID(TestPara, 40, -5, 0.4, 0,true); // goes rest of the way to mogo

    wait(250,msec);
    Clamp.set(true); // activates clamp
    wait(250,msec);  
    RunRoller(100); // activates intake

    wait(250,msec);
    TurnMaxTimePID(TestPara, 90, 1, true); // turns to face stacked rings
    wait(200,msec);
    MoveEncoderPID(TestPara, -100, -25, 0.4, 90 ,true); // drives towards stacked rings
    wait(150,msec);
    MoveEncoderPID(TestPara, 100, -65, 0.4, 110, true);
    wait(200,msec);
    Clamp.set(false); // deactivates the clamp
    wait(100,msec);
    MoveEncoderPID(TestPara, -100, -7, 0.4, 110, true);
    wait(150, msec);
    TurnMaxTimePID(TestPara, 50, 1, true);
    wait(150, msec);
    MoveEncoderPID(TestPara, 50, -23, 0.4, 45, true);
    wait(100, msec);
    Clamp.set(true); // activates the clamp
    wait(100, msec);
    MoveEncoderPID(TestPara, 100, -5, 0.4, 45, true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, -90, 1, true);
    wait(150,msec);
    MoveEncoderPID(TestPara, -100, -18, 0.4, -90, true);
    wait(100, msec);
    MoveEncoderPID(TestPara, 100, -15, 0.4, -90, true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, -45, 1, true);
    RunRoller(0);
    wait(50, msec);
    MoveEncoderPID(TestPara, 100, -7, 0.4, -45, true);
    //MoveEncoderPID(TestPara, 100, -15, 0.4, -135, true);
    //wait(100, msec);
    //TurnMaxTimePID(TestPara, 90, 1, true);
    //MoveEncoderPID(TestPara, 100, -7, 0.4, 90, true);
    
    //TurnMaxTimePID(TestPara, 185, 1, true); // turns toward center ring
    //wait(250,msec);
    //MoveEncoderPID(TestPara, -50, -8, 0.4, 183, true); // drives towards the center rings
    //wait(200,msec);
    //MoveEncoderPID(TestPara, -100, 10, 0.4, 183, true);
    //MoveEncoderPID(TestPara, 100, -4, 0.4, 90 ,true); // drives away from stacked rings
    //wait(4,sec);
    //RunRoller(-100); // spits out any potential opponent rings
    //MoveEncoderPID(TestPara, 100, -5, 0.4, 90 ,true); // fully removes the rings from the bot

    // this stuff down here just makes the bot touch the ladder

    // TurnMaxTimePID(TestPara, 45, 1, true);
    // RunRoller(0);
    //
    
    //MoveEncoderPID(TestPara, 100, -6, 0.4, 45 ,true);
}