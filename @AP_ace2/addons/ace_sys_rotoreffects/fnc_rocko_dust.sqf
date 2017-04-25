/* ace_sys_helidust | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

// TODO: not a nice way to check for pilots
// what if a third party addon has its own pilot classes ?
#define __PILOT ["USMC_Soldier_Pilot","CDF_Soldier_Pilot","RU_Soldier_Pilot","GUE_Soldier_Pilot","Ins_Soldier_Pilot","CZ_Soldier_Pilot_EP1","US_Soldier_Pilot_EP1","US_Pilot_Light_EP1","Pierce","Pierce_Light","UN_CDF_Soldier_Pilot_EP1","TK_Soldier_Pilot_EP1","BAF_Pilot_MTP","BAF_Pilot_DDPM","BAF_Pilot_W"]
#define __LHD ["USMC_LHD_Crew_Base"]

#define __VTOL (getNumber(configFile >> "CfgVehicles" >> (typeOf _v) >> "vtol"))

private ["_v", "_ond", "_distance", "_typeOf", "_timeend", "_dbenabled"];

PARAMS_1(_v);

_ond = _v getVariable QGVAR(duston);
if (isNil "_ond") then {
	_v setVariable [QGVAR(duston), false];
};

if (_v getVariable QGVAR(duston)) exitWith {};
_v setVariable [QGVAR(duston), true];

while {alive _v && {canMove _v}} do {
	TRACE_1("wating","");
	if !(_v getVariable QGVAR(enginestate)) exitWith {};
	waitUntil {sleep 0.321;((((getPos _v) select 2) < 25) || {!(_v getVariable QGVAR(enginestate))})};
	if !(_v getVariable QGVAR(enginestate)) exitWith {};
	_distance = _v distance player;
	if (_distance < 25 && {vehicle player == player}) then {
		TRACE_1("Prepare dust","");
		private "_typeOf";
		_typeOf = typeOf player;
		if ([player] call ace_sys_goggles_fnc_eyeprotection) exitWith { TRACE_1("No dust cuz of eyeprotection",""); };
		if ([player] call ACE_fnc_isPilot) exitWith {TRACE_1("No dust cuz of class","")};
		if (_typeOf in __LHD) exitWith {TRACE_1("No dust cuz of class","")};

		if (alive _v && {canMove _v} && {alive player}) then {
			TRACE_1("Make dust","");
			"dynamicBlur" ppEffectEnable true;
			"dynamicBlur" ppEffectAdjust [12.5 / ((_v distance player) max 0.001)];
			"dynamicBlur" ppEffectCommit 2;
			if ((random 10) > 5) then {
				[player,10,40] spawn ace_fx_fnc_cough;
			};
		};
	};
	sleep 3;
	"dynamicBlur" ppEffectEnable false;
};

_v setVariable [QGVAR(duston), false];
if (alive _v && {canMove _v} && {alive player} && {!(__VTOL in [1, 2, 3])}) then {
	// spindown
	if (position _v select 2 < 25) then {
		private "_typeOf";
		_typeOf = typeOf player;
		if ([player] call ace_sys_goggles_fnc_eyeprotection) exitWith {TRACE_1("No dust cuz of eyeprotection","")};
		if (_typeOf in __PILOT) exitWith {TRACE_1("No dust cuz of class","")};
		if (_typeOf in __LHD) exitWith {TRACE_1("No dust cuz of class","")};
		_timeend = time + 30;
		while {_timeend >= time} do {
			if (!alive player || {!alive _v} || {!canMove _v} || {(_v getVariable QGVAR(enginestate))}) exitWith {};
			_dbenabled = false;
			if (((_v distance player) < 25) && {vehicle player == player}) then {
				_dbenabled = true;
				"dynamicBlur" ppEffectEnable true;
				"dynamicBlur" ppEffectAdjust [((_timeend - time) / 3) / ((_v distance player) max 0.001)];
				"dynamicBlur" ppEffectCommit 2;
			};
			sleep 2;
			if (_dbenabled) then {
				"dynamicBlur" ppEffectEnable false;
				_dbenabled = false;
			};
		};
		"dynamicBlur" ppEffectEnable false;
	};
};
