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
#include "RobotTest.h"

// Initialize static variable
uint32_t RTestClass::_timeout = RTE_DEFAULT_TIMEOUT;

/**
  * @brief  Begin start synchronisation between DUT and Host using
  *         specified Stream object (Serial, USB,...)
  * @param  s: Stream object reference to use as transport
  * @param  retry: number of retry
  * @param  timeout: optional value in milliseconds
  *         Default: RTE_DEFAULT_TIMEOUT
  * @retval bool
  */
bool RTestClass::begin(Stream &s, uint8_t retry, uint32_t timeout)
{
  RTEStream = &s;
  setTimeout(timeout);
  return sync(retry, timeout);
}

/**
  * @brief  Perform synchronisation between DUT and Host
  * @param  retry: number of retry
  * @param  timeout: value in milliseconds
  * @retval bool
  */
bool RTestClass::sync(uint8_t retry, uint32_t timeout)
{
  bool synced = false;
  String sync_key = String(RTE_SYNC_KEY);
  sync_key += RTE_KV_SEP;
  RTEStream->setTimeout(timeout);
  // First send hook message, if Host does not receive it
  // no sync will be received
  for(uint8_t i=0; (i < retry) && !synced; i++) {
    uint32_t start = millis();
    bool expired = false;
    while(!RTEStream->available() && !expired) {
      RTEStream->println(RTE_HOOK_MSG);
      expired = ((millis() - start) > timeout) ? true : 10;
      // Wait before next send
      delay(500);
    }
    if (RTEStream->available()) {
      String msg = RTEStream->readStringUntil('\n');
      int idx = msg.indexOf(sync_key);
      if (idx != -1) {
        String sync_msg = msg.substring(idx);
        if(RTEStream->println(sync_msg) == (sync_msg.length()+ strlen("\r\n"))) {
          synced= true;
        }
      }
    }
  }
  return synced;
}

// Preinstantiate Object
RTestClass RTE = RTestClass();
