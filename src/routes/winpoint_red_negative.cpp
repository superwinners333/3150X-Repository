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
    MoveEncoderPID(TestPara, 80, -7 , 0.4,-45,true); 
    wait(400,msec);
    MoveEncoderPID(TestPara, 40, 2 , 0.4,0,true);
    wait(400,msec);
    RunRoller(100); // put ring on alliance stake
    wait(3,sec);
    RunRoller(0); // stop intake
    MoveEncoderPID(TestPara, 100, 6 , 0.4,0,true);


}