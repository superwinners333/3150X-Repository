#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void red_positive() 
{   
    PIDDataSet TestPara={1.5,0.1,0.15};

    MoveEncoderPID(TestPara, 90, -19, 0.4, 0,true); // moves most of the way to mogo
    MoveEncoderPID(TestPara, 40, -5, 0.4, 0,true); // moves rest of the way to mogo
    
    wait(100,msec); 
    Clamp.set(true); // clamps onto mogo
    wait(100,msec);  
    TurnMaxTimePID(TestPara, -90, 1, true); // turns to face stacked rings
    RunRoller(100); // activates intake
    wait(100,msec);
    MoveEncoderPID(TestPara, -100, -18, 0.4, -90 ,true); // goes to stacked rings
    wait(150,msec);
    MoveEncoderPID(TestPara, 100, -9, 0.4, -90 ,true); // drives backwards a bit to get them out of the bot
    
    // 2 ring part ends here

    // TurnMaxTimePID(TestPara, -135, 1, true);
    // MoveEncoderPID(TestPara, -100, -13, 0.4, -135 ,true);
    // wait(200,msec);
    // MoveEncoderPID(TestPara, 100, -13, 0.4, -135 ,true);

    // sketch part

    // --------------------------------------
    // TurnMaxTimePID(TestPara, 45, 1, true);
    // wait(500,msec);
    // Clamp.set(false);
    // MoveEncoderPID(TestPara, -100, -20, 0.4, 45 ,true); // drives accross to middle
    // TurnMaxTimePID(TestPara, -48, 1, true); // rotates to mogo
    // MoveEncoderPID(TestPara, 100, -17, 0.4, -48 ,true); // drives to mogo
    // MoveEncoderPID(TestPara, 40, -5, 0.4, -48,true);
    // wait(100,msec);
    // Clamp.set(true);
    // wait(100,msec);
    // TurnMaxTimePID(TestPara, 90, 1, true); // turns to rings on other side
    // MoveEncoderPID(TestPara, -100, -13, 0.4, 90 ,true); // drives to rings
    // TurnMaxTimePID(TestPara, -135, 1, true);
    // wait(100,msec);
    // MoveEncoderPID(TestPara, -80, -24, 0.4, -135 ,true);
    // ------------------------------------
    
    // this stuff down here just makes the bot touch the ladder

    // TurnMaxTimePID(TestPara, -45, 1, true);
    // RunRoller(0);
    // MoveEncoderPID(TestPara, 100, -6, 0.4, -45 ,true); 
}