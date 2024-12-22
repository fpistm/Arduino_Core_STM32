/*
  Copyright (c) 2011 Arduino.  All right reserved.
  Copyright (c) 2013 by Paul Stoffregen <paul@pjrc.com> (delayMicroseconds)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _WIRING_TIME_H_
#define _WIRING_TIME_H_

#include "clock.h"
#include "dwt.h"
#include <sys/time.h> // for struct timeval

#ifdef __cplusplus
extern "C" {
#endif
/**
 * \brief Returns the number of milliseconds since the Arduino board began running the current program.
 *
 * This number will overflow (go back to zero), after approximately 50 days.
 *
 * \return Number of milliseconds since the program started (uint32_t)
 */
extern uint32_t millis(void) ;

/**
 * \brief Returns the number of microseconds since the Arduino board began running the current program.
 *
 * This number will overflow (go back to zero), after approximately 70 minutes. On 16 MHz Arduino boards
 * (e.g. Duemilanove and Nano), this function has a resolution of four microseconds (i.e. the value returned is
 * always a multiple of four). On 8 MHz Arduino boards (e.g. the LilyPad), this function has a resolution
 * of eight microseconds.
 *
 * \note There are 1,000 microseconds in a millisecond and 1,000,000 microseconds in a second.
 */
extern uint32_t micros(void) ;

/**
 * \brief Pauses the program for the amount of time (in milliseconds) specified as parameter.
 * (There are 1000 milliseconds in a second.)
 *
 * \param ms the number of milliseconds to pause (uint32_t)
 */
extern void delay(uint32_t ms) ;

/**
 * \brief gives the number of seconds and microseconds since the Epoch
 *
 *        based on millisecond since last power on.
 *
 * \note  The function is declared as weak  to be overwritten  in case of other
 *        implementations in user file (using RTC values for example).
 *
 * \param tv argument is a struct timeval
 * \param tz argument is a struct timezone (unused)
 *
 * \return 0
 */
int __attribute__((weak)) _gettimeofday(struct timeval *tv, void *tz)
{
  (void)tz;
  tv->tv_sec = getCurrentMillis() / 1000;
  tv->tv_usec = getCurrentMicros() - (tv->tv_sec * 1000000);  // get remaining microseconds
  return 0;
}

#ifdef __cplusplus
}
#endif

#endif /* _WIRING_TIME_H_ */
