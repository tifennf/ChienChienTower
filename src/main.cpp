// #include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "display.hpp"
#include "program_state.hpp"

#define MESSAGE_MAX_LEN 256

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    // program state init
    init_program_state();

    // display init
    init_display();

    // BLE server init
    init_ble_server();
}
void loop() {
    // waiting for activation (BLE)
    while (p_program_state->sleep) {
        Serial.println("Sleeping...");
        delay(1000);
    }

    u8g2.clearBuffer();

    // if Serial buffer is not empty, write it on display
    if (Serial.available() > 0) {
        char msg[MESSAGE_MAX_LEN];

        Serial.readStringUntil('\n').toCharArray(
            msg, MESSAGE_MAX_LEN);  // read message from Serial

        draw_message(msg);  // drawing
    }
    draw_youpi();
    u8g2.sendBuffer();

    delay(1000);
}