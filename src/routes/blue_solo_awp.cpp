#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void blue_solo_awp() // FOR BLUE NEGATIVE CORNER (original)
{   
   
    PIDDataSet TestPara={1.5,0.1,0.15}; // for red positive corner or blue negative
    TurnMaxTimePID(TestPara, 34, 0.4, true);
    RunArms(100);
    MoveEncoderPID(TestPara,-50,1.1,0.2,34,true);
    // RunArms(100);
    wait(175,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, 25, 1, true);

    MoveEncoderPID(TestPara,80,28,0.2,25,true); // grabs mogo
    RunArms(-100);
    MoveEncoderPID(TestPara,30,10,0.2,16,true);
    Clamp.set(true);
    // wait(100,msec);
    // RunArms(-100);
    wait(70,msec);
    RunArms(0);
    
    TurnMaxTimePID(TestPara, -105, 1, false); // turns to first ring
    RunRoller(100);
    MoveEncoderPID(TestPara,-100,33,0.2,-105,false); // grabs first ring
    MoveEncoderPID(TestPara,100,25,0.5,-105,false); // drives away from first ring
    wait(15,msec);
    TurnMaxTimePID(TestPara, 56, 1, true); // turns to center ring

    Pistake.set(true);
    RunRoller(70);
    Clamp.set(false); // releases mogo
    MoveEncoderPID(TestPara,-100,9,0.3,56,true); // goes towards center ring
    MoveEncoderPID(TestPara,-65,10.5,0.3,56,true); // goes towards cener ring
    // wait(30,msec);
    RunRoller(0); // stops intake to store ring
    Pistake.set(false);

    TurnMaxTimePID(TestPara, -42, 0.4, false); // turns to mogo
    MoveEncoderPID(TestPara,100,21,0.2,-42,true); // drives to mogo
    MoveEncoderPID(TestPara,30,20,0.2,-42,true);
    Clamp.set(true);
    wait(40,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 90, 0.3, false); // turns to last ring
    MoveEncoderPID(TestPara,-100,34,0.2,90,false); // grabs ring
    MoveEncoderPID(TestPara,100,10,0.2,90,false); // drives backwards
    wait(30,msec);

    TurnMaxTimePID(TestPara, -90, 0.4, false); // turns to face ladder
    wait(100,msec);
    RunArms(100);
    MoveEncoderPID(TestPara,-100,8,0.2,-90,false); // drives towards ladder
    wait(400,msec);
    RunArms(0);
    
}