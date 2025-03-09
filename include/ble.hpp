#ifndef __BLESERVER__
#define __BLESERVER__

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

// exporting ptr
extern BLEServer *p_server;
extern BLECharacteristic *p_charac;

void init_ble_server();

#endif