#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void blue_positive() 
{ // NEGATIVE IS TO THE LEFT
    PIDDataSet TestPara={1.5,0.1,0.15};

    MoveEncoderPID(TestPara, 100, -23, 0.4, 0,true); // moves most of the way to mogo
    MoveEncoderPID(TestPara, 40, -5, 0.4, 0,true); // moves rest of the way to mogo
    
    wait(250,msec); 
    Clamp.set(true); // clamps onto mogo
    wait(250,msec);  
    RunRoller(100); // activates intake

    wait(250,msec);
    TurnMaxTimePID(TestPara, 90, 1, true); // turns to face stacked rings

}