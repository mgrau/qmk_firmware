#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,   // base layer
    FUN,        // function layer
    GAME,       // gaming layer
    GIT,        // git macro layer
    CAD,        // cadet unicode layer
    FNT,        // front cadet layer
    UP,         // shifted front cadet layer
    FUT,        // futhark layer
    RAISE,
    LOWER,
    ADJ,        // rasie + lower
};



#define _______ KC_TRNS
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_GRV LCTL(KC_GRV)
#define GIT_GRV LT(GIT, KC_GRV)
#define DEL_CTL MT(MOD_LCTL, KC_DEL)
#define SPACE_MOD LT(SPACE, KC_SPC)
#define LOW_MOD LT(LOWER, KC_SPC)
#define RAS_MOD LT(RAISE, KC_SPC)
#define FNT_TAB LT(FNT, KC_TAB)
#define FNT_ENT LT(FNT, KC_ENT)

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

	[BASE] = MGLAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,\
    FNT_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         \
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          FNT_ENT,         \
    KC_LSPO,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC,         \
    DEL_CTL, KC_LGUI, KC_LALT,          LOW_MOD,          KC_SPC,           RAS_MOD,          MO(FUN), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
    ),
	[RAISE] = MGLAYOUT(
    KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,          KC_DEL, \
    _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______, _______, _______,         \
    _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,         \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         \
    _______, _______, _______,          _______,          _______,          _______,          _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
    ),
	[LOWER] = MGLAYOUT(
    KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,          KC_DEL, \
    _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______, _______, _______,         \
    _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,         \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         \
    _______, _______, _______,          _______,          _______,          _______,          _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
    ),
	[ADJUST] = MGLAYOUT(
    _______, KC_A   , _______, _______, _______, _______, _______, _______, _______, _______, _______,RGB_RMOD, RGB_MOD,          RGB_TOG,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         \
    _______,          _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______,          _______,         \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______ \
    ),
    [FUN] = MGLAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,          _______,\
    _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, UT_AUTO, UT_AGCR, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,         \
    _______, _______, _______, _______, _______, TG(GAME),_______, _______, _______, _______, _______, _______,          _______,         \
    _______,          _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______,          _______,         \
    UC_M_LN, UC_M_WC, UC_M_OS,          _______,          _______,          _______,          _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END \
    ),
    [GAME] = MGLAYOUT(
    KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,RGB_RMOD, RGB_MOD,          RGB_TOG,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         \
    _______,          _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______,          _______,         \
    _______, _______, _______,          KC_SPC,           _______,          KC_SPC,           _______, _______, _______, _______, _______ \
    ),
    [CAD] = MGLAYOUT(
    X(IBNG), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        , _______, \
    _______, X(AND),  X(OR),   X(INSC), X(UNI),  X(SUB),  X(SUP),  X(FALL), X(INF),  X(EXIS), X(PART), _______, _______, _______,        , \
    _______, X(UPTK), X(DNTK), X(RTTK), X(LTTK), X(LRAR), X(LARR), X(DARR), X(UARR), X(RARR), _______, _______,          _______,        , \
    _______,          X(LDO),  X(LUP),  X(NOTE), X(ASYM), X(EQIV), X(LEQ),  X(GEQ),  _______, _______, _______,          _______,        , \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
    ),
    [FNT] = MGLAYOUT(
    _______, X(F_1),  X(F_2),  X(F_3),  X(F_4),  X(F_5),  X(F_6),  X(F_7),  X(F_8),  X(F_9),  X(F_0),  X(F_11), X(F_12),        , _______, \
    _______, X(F_q),  X(F_w),  X(F_e),  X(F_r),  X(F_t),  X(F_y),  X(F_u),  X(F_i),  X(F_o),  X(F_p),  _______, _______, _______,        , \
    _______, X(F_a),  X(F_s),  X(F_d),  X(F_f),  X(F_g),  X(F_h),  X(F_j),  X(F_k),  X(F_l),  _______, _______,          _______,        , \
    MO(UP),           X(F_z),  X(F_x),  X(F_c),  X(F_v),  X(F_b),  X(F_n),  X(F_m),  X(F_ll), X(F_gg), X(Fint),          MO(UP),         , \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
    ),
    [UP] = MGLAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        , _______, \
    _______, X(F_Q),  X(F_W),  X(F_E),  X(F_R),  X(F_T),  X(F_Y),  X(F_U),  X(F_I),  X(F_O),  X(F_P),  _______, _______, _______,        , \
    _______, X(F_A),  X(F_S),  X(F_D),  X(F_F),  X(F_G),  X(F_H),  X(F_J),  X(F_K),  X(F_L),  _______, _______,          _______,        , \
    _______, X(F_Z),  X(F_X),  X(F_C),  X(F_V),  X(F_B),  X(F_N),  X(F_M),  _______, _______, _______, _______,          _______,        , \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
    ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  // rgblight_disable();
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
