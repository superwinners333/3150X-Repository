#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void blue_negative() 
{ // NEGATIVE IS TO THE LEFT
    PIDDataSet TestPara={1.5,0.1,0.15};

    TurnMaxTimePID(TestPara, 35, 0.4, true);
    MoveEncoderPID(TestPara,-50,1.3,0.2,35,true);
    RunArms(100);
    wait(550,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, 25, 1, true);
    MoveEncoderPID(TestPara,80,28,0.2,25,true);
    MoveEncoderPID(TestPara,30,13,0.2,16,true);
    Clamp.set(true);
    wait(100,msec);
    RunArms(-100);
    wait(700,msec);
    RunArms(0);

    // CENTER RINGS CODE
    TurnMaxTimePID(TestPara, -140, 0.4, true); // turns to face first center ring (2)
    RunRoller(100); // spins intake forward
    MoveEncoderPID(TestPara, -100, -31.3, 0.4, -140 ,true); // drives towards first center ring (2) and intakes it 
    wait(140,msec);
    // TurnMaxTimePID(TestPara, -90, 0.4, true); // turns to second center ring (3)
    MoveEncoderPID(TestPara, -100, -14, 0.6, -86, true); // moves to second center ring (3) 
    wait(150,msec);

// STACKED BOTTOM RING CODE (4)
    // RunRoller(0);
    TurnMaxTimePID(TestPara, 19, 0.7, true); // rotates to stack bottom ring (4)
    wait(50,msec);
    MoveEncoderPID(TestPara, -100, -16, 0.4, 19, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -100, -16, 0.4, 19, false); // goes to stack bottom ring (4) // 60 original distance
    // RunRoller(100);

// STACKED TOP RING CODE (5)
    // wait(300,msec);
    wait(10,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 85, 0.4, true); // rotates to stack top ring (5)
    // RunRoller(100);
    wait(300,msec);
    Pistake.set(true);
    MoveEncoderPID(TestPara, -100, -45, 0.4, 85, true); // moves towards stack top ring (5) // original value 15
    // Pistake.set(true); // activates pistake
    // MoveEncoderPID(TestPara, -100, -16, 0.4, 85, true); // moves towards stack top ring (5)
    wait(130,msec);
    // Pistake.set(false);

// TOUCHING TOWER CODE
    TurnMaxTimePID(TestPara, 170, 0.4, true); // turns towards tower
    MoveEncoderPID(TestPara, -100, -17, 0.4, 170, false); // goes towards tower
    Pistake.set(false);
    RunArms(100);
    wait(800,msec);
    StopArms();
}