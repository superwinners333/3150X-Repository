#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// Left is - heading

void back_up() 
{
    PIDDataSet TestPara={1.5,0.1,0.15};
    Gyro.setHeading(0,degrees);
    MoveEncoderPID(TestPara,100,6.4,0.2,0,true);
    CStop();
}