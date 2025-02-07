#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void blue_corner_clear() 
{ // NEGATIVE IS TO THE LEFT
    PIDDataSet TestPara={1.5,0.1,0.15};

    TurnMaxTimePID(TestPara, -34, 0.4, true);
    RunArms(100);
    MoveEncoderPID(TestPara,-50,1.1,0.2,-34,true);
    wait(175,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, -25, 1, true);

    MoveEncoderPID(TestPara,80,28,0.2,-25,true); // grabs mogo
    RunArms(-100);
    MoveEncoderPID(TestPara,30,10,0.2,-16,true);
    Clamp.set(true);
    wait(80,msec);
    RunArms(0);
    

    TurnMaxTimePID(TestPara, -50, 0.8, false);
    RunRoller(100);
    Pistake.set(true);
    MoveEncoderPID(TestPara,-100,34,0.2,105,false); // grabs first ring
    Pistake.set(false);
    wait(200,msec);
    MoveEncoderPID(TestPara,100,30,0.4,130,false); // backs away
    wait(15,msec);
    TurnMaxTimePID(TestPara, 105, 0.7, false);
    MoveEncoderPID(TestPara,-100,34,0.2,105,false); // grabs second ring
    MoveEncoderPID(TestPara,100,30,0.4,130,false);
    wait(15,msec);
    TurnMaxTimePID(TestPara, 60, 0.4, false);   


    Doinker.set(true);
    MoveEncoderPID(TestPara,-100,74,0.5,60,true); // moves to corner rings
    wait(50,msec);
    TurnMaxTimePID(TestPara, 110, 0.5, false); // turns left and right to remove rings from corners
    TurnMaxTimePID(TestPara, 80, 0.5, false);
    TurnMaxTimePID(TestPara, 110, 0.5, false);
    TurnMaxTimePID(TestPara, 0, 0.5, false);
    Doinker.set(false);
    wait(50,msec);
    MoveEncoderPID(TestPara,100,20,0.5,0,false); // drives away from corner rings
}