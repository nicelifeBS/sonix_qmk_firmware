// Copyright 2024 BJ's DCS Box (@nicelife_bs)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

// Min 0, max 32
#define JOYSTICK_BUTTON_COUNT 32
// Min 0, max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 0
// Min 8, max 16
#define JOYSTICK_AXIS_RESOLUTION 10