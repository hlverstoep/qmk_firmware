/*
Copyright 2022 Dimitris Mantzouranis <d3xter93@gmail.com>
Copyright 2022 Pablo Ramirez

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    WIN_BASE = 0,
    WIN_FN   = 1,
    MAC_BASE = 2,
    MAC_FN   = 3,
};
#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer

#define KC_MSSN LGUI(KC_F3)         // Mission Control
#define KC_FIND LALT(LGUI(KC_SPC))  // Finder
#define KC_MSCR LSFT(LGUI(KC_3))    // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
    *****************************************************************************************************************
    * ESC  * F1   * F2   * F3   * F4   * F5   * F6   * F7   * F8   * F9   * F10  * F11  * F12  * PSCR * DEL  * RMOD *
    *****************************************************************************************************************
    * ~    * 1    * 2    * 3    * 4    * 5    * 6    * 7    * 8    * 9    * 0    * *    * =    * BSPC        * PGUP *
    *****************************************************************************************************************
    * TAB     * Q    * W    * E    * R    * T    * Y    * U    * I    * O    * P    * [    * ]    * \        * PGDN *
    *****************************************************************************************************************
    * CAPS      * A    * S    * D    * F    * G    * H    * J    * K    * L    * ;    * '    * ENT           * HOME *
    *****************************************************************************************************************
    * LSFT         * Z    * X    * C    * V    * B    * N    * M    * ,    * .    * /    * RSFT       * UP   * END  *
    *****************************************************************************************************************
    * LCTL  * LGUI  * LALT  * SPC                                         * RALT * FN   * RCTL * LEFT * DOWN * RGHT *
    *****************************************************************************************************************
  */
  [WIN_BASE] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_DEL,     BL_TOGG  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,                 KC_HOME  ,
      KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LGUI,    KC_LALT,                                        KC_SPC,                                         KC_RALT,    MO(WIN_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  /*
    *****************************************************************************************************************
    *RESET * BRID * BRIU * TASK * FLXP * RVAD * RVAI * MPRV * MPLY * MNXT * MUTE * VOLD * VOLU *      *  INS * RTOG *
    *****************************************************************************************************************
    *      *      *      *      *      *      *      *      *      *      *      *      *      *             *      *
    *****************************************************************************************************************
    *         *      *      *      *      *      *      *      *      *      *      *      *      *          *      *
    *****************************************************************************************************************
    *           *      *      *      *      *      *      *      *      *      *      *      *               *      *
    *****************************************************************************************************************
    *              *      *      *      *      *      *      *      *      *      *      *            * RSAI *      *
    *****************************************************************************************************************
    *       *       *       *                                             *      *      *      * RHUD * RSAD * RHUI *
    *****************************************************************************************************************
  */
  [WIN_FN] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      RESET,      KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    BL_DEC,     BL_INC,     KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    KC_INS,     BL_STEP  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    _______,    _______,    _______
  ),

   /*
    *****************************************************************************************************************
    * ESC  * F1   * F2   * F3   * F4   * F5   * F6   * F7   * F8   * F9   * F10  * F11  * F12  * PSCR * DEL  * RMOD *
    *****************************************************************************************************************
    * ~    * 1    * 2    * 3    * 4    * 5    * 6    * 7    * 8    * 9    * 0    * *    * =    * BSPC        * PGUP *
    *****************************************************************************************************************
    * TAB     * Q    * W    * E    * R    * T    * Y    * U    * I    * O    * P    * [    * ]    * \        * PGDN *
    *****************************************************************************************************************
    * CAPS      * A    * S    * D    * F    * G    * H    * J    * K    * L    * ;    * '    * ENT           * HOME *
    *****************************************************************************************************************
    * LSFT         * Z    * X    * C    * V    * B    * N    * M    * ,    * .    * /    * RSFT       * UP   * END  *
    *****************************************************************************************************************
    * LCTL  * LGUI  * LALT  * SPC                                         * RALT * FN   * RCTL * LEFT * DOWN * RGHT *
    *****************************************************************************************************************
  */
  [MAC_BASE] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_DEL,     BL_TOGG  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      XXXXXXX,    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),     KC_G,       KC_H,       RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN),  KC_QUOT,                KC_ENT,                 KC_HOME  ,
      XXXXXXX,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                XXXXXXX,    KC_UP,      KC_END   ,
      XXXXXXX,    XXXXXXX,    XXXXXXX,                                        KC_SPC,                                         KC_N,       MO(WIN_FN), XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  /*
    *****************************************************************************************************************
    *RESET * BRID * BRIU * TASK * FLXP * RVAD * RVAI * MPRV * MPLY * MNXT * MUTE * VOLD * VOLU *      *  INS * RTOG *
    *****************************************************************************************************************
    *      *      *      *      *      *      *      *      *      *      *      *      *      *             *      *
    *****************************************************************************************************************
    *         *      *      *      *      *      *      *      *      *      *      *      *      *          *      *
    *****************************************************************************************************************
    *           *      *      *      *      *      *      *      *      *      *      *      *               *      *
    *****************************************************************************************************************
    *              *      *      *      *      *      *      *      *      *      *      *            * RSAI *      *
    *****************************************************************************************************************
    *       *       *       *                                             *      *      *      * RHUD * RSAD * RHUI *
    *****************************************************************************************************************
  */
  [MAC_FN] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      RESET,      KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    BL_DEC,     BL_INC,     KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    KC_INS,     BL_STEP  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_END,     KC_PGUP,    KC_PGDN,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_RGHT,    KC_UP,      KC_DOWN,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    _______,    _______,    _______
  )
};

enum combo_events {
  COMBO_CAPS,
  COMBO_NAV,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_caps[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo_nav[] = {KC_D, KC_K, COMBO_END};
combo_t key_combos[] = {
    [COMBO_CAPS] = COMBO(combo_caps, KC_CAPS),
    [COMBO_NAV] = COMBO(combo_nav, TG(MAC_FN)),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return
        (combo_index == COMBO_CAPS && layer_state_is(MAC_BASE)) ||
        combo_index == COMBO_NAV;
}

bool dip_switch_update_user(uint8_t index, bool active) {
  switch(index) {
    case 0: // OS switch
      if (active) { // Mac/iOS mode
        layer_move(MAC_BASE);
        combo_enable();
      }
      else { // Windows/Android mode
        layer_move(WIN_BASE);
        combo_disable();
      }
      break;
    case 1: // Connection switch
      // Probably it's not possible to do anything sensible here as switching from Cable to BT requires turning off the board. (BT / OFF / Cable)
      if (active) { // BT mode
        // do stuff
      }
      else { //Cable mode
        // do stuff
      }
      break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable = true;
  // debug_matrix = true;
  // debug_keyboard = true;
  // debug_mouse = true;
}