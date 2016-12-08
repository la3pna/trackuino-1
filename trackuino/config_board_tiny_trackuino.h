/* trackuino copyright (C) 2010  EA5HAV Javi
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __CONFIG_BOARD__
#define __CONFIG_BOARD__


// --------------------------------------------------------------------------
// THIS IS THE TINY TRACKUINO BOARD-SPECIFIC CONFIGURATION FILE
// (http://www.github.com/johnboiles/tinytrackuino)
//
// NOTE: all pins are Arduino based, not the Atmega chip. Mapping:
// http://www.arduino.cc/en/Hacking/PinMapping
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Modem config (afsk.cpp)
// --------------------------------------------------------------------------

// AUDIO_PIN is the audio-out pin. On the Atmega32u4 the audio is generated
// by either timer 1 or timer 4 using PWM.
#define AUDIO_PIN       10

// --------------------------------------------------------------------------
// Radio config (radio_hx1.cpp)
// --------------------------------------------------------------------------

// This is the PTT pin
#define PTT_PIN           4

// --------------------------------------------------------------------------
// Sensors config (sensors.cpp)
// --------------------------------------------------------------------------

// Most of the sensors.cpp functions use internal reference voltages (either
// AVCC or 1.1V). If you want to use an external reference, you should
// uncomment the following line:
//
// #define USE_AREF
//
// BEWARE! If you hook up an external voltage to the AREF pin and 
// accidentally set the ADC to any of the internal references, YOU WILL
// FRY YOUR AVR.
//
// It is always advised to connect the AREF pin through a pull-up resistor,
// whose value is defined here in ohms (set to 0 if no pull-up):
//
// #define AREF_PULLUP           4700
//
// Since there is already a 32K resistor at the ADC pin, the actual
// voltage read will be VREF * 32 / (32 + AREF_PULLUP)
//
// Read more in the Arduino reference docs:
// http://arduino.cc/en/Reference/AnalogReference?from=Reference.AREF

// Pin mappings for the internal / external temperature sensors. VS refers
// to (arduino) digital pins, whereas VOUT refers to (arduino) analog pins.
#define INTERNAL_LM60_VS_PIN     6
#define INTERNAL_LM60_VOUT_PIN   0
#define EXTERNAL_LM60_VS_PIN     7
#define EXTERNAL_LM60_VOUT_PIN   1

// Voltage meter analog pin
#define VMETER_PIN      2

// --------------------------------------------------------------------------
// Buzzer config (buzzer.cpp)
// --------------------------------------------------------------------------

#define BUZZER_PIN              9

// --------------------------------------------------------------------------
// Debug
// --------------------------------------------------------------------------

// This is the LED pin (13 on most Arduinos, 17 on Atmega32u4). The LED will be on while the AVR is
// running and off while it's sleeping, so its brightness gives an indication
// of the CPU activity.
#define LED_PIN                 13

// --------------------------------------------------------------------------
// LCD
// --------------------------------------------------------------------------

//#define LCD_ENABLED
//#define LCD_PINS 12, 11, 5, 8, 9, 10

#endif
