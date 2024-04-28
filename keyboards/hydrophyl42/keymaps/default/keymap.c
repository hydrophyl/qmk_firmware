#include QMK_KEYBOARD_H

#define KC_ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,   KC_Q,    KC_W,     KC_E,    KC_R,   KC_T,                        KC_Y,    KC_U,    KC_I,   KC_O,    KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ENT,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                         KC_H,    KC_J,    KC_K,   KC_L,   KC_SCLN,  KC_LGUI,
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
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_TRNS,
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
    D_F_LAYER,
    W_D_LAYER,
    
    //Function layer
    Q_W_LAYER,
    
    //Common symbols
    SCLN_L_DOT,
    K_SCLN_COMM,
    J_SCLN_L_COLN,
    J_K_SCLN_SCLN,
    I_SCLN_QUOT,
    U_SCLN_DQUO,
    //Number layer
    numDOT,
    numCOMM,
    numCOLN,
    numSCLN,
    numQUOT,
    numDQUO,
    
    //Basic math symbols
    Y_U_EQL,
    H_J_MINS,
    H_J_K_PLUS,
    N_M_UNDS,
    //Number layer
    Y_1_EQL,
    H_4_MINS,
    H_4_5_PLUS,
    N_7_UNDS,
    
    //Parentheses
    BSPC_U_LBRC,
    BSPC_I_RBRC,
    BSPC_J_LPRN,
    BSPC_K_RPRN,
    BSPC_M_LCBR,
    BSPC_LEFT_RCBR,
    //Number layer
    BSPC_1_LBRC,
    BSPC_2_RBRC,
    BSPC_4_LPRN,
    BSPC_5_RPRN,
    BSPC_7_LCBR,
    BSPC_8_RCBR,
    
    //Symbols
    M_K_O_SLSH,
    U_K_DOWN_BSLS,
    I_J_SPC_PIPE,
    J_I_SCLN_CIRC,
    I_J_DEL_LT,
    U_K_BSPC_GT,
    Y_J_GRV,
    J_P_TILD,
    Y_U_I_HASH,
    U_DOWN_PERC,
    U_I_SCLN_EXLM,
    J_K_O_QUES,
    M_LEFT_O_DLR,
    U_K_SCLN_AT,
    H_K_AMPR,
    N_M_LEFT_ASTR,
    //Symbols on number layer
    numSLSH,
    numBSLS,
    numPIPE,
    numCIRC,
    numLT,
    numGT,
    numGRV,
    numTILD,
    numHASH,
    numPERC,
    numEXLM,
    numQUES,
    numDLR,
    numAT,
    numAMPR,
    numASTR,
    
    //Control keys
    K_SCLN_L_ENT,
    numENT,
    J_K_TAB,
    V_B_LSFT_CAPS,

    //Navigation keys
    U_I_O_HOME,
    I_O_P_END,
    N_UP_PGUP,
    N_DOWN_PGDN,
    SPC_DEL_INS,
    
    //Additional media keys
    P_VOLU_MPRV,
    SCLN_VOLD_MNXT,
    UP_MPLY_MUTE,
    
    //Mouse keys
    M_LEFT_BTN1,
    M_DOWN_BTN2,
    M_LEFT_DOWN_BTN3,
    J_L_WH_U,
    M_UP_WH_D,
    M_L_WH_L,
    J_UP_WH_R,
    
    //Misc 
    P_C_M_R_LCG_SWP,
    M_A_C_LCG_NRM,
    Q_W_E_R_T_NK_TOGG,
    ASDF_LOREM,
    COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;
    //Number layer
    const uint16_t PROGMEM d_f_layer[] = { KC_D, KC_F, COMBO_END};

    //Function layer
    const uint16_t PROGMEM q_w_layer[] = { KC_Q, KC_W, COMBO_END};

    //Common symbols
    const uint16_t PROGMEM SCLN_L_dot[] = { KC_SCLN, KC_L, COMBO_END};
    const uint16_t PROGMEM k_up_comm[] = { KC_K, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM j_up_l_coln[] = { KC_J, KC_SCLN, KC_L, COMBO_END};
    const uint16_t PROGMEM j_k_up_scln[] = { KC_J, KC_K, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM i_up_quot[] = { KC_I, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM u_up_dquo[] = { KC_U, KC_SCLN, COMBO_END};
    //Number layer
    const uint16_t PROGMEM numdot[] = { KC_6, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM numcomm[] = { KC_5, KC_6, COMBO_END};
    const uint16_t PROGMEM numcoln[] = { KC_4, KC_6, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM numscln[] = { KC_4, KC_5, KC_6, COMBO_END};
    const uint16_t PROGMEM numquot[] = { KC_2, KC_6, COMBO_END};
    const uint16_t PROGMEM numdquo[] = { KC_1, KC_6, COMBO_END};

    //Basic math symbols
    const uint16_t PROGMEM y_u_eql[] = { KC_Y, KC_U, COMBO_END};
    const uint16_t PROGMEM h_j_mins[] = { KC_H, KC_J, COMBO_END};
    const uint16_t PROGMEM h_j_k_plus[] = { KC_H, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM n_m_unds[] = { KC_N, KC_M, COMBO_END};
    //Number layer
    const uint16_t PROGMEM y_1_eql[] = { KC_Y, KC_1, COMBO_END};
    const uint16_t PROGMEM h_4_mins[] = { KC_H, KC_4, COMBO_END};
    const uint16_t PROGMEM h_4_5_plus[] = { KC_H, KC_4, KC_5, COMBO_END};
    const uint16_t PROGMEM n_7_unds[] = { KC_N, KC_7, COMBO_END};

    //Parentheses
    const uint16_t PROGMEM bspc_u_lbrc[] = { KC_BSPC, KC_U, COMBO_END};
    const uint16_t PROGMEM bspc_i_rbrc[] = { KC_BSPC, KC_I, COMBO_END};
    const uint16_t PROGMEM bspc_j_lprn[] = { KC_BSPC, KC_J, COMBO_END};
    const uint16_t PROGMEM bspc_k_rprn[] = { KC_BSPC, KC_K, COMBO_END};
    const uint16_t PROGMEM bspc_m_lcbr[] = { KC_BSPC, KC_M, COMBO_END};
    const uint16_t PROGMEM bspc_LEFT_rcbr[] = { KC_BSPC, KC_LEFT, COMBO_END};
    //Number layer
    const uint16_t PROGMEM bspc_1_lbrc[] = { KC_BSPC, KC_1, COMBO_END};
    const uint16_t PROGMEM bspc_2_rbrc[] = { KC_BSPC, KC_2, COMBO_END};
    const uint16_t PROGMEM bspc_4_lprn[] = { KC_BSPC, KC_4, COMBO_END};
    const uint16_t PROGMEM bspc_5_rprn[] = { KC_BSPC, KC_5, COMBO_END};
    const uint16_t PROGMEM bspc_7_lcbr[] = { KC_BSPC, KC_7, COMBO_END};
    const uint16_t PROGMEM bspc_8_rcbr[] = { KC_BSPC, KC_8, COMBO_END};

    //Symbols
    const uint16_t PROGMEM m_k_o_slsh[] = { KC_M, KC_K, KC_O, COMBO_END};
    const uint16_t PROGMEM u_k_DOWN_bsls[] = { KC_U, KC_K, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM i_j_spc_pipe[] = { KC_I, KC_J, KC_SPC, COMBO_END};
    const uint16_t PROGMEM j_i_SCLN_circ[] = { KC_J, KC_I, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM i_j_del_lt[] = { KC_I, KC_J, KC_DEL, COMBO_END};
    const uint16_t PROGMEM u_k_bspc_gt[] = { KC_U, KC_K, KC_BSPC, COMBO_END};
    const uint16_t PROGMEM y_j_grv[] = { KC_Y, KC_J, COMBO_END};
    const uint16_t PROGMEM j_p_tild[] = { KC_J, KC_P, COMBO_END};
    const uint16_t PROGMEM y_u_i_hash[] = { KC_Y, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM u_down_perc[] = { KC_U, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM u_i_up_exlm[] = { KC_U, KC_I, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM j_k_o_ques[] = { KC_J, KC_K, KC_O, COMBO_END};
    const uint16_t PROGMEM m_left_o_dlr[] = { KC_M, KC_LEFT, KC_O, COMBO_END};
    const uint16_t PROGMEM u_k_up_at[] = { KC_U, KC_K, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM h_k_ampr[] = { KC_H, KC_K, COMBO_END};
    const uint16_t PROGMEM n_m_left_astr[] = { KC_N, KC_M, KC_LEFT, COMBO_END};
    //Symbols on number layer
    const uint16_t PROGMEM numslsh[] = { KC_7, KC_5, KC_3, COMBO_END};
    const uint16_t PROGMEM numbsls[] = { KC_1, KC_5, KC_9, COMBO_END};
    const uint16_t PROGMEM numpipe[] = { KC_2, KC_4, KC_0, COMBO_END};
    const uint16_t PROGMEM numcirc[] = { KC_4, KC_2, KC_6, COMBO_END};
    const uint16_t PROGMEM numlt[] = { KC_2, KC_4, KC_DEL, COMBO_END};
    const uint16_t PROGMEM numgt[] = { KC_1, KC_5, KC_BSPC, COMBO_END};
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
    const uint16_t PROGMEM k_SCLN_L_ent[] = { KC_K, KC_SCLN, KC_L, COMBO_END};
    const uint16_t PROGMEM nument[] = { KC_5, KC_6, KC_L, COMBO_END};
    const uint16_t PROGMEM j_k_tab[] = { KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM v_b_lsft_caps[] = { KC_V, KC_B, KC_LSFT, COMBO_END};

    //Navigation keys
    const uint16_t PROGMEM u_i_o_home[] = { KC_U, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM i_o_p_end[] = { KC_I, KC_O, KC_P, COMBO_END};
    const uint16_t PROGMEM n_up_pgup[] = { KC_N, KC_UP, COMBO_END};
    const uint16_t PROGMEM n_down_pgdn[] = { KC_N, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM spc_del_ins[] = { KC_SPC, KC_DEL, COMBO_END};

    //Additional media keys
    const uint16_t PROGMEM p_volu_mprv[] = { KC_P, KC_VOLU, COMBO_END};
    const uint16_t PROGMEM scln_vold_mnxt[] = { KC_SCLN, KC_VOLD, COMBO_END};
    const uint16_t PROGMEM rght_mply_mute[] = { KC_UP, KC_MPLY, COMBO_END};

    //Mouse keys
    const uint16_t PROGMEM m_left_btn1[] = { KC_M, KC_LEFT, COMBO_END};
    const uint16_t PROGMEM m_down_btn2[] = { KC_M, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM m_left_down_btn3[] = { KC_M, KC_LEFT, KC_DOWN, COMBO_END};
    const uint16_t PROGMEM j_L_wh_u[] = { KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM m_UP_wh_d[] = { KC_M, KC_UP, COMBO_END};
    const uint16_t PROGMEM m_L_wh_l[] = { KC_M, KC_L, COMBO_END};
    const uint16_t PROGMEM j_UP_wh_r[] = { KC_J, KC_UP, COMBO_END};

    //Misc
    const uint16_t PROGMEM lorem_combo[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
    //Number layer
    [D_F_LAYER] = COMBO(d_f_layer, TT(1)),
    [W_D_LAYER] = COMBO(w_d_layer, TT(1)),

    //Function layer
    [Q_W_LAYER] = COMBO(q_w_layer, TT(2)),

    //Common symbols
    [SCLN_L_DOT] = COMBO(SCLN_L_dot, KC_DOT),
    [K_SCLN_COMM] = COMBO(k_up_comm, KC_COMM),
    [J_SCLN_L_COLN] = COMBO(j_up_l_coln, KC_COLN),
    [J_K_SCLN_SCLN] = COMBO(j_k_up_scln, KC_SCLN),
    [I_SCLN_QUOT] = COMBO(i_up_quot, KC_QUOT),
    [U_SCLN_DQUO] = COMBO(u_up_dquo, KC_DQUO),
    //Number layer
    [numDOT] = COMBO(numdot, KC_DOT),
    [numCOMM] = COMBO(numcomm, KC_COMM),
    [numCOLN] = COMBO(numcoln, KC_COLN),
    [numSCLN] = COMBO(numscln, KC_SCLN),
    [numQUOT] = COMBO(numquot, KC_QUOT),
    [numDQUO] = COMBO(numdquo, KC_DQUO),

    //Basic math symbols
    [Y_U_EQL] = COMBO(y_u_eql, KC_EQL),
    [H_J_MINS] = COMBO(h_j_mins, KC_MINS),
    [H_J_K_PLUS] = COMBO(h_j_k_plus, KC_PLUS),
    [N_M_UNDS] = COMBO(n_m_unds, KC_UNDS),
    //Number layer
    [Y_1_EQL] = COMBO(y_1_eql, KC_EQL),
    [H_4_MINS] = COMBO(h_4_mins, KC_MINS),
    [H_4_5_PLUS] = COMBO(h_4_5_plus, KC_PLUS),
    [N_7_UNDS] = COMBO(n_7_unds, KC_UNDS),

    //Parentheses
    [BSPC_U_LBRC] = COMBO(bspc_u_lbrc, KC_LBRC),
    [BSPC_I_RBRC] = COMBO(bspc_i_rbrc, KC_RBRC),
    [BSPC_J_LPRN] = COMBO(bspc_j_lprn, KC_LPRN),
    [BSPC_K_RPRN] = COMBO(bspc_k_rprn, KC_RPRN),
    [BSPC_M_LCBR] = COMBO(bspc_m_lcbr, KC_LCBR),
    [BSPC_LEFT_RCBR] = COMBO(bspc_LEFT_rcbr, KC_RCBR),
    //Number layer   
    [BSPC_1_LBRC] = COMBO(bspc_1_lbrc, KC_LBRC),
    [BSPC_2_RBRC] = COMBO(bspc_2_rbrc, KC_RBRC),
    [BSPC_4_LPRN] = COMBO(bspc_4_lprn, KC_LPRN),
    [BSPC_5_RPRN] = COMBO(bspc_5_rprn, KC_RPRN),
    [BSPC_7_LCBR] = COMBO(bspc_7_lcbr, KC_LCBR),
    [BSPC_8_RCBR] = COMBO(bspc_8_rcbr, KC_RCBR),

    //Symbols
    [M_K_O_SLSH] = COMBO(m_k_o_slsh, KC_SLSH),
    [U_K_DOWN_BSLS] = COMBO(u_k_DOWN_bsls, KC_BSLS),
    [I_J_SPC_PIPE] = COMBO(i_j_spc_pipe, KC_PIPE),
    [J_I_SCLN_CIRC] = COMBO(j_i_SCLN_circ, KC_CIRC),
    [I_J_DEL_LT] = COMBO(i_j_del_lt, KC_LT),
    [U_K_BSPC_GT] = COMBO(u_k_bspc_gt, KC_GT),
    [Y_J_GRV] = COMBO(y_j_grv, KC_GRV),
    [J_P_TILD] = COMBO(j_p_tild, KC_TILD),
    [Y_U_I_HASH] = COMBO(y_u_i_hash, KC_HASH),
    [U_DOWN_PERC] = COMBO(u_down_perc, KC_PERC),
    [U_I_SCLN_EXLM] = COMBO(u_i_up_exlm, KC_EXLM),
    [J_K_O_QUES] = COMBO(j_k_o_ques, KC_QUES),
    [M_LEFT_O_DLR] = COMBO(m_left_o_dlr, KC_DLR),
    [U_K_SCLN_AT] = COMBO(u_k_up_at, KC_AT),
    [H_K_AMPR] = COMBO(h_k_ampr, KC_AMPR),
    [N_M_LEFT_ASTR] = COMBO(n_m_left_astr, KC_ASTR),
    //Symbols on number layer
    [numSLSH] = COMBO(numslsh, KC_SLSH),
    [numBSLS] = COMBO(numbsls, KC_BSLS),
    [numPIPE] = COMBO(numpipe, KC_PIPE),
    [numCIRC] = COMBO(numcirc, KC_CIRC),
    [numLT] = COMBO(numlt, KC_LT),
    [numGT] = COMBO(numgt, KC_GT),
    [numGRV] = COMBO(numgrv, KC_GRV),
    [numTILD] = COMBO(numtild, KC_TILD),
    [numHASH] = COMBO(numhash, KC_HASH),
    [numPERC] = COMBO(numperc, KC_PERC),
    [numEXLM] = COMBO(numexlm, KC_EXLM),
    [numQUES] = COMBO(numques, KC_QUES),
    [numDLR] = COMBO(numdlr, KC_DLR),
    [numAT] = COMBO(numat, KC_AT),
    [numAMPR] = COMBO(numampr, KC_AMPR),
    [numASTR] = COMBO(numastr, KC_ASTR),

    //Control keys
    [K_SCLN_L_ENT] = COMBO(k_SCLN_L_ent, KC_ENT),
    [numENT] = COMBO(nument, KC_ENT),
    [J_K_TAB] = COMBO(j_k_tab, KC_TAB),
    [V_B_LSFT_CAPS] = COMBO(v_b_lsft_caps, KC_CAPS),

    //Navigation keys
    [U_I_O_HOME] = COMBO(u_i_o_home, KC_HOME),
    [I_O_P_END] = COMBO(i_o_p_end, KC_END),
    [N_UP_PGUP] = COMBO(n_up_pgup, KC_PGUP),
    [N_DOWN_PGDN] = COMBO(n_down_pgdn, KC_PGDN),
    [SPC_DEL_INS] = COMBO(spc_del_ins, KC_INS),

    //Additional media keys
    [P_VOLU_MPRV] = COMBO(p_volu_mprv, KC_MPRV),
    [SCLN_VOLD_MNXT] = COMBO(scln_vold_mnxt, KC_MNXT),
    [UP_MPLY_MUTE] = COMBO(rght_mply_mute, KC_MUTE),

    //Mouse keys
    [M_LEFT_BTN1] = COMBO(m_left_btn1, KC_BTN1),
    [M_DOWN_BTN2] = COMBO(m_down_btn2, KC_BTN2),
    [M_LEFT_DOWN_BTN3] = COMBO(m_left_down_btn3, KC_BTN3),
    [J_L_WH_U] = COMBO(j_L_wh_u, KC_WH_U),
    [M_UP_WH_D] = COMBO(m_UP_wh_d, KC_WH_D),
    [M_L_WH_L] = COMBO(m_L_wh_l, KC_WH_L),
    [J_UP_WH_R] = COMBO(j_UP_wh_r, KC_WH_R),

    //Misc
    [ASDF_LOREM] = COMBO_ACTION(lorem_combo),
    [P_C_M_R_LCG_SWP] = COMBO(p_c_m_r_lcg_swp, LCG_SWP),
    [M_A_C_LCG_NRM] = COMBO(m_a_c_lcg_nrm, LCG_NRM),
    [Q_W_E_R_T_NK_TOGG] = COMBO(q_w_e_r_t_nk_togg, NK_TOGG),
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