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
    wait(50,msec);
    TurnMaxTimePID(TestPara, -90, 0.4, true); // turns towards mogo
    wait(50,msec);
    MoveEncoderPID(TestPara, 100, -14, 0.3, -90,false); // goes to mogo
    MoveEncoderPID(TestPara, 30, -18, 0.2, -90,false); // slows down going to mogo
    wait(20,msec);
    Clamp.set(true); // clamps to mogo
    wait(100,msec);
    TurnMaxTimePID(TestPara, 0, 0.4, true); // turns to ring between bot and ladder
    wait(60,msec);
    MoveEncoderPID(TestPara, -100, -30.3, 0.3, 0,true); // drives to the ring between bot and ladder

    // WALL STAKES
    wait(80,msec);
    TurnMaxTimePID(TestPara, 39.3, 0.2, true); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -27.8, 0.3, 39.3,true); // drives to rings in front of wall stake
    wait(20,msec);
    Macro(); // activates macro
    wait(20,msec);
    TurnMaxTimePID(TestPara, 90, 0.4, false); // turns towards wall stake
    wait(20,msec);
    // MoveTimePID(TestPara, 35, 2.4, 0.7, 90, true); // runs into wall stake
    // Macro(); // activates macro
    Move(-35,-35);
    wait(2.4,sec);
    wait(200,msec);

    // Move(-70,-70);
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
    wait(0.4,sec);
    Move(0,0);

    RunArms(0);
    wait(20,msec);
    MoveEncoderPID(TestPara, 100, -5.6, 0.4, 90,false); // moves back
    RunArms(-100);
    wait(500,msec);
    RunArms(0);
    // MoveEncoderPID(TestPara, 100, -3.3, 0.2, 90,false); // moves back

    // CORNER RINGS
    wait(20,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -170, 0.2, true); // turns to in front of wall stake
    wait(50,msec);
    MoveEncoderPID(TestPara, -80, -46, 0.6, 180,false); // picks up the 3 rings that are in a line
    MoveEncoderPID(TestPara, -50, -46, 0.2, 180,false);
    wait(100,msec);
    MoveEncoderPID(TestPara, 75, -10.3, 0.6, 180,false); // backs up
    wait(50,msec);
    TurnMaxTimePID(TestPara, 85, 0.4, false); // turns to side ring
    MoveEncoderPID(TestPara, -100, -10.5, 0.2, 85,true); // picks up side ring 
    wait(280,msec);
    MoveEncoderPID(TestPara, 100, 0.5, 0.2, 85,false); // backs away

    TurnMaxTimePID(TestPara, -28, 0.5, true); // turns so mogo faces corner

    // PUTTING OTHER MOGO IN CORNER
    wait(350,msec);
    MoveTimePID(TestPara, -100, 0.4, 0.4, -28, false); // backs up into corner
    RunRoller(0);
    MoveTimePID(TestPara, -50, 1.2, 0.2, -28, false); 
    wait(70,msec);
    Clamp.set(false);
    wait(250,msec);
    MoveEncoderPID(TestPara, -100, -4.5, 0.3, -40,true); // drives away from corner
    wait(70,msec);
    TurnMaxTimePID(TestPara, 90, 0.7, true); // rotate towards mogo on other side 
    // TurnMaxTimePID(TestPara, 90, 0.7, true);

    // =======================================================================================
    // NEXT CORNER 
    // =======================================================================================

    wait(50,msec);
    MoveEncoderPID(TestPara, 100, -103, 0.6, 90, false); // drives to mogo
    MoveEncoderPID(TestPara, 30, -34.5, 0.2,90,false); // slows down before grabbing mogo
    wait(30,msec);
    Clamp.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 0, 0.4, true); // turns to ring between bot and ladder
    RunRoller(100);
    wait(20,msec);
    MoveEncoderPID(TestPara, -100, -27, 0.2, 0,true); // drives to the ring between bot and ladder

    // OTHER SIDE WALL STAKES
    wait(20,msec);
    TurnMaxTimePID(TestPara, -37.8, 0.4, false); // turns to in front of wall stake
    MoveEncoderPID(TestPara, -100, -28, 0.2, -37.8, true); // drives to in front of wall stake
    wait(40,msec);
    Macro(); // activates macro
    TurnMaxTimePID(TestPara, -90, 0.4, false); // turns towards wall stake
    // MoveTimePID(TestPara, 30, 2.3, 0.2, -90, true); // runs into wall stake
    // Macro(); // activates macro
    Gyro.setHeading(270,degrees);
    Move(-30,-30);
    wait(2.4,sec);
    wait(200,msec);

    // Move(-70,-70);
    RunRoller(0);
    wait(60,msec);
    RunRoller(100); // stutters intake
    wait(70,msec);
    RunRoller(0); // stutters intake
    wait(60,msec);
    RunRoller(100); // stutters intake
    wait(70,msec);

    RunRoller(0);
    wait(20,msec);
    Move(-35,-35);
    RunArms(100); // scores on wall stake
    wait(0.36,sec);
    RunArms(0); // scores on wall stake
    wait(20,msec);
    // Gyro.setHeading(270,degrees);
    Move(0,0);

    RunArms(0);
    MoveEncoderPID(TestPara, 100, -12.5, 0.4, -90,true); // moves back
    
    wait(450,msec);
    RunArms(-100);
    // MoveEncoderPID(TestPara, 100, -3.9, 0.4, -90,false); // moves back

    // OTHER SIDE CORNER RINGS
    wait(50,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 180, 0.4, true); // turns to 3 rings in a line  // 189
    RunArms(0);
    wait(60,msec);
    MoveEncoderPID(TestPara, -80, -44, 0.5, 180,false); // picks up the 3 rings that are in a line
    MoveEncoderPID(TestPara, -50, -39, 0.5, 180,false); 
    wait(100,msec);
    MoveEncoderPID(TestPara, 80, -9.8, 0.5, 180,false); // backs up 
    wait(70,msec);
    TurnMaxTimePID(TestPara, -85, 0.4, false); // turns to side ring -85
    MoveEncoderPID(TestPara, -90, -9.3, 0.6, -85,true); // picks up side ring
    wait(120,msec);

    // PUTTING OTHER MOGO IN CORNER
    TurnMaxTimePID(TestPara, 27, 0.8, false); // turns so mogo faces corner +5
    wait(500,msec);
    RunRoller(0);
    MoveTimePID(TestPara, -75, 0.6, 0.2, 27, false); // backs up into corner
    MoveTimePID(TestPara, -30, 0.8, 0.2, 27, true); // backs up into corner
    wait(250,msec);
    Clamp.set(false);
    wait(50,msec);
    MoveEncoderPID(TestPara, -100, 8, 0.5, 40,false); // backs away from corner
    wait(50,msec);

    // ===========================================================================
    // OTHER SIDE 
    // ===========================================================================

    // CROSSING TO THE OTHER SIDE OF THE FIELD
    TurnMaxTimePID(TestPara, 0, 0.6, true);
    
    MoveEncoderPID(TestPara, -100, 100, 0.4, 0, true); // drives to past the white line
    wait(80,msec);
    RunRoller(60);
    TurnMaxTimePID(TestPara, 90, 0.4, true); // turns to next ring
    MoveEncoderPID(TestPara, -100, 30, 0.4, 90, true); // drives to it
    wait(40,msec);
    // Gyro.setHeading(0,degrees);
    
    // PUSHING MOGO INTO CORNER AND CLAMPING ANOTHER ONE
    TurnMaxTimePID(TestPara, -7, 0.4, true); // turns to face mogo
    RunRoller(0);
    MoveEncoderPID(TestPara, -100, -34, 0.2, -7, false); // drives into mogo
    
    TurnMaxTimePID(TestPara, -90, 0.3, false);
    MoveTimePID(TestPara, 100, 1.3, 0.4, -90, false);
    // MoveTimePID(TestPara, 40, 1.3, 0.4, -80, false); // pushes mogo into corner ------ IMPORTANT VALUE

    MoveEncoderPID(TestPara, 100, 2, 0.4, -80, false);
    wait(50,msec);
    TurnMaxTimePID(TestPara, -70, 0.3, false);

    MoveEncoderPID(TestPara, 100, -64, 0.4, -70, false); // drives backwards into next mogo
    MoveEncoderPID(TestPara, 30, -35, 0.4, -70, false); // slows down
    wait(50,msec);
    Clamp.set(true);
    wait(80,msec);

    // SCORES FINAL 
    TurnMaxTimePID(TestPara, 158, 0.5, false); // turns to next ring
    RunRoller(100);
    wait(30,msec);
    MoveEncoderPID(TestPara, -100, -21, 0.4, 158, true); // grabs ring
    TurnMaxTimePID(TestPara, 90, 0.2, false); // turns to next ring
    MoveEncoderPID(TestPara, -100, -27, 0.4, 90, true); // grabs ring

    TurnMaxTimePID(TestPara, 0, 0.6, false); // turns to the 2 rings in a row
    MoveEncoderPID(TestPara, -80, -22, 0.6, 0, false); // grabs both of the rings
    MoveEncoderPID(TestPara, -50, -23, 0.6, 0, false);
    wait(80,msec);
    MoveEncoderPID(TestPara, 100, -5, 0.4, 0, false); // backs up
    wait(20,msec);

    TurnMaxTimePID(TestPara, 95, 0.4, false); // turns to final ring
    MoveEncoderPID(TestPara, -100, -8.5, 0.4, 95, false); // grabs final ring
    Doinker.set(true);
    wait(250,msec);
    TurnMaxTimePID(TestPara, 0, 0.2, true); // turns so mogo faces corner
    TurnMaxTimePID(TestPara, -152, 0.2, true); // turns so mogo faces corner
    Doinker.set(false);
    wait(300,msec);

    // PUTTING OTHER MOGO IN CORNER
    
    MoveTimePID(TestPara, -50, 1, 0.4, -152, true); // backs up into corner
    wait(50,msec);
    Clamp.set(false);
    RunRoller(0);
    wait(50,msec);
    MoveEncoderPID(TestPara, -100, -6, 0.4, -147.5,true); // drives away from corner
    wait(50,msec);
    RunArms(100);
    TurnMaxTimePID(TestPara, 50, 0.5, false); // Turns to face ladder
    MoveEncoderPID(TestPara, 100, -9, 0.3, 50,false);
    StopArms();
    wait(40,msec);
    // Doinker.set(false);
    MoveEncoderPID(TestPara, 100, -70, 0.4, 60,false);
    // MoveEncoderPID(TestPara, 100, -70, 0.4, 50,false);
    Move(100,100);

}