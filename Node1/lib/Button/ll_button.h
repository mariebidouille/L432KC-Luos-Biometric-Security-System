/******************************************************************************
 * @file low-level button
 * @brief driver example 4 buttons
 * @author MarieBidouille
 * @version 0.0.0
 ******************************************************************************/
#ifndef LL_BUTTON_H
#define LL_BUTTON_H

#include "stdbool.h"
#include "stdio.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BTN_CLOCK_ENABLE()           \
    do                                \
    {                                 \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
        __HAL_RCC_GPIOB_CLK_ENABLE(); \
    } while (0U)

#define BTN_ENROLL_Pin              GPIO_PIN_4
#define BTN_ENROLL_GPIO_Port        GPIOA

#define BTN_DELETE_Pin              GPIO_PIN_0
#define BTN_DELETE_GPIO_Port        GPIOB

#define BTN_UP_Pin                  GPIO_PIN_1
#define BTN_UP_GPIO_Port            GPIOB

#define BTN_DOWN_Pin                GPIO_PIN_12
#define BTN_DOWN_GPIO_Port          GPIOA
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/
void ll_button_init(void);
uint8_t ll_button_read(bool *, bool *, bool *, bool*);

#endif /* LL_BUTTON_H */
