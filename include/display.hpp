#ifndef __DISPLAY__
#define __DISPLAY__

#include <Arduino.h>
#include <U8g2lib.h>

extern U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2;  // display object

void init_display();

void draw_youpi();
void draw_message(char* msg);

#endif
