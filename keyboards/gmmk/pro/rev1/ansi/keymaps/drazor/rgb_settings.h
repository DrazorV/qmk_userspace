#ifndef RGB_SETTINGS_H
#define RGB_SETTINGS_H

#include "quantum.h"
#include <stdint.h>

// Structure for Hue Data
typedef struct {
    uint8_t caps_lock_hue; // Hue for Caps Lock
    uint8_t layer1_hue;    // Hue for Layer 1
    uint8_t layer2_hue;    // Hue for Layer 2
} hue_data_t;

// Global Variable
extern hue_data_t hues;

// EEPROM Operations
void save_hues_to_eeprom(void);
void load_hues_from_eeprom(void);

// VIA Command Handling
void via_custom_value_command_kb(uint8_t *data, uint8_t length);
void hue_config_set_value(uint8_t *data);
void hue_config_get_value(uint8_t *data);
void hue_config_save(void);

#endif // RGB_SETTINGS_H
