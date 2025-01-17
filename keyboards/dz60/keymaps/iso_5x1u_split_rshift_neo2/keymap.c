/* Copyright 2024 IantoKX (@IantoKX)
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

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,     // can always be here
  US_OSX_SMALL_UE,
  US_OSX_SMALL_AE,
  US_OSX_SMALL_OE,
  US_OSX_CAPITAL_UE,
  US_OSX_CAPITAL_AE,
  US_OSX_CAPITAL_OE,
  NEO2_LMOD3,
  NEO2_RMOD3,
  NEO2_1,
  NEO2_2,
  NEO2_3,
  NEO2_4,
  NEO2_5,
  NEO2_6,
  NEO2_7,
  NEO2_8,
  NEO2_9,
  NEO2_0,
  NEO2_MINUS,
  NEO2_UE,
  NEO2_AE,
  NEO2_OE,
  NEO2_COMMA,
  NEO2_DOT,
  NEO2_SHARP_S,
  NEO2_CRCMFLX,
  NEO2_GRV,
  NEO2_ACUT,
  SYMBOL,
  NUMPAD,

};

enum td_codes  {
  TD_RESET
};


#define _BASE 0
#define _SHIFT 1
#define _SYMBOL 2
#define _NUMPAD 3
#define _GREEK 4
#define _MATH 5
#define _QWERTZ 6
#define _FUNC 7

// bitmasks for modifier keys
#define MODS_NONE   0
#define MODS_SHIFT  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL   (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT    (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI    (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

tap_dance_action_t tap_dance_actions[] = {
    [TD_RESET] = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, QK_BOOT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case NEO2_CRCMFLX:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
          register_unicode(0x30C);
        } else {
          register_code(KC_GRV);
        }
      } else {
        unregister_code(KC_GRV);
      }
      return false;
    case NEO2_1:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
          register_code16(KC_TILD);
        } else {
          register_code(KC_1);
        }
      } else {
        unregister_code16(KC_TILD);
        unregister_code(KC_1);
      }
      return false;
    case NEO2_2:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
          register_code16(KC_HASH);
        } else {
          register_code(KC_2);
        }
      } else {
        unregister_code16(KC_HASH);
        unregister_code(KC_2);
      }
      return false;
    case NEO2_3:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
          register_unicode(0x2113);
        } else {
          register_code(KC_3);
        }
      } else {
        unregister_code(KC_3);
      }
      return false;
    case NEO2_4:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
          register_unicode(0xBB);
        } else {
          register_code(KC_4);
        }
      } else {
        unregister_code(KC_4);
      }
      return false;
    case NEO2_5:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_unicode(0xAB);
          } else {
            register_code(KC_5);
          }
        } else {
          unregister_code(KC_5);
        }
        return false;
    case NEO2_6:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_code16(KC_DLR);
          } else {
            register_code(KC_6);
          }
        } else {
          unregister_code16(KC_DLR);
          unregister_code(KC_6);
        }
        return false;
    case NEO2_7: {
      static uint8_t kc;

        if (record->event.pressed) {
          bool isShifted = get_mods() & MOD_MASK_SHIFT;
          if (isShifted) {
            del_mods(MOD_MASK_SHIFT);
            add_mods(MOD_RALT);
            kc = KC_E;
          } else {
            kc = KC_7;
          }

          register_code(kc);

          if (isShifted) {
            del_mods(MOD_RALT);
            register_code(KC_LSFT);
          }
        } else {
          unregister_code(kc);
        }
        return false;
      }
    case NEO2_8:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_unicode(0x201E);
          } else {
            register_code(KC_8);
          }
        } else {
          unregister_code(KC_8);
        }
        return false;
    case NEO2_9:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_unicode(0x201C);
          } else {
            register_code(KC_9);
          }
        } else {
          unregister_code(KC_9);
        }
        return false;
    case NEO2_0:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_unicode(0x201D);
          } else {
            register_code(KC_0);
          }
        } else {
          unregister_code(KC_0);
        }
        return false;
    case NEO2_MINUS:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_unicode(0x2014);
          } else {
            register_code(KC_SLSH);
          }
        } else {
          unregister_code(KC_SLSH);
        }
        return false;
    case NEO2_GRV:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_unicode(0x327);
          } else {
            register_code16(S(KC_EQL));
          }
        } else {
          unregister_code16(S(KC_EQL));
        }
        return false;
    case NEO2_ACUT:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_unicode(0x303);
          } else {
            register_code(KC_EQL);
          }
        } else {
          unregister_code(KC_EQL);
        }
        return false;
    case NEO2_SHARP_S:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_unicode(0x1E9E);
          } else {
            register_code(KC_MINS);
          }
        } else {
          unregister_code(KC_MINS);
        }
        return false;
    case NEO2_COMMA:
        if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
            register_unicode(0x2013);
          } else {
            register_code(KC_COMM);
          }
        } else {
          unregister_code(KC_COMM);
        }
        return false;
    case NEO2_DOT:
          if (record->event.pressed) {
            if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
              register_unicode(0x2022);
            } else {
              register_code(KC_DOT);
            }
          } else {
            unregister_code(KC_DOT);
          }
          return false;
    case SYMBOL:
    /**
    * FIXME: when both SYMBOLs are pressed, releasing one should not
    * turn off SYMBOL, releasing both should
    */
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
          layer_on(_GREEK);
        } else {
          layer_on(_SYMBOL);
          update_tri_layer(_NUMPAD, _SYMBOL, _MATH);
        }
      } else {
        if (IS_LAYER_ON(_GREEK)) {
          add_mods(MOD_LSFT);
        }
          layer_off(_GREEK);
          layer_off(_SYMBOL);
          update_tri_layer(_NUMPAD, _SYMBOL, _MATH);
      }
      return false;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
        update_tri_layer(_NUMPAD, _SYMBOL, _MATH);
      } else {
        layer_off(_NUMPAD);
        update_tri_layer(_NUMPAD, _SYMBOL, _MATH);
      }
      return false;
    case KC_LSFT:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_SYMBOL)) {
          layer_on(_GREEK);
        } else {
          register_mods(MOD_LSFT);
        }
      } else {
        if (IS_LAYER_ON(_GREEK)) {
          layer_off(_GREEK);
          layer_on(_SYMBOL);
        }
          unregister_mods(MOD_LSFT);
      }
      return false;
    case KC_RSFT:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_SYMBOL)) {
          layer_on(_GREEK);
        } else {
          register_mods(MOD_RSFT);
        }
      } else {
        if (IS_LAYER_ON(_GREEK)) {
          layer_off(_GREEK);
          layer_on(_SYMBOL);
        }
          unregister_mods(MOD_RSFT);
      }
      return false;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_iso_5x1u_split_rshift(
      NEO2_CRCMFLX,    NEO2_1,     NEO2_2,     NEO2_3,     NEO2_4,           NEO2_5,     NEO2_6,     NEO2_7,     NEO2_8,     NEO2_9,     NEO2_0,   NEO2_MINUS,  NEO2_GRV,       KC_BSPC,
            KC_TAB,      KC_X,       KC_V,       KC_L,       KC_C,             KC_W,       KC_K,       KC_H,       KC_G,       KC_F,       KC_Q, NEO2_SHARP_S, NEO2_ACUT,
            SYMBOL,      KC_U,       KC_I,       KC_A,       KC_E,             KC_O,       KC_S,       KC_N,       KC_R,       KC_T,       KC_D,         KC_Z,    SYMBOL,        KC_ENT,
           KC_LSFT,    NUMPAD,    KC_LBRC,    KC_SCLN,    KC_QUOT,             KC_P,       KC_Y,       KC_B,       KC_M, NEO2_COMMA,   NEO2_DOT,         KC_J,   KC_LSFT, LT(7, KC_DEL),
           KC_LCTL,   KC_LGUI,    KC_LALT,                                                   KC_SPC,                         NUMPAD,    KC_LEFT,      KC_DOWN,     KC_UP,       KC_RGHT
    ),
    // [1] = LAYOUT_60_iso_5x1u_split_rshift(
    //      UC(0x30C),         KC_TILD,    KC_HASH, UC(0x2113),   UC(0xBB),         UC(0xAB),     KC_DLR, ALGR(KC_E), UC(0x201E), UC(0x201C), UC(0x201D),       UC(0x2014),  UC(0x327),       KC_BSPC,
    //      S(KC_TAB),         S(KC_X),    S(KC_V),    S(KC_L),    S(KC_C),          S(KC_W),    S(KC_K),    S(KC_H),    S(KC_G),    S(KC_F),    S(KC_Q),       UC(0x1E9E),  UC(0x303),       _______,
    //        _______,         S(KC_U),    S(KC_I),    S(KC_A),    S(KC_E),          S(KC_O),    S(KC_S),    S(KC_N),    S(KC_R),    S(KC_T),    S(KC_D),          S(KC_Z),                 S(KC_ENT),
    //        _______,                  S(KC_LBRC), S(KC_SCLN), S(KC_QUOT),          S(KC_P),    S(KC_Y),    S(KC_B),    S(KC_M), UC(0x2013), UC(0x2022),          S(KC_J),    S(KC_UP),       KC_DEL,
    //     S(KC_LCTL),         _______, S(KC_LALT),                                  _______,                    LM(_NUMPAD, MOD_LSFT),    _______,       S(KC_LEFT),  S(KC_DOWN),    S(KC_RGHT)
    // ),
    [2] = LAYOUT_60_iso_5x1u_split_rshift(
           XXXXXXX,      UC(0xB9),   UC(0xB2),   UC(0xB3),    UC(0x203A),    UC(0x2039),   UC(0xA2),   UC(0xA5), UC(0x201A), UC(0x2018), UC(0x2019),    XXXXXXX, UC(0x30A),   KC_BSPC,
           _______,    UC(0x2026), S(KC_SLSH), ALGR(KC_8),    ALGR(KC_9),      UC(0x5E),    S(KC_1),    KC_NUBS, S(KC_NUBS),    S(KC_0),    S(KC_6),  UC(0x17F), UC(0x338),
           _______, ALGR(KC_MINS),    S(KC_7), ALGR(KC_7),    ALGR(KC_0),    S(KC_RBRC), S(KC_MINS),    S(KC_8),    S(KC_9),    KC_SLSH,  S(KC_DOT), ALGR(KC_Q),   _______,   KC_ENT,
           _______,       _______,    KC_NUHS,     KC_DLR, ALGR(KC_NUBS), ALGR(KC_RBRC),   UC(0x60),    KC_RBRC,    S(KC_5),    S(KC_2), S(KC_NUHS), S(KC_COMM),   _______,   KC_DEL,
           _______,       _______,    _______,                                    _______,                                      _______,    _______,    _______,   _______,  _______
    ),
    [3] = LAYOUT_60_iso_5x1u_split_rshift(
         UC(0x307),    UC(0x1D43), UC(0x1D52), C(0x2116),    UC(0x22EE),     UC(0x183),   UC(0xA3),   UC(0xA4),     KC_TAB,    KC_PSLS,    KC_PAST,    KC_PMNS, UC(0x308), KC_BSPC,
           _______,       KC_PGUP,    KC_BSPC,     KC_UP,        KC_DEL,       KC_PGDN,   UC(0xD7),      KC_P7,      KC_P8,      KC_P9,    KC_PPLS, UC(0x2212), UC(0x30B),
           _______,       KC_HOME,    KC_LEFT,   KC_DOWN,       KC_RGHT,        KC_END,   UC(0xF7),      KC_P4,      KC_P5,      KC_P6,    KC_COMM,     KC_DOT,   _______, KC_PENT,
           KC_LSFT,       _______,     KC_ESC,    KC_TAB,        KC_INS,        KC_ENT,    C(KC_Z),  S(KC_DOT),      KC_P1,      KC_P2,      KC_P3, S(KC_COMM),   _______,  KC_DEL,
           _______,       _______,    _______,                             KC_P0,                                              _______,    _______,    _______,   _______, _______
    ),
    [4] = LAYOUT_60_iso_5x1u_split_rshift(
         UC(0x309),      UC(0x2081), UC(0x2082), UC(0x2083),    UC(0x2642),    UC(0x2640), UC(0x26A5),  UC(0x3F0), UC(0x27E8), UC(0x27E9), UC(0x2080), UC(0x2011), UC(0x314), KC_BSPC,
            KC_TAB,       UC(0x3BE),    XXXXXXX,  UC(0x3BB),     UC(0x3C7),     UC(0x3C9),  UC(0x3BA),  UC(0x3C8),  UC(0x3B3),  UC(0x278),  UC(0x3C6),  UC(0x3C2), UC(0x313),
           _______,         XXXXXXX,  UC(0x3B9),  UC(0x3B1),     UC(0x3B5),     UC(0x3BF),  UC(0x3C3),  UC(0x3BD),  UC(0x3C1),  UC(0x3C4),  UC(0x3B4),  UC(0x3C5),   _______,  KC_ENT,
           _______,         _______,   UC(0xB5),  UC(0x3F5),     UC(0x3B7),     UC(0x3C0),  UC(0x3B6),  UC(0x3B2),  UC(0x3BC),  UC(0x3F1),  UC(0x3D1),  UC(0x3B8),   _______,  KC_DEL,
           _______,         _______,    _______,                            UC(0xA0),                                             _______,    _______,    _______,   _______, _______
    ),
    [5] = LAYOUT_60_iso_5x1u_split_rshift(
         UC(0x323),        UC(0xAC), UC(0x2228), UC(0x2227),    UC(0x22A5),    UC(0x2221), UC(0x2225), UC(0x2192), UC(0x221E), UC(0x221D), UC(0x2205),   UC(0xAD), UC(0x304), KC_BSPC,
            KC_TAB,       UC(0x39E), UC(0x221A),  UC(0x39B),    UC(0x2102),     UC(0x3A9),   UC(0xD7),  UC(0x3A8),  UC(0x393),  UC(0x3A6), UC(0x211A), UC(0x2218), UC(0x306),
           _______,      UC(0x2282), UC(0x222B), UC(0x2200),    UC(0x2203),    UC(0x2208),  UC(0x3A3), UC(0x2115), UC(0x211D), UC(0x2202), UC(0x2206), UC(0x2207),   _______,  KC_ENT,
           KC_LSFT,         _______,  UC(0x22C3), UC(0x22C2),    UC(0x2135),     UC(0x3A0), UC(0x2124), UC(0x21D5), UC(0x21D4), UC(0x21D2), UC(0x21A6),  UC(0x398),  _______,  KC_DEL,
           _______,         _______,    _______,                        UC(0x202F),                                               _______,    _______,    _______,   _______, _______
    ),
    [6] = LAYOUT_60_iso_5x1u_split_rshift(
           KC_ESC,            KC_1,       KC_2,       KC_3,          KC_4,       KC_5,          KC_6,       KC_7,       KC_8,       KC_9,       KC_0,    KC_MINS,    KC_EQL,      KC_BSPC,
           KC_TAB,            KC_Q,       KC_W,       KC_E,          KC_R,       KC_T,          KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,    KC_LBRC,   KC_RBRC,
           KC_CAPS,            KC_A,       KC_S,       KC_D,          KC_F,       KC_G,          KC_H,       KC_J,       KC_K,       KC_L,    KC_SCLN,    KC_QUOT,   KC_HASH,       KC_ENT,
           KC_LSFT,         KC_BSLS,       KC_Z,       KC_X,          KC_C,       KC_V,          KC_B,       KC_N,       KC_M,    KC_COMM,     KC_DOT,    KC_SLSH,   KC_RSFT, LT(7,KC_DEL),
           KC_LCTL,         KC_LGUI,    KC_LALT,                            KC_SPC,                                               KC_RALT,    KC_LEFT,    KC_DOWN,     KC_UP,      KC_RGHT
    ),
    [7] = LAYOUT_60_iso_5x1u_split_rshift(
           QK_BOOT,         KC_F1,      KC_F2,      KC_F3,         KC_F4,      KC_F5,         KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_F10,     KC_F11,    KC_F12,        KC_DEL,
           _______,         RGB_TOG,    _______,    RGB_HUI,       RGB_HUD,    RGB_SAI,       RGB_SAD,    RGB_VAI,    RGB_VAD,    RGB_MOD,    _______,    _______,   _______,
           _______,         _______,    _______,    _______,       _______,    _______,       _______,    _______,    RGB_SPI,    RGB_SPD,    _______,    _______,   _______,       KC_PSCR,
           _______,         _______,    _______,    _______,       _______,    _______,       _______,    _______,    _______,    _______,    _______,    _______,   _______,       _______,
           _______,         _______,    _______,                            _______,                                              _______,    UC_PREV,     UC_WIN,   UC_WINC,       UC_NEXT
    )
};
//
// const rgblight_segment_t PROGMEM layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//   {11, 1, HSV_RED},
//   {31, 3, HSV_RED}
// );
//
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//   layer3_layer
// );
//
// void keyboard_post_init_user(void) {
//   rgblight_layers = my_rgb_layers;
// };
//
// layer_state_t layer_state_set_user(layer_state_t state) {
//   rgblight_set_layer_state(3, layer_state_cmp(state, 0));
//   return state;
// };
