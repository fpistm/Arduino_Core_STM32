/**
  ******************************************************************************
  * @file    cdc_queue.c
  * @author  makarenya
  * @version V1.0.0
  * @date    23-December-2018
  * @brief   Provides methods to manipulate with CDC cyclic buffers
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

#ifdef USBCON
#ifdef USBD_USE_CDC

#include "cdc_queue.h"

/* Private Variables */
/* Transmit/Received Data over USB are stored in those buffer */
CDC_TransmitQueue_TypeDef TxQueue;
CDC_ReceiveQueue_TypeDef RxQueue;

// Initialize read and write position of queue
void CDC_TransmitQueue_Init(void)
{
  TxQueue.read = 0;
  TxQueue.write = 0;
}

// Determine size, available for write in queue
int CDC_TransmitQueue_WriteSize(void)
{
  return (TxQueue.read + CDC_TRANSMIT_QUEUE_BUFFER_SIZE - TxQueue.write - 1)
         % CDC_TRANSMIT_QUEUE_BUFFER_SIZE;
}

// Determine size of data, stored in queue
int CDC_TransmitQueue_ReadSize(void)
{
  return (TxQueue.write + CDC_TRANSMIT_QUEUE_BUFFER_SIZE - TxQueue.read)
         % CDC_TRANSMIT_QUEUE_BUFFER_SIZE;
}

// Write provided data into queue.
void CDC_TransmitQueue_Enqueue(const uint8_t *buffer, uint32_t size)
{
  uint32_t sizeToEnd = CDC_TRANSMIT_QUEUE_BUFFER_SIZE - TxQueue.write;
  if (sizeToEnd > size) {
    memcpy(&TxQueue.buffer[TxQueue.write], &buffer[0], size);
  } else {
    memcpy(&TxQueue.buffer[TxQueue.write], &buffer[0], sizeToEnd);
    memcpy(&TxQueue.buffer[0], &buffer[sizeToEnd], size - sizeToEnd);
  }
  TxQueue.write = (uint16_t)((TxQueue.write + size) %
                             CDC_TRANSMIT_QUEUE_BUFFER_SIZE);
}

// Read flat block from queue biggest as possible, but max QUEUE_MAX_PACKET_SIZE
uint8_t *CDC_TransmitQueue_ReadBlock(uint16_t *size)
{
  if (TxQueue.write >= TxQueue.read) {
    *size = TxQueue.write - TxQueue.read;
  } else {
    *size = CDC_TRANSMIT_QUEUE_BUFFER_SIZE - TxQueue.read;
  }
  TxQueue.reserved = *size;
  return &TxQueue.buffer[TxQueue.read];
}

void CDC_TransmitQueue_CommitRead(void)
{
  TxQueue.read = (TxQueue.read + TxQueue.reserved) %
                 CDC_TRANSMIT_QUEUE_BUFFER_SIZE;
}

// Initialize read and write position of queue.
void CDC_ReceiveQueue_Init(void)
{
  RxQueue.read = 0;
  RxQueue.write = 0;
  RxQueue.length = CDC_RECEIVE_QUEUE_BUFFER_SIZE;
}

// Reserve block in queue and return pointer to it.
uint8_t *CDC_ReceiveQueue_ReserveBlock(void)
{
  const uint16_t limit =
    CDC_RECEIVE_QUEUE_BUFFER_SIZE - CDC_QUEUE_MAX_PACKET_SIZE;
  volatile uint16_t read = RxQueue.read;

  if (read <= RxQueue.write) {
    // if write is limited only by buffer size.
    if (RxQueue.write < limit || (RxQueue.write == limit && read > 0)) {
      // if size in the rest of buffer is enough for full packet plus 1 byte
      // or if it tight enough and write position can be set to 0
      return RxQueue.buffer + RxQueue.write;
    } else if (read > CDC_QUEUE_MAX_PACKET_SIZE) {
      // if size in the rest is not enough, but enough size in head
      RxQueue.length = RxQueue.write;
      RxQueue.write = 0;
      return RxQueue.buffer + RxQueue.write;
    }
  } else if (RxQueue.write + CDC_QUEUE_MAX_PACKET_SIZE < read) {
    // write position must be less than read position
    // after reading largest possible packet
    return RxQueue.buffer + RxQueue.write;
  }
  return 0;
}

