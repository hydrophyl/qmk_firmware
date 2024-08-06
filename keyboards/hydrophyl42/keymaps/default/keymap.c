#include QMK_KEYBOARD_H

#define KC_ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,   KC_Q,    KC_W,     KC_E,    KC_R,   KC_T,                        KC_Y,    KC_U,    KC_I,   KC_O,    KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ENT,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                         KC_H,    KC_J,    KC_K,   KC_L,   KC_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                         KC_N,    KC_M,   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_SPC, KC_LALT,     KC_LGUI, KC_SPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),
    
  [1] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,  KC_1,    KC_2,    KC_3,  KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,  KC_4,    KC_5,    KC_6,  KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,  KC_7,    KC_8,    KC_9,  KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TO(0),  KC_TRNS, KC_TRNS,    KC_TRNS,   KC_0,  KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
    
  [2] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,  KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,  KC_F9,   KC_F10, KC_F11,  KC_F12, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TO(0),  KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )
};


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

enum combos { 
    //Number layer
    NUM_LAYER,
    
    //Function layer
    FUNC_LAYER,
    
    //Common symbols
    NORM_DOT,
    NORM_COMM,
    NORM_COLN,
    NORM_SCLN,
    NORM_QUOT,
    NORM_DQUO,
    //Number layer
    numDOT,
    numCOMM,
    numCOLN,
    numSCLN,
    numQUOT,
    numDQUO,
    
    //Basic math symbols
    NORM_EQL,
    NORM_MINS,
    NORM_PLUS,
    NORM_UNDS,
    //Number layer
    NUM_EQL,
    NUM_MINS,
    NUM_PLUS,
    NUM_UNDS,
    
    //Parentheses
    NORM_LBRC,
    NORM_RBRC,
    NORM_LPRN,
    NORM_RPRN,
    NORM_LCBR,
    NORM_RCBR,
    //Number layer
    NUM_LBRC,
    NUM_RBRC,
    NUM_LPRN,
    NUM_RPRN,
    NUM_LCBR,
    NUM_RCBR,
    
    //Symbols
    NORM_SLSH,
    NORM_BSLS,
    NORM_PIPE,
    NORM_CIRC,
    NORM_LT,
    NORM_GT,
    NORM_GRV,
    NORM_TILD,
    NORM_HASH,
    NORM_PERC,
    NORM_EXLM,
    NORM_QUES,
    NORM_DLR,
    NORM_AT,
    NORM_AMPR,
    NORM_ASTR,
    //Symbols on NUMber layer
    NUMSLSH,
    NUMBSLS,
    NUMPIPE,
    NUMCIRC,
    NUMLT,
    NUMGT,
    NUMGRV,
    NUMTILD,
    NUMHASH,
    NUMPERC,
    NUMEXLM,
    NUMQUES,
    NUMDLR,
    NUMAT,
    NUMAMPR,
    NUMASTR,
    
    //Control keys
    NORM_ENT,
    NUM_ENT,
    NORM_TAB,
    NORM_CAPS,

    //Navigation keys
    NORM_HOME,
    NORM_END,
    NORM_PGUP,
    NORM_PGDN,
    NORM_INS,
    
    //Additional media keys
    NORM_VOLU,
    NORM_VOLD,
    NORM_MPRV,
    NORM_MNXT,
    NORM_MUTE,
    
    //Misc 
    ASDF_LOREM,
    COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;
    //Number layer
    const uint16_t PROGMEM num_layer[] = { KC_B, KC_SPC, COMBO_END};

    //Function layer
    const uint16_t PROGMEM func_layer[] = { KC_Q, KC_W, COMBO_END};

