#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void basic_red_positive() 
{
    PIDDataSet TestPara={1.5,0.1,0.15};
    MoveEncoderPID(TestPara, 10, -25, 0.4,0,true); // move backwards into mogo
    wait(250,msec);
    Clamp.set(true); // clamp onto mogo
    Clamp2.set(true);
    wait(250,msec);
    MoveEncoderPID(TestPara, 10, -8, 0.4,0,true); // move back a bit more to align with ring after rotating
    wait(250,msec);
    TurnMaxTimePID(TestPara, 90, 0.9, true); // rotate
    RunRoller(-100); // put ring into mogo and prep for next ring
    wait(250,msec);
    MoveEncoderPID(TestPara, 10, 41, 0.4,0,true); // pick up ring and ram into wall
    MoveEncoderPID(TestPara, 10, -5, 0.4,0,true); // move back from wall to prepare for turning
    wait(250,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -85, 0.9, true); //rotate to face rings in corner
    wait(250,msec);
    Doinker.set(true); // activate doinker
    wait(250,msec);
    MoveEncoderPID(TestPara, 10, 33, 0.4,0,true); // drive to rings in corner
    wait(250,msec);
    TurnMaxTimePID(TestPara, -90, 0.9, true); // remove the rings in the corner
    wait(250,msec);
    MoveEncoderPID(TestPara, 10, 10, 0.4,0,true); // move away from corner
    wait(250,msec);
    TurnMaxTimePID(TestPara, -30, 0.9, true); // rotate so that back faces corner
    wait(250,msec);
    MoveEncoderPID(TestPara, 10, -12, 0.4,0,true); // drive backwards into corner
    wait(250,msec);
    Clamp.set(false); // drop mogo in corner
    Clamp2.set(false);
    wait(250,msec);
    TurnMaxTimePID(TestPara, -15, 0.9, true); // rotate to face ladder
    wait(250,msec);
    MoveEncoderPID(TestPara, 10, 35, 0.4,0,true); // touch ladder
}