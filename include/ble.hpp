#ifndef __BLESERVER__
#define __BLESERVER__

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

// encapsulate all ble stuffs
struct BLEState {
    BLEServer* p_server;
    BLEService* p_service;
    BLECharacteristic* p_characteristic;
    BLEAdvertising* p_advertising;
};

void init_ble_server();

#endif