#include "display.hpp"
#include "program_state.hpp"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <U8g2lib.h>
#include <Wire.h>

#define MESSAGE_MAX_LEN 256

void setup() {
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
    if (p_program_state->sleep) {
        Serial.println("Sleeping...");
        uint16_t app_id = p_server->m_appId;

        char buf[32];
        sprintf(buf, "App id: %d\n", app_id);
        Serial.println(buf);
    } else {
        u8g2.clearBuffer();

        // if Serial buffer is not empty, write it on display
        if (Serial.available() > 0) {
            char msg[MESSAGE_MAX_LEN];

            Serial.readStringUntil('\n').toCharArray(
                msg, MESSAGE_MAX_LEN); // read message from Serial

            draw_message(msg); // drawing
        }
        draw_youpi();
        u8g2.sendBuffer();
    }

    delay(1000);
}