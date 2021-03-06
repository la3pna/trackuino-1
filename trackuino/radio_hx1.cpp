#include <si5351.h>

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

#include "config.h"
#include "pin.h"
#include "radio_hx1.h"
#include "gps.h"
#include <Arduino.h>

#include "si5351.h"
#include "Wire.h"

Si5351 si5351;

void RadioHx1::setup()
{
  // Configure pins
  pinMode(PTT_PIN, OUTPUT);
  pin_write(PTT_PIN, LOW);
  pinMode(AUDIO_PIN, OUTPUT);

  pinMode(SW_PIN,OUTPUT);
  pin_write(SW_PIN,LOW);

}

void RadioHx1::ptt_on()
{
  setup();
  pin_write(PTT_PIN, HIGH);

  static bool nogps;
  #ifdef GPS_DISABLED
  nogps = true;
  #else
   nogps = false;
  #endif
  
  if(gps_valid || nogps){
  pin_write(SW_PIN,HIGH);
  }


#ifdef DEBUG_RADIO
    // Show modem ISR stats from the previous transmission
    Serial.println();
    Serial.println(gps_valid);
    Serial.println();
#endif
  
  delay(25); 
   
   si5351.init(SI5351_CRYSTAL_LOAD_0PF, 0, CORRECTION);
  unsigned long long freq = FREQUENCY *100ULL;
  si5351.set_vcxo(freq*6, DEVIATION);

  // Set CLK0 to be locked to VCXO
  si5351.set_ms_source(SI5351_CLK0, SI5351_PLLB);

  // Tune to 146 MHz center frequency
  si5351.set_freq_manual(freq, freq*6, SI5351_CLK0);
  si5351.drive_strength(SI5351_CLK0, SI5351_DRIVE_6MA);
 // si5351.output_enable(SI5351_CLK0, 0);
 si5351.output_enable(SI5351_CLK0, 1);
  delay(25);
}

void RadioHx1::ptt_off()
{

  pin_write(PTT_PIN, LOW);
  si5351.output_enable(SI5351_CLK0, 0);
  delay(25);
  pin_write(SW_PIN,LOW);
  delay(125);
}


