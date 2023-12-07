// Copyright 2022 @boardsource
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "keymap_uk.h"
#include "keys.h"

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _WM,
  _MOUSE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Tap dance declarations
enum tap_dance_keys {
  TD_SYM3,
  TD_SYM4,
  TD_LDBR,
  TD_RDBR,
};

enum keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  WP_TODO,
};

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Escape, twice for Caps Lock
  [TD_SYM3] = ACTION_TAP_DANCE_DOUBLE(UK_PERC, UK_PND),
  [TD_SYM4] = ACTION_TAP_DANCE_DOUBLE(UK_CIRC, UK_DLR),
  [TD_LDBR] = ACTION_TAP_DANCE_DOUBLE(UK_LBRC, UK_LABK),
  [TD_RDBR] = ACTION_TAP_DANCE_DOUBLE(UK_RBRC, UK_RABK),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN,    KC_BSPC,
  ESCKEY,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,       KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_ENT,
  OSM_SFT, KC_LALT, KC_LGUI, KC_LCTL, LOWER,   KC_SPC,  KC_SPC,  RAISE,   MO(_WM), XXXXXXX, XXXXXXX,    KC_RGHT
),
[_LOWER] = LAYOUT_ortho_4x12(
  UK_GRV,   KC_EXLM,  KC_HOME,       KC_UP,    KC_END,         TD(TD_SYM3), TD(TD_SYM4), KC_AMPR,  KC_ASTR,       KC_LCBR,     KC_RCBR,      _______,
  KC_BSPC,  KC_ENTER, KC_LEFT,       KC_DOWN,  KC_RIGHT,       KC_UNDS,     KC_COLN,     KC_MINUS, KC_EQUAL,      KC_LPRN,     KC_RPRN,      UK_DQUO,
  _______,  UK_BSLS,  LCTL(KC_LEFT), XXXXXXX,  LCTL(KC_RIGHT), UK_PIPE,     KC_PLUS,     UK_HASH,  UK_TILD,       TD(TD_LDBR), TD(TD_RDBR),  _______,
  _______,  _______,  _______,       _______,  _______,        _______,     _______,     _______,  LSFT(KC_RALT), _______,     _______,      CW_TOGG
),
[_RAISE] = LAYOUT_ortho_4x12(
  _______,  KC_F1,    KC_F2,         KC_F3,    KC_F4,          KC_NO,       KC_KP_ASTERISK, KC_7,     KC_8,  KC_9,   KC_KP_MINUS,  _______,
  _______,  KC_F5,    KC_F6,         KC_F7,    KC_F8,          KC_NO,       KC_KP_SLASH,    KC_4,     KC_5,  KC_6,   KC_0,         KC_DELETE,
  _______,  KC_F9,    KC_F10,        KC_F11,   KC_F12,         KC_NO,       KC_EQUAL,       KC_1,     KC_2,  KC_3,   KC_KP_PLUS,   _______,
  _______,  _______,  _______,       _______,  _______,        _______,     _______,        _______,  KC_0,  KC_DOT, _______,      KC_CAPS_LOCK
),
[_ADJUST] = LAYOUT_ortho_4x12(
  XXXXXXX, I3_QUIT, I3_WS_L, I3_WN_U, I3_WS_R, DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, XXXXXXX, KC_INS,  XXXXXXX,
  QK_BOOT, XXXXXXX, I3_WN_L, I3_WN_D, I3_WN_R, XXXXXXX, KC_VOLU, KC_LSFT, KC_LCTL, XXXXXXX, KC_PSCR, XXXXXXX,
  XXXXXXX, AU_ON,   AU_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
[_WM] = LAYOUT_ortho_4x12(
  XXXXXXX, I3_WS_5, I3_WS_6, I3_WS_7, I3_WS_8, XXXXXXX, XXXXXXX, I3_WS_15, I3_WS_16, I3_WS_17, I3_WS_18, XXXXXXX,
  XXXXXXX, I3_WS_1, I3_WS_2, I3_WS_3, I3_WS_4, I3_WS_A, I3_WS_B, I3_WS_11, I3_WS_12, I3_WS_13, I3_WS_14, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     I3_TERM,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, I3_LAST, I3_WIND, I3_WIND, I3_UGNT, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX
),
[_MOUSE] = LAYOUT_ortho_4x12(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D, KC_PGUP, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGDN, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX
),
};


bool isRecording = false;
bool isRecordingLedOn = false;
#define RECORDING_FLASH_INTERVAL 500
static uint16_t recording_timer;

// Listener function => Triggered when you start recording a macro.
void dynamic_macro_record_start_user(int8_t direction) {
  isRecording = true;
  isRecordingLedOn = true;
  // timer_read() is a built-in function in qmk. => It read the current time
  recording_timer = timer_read();
}

