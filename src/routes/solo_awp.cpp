#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void solo_awp() 
{   
   
    PIDDataSet TestPara={1.5,0.1,0.15}; // for red positive corner or blue negative
    TurnMaxTimePID(TestPara, 35, 0.4, true);
    MoveEncoderPID(TestPara,-50,0.8,0.2,35,true);
    RunArms(100);
    wait(600,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, 25, 1, true);
    MoveEncoderPID(TestPara,80,22,0.2,25,true);
    MoveEncoderPID(TestPara,20,10,0.2,16,true);
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
    MoveEncoderPID(TestPara,-100,17,0.2,45,true);
    wait(400,msec);
    Pistake.set(false);
    wait(1,sec);
    Clamp.set(false);
    wait(100,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -40, 1, true);
    RunRoller(-100);
    MoveEncoderPID(TestPara,80,12.5,0.2,-40,false);
    MoveEncoderPID(TestPara,25,11,0.2,-40,true);
    Clamp.set(true);
    wait(500,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 90, 1, true);
    MoveEncoderPID(TestPara,-100,16,0.2,90,true);
    TurnMaxTimePID(TestPara, -100, 1, true);
    MoveEncoderPID(TestPara,-80,28,0.2,-100,true);
    RunArms(100);
    wait(700,msec);
    StopArms();



    
    // this stuff down here just makes the bot touch the ladder

    // TurnMaxTimePID(TestPara, -45, 1, true);
    // RunRoller(0);
    // MoveEncoderPID(TestPara, 100, -6, 0.4, -45 ,true); 
}