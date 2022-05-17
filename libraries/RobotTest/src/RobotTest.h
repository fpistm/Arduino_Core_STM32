/*
  Copyright (c) 2022 Frederic Pillon <frederic.pillon@st.com> for
  STMicroelectronics. All right reserved.

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
#ifndef __ROBOTTEST_H__
#define __ROBOTTEST_H__

#include "Arduino.h"

// Default timeout in milliseconds
#define RTE_DEFAULT_TIMEOUT   2000
#define RTE_DEFAULT_RETRY     10
#define RTE_SYNC_KEY          "__Sync"
#define RTE_KV_SEP            ":"
#define RTE_HOOK_MSG          "STM32duino"

class RTestClass {

  public:
    bool begin(Stream &s, uint8_t retry=RTE_DEFAULT_RETRY, uint32_t timeout=RTE_DEFAULT_TIMEOUT);
    bool sync(uint8_t retry=RTE_DEFAULT_RETRY, uint32_t timeout=RTE_DEFAULT_TIMEOUT);
    void setTimeout(uint32_t msec=RTE_DEFAULT_TIMEOUT)
    {
      _timeout = msec;;
    };

  private:
    Stream * RTEStream;
    static uint32_t  _timeout;
};

extern RTestClass RTE;
#endif /* __ROBOTTEST_H__ */
