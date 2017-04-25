/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

with uiNameSpace do { ACE_AIRACRAFT_LOADOUT = _this select 0 };

TRACE_1("Dialog open ... Processing weaponlist","");
private["_dummy"];
_dummy = [] spawn FUNC(weaponlist);

false
