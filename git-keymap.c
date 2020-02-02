#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL,
  GIT_SETUP,
  GIT_TAG,
  GIT_PUSH,
  GIT_REBASE,
  GIT_PULL,
  GIT_MERGE,
  GIT_BRANCH,
  GIT_FETCH,
  GIT_STATUS,
  GIT_CHECKOUT,
  GIT_COMMIT,
  GIT_REVERT,
  GIT_ADD,
  GIT_LOG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, \
        KC_PSCR, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_APP, \
        KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, MO(1), \
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_HOME, KC_END, KC_LEFT, KC_DOWN, KC_RGHT),
	[1] = LAYOUT(GIT_SETUP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, GIT_REVERT, GIT_REVERT, GIT_LOG, \
        GIT_TAG, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_M_P, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_MRWD, \
        GIT_PUSH, RGB_VAD, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, GIT_COMMIT, GIT_ADD, \
        GIT_REBASE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, GIT_CHECKOUT, KC_VOLU, KC_MSTP, \
        GIT_PULL, GIT_MERGE, GIT_BRANCH, KC_TRNS, KC_TRNS, KC_TRNS, GIT_FETCH, GIT_STATUS, KC_HOME, KC_VOLD, KC_END)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case GIT_SETUP: SEND_STRING("git config --global color.ui auto; git config --global user.name \"name\";git config --global user.email \"ltran at long-tran.com\";"); break;
            case GIT_TAG: SEND_STRING("git tag CoolTag"); break;
            case GIT_PUSH: SEND_STRING("git push"); break;
            case GIT_REBASE: SEND_STRING("git rebase CoolBranch"); break;
            case GIT_PULL: SEND_STRING("git pull"); break;
            case GIT_MERGE: SEND_STRING("git merge"); break;
            case GIT_BRANCH: SEND_STRING("git branch CoolBranch"); break;
            case GIT_FETCH: SEND_STRING("git fetch"); break;
            case GIT_STATUS: SEND_STRING("git status"); break;
            case GIT_CHECKOUT: SEND_STRING("git checkout CoolBranch"); break;
            case GIT_COMMIT: SEND_STRING("git commit -m \"Cool\""); break;
            case GIT_REVERT: SEND_STRING("git revert CommitID"); break;
            case GIT_ADD: SEND_STRING("git add CoolFile"); break;
            case GIT_LOG: SEND_STRING("git log --follow CoolFile"); break;
        }
    }
    return true;
}
