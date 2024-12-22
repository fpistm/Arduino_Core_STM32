/*
  Copyright (c) 2011 Arduino.  All right reserved.

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

#ifndef _WIRING_CONSTANTS_
#define _WIRING_CONSTANTS_

// #include <stdbool.h>
// #include <stdint.h>

// #ifdef __cplusplus
//   #include <algorithm>
//   using std::min;
//   using std::max;
// #else // C
//   #include <stdlib.h>
//   #ifndef abs
//     #define abs(x) ((x)>0?(x):-(x))
//   #endif // abs

//   #ifndef min
//     #define min(a,b) ((a)<(b)?(a):(b))
//   #endif // min

//   #ifndef max
//     #define max(a,b) ((a)>(b)?(a):(b))
//   #endif // max

// #endif // __cplusplus

#define interrupts() __enable_irq()
#define noInterrupts() __disable_irq()

//macro added for compatibility
#ifndef _BV
  #define _BV(bit) (1 << (bit))
#endif
#ifndef cbi
  #define cbi(reg, bitmask) *reg &= ~bitmask
#endif
#ifndef sbi
  #define sbi(reg, bitmask) *reg |= bitmask
#endif

#endif /* _WIRING_CONSTANTS_ */
