// Copyright 2022 @boardsource
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "keymap_uk.h"
#include "keys.h"
#include "sounds.h"

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _WM,
  _MOUSE,
  _DEBUG,
  _GAME_WASD,
  _GAME_ESDF,
  _GAME_LOWER,
  _GAME_RAISE,
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
  WP_SPCL, // left space
  WP_SPCR, // right space
  WP_SPCC, // print space counts
  WP_SNG1, // song 1
};

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Escape, twice for Caps Lock
  [TD_SYM3] = ACTION_TAP_DANCE_DOUBLE(UK_PERC, UK_PND),
  [TD_SYM4] = ACTION_TAP_DANCE_DOUBLE(UK_CIRC, UK_DLR),
  [TD_LDBR] = ACTION_TAP_DANCE_DOUBLE(UK_LBRC, UK_LABK),
  [TD_RDBR] = ACTION_TAP_DANCE_DOUBLE(UK_RBRC, UK_RABK),
};

// Custom key names to keep the keymap readable
#define WP_WRDL LCTL(KC_LEFT)
#define WP_WRDR LCTL(KC_RGHT)
#define WP_SYM3 TD(TD_SYM3)
#define WP_SYM4 TD(TD_SYM4)
#define WP_LDBR TD(TD_LDBR)
#define WP_RDBR TD(TD_RDBR)

// Custom key names for the keypad keys
// QMK should probably have these
#define KP_AST KC_KP_ASTERISK
#define KP_SLSH KC_KP_SLASH
#define KP_PLUS KC_KP_PLUS
#define KP_EQL KC_KP_EQUAL
#define KP_MINS KC_KP_MINUS

// Mod tap keys, left hand
#define MT_A LSFT_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LGUI_T(KC_D)
#define MT_F LCTL_T(KC_F)
// Mod tap keys, right hand
#define MT_J LCTL_T(KC_J)
#define MT_K LGUI_T(KC_K)
#define MT_L LALT_T(KC_L)
#define MT_P LSFT_T(KC_P)

// Mod taps in the lower layer
#define MTL_R1 LSFT_T(KC_MINS) // I've put shift here as I want to use with arrow keys
#define MTL_R2 LGUI_T(KC_EQL)  // Unused, there's not really much use for super on the lower layer
#define MTL_R3 LALT_T(KC_LPRN) // does not work well as brackets are fake keys that send a shifted keypress
#define MTL_R4 LSFT_T(KC_RPRN) // with mod-tap this misbehaves https://github.com/qmk/qmk_firmware/issues/2440

// Mod taps in the raise layer, left hand
#define MTR_L1 MT(MOD_LSFT, KC_F5)
#define MTR_L2 MT(MOD_LALT, KC_F6)
#define MTR_L3 MT(MOD_LGUI, KC_F7)
#define MTR_L4 MT(MOD_LCTL, KC_F8)
// Mod taps in the raise layer, right hand
#define MTR_R1 MT(MOD_LCTL, KC_4)
#define MTR_R2 MT(MOD_LGUI, KC_5)
#define MTR_R3 MT(MOD_LALT, KC_6)
#define MTR_R4 MT(MOD_LSFT, KC_0)

// Keys for debugger in JetBrains IDEs
#define DB_STOP C(KC_F2)
#define DB_RUN C(KC_F5)
#define DB_RESM KC_F9
#define DB_STOV KC_F8 // Step over
#define DB_STIN KC_F7 // Step into
#define DB_STMY A(S(KC_F7)) // Step into my code
#define DB_STOU S(KC_F6) // Step out
#define DB_EXPT A(KC_F10) // Exec point
#define DB_JUMP A(S(KC_9)) // Jump to cursor

