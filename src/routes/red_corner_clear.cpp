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

    TurnMaxTimePID(TestPara, 34, 0.4, true);
    RunArms(100);
    MoveEncoderPID(TestPara,-50,1.1,0.2,34,true);
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
    wait(240,msec);
    MoveEncoderPID(TestPara,100,16,0.2,50,false); // drives away
    wait(20,msec);
    TurnMaxTimePID(TestPara, -100, 0.3, false); // turns to next ring
    MoveEncoderPID(TestPara,-100,34,0.5,-100,false); // drives into next ring

    // MoveEncoderPID(TestPara,100,30,0.4,-130,false);  // drives away
    wait(15,msec);
    TurnMaxTimePID(TestPara, -15, 0.6, false); // turns to face corner

    wait(20,msec);
    // Doinker.set(true);
    MoveEncoderPID(TestPara,-75,55,0.5,-20,true); // moves to corner ring
    RunRoller(-100);
    MoveEncoderPID(TestPara,-75,14,0.5,-20,true);

    // TurnMaxTimePID(TestPara, 40, 0.2, false); // sweeps
    // Doinker.set(false);
    // TurnMaxTimePID(TestPara, -30, 0.4, false);

    wait(100,msec);
    RunRoller(100);

    wait(50,msec);
    MoveEncoderPID(TestPara,-100,7,0.3,-30,true); // runs into corner more

    wait(70,msec);
    MoveEncoderPID(TestPara,15,9,0.4,-30,true); // drives away from corner
    wait(20,msec);

    Doinker.set(true);
    wait(40,msec);
    MoveEncoderPID(TestPara,-100,3,0.4,-20,true);
    wait(50,msec);
    TurnMaxTimePID(TestPara, 30,0.4, false);
    Doinker.set(false);
    wait(50,msec);
    TurnMaxTimePID(TestPara, 180, 0.4, false);
    // Clamp.set(false);
    MoveEncoderPID(TestPara,-100,4,0.4,180,false);

}