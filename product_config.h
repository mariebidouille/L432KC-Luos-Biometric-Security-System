/******************************************************************************
 * @file product_config
 * @brief biometric security system configuration file
 * @author MarieBidouille
 * @version 0.0.0
 ******************************************************************************/
#ifndef PRODUCT_CONFIG_H
#define PRODUCT_CONFIG_H

#include "luos.h"

typedef enum
{
    BIOMETRIC_APP = LUOS_LAST_TYPE, 
    LCD_TYPE, 
    FINGERPRINT_TYPE
} security_system_t;

typedef enum
{
    CHECK = LUOS_LAST_STD_CMD, 
    ENROLL, 
    DELETE
} security_system_cmd_t;

#endif /* PRODUCT_CONFIG_H */