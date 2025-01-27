#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// Left is - heading

void old_six_blue() 
{
    // NEGATIVE HEADING TURNS TO THE LEFT
    PIDDataSet TestPara={1.5,0.1,0.15};

// CLAMP CODE
    // Pistake.set(true);
    MoveEncoderPID(TestPara, 100, -7, 0.4, -0, true); // drives most of the way to mogo
    MoveEncoderPID(TestPara, 30, -4, 0.4, -0, true); // goes rest of the way to mogo
    wait(100,msec);
    Clamp.set(true); // activates clamp
    wait(100,msec);

// CENTER RINGS CODE
    TurnMaxTimePID(TestPara, -145, 0.4, true); // turns to face first center ring (2)
    RunRoller(100); // spins intake forward
    MoveEncoderPID(TestPara, -100, -8, 0.4, -145 ,true); // drives towards first center ring (2) and intakes it 
    wait(120,msec);
    // TurnMaxTimePID(TestPara, -90, 0.4, true); // turns to second center ring (3)
    MoveEncoderPID(TestPara, -100, -4, 0.4, -83, true); // moves to second center ring (3) 
    wait(120,msec);

// STACKED BOTTOM RING CODE (4)
    TurnMaxTimePID(TestPara, 12, 0.4, true); // rotates to stack bottom ring (4)
    MoveEncoderPID(TestPara, -100, -7, 0.4, 12, true); // goes to stack bottom ring (4)
    // wait(100,msec);

// CORNER RING CODE (5)
    TurnMaxTimePID(TestPara, -25, 0.4, true);
    MoveEncoderPID(TestPara, -100, -13, 0.4, -37, true); // rotates + moves to corner ring (5)
    RunRoller(-100);
    MoveEncoderPID(TestPara, -100, -0.6, 0.4, -37, true);
    wait(200,msec);
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, -1, 0.4, -37, true);
    wait(200,msec);
    MoveEncoderPID(TestPara, 100, -6, 0.4, -37, true); // moves away from the corner ring (5)

// STACKED TOP RING CODE (6)
    wait(100,msec);
    TurnMaxTimePID(TestPara, 85, 0.4, true); // rotates to stack top ring (6)
    MoveEncoderPID(TestPara, -100, -5, 0.4, 85, true); // moves towards stack top ring (6)
    Pistake.set(true); // activates pistake
    MoveEncoderPID(TestPara, -100, -5, 0.4, 85, true); // moves towards stack top ring (6)
    wait(100,msec);
    Pistake.set(false);

// TOUCHING TOWER CODE
    MoveEncoderPID(TestPara, 100, -1, 0.4, 90, true); // drives backwards
    TurnMaxTimePID(TestPara, -180, 0.4, true); // turns towards tower
    MoveEncoderPID(TestPara, -100, -4, 0.4, 180, false); // goes towards tower
    
}