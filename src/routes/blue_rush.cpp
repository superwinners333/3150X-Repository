#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// make sure that heading stays the same between turns
// or not if u think you can do it without

void blue_rush() 
{
    PIDDataSet TestPara={1.5,0.1,0.15}; // this is important and DONT TOUCH THIS

    TurnMaxTimePID(TestPara, 15.2, 0.4, false); // rotates to center rings
    RightDoinker.set(true); // activates doinker to grab center rings
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, 55.5, 0.2, 15.2,true); // rushes to center rings
    wait(150,msec);
    // RunRoller(0); 
    MoveEncoderPID(TestPara, 30, 2.5, 0.2, 15.4,true); // slowly backs up
    RunRoller(0);
    TurnMaxTimePID(TestPara, 68, 0.4, true); // rotates to mogo -- IMPORTANT -- Change 60 to whatever bvalue is below
    MoveEncoderPID(TestPara, 80, 19, 0.4, 68,false); // backs up to mogo
    MoveEncoderPID(TestPara, 30, 16.3, 0.4, 63,false); // backs up to mogo
    wait(50,msec);
    Clamp.set(true); 
    RightDoinker.set(false); // lifts doinker to release stolen center ring
    RunRoller(100); // reruns motor
    wait(50,msec);
    TurnMaxTimePID(TestPara, 90, 0.4, false); // turns towards ring stack and stolen center ring
    MoveEncoderPID(TestPara, -80, 18, 0.2, 90,false); // drives towards them
    MoveEncoderPID(TestPara, -60, 18, 0.2, 90,false); // slows down to 60% speed
    wait(200,msec);
    
    MoveEncoderPID(TestPara, 100, 3, 0.2, 90,false); // backs up a bit
    wait(50,msec);
    TurnMaxTimePID(TestPara, 140, 0.4, false); // turns to corner    IMPORTANT -- change 140 to whatever value is below
    wait(50,msec);
    MoveEncoderPID(TestPara, -100, 39, 0.2, 145,false); // runs into corner
    MoveTimePID(TestPara, 70, 1.2, 0.2, 145, false); // slows down so we dont break the wall
    wait(200,msec);
    MoveEncoderPID(TestPara, 70, 16, 0.2, 145,true); // backs away from the corner

    TurnMaxTimePID(TestPara, -90, 0.4, true); // turns to stacked ring and preload ring
    wait(25,msec);
    MoveEncoderPID(TestPara, -100, 35, 0.2, -90,true); // drives towards preload ring
    wait(250,msec);
    Pistake.set(true);
    wait(50,msec);
    MoveEncoderPID(TestPara, -50, 13, 0.2, -90,false); // drives to stacked ring
    wait(150,msec);
    Pistake.set(false);
    wait(150,msec);

    TurnMaxTimePID(TestPara, -10, 0.4, false); // turns to face ladder
    wait(150,msec);
    MoveEncoderPID(TestPara, -80, 20, 0.5, -10,false); // drives into ladder
    wait(100,msec);
    RunArms(100); // Run Arms to touch bar
    wait(500,msec);
    RunArms(0);

}