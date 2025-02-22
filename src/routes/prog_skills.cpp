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
    MoveEncoderPID(TestPara, -100, -9, 0.2, 0,true); // drives away from wall
    // wait(20,msec);
    TurnMaxTimePID(TestPara, -90, 0.4, true); // turns towards mogo
    wait(50,msec);
    MoveEncoderPID(TestPara, 100, -14, 0.2, -90,false); // goes to mogo
    MoveEncoderPID(TestPara, 30, -18, 0.2, -90,false); // slows down going to mogo
    wait(20,msec);
    Clamp.set(true); // clamps to mogo
    wait(100,msec);
    TurnMaxTimePID(TestPara, 0, 0.4, true); // turns to ring between bot and ladder
    wait(60,msec);
    MoveEncoderPID(TestPara, -100, -30, 0.3, 0,true); // drives to the ring between bot and ladder

    // WALL STAKES
    wait(80,msec);
    TurnMaxTimePID(TestPara, 39, 0.2, true); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -30, 0.3, 39,true); // drives to rings in front of wall stake
    wait(20,msec);
    Macro(); // activates macro
    wait(20,msec);
    TurnMaxTimePID(TestPara, 90, 0.2, false); // turns towards wall stake
    wait(20,msec);
    // MoveTimePID(TestPara, 35, 2.4, 0.7, 90, true); // runs into wall stake
    Move(-35,-35);
    wait(2.4,sec);
    wait(200,msec);

    RunRoller(0);
    wait(60,msec);
    RunRoller(100); // stutters the intake
    wait(70,msec);
    RunRoller(0); // stutters intake
    wait(70,msec);
    RunRoller(100); // stutters intake
    wait(70,msec);

    // Move(-35,-35); // runs into wall stake continuously
    RunRoller(0);
    RunArms(100); // scores on wall stake
    wait(0.8,sec);
    Move(0,0);

    RunArms(-100);
    wait(20,msec);
    MoveEncoderPID(TestPara, 100, -4.3, 0.4, 90,true); // moves back
    wait(300,msec);
    RunArms(0);
    MoveEncoderPID(TestPara, 100, -3.2, 0.2, 90,false); // moves back

    // CORNER RINGS
    wait(20,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 180, 0.2, true); // turns to in front of wall stake
    wait(30,msec);
    MoveEncoderPID(TestPara, -80, -47, 0.5, 180,false); // picks up the 3 rings that are in a line
    MoveEncoderPID(TestPara, -50, -43, 0.2, 180,false);
    wait(90,msec);
    MoveEncoderPID(TestPara, 75, -8.6, 0.6, 180,false); // backs up
    wait(50,msec);
    TurnMaxTimePID(TestPara, 88, 0.4, false); // turns to side ring
    MoveEncoderPID(TestPara, -100, -10.5, 0.2, 88,true); // picks up side ring 
    wait(280,msec);
    MoveEncoderPID(TestPara, 100, 0.5, 0.2, 88,false); // backs away

    TurnMaxTimePID(TestPara, -24, 0.3, false); // turns so mogo faces corner

    // PUTTING OTHER MOGO IN CORNER
    wait(350,msec);
    MoveTimePID(TestPara, -100, 0.5, 0.2, -24, false); // backs up into corner
    RunRoller(0);
    MoveTimePID(TestPara, -50, 0.9, 0.2, -24, false); 
    wait(70,msec);
    Clamp.set(false);
    wait(50,msec);
    MoveEncoderPID(TestPara, -100, -3.4, 0.3, -33,true); // drives away from corner
    wait(70,msec);
    TurnMaxTimePID(TestPara, 90, 0.7, true); // rotate towards mogo on other side 
    TurnMaxTimePID(TestPara, 90, 0.7, true);

    // =======================================================================================
    // NEXT CORNER 
    // =======================================================================================

    wait(50,msec);
    MoveEncoderPID(TestPara, 100, -102.5, 0.6, 90, false); // drives to mogo
    MoveEncoderPID(TestPara, 30, -34.4, 0.2,90,false); // slows down before grabbing mogo
    wait(30,msec);
    Clamp.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 0, 0.4, true); // turns to ring between bot and ladder
    RunRoller(100);
    wait(20,msec);
    MoveEncoderPID(TestPara, -100, -27, 0.2, 0,true); // drives to the ring between bot and ladder

    // OTHER SIDE WALL STAKES
    wait(20,msec);
    TurnMaxTimePID(TestPara, -40, 0.4, false); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -35, 0.2, -40, true); // drives to in front of wall stake
    wait(40,msec);
    Macro(); // activates macro
    TurnMaxTimePID(TestPara, -90, 0.2, false); // turns towards wall stake
    // MoveTimePID(TestPara, 30, 2.3, 0.2, -90, true); // runs into wall stake
    Move(-35,-35);
    wait(2.3,sec);
    wait(200,msec);

    RunRoller(0);
    wait(60,msec);
    RunRoller(100); // stutters intake
    wait(70,msec);
    RunRoller(0); // stutters intake
    wait(60,msec);
    RunRoller(100); // stutters intake
    wait(70,msec);

    RunRoller(0);
    // Move(-30,-30); // continuously drives into bot
    wait(20,msec);
    RunArms(100); // scores on wall stake
    wait(0.9,sec);
    Move(0,0);

    RunArms(-100);
    MoveEncoderPID(TestPara, 100, -4.4, 0.4, -90,true); // moves back
    wait(450,msec);
    RunArms(0);
    MoveEncoderPID(TestPara, 100, -3.9, 0.4, -90,false); // moves back

    // OTHER SIDE CORNER RINGS
    wait(50,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 180, 0.4, true); // turns to 3 rings in a line
    MoveEncoderPID(TestPara, -80, -50, 0.5, 180,false); // picks up the 3 rings that are in a line
    MoveEncoderPID(TestPara, -50, -35, 0.5, 180,false); 
    wait(100,msec);
    MoveEncoderPID(TestPara, 80, -8.7, 0.5, 180,false); // backs up
    wait(70,msec);
    TurnMaxTimePID(TestPara, -85, 0.4, false); // turns to side ring
    MoveEncoderPID(TestPara, -90, -9.3, 0.6, -85,true); // picks up side ring
    wait(120,msec);

    // PUTTING OTHER MOGO IN CORNER
    TurnMaxTimePID(TestPara, 15, 0.8, false); // turns so mogo faces corner
    wait(240,msec);
    MoveTimePID(TestPara, -75, 0.6, 0.2, 15, false); // backs up into corner
    RunRoller(0);
    MoveTimePID(TestPara, -30, 0.8, 0.2, 15, true); // backs up into corner
    wait(50,msec);
    Clamp.set(false);
    wait(50,msec);
    MoveEncoderPID(TestPara, -100, -6, 0.5, 32.5,true); // backs away from corner
    wait(50,msec);

    // ===========================================================================
    // OTHER SIDE 
    // ===========================================================================

    // CROSSING TO THE OTHER SIDE OF THE FIELD
    TurnMaxTimePID(TestPara, 0, 0.6, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, 110, 0.4, 0, true); // drives to past the white line
    wait(80,msec);
    TurnMaxTimePID(TestPara, 90, 0.3, true); // turns to next ring
    MoveEncoderPID(TestPara, -100, 37, 0.2, 90, true); // drives there
    wait(40,msec);
    RunRoller(0);

    // PUSHING MOGO INTO CORNER AND CLAMPING ANOTHER ONE
    TurnMaxTimePID(TestPara, -5, 0.4, true); // turns to face mogo
    MoveEncoderPID(TestPara, -100, -36, 0.2, -5, false); // drives into mogo
    TurnMaxTimePID(TestPara, -80, 0.3, false);
    MoveTimePID(TestPara, 100, 0.4, 0.4, -100, false);
    MoveTimePID(TestPara, 75, 1.2, 0.4, -80, false); // pushes mogo into corner ------ IMPORTANT VALUE

    MoveEncoderPID(TestPara, 100, -68, 0.4, -80, false); // drives backwards into next mogo
    MoveEncoderPID(TestPara, 30, -24, 0.4, -75, false); // slows down
    wait(50,msec);
    Clamp.set(true);
    wait(80,msec);

    // SCORES FINAL 
    TurnMaxTimePID(TestPara, 143, 0.5, false); // turns to next ring
    RunRoller(100);
    wait(30,msec);
    MoveEncoderPID(TestPara, -100, -39, 0.4, 143, true); // grabs ring
    TurnMaxTimePID(TestPara, 90, 0.2, false); // turns to next ring
    MoveEncoderPID(TestPara, -100, -24, 0.4, 90, true); // grabs ring

    TurnMaxTimePID(TestPara, 0, 0.6, false); // turns to the 2 rings in a row
    MoveEncoderPID(TestPara, -100, -17, 0.6, 0, false); // grabs both of the rings
    MoveEncoderPID(TestPara, -40, -25, 0.6, 0, false);
    wait(80,msec);
    MoveEncoderPID(TestPara, 80, -9, 0.4, 0, false); // backs up
    wait(20,msec);

    TurnMaxTimePID(TestPara, 80, 0.4, false); // turns to final ring
    MoveEncoderPID(TestPara, -100, -9, 0.4, 80, false); // grabs final ring
    wait(250,msec);
    TurnMaxTimePID(TestPara, -162, 0.2, true); // turns so mogo faces corner
    wait(300,msec);

    // PUTTING OTHER MOGO IN CORNER
    RunRoller(0);
    MoveTimePID(TestPara, -50, 1.2, 0.4, -162, true); // backs up into corner
    wait(50,msec);
    Clamp.set(false);
    wait(50,msec);
    MoveEncoderPID(TestPara, -100, -8, 0.4, -147.5,true); // drives away from corner
    wait(50,msec);
    RunArms(100);
    TurnMaxTimePID(TestPara, 50, 0.5, false); // Turns to face ladder
    MoveEncoderPID(TestPara, 100, -9, 0.3, 50,false);
    StopArms();
    wait(40,msec);
    MoveEncoderPID(TestPara, 100, -70, 0.4, 50,false);
    // MoveEncoderPID(TestPara, 100, -70, 0.4, 50,false);
    Move(100,100);

}