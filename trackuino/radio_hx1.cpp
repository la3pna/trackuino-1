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
#include <Arduino.h>
Si5351 si5351;
#include "Wire.h"


void RadioHx1::setup()
{
  // Configure pins
  pinMode(PTT_PIN, OUTPUT);
  pin_write(PTT_PIN, LOW);
  pinMode(AUDIO_PIN, OUTPUT);
    si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
unsigned long long freq = 14482500000ULL;
  // Set VCXO osc to 876 MHz (146 MHz x 6), 40 ppm pull
  si5351.set_vcxo(freq*6, 40);

  // Set CLK0 to be locked to VCXO
  si5351.set_ms_source(SI5351_CLK0, SI5351_PLLB);

  // Tune to 146 MHz center frequency
  si5351.set_freq_manual(freq, freq*6, SI5351_CLK0);
 si5351.output_enable(SI5351_CLK0, 0);
  delay(25);

}

void RadioHx1::ptt_on()
{
  pin_write(PTT_PIN, HIGH);
  si5351.output_enable(SI5351_CLK0, 1);

  delay(25);   // The HX1 takes 5 ms from PTT to full RF, give it 25
}

void RadioHx1::ptt_off()
{
  pin_write(PTT_PIN, LOW);
  delay(25);
}
