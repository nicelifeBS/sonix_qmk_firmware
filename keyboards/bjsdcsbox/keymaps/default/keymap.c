// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_ortho_4x1(
        JS_0,   JS_1,   JS_2,   JS_3
    )
};


// Rotary Encoder Setup
#ifdef ENCODER_ENABLE
enum {
    CCW_ENCODER_0 = 4, // JS_4
    CW_ENCODER_0 = 5 // JS_5
};

uint16_t encoder_stationary_release_delay_ms = 25;
uint16_t encoder_last_update_time = 0;

// using the encoder callback as we do need more control over the encoders and when they are updated
bool encoder_update_user(uint8_t index, bool clockwise) {
  // index will go through all available encoders
  if (index == 0) {
    if (clockwise) {
      unregister_joystick_button(CW_ENCODER_0);
      register_joystick_button(CCW_ENCODER_0);
      encoder_last_update_time = timer_read(); /* Update the last time that the encoder was detected as rotated */
    } else {
      unregister_joystick_button(CCW_ENCODER_0);
      register_joystick_button(CW_ENCODER_0);
      encoder_last_update_time = timer_read(); /* Update the last time that the encoder was detected as rotated */
    }
  }
  return false;
}
#endif

void housekeeping_task_user(void) {
    #ifdef ENCODER_ENABLE
    uint16_t current_time = timer_read();
    uint16_t elapsed_time_since_last_update = current_time - encoder_last_update_time;
    /* If an encoder has been stationary for encoder_stationary_release_delay_ms, then unregister the joystick buttons for both directions */
    if (elapsed_time_since_last_update >= encoder_stationary_release_delay_ms) {
        unregister_joystick_button(CCW_ENCODER_0);
        unregister_joystick_button(CW_ENCODER_0);
    }
    #endif
}