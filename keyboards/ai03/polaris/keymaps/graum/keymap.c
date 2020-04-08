/* Copyright 2019 Ryota Goto
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

#include "cadet_unicode.c"

enum layer {
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

enum git_keycodes {
    // GIT MACROS
    GIT_REV = SAFE_RANGE,
    GIT_TAG,
    GIT_BRA,
    GIT_PUL,
    GIT_MER,
    GIT_REB,
    GIT_COM,
    GIT_CHE,
    GIT_CLO,
    GIT_FET,
    GIT_STA,
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
#define RGT_CTL MT(MOD_RCTL, KC_RGHT)
#define LFT_CAD LT(CAD, KC_LEFT)

#define MGLAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K013, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K113, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,             K213, \
	K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K312, \
	K400, K401, K402,                   K406,                         K411, K412, K413  \
) \
{ \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  KC_NO, K213 }, \
	{ K300,  KC_NO, K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  KC_NO}, \
	{ K400,  K401,  K402,  KC_NO, KC_NO, KC_NO, K406,  KC_NO, KC_NO, KC_NO, KC_NO, K411,  K412,  K413 }  \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  	[BASE] = MGLAYOUT(
    GIT_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    FNT_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          FNT_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    DEL_CTL, KC_LGUI, KC_LALT,                            RAS_MOD,                                     LFT_CAD, MO(FUN), RGT_CTL
    ),
    [RAISE] = MGLAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,
    _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______,
    _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______,                            _______,                                     KC_HOME, _______, KC_END
    ),
	[LOWER] = MGLAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,
    _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______,
    _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______,                            _______,                                     _______, _______, _______
    ),
    [FUN] = MGLAYOUT(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,
    _______, _______, _______, _______, _______, TG(GAME),_______, _______, _______, _______, _______, _______,          _______,
    _______,          _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______,          _______,
    UC_M_LN, UC_M_WC, UC_M_OS,                            _______,                                     _______, _______, _______
    ),
    [GAME] = MGLAYOUT(
    KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_ENT,
    KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_RSFT,
    KC_ESC,  _______, KC_LALT,                            KC_SPC,                                      KC_RALT, _______, KC_RCTL
    ),
    [GIT] = MGLAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, GIT_REV,
    GIT_TAG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          GIT_COM,
    GIT_REB,          _______, _______, _______, _______, _______, _______, _______, _______, _______, GIT_CHE,          _______,
    GIT_BRA, GIT_PUL, GIT_MER,                            _______,                                     GIT_CLO, GIT_FET, GIT_STA
    ),
    [CAD] = MGLAYOUT(
    X(IBNG), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, X(AND),  X(OR),   X(INSC), X(UNI),  X(SUB),  X(SUP),  X(FALL), X(INF),  X(EXIS), X(PART), _______, _______, _______,
    _______, X(UPTK), X(DNTK), X(RTTK), X(LTTK), X(LRAR), X(LARR), X(DARR), X(UARR), X(RARR), _______, _______,          _______,
    _______,          X(LDO),  X(LUP),  X(NOTE), X(ASYM), X(EQIV), X(LEQ),  X(GEQ),  _______, _______, _______,          _______,
    _______, _______, _______,                            _______,                                     _______, _______, _______
    ),
    [FNT] = MGLAYOUT(
    _______, X(F_1),  X(F_2),  X(F_3),  X(F_4),  X(F_5),  X(F_6),  X(F_7),  X(F_8),  X(F_9),  X(F_0),  X(F_11), X(F_12), _______,
    _______, X(F_q),  X(F_w),  X(F_e),  X(F_r),  X(F_t),  X(F_y),  X(F_u),  X(F_i),  X(F_o),  X(F_p),  _______, _______, _______,
    _______, X(F_a),  X(F_s),  X(F_d),  X(F_f),  X(F_g),  X(F_h),  X(F_j),  X(F_k),  X(F_l),  _______, _______,          _______,
    MO(UP),           X(F_z),  X(F_x),  X(F_c),  X(F_v),  X(F_b),  X(F_n),  X(F_m),  X(F_ll), X(F_gg), X(Fint),          MO(UP),
    _______, _______, _______,                            _______,                                     _______, _______, _______
    ),
    [UP] = MGLAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, X(F_Q),  X(F_W),  X(F_E),  X(F_R),  X(F_T),  X(F_Y),  X(F_U),  X(F_I),  X(F_O),  X(F_P),  _______, _______, _______,
    _______, X(F_A),  X(F_S),  X(F_D),  X(F_F),  X(F_G),  X(F_H),  X(F_J),  X(F_K),  X(F_L),  _______, _______,          _______,
    _______,          X(F_Z),  X(F_X),  X(F_C),  X(F_V),  X(F_B),  X(F_N),  X(F_M),  _______, _______, _______,          _______,
    _______, _______, _______,                            _______,                                     _______, _______, _______
    ),
    /*
    [X] = MGLAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______,                            _______,                                     _______, _______, _______
    ),
    */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GIT_REV:
            if (record->event.pressed) {
                SEND_STRING("git revert");
            }
            break;
        case GIT_TAG:
            if (record->event.pressed) {
                SEND_STRING("git tag");
            }
            break;
        case GIT_BRA:
            if (record->event.pressed) {
                SEND_STRING("git branch");
            }
            break;
        case GIT_PUL:
            if (record->event.pressed) {
                SEND_STRING("git pull");
            }
            break;
        case GIT_MER:
            if (record->event.pressed) {
                SEND_STRING("git merge");
            }
            break;
        case GIT_REB:
            if (record->event.pressed) {
                SEND_STRING("git rebase");
            }
            break;
        case GIT_COM:
            if (record->event.pressed) {
                SEND_STRING("git commit");
            }
            break;
        case GIT_CHE:
            if (record->event.pressed) {
                SEND_STRING("git checkout");
            }
            break;
        case GIT_CLO:
            if (record->event.pressed) {
                SEND_STRING("git clone");
            }
            break;
        case GIT_FET:
            if (record->event.pressed) {
                SEND_STRING("git fetch");
            }
            break;
        case GIT_STA:
            if (record->event.pressed) {
                SEND_STRING("git stash");
            }
            break;
    }
    return true; //Process all other keycodes normally
}