// Layer switching
#define MO_WM MO(_WM)
#define TO_HOME TO(_QWERTY)
#define DF_HOME DF(_QWERTY)
#define TO_DEBG TO(_DEBUG)
#define TO_WASD TO(_GAME_WASD)
#define TO_ESDF TO(_GAME_ESDF)
#define MO_GLOW MO(_GAME_LOWER)
#define MO_GRSE MO(_GAME_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
//  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
// Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
//  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN, KC_BSPC,
  ESCKEY,  MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_P,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  CW_TOGG, KC_LALT, KC_LGUI, KC_LCTL, LOWER,   WP_SPCL, WP_SPCR, RAISE,   MO_WM,   KC_APP,  KC_RALT, KC_RGHT
),
[_LOWER] = LAYOUT_ortho_4x12(
  UK_GRV,  KC_EXLM, KC_HOME, KC_UP,   KC_END,  WP_SYM3, WP_SYM4, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______,
  KC_BSPC, KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_UNDS, KC_COLN, MTL_R1,  KC_EQL,  KC_LPRN, KC_RPRN, UK_DQUO,
  _______, UK_BSLS, WP_WRDL, XXXXXXX, WP_WRDR, UK_PIPE, KC_PLUS, UK_HASH, UK_TILD, WP_LDBR, WP_RDBR, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LSFT, KC_LALT, _______, CW_TOGG
),
//  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
//  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
// Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
//  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_RAISE] = LAYOUT_ortho_4x12(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KP_AST,  KC_7,    KC_8,    KC_9,    KP_SLSH, _______,
  _______, MTR_L1,  MTR_L2,  MTR_L3,  MTR_L4,  KC_NO,   KP_MINS, MTR_R1,  MTR_R2,  MTR_R3,  MTR_R4,  KC_DEL,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KP_PLUS, KC_1,    KC_2,    KC_3,    KP_EQL,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  _______, _______
),
[_ADJUST] = LAYOUT_ortho_4x12(
  XXXXXXX, I3_QUIT, I3_WS_L, I3_WN_U, I3_WS_R, DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, XXXXXXX, KC_INS,  XXXXXXX,
  QK_BOOT, XXXXXXX, I3_WN_L, I3_WN_D, I3_WN_R, DT_UP,   KC_VOLU, KC_LSFT, KC_LCTL, XXXXXXX, KC_PSCR, XXXXXXX,
  KC_CAPS, AU_ON,   AU_OFF,  XXXXXXX, DT_PRNT, DT_DOWN, KC_VOLD, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, WP_SPCC, XXXXXXX, TO_DEBG, TO_WASD, TO_ESDF, XXXXXXX
),
//  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
//  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
// Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
//  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_WM] = LAYOUT_ortho_4x12(
  XXXXXXX, I3_WS5,  I3_WS6,  I3_WS7,  I3_WS8,  XXXXXXX, XXXXXXX, I3_WS15, I3_WS16, I3_WS17, I3_WS18, XXXXXXX,
  XXXXXXX, I3_WS1,  I3_WS2,  I3_WS3,  I3_WS4,  XXXXXXX, XXXXXXX, I3_WS11, I3_WS12, I3_WS13, I3_WS14, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, I3_WS_A, I3_WS_B, I3_TERM,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, I3_LAST, I3_WIND, I3_WIND, I3_UGNT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
[_MOUSE] = LAYOUT_ortho_4x12(
  XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D, KC_PGUP, XXXXXXX,
  XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGDN, XXXXXXX,
  XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX
),
//  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
//  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
// Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
//  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_DEBUG] = LAYOUT_ortho_4x12(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DB_EXPT, DB_JUMP, XXXXXXX, XXXXXXX, XXXXXXX,
  TO_HOME, DB_STOP, XXXXXXX, DB_RUN,  DB_RESM, XXXXXXX, XXXXXXX, DB_STOV, DB_STIN, DB_STMY, DB_STOU, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
[_GAME_WASD] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Y,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_SCLN, KC_BSPC,
  KC_ESC,  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    KC_QUOTE,
  KC_G,    KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, MO_GLOW, KC_SPC,  KC_SPC,  MO_GRSE, MO_WM,   XXXXXXX, XXXXXXX, I3_WN_R
),
[_GAME_ESDF] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN, KC_BSPC,
  KC_ESC,  MT(MOD_LSFT, KC_A),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, MO_GLOW, KC_SPC,  KC_SPC,  MO_GRSE, MO_WM,   XXXXXXX, XXXXXXX, I3_WN_R
),
//  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
//  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
// Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
//  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_GAME_LOWER] = LAYOUT_ortho_4x12(
  _______, KC_EXLM, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______, _______, _______, _______,
  KC_BSPC, KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO_HOME
),
[_GAME_RAISE] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_0,    _______,
  _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO_HOME
),
};

bool isRecording = false;
bool isRecordingLedOn = false;
#define RECORDING_FLASH_INTERVAL 500
static uint16_t recording_timer;

// Listener function => Triggered when you start recording a macro.
bool dynamic_macro_record_start_user(int8_t direction) {
  isRecording = true;
  isRecordingLedOn = true;
  // timer_read() is a built-in function in qmk. => It read the current time
  recording_timer = timer_read();
  return true;
}

