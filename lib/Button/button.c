/******************************************************************************
 * @file button
 * @brief driver example a simple button
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#include "button.h"
#include "ll_button.h"
#include "profile_state.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
profile_state_t button_enroll;
profile_state_t button_delete;
profile_state_t button_up;
profile_state_t button_down;

/*******************************************************************************
 * Function
 ******************************************************************************/

/******************************************************************************
 * @brief init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void Button_Init(void)
{
    // hardware initialization
    ll_button_init();

    // service initialization
    revision_t revision = {.major = 1, .minor = 0, .build = 0};
    
    button_delete.access = READ_ONLY_ACCESS;
    button_enroll.access = READ_ONLY_ACCESS;
    button_up.access = READ_ONLY_ACCESS;
    button_down.access = READ_ONLY_ACCESS;

    // Service creation following state profile
    ProfileState_CreateService(&button_enroll, 0, "btn_enroll", revision);
    ProfileState_CreateService(&button_delete, 0, "btn_delete", revision);
    ProfileState_CreateService(&button_up, 0, "btn_up", revision);
    ProfileState_CreateService(&button_down, 0, "btn_down", revision);
}

/******************************************************************************
 * @brief loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void Button_Loop(void)
{
    ll_button_read(&button_enroll.state, &button_delete.state, &button_up.state, &button_down.state);
}

