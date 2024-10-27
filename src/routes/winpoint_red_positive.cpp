#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void winpoint_red_positive() 
{
    PIDDataSet TestPara={1.5,0.1,0.15};
    MoveEncoderPID(TestPara, 100, -15, 0.4, 0,true);
    MoveEncoderPID(TestPara, 40, -10, 0.4, 0,true);
    wait(500,msec);
    Clamp.set(true); // clamp onto mogo
    wait(250,msec);
    RunRoller(100);
    // MoveEncoderPID(TestPara, 100, -1  , 0.4, 90,true);
}