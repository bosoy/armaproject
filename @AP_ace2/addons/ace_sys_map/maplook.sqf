//maplook.sqf
//Original script by Kevb0 - Modified by Strango
// Modified by Xeno
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// TODO: ACE_ItemMap with scope = 1 doesn't work, reverting to ACE_Map, otherwise you are not able to look up maps of other units

#define __MAP "ACE_Map"

PARAMS_2(_guywithmap,_guywithoutmap);

hintSilent format [localize "STR_DN_ACE_SYS_MAP_LOOKING",(_guywithmap distance _guywithoutmap),2];

_guywithoutmap addWeapon __MAP;  // Add the hidden map. Possibly makes sys_ruck hack for "ACE_Map" obsolete....or not
while { _guywithmap distance _guywithoutmap < 2 && {isNil "ACE_gearopen"} } do {
	if (speed _guywithoutmap > 7) exitWith {};
	if (!alive _guywithoutmap) exitWith {};
	sleep 0.5;
};
_guywithoutmap removeWeapon __MAP; // Remove the hidden map

if (alive _guywithoutmap && {!(_guywithoutmap hasWeapon __MAP)}) then {
	hintSilent localize "STR_DN_ACE_SYS_MAP_TOO_FAR";
};
