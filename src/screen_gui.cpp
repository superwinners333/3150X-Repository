#include "screen_gui.hpp"
#include "vex.h"

bool OtherCodes = false;
void DisplayAutoSelector(void)
{

  Brain.Screen.clearScreen();

//auton selector
Brain.Screen.setFont(monoM);
Brain.Screen.setFillColor(black);
Brain.Screen.setCursor(1,1);
Brain.Screen.setPenWidth(3);
Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.drawRectangle(1,25,100,50);

Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.drawRectangle(375,25,100,50);

Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.drawRectangle(1,100,100,50);

Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.drawRectangle(375,100,100,50);

Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.drawRectangle(1,175,100,50);

Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.drawRectangle(375,175,100,50);

Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.drawRectangle(187,5,100,50);

Brain.Screen.setPenColor("#FFC0CB");
Brain.Screen.drawRectangle(187,175,100,50);
}

void DisplayWords(void)
{
  Brain.Screen.setPenColor("#FFC0CB");
  Brain.Screen.setFont(monoM);
  //-----------------------------------------------//

  if (!OtherCodes){
    Brain.Screen.setCursor(3,3);
    Brain.Screen.print("BLUE+");
  }
  if (OtherCodes){
    Brain.Screen.setCursor(3,3);
    Brain.Screen.print("B+CLEAR");
  }
  //-----------------------------------------------//
  if (!OtherCodes){
    Brain.Screen.setCursor(7,3);
    Brain.Screen.print("BLUE-");
  }
  if (OtherCodes){
    Brain.Screen.setCursor(7,3);
    Brain.Screen.print("BLUE 6");
  }
  //-----------------------------------------------//
  if (!OtherCodes){
    Brain.Screen.setCursor(3,40);
    Brain.Screen.print("BLUE-AWP");
  }
  if (OtherCodes){
    Brain.Screen.setCursor(3,40);
    Brain.Screen.print("B-RUSH");
  }
  //-----------------------------------------------//
  if (!OtherCodes){
    Brain.Screen.setCursor(7,40);
    Brain.Screen.print("RED+");
  }
  if (OtherCodes){
    Brain.Screen.setCursor(7,40);
    Brain.Screen.print("R+CLEAR");
  }
  //-----------------------------------------------//

  if (!OtherCodes){
    Brain.Screen.setCursor(11,3);
    Brain.Screen.print("RED-");
  }
  if (OtherCodes){
    Brain.Screen.setCursor(11,3);
    Brain.Screen.print("RED 6");
  }
  //-----------------------------------------------//
  if (!OtherCodes){
    Brain.Screen.setCursor(11,40);
    Brain.Screen.print("RED-AWP");
  }
  if (OtherCodes){
    Brain.Screen.setCursor(11,40);
    Brain.Screen.print("R-RUSH");
  }
  //-----------------------------------------------//

  Brain.Screen.setCursor(11,22);
  Brain.Screen.print("Toggle"); // Skills
}

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
int AutoSelectorVal;

void UpdateDynamic(void)
{
  DisplayAutoSelector();
  DisplayWords();
  Brain.Screen.setFillColor("#FFC0CB");
  Brain.Screen.setPenColor(black);

// ---------------------------------------------------------------- //
if(AutoSelectorVal==1){
  if (!OtherCodes){
    Brain.Screen.drawRectangle(1,25,100,50);
    Brain.Screen.setCursor(3,3);
    Brain.Screen.print("BLUE+");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Blue Positive");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE+");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes){
    Brain.Screen.drawRectangle(1,25,100,50);
    Brain.Screen.setCursor(3,3);
    Brain.Screen.print("B+CLEAR");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Blue Corner Clear");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE+");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==2){
  if (!OtherCodes){
    Brain.Screen.drawRectangle(375,25,100,50);
    Brain.Screen.setCursor(3,40);
    Brain.Screen.print("BLUE AWP");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Solo AWP");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE-");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes){
    Brain.Screen.drawRectangle(375,25,100,50);
    Brain.Screen.setCursor(3,40);
    Brain.Screen.print("RED RUSH");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Ring Rush");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE-");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==3){
  if (!OtherCodes){
    Brain.Screen.drawRectangle(1,100,100,50);
    Brain.Screen.setCursor(7,3);
    Brain.Screen.print("BLUE-");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Blue Negative");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE-");
    Brain.Screen.setFont(monoM);  
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes){
    Brain.Screen.drawRectangle(1,100,100,50);
    Brain.Screen.setCursor(7,3);
    Brain.Screen.print("BLUE 6");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Blue Six");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BLUE-");
    Brain.Screen.setFont(monoM);  
    Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==4){
  if (!OtherCodes){
    Brain.Screen.drawRectangle(375,100,100,50);
    Brain.Screen.setCursor(7,40);
    Brain.Screen.print("RED+");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Red Positive");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED+");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes){
    Brain.Screen.drawRectangle(375,100,100,50);
    Brain.Screen.setCursor(7,40);
    Brain.Screen.print("R+CLEAR");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Red Corner Clear");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED+");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==5){
  if (!OtherCodes){
    Brain.Screen.drawRectangle(1,175,100,50);
    Brain.Screen.setCursor(11,3);
    Brain.Screen.print("RED-");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Red Negative");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED-");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes){
    Brain.Screen.drawRectangle(1,175,100,50);
    Brain.Screen.setCursor(11,3);
    Brain.Screen.print("RED 6");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Red Six");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED-");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==6){
  if (!OtherCodes){
    Brain.Screen.drawRectangle(375,175,175,50);
    Brain.Screen.setCursor(11,40);
    Brain.Screen.print("RED AWP");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Solo AWP");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED-");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
  if (OtherCodes){
    Brain.Screen.drawRectangle(375,175,175,50);
    Brain.Screen.setCursor(11,40);
    Brain.Screen.print("RED RUSH");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FFC0CB");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Ring Rush");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RED-");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#FFC0CB");
  }
}
// ---------------------------------------------------------------- //
if(AutoSelectorVal==7){
  Brain.Screen.drawRectangle(187,175,100,50);
  Brain.Screen.setCursor(11,22);
  Brain.Screen.print("Skills"); // Skills
  Brain.Screen.setFillColor(black);
  Brain.Screen.setFont(monoXL);
  Brain.Screen.setPenColor("#FFC0CB");
  Brain.Screen.setCursor(3,10);
  Brain.Screen.print("SKILLS"); // SKILLS
  Brain.Screen.setCursor(4,10);
  Brain.Screen.print("SKILLS"); // SKILLS
  Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#FFC0CB");
}

}
