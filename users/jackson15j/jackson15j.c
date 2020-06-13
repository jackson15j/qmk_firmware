#include "jackson15j.h"

// Colemak combos.
enum combos {
    QW_ESC,
    FP_QUOTE,
    LU_HYPHEN,
    YSC_BKSPC,
    ZX_DEL,
    CD_TAB,
    HCOM_UNDSCR,
    FSSLSH_ENTER
};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM ysc_combo[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM hcom_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM fsslsh_combo[] = {KC_DOT, KC_SLASH, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    [QW_ESC] = COMBO(qw_combo, KC_ESC),
    [FP_QUOTE] = COMBO(fp_combo, KC_DBLQT),
    [LU_HYPHEN] = COMBO(lu_combo, KC_QUOT),
    [YSC_BKSPC] = COMBO(ysc_combo, KC_BSPC),
    [ZX_DEL] = COMBO(zx_combo, KC_DEL),
    [CD_TAB] = COMBO(cd_combo, KC_TAB),
    [HCOM_UNDSCR] = COMBO(hcom_combo, KC_UNDSCR),
    [FSSLSH_ENTER] = COMBO(fsslsh_combo, KC_ENT)
};
