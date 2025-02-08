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

    // wait(1.7,sec);

    TurnMaxTimePID(TestPara, -36, 0.4, true);
    RunArms(100);
    MoveEncoderPID(TestPara,-50,1.4,0.2,-36,true);

    // wait(30,msec);

    wait(175,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, -25, 0.9, true);

    MoveEncoderPID(TestPara,80,28,0.2,-25,true); // grabs mogo
    RunArms(-100);
    MoveEncoderPID(TestPara,30,10,0.2,-16,true);
    Clamp.set(true);
    wait(80,msec);
    RunArms(0);
    
    TurnMaxTimePID(TestPara, 105, 1, false);
    RunRoller(100);
    MoveEncoderPID(TestPara,-100,34,0.2,105,false); // grabs first ring
    MoveEncoderPID(TestPara,100,30,0.4,130,false);
    wait(15,msec);
    TurnMaxTimePID(TestPara, 60, 0.4, false);

    wait(20,msec);
    RunRoller(-100);
    MoveEncoderPID(TestPara,-80,84,0.5,60,true); // moves to corner ring
    wait(50,msec);
    RunRoller(100);
    MoveEncoderPID(TestPara,-100,3,0.3,60,true); // runs into corner more

    wait(70,msec);
    MoveEncoderPID(TestPara,15,13,0.4,60,true); // drives away from corner
    wait(20,msec);

    // MoveEncoderPID(TestPara,-100,4,0.4,60,false);
    // MoveEncoderPID(TestPara,100,4,0.4,60,false);

    MoveEncoderPID(TestPara,100,13,0.4,60,true);
    wait(70,msec);

    TurnMaxTimePID(TestPara, -90, 0.6, false); // turns toward stacked ring
    Pistake.set(true);
    MoveEncoderPID(TestPara,-100,49,0.4,-90,true); // moves to stacked ring
    Pistake.set(false); // deactivates pistake
    wait(30,msec);
    // MoveEncoderPID(TestPara,100,6,0.4,-90,true);
    // wait(30,msec);

    TurnMaxTimePID(TestPara, -170, 0.4, false); // turns to ladder
    wait(150,msec);
    MoveEncoderPID(TestPara,-100,28,0.4, -170,true);
    RunRoller(0);
    RunArms(100);
    wait(700,msec);
    RunArms(0);
}