// Listener function => Triggered when the macro recording is stopped.
void dynamic_macro_record_end_user(int8_t direction) {
  isRecording = false;
  isRecordingLedOn = false;
}

bool caps_word_active = false;
void caps_word_set_user(bool active) {caps_word_active = active;}

uint8_t mods_active = 0;
void oneshot_mods_changed_user(uint8_t mods) {mods_active = mods;}


void clear_backlight(void) {
  rgblight_disable_noeeprom();
}

void set_backlight_for_layer(uint8_t hue, uint8_t sat, uint8_t val) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(hue, sat, val);
} 

layer_state_t layer_state_set_user(layer_state_t state) {
  layer_state_t adjusted_state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  #ifdef KEYBOARD_planck_rev6_drop
    switch(biton32(adjusted_state)) {
      case _LOWER:
        set_backlight_for_layer(HSV_GREEN);
        break;
      case _RAISE:
        set_backlight_for_layer(HSV_YELLOW);
        break;
      case _ADJUST:
        set_backlight_for_layer(HSV_BLUE);
        break;
      case _WM:
        set_backlight_for_layer(HSV_MAGENTA);
        break;
      case _MOUSE:
        set_backlight_for_layer(HSV_CYAN);
        break;
      default:
        clear_backlight();
        break;
    }
  #endif
  return adjusted_state;
}


static float disabled_key_sound[][2] = SONG(AG_NORM_SOUND);
bool pressed_disabled_key = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case XXXXXXX:
      if (record->event.pressed) {
        pressed_disabled_key = true;
        #ifdef AUDIO_ENABLE
          PLAY_SONG(disabled_key_sound);
        #endif
      } else if (record->event.pressed == false) {
        pressed_disabled_key = false;
      }
    default:
      return true;
  }
}


// Define some colours as 3 int arrays
#define _PASS_ {-1, -1, -1}
#define CL_OFF {0, 0, 0}
#define CL_RED {168, 18, 10}
#define CL_REC {255, 5, 5}
#define CL_PLY {21, 230, 33}
#define CL_GRN {21, 163, 33}
#define CL_BLU {35, 57, 219}
#define CL_YEL {238, 242, 7}
#define CL_MAG {255, 0, 255}
#define CL_FFF {255, 255, 255}
#define CL_CYN {0, 255, 255}
#define CL_VUP {100, 255, 50}
#define CL_VDN {255, 100, 50}

#ifdef KEYBOARD_boardsource_equals_48
// Define an 2d array of RGB LED colours with rows and columns

