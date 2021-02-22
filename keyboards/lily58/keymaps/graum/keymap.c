#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#include "cadet_unicode.c"
#include "logo.c"
#include "pet.c"

extern uint8_t is_master;

enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GREEK,
  _GAME
};

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define DEL_SFT MT(MOD_LSFT, KC_DEL)
#define SPC_LOW LT(_RAISE, KC_SPC)
#define ENT_UP LT(_LOWER, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | `    |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | LGUI | GREEK|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_BASE] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  CTL_ESC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  DEL_SFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,\
                       KC_LALT, KC_LGUI, MO(_LOWER),    SPC_LOW, ENT_UP,  MO(_RAISE), KC_LGUI, MO(_GREEK) \
),
 /* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    | Home | PGDN | PGUP | End  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------| Left | Down |  Up  |Right |Right |      |
 * |------+------+------+------+------+------|   (   |    |   )   |------+------+------+------+------+------|
 * |      |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_MINS, KC_EQL,  _______, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LPRN, KC_RPRN, KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,  \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Prev | Play | Next |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |VolDwn| Mute | VolUp|      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,                   KC_BTN1, KC_BTN2, _______, _______, _______, _______, \
  _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______,  \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_GAME),                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),
 [_GREEK] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, GK_Q,    GK_W,    GK_E,    GK_R,    GK_T,                      GK_Y,    GK_U,    GK_I,    GK_O,    GK_P,    _______, \
  _______, GK_A,    GK_S,    GK_D,    GK_F,    GK_G,                      GK_H,    GK_J,    GK_K,    GK_L,    _______, _______, \
  _______, GK_Z,    GK_X,    GK_C,    GK_V,    GK_B,    _______, _______, GK_N,    GK_M,    _______, _______, _______, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),
 [_GAME] = LAYOUT( \
  KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  KC_TAB,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  KC_LCTL, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                             KC_LALT, KC_LGUI, KC_ESC,  KC_SPC,  KC_ENT,  _______, KC_RGUI, TO(_BASE) \
)
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  // if (!is_keyboard_master())
  //   return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  // return rotation;
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// status variables
int current_wpm = 0;
bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;

static void print_status_narrow(void) {
    // If you want to change the display of OLED, you need to change here
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_timelog(), false);

    // Print current mode
    oled_set_cursor(0,0);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
    }


    // // Print current layer
    oled_set_cursor(0,5);
    oled_write("Layer", false);

    oled_set_cursor(0,6);
    char layer_state_str[8];
    switch (get_highest_layer(layer_state))
    {
    case _BASE:
     snprintf(layer_state_str, sizeof(layer_state_str), "Base");
      break;
    case _RAISE:
     snprintf(layer_state_str, sizeof(layer_state_str), "Raise");
      break;
    case _LOWER:
     snprintf(layer_state_str, sizeof(layer_state_str), "Lower");
      break;
    case _ADJUST:
     snprintf(layer_state_str, sizeof(layer_state_str), "Adj");
      break;
    case _GREEK:
     snprintf(layer_state_str, sizeof(layer_state_str), "Greek");
     break;
    case _GAME:
     snprintf(layer_state_str, sizeof(layer_state_str), "Game");
      break;
    default:
     snprintf(layer_state_str, sizeof(layer_state_str), "Und-%ld", layer_state);
    }
    oled_write_ln(layer_state_str, false);

    // KEYBOARD PET RENDER START
    render_luna(0,13,current_wpm,isSneaking,isJumping,showedJump);
    // KEYBOARD PET RENDER END
}

static void print_logo_narrow(void) {
    oled_set_cursor(0,0);
    oled_write_raw_P(hell_logo, sizeof(hell_logo));
    // render_logo();

    oled_set_cursor(0,7);
    oled_write_ln(read_keylogs(), false);
    // oled_write_ln("Test", false);

    // wpm counter
    char wpm_str[8];
    oled_set_cursor(0,14);
    sprintf(wpm_str, " %03d", current_wpm);
    oled_write(wpm_str, false);

    oled_set_cursor(0,15);
    oled_write(" wpm", false);
}

void oled_task_user(void) {
  current_wpm = get_current_wpm();

  if (is_keyboard_master()) {
    print_status_narrow();
  } else {
    print_logo_narrow();
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  switch (keycode) {
        // KEYBOARD PET STATUS START
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
                showedJump = true;
            }
            break;
        // KEYBOARD PET STATUS END
  }
  return true;
}