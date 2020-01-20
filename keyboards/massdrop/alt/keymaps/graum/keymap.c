#include QMK_KEYBOARD_H
#include "rgb_matrix_user.h"
#include "cadet_unicode.c"

enum alt_keycodes {
    //USB Extra Port Toggle Auto Detect / Always Active
    UT_AUTO = SAFE_RANGE,
    UT_AGCR,    //USB Toggle Automatic GCR control
    DBG_TOG,    //DEBUG Toggle On / Off
    DBG_MTRX,   //DEBUG Toggle Matrix Prints
    DBG_KBD,    //DEBUG Toggle Keyboard Prints
    DBG_MOU,    //DEBUG Toggle Mouse Prints
    MD_BOOT,    //Restart into bootloader after hold timeout
    // GIT MACROS
    GIT_REV,
    GIT_TAG,
    GIT_BRA,
    GIT_PUL,
    GIT_MER,
    GIT_REB,
    GIT_COM,
    GIT_CHE,
    GIT_CLO,
    GIT_FET,
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

enum layers {
    BASE = 0,   // base layer
    FUN,        // function layer
    SPACE,      // space bar layer
    GAME,       // gaming layer
    GIT,        // git macro layer
    CAD,        // cadet unicode layer
};

#define _______ KC_TRNS
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_GRV LCTL(KC_GRV)
#define GIT_GRV LT(GIT, KC_GRV)
#define DEL_CTL MT(MOD_LCTL, KC_DEL)

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        GIT_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,  \
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,          KC_UP,   KC_PGDN, \
        DEL_CTL, KC_LGUI, KC_LALT,                            LT(SPACE, KC_SPC),                  MO(CAD), MO(FUN), KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [SPACE] = LAYOUT(
        CTL_GRV, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL , _______, \
        _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______, _______, _______, _______, \
        _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, _______, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    [FUN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, UT_AUTO, UT_AGCR, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END,  \
        _______, _______, _______, _______, _______, TG(GAME),_______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, _______, _______, _______, _______, MD_BOOT, TG_NKRO, _______, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        UC_M_LN, UC_M_WC, UC_M_OS,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    [GAME] = LAYOUT(
        KC_ESC , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            KC_SPC,                             _______, _______, _______, _______, _______  \
    ),
    [GIT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, GIT_REV, _______, \
        GIT_TAG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          GIT_COM, _______, \
        GIT_REB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, GIT_CHE,          _______, _______, \
        GIT_BRA, GIT_PUL, GIT_MER,                            _______,                            GIT_CLO, GIT_FET, _______, _______, _______  \
    ),
    [CAD] = LAYOUT(
        X(IBNG), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, X(AND),  X(OR),   X(INSC), X(UNI),  X(SUB),  X(SUP),  X(FALL), X(INF),  X(EXIS), X(PART), _______, _______, _______, _______, \
        _______, X(UPTK), X(DNTK), X(RTTK), X(LTTK), X(LRAR), X(LARR), X(DARR), X(UARR), X(RARR), _______, _______,          _______, _______, \
        _______, X(LDO),  X(LUP),  X(NOTE), X(ASYM), X(EQIV), X(LEQ),  X(GEQ),  _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case UT_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case UT_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case GIT_REV:
            if (record->event.pressed) {
                SEND_STRING("git revert");
            }
            return false;
        case GIT_TAG:
            if (record->event.pressed) {
                SEND_STRING("git tag");
            }
            return false;
        case GIT_BRA:
            if (record->event.pressed) {
                SEND_STRING("git branch");
            }
            return false;
        case GIT_PUL:
            if (record->event.pressed) {
                SEND_STRING("git pull");
            }
            return false;
        case GIT_MER:
            if (record->event.pressed) {
                SEND_STRING("git merge");
            }
            return false;
        case GIT_REB:
            if (record->event.pressed) {
                SEND_STRING("git rebase");
            }
            return false;
        case GIT_COM:
            if (record->event.pressed) {
                SEND_STRING("git commit");
            }
            return false;
        case GIT_CHE:
            if (record->event.pressed) {
                SEND_STRING("git checkout");
            }
            return false;
        case GIT_CLO:
            if (record->event.pressed) {
                SEND_STRING("git clone");
            }
            return false;
        case GIT_FET:
            if (record->event.pressed) {
                SEND_STRING("git fetch");
            }
            return false;
        // case RGB_TOG:
        //     if (record->event.pressed) {
        //       switch (rgb_matrix_get_flags()) {
        //         case LED_FLAG_ALL: {
        //             rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
        //             rgb_matrix_set_color_all(0, 0, 0);
        //           }
        //           break;
        //         case LED_FLAG_KEYLIGHT: {
        //             rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
        //             rgb_matrix_set_color_all(0, 0, 0);
        //           }
        //           break;
        //         case LED_FLAG_UNDERGLOW: {
        //             rgb_matrix_set_flags(LED_FLAG_NONE);
        //             rgb_matrix_disable_noeeprom();
        //           }
        //           break;
        //         default: {
        //             rgb_matrix_set_flags(LED_FLAG_ALL);
        //             rgb_matrix_enable_noeeprom();
        //           }
        //           break;
        //       }
        //     }
        //     return false;
        default:
            return true; //Process all other keycodes normally
    }
}
