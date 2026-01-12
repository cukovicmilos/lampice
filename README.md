# Lampice

ESP8266 D1 Mini projekat za kontrolu "glupih" LED lampica koje imaju fizički taster za promenu režima.

## Kako radi

Čip simulira pritiske tastera na pinu D1 - šalje HIGH/LOW signale koji menjaju režim lampica bez potrebe za fizičkim pritiskom.

## Hardware

- **ESP8266 D1 Mini**
- LED lampice sa tasterom za promenu režima

## Povezivanje

| D1 Mini | Lampice |
|---------|---------|
| D1 (GPIO5) | Taster (signal) |
| GND | GND |

## Konfiguracija

U `button_click.ino`:

```cpp
const int BROJ_KLIKOVA = 3;  // Broj simuliranih klikova
delay(300);                   // Trajanje HIGH signala (ms)
delay(800);                   // Pauza između klikova (ms)
```

## Upload

```bash
arduino-cli compile --fqbn esp8266:esp8266:d1_mini ./button_click
arduino-cli upload -p /dev/cu.usbserial-210 --fqbn esp8266:esp8266:d1_mini ./button_click
```

## Debug

Ugrađeni LED na D1 Mini (D4) treperi pri svakom simuliranom kliku. Serial monitor na 115200 baud prikazuje status.
