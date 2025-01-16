
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include "display.hpp"
#include "program_state.hpp"

// BLE parameters
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class ActivationCallback : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* charac) {
        const char* val =
            charac->getValue().c_str();  // value received from ble client

        // if val is ON, then tower wake up, else tower is sleeping
        if (strcmp(val, "ON") == 0) {
            p_program_state->sleep = 0;  // wake up tower
            Serial.println("Tower waking up");
        } else {
            p_program_state->sleep = 1;
            charac->setValue("OFF");

            u8g2.clearDisplay();  // display is OFF when tower sleeping
            Serial.println("Tower going to sleep");
        }
    }
};

// BLE server initialization
void init_ble_server() {
    BLEDevice::init("ChienChienTower");
    BLEServer* p_server = BLEDevice::createServer();

    // service to manage tower sleep
    BLEService* p_service = p_server->createService(SERVICE_UUID);

    BLECharacteristic* p_charac = p_service->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE);  // r/w access

    p_charac->setValue("OFF");  // tower sleeping by default
    p_charac->setCallbacks(new ActivationCallback());

    // start service
    p_service->start();

    // make server visible
    BLEAdvertising* p_advertising = p_server->getAdvertising();
    p_advertising->start();

    // states initilization
    BLEState* p_ble_state = (BLEState*)malloc(sizeof(BLEState));
    p_ble_state->p_advertising = p_advertising;
    p_ble_state->p_characteristic = p_charac;
    p_ble_state->p_server = p_server;
    p_ble_state->p_service = p_service;

    // registering ble state into program state
    p_program_state->p_ble_state = p_ble_state;
}