
#include "display.hpp"
#include <U8g2lib.h>
#include <Wire.h>

// display's constructor, need to be in main for unknown reason
U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(
    U8G2_R0,
    /* reset=*/U8X8_PIN_NONE);  // EastRising 0.42" OLED

// parse and clean msg into buffer
int parse_msg(String msg, char** res) {
    msg.trim();
    msg.toCharArray(*res, 256, 0);

    return 0;
}

void draw_youpi() {
    u8g2.drawStr(10, 40, "\\ (o u o ) /");
}

void print_youpi() {
    u8g2.clearBuffer();
    draw_youpi();
    u8g2.sendBuffer();
}

void init_display(void) {
    // display init
    Wire.begin(SDA_PIN, SCL_PIN);  // permet la communication avec l'écran
    u8g2.begin();                  // on initialise la bibliothèque graphique
    u8g2.setFont(u8g2_font_ncenB08_tr);
    Serial.println("Display initialisation done");
}

void print_message(char* msg) {
    u8g2.clearBuffer();

    Serial.print("Message envoyé : ");
    Serial.println(msg);

    u8g2.drawStr(10, 30, msg);  // on écrit le message dans le buffer
    u8g2.drawStr(10, 40, "\\ (o u o ) /");

    u8g2.sendBuffer();  // on écrit le buffer via Wire pour l'afficher sur
}