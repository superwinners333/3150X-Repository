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
    TurnMaxTimePID(TestPara, 41, 0.9, true); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -18.8, 0.4, 41,true); // drives to in front of wall stake
    wait(100,msec);
    Macro(); // activates macro
    TurnMaxTimePID(TestPara, 90, 0.9, true); // turns towards wall stake
    MoveTimePID(TestPara, 25, 2, 0.4, 90, true); // runs into wall stake
    wait(1.4,sec);
    RunRoller(0);
    RunArms(100); // scores on wall stake
    wait(1.6,sec);
    RunArms(-100);
    MoveEncoderPID(TestPara, 100, -3, 0.4, 90,true); // moves back
    wait(500,msec);
    StopArms();
    MoveEncoderPID(TestPara, 100, -3, 0.4, 90,true); // moves back

    // CORNER RINGS
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 180, 0.9, true); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -60, -50, 0.4, 180,true); // picks up the 3 rings that are in a line
    wait(100,msec);
    
    // POSSIBLE SUBSTITUTE CODE
    // TurnMaxTimePID(TestPara, 45, 0.9, true); // turns to side ring
    // MoveEncoderPID(TestPara, -100, -8, 0.4, 45, true); // picks up side ring
    // wait(100,msec);
    // TurnMaxTimePID(TestPara, -20, 0.9, true); // turns so mogo faces corner
    MoveEncoderPID(TestPara, 80, -8, 0.4, 180,true); // backs up
    wait(100,msec);
    TurnMaxTimePID(TestPara, 90, 0.9, true); // turns to side ring
    MoveEncoderPID(TestPara, -100, -5, 0.4, 90,true); // picks up side ring 
    wait(100,msec);
    TurnMaxTimePID(TestPara, -25, 0.9, true); // turns so mogo faces corner

    RunRoller(0);
    MoveTimePID(TestPara, -35, 1.6, 0.4, -25, true); // backs up into corner
    wait(100,msec);
    Clamp.set(false);
    wait(100,msec);
    MoveEncoderPID(TestPara, -70, -4.2, 0.4, -36,true); // drives away from corner
    TurnMaxTimePID(TestPara, 90, 1.2, true); // rotate towards mogo on other side

    // ===================================
    // NEXT CORNER 
    // ===================================
    wait(100,msec);
    MoveEncoderPID(TestPara, 100, -49, 0.4, 90, false); // drives to mogo
    wait(50,msec);
    MoveEncoderPID(TestPara, 40, -14, 0.4, 90,true); // slows down before grabbing mogo
    wait(100,msec);
    Clamp.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 0, 0.9, true); // turns to ring between bot and ladder
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, -15, 0.4, 0,true); // drives to the ring between bot and ladder

    // OTHER SIDE WALL STAKES
    wait(100,msec);
    TurnMaxTimePID(TestPara, -41, 0.9, true); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -18.8, 0.4, -41, true); // drives to in front of wall stake
    wait(100,msec);
    Macro(); // activates macro
    TurnMaxTimePID(TestPara, -90, 0.9, true); // turns towards wall stake
    MoveTimePID(TestPara, 25, 2.3, 0.4, -90, true); // runs into wall stake
    wait(1,sec);
    RunRoller(0);
    RunArms(100); // scores on wall stake
    wait(2,sec);
    RunArms(-100);
    MoveEncoderPID(TestPara, 100, -3, 0.4, -90,true); // moves back
    wait(500,msec);
    StopArms();
    MoveEncoderPID(TestPara, 100, -3, 0.4, -90,true); // moves back

    // OTHER SIDE CORNER RINGS
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 180, 0.9, true); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -60, -50, 0.4, 180,true); // picks up the 3 rings that are in a line
    wait(100,msec);
    MoveEncoderPID(TestPara, 80, -13, 0.4, 180,true); // backs up
    wait(100,msec);
    TurnMaxTimePID(TestPara, -90, 0.9, true); // turns to side ring
    MoveEncoderPID(TestPara, -100, -5, 0.4, -90,true); // picks up side ring
    wait(100,msec);
    TurnMaxTimePID(TestPara, 20, 0.9, true); // turns so mogo faces corner
    MoveTimePID(TestPara, -70, 2, 0.4, 20, true); // backs up into corner
    wait(100,msec);
    Clamp.set(false);
    wait(100,msec);
    MoveTimePID(TestPara, -70, 2, 0.4, 30, true); // backs away from corner

    // CROSSING TO THE OTHER SIDE OF THE FIELD
}