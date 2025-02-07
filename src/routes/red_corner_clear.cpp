#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void red_corner_clear() 
{ // NEGATIVE IS TO THE LEFT
    PIDDataSet TestPara={1.5,0.1,0.15};

    TurnMaxTimePID(TestPara, 34, 0.4, true);
    RunArms(100);
    MoveEncoderPID(TestPara,-50,1.1,0.2,34,true);
    wait(175,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, 25, 1, true);

    MoveEncoderPID(TestPara,80,28,0.2,25,true); // drives towards mogo
    RunArms(-100);
    MoveEncoderPID(TestPara,30,10,0.2,16,true); // slows down and turns
    Clamp.set(true);
    wait(80,msec);
    RunArms(0);
    
    TurnMaxTimePID(TestPara, 50, 0.8, false);
    Pistake.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara,-100,43,0.2,50,false); // grabs first ring
    Pistake.set(false);
    wait(200,msec);
    MoveEncoderPID(TestPara,100,43,0.2,50,false); // drives away
    wait(15,msec);
    TurnMaxTimePID(TestPara, -105, 0.5, false); // turns to next ring
    MoveEncoderPID(TestPara,-100,34,0.2,-105,false); // drives into next ring
    wait(50,msec);
    
    Doinker.set(true);
    MoveEncoderPID(TestPara, -100,70,0.6,-25,true); // drives into corner

    TurnMaxTimePID(TestPara, 30, 0.5, false); // turns left and right to remove rings from corners
    TurnMaxTimePID(TestPara, -10, 0.5, false);
    TurnMaxTimePID(TestPara, 30, 0.5, false);
    TurnMaxTimePID(TestPara, 0, 0.5, false);
    Doinker.set(false);
    wait(50,msec);
    MoveEncoderPID(TestPara, 100,20,0.2,0,false); // drives away from corner

}