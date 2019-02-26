#include QMK_KEYBOARD_H

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _F1 1 // function layer for unicode
#define _F2 2 // function layer for utilities like bootloader and backlight
#define _SL 3

#define SUP 4
#define SUB 5

#define _______ KC_TRNS
#define CTL_ESC MT(MOD_LCTL,KC_ESC)
#define CTL_GRV LCTL(KC_GRV)

#define X_ALPHA UC(0x03B1)
#define X_BETA  UC(0x03B2)
#define X_GAMMA UC(0x03B3)
#define X_DELTA UC(0x03B4)
#define X_EPS   UC(0x03B5)
#define X_ZETA  UC(0x03B6)
#define X_ETA   UC(0x03B7)
#define X_THETA UC(0x03B8)
#define X_IOTA  UC(0x03B9)
#define X_KAPPA UC(0x03BA)
#define X_LAMBD UC(0x03BB)
#define X_MU    UC(0x03BC)
#define X_NU    UC(0x03BD)
#define X_XI    UC(0x03BE)
#define X_OMIC  UC(0x03BF)
#define X_PI    UC(0x03C0)
#define X_RHO   UC(0x03C1)
#define X_SIGMA UC(0x03C3)
#define X_TAU   UC(0x03C4)
#define X_PHI   UC(0x03C6)
#define X_CHI   UC(0x03C7)
#define X_PSI   UC(0x03C8)
#define X_OMEGA UC(0x03C9)


#define X_SUP0  UC(0x2070)
#define X_SUP1  UC(0x2071)
#define X_SUP2  UC(0x00B2)
#define X_SUP3  UC(0x00B3)
#define X_SUP4  UC(0x2074)
#define X_SUP5  UC(0x2075)
#define X_SUP6  UC(0x2076)
#define X_SUP7  UC(0x2077)
#define X_SUP8  UC(0x2078)
#define X_SUP9  UC(0x2079)

#define X_IBANG UC(0x203D)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |Ctl/Esc|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |ShiftSC |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|ShiftSC   |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |FN1 |Gui |FN2 |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BL] = LAYOUT_60_ansi(
  KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  CTL_ESC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSPO,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSPC, \
  KC_LCTL, KC_LGUI,KC_LALT,                LT(_SL,KC_SPC),                                 TT(_F1),KC_RGUI, MO(_F2),KC_RCTL),

  /* Keymap _F1: Unicode Layer
   * ,-----------------------------------------------------------.
   * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_F1] = LAYOUT_60_ansi(
  KC_ESC,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,_______, \
  _______,_______,X_OMEGA,  X_EPS,  X_RHO,  X_TAU,  X_PSI,_______, X_IOTA,X_THETA,  X_PHI,_______,_______,_______, \
  _______,X_ALPHA,X_SIGMA,X_DELTA,_______,X_GAMMA,_______,_______,_______,_______,_______,_______,        _______, \
  MO(SUP),         X_ZETA,  X_CHI,_______,   X_NU,X_BETA ,  X_ETA,_______,_______,_______,_______,        MO(SUP), \
  _______,_______,_______,                _______,                        _______,_______,_______,_______),

  /* Keymap _F2: Function Layer
   * ,-----------------------------------------------------------.
   * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  RESET|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |BL-|BL+|BL   |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_F2] = LAYOUT_60_ansi(
  _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,RESET,  \
  _______,_______,KC_MS_U,_______,_______,_______,_______,_______,_______,_______,_______,BL_DEC , BL_INC,BL_TOGG, \
  _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,_______,_______,_______,_______,_______,_______,        _______, \
  KC_BTN2,        _______,_______,_______,_______,RESET  ,_______,_______,_______,_______,_______,        _______, \
  _______,_______,_______,                KC_BTN1,                        _______,_______,_______,_______),

  /* Keymap _SL: Spapcebar Layer
   * ,-----------------------------------------------------------.
   * |  `|   |   |   |   |   |   |   |   |   |   |   |   |    DEL|
   * |-----------------------------------------------------------|
   * |     |PRE|PLY|FWD|   |   |   |HOM|PDN|PUP|END|   |   |     |
   * |-----------------------------------------------------------|
   * |      |VL+|MUT|VL-|   |   |<- | ↓ | ↑ | ->|   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_SL] = LAYOUT_60_ansi(
  CTL_GRV,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_DEL ,  \
  _______,KC_MRWD,KC_MPLY,KC_MFFD,_______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,_______,_______, \
  _______,KC_VOLD,KC_MUTE,KC_VOLU,_______,_______,KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,_______,_______,        _______, \
  _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______, \
  _______,_______,_______,                _______,                        _______,_______,_______,_______),


[SUP] = LAYOUT_60_ansi(
  _______, X_SUP1, X_SUP2, X_SUP3, X_SUP4, X_SUP5, X_SUP6, X_SUP7, X_SUP8, X_SUP9, X_SUP0,_______,_______,_______,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______, \
  _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______, \
  _______,_______,_______,                _______,                        _______,_______,_______,_______),
};

void matrix_init_user(void) {
    set_unicode_input_mode(UC_OSX);
};
