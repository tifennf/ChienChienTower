
#include "display.hpp"
#include <U8g2lib.h>
#include <Wire.h>

// display's constructor, need to be in main for unknown reason
U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(
    U8G2_R0,
    /* reset=*/U8X8_PIN_NONE);  // EastRising 0.42" OLED

// display initialization
void init_display(void) {
    Wire.begin(SDA_PIN, SCL_PIN);  // permet la communication avec l'écran
    u8g2.begin();                  // on initialise la bibliothèque graphique
    u8g2.setFont(u8g2_font_ncenB08_tr);
    Serial.println("Display initialisation done");
}

// draw a happy person raising its arms
void draw_youpi() {
    u8g2.drawStr(10, 40, "\\ (o u o ) /");
}

// draw a message
void draw_message(char* msg) {
    Serial.print("Message affiché: ");
    Serial.println(msg);

    u8g2.drawStr(10, 30, msg);  // write msg in display's buffer
    draw_youpi();
}