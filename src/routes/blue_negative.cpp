#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void blue_negative() 
{ // NEGATIVE IS TO THE LEFT
    // we start at 42 degrees???
    PIDDataSet TestPara={1.5,0.1,0.15};

    // Macro();
    // RunRoller(100);
    // wait(300,msec);
    // RunRoller(0);
    TurnMaxTimePID(TestPara, 35, 0.4, true);
    MoveEncoderPID(TestPara,-50,0.8,0.2,35,true);
    RunArms(100);
    wait(600,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, 25, 1, true);
    MoveEncoderPID(TestPara,80,22,0.2,25,true);
    MoveEncoderPID(TestPara,20,10,0.2,16,true);
    Clamp.set(true);
    wait(100,msec);
    RunArms(-100);
    wait(700,msec);
    RunArms(0);

    // CENTER RINGS CODE
    TurnMaxTimePID(TestPara, -145, 0.4, true); // turns to face first center ring (2)
    RunRoller(100); // spins intake forward
    MoveEncoderPID(TestPara, -100, -8.8, 0.4, -130 ,true); // drives towards first center ring (2) and intakes it 
    wait(120,msec);
    // TurnMaxTimePID(TestPara, -90, 0.4, true); // turns to second center ring (3)
    MoveEncoderPID(TestPara, -100, -7, 0.4, -84, true); // moves to second center ring (3) 
    wait(120,msec);

// STACKED BOTTOM RING CODE (4)
    TurnMaxTimePID(TestPara, 16, 0.4, true); // rotates to stack bottom ring (4)
    RunRoller(0);
    MoveEncoderPID(TestPara, -100, -25, 0.4, 16, true); // goes to stack bottom ring (4)
    RunRoller(100);
    // wait(100,msec);

// CORNER RING CODE (5)
    // TurnMaxTimePID(TestPara, -25, 0.4, true);
    // MoveEncoderPID(TestPara, -100, -28, 0.4, -37, true); // rotates + moves to corner ring (5)
    // RunRoller(-100);
    // MoveEncoderPID(TestPara, -100, -2, 0.4, -37, true);
    // wait(200,msec);
    // RunRoller(100);
    // MoveEncoderPID(TestPara, -100, -3, 0.4, -37, true);
    // wait(200,msec);
    // MoveEncoderPID(TestPara, 100, -11, 0.4, -37, true); // moves away from the corner ring (5)

// STACKED TOP RING CODE (6)
    wait(300,msec);
    // TurnMaxTimePID(TestPara, 85, 0.4, true); // rotates to stack top ring (6)
    TurnMaxTimePID(TestPara, 85, 0.4, true); // rotates to stack top ring (6)
    MoveEncoderPID(TestPara, -100, -12, 0.4, 85, true); // moves towards stack top ring (6)
    Pistake.set(true); // activates pistake
    MoveEncoderPID(TestPara, -100, -15, 0.4, 85, true); // moves towards stack top ring (6)
    wait(100,msec);
    Pistake.set(false);

// TOUCHING TOWER CODE
    // MoveEncoderPID(TestPara, 100, -2, 0.4, 90, true); // drives backwards
    TurnMaxTimePID(TestPara, -180, 0.4, true); // turns towards tower
    MoveEncoderPID(TestPara, -100, -8, 0.4, 180, false); // goes towards tower
    RunArms(100);
    wait(800,msec);
    StopArms();
}