#include <Wire.h>
#include "font.h"

#define OLED_address  0x3c                                // all the OLED's I have seen have this address
//#define offset 0x00    // SDD1306                       // offset=0 for SSD1306 controller
#define offset 0x02    // SH1106                          // offset=2 for SH1106 controller

//==========================================================//
// Resets display depending on the actual mode.
static void reset_display(void)
{
  displayOff();
  clear_display();
  displayOn();
}

//==========================================================//
// Turns display on.
void displayOn(void)
{
  sendcommand(0xaf);        //display on
}

//==========================================================//
// Turns display off.
void displayOff(void)
{
  sendcommand(0xae);    //display off
}

//==========================================================//
// Clears the display by sendind 0 to all the screen map.
static void clear_display(void)
{
  unsigned char i, k;
  for (k = 0; k < 8; k++)
  {
    setXY(k, 0);
    {
      for (i = 0; i < (128 + 2 * offset); i++) //locate all COL
      {
        SendChar(0);         //clear all COL
        //delay(10);
      }
    }
  }
}
