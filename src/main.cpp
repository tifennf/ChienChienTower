// #include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "display.hpp"

// BLE parameters
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define MESSAGE_MAX_LEN 256

// State
struct ProgramState {
    BLEServer* p_server;
    BLEService* p_service;
    BLECharacteristic* p_characteristic;
    BLEAdvertising* p_advertising;
};

ProgramState state;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    // display init
    init_display();

    // BLE server init
    BLEDevice::init("ChienChienTower");
    BLEServer* p_server = BLEDevice::createServer();
    BLEService* p_service = p_server->createService(SERVICE_UUID);
    BLECharacteristic* p_charac = p_service->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE);  // r/w access

    p_charac->setValue("Test");

    p_service->start();

    // make server visible
    BLEAdvertising* p_advertising = p_server->getAdvertising();
    p_advertising->start();

    // program state init
    state.p_server = p_server;
    state.p_service = p_service;
    state.p_characteristic = p_charac;
    state.p_advertising = p_advertising;
}
void loop() {
    u8g2.clearBuffer();
    if (Serial.available() > 0) {
        char msg[MESSAGE_MAX_LEN];
        Serial.readStringUntil('\n').toCharArray(msg, MESSAGE_MAX_LEN);
        draw_message(msg);
    }
    draw_youpi();
    u8g2.sendBuffer();

    delay(1000);
}