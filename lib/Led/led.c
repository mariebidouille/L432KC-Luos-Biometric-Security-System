/******************************************************************************
 * @file led
 * @brief driver example a simple Led
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#include "led.h"
#include "ll_led.h"

#include "profile_state.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
profile_state_t led_green;
profile_state_t led_red;

/*******************************************************************************
 * Functions
 ******************************************************************************/

/******************************************************************************
 * @brief init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void Led_Init(void)
{
    ll_led_init();

    led_green.access = WRITE_ONLY_ACCESS;
    led_red.access = WRITE_ONLY_ACCESS;

    revision_t revision = {.major = 1, .minor = 0, .build = 0};

    ProfileState_CreateService(&led_green, 0, "led_green", revision);
    ProfileState_CreateService(&led_red, 0, "led_red", revision);
}

/******************************************************************************
 * @brief loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void Led_Loop(void)
{
    ll_led_write(&led_green.state, &led_red.state);
}