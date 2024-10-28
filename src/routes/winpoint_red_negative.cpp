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

    MoveEncoderPID(TestPara, 100, -23, 0.4, 0,true);
    MoveEncoderPID(TestPara, 40, -5, 0.4, 0,true);

    // TurnMaxTimePID(TestPara, 90, 5, true);
    // wait(10,sec);

    // MoveEncoderPID(TestPara, 40, -24, 0.4 , 0 ,true);
    // MoveEncoderPID(TestPara, 40, -6, 0.4 , 0 ,true);

    wait(250,msec);
    Clamp.set(true);
    wait(250,msec);  
    RunRoller(100);

    wait(250,msec);
    TurnMaxTimePID(TestPara, -90, 1, true);
    wait(250,msec);
    MoveEncoderPID(TestPara, -100, -18, 0.4, -90 ,true);    
    wait(250,msec);
    MoveEncoderPID(TestPara, 100, -4, 0.4, -90 ,true); 
    wait(4,sec);
    RunRoller(-100);
    MoveEncoderPID(TestPara, 100, -5, 0.4, -90 ,true); 

    // TurnMaxTimePID(TestPara, -45, 1, true);
    // RunRoller(0);
    // MoveEncoderPID(TestPara, 100, -6, 0.4, -45 ,true); 
}