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

#if defined(__AVR_ATmega32U4__)

#ifndef __AFSK_AVR32U4_H__
#define __AFSK_AVR32U4_H__

#include <stdint.h>
#include <avr/pgmspace.h>
#include "config.h"

// Exported consts
extern const uint32_t MODEM_CLOCK_RATE;
extern const uint8_t REST_DUTY;
extern const uint16_t TABLE_SIZE;
extern const uint32_t PLAYBACK_RATE;

// Exported vars
extern const unsigned char afsk_sine_table[];

//#define AFSK_USE_TIMER1 1
#define AFSK_USE_TIMER4 1

#if AFSK_USE_TIMER1
#if AUDIO_PIN == 9
#  define AFSK_OCR OCR1A
#elif AUDIO_PIN == 10
#  define AFSK_OCR OCR1B
#else
#  error "Only AUDIO_PIN 9 and 10 are supported for 32u4 processors with timer 1."
#endif

#elif AFSK_USE_TIMER4
#if AUDIO_PIN == 6
#  define AFSK_OCR OCR4D
#elif AUDIO_PIN == 10
#  define AFSK_OCR OCR4B
#elif AUDIO_PIN == 13
#  define AFSK_OCR OCR4A
#else
#  error "Only AUDIO_PIN 9 and 10 are supported for 32u4 processors with timer 4."
#endif
#endif

// Inline functions (this saves precious cycles in the ISR)
inline uint8_t afsk_read_sample(int phase)
{
  return pgm_read_byte_near(afsk_sine_table + phase);
}

inline void afsk_output_sample(uint8_t s)
{
  AFSK_OCR = s;
}

#ifdef DEBUG_MODEM
inline uint16_t afsk_timer_counter()
{
  uint16_t t = TCNT1;
  if ((TIFR1 & _BV(TOV1)) && t < 128)
    t += 256;
  return t;
}

inline int afsk_isr_overrun()
{
  return (TIFR1 & _BV(TOV1));
}
#endif


// Exported functions
void afsk_setup();
void afsk_send(const uint8_t *buffer, int len);
void afsk_start();
int afsk_busy();
void afsk_isr();
void afsk_timer_setup();
void afsk_timer_start();
void afsk_timer_stop();

#ifdef DEBUG_MODEM
void afsk_debug();
#endif

#endif
#endif // AVR
