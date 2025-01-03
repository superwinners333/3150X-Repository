#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// negative heading is turning left
// or not if u think you can do it without

void prog_skills() 
{
    PIDDataSet TestPara={1.5,0.1,0.15}; // this is important and DONT TOUCH THIS

    RunRoller(100); // activates intake and scores ring on alliance stake
    wait(400,msec);
    MoveEncoderPID(TestPara, -100, -4, 0.4, 0,true); // drives away from wall
    TurnMaxTimePID(TestPara, -90, 0.9, true); // turns towards mogo
    MoveEncoderPID(TestPara, 50, -20.5, 0.4, -90,true); // goes to mogo
    wait(100,msec);
    Clamp.set(true); // clamps to mogo
    wait(100,msec);
    TurnMaxTimePID(TestPara, 0, 0.9, true); // turns to ring between bot and ladder
    MoveEncoderPID(TestPara, -100, -15, 0.4, 0,true); // drives to the ring between bot and ladder

    // WALL STAKES
    wait(100,msec);
    TurnMaxTimePID(TestPara, 42, 0.9, true); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -18.4, 0.4, 42,true); // drives to in front of wall stake
    wait(100,msec);
    Macro(); // activates macro
    TurnMaxTimePID(TestPara, 90, 0.9, true); // turns towards wall stake
    MoveTimePID(TestPara, 25, 2.1, 0.4, 90, true); // runs into wall stake
    wait(1,sec);
    RunRoller(0);
    RunArms(100); // scores on wall stake
    wait(2,sec);
    RunArms(-100);
    MoveEncoderPID(TestPara, 100, -3, 0.4, 90,true);
    wait(500,msec);
    StopArms();
    MoveEncoderPID(TestPara, 100, -4, 0.4, 90,true);

    // CORNER RINGS
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 180, 0.9, true); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -60, -50, 0.4, 180,true);
    wait(100,msec);
    MoveEncoderPID(TestPara, 80, -10, 0.4, 180,true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 90, 0.9, true);
    MoveEncoderPID(TestPara, -100, -5, 0.4, 90,true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, -20, 0.9, true);
    MoveTimePID(TestPara, -70, 2, 0.4, -20, true);
    wait(100,msec);
    Clamp.set(false);

    // MoveEncoderPID(TestPara, 100, -23, 0.4, 0,true); // forward
    // MoveEncoderPID(TestPara, 40, -5, 0.4, 0,true); 
    // wait(250,msec); 
    // Clamp.set(true); 
    // TurnMaxTimePID(TestPara, 90, 0.9, true); 
}