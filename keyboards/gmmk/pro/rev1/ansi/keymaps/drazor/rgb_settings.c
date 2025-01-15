#include "rgb_settings.h"
#include "eeprom.h"
#include "rgb_matrix.h"
#include "raw_hid.h"

hue_data_t hues = {128, 128, 128}; // Default values

// EEPROM Operations
void save_hues_to_eeprom(void) {
    uint32_t packed_hues = *((uint32_t*)&hues); // Pack struct into 32-bit value
    eeconfig_update_user(packed_hues);         // Save to EEPROM
}

void load_hues_from_eeprom(void) {
    uint32_t packed_hues = eeconfig_read_user(); // Read 32-bit value from EEPROM
    if (packed_hues != 0xFFFFFFFF) {             // Check for uninitialized data
        *((uint32_t*)&hues) = packed_hues;       // Unpack struct
    } else {
        hues.caps_lock_hue = 85; // Default values
        hues.layer1_hue = 85;
        hues.layer2_hue = 85;
        save_hues_to_eeprom(); // Save defaults
    }
    xprintf("Loaded Hues - CapsLock: %u, Layer1: %u, Layer2: %u\n",hues.caps_lock_hue, hues.layer1_hue, hues.layer2_hue);
}

enum via_hue_value {
    id_capslock_hue = 1,
    id_layer1_hue   = 2,
    id_layer2_hue   = 3,
};

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if ( *channel_id == id_custom_channel ) {
        switch (*command_id) {
            case id_custom_set_value:
            {
                hue_config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value:
            {
                hue_config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save:
            {
                hue_config_save();
                break;
            }
            default:
            {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    *command_id = id_unhandled;
}


// VIA Command Handling
void  hue_config_set_value(uint8_t *data) {

    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_capslock_hue:
        {
            hues.caps_lock_hue = *value_data;
            break;
        }
        case id_layer1_hue:
        {
            hues.layer1_hue = *value_data;
            break;
        }
        case id_layer2_hue:
        {
            hues.layer2_hue = *value_data;
            break;
        }
    }
}

void  hue_config_get_value(uint8_t *data) {

    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch ( *value_id ) {
        case id_capslock_hue:
        {
            *value_data = hues.caps_lock_hue;
            break;
        }
        case id_layer1_hue:
        {
            *value_data = hues.layer1_hue;
            break;
        }
        case id_layer2_hue:
        {
            *value_data = hues.layer2_hue;
            break;
        }
    }
}

void hue_config_save(void) {
    save_hues_to_eeprom();
}

// User EEPROM Initialization
void keyboard_post_init_user(void) {
    load_hues_from_eeprom(); // Load hues from EEPROM
}