    //Common symbols
    const uint16_t PROGMEM norm_dot[] = { KC_LALT, KC_M, COMBO_END};
    const uint16_t PROGMEM norm_comm[] = { KC_LALT, KC_LEFT, COMBO_END};
    const uint16_t PROGMEM norm_coln[] = { KC_O, KC_L, COMBO_END};
    const uint16_t PROGMEM norm_scln[] = { KC_P, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM norm_quot[] = { KC_U, KC_J, COMBO_END};
    const uint16_t PROGMEM norm_dquo[] = { KC_I, KC_K, COMBO_END};
    //Number layer
    const uint16_t PROGMEM numdot[] = { KC_LALT, KC_7, COMBO_END};
    const uint16_t PROGMEM numcomm[] = { KC_LALT, KC_8, COMBO_END};
    const uint16_t PROGMEM numcoln[] = { KC_3, KC_6, COMBO_END};
    const uint16_t PROGMEM numscln[] = { KC_P, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM numquot[] = { KC_1, KC_4, COMBO_END} ;
    const uint16_t PROGMEM numdquo[] = { KC_2, KC_5, COMBO_END};

    //Basic math symbols
    const uint16_t PROGMEM norm_eql[] = { KC_Y, KC_U, COMBO_END};
    const uint16_t PROGMEM norm_mins[] = { KC_H, KC_J, COMBO_END};
    const uint16_t PROGMEM norm_plus[] = { KC_H, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM norm_unds[] = { KC_N, KC_M, COMBO_END};
    //Number layer
    const uint16_t PROGMEM num_eql[] = { KC_Y, KC_1, COMBO_END};
    const uint16_t PROGMEM num_mins[] = { KC_H, KC_4, COMBO_END};
    const uint16_t PROGMEM num_plus[] = { KC_H, KC_4, KC_5, COMBO_END};
    const uint16_t PROGMEM num_unds[] = { KC_N, KC_7, COMBO_END};

    //Parentheses
    const uint16_t PROGMEM norm_lbrc[] = { KC_LGUI, KC_U, COMBO_END};
    const uint16_t PROGMEM norm_rbrc[] = { KC_LGUI, KC_I, COMBO_END};
    const uint16_t PROGMEM norm_lprn[] = { KC_LGUI, KC_J, COMBO_END};
    const uint16_t PROGMEM norm_rprn[] = { KC_LGUI, KC_K, COMBO_END};
    const uint16_t PROGMEM norm_lcbr[] = { KC_LGUI, KC_M, COMBO_END};
    const uint16_t PROGMEM norm_rcbr[] = { KC_LGUI, KC_LEFT, COMBO_END};
    //Number layer 
    const uint16_t PROGMEM num_lbrc[] = { KC_LGUI, KC_1, COMBO_END};
    const uint16_t PROGMEM num_rbrc[] = { KC_LGUI, KC_2, COMBO_END};
    const uint16_t PROGMEM num_lprn[] = { KC_LGUI, KC_4, COMBO_END};
    const uint16_t PROGMEM num_rprn[] = { KC_LGUI, KC_5, COMBO_END};
    const uint16_t PROGMEM num_lcbr[] = { KC_LGUI, KC_7, COMBO_END};
    const uint16_t PROGMEM num_rcbr[] = { KC_LGUI, KC_8, COMBO_END};

    //Symbols
    const uint16_t PROGMEM norm_slsh[] = { KC_M, KC_K, KC_O, COMBO_END};
    const uint16_t PROGMEM norm_bsls[] = { KC_U, KC_K, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM norm_pipe[] = { KC_O, KC_L, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM norm_circ[] = { KC_J, KC_I, KC_L, COMBO_END};
    const uint16_t PROGMEM norm_lt[] = { KC_I, KC_J, KC_LEFT, COMBO_END};
    const uint16_t PROGMEM norm_gt[] = { KC_I, KC_L, KC_LEFT, COMBO_END};
    const uint16_t PROGMEM norm_grv[] = { KC_Y, KC_J, COMBO_END};
    const uint16_t PROGMEM norm_tild[] = { KC_J, KC_P, COMBO_END};
    const uint16_t PROGMEM norm_hash[] = { KC_Y, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM norm_perc[] = { KC_U, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM norm_exlm[] = { KC_U, KC_I, KC_L, COMBO_END};
    const uint16_t PROGMEM norm_ques[] = { KC_J, KC_K, KC_O, COMBO_END};
    const uint16_t PROGMEM norm_dlr[] = { KC_M, KC_LEFT, KC_O, COMBO_END};
    const uint16_t PROGMEM norm_at[] = { KC_U, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM norm_ampr[] = { KC_H, KC_K, COMBO_END};
    const uint16_t PROGMEM norm_astr[] = { KC_N, KC_M, KC_LEFT, COMBO_END};
    //Symbols on number layer
    const uint16_t PROGMEM numslsh[] = { KC_7, KC_5, KC_3, COMBO_END};
    const uint16_t PROGMEM numbsls[] = { KC_1, KC_5, KC_9, COMBO_END};
    const uint16_t PROGMEM numpipe[] = { KC_2, KC_4, KC_0, COMBO_END};
    const uint16_t PROGMEM numcirc[] = { KC_4, KC_2, KC_6, COMBO_END};
    const uint16_t PROGMEM numlt[] = { KC_2, KC_4, KC_8, COMBO_END};
    const uint16_t PROGMEM numgt[] = { KC_2, KC_6, KC_8, COMBO_END};
    const uint16_t PROGMEM numgrv[] = { KC_Y, KC_4, COMBO_END};
    const uint16_t PROGMEM numtild[] = { KC_4, KC_P, COMBO_END};
    const uint16_t PROGMEM numhash[] = { KC_Y, KC_1, KC_2, COMBO_END};
    const uint16_t PROGMEM numperc[] = { KC_1, KC_9, COMBO_END};
    const uint16_t PROGMEM numexlm[] = { KC_1, KC_2, KC_6, COMBO_END};
    const uint16_t PROGMEM numques[] = { KC_4, KC_5, KC_3, COMBO_END};
    const uint16_t PROGMEM numdlr[] = { KC_7, KC_8, KC_3, COMBO_END};
    const uint16_t PROGMEM numat[] = { KC_1, KC_5, KC_6, COMBO_END};
    const uint16_t PROGMEM numampr[] = { KC_H, KC_5, COMBO_END};
    const uint16_t PROGMEM numastr[] = { KC_N, KC_7, KC_8, COMBO_END};

    //Control keys
    const uint16_t PROGMEM norm_ent[] = { KC_K, KC_L, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM norm_tab[] = { KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM norm_caps[] = { KC_V, KC_B, KC_LSFT, COMBO_END};

    //Navigation keys
    const uint16_t PROGMEM norm_home[] = { KC_U, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM norm_end[] = { KC_I, KC_O, KC_P, COMBO_END};
    const uint16_t PROGMEM norm_pgup[] = { KC_N, KC_UP, COMBO_END};
    const uint16_t PROGMEM norm_pgdn[] = { KC_N, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM norm_ins[] = { KC_SPC, KC_DEL, COMBO_END};

    //Additional media keys
    const uint16_t PROGMEM norm_volu[] = { KC_DEL, KC_LEFT, COMBO_END};
    const uint16_t PROGMEM norm_vold[] = { KC_DEL, KC_M, COMBO_END};
    const uint16_t PROGMEM norm_mprv[] = { KC_DEL, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM norm_mnxt[] = { KC_DEL, KC_UP, COMBO_END};
    const uint16_t PROGMEM norm_mute[] = { KC_DEL, KC_RGHT, COMBO_END};

    //Misc
    const uint16_t PROGMEM lorem_combo[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
    //Number layer
    [NUM_LAYER] = COMBO(num_layer, TT(1)),
    //Function layer
    [FUNC_LAYER] = COMBO(func_layer, TT(2)),

    //Common symbols
    [NORM_DOT]  = COMBO(norm_dot, KC_DOT),
    [NORM_COMM] = COMBO(norm_comm, KC_COMM),
    [NORM_COLN] = COMBO(norm_coln, KC_COLN),
    [NORM_SCLN] = COMBO(norm_scln, KC_SCLN),
    [NORM_QUOT] = COMBO(norm_quot, KC_QUOT),
    [NORM_DQUO] = COMBO(norm_dquo, KC_DQUO),
    //Number layer
    [numDOT] = COMBO(numdot, KC_DOT),
    [numCOMM] = COMBO(numcomm, KC_COMM),
    [numCOLN] = COMBO(numcoln, KC_COLN),
    [numSCLN] = COMBO(numscln, KC_SCLN),
    [numQUOT] = COMBO(numquot, KC_QUOT),
    [numDQUO] = COMBO(numdquo, KC_DQUO),

    //Basic math symbols
    [NORM_EQL] = COMBO(norm_eql, KC_EQL),
    [NORM_MINS] = COMBO(norm_mins, KC_MINS),
    [NORM_PLUS] = COMBO(norm_plus, KC_PLUS),
    [NORM_UNDS] = COMBO(norm_unds, KC_UNDS),
    //Number layer
    [NUM_EQL] = COMBO(num_eql, KC_EQL),
    [NUM_MINS] = COMBO(num_mins, KC_MINS),
    [NUM_PLUS] = COMBO(num_plus, KC_PLUS),
    [NUM_UNDS] = COMBO(num_unds, KC_UNDS),

    //Parentheses
    [NORM_LBRC] = COMBO(norm_lbrc, KC_LBRC),
    [NORM_RBRC] = COMBO(norm_rbrc, KC_RBRC),
    [NORM_LPRN] = COMBO(norm_lprn, KC_LPRN),
    [NORM_RPRN] = COMBO(norm_rprn, KC_RPRN),
    [NORM_LCBR] = COMBO(norm_lcbr, KC_LCBR),
    [NORM_RCBR] = COMBO(norm_rcbr, KC_RCBR),
    //Number layer   
    [NORM_LBRC] = COMBO(norm_lbrc, KC_LBRC),
    [NORM_RBRC] = COMBO(norm_rbrc, KC_RBRC),
    [NORM_LPRN] = COMBO(norm_lprn, KC_LPRN),
    [NORM_RPRN] = COMBO(norm_rprn, KC_RPRN),
    [NORM_LCBR] = COMBO(norm_lcbr, KC_LCBR),
    [NORM_RCBR] = COMBO(norm_rcbr, KC_RCBR),

    //Symbols
    [NORM_SLSH] = COMBO(norm_slsh, KC_SLSH),
    [NORM_BSLS] = COMBO(norm_bsls, KC_BSLS),
    [NORM_PIPE] = COMBO(norm_pipe, KC_PIPE),
    [NORM_CIRC] = COMBO(norm_circ, KC_CIRC),
    [NORM_LT] = COMBO(norm_lt, KC_LT),
    [NORM_GT] = COMBO(norm_gt, KC_GT),
    [NORM_GRV] = COMBO(norm_grv , KC_GRV),
    [NORM_TILD] = COMBO(norm_tild, KC_TILD),
    [NORM_HASH] = COMBO(norm_hash, KC_HASH),
    [NORM_PERC] = COMBO(norm_perc, KC_PERC),
    [NORM_EXLM] = COMBO(norm_exlm, KC_EXLM),
    [NORM_QUES] = COMBO(norm_ques, KC_QUES),
    [NORM_DLR] = COMBO(norm_dlr, KC_DLR),
    [NORM_AT] = COMBO(norm_at, KC_AT),
    [NORM_AMPR] = COMBO(norm_ampr, KC_AMPR),
    [NORM_ASTR] = COMBO(norm_astr, KC_ASTR),
    //Symbols on number layer
    [NUMSLSH] = COMBO(numslsh, KC_SLSH),
    [NUMBSLS] = COMBO(numbsls, KC_BSLS),
    [NUMPIPE] = COMBO(numpipe, KC_PIPE),
    [NUMCIRC] = COMBO(numcirc, KC_CIRC),
    [NUMLT] = COMBO(numlt, KC_LT),
    [NUMGT] = COMBO(numgt, KC_GT),
    [NUMGRV] = COMBO(numgrv, KC_GRV),
    [NUMTILD] = COMBO(numtild, KC_TILD),
    [NUMHASH] = COMBO(numhash, KC_HASH),
    [NUMPERC] = COMBO(numperc, KC_PERC),
    [NUMEXLM] = COMBO(numexlm, KC_EXLM),
    [NUMQUES] = COMBO(numques, KC_QUES),
    [NUMDLR] = COMBO(numdlr, KC_DLR),
    [NUMAT] = COMBO(numat, KC_AT),
    [NUMAMPR] = COMBO(numampr, KC_AMPR),
    [NUMASTR] = COMBO(numastr, KC_ASTR),

    //Control keys
    [NORM_ENT] = COMBO(norm_ent, KC_ENT),
    [NORM_TAB] = COMBO(norm_tab, KC_TAB),
    [NORM_CAPS] = COMBO(norm_caps, KC_CAPS),

    //Navigation keys
    [NORM_HOME] = COMBO(norm_home, KC_HOME),
    [NORM_END] = COMBO(norm_end, KC_END),
    [NORM_PGUP] = COMBO(norm_pgup, KC_PGUP),
    [NORM_PGDN] = COMBO(norm_pgdn, KC_PGDN),
    [NORM_INS] = COMBO(norm_ins, KC_INS),

    //Additional media keys
    [NORM_VOLU] = COMBO(norm_volu, KC_VOLU),
    [NORM_VOLD] = COMBO(norm_vold, KC_VOLD),
    [NORM_MPRV] = COMBO(norm_mprv, KC_MPRV),
    [NORM_MNXT] = COMBO(norm_mnxt, KC_MNXT),
    [NORM_MUTE] = COMBO(norm_mute, KC_MUTE),

    //Misc
    [ASDF_LOREM] = COMBO_ACTION(lorem_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case ASDF_LOREM:
      if (pressed) {
        SEND_STRING("Lorem ipsum dolor sit amet ");
      }
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}