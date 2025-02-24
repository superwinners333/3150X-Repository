#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void red_corner_clear() 
{ // NEGATIVE IS TO THE LEFT
    PIDDataSet TestPara={1.5,0.1,0.15};

    TurnMaxTimePID(TestPara, 36, 0.4, true);
    RunArms(100);
    MoveEncoderPID(TestPara,-50,1.1,0.2,36,true);
    wait(175,msec);
    RunArms(0);
    TurnMaxTimePID(TestPara, 25, 1, true);

    MoveEncoderPID(TestPara,80,28,0.2,25,true); // drives towards mogo
    RunArms(-100);
    MoveEncoderPID(TestPara,30,10,0.2,16,true); // slows down and turns
    Clamp.set(true);
    wait(80,msec);
    RunArms(0);
    
    TurnMaxTimePID(TestPara, 50, 0.8, false);
    Pistake.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara,-100,17,0.3,50,false); // grabs first ring
    Pistake.set(false);
    wait(220,msec);
    MoveEncoderPID(TestPara,90,16.5,0.8,-50,false); // backs away
    wait(20,msec);
    TurnMaxTimePID(TestPara, -99, 0.3, false); // turns to second ring
    MoveEncoderPID(TestPara,-100,26,0.5,-99,false); // grabs second ring
    TurnMaxTimePID(TestPara, -20, 0.4, false); // turns towards corner
    MoveEncoderPID(TestPara,-100,33,0.4,-23,false); // runs into corner
    MoveTimePID(TestPara,50,1.2,0.4,-23,false);  // runs into corner
   
    wait(200,msec);
    MoveEncoderPID(TestPara,40,2.9,0.3,-23,false); // backs up to activate pistake
    Pistake.set(true);
    wait(150,msec);
    MoveEncoderPID(TestPara,-100,3.6,0.2,-23,false); // runs into corner again
    wait(150,msec);
    Pistake.set(false);
    wait(150,msec);
    MoveEncoderPID(TestPara,90,4,0.4,-40,false); // drives away from corner rings
    
    wait(50,msec);
    Doinker.set(true);
    wait(50,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara,-100,6,0.2,-40,false); // drives to place doinker in optimal place to sweep
    wait(50,msec);
    TurnMaxTimePID(TestPara, 40, 0.3, true); // sweeps corner
    wait(20,msec);
    RunRoller(100);
    MoveEncoderPID(TestPara,100,2,0.4,40,false); // backs up a bit
    wait(20,msec);
    Doinker.set(false);
    wait(50,msec);
    
    TurnMaxTimePID(TestPara, 150, 0.4, false); // turns so mogo faces corner
    RunRoller(0);
    wait(50,msec);
    MoveTimePID(TestPara, -100, 0.8, 0.2, 150, false); // backs up into corner to release mogo
    wait(50,msec);
    Clamp.set(false);
    wait(50,msec);
    MoveEncoderPID(TestPara,-100,5,0.2,150,false); // drives forward away from corner
    TurnMaxTimePID(TestPara, 0, 0.5, false); // turns so back faces center mogo
    MoveEncoderPID(TestPara,100,9,0.2,0,false); 

}