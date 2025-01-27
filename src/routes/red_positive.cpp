#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void red_positive() 
{ // NEGATIVE IS TO THE LEFT
    // we start at 42 degrees???
    PIDDataSet TestPara={1.5,0.1,0.15};

    TurnMaxTimePID(TestPara, 34, 0.4, true);
    MoveEncoderPID(TestPara,-50,1.1,0.2,34,true);
    RunArms(100);
    wait(550,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, 25, 1, true);
    MoveEncoderPID(TestPara,80,28,0.2,25,true); // grabs mogo
    MoveEncoderPID(TestPara,30,10,0.2,16,true);
    Clamp.set(true);
    wait(100,msec);
    RunArms(-100);
    wait(700,msec);
    RunArms(0);
    
    TurnMaxTimePID(TestPara, -105, 1, false);
    RunRoller(100);
    MoveEncoderPID(TestPara,-100,34,0.2,-105,false); // grabs first ring
    MoveEncoderPID(TestPara,100,30,0.4,-130,false);
    wait(15,msec);
    TurnMaxTimePID(TestPara, -60, 1, false);

    wait(50,msec);
    RunRoller(-100);
    MoveEncoderPID(TestPara,-70,86,0.5,-60,true); // moves to corner ring
    wait(250,msec);
    RunRoller(100);
    MoveEncoderPID(TestPara,-100,5,0.3,-60,true); // runs into corner more
    wait(200,msec);

    MoveEncoderPID(TestPara,100,1.0,0.3,-60,true); // drive out slightly
    wait(15,msec);
    MoveEncoderPID(TestPara,-100,2,0.3,-60,true); // ram back in

    wait(100,msec);
    MoveEncoderPID(TestPara,50,32,1.1,-60,true); // drives away from corner

    wait(100,msec);

    TurnMaxTimePID(TestPara, 90, 1, false); // turns toward stacked ring
    Pistake.set(true);
    MoveEncoderPID(TestPara,-100,41.5,0.2,90,true); // moves to stacked ring
    wait(400,msec);
    Pistake.set(false); // deactivates pistake
    wait(100,msec);

    TurnMaxTimePID(TestPara, 170, 1, false); // turns to ladder
    MoveEncoderPID(TestPara,-100,25,0.2, 170,true);
    RunArms(100);
    wait(800,msec);
    RunArms(0);
}