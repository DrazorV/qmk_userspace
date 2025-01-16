#pragma once

// April 2023 update: QMK supports GMMK Pro by emulating EEPROM through its onboard flash and using a wear-leveling algorithm to spread out writes. Recent QMK changes require me to now explicitly specify a larger EEPROM
// size to properly fit my firmware (which requires 1195 bytes as of April 10, 2023). In the future, I may need to increase this if firmware grows further. Also, I don't currently explicitly call out EEPROM_DRIVER = wear_leveling and
// WEAR_LEVELING_DRIVER = embedded_flash in rules.mk but may need to in the future if defaults change -- QMK should eventually support writing to my MCU's actual EEPROM.
#define WEAR_LEVELING_LOGICAL_SIZE 1280             //default 1024    Number of bytes “exposed” to the rest of QMK and denotes the size of the usable EEPROM.
#define WEAR_LEVELING_BACKING_SIZE 2560             //default 2048    Number of bytes used by the wear-leveling algorithm for its underlying storage, and needs to be a multiple of the logical size.

#define DYNAMIC_KEYMAP_EEPROM_MAX_SIZE 1024
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 32 // Reserve space for custom settings
#define EECONFIG_USER_DATA_SIZE 9

// Force n-key rollover
#define FORCE_NKRO

// Set keyboard debounce time (originally 5ms, now 8ms to combat touchy switches)
#define DEBOUNCE 8

// Set TT to two taps
#define TAPPING_TOGGLE 2

#ifdef COMMAND_ENABLE
#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL) //debug commands accessed by holding down both CTRLs: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_command.md
#endif

// Caps Word configuration
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 10000      // Automatically turn off after x milliseconds of idle. 0 to never timeout.

// Handle GRAVESC combo keys
#define GRAVE_ESC_ALT_OVERRIDE
// Always send Escape if Alt is pressed
#define GRAVE_ESC_CTRL_OVERRIDE
// Always send Escape if Control is pressed


// #define TAPPING_TERM 180
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY
#define ENCODER_DIRECTION_FLIP

#ifdef RGB_MATRIX_ENABLE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_MATRIX_KEYPRESSES            // Enables REACTIVE & SPLASH modes
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS   // Enables Heatmap, Rain

    // RGB step values
    #define RGBLIGHT_HUE_STEP 32             // The number of steps to cycle through the hue by (default 10)
    #define RGBLIGHT_SAT_STEP 17             // The number of steps to increment the saturation by (default 17)
    #define RGBLIGHT_VAL_STEP 17             // The number of steps to increment the brightness by (default 17)

    // Startup values, when none have been set
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RIVERFLOW
    #define RGB_MATRIX_DEFAULT_HUE 0                          // Sets the default hue value, if none has been set
    #define RGB_MATRIX_DEFAULT_SAT 255                        // Sets the default saturation value, if none has been set
    #define RGB_MATRIX_DEFAULT_SPD 127                        // Sets the default animation speed, if none has been set


    #define ENABLE_RGB_MATRIX_STARLIGHT
    #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
    #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
    #define ENABLE_RGB_MATRIX_RIVERFLOW
#endif //RGB_MATRIX_ENABLE

/*
// Mouse Keys Accelerated Mode Definitions
#define MOUSEKEY_DELAY 3               // Delay between pressing a movement key and cursor movement (default: 10)
#define MOUSEKEY_INTERVAL 13           // Time between cursor movements in milliseconds (default: 20); Try setting to 1000/monitor refresh for smooth movement.
#define MOUSEKEY_MOVE_DELTA 8          // Step size (default: 8)
#define MOUSEKEY_MAX_SPEED 9           // Maximum cursor speed at which acceleration stops (default: 10)
#define MOUSEKEY_TIME_TO_MAX 150       // Time until maximum cursor speed is reached (default: 30)
#define MOUSEKEY_WHEEL_DELAY 0         // Delay between pressing a wheel key and wheel movement (default: 10)
#define MOUSEKEY_WHEEL_INTERVAL 80     // Time between wheel movements (default: 80)
#define MOUSEKEY_WHEEL_MAX_SPEED 8     // Maximum number of scroll steps per scroll action (default: 8)
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40  // Time until maximum scroll speed is reached (default: 40)
*/

// Mouse Keys Kinetic Mode Definitions
#define MK_KINETIC_SPEED                        // Enable Kinetic mode:  Uses a quadratic curve on cursor speed to allow precise movements at the beginning and increases speed thereafter.
#define MOUSEKEY_DELAY 3                        // Delay between pressing a movement key and cursor movement (default: 10)
#define MOUSEKEY_INTERVAL 13                    // Time between cursor movements in milliseconds (default: 20); Try setting to 1000/monitor refresh for smooth movement.
#define MOUSEKEY_MOVE_DELTA 5                   // Step size for accelerating from initial to base speed (default: 8)
#define MOUSEKEY_MOVE_MAX 50                    // use instead of BASE SPEED to limit speed in Kinetic mode
#define MOUSEKEY_INITIAL_SPEED 100              // Initial speed of the cursor in pixels per second (default: 100)
//#define MOUSEKEY_BASE_SPEED 800               // (broken in QMK 0.16.0) Maximum cursor speed at which acceleration stops (default: 1000)
#define MOUSEKEY_DECELERATED_SPEED 400          // Decelerated cursor speed (default: 400)
#define MOUSEKEY_ACCELERATED_SPEED 2000         // Accelerated cursor speed (default: 3000)
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16     // Initial number of movements of the mouse wheel (default: 16)
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32        // Maximum number of movements at which acceleration stops (default: 32)
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48 // Accelerated wheel movements (default: 48)
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8  // Decelerated wheel movements (default: 8)
