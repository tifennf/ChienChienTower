from bleak import BleakClient
import asyncio

import argparse


parser = argparse.ArgumentParser(
    description="Script d'activation/desactivation pour CCT"
)

parser.add_argument("--message", help="message to send", default="OFF", type=str)

args = parser.parse_args()

address = "84:F7:03:67:FF:1E"

ACTIVATION_CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8"


async def main(address):
    async with BleakClient(address) as client:

        msg = args.message.encode("utf-8")
        await client.write_gatt_char(ACTIVATION_CHARACTERISTIC_UUID, msg)


asyncio.run(main(address))
