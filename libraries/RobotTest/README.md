## Robot Test Library V1.0.0 for stm32 Arduino core

**Written by:** _Frederic Pillon_

### Requirement
* [Arduino_Core_STM32](https://github.com/stm32duino/Arduino_Core_STM32) version > 2.3.0

### What is the Robot Test library.

The RobotTest library provides an interface to

### How to use it
The RobotTest is a built-in library included with the STM32 core package. To add its functionality to your sketch
you will need to reference the library header file. It is done by adding: `#include <RobotTest.h>`

```Arduino
#include <RobotTest.h>

void setup() {
    ...
}

void loop() {
    ...your code here...
}

```

### Library functions

#### Preinstantiate Object

A default instance is available: `RTE`

```Arduino
RTestClass RTE = RTestClass();
```

#### Predefined values

 * Default timeout in milliseconds: `RTE_DEFAULT_TIMEOUT`
 * Maximal timeout in microseconds: `RTE_DEFAULT_RETRY`

#### `void begin(uint32_t timeout, uint32_t window = IWDG_TIMEOUT_MAX)`

The `begin()` function would initialize the IWDG hardware block.

The `timeout` parameter is in microseconds and set the timer reset timeout.
When the timer reaches zero the hardware block would generate a reset signal
for the CPU.

When specifying timeout value plan to refresh the timer at least twice
as often. The `reload()` operation is not expensive.

The downside of selecting a very large timeout value is that your system
may be left in a "stuck" state for too long, before the reset is
generated.

Valid timeout values depends of the LSI clock. Typically, it is 32kH value are between
125µs and 32,768ms (~32.8 seconds). The precision depends of the timeout values:

 | timeout value range | timeout value precision |
 | ------------------- |:-----------------------:|
 | 125µs - 512ms       | 125µs
 | 513ms - 1024ms      | 250µs
 | 1025ms - 2048ms     | 500µs
 | 2049ms - 4096ms     | 1ms
 | 4097ms - 8192ms     | 2ms
 | 8193ms - 16384ms    | 4ms
 | 16385ms - 32768ms   | 8ms

The optional `window` parameter is in microseconds and must be less than `timeout`.
If the window option is enabled, the counter must be refreshed inside the window;
otherwise, a system reset is generated.

**Note:**
Window feature is not available for all STM32 series.

Calling the `begin()` method with value outside of the valid range
would return without initializing the watchdog timer.

**WARNING:**
*Once started the IWDG timer can not be stopped. If you are
planning to debug the live system, the watchdog timer may cause the
system to be reset while you are stopped in the debugger. Also consider
the iwatchdog timer implications if you are designing a system which puts
the CPU in sleep mode.*

#### `void reload()`

The `reload()` method reloads the counter value.

Once you have initialized the IWDG you **HAVE** to call `reload()`
periodically to prevent the CPU being reset.

#### `void set(uint32_t timeout, uint32_t window = IWDG_TIMEOUT_MAX)`

The `set()` method allows to set the timeout and window values.

The `timeout` and optional `window` parameters are the same than `begin()` method.

#### `void get(uint32_t* timeout, uint32_t* window = NULL)`

The `get()` method allows to get the current timeout and window values
currently set.

The `timeout` and optional `window` pointers to get values are in microseconds.

#### `bool isEnabled()`

The `isEnabled()` method returns status of the IWDG block. If enabled or not.

#### `bool isReset(bool clear)`

The `isReset()` method checks if the system has resumed from IWDG reset.

The optional `clear` parameter allow to clear IWDG reset flag if true. Default: false.

#### `void clearReset()`

The `clearReset()` method clears IWDG reset flag.
