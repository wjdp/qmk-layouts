#if defined(KEYBOARD_zsa_planck_ez)

#include "planck_ez.h"

// ZSA exclude this if you don't ifdef ORYX_CONFIGURATOR
#define PLANCK_EZ_LED_LOWER 1
#define PLANCK_EZ_LED_RAISE 2
#define PLANCK_EZ_LED_ADJUST 3

layer_state_t layer_state_set_kb(layer_state_t state) {
  planck_ez_left_led_off();
  planck_ez_right_led_off();
  state = layer_state_set_user(state);
  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case PLANCK_EZ_LED_LOWER:
          planck_ez_left_led_on();
          break;
      case PLANCK_EZ_LED_RAISE:
          planck_ez_right_led_on();
          break;
      case PLANCK_EZ_LED_ADJUST:
          planck_ez_right_led_on();
          planck_ez_left_led_on();
          break;
      default:
          break;
  }
  return state;
}

#endif