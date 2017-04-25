/*
  BASIC Test - Run without ACE etc. Just CBA at most, but also test without
  (e.g copy to mission, incl a CBA script_component.hpp etc)
*/

// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_7(_unit,_weapon,_bla,_bla,_ammo,_magazine,_bullet);
if (isNull _bullet) exitwith { TRACE_2("Fired EH did not bring bullet",diag_fps,diag_fpsMin) };
