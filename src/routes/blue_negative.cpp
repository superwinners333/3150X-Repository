#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// Left is - heading

void blue_negative() 
{
    // NEGATIVE HEADING TURNS TO THE LEFT
    PIDDataSet TestPara={1.5,0.1,0.15};

// CLAMP CODE
    // Pistake.set(true);
    MoveEncoderPID(TestPara, 100, -8, 0.4, -0,true); // drives most of the way to mogo
    MoveEncoderPID(TestPara, 40, -3.5, 0.4, -0,true); // goes rest of the way to mogo
    wait(100,msec);
    Clamp.set(true); // activates clamp
    wait(100,msec);

// CENTER RING CODE
    TurnMaxTimePID(TestPara, -145, 0.4, true); // turns to face first center ring (2)
    RunRoller(100); // spins intake forward
    MoveEncoderPID(TestPara, -100, -16, 0.4, -145 ,true); // drives towards first center ring (2) and intakes it 
    wait(100,msec);
    // TurnMaxTimePID(TestPara, -90, 0.4, true); // turns to second center ring (3)
    MoveEncoderPID(TestPara, -100, -6, 0.4, -90, true); // moves to second center ring (3) 
    wait(100,msec);

// STACKED BOTTOM RING CODE (4)
    TurnMaxTimePID(TestPara, 12, 0.4, true); // rotates to stack bottom ring (4)
    MoveEncoderPID(TestPara, -100, -15, 0.4, 12, true); // goes to stack bottom ring (4)
    wait(150,msec);

// CORNER RING CODE (5)
    TurnMaxTimePID(TestPara, -40, 0.4, true);
    // RunRoller(-100); // spins intake backwards
    MoveEncoderPID(TestPara, -100, -24, 0.4, -40, true); // rotates + moves to corner ring (5)
    wait(200,msec);
    // RunRoller(100); // spins intake forwards
    MoveEncoderPID(TestPara, 100, -12, 0.4, -40, true); // moves away from the corner ring (5)

// STACKED TOP RING CODE (6)
    wait(100,msec);
    TurnMaxTimePID(TestPara, 85, 0.4, true); // rotates to stack top ring (6)
    MoveEncoderPID(TestPara, -100, -12, 0.4, 85, true); // moves towards stack top ring (6)
    Pistake.set(true); // activates pistake
    MoveEncoderPID(TestPara, -100, -12, 0.4, 85, true); // moves towards stack top ring (6)
    wait(100,msec);

// TOUCHING TOWER CODE
    MoveEncoderPID(TestPara, 100, -2, 0.4, 90, true); // drives backwards
    TurnMaxTimePID(TestPara, -180, 0.4, true); // turns towards tower
    MoveEncoderPID(TestPara, -100, -5, 0.4, 180, false); // goes towards tower
    
}