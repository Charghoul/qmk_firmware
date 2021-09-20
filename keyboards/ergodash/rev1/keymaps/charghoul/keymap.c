#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, LT(1,KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_DEL, KC_BSPC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HOME, KC_PGUP, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, LALT(KC_GRV), MO(1), KC_SPC, KC_END, KC_PGDN, KC_ENT, OSL(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

[_LOWER] = LAYOUT(KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_UNDS, KC_PLUS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12, KC_TAB, KC_NO, KC_NO, RALT(KC_5), KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_NO, RALT(KC_Y), KC_NO, KC_NO, RALT(KC_P), KC_PIPE, KC_TILD, RALT(KC_Q), KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_COLN, KC_DQUO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_LT, KC_GT, KC_QUES, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, LALT(KC_GRV), KC_TRNS, KC_SPC, KC_END, KC_PGDN, KC_ENT, MO(3), KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_RAISE] = LAYOUT(KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_UNDS, KC_PLUS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12, KC_TAB, KC_NO, KC_NO, RALT(KC_5), KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_NO, RALT(KC_Y), KC_NO, KC_NO, RALT(KC_P), KC_PIPE, KC_TILD, RALT(KC_Q), KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_COLN, KC_DQUO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_LT, KC_GT, KC_QUES, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, LALT(KC_GRV), MO(3), KC_SPC, KC_END, KC_PGDN, KC_ENT, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_ADJUST] = LAYOUT(RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, BL_TOGG, BL_BRTG, BL_INC, BL_DEC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS) 

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
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
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
