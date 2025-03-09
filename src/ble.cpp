
#include "display.hpp"
#include "program_state.hpp"
#include <Arduino.h>
#include <BLE2902.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

// Service and activation charac uuid
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define ACTIVATION_CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLEServer *p_server = NULL;
BLECharacteristic *p_charac = NULL;
bool deviceConnected = false;

class ServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer *pServer) {
        deviceConnected = true;
        Serial.println("Client connecté");
    };

    void onDisconnect(BLEServer *pServer) {
        deviceConnected = false;
        Serial.println("Client déconnecté");
        // restart advertissing in order to enable new connections
        pServer->startAdvertising();
    }
};

class ActivationCallback : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *charac) {
        const char *val =
            charac->getValue().c_str(); // value received from ble client

        // if val is ON, then tower wake up, else tower is sleeping
        if (strcmp(val, "ON") == 0) {
            p_program_state->sleep = false; // wake up tower
            Serial.println("Tower waking up");
        } else {
            p_program_state->sleep = true;
            charac->setValue("OFF");

            u8g2.clearDisplay(); // display is OFF when tower sleeping
            Serial.println("Tower going to sleep");
        }
    }
};

// BLE server initialization
void init_ble_server() {
    BLEDevice::init("ChienChienTower");
    p_server = BLEDevice::createServer();

    p_server->setCallbacks(new ServerCallbacks());

    // service to manage tower sleep
    BLEService *p_service = p_server->createService(SERVICE_UUID);
    p_charac = p_service->createCharacteristic(
        ACTIVATION_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE |
            BLECharacteristic::PROPERTY_NOTIFY); // r/w access

    // added descriptor
    p_charac->addDescriptor(new BLE2902());

    // default value
    p_charac->setValue("OFF"); // tower sleeping by default

    // add callback for charac
    p_charac->setCallbacks(new ActivationCallback());

    // start service
    p_service->start();

    // make server visible
    BLEAdvertising *p_advertising = BLEDevice::getAdvertising();
    p_advertising->addServiceUUID(SERVICE_UUID);
    p_advertising->setScanResponse(true);
    p_advertising->setMinPreferred(0x12);

    BLEDevice::startAdvertising();
}