const uint8_t PROGMEM colourmaps[][MATRIX_ROWS][MATRIX_COLS][3] = {
  [_QWERTY] = {
    {CL_BLU, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_RED}, 
    {CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF}, 
    {_PASS_, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_BLU}, 
    {_PASS_, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF}, 
  }, 
  [_LOWER] = {
    {CL_GRN, CL_GRN, CL_BLU, CL_YEL, CL_BLU, CL_GRN, CL_GRN, CL_GRN, CL_GRN, CL_GRN, CL_GRN, CL_RED}, 
    {CL_RED, CL_BLU, CL_YEL, CL_YEL, CL_YEL, CL_GRN, CL_GRN, CL_GRN, CL_GRN, CL_GRN, CL_GRN, CL_GRN}, 
    {_PASS_, CL_GRN, CL_YEL, CL_OFF, CL_YEL, CL_GRN, CL_GRN, CL_GRN, CL_GRN, CL_GRN, CL_GRN, CL_BLU}, 
    {_PASS_, CL_OFF, CL_OFF, CL_OFF, CL_GRN, CL_GRN, CL_GRN, CL_OFF, CL_YEL, CL_OFF, CL_OFF, {RGB_MAGENTA}}, 
  }, 
  [_RAISE] = {
    {CL_OFF, CL_YEL, CL_YEL, CL_YEL, CL_YEL, CL_OFF, CL_GRN, CL_FFF, CL_FFF, CL_FFF, CL_GRN, CL_RED}, 
    {CL_OFF, CL_YEL, CL_YEL, CL_YEL, CL_YEL, CL_OFF, CL_GRN, CL_FFF, CL_FFF, CL_FFF, CL_FFF, CL_RED}, 
    {_PASS_, CL_YEL, CL_YEL, CL_YEL, CL_YEL, CL_OFF, CL_GRN, CL_FFF, CL_FFF, CL_FFF, CL_GRN, CL_BLU}, 
    {_PASS_, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_YEL, CL_YEL, CL_YEL, CL_FFF, CL_FFF, CL_OFF, {RGB_YELLOW}}, 
  },
  [_ADJUST] = {
    {CL_OFF, CL_RED, CL_FFF, CL_BLU, CL_FFF, CL_REC, CL_REC, CL_PLY, CL_PLY, CL_OFF, CL_FFF, CL_OFF}, 
    {CL_RED, CL_OFF, CL_BLU, CL_BLU, CL_BLU, CL_OFF, CL_VUP, CL_FFF, CL_FFF, CL_OFF, CL_FFF, CL_OFF}, 
    {_PASS_, CL_VUP, CL_VDN, CL_OFF, CL_OFF, CL_OFF, CL_VDN, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF}, 
    {_PASS_, CL_OFF, CL_OFF, CL_OFF, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_OFF, CL_OFF, CL_OFF, CL_OFF}, 
  },
  [_WM] = {
    {CL_OFF, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_OFF, CL_OFF, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_OFF}, 
    {CL_OFF, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_BLU, CL_OFF}, 
    {CL_FFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_CYN}, 
    {CL_OFF, CL_OFF, CL_OFF, CL_FFF, CL_MAG, CL_MAG, CL_MAG, CL_RED, CL_MAG, CL_OFF, CL_OFF, CL_OFF}, 
  },
  [_MOUSE] = {
    {CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_FFF, CL_YEL, CL_FFF, CL_BLU, CL_OFF}, 
    {CL_YEL, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_FFF, CL_YEL, CL_YEL, CL_YEL, CL_BLU, CL_OFF}, 
    {_PASS_, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_OFF, CL_CYN, CL_CYN, CL_OFF, CL_OFF, CL_OFF, CL_OFF}, 
    {CL_OFF, CL_OFF, CL_MAG, CL_MAG, CL_MAG, CL_OFF, CL_YEL, CL_YEL, CL_YEL, CL_OFF, CL_OFF, CL_OFF}, 
  },
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  // loop over all values between led_min and led_max
  // setting the colour of each LED to the colour of the corresponding key
  int layer = get_highest_layer(layer_state);
  for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        if (colourmaps[layer][row][col][0] == -1) continue; // skip if no colour (i.e. _PASS_)
        uint8_t index = g_led_config.matrix_co[row][col];
        rgb_matrix_set_color(
          index, 
          colourmaps[layer][row][col][0], colourmaps[layer][row][col][1], colourmaps[layer][row][col][2]
        );
    }
  }
  uint8_t capsIndex = g_led_config.matrix_co[2][0];
  if (caps_word_active) {
    rgb_matrix_set_color(capsIndex, RGB_MAGENTA);
  } else if (host_keyboard_led_state().caps_lock) {
    rgb_matrix_set_color(capsIndex, RGB_YELLOW);
  } else {
    rgb_matrix_set_color(capsIndex, RGB_OFF);
  }

  uint8_t osmShiftIndex = g_led_config.matrix_co[3][0];
  if (mods_active & MOD_MASK_SHIFT) {
    rgb_matrix_set_color(osmShiftIndex, RGB_MAGENTA);
  } else {
    rgb_matrix_set_color(osmShiftIndex, RGB_OFF);
  }

  // If a disabled key is pressed, turn all disabled keys red
  if (pressed_disabled_key) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t index = g_led_config.matrix_co[row][col];
        if (keymap_key_to_keycode(layer, (keypos_t){col,row}) == XXXXXXX) {
          rgb_matrix_set_color(index, RGB_RED);
        }
      }
    }
  }

  // Flash some LEDs when recording a macro
  if (isRecording) {
    // timer_elapsed() is a built-in function in qmk => it calculates in ms the time elapsed with timer_read()
    if (timer_elapsed(recording_timer) > RECORDING_FLASH_INTERVAL) {
      isRecordingLedOn = !isRecordingLedOn;
      recording_timer = timer_read();
    }
    if (isRecordingLedOn) {
      rgb_matrix_set_color(g_led_config.matrix_co[3][4], RGB_RED);
      rgb_matrix_set_color(g_led_config.matrix_co[3][7], RGB_RED);
    }
  }

  return false;
}

// Turn off the backlight when the host goes to sleep
void suspend_power_down_kb(void) {rgb_matrix_set_suspend_state(true);}
void suspend_wakeup_init_kb(void) {rgb_matrix_set_suspend_state(false);}
#endif


void keyboard_post_init_user(void) {
  set_single_persistent_default_layer(_QWERTY);
  #ifdef KEYBOARD_planck_rev6_drop
    clear_backlight();
  #endif
  #ifdef KEYBOARD_boardsource_equals_48
    // Default LEDs off, no animations or backlight
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
  #endif
}