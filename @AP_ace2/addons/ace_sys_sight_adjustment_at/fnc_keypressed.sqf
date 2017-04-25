//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
#define __cfgw configFile >> "CfgWeapons" >> _wpn

private["_wpn","_abort"];
PARAMS_2(_keyData,_type);

TRACE_1("Key detected","");

if (secondaryWeapon player == "") exitwith {
	TRACE_1("No launcher","");
	false;
};

_wpn = currentWeapon player;
TRACE_1("Weapon",_wpn);

if (_wpn != secondaryWeapon player) exitwith {
	TRACE_1("Weapon not secondary","");
	false;
};		//now we know player's got launcher in hands

//don't allow sight adj when looking through a BDC scope (such as PGO)
_abort = false;
if (getNumber(__cfgw >> "ace_sa_enabled")==1) then {
	if (isNumber(__cfgw >> "ace_at_zero_fov") && {cameraview == "gunner"}) then {
		if (abs(1 - ((call cba_fnc_getfov) select 0)/getNumber(__cfgw >> "ace_at_zero_fov"))<= 0.1) then {_abort = true};
	};
};
if (_abort) exitwith {false};

if (_wpn != ACE_SYS_SA_CURWEAPON) exitwith {		//retrieving sight properties from weapon config
	TRACE_1("Calling fnc_newWeap","");
	_wpn call FUNC(newWeap);
	false;
};

//at this point weapon config is loaded up and player has launcher in hands, time to actually increase/decrease range setting
TRACE_1("Before switch","");
switch (_type) do {
	case 0: {
		1 call FUNC(setDegrees);
	};
	case 1: {
		-1 call FUNC(setDegrees);
	};
	default { TRACE_1("Error",""); };
};
TRACE_1("Past switch","");

cutRsc ["ACE_RscGeneric","PLAIN"];
#define __dsp (uiNameSpace getVariable "ACE_RscGeneric")
#define __ctrl __dsp displayCtrl 135136
__ctrl ctrlSetText format["%1: %2 m", localize "STR_ACE_SA_ATGL_RANGE", ACE_SYS_SA_CURELEVATION];

TRACE_1("The End","");

true;