// Listener function => Triggered when the macro recording is stopped.
bool dynamic_macro_record_end_user(int8_t direction) {
  isRecording = false;
  isRecordingLedOn = false;
  return true;
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
      case _DEBUG:
        set_backlight_for_layer(HSV_CYAN);
        break;
      case _GAME_WASD:
      case _GAME_ESDF:
      case _GAME_LOWER:
      case _GAME_RAISE:
        set_backlight_for_layer(HSV_GREEN);
        break;
      case _QWERTY:
        bool caps = host_keyboard_led_state().caps_lock;
        if (caps) {
          set_backlight_for_layer(HSV_YELLOW);
        } else {
          clear_backlight();
        }
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

uint32_t count_space_left = 0;
uint32_t count_space_right = 0;

void handle_space(keyrecord_t *record) {
  if (record->event.pressed) {
    register_code(KC_SPC);
  } else if (record->event.pressed == false) {
    unregister_code(KC_SPC);
  }
}

float song[][2] = SONG(WP_RICK_ROLL);
float song_layer_debug[][2] = SONG(PREONIC_SOUND);
float song_layer_game[][2] = SONG(WP_ONE_UP_SOUND);
float song_layer_home[][2] = SONG(STARTUP_SOUND);

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
      return false;
    case WP_SPCL:
      count_space_left += record->event.pressed ? 1 : 0;
      handle_space(record);
      return true;
    case WP_SPCR:
      count_space_right += record->event.pressed ? 1 : 0;
      handle_space(record);
      return true;
    case WP_SPCC:
      if (record->event.pressed) {
        // build a string reporting the values of the space counters        
        char space_count_str[32];
        sprintf(space_count_str, "Left: %lu, Right: %lu", count_space_left, count_space_right);
        SEND_STRING(space_count_str);
      }
      return true;
    case WP_SNG1:
      if (record->event.pressed) {PLAY_SONG(song);}
      return true;
    case TO_DEBG:
      if (record->event.pressed) {PLAY_SONG(song_layer_debug);}
      return true;
    case TO_WASD:
    case TO_ESDF:
      if (record->event.pressed) {PLAY_SONG(song_layer_game);}
      return true;
    case TO_HOME:
      if (record->event.pressed) {PLAY_SONG(song_layer_home);}
      return true;
    default:
      return true;
  }
}


// Define some colours as 3 int arrays
#define _PASS_ {-1, -1, -1}
#define CL_OFF {0, 0, 0}       // Off
#define CL_RED {190, 18, 10}   // Red
#define CL_GRN {21, 163, 33}   // Green
#define CL_BLU {35, 57, 219}   // Blue
#define CL_YEL {238, 242, 7}   // Yellow
#define CL_ORG {242, 144, 7}   // Orange
#define CL_MAG {242, 12, 242}   // Magenta
#define CL_FFF {255, 255, 255} // White
#define CL_CYN {0, 255, 255}   // Cyan

#define CL_DEL {168, 18, 10}   // Delete or backspace
#define CL_ESC {255, 0, 0}     // Exit or escape
#define CL_REC {255, 5, 5}     // Record macro
#define CL_PLY {21, 255, 33}   // Play macro
#define CL_SP1 {240, 98, 50}   // Speed (slow)
#define CL_SP2 {245, 82, 27}   // Speed (medium)
#define CL_SP3 {250, 67, 5}    // Speed (fast)
#define CL_VUP {100, 255, 50}  // Volume up
#define CL_VDN {255, 100, 50}  // Volume down
#define CL_TUP {214, 255, 50}  // Tapping term up
#define CL_TDN {255, 156, 50}  // Tapping term down

#ifdef KEYBOARD_boardsource_equals_48
// Define an 2d array of RGB LED colours with rows and columns

