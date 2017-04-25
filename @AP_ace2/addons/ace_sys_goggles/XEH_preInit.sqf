/* ace_sys_goggles (.pbo) | (c) 2009, 2010 by rocko */

#include "script_component.hpp"

#define __protection getNumber (configFile >> "CfgIdentities" >> _identity >> "ACE" >> "ACE_GOGGLES" >> "protection")

PREP(killed);
PREP(rsc_mask);

// OLD BWC
ace_eyeprotection = COMPILE_FILE(fnc_eyeprotection_bwc);
ace_earprotection = COMPILE_FILE(fnc_earprotection_bwc);

PREP(eyeprotection);
PREP(earprotection);

[QGVAR(setident), {_this setIdentity "ACE_Original_Identity"}] call CBA_fnc_addEventHandler;
[QGVAR(setidentcustom), {_this call FUNC(custom)}] call CBA_fnc_addEventHandler;
[QGVAR(setident2), {(_this select 0) setIdentity (_this select 1)}] call CBA_fnc_addEventHandler;

GVAR(mask_deh) = false;

GVAR(overlay_change) = {
	if (isNil QGVAR(overlay_change_active)) then { GVAR(overlay_change_active) = false; };
	if (GVAR(overlay_change_active)) exitWith { false };
	private "_ts1";
	_ts1 = _this select 1;
	if (_ts1 in actionKeys "toggleWeapons" || {_ts1 == -11}) then {
		[] spawn {
			GVAR(overlay_change_active) = true;
			((uiNamespace getVariable "ACE_Gasmask") displayCtrl -1) ctrlSetTextColor [1,1,1,0.7];
			sleep 1.4;
			((uiNamespace getVariable "ACE_Gasmask") displayCtrl -1) ctrlSetTextColor [1,1,1,1];
			GVAR(overlay_change_active) = false;
		};
	};
	false;
};

//FUNC(visor_down) = {
//	_unit = player;
//	_old_identity = _unit getVariable "ace_sys_goggles_identity"; // e.g Wearing an MFS or some sunglasses...
//	player setVariable [QGVAR(visor_store), _oldIdentity]; // Stored for later
//	
//	_identity = "ACE_Visor";
//	// Check if MFS is
//	if (_old_identity in ["ACE_GlassesMFS","ACE_GlassesMFS_R"]) then {
//		_identity = "ACE_GlassesMFSVisor";
//		if (_old_identity in ["ACE_GlassesMFS_R"]) then {
//			_identity = "ACE_GlassesMFS_RVisor";
//		};
//	};
//	// Execute FSM fake
//	["ace_sys_goggles_setident2", [_unit, _identity]] call CBA_fnc_globalEvent;
//
//	_unit setVariable ["ace_sys_goggles_identity",_identity,false];
//	_unit setVariable ["ace_sys_goggles_protection", __protection, false];
//	// BWC
//	_unit setVariable ["ACE_Identity",_identity];
//
//	__rsc spawn ace_sys_goggles_fnc_rsc_mask;	
//	
//	_unit setVariable [QGVAR(visorDown),true];
//};

//FUNC(visor_up) = {
//	_old_identity = _unit getVariable "ace_sys_goggles_identity";
//	
//	player setVariable [QGVAR(visorDown),false];
//};

//FUNC(check_custom) = {};

//FUNC(custom) = {
//	PARAMS_1(_unit);
//	if (!isPlayer _unit) exitWith {};
//	// Check if CustomIdentities Array exist, either config wise or in a mission
//};

