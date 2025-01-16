#include "eeprom_settings.h"
#include "eeprom.h"
#include "rgb_matrix.h"
#include "raw_hid.h"
#include "print.h"

user_config_t user_config; // Global configuration struct

enum via_value {
    id_capslock     = 1,
    id_layer1       = 2,
    id_layer2       = 3,
    id_reactive     = 4,
    id_autocorrect  = 5
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
                user_config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value:
            {
                user_config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save:
            {
                eeconfig_update_user_datablock(&user_config); // Save to EEPROM
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
void  user_config_set_value(uint8_t *data) {

    uint8_t *value_id = &(data[0]);  // Get the value ID
    hsv_t *hsv_data   = (hsv_t *)&(data[1]);  // Point to HSV structure

    switch (*value_id) {
        case id_capslock:
            user_config.caps_lock_hs = *hsv_data;
            break;
        case id_layer1:
            user_config.layer1_hs = *hsv_data;
            break;
        case id_layer2:
            user_config.layer2_hs = *hsv_data;
            break;
        case id_reactive:
            user_config.reactive_overlay = data[1];
        case id_autocorrect:
            user_config.ac_togg = data[1];
        default:
            return; // Unknown value ID, do nothing
    }
}

void user_config_get_value(uint8_t *data) {
    // data = [ value_id, R, G, B ]
    uint8_t *value_id = &(data[0]);
    hsv_t *hsv_data   = (hsv_t *)&(data[1]);

    switch (*value_id) {
        case id_capslock:
            *hsv_data = user_config.caps_lock_hs;
            break;
        case id_layer1:
            *hsv_data = user_config.layer1_hs;
            break;
        case id_layer2:
            *hsv_data = user_config.layer2_hs;
            break;
        case id_reactive: // Handle overlay toggle as boolean
            data[1] = user_config.reactive_overlay;
            break;
        case id_autocorrect: // Handle AC toggle as boolean
            data[1] = user_config.ac_togg;
            break;

    }
}

