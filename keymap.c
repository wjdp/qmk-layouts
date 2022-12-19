/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_uk.h"
#include "keys.h"
#include "sounds.h"

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable(); // Enable RGB by default
  // Newer QMK doesn't have this, unsure if needed
  // rgblight_sethsv_white();  // Set it to white by default
}

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _WM,
  _MOUSE,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  WP_TODO,

  SN_0001,
  SN_0002,
  SN_0003,
  SN_0004,
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

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SYM3] = ACTION_TAP_DANCE_DOUBLE(UK_PERC, UK_PND),
    [TD_SYM4] = ACTION_TAP_DANCE_DOUBLE(UK_CIRC, UK_DLR),
    [TD_LDBR] = ACTION_TAP_DANCE_DOUBLE(UK_LBRC, UK_LABK),
    [TD_RDBR] = ACTION_TAP_DANCE_DOUBLE(UK_RBRC, UK_RABK),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   P  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN,    KC_BSPC,
  ESCKEY,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,       KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_ENT ,
  CAPSKEY, KC_LALT, KC_LGUI, KC_LCTL, LOWER,   KC_SPC,  KC_SPC,  RAISE,   MO(_WM), KC_LEAD, OSM(KC_MEH),KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
// [_LOWER] = LAYOUT_planck_grid(
//     UK_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
//     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
//     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
//     _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
// ),

[_LOWER] = LAYOUT_planck_grid(
  UK_GRV,   KC_EXLM,  KC_HOME,       KC_UP,    KC_END,         TD(TD_SYM3), TD(TD_SYM4), KC_AMPR,  KC_ASTR,   KC_LCBR,        KC_RCBR,      _______,
  _______,  KC_ENTER, KC_LEFT,       KC_DOWN,  KC_RIGHT,       KC_UNDS,     KC_COLN,     KC_MINUS, KC_EQUAL,  KC_LPRN,        KC_RPRN,      UK_DQUO,
  _______,  UK_BSLS,  LCTL(KC_LEFT), XXXXXXX,  LCTL(KC_RIGHT), UK_PIPE,     KC_PLUS,     UK_HASH,  UK_TILD,   TD(TD_LDBR),    TD(TD_RDBR),  _______,
  _______,  _______,  _______,       _______,  _______,        _______,     _______,     _______,  _______,   LSFT(KC_RALT),  _______,      CAPSWRD
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
// [_RAISE] = LAYOUT_planck_grid(
//     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
//     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
//     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
// ),

[_RAISE] = LAYOUT_planck_grid(
  _______,  KC_F1,    KC_F2,         KC_F3,    KC_F4,          KC_NO,       KC_KP_ASTERISK, KC_7,     KC_8,  KC_9,   KC_KP_MINUS,  _______,
  _______,  KC_F5,    KC_F6,         KC_F7,    KC_F8,          KC_NO,       KC_KP_SLASH,    KC_4,     KC_5,  KC_6,   KC_0,         KC_DELETE,
  _______,  KC_F9,    KC_F10,        KC_F11,   KC_F12,         KC_NO,       KC_EQUAL,       KC_1,     KC_2,  KC_3,   KC_KP_PLUS,   _______,
  _______,  _______,  _______,       _______,  _______,        _______,     _______,        _______,  KC_0,  KC_DOT, _______,      KC_CAPS_LOCK
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
  _______, I3_QUIT, I3_WS_L, I3_WN_U, I3_WS_R, _______, _______, _______, _______, _______, KC_INS,  KC_DELETE,
  QK_BOOT, _______, I3_WN_L, I3_WN_D, I3_WN_R, _______, KC_VOLU, KC_LSFT, KC_LCTL, _______, KC_PSCR, SN_0002,
  _______, AU_ON,   AU_OFF,  CK_TOGG, CK_UP,   CK_DOWN, KC_VOLD, _______, _______, _______, _______, SN_0003,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SN_0004
),

[_WM] = LAYOUT_planck_grid(
  _______, I3_WS_5, I3_WS_6, I3_WS_7, I3_WS_8, _______, _______, I3_WS_15, I3_WS_16, I3_WS_17, I3_WS_18, _______,
  _______, I3_WS_1, I3_WS_2, I3_WS_3, I3_WS_4, I3_WS_A, I3_WS_B, I3_WS_11, I3_WS_12, I3_WS_13, I3_WS_14, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     I3_TERM,
  _______, _______, _______, KC_LALT, I3_LAST, I3_WIND, I3_WIND, I3_UGNT, _______, _______, _______,     _______
),

/* Mouse layer
 * ,---------------------------------------------------------------------------------------------------------.
 * |      |        |        |        |        |        |        | Whl Up | M Up   | Whl Dn | PageUp |        |
 * |------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |      |        |        |        |        |        | Ctrl   | M Left | M Down | M Right| PageDn |        |
 * |------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |      |        |        |        |        |        | WWWBk  | WWWFw  |        |        |        |        |
 * |------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |      |        | Acclr1 | Acclr2 | Acclr3 | Click button 1  | CBtn2  | CBtn3  |        |        |        |
 * ,---------------------------------------------------------------------------------------------------------.
 */
[_MOUSE] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, KC_PGUP, _______,
  _______, _______, _______, _______, _______, _______, KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, KC_WBAK, KC_WFWD, _______, _______, _______, _______,
  _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______
),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// array of songs
float song_1[][2] = SONG(WP_MARIO_MUSHROOM);
float song_2[][2] =  SONG(WP_MEGALOVANIA);
float song_3[][2] =  SONG(USSR_ANTHEM);
float song_4[][2] =  SONG(WP_RICK_ROLL);

