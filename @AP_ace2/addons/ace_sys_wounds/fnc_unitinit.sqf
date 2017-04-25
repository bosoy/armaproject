#include "script_component.hpp"

_this setVariable ["ace_w_initialized",true];
_this setVariable ["ace_w_overall",0];
_this setVariable ["ace_w_head_hit",0];
_this setVariable ["ace_w_body",0];
_this setVariable ["ace_w_hands",0];
_this setVariable ["ace_w_legs",0];
_this setVariable ["ace_w_state",0]; // state 0 = everything is ok
_this setVariable [QGVAR(uncon), false, true];
_this setVariable ["ace_w_bleed",0]; // 0 = no bleeding
_this setVariable ["ace_w_bleed_add",0];
_this setVariable ["ace_w_pain",0];
_this setVariable ["ace_w_pain_add",0];
_this setVariable ["ace_w_epi",0];
_this setVariable ["ace_w_nextuncon", -1];
_this setVariable ["ace_w_unconlen", -1];
_this setVariable ["ace_w_stab", 1];
_this setVariable ["ace_w_carry", objNull, true];
_this setVariable ["ace_w_revive", -1];
_this setVariable ["ace_w_wakeup", 0];

_this setVariable ["ace_w_hc", 0]; // heal count
_this setVariable ["ace_w_healing", false];
_this setVariable ["ace_w_healing_r", false];
_this setVariable ["ace_w_stabilizing", false];
_this setVariable ["ace_w_stabilizing_r", false];

_this setVariable ["ace_w_falling", false];
_this setVariable ["ace_w_check", false];
_this setVariable ["ace_w_requested_help", false];
_this setVariable ["ace_is_burning", false];
_this setVariable ["ace_w_busy", false, true];

// Tourniquet stuff
_this setVariable ["ace_w_cat",false,true];
_this setVariable ["ace_w_cat_time",0];
_this setVariable ["ace_w_cat_bleed_add_restore",0,true];

// Morphine stuff
_this setVariable ["ace_w_mor_time",0];
_this setVariable ["ace_w_mor_dosage",0];