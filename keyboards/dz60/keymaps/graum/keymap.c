#include QMK_KEYBOARD_H

// Give each layer a name
#define _BASE   0 // base layer
#define _FL     1 // function layer
#define _SL     2 // space bar layer
#define _GL     3 // gaming layer

#define _______ KC_TRNS
#define CTL_ESC MT(MOD_LCTL, KC_ESC)

#define MGLAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,      k0e, \
    k10,      k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, \
    k20,      k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d,      \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,      k3d,      \
    k40, k41,      k43, k44,      k46,      k48,      k4a, k4b, k4c, k4d, k4e  \
) { \
    { k00,  k01,   k02,   k03,  k04,  k05,   k06,  k07,   k08,  k09,   k0a,  k0b,  k0c,  KC_NO,k0e   }, \
    { k10,  KC_NO, k12,   k13,  k14,  k15,   k16,  k17,   k18,  k19,   k1a,  k1b,  k1c,  k1d,  k1e   }, \
    { k20,  KC_NO, k22,   k23,  k24,  k25,   k26,  k27,   k28,  k29,   k2a,  k2b,  k2c,  k2d,  KC_NO }, \
    { k30,  KC_NO, k32,   k33,  k34,  k35,   k36,  k37,   k38,  k39,   k3a,  k3b,  KC_NO,k3d,  KC_NO }, \
    { k40,  k41,   KC_NO, k43,  k44,  KC_NO, k46,  KC_NO, k48,  KC_NO, k4a,  k4b,  k4c,  k4d,  k4e   }  \
}

/* MGLAYOUT
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │0e │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │
 * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────┤
 * │30     │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │    3d     │
 * ├────┬──┴─┬─┴──┬┴───┴───┼───┴┬──┴───┴───┼───┼───┼───┬───┬───┤
 * │40  │41  │43  │44      │46  │48        │4a │4b │4c │4d │4e │
 * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = MGLAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         \
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          \
    KC_LSPO,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC,         \
    KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           LT(_SL, KC_SPC),  MO(_FL), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),
	[_SL] = MGLAYOUT(
    KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,          KC_DEL, \
    _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______, _______, _______,         \
    _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,         \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______ \
),
	[_FL] = MGLAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         \
    _______,          _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______,          _______,         \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______ \
),
};


