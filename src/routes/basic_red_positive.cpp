#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// make sure that heading stays the same between turns
// or not if u think you can do it without

void basic_red_positive() 
{
    PIDDataSet TestPara={1.5,0.1,0.15}; // this is important and DONT TOUCH THIS

    MoveEncoderPID(TestPara, 100, -23, 0.4, 0,true); // this just moves the bot backwards

    MoveEncoderPID(TestPara, 40, -5, 0.4, 0,true); // keep the travel distance as a negative and change motor speed to negative to go forward
    // also travel distance isnt really in inches
    // i heard that just get the number u put in and divide by two for the actual distance

    wait(250,msec); // put some waits in between code if u want 

    Clamp.set(true); // true turns on the clamp, false turns it off

    TurnMaxTimePID(TestPara, 90, 0.9, true); // this turns the bot
    // the heading is also relative to starting position
    // so its just turning to 90 degrees relative to starting position
    // instead of actually turning 90 degrees
    // also this turns right (i think)
    // so -90 turns left 90 degrees

    RunRoller(100); // sets intake at ur desired speed. positive integer will intake it, negative will outake
}