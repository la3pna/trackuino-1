/* trackuino copyright (C) 2010  EA5HAV Javi

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__


// --------------------------------------------------------------------------
// THIS IS THE TRACKUINO FIRMWARE CONFIGURATION FILE. YOUR CALLSIGN AND
// OTHER SETTINGS GO HERE.
//
// NOTE: all pins are Arduino based, not the Atmega chip. Mapping:
// http://www.arduino.cc/en/Hacking/PinMapping
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Board Config
// --------------------------------------------------------------------------

// You must include a board config file that specifies the pins used by your
// hardware.

//#include "config_board_tiny_trackuino.h"
//#include "config_board_trackuino_shield.h"
#include "config_board_pnatracker.h"

// --------------------------------------------------------------------------
// APRS config (aprs.c)
// --------------------------------------------------------------------------

// Set your callsign and SSID here. Common values for the SSID are
// (from http://zlhams.wikidot.com/aprs-ssidguide):
//
// - Balloons:  11
// - Cars:       9
// - Home:       0
// - IGate:      5
#define S_CALLSIGN      "LA3PNA"
#define S_CALLSIGN_ID   11

// Destination callsign: APRS (with SSID=0) is usually okay.
#define D_CALLSIGN      "APRS"
#define D_CALLSIGN_ID   0

// Digipeating paths:
// (read more about digipeating paths here: http://wa8lmf.net/DigiPaths/ )
// The recommended digi path for a balloon is WIDE2-1 or pathless. The default
// is pathless. Uncomment the following two lines for WIDE2-1 path:
#define DIGI_PATH1      "WIDE2"
#define DIGI_PATH1_TTL  1

// Symbol table and code: '/' for primary table, code 'O' for balloon, '-' for QTH.
#define SYMBOL_TABLE    '/'
#define SYMBOL_CODE     'l'

// APRS comment: this goes in the comment portion of the APRS message. You
// might want to keep this short. The longer the packet, the more vulnerable
// it is to noise.
#define APRS_COMMENT    "PNAtracker test"


// --------------------------------------------------------------------------
// AX.25 config (ax25.cpp)
// --------------------------------------------------------------------------

// TX delay in milliseconds
#define TX_DELAY      1000

// --------------------------------------------------------------------------
// Tracker config (trackuino.ino)
// --------------------------------------------------------------------------

// APRS packets are slotted so that multiple trackers can be used without
// them stepping on one another. The transmission times are governed by
// the formula:
//
//         APRS_SLOT (seconds) + n * APRS_PERIOD (seconds)
//
// When launching multiple balloons, use the same APRS_PERIOD in all balloons
// and set APRS_SLOT so that the packets are spaced equally in time.
// Eg. for two balloons and APRS_PERIOD = 60, set APRS_SLOT to 0 and 30,
// respectively. The first balloon will transmit at 00:00:00, 00:01:00,
// 00:02:00, etc. amd the second balloon will transmit at 00:00:30, 00:01:30,
// 00:02:30, etc.
#define APRS_SLOT     -1     // seconds. -1 disables slotted transmissions
#define APRS_PERIOD   60    // seconds

// GPS baud rate (in bits per second). This is also the baud rate at which
// debug data will be printed out the serial port.
#define GPS_BAUDRATE  9600

// Disable GPS and just use a predefined latitude and longitude.
// Make sure to use the correct format. You may also define an altitude (in meters).
#define GPS_DISABLED
#define LATITUDE "5943.11N"
#define LONGITUDE "01008.40E"
#define ALTITUDE 200


// --------------------------------------------------------------------------
// Radio config (RadioHx1.cpp)
// --------------------------------------------------------------------------

// Need to add the constants for the radio chip. 
//
// 
#define FREQUENCY 144800000 // Frequency in Hz.

// CORRECTION constant is determined during production and not changed. 
#define CORRECTION  350

#define DEVIATION 80


// --------------------------------------------------------------------------
// Sensors config (sensors.cpp)
// --------------------------------------------------------------------------

#define INTERNAL_LM60_DISABLED
//#define EXTERNAL_LM60_DISABLED //Unncomment if a external LM60 is mounted

// Units for temperature sensors (Added by: Kyle Crockett)
// 1 = Celsius, 2 = Kelvin, 3 = Fahrenheit
#define TEMP_UNIT 1

// Calibration value in the units selected. Use integer only.
#define CALIBRATION_VAL 0

// Resistors divider for the voltage meter (ohms)
#define VMETER_R1       10000
#define VMETER_R2       57800



// --------------------------------------------------------------------------
// Debug
// --------------------------------------------------------------------------

// Debug info includes printouts from different modules to aid in testing and
// debugging.
//
// 1. To properly receive debug information, only connect the Arduino RX pin
//    to the GPS TX pin, and leave the Arduino TX pin disconnected.
//
// 2. On the serial monitor, set the baudrate to GPS_BAUDRATE (above),
//    usually 9600.
//
// 3. When flashing the firmware, disconnect the GPS from the RX pin or you
//    will get errors.

//#define DEBUG_GPS    // GPS sentence dump and checksum validation
// #define DEBUG_AX25   // AX.25 frame dump
// #define DEBUG_MODEM  // Modem ISR overrun and profiling
// #define DEBUG_RESET  // AVR reset
// #define DEBUG_SENS   // Sensors

#endif

