/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL

#include "script_component.hpp"
#include "script_dialog_defines.hpp"

PARAMS_2(_unit,_disp);

private["_weapon_on_back","_pic"];

_weapon_on_back = _unit getVariable ["ACE_weapononback",""];
_pic = if ( _weapon_on_back != "" && {isClass (configFile >> "cfgWeapons" >> _weapon_on_back)} ) then {
	getText (configFile >> "cfgWeapons" >> _weapon_on_back >> "picture")
} else {
	QPATHTO_T(data\ui\ui_gear_wob_gs.paa)
};

(_disp displayCtrl ACE_GEAR_SLOT_WOB_IDC) ctrlsettext _pic;
