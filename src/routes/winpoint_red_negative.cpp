#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void winpoint_red_negative() 
{
    PIDDataSet TestPara={1.5,0.1,0.15};
    MoveEncoderPID(TestPara, 10, -5 , 0.4,0,true); // move backwards into wall
    wait(400,msec);
    RunRoller(-100); // put ring on alliance stake
    wait(3,sec);
    RunRoller(0); // stop intake
    MoveEncoderPID(TestPara, 10, 6 , 0.4,0,true); // move forward
    RunRoller(100); // spit out potential enemy rings
    wait(250,msec);
    TurnMaxTimePID(TestPara, -45, 0.9, true); // rotate so that back faces mogo
    wait(250,msec);
    RunRoller(0); // stop intake
    MoveEncoderPID(TestPara, 10, -34 , 0.4,0,true); // move to mogo
    wait(250,msec);
    Clamp.set(true); // clamp on mogo
    Clamp2.set(true);
    wait(250,msec);
    MoveEncoderPID(TestPara, 10, -9 , 0.4,0,true); // move back 
    wait(250,msec)
    TurnMaxTimePID(TestPara, 135, 0.9, true); // rotate to face ring
    RunRoller(-100); // run intake to prepare for intaking ring
    wait(250,msec)
    MoveEncoderPID(TestPara, 10, 24 , 0.4,0,true); // move forward to ring


}