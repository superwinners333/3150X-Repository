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
    MoveEncoderPID(TestPara, -100, -8, 0.2, 0,true); // drives away from wall
    TurnMaxTimePID(TestPara, -90, 0.4, false); // turns towards mogo
    MoveEncoderPID(TestPara, 100, -14, 0.2, -90,true); // goes to mogo
    MoveEncoderPID(TestPara, 30, -19, 0.4, -90,true);
    // wait(100,msec);
    Clamp.set(true); // clamps to mogo
    wait(50,msec);
    TurnMaxTimePID(TestPara, 0, 0.4, false); // turns to ring between bot and ladder
    MoveEncoderPID(TestPara, -100, -37, 0.2, 0,true); // drives to the ring between bot and ladder

    // WALL STAKES
    wait(100,msec);
    TurnMaxTimePID(TestPara, 40, 0.5, false); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -33, 0.2, 40,true); // drives to rings in front of wall stake
    wait(50,msec);
    Macro(); // activates macro
    wait(50,msec);
    TurnMaxTimePID(TestPara, 90, 0.7, false); // turns towards wall stake
    wait(100,msec);
    MoveTimePID(TestPara, 35, 2.3, 0.4, 90, true); // runs into wall stake
    wait(1,sec);
    RunRoller(0);
    RunArms(100); // scores on wall stake
    wait(1.6,sec);
    RunArms(-100);
    MoveEncoderPID(TestPara, 100, -4, 0.4, 90,true); // moves back
    wait(450,msec);
    RunArms(0);
    MoveEncoderPID(TestPara, 100, -3.5, 0.4, 90,true); // moves back

    // CORNER RINGS
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 180, 0.9, true); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -90, 0.4, 180,false); // picks up the 3 rings that are in a line
    wait(90,msec);
    MoveEncoderPID(TestPara, 80, -11, 0.4, 180,false); // backs up
    wait(50,msec);
    TurnMaxTimePID(TestPara, 90, 0.4, false); // turns to side ring
    MoveEncoderPID(TestPara, -100, -7, 0.4, 90,true); // picks up side ring 
    wait(50,msec);
    TurnMaxTimePID(TestPara, -18, 0.7, true); // turns so mogo faces corner

    // PUTTING OTHER MOGO IN CORNER
    RunRoller(0);
    MoveTimePID(TestPara, -40, 1.6, 0.4, -18, true); // backs up into corner
    wait(100,msec);
    Clamp.set(false);
    wait(100,msec);
    MoveEncoderPID(TestPara, -70, -7, 0.4, -32.5,true); // drives away from corner
    TurnMaxTimePID(TestPara, 90, 1, true); // rotate towards mogo on other side

    // ===================================
    // NEXT CORNER 
    // ===================================

    wait(100,msec);
    MoveEncoderPID(TestPara, 100, -94, 0.4, 90, false); // drives to mogo
    wait(50,msec);
    MoveEncoderPID(TestPara, 40, -22, 0.4, 90,true); // slows down before grabbing mogo
    wait(100,msec);
    Clamp.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 0, 0.9, false); // turns to ring between bot and ladder
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, -25, 0.4, 0,true); // drives to the ring between bot and ladder

    // OTHER SIDE WALL STAKES
    wait(100,msec);
    TurnMaxTimePID(TestPara, -41, 0.9, false); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -39, 0.4, -41, true); // drives to in front of wall stake
    wait(100,msec);
    Macro(); // activates macro
    TurnMaxTimePID(TestPara, -90, 0.9, false); // turns towards wall stake
    MoveTimePID(TestPara, 25, 2.3, 0.4, -90, true); // runs into wall stake
    wait(1,sec);
    RunRoller(0);
    RunArms(100); // scores on wall stake
    wait(1.9,sec);
    RunArms(-100);
    MoveEncoderPID(TestPara, 100, -5, 0.4, -90,true); // moves back
    wait(500,msec);
    StopArms();
    MoveEncoderPID(TestPara, 100, -4, 0.4, -90,true); // moves back

    // OTHER SIDE CORNER RINGS
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 180, 0.5, false); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -90, 0.4, 180,false); // picks up the 3 rings that are in a line
    wait(90,msec);
    MoveEncoderPID(TestPara, 80, -11, 0.4, 180,false); // backs up
    wait(70,msec);
    TurnMaxTimePID(TestPara, -90, 0.5, false); // turns to side ring
    MoveEncoderPID(TestPara, -100, -5, 0.4, -90,true); // picks up side ring
    wait(100,msec);

    // PUTTING OTHER MOGO IN CORNER
    TurnMaxTimePID(TestPara, 20, 0.4, false); // turns so mogo faces corner
    RunRoller(0);
    MoveTimePID(TestPara, -70, 2, 0.4, 20, true); // backs up into corner
    wait(100,msec);
    Clamp.set(false);
    wait(100,msec);
    MoveEncoderPID(TestPara, -100, -5, 0.4, -90,true); // backs away from corner
    wait(50,msec);

    // ===================================
    // OTHER SIDE 
    // ===================================

    // CROSSING TO THE OTHER SIDE OF THE FIELD
    TurnMaxTimePID(TestPara, 0, 0.8, true); // rotates to other side of the field
    MoveEncoderPID(TestPara, -100, -65, 0.4, -90, true); // arrives at the two white lines
    TurnMaxTimePID(TestPara, 45, 0.4, false); // turns to face next ring
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, -26, 0.4, 45, true); // grabs next ring
    RunRoller(0);

    // PUSHING MOGO INTO CORNER AND CLAMPING ANOTHER ONE
    TurnMaxTimePID(TestPara, 0, 0.4, false); // turns to face mogo
    MoveEncoderPID(TestPara, -100, -30, 0.4, 0, false); // drives into mogo
    MoveTimePID(TestPara, -80, 3.0, 0.4, -75, false); // pushes mogo into corner ------ IMPORTANT VALUE

    MoveEncoderPID(TestPara, 100, -80, 0.4, -75, true); // drives backwards into next mogo
    MoveEncoderPID(TestPara, 25, -14, 0.4, -75, true); // slows down
    Clamp.set(true);
    wait(50,msec);

    // SCORES FINAL 
    TurnMaxTimePID(TestPara, 135, 0.5, false); // turns to next ring
    RunRoller(100);
    wait(30,msec);
    MoveEncoderPID(TestPara, -100, -23, 0.4, 135, true); // grabs ring
    TurnMaxTimePID(TestPara, 90, 0.5, false); // turns to next ring
    MoveEncoderPID(TestPara, -100, -20, 0.4, 90, true); // grabs ring

    TurnMaxTimePID(TestPara, 0, 0.6, false); // turns to the two rings in a row
    MoveEncoderPID(TestPara, -100, -55, 0.4, 0, false); // grabs both of the rings
    wait(80,msec);
    MoveEncoderPID(TestPara, 80, -19, 0.4, 0, false); // backs up
    wait(50,msec);

    TurnMaxTimePID(TestPara, 90, 0.4, false); // turns to final ring
    MoveEncoderPID(TestPara, -100, -10, 0.4, 90, false); // grabs final ring
    wait(50,msec);
    TurnMaxTimePID(TestPara, -162, 0.6, true); // turns so mogo faces corner

    // PUTTING OTHER MOGO IN CORNER
    RunRoller(0);
    MoveTimePID(TestPara, -40, 1.6, 0.4, -162, true); // backs up into corner
    wait(100,msec);
    Clamp.set(false);
    wait(100,msec);
    MoveEncoderPID(TestPara, -100, -8, 0.4, -147.5,true); // drives away from corner
    wait(50,msec);
    RunArms(100);
    TurnMaxTimePID(TestPara, 45, 0.5, false); // Turns to face ladder
    MoveEncoderPID(TestPara, 100, -8, 0.4, 45,true);
    StopArms();
    MoveEncoderPID(TestPara, 50, -13, 0.4, 45,false);

}