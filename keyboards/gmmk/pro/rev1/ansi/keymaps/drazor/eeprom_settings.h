#ifndef EEPROM_SETTINGS_H
#define EEPROM_SETTINGS_H

#include "quantum.h"

// Define the User Config Union
typedef union {
    uint8_t raw[EECONFIG_USER_DATA_SIZE];
    struct {
        hsv_t caps_lock_hs; // Hue & Saturation for Caps Lock
        hsv_t layer1_hs;    // Hue & Saturation for Layer 1
        hsv_t layer2_hs;    // Hue & Saturation for Layer 2
        uint8_t caps_lock_br;
        uint8_t layer1_br;
        uint8_t layer2_br;
        bool caps_lock_ind;
        bool layer1_ind;
        bool layer2_ind;
        bool reactive_overlay; // Toggle for the reactive overlay effect
    } __attribute__((packed)); // Ensure no padding
} user_config_t;

extern user_config_t user_config;


// Global Variable
extern user_config_t user_config;

// VIA Command Handling
void via_custom_value_command_kb(uint8_t *data, uint8_t length);
void user_config_set_value(uint8_t *data);
void user_config_get_value(uint8_t *data);

#endif // EEPROM_SETTINGS_H
