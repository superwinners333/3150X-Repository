#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void blue_positive() 
{ // NEGATIVE IS TO THE LEFT
    // we start at 47 degrees???
    PIDDataSet TestPara={1.5,0.1,0.15};

    Macro();
    RunRoller(100);
    wait(300,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, -100, -1.5, 0.4, 0,true); // drives towards alliance stake
    RunArms(100);
    wait(1.15,sec);
    StopArms();
    wait(100,msec);
    RunArms(-65);
    MoveEncoderPID(TestPara, 100, -9.6, 0.4, 0,true); // drives away from alliance stake
    TurnMaxTimePID(TestPara, -46, 0.9, true); // turns back towards mogo
    StopArms();
    wait(100,msec);
    MoveEncoderPID(TestPara, 100, -6, 0.4, -46,true); // drives towards mogo
    wait(50,msec);
    MoveEncoderPID(TestPara, 40, -6.2, 0.4, -46,true);
    wait(100,msec);
    Clamp.set(true);
    wait(100,msec);

    // CENTER RINGS CODE
    TurnMaxTimePID(TestPara, 172, 0.4, true); // turns to face first center ring (2)
    RunRoller(100); // spins intake forward
    MoveEncoderPID(TestPara, -100, -12, 0.4, 172 ,true); // drives towards first center ring (2) and intakes it 
    wait(130,msec);
    // TurnMaxTimePID(TestPara, -90, 0.4, true); // turns to second center ring (3)
    MoveEncoderPID(TestPara, -100, -7.5, 0.4, -130, true); // moves to second center ring (3) 
    wait(120,msec);

// STACKED BOTTOM RING CODE (4)
    TurnMaxTimePID(TestPara, -31, 0.4, true); // rotates to stack bottom ring (4)
    MoveEncoderPID(TestPara, -100, -15, 0.4, -31, true); // goes to stack bottom ring (4)
    // wait(100,msec);

// CORNER RING CODE (5)
    TurnMaxTimePID(TestPara, -83, 0.4, true);
    MoveEncoderPID(TestPara, -100, -28, 0.4, -85, true); // rotates + moves to corner ring (5)
    RunRoller(-100);
    MoveEncoderPID(TestPara, -100, -2, 0.4, -85, true);
    wait(200,msec);
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, -3, 0.4, -85, true);
    wait(200,msec);
    MoveEncoderPID(TestPara, 100, -8, 0.4, -85, true); // moves away from the corner ring (5)

// STACKED TOP RING CODE (6)
    wait(100,msec);
    TurnMaxTimePID(TestPara, 38, 0.4, true); // rotates to stack top ring (6)
    MoveEncoderPID(TestPara, -100, -12, 0.4, 38, true); // moves towards stack top ring (6)
    Pistake.set(true); // activates pistake
    MoveEncoderPID(TestPara, -100, -12, 0.4, 38, true); // moves towards stack top ring (6)
    wait(100,msec);
    Pistake.set(false);

// TOUCHING TOWER CODE
    MoveEncoderPID(TestPara, 100, -2, 0.4, 47, true); // drives backwards
    TurnMaxTimePID(TestPara, 137, 0.4, true); // turns towards tower
    MoveEncoderPID(TestPara, -100, -10, 0.4, 137, false); // goes towards tower
}