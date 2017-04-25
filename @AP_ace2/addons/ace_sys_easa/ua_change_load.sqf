/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __check1 (isnil {_ace_easa getVariable "ACE_EASA_LIP"})
#define __check2 (_ace_easa getVariable "ACE_EASA_LIP")

private["_ace_easa","_pos","_box","_tmp_air","_air","_dialog","_actrice"];

TRACE_1("User access to EASA module","");

_ace_easa = _this;
_actrice = player;
if (player != vehicle player) exitWith {};

GVAR(easa) = _ace_easa;
TRACE_1("User access to EASA module",_ace_easa);

if (!__check1 && {__check2}) exitWith {
	TRACE_1("Module is in use currently","");
	hint (localize "STR_ACE_EASA_HANGARINUSE");
};

_pos = _ace_easa getVariable ["ACE_EASA_POS", getPos _ace_easa];

_tmp_air = ((position GVAR(easa)) nearEntities ["Air",20]) select 0;
if (_tmp_air == objNull || {(GVAR(easa) distance  _tmp_air) > 20}) exitWith {
	if (_tmp_air == objNull) then {
		TRACE_1("No aircraft found","");
	} else {
		TRACE_1("Distance", ((position _tmp_air) distance _pos));
	};
	hint (localize "STR_ACE_EASA_NOAIRCRAFT");
};
private["_air"];
if (_tmp_air isKindOf "Helicopter") exitWith {}; // Disabled due to incompatibility with rack + multimagazines on helicopters
if (_tmp_air isKindOf "Plane") then {
	_air = _tmp_air;
};
GVAR(air) = _air;
TRACE_1("Valid aircraft found",_air);

[_ace_easa,_air,"SET"] call FUNC(rules);

sleep 1;
_dialog = createDialog "ACE_Aircraft_Loadout";
_ace_easa setVariable ["ACE_EASA_LIP",true,true];

TRACE_1("Dialog started ... waiting until closed","");
waitUntil { !dialog };
TRACE_1("Dialog closed ... Procedure finished ... cleaning up","");

_ace_easa setVariable ["ACE_EASA_LIP",false,true];

["",_air,"DESTROY"] call FUNC(rules);

GVAR(air) = nil;
GVAR(easa) = nil;
GVAR(pylons_processed) = nil;
_air = nil;
