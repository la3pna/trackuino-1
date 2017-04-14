Trackuino
=========
Firmware to turn your Arduino into an APRS tracker. This is a fork of the [original mercurial repo](http://code.google.com/p/trackuino) by EA5HAV Javi and John Boiles. 
Changed to use the Si5351B by Thomas S. Knutsen LA3PNA.

Board support
-------------
This version is only able to work with the Si5351 clock generators. 

Building with the Arduino IDE
-----------------------------

Install the etherkit Si5351 library from: https://github.com/etherkit/Si5351Arduino#library-installation

1. Open `trackuino/trackuino.ino`
2. Locate the `config.h` tab and replace settings with your own (`S_CALLSIGN`, `APRS_COMMENT`, etc).
3. Select the appropriate board for your hardware setup!
5. Click Upload

