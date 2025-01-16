#ifndef RGB_SETTINGS_H
#define RGB_SETTINGS_H

#include "quantum.h"

// Define the User Config Union
typedef union {
    uint8_t raw[EECONFIG_USER_DATA_SIZE];
    struct {
        hsv_t caps_lock_hs; // Hue & Saturation for Caps Lock
        hsv_t layer1_hs;    // Hue & Saturation for Layer 1
        hsv_t layer2_hs;    // Hue & Saturation for Layer 2
    } __attribute__((packed)); // Ensure no padding
} user_config_t;

// Global Variable
extern user_config_t user_config;

// VIA Command Handling
void via_custom_value_command_kb(uint8_t *data, uint8_t length);
void user_config_set_rgb(uint8_t *data);
void user_config_get_rgb(uint8_t *data);

#endif // RGB_SETTINGS_H
