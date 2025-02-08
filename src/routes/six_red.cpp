#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// Left is - heading

void six_red() 
{
    // NEGATIVE HEADING TURNS TO THE LEFT
    PIDDataSet TestPara={1.5,0.1,0.15};

    // CLAMP CODE
    MoveEncoderPID(TestPara, 100, -22, 0.4, 0, true); // drives most of the way to mogo
    MoveEncoderPID(TestPara, 20, -11, 0.4, 0, true); // goes rest of the way to mogo
    wait(100,msec);
    Clamp.set(true); // activates clamp
    wait(100,msec);

// CENTER RINGS CODE
    TurnMaxTimePID(TestPara, 139, 0.4, false); // turns to face first center ring (2)
    RunRoller(100); // spins intake forward
    MoveEncoderPID(TestPara, -100, -28, 0.4, 139 ,true); // drives towards first center ring (2) and intakes it 
    wait(140,msec);
    MoveEncoderPID(TestPara, -80, -20, 0.7, 88, true); // moves to second center ring (3) 
    wait(130,msec);

// STACKED BOTTOM RING CODE (4)
    // RunRoller(0);
    TurnMaxTimePID(TestPara, -19.3, 0.7, false); // rotates to stack bottom ring (4)
    RunRoller(0);
    MoveEncoderPID(TestPara, -100, -52, 0.5, -19.3, true); // goes to stack bottom ring (4)
    RunRoller(100);

// STACKED TOP RING CODE (5)
    wait(300,msec);
    TurnMaxTimePID(TestPara, -85, 0.4, true); // rotates to stack top ring (5)
    MoveEncoderPID(TestPara, -100, -17, 0.4, -85, true); // moves towards stack top ring (5)
    Pistake.set(true); // activates pistake
    MoveEncoderPID(TestPara, -100, -18, 0.4, -85, true); // moves towards stack top ring (5)
    wait(100,msec);
    Pistake.set(false);

// TOUCHING TOWER CODE
    // MoveEncoderPID(TestPara, 100, -2, 0.4, 90, true); // drives backwards
    TurnMaxTimePID(TestPara, -170, 0.4, false); // turns towards tower
    MoveEncoderPID(TestPara, -100, -17, 0.4, -170, false); // goes towards tower
    RunArms(100);
    wait(800,msec);
    StopArms();

}