// Commits block in queue and make it available for reading
void CDC_ReceiveQueue_CommitBlock(uint16_t size)
{
  RxQueue.write += size;
  if (RxQueue.write >= RxQueue.length) {
    RxQueue.length = CDC_RECEIVE_QUEUE_BUFFER_SIZE;
  }
  if (RxQueue.write >= CDC_RECEIVE_QUEUE_BUFFER_SIZE) {
    RxQueue.write = 0;
  }
}

// Determine size, available for read
int CDC_ReceiveQueue_ReadSize(void)
{
  // reading length after write make guarantee, that length >= write
  // and determined reading size will be smaller or equal than real one.
  volatile uint16_t write = RxQueue.write;
  volatile uint16_t length = RxQueue.length;
  if (write >= RxQueue.read) {
    return write - RxQueue.read;
  }
  return length + write - RxQueue.read;
}

// Read one byte from queue.
int CDC_ReceiveQueue_Dequeue(void)
{
  volatile uint16_t write = RxQueue.write;
  volatile uint16_t length = RxQueue.length;
  if (RxQueue.read == length) {
    RxQueue.read = 0;
  }
  if (write == RxQueue.read) {
    return -1;
  }
  uint8_t ch = RxQueue.buffer[RxQueue.read++];
  if (RxQueue.read >= length) {
    RxQueue.read = 0;
  }
  return ch;
}

// Peek byte from queue.
int CDC_ReceiveQueue_Peek(void)
{
  volatile uint16_t write = RxQueue.write;
  volatile uint16_t length = RxQueue.length;
  if (RxQueue.read >= length) {
    RxQueue.read = 0;
  }
  if (write == RxQueue.read) {
    return -1;
  }
  return RxQueue.buffer[RxQueue.read];
}

uint16_t CDC_ReceiveQueue_Read(uint8_t *buffer, uint16_t size)
{
  volatile uint16_t write = RxQueue.write;
  volatile uint16_t length = RxQueue.length;
  uint16_t available;

  if (RxQueue.read >= length) {
    RxQueue.read = 0;
  }
  if (write >= RxQueue.read) {
    available = write - RxQueue.read;
  } else {
    available = length - RxQueue.read;
  }
  if (available < size) {
    size = available;
  }

  memcpy(buffer, &RxQueue.buffer[RxQueue.read], size);
  RxQueue.read = RxQueue.read + size;
  if (RxQueue.read >= length) {
    RxQueue.read = 0;
  }
  return size;
}

bool CDC_ReceiveQueue_ReadUntil(uint8_t terminator, uint8_t *buffer, uint16_t size, uint16_t *fetched)
{
  volatile uint16_t write = RxQueue.write;
  volatile uint16_t length = RxQueue.length;
  uint16_t available;

  if (RxQueue.read >= length) {
    RxQueue.read = 0;
  }
  if (write >= RxQueue.read) {
    available = write - RxQueue.read;
  } else {
    available = length - RxQueue.read;
  }
  if (available < size) {
    size = available;
  }

  uint8_t *start = &RxQueue.buffer[RxQueue.read];
  for (uint16_t i = 0; i < size; i++) {
    uint8_t ch = start[i];
    if (ch == terminator) {
      RxQueue.read += (uint16_t)(i + 1);
      if (RxQueue.read >= length) {
        RxQueue.read = 0;
      }
      *fetched = i;
      return true;
    } else {
      buffer[i] = ch;
    }
  }

  *fetched = size;
  RxQueue.read += size;
  if (RxQueue.read >= length) {
    RxQueue.read = 0;
  }
  return false;
}
#endif /* USBD_USE_CDC */
#endif /* USBCON */
