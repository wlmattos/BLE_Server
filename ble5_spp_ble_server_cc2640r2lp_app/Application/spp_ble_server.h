/******************************************************************************

 @file  spp_ble_server.h

 @brief This file contains the Serial Port Profile sample application
        definitions and prototypes.

 Group: CMCU, SCS
 Target Device: CC2640R2

 ******************************************************************************

 Copyright (c) 2013-2017, Texas Instruments Incorporated
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 *  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

 *  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 *  Neither the name of Texas Instruments Incorporated nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef SPP_BLE_SERVER_H
#define SPP_BLE_SERVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */
#include <string.h>

/*********************************************************************
*  EXTERNAL VARIABLES
*/

/*********************************************************************
 * CONSTANTS
 */
// External Events for RTOS application
#define SBP_UART_DATA_EVT                     0x0010
#define SBP_UART_ERROR_EVT                    0x0020

//LED parameters
#define Board_LED_TOGGLE                      3
#define BLINK_DURATION                        500 // Milliseconds

 /* Delay */
#define delay_ms(i) ( CPUdelay(12000*(i)) )

//! @name LTC1867 Single-Ended Channel Addresses, COM=GND
//! @{
// Single-Ended Channel Address When CH7/COM Pin Is used As CH7
#define LTC1867_CH0             0x80
#define LTC1867_CH1             0xC0
#define LTC1867_CH2             0x90
#define LTC1867_CH3             0xD0
#define LTC1867_CH4             0xA0
#define LTC1867_CH5             0xE0
#define LTC1867_CH6             0xB0
#define LTC1867_CH7             0xF0
//!@}

//! @name LTC1867 Sleep / Unipolar/Bipolar config bits
//! @{
// Sleep Mode Command
#define LTC1867_SLEEP_MODE      0x02
#define LTC1867_EXIT_SLEEP_MODE 0x00
#define LTC1867_UNIPOLAR_MODE   0x04  // Bitwise OR with channel commands for unipolar mode
#define LTC1867_BIPOLAR_MODE    0x00
//!@}




/*********************************************************************
 * MACROS
 */
#define DEBUG_SIMPLE

#if !defined(DEBUG_SIMPLE)
#  define Display_print0(handle, line, col, fmt) DEBUG(fmt); \
    DEBUG_NEWLINE()
#  define Display_print1(handle, line, col, fmt, a0) DEBUG((uint8 *)fmt); \
    DEBUG((uint8_t*)convInt32ToText((int32)a0)); DEBUG_NEWLINE()
#else
#  define Display_print0(handle, line, col, fmt)

#  define Display_print1(handle, line, col, fmt, a0)

#endif
/*********************************************************************
 * FUNCTIONS
 */

/*
 * Task creation function for the Simple BLE Peripheral.
 */
extern void SPPBLEServer_createTask(void);

extern void SPPBLEServer_toggleLed(uint8_t led, uint8_t state);
extern char* convInt32ToText(int32 value);

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* SPP_BLE_SERVER_H */