const uint8_t PROGMEM colourmaps[][MATRIX_ROWS][MATRIX_COLS][3] = {
 //  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
 //  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
 // Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
 //  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_QWERTY] = {
  {CL_BLU,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_DEL},
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
  {_PASS_,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_BLU},
  {_PASS_,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
}, 
[_LOWER] = {
  {CL_GRN,  CL_GRN,  CL_BLU,  CL_YEL,  CL_BLU,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN,  CL_DEL},
  {CL_DEL,  CL_BLU,  CL_YEL,  CL_YEL,  CL_YEL,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN},
  {_PASS_,  CL_GRN,  CL_YEL,  CL_OFF,  CL_YEL,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN,  CL_GRN,  CL_BLU},
  {_PASS_,  CL_OFF,  CL_OFF,  CL_OFF,  CL_GRN,  CL_GRN,  CL_GRN,  CL_OFF,  CL_YEL,  CL_FFF,  CL_OFF,  {RGB_MAGENTA}},
},
 //  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
 //  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
 // Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
 //  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_RAISE] = {
  {CL_OFF,  CL_YEL,  CL_YEL,  CL_YEL,  CL_YEL,  CL_OFF,  CL_GRN,  CL_FFF,  CL_FFF,  CL_FFF,  CL_GRN,  CL_DEL},
  {CL_OFF,  CL_YEL,  CL_YEL,  CL_YEL,  CL_YEL,  CL_OFF,  CL_GRN,  CL_FFF,  CL_FFF,  CL_FFF,  CL_FFF,  CL_DEL},
  {_PASS_,  CL_YEL,  CL_YEL,  CL_YEL,  CL_YEL,  CL_OFF,  CL_GRN,  CL_FFF,  CL_FFF,  CL_FFF,  CL_GRN,  CL_BLU},
  {_PASS_,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_YEL,  CL_YEL,  CL_YEL,  CL_FFF,  CL_FFF,  CL_OFF,  {RGB_YELLOW}},
},
[_ADJUST] = {
  {CL_OFF,  CL_RED,  CL_FFF,  CL_BLU,  CL_FFF,  CL_REC,  CL_REC,  CL_PLY,  CL_PLY,  CL_OFF,  CL_FFF,  CL_OFF},
  {CL_ESC,  CL_OFF,  CL_BLU,  CL_BLU,  CL_BLU,  CL_TUP,  CL_VUP,  CL_FFF,  CL_FFF,  CL_OFF,  CL_FFF,  CL_OFF},
  {_PASS_,  CL_VUP,  CL_VDN,  CL_OFF,  CL_PLY,  CL_TDN,  CL_VDN,  CL_MAG,  CL_MAG,  CL_MAG,  CL_OFF,  CL_OFF},
  {_PASS_,  CL_OFF,  CL_OFF,  CL_OFF,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_GRN,  CL_OFF,  CL_OFF},
},
 //  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
 //  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
 // Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
 //  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_WM] = {
  {CL_OFF,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_OFF,  CL_OFF,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_OFF},
  {CL_OFF,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_OFF},
  {CL_FFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_CYN},
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_FFF,  CL_MAG,  CL_MAG,  CL_MAG,  CL_RED,  CL_MAG,  CL_OFF,  CL_OFF,  CL_OFF},
},
[_MOUSE] = {
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_FFF,  CL_YEL,  CL_FFF,  CL_BLU,  CL_OFF},
  {CL_YEL,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_FFF,  CL_YEL,  CL_YEL,  CL_YEL,  CL_BLU,  CL_OFF},
  {_PASS_,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_CYN,  CL_CYN,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
  {CL_OFF,  CL_OFF,  CL_SP1,  CL_SP2,  CL_SP3,  CL_OFF,  CL_ORG,  CL_ORG,  CL_ORG,  CL_OFF,  CL_OFF,  CL_OFF},
},
 //  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
 //  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
 // Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
 //  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_DEBUG] = {
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_BLU,  CL_BLU,  CL_OFF,  CL_OFF,  CL_OFF},
  {CL_ESC,  CL_RED,  CL_OFF,  CL_PLY,  CL_GRN,  CL_OFF,  CL_OFF,  CL_BLU,  CL_BLU,  CL_BLU,  CL_BLU,  CL_OFF},
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
},
[_GAME_WASD] = {
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_GRN,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
  {CL_ESC,  CL_OFF,  CL_GRN,  CL_GRN,  CL_GRN,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
},
 //  Tab  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    ;   |  Bksp
 //  Esc  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    P   |  "
 // Shift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  Enter
 //  OSM  |  Alt   | Super  |  Ctrl  |  Lower |      Space      | Raise  |   WM   |    ?   |    ?   |  Right
[_GAME_LOWER] = {
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_YEL,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
  {CL_OFF,  CL_OFF,  CL_YEL,  CL_YEL,  CL_YEL,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF},
  {CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_OFF,  CL_ESC},
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
