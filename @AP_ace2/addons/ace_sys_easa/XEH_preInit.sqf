/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(onload);
PREP(default_loadout);
PREP(apply_loadout);
PREP(remove_loadout);
PREP(pylonlist);
PREP(weaponlist);

PREP(load);

PREP(rules);

[QGVAR(load), {_this spawn FUNC(load)}] call CBA_fnc_addEventHandler;

ADDON = true;