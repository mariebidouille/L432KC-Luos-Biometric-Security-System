/******************************************************************************
 * @file low-level button
 * @brief driver example 4 buttons
 * @author MarieBidouille
 * @version 0.0.0
 ******************************************************************************/
#include "ll_button.h"
#include "stm32l4xx_hal.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/

/******************************************************************************
 * @brief initialize button hardware
 * @param None
 * @return None
 ******************************************************************************/
void ll_button_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // configure gpio clock
    BTN_CLOCK_ENABLE();

    /*Configure GPIO pin : button pin */
    GPIO_InitStruct.Pin  = BTN_ENROLL_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(BTN_ENROLL_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin  = BTN_DELETE_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(BTN_DELETE_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin  = BTN_UP_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(BTN_UP_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin  = BTN_DOWN_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(BTN_DOWN_GPIO_Port, &GPIO_InitStruct); 
}

/******************************************************************************
 * @brief read the button state
 * @param None
 * @return button state
 ******************************************************************************/
uint8_t ll_button_read(bool *enroll_state, bool *delete_state, bool *up_state, bool *down_state)
{
    *enroll_state = (bool) (HAL_GPIO_ReadPin(BTN_ENROLL_GPIO_Port, BTN_ENROLL_Pin)>0);
    *delete_state =(bool) (HAL_GPIO_ReadPin(BTN_DELETE_GPIO_Port, BTN_DELETE_Pin)>0);
    *up_state = (bool) (HAL_GPIO_ReadPin(BTN_UP_GPIO_Port, BTN_UP_Pin)>0);
    *down_state = (bool) (HAL_GPIO_ReadPin(BTN_DOWN_GPIO_Port, BTN_DOWN_Pin)>0);
    return true;
}
