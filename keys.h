#pragma once

#define ESCKEY LT(_MOUSE, KC_ESC)
#define CAPSKEY OSM(MOD_LSFT)

#define I3_QUIT LGUI(KC_Q)

// Navigate workspaces
#define I3_WS_L LGUI(LSFT(KC_TAB))
#define I3_WS_R LGUI(KC_TAB)

// Directional window navigation keys
#define I3_WN_U LGUI(KC_UP)
#define I3_WN_D LGUI(KC_DOWN)
#define I3_WN_L LGUI(KC_LEFT)
#define I3_WN_R LGUI(KC_RIGHT)

// Left hand workspace navigation keys
#define I3_WS_1 LGUI(KC_1)
#define I3_WS_2 LGUI(KC_2)
#define I3_WS_3 LGUI(KC_3)
#define I3_WS_4 LGUI(KC_4)
#define I3_WS_5 LGUI(KC_5)
#define I3_WS_6 LGUI(KC_6)
#define I3_WS_7 LGUI(KC_7)
#define I3_WS_8 LGUI(KC_8)

// Right hand workspace navigation keys
#define I3_WS_11 LGUI(LCTL(KC_1))
#define I3_WS_12 LGUI(LCTL(KC_2))
#define I3_WS_13 LGUI(LCTL(KC_3))
#define I3_WS_14 LGUI(LCTL(KC_4))
#define I3_WS_15 LGUI(LCTL(KC_5))
#define I3_WS_16 LGUI(LCTL(KC_6))
#define I3_WS_17 LGUI(LCTL(KC_7))
#define I3_WS_18 LGUI(LCTL(KC_8))

#define I3_WS_A LALT(LGUI(LCTL(KC_J)))
#define I3_WS_B LALT(LGUI(LCTL(KC_K)))

// Goto last workspace
#define I3_LAST LGUI(KC_Z)
// Goto urgent workspace
#define I3_UGNT LGUI(KC_X)

// Launch terminal
#define I3_TERM LGUI(KC_ENTER)
// Menu
#define I3_MENU LGUI(KC_D)
// Search windows
#define I3_WIND LCTL(LGUI(KC_SPACE))
