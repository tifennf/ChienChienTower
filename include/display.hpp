#ifndef __DISPLAY__
#define __DISPLAY__

#include <Arduino.h>
#include <U8g2lib.h>

// display parameters
#define SDA_PIN 5  // là où passent les données
#define SCL_PIN 6  // clock pour gérér la synchro ?
#define MAX_X 72
#define MAX_Y 40

extern U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2;

int parse_msg(String msg, char** res);

void draw_youpi();
void print_youpi();

void init_display();

void draw_message(char* msg);

#endif
