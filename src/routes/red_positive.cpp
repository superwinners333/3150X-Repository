#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void red_positive() 
{ // NEGATIVE IS TO THE LEFT
    // we start at 42 degrees???
    PIDDataSet TestPara={1.5,0.1,0.15};

    TurnMaxTimePID(TestPara, 40, 0.4, true);
    MoveEncoderPID(TestPara,-50,0.8,0.2,40,true);
    RunArms(100);
    wait(600,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, 40, 1, true);
    MoveEncoderPID(TestPara,80,16,0.2,40,true);
    MoveEncoderPID(TestPara,25,15,0.2,-0,true);
    Clamp.set(true);
    wait(300,msec);
    RunArms(-100);
    wait(700,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, -85, 1, false);
    RunRoller(100);
    MoveEncoderPID(TestPara,-100,13,0.2,-85,false); // grabs first ring
    MoveEncoderPID(TestPara,100,12.5,0.2,-85,false);
    TurnMaxTimePID(TestPara, 39, 1, false);
    Pistake.set(true);
    MoveEncoderPID(TestPara,-100,17,0.2,43,true); // moves to stacked ring
    wait(400,msec);
    Pistake.set(false);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 180, 1, false);
    MoveEncoderPID(TestPara,-100,17,0.2, 180,true);
    RunArms(100);
    wait(800,msec);
    RunArms(0);
}