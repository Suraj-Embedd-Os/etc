/**
 * \file
 *
 * \brief USART basic driver.
 *
 (c) 2020 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

#ifndef USART_BASIC_H_INCLUDED
#define USART_BASIC_H_INCLUDED

#include <atmel_start.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Normal Mode, Baud register value */
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(3333333 * 64 / (16 * (float)BAUD_RATE)) + 0.5)

int8_t USART_SCRN_init();

void USART_SCRN_enable();

void USART_SCRN_enable_rx();

void USART_SCRN_enable_tx();

void USART_SCRN_disable();

uint8_t USART_SCRN_get_data();

bool USART_SCRN_is_tx_ready();

bool USART_SCRN_is_rx_ready();

bool USART_SCRN_is_tx_busy();

uint8_t USART_SCRN_read(void);

void USART_SCRN_write(const uint8_t data);

/* Normal Mode, Baud register value */
#define USART1_BAUD_RATE(BAUD_RATE) ((float)(3333333 * 64 / (16 * (float)BAUD_RATE)) + 0.5)

int8_t USART_WIFI_init();

void USART_WIFI_enable();

void USART_WIFI_enable_rx();

void USART_WIFI_enable_tx();

void USART_WIFI_disable();

uint8_t USART_WIFI_get_data();

bool USART_WIFI_is_tx_ready();

bool USART_WIFI_is_rx_ready();

bool USART_WIFI_is_tx_busy();

uint8_t USART_WIFI_read(void);

void USART_WIFI_write(const uint8_t data);

/* Normal Mode, Baud register value */
#define USART2_BAUD_RATE(BAUD_RATE) ((float)(3333333 * 64 / (16 * (float)BAUD_RATE)) + 0.5)

int8_t USART_TEMP_init();

void USART_TEMP_enable();

void USART_TEMP_enable_rx();

void USART_TEMP_enable_tx();

void USART_TEMP_disable();

uint8_t USART_TEMP_get_data();

bool USART_TEMP_is_tx_ready();

bool USART_TEMP_is_rx_ready();

bool USART_TEMP_is_tx_busy();

uint8_t USART_TEMP_read(void);

void USART_TEMP_write(const uint8_t data);

/* Normal Mode, Baud register value */
#define USART3_BAUD_RATE(BAUD_RATE) ((float)(3333333 * 64 / (16 * (float)BAUD_RATE)) + 0.5)

int8_t USART_3_init();

void USART_3_enable();

void USART_3_enable_rx();

void USART_3_enable_tx();

void USART_3_disable();

uint8_t USART_3_get_data();

bool USART_3_is_tx_ready();

bool USART_3_is_rx_ready();

bool USART_3_is_tx_busy();

uint8_t USART_3_read(void);

void USART_3_write(const uint8_t data);

#ifdef __cplusplus
}
#endif

#endif /* USART_BASIC_H_INCLUDED */