void set_backlight_for_layer(uint8_t hue, uint8_t sat, uint8_t val) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(hue, sat, val);
} 

layer_state_t layer_state_set_user(layer_state_t state) {
  layer_state_t adjusted_state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
      rgblight_disable_noeeprom();
      break;
  }
  return adjusted_state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case WP_TODO:
      PLAY_SONG(plover_gb_song);
      return false;
    case SN_0001:
      PLAY_SONG(song_1);
      return false;
    case SN_0002:
      PLAY_SONG(song_2);
      return false;
    case SN_0003:
      PLAY_SONG(song_3);
      return false;
    case SN_0004:
      PLAY_SONG(song_4);
      return false;
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_Q) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    // Select whole line
    SEQ_TWO_KEYS(KC_D, KC_D) {
      tap_code(KC_HOME);
      register_code(KC_LEFT_SHIFT);
      tap_code(KC_END);
      unregister_code(KC_LEFT_SHIFT);
    }
    // Select to start of line
    SEQ_TWO_KEYS(KC_D, KC_W) {
      register_code(KC_LEFT_SHIFT);
      tap_code(KC_HOME);
      unregister_code(KC_LEFT_SHIFT);
    }
    // Select to end of line
    SEQ_TWO_KEYS(KC_D, KC_R) {
      register_code(KC_LEFT_SHIFT);
      tap_code(KC_END);
      unregister_code(KC_LEFT_SHIFT);
    }
    // Select word
    SEQ_TWO_KEYS(KC_D, KC_E) {
      register_code(KC_LEFT_CTRL);
      tap_code(KC_LEFT);
      register_code(KC_LEFT_SHIFT);
      tap_code(KC_RIGHT);
      unregister_code(KC_LEFT_CTRL);
      unregister_code(KC_LEFT_SHIFT);
    }
    // Select to start of word
    SEQ_TWO_KEYS(KC_D, KC_S) {
      register_code(KC_LEFT_SHIFT);
      register_code(KC_LEFT_CTRL);
      tap_code(KC_LEFT);
      unregister_code(KC_LEFT_CTRL);
      unregister_code(KC_LEFT_SHIFT);
    }
    // Select to end of word
    SEQ_TWO_KEYS(KC_D, KC_F) {
      register_code(KC_LEFT_SHIFT);
      register_code(KC_LEFT_CTRL);
      tap_code(KC_RIGHT);
      unregister_code(KC_LEFT_CTRL);
      unregister_code(KC_LEFT_SHIFT);
    }
    // Setup a 1,2 terminal workspace
    SEQ_TWO_KEYS(KC_W, KC_T) {
      register_code(KC_LGUI);
      tap_code(KC_ENTER);
      tap_code(KC_ENTER);
      wait_ms(100);
      tap_code(KC_V);
      tap_code(KC_ENTER);
      wait_ms(100);
      tap_code(KC_UP);
      tap_code(KC_LEFT);
      unregister_code(KC_LGUI);
    }
  }
}
