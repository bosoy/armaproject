//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(chgBat);
PREP(chgMil);
PREP(findLT);

PREP(setCurrentLaserCode);
GVAR(currentLaserCode) = 1001;

//constants
EMP_RF_BLF = ( 1/(90*60) ); //battery life, set very high to disable, default 90 minutes
EMP_RF_MAX = 240; //degrees (F), temp before risk of burn out, set very high to disable, default 240
EMP_RF_OHT = 190; //degrees (F), temp to start indicating overheat, default 190
EMP_RF_AMB = 60; //degrees (F), ambient air temperature, default 60
EMP_RF_IDL = 0.5; //degrees (F) per minute, heating rate with laser off, default 0.5
EMP_RF_ACT = 10; //degrees (F) per minute, heating rate with laser on, default 10
EMP_RF_TMP = 60; //degrees (F), starting temperature of device, default same as ambient 60
EMP_RF_REF = 1; //seconds, update display rate, default 1

//output
EMP_RF_ELV = 400; //mils, max elevation setting, default 400
EMP_RF_ACC = 5; //meters, range accurate to, default 5
EMP_RF_MSL = [6400, 6000, 6300, 6283, 360]; //mils, azimuth settings available, default [6400,6000,6300,6283,360]
EMP_RF_MIL = (EMP_RF_MSL select 0); //mils, selected azimuth setting, default first in above array
EMP_VC_MSL = [360, 6400, 6000, 6300, 6283]; //mils, azimuth settings available for Vector 21, default [360,6400,6000,6300,6283]
EMP_VC_MIL = (EMP_VC_MSL select 0); //mils, selected azimuth setting for Vector 21, default first in above array

//conditionals
EMP_RF_BAT = 0; //battery remaining
EMP_RF_UNL = false; //swiped batteries during operation
EMP_RF_MRK = 0; //time last run (start of cooldown)
EMP_RF_BRK = false; //broken after extreme overheat
EMP_RF_LAZ = false; //laser on
EMP_RF_RUN = false; //display running
EMP_RF_STP = false; //stop display
EMP_RF_HLD = false; //keep display up, TODO: allow freelook
EMP_RF_CML = false; //changing mils, need pause

if(getNumber(configFile >> "CfgSettings" >> "CBA" >> "events" >> QUOTE(ADDON) >> "Preload_Battery" >> "always") == 0) then {
	EMP_RF_ALB = false;
} else {
	EMP_RF_ALB = true; //load batteries without device selected using key combo
};

EMP_RF_LIST = __rangefinders;

FUNC(RFkeyDownHandler) = {
	TRACE_1("",_this);
	PARAMS_2(_player,_keys);
	if((currentWeapon _player) in __rangefinders) then {
		if((_keys select 1) in (actionKeys "ReloadMagazine")) then {
			true; //M40,M24 improper reload animation workaround
		} else {
			false;
		};
	} else {
		false;
	};
};
[QUOTE(ADDON), "Toggle_Power", { [player,_this] call FUNC(RFkeyDownHandler) }, "keydown"] call CBA_fnc_addKeyHandlerFromConfig;

FUNC(RFkeyUpHandler) = {
	TRACE_1("",_this);
	PARAMS_2(_player,_keys);
	if((currentWeapon _player) in __rangefinders) then {
		_player execFSM "\x\ace\addons\sys_rangefinder\rangefinder.fsm";
		if((_keys select 1) in (actionKeys "ReloadMagazine")) then {
			true; //M40,M24 improper reload animation workaround
		} else {
			false;
		};
	} else {
		false;
	};
};
[QUOTE(ADDON), "Toggle_Power", { [player,_this] call FUNC(RFkeyUpHandler) }, "keyup"] call CBA_fnc_addKeyHandlerFromConfig;

FUNC(RFaltKeyDownHandler) = {
	TRACE_1("",_this);
	if((currentWeapon _this) in __rangefinders) then {
		_this spawn FUNC(chgMil);
		true;
	} else {
		false;
	};
};
[QUOTE(ADDON), "Cycle_Mils", { player call FUNC(RFaltKeyDownHandler) }, "DOWN"] call CBA_fnc_addKeyHandlerFromConfig;

FUNC(RFmodKeyDownHandler) = {
	private["_run","_rfweapon"];
	TRACE_1("",_this);
	_run = false;
	{if(_this hasWeapon _x) then {_run=true; _rfweapon = _x;};} forEach __rangefinders;
	if(_run) then {
		if(EMP_RF_ALB) then {
			[_this,_rfweapon] spawn FUNC(chgBat);
			true;
		} else {
			if((currentWeapon _this) in __rangefinders) then {
				[_this,_rfweapon] spawn FUNC(chgBat);
				true;
			} else {
				false;
			};
		};
	} else {
		false;
	};
};
[QUOTE(ADDON), "Preload_Battery", { player call FUNC(RFmodKeyDownHandler) }, "DOWN"] call CBA_fnc_addKeyHandlerFromConfig;

// LaserCode key event handlers

FUNC(RFcodeDownHandler) = {
	private["_run", "_rfweapon", "_newLaserCode"];

	TRACE_1("",_this);
	TRACE_1("", (currentWeapon vehicle player));
	_run =  false;
	_newLaserCode = GVAR(currentLaserCode);
	if (currentWeapon vehicle player in ["Laserdesignator","Laserdesignator_Mounted"] && {cameraView != "GUNNER"}) exitWith { false };

	if (GVAR(currentLaserCode) == 1001) then {
		_newLaserCode = 1999;
	} else {
		_newLaserCode = _newLaserCode - 1;
	};
	[_newLaserCode] call FUNC(setCurrentLaserCode);
	TRACE_1("laser code set", GVAR(currentLaserCode));
	true
};
[QUOTE(ADDON), "LaserCode_Down", { player call FUNC(RFcodeDownHandler) }, "DOWN"] call CBA_fnc_addKeyHandlerFromConfig;
//[205, [true, false, false], { player call FUNC(RFcodeUpHandler) }, "keydown", QGVAR(RFcodeUp)] call CBA_fnc_addKeyHandler;


FUNC(RFcodeUpHandler) = {
	private["_run", "_rfweapon", "_newLaserCode"];

	TRACE_1("",_this);
	TRACE_1("", (currentWeapon vehicle player));
	_run =  false;
	_newLaserCode = GVAR(currentLaserCode);
	if (currentWeapon vehicle player in ["Laserdesignator","Laserdesignator_Mounted"] && {cameraView != "GUNNER"}) exitWith { false };

	if (GVAR(currentLaserCode) == 1999) then {
		_newLaserCode = 1001;
	} else {
		INC(_newLaserCode);
	};
	[_newLaserCode] call FUNC(setCurrentLaserCode);
	TRACE_1("laser code set", GVAR(currentLaserCode));

	true
};
[QUOTE(ADDON), "LaserCode_Up", { player call FUNC(RFcodeUpHandler) }, "DOWN"] call CBA_fnc_addKeyHandlerFromConfig;
//[203, [true, false, false], { player call FUNC(RFcodeDownHandler) }, "keydown", QGVAR(RFcodeDown)] call CBA_fnc_addKeyHandler;

FUNC(pickUpSoflam) = {
	PARAMS_2(_scope,_unit);

	_scopeType = typeOf _scope;
	if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
		_unit playMove "AmovPercMstpSrasWrflDnon_diary";
	};
	sleep 1;
	_unit addWeapon _scopeType;
	deleteVehicle _scope;
};

FUNC(placeSoflam) = {

	private ["_unit", "_weapon"];

	_unit = _this;
	_weapon = "ACE_SOFLAMTripod";

	private["_scopeType","_scope"];
	_scopeType = _weapon;

	if !(_weapon in (weapons _unit)) exitWith { false };
	if ("ACE_SOFLAMTripod" in (weapons _unit)) then { _unit removeWeapon "ACE_SOFLAMTripod"; };

	if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
		_unit playMove "AmovPercMstpSrasWrflDnon_diary";
	};

	sleep 1;

	_position = _unit modelToWorld [0,0,0];
	_position set [0, (_position select 0) + (sin (direction _unit) * 0.8)];
	_position set [1, (_position select 1) + (cos (direction _unit) * 0.8)];
	_z = [_unit] call CBA_fnc_realHeight;
	_position set [2,_z];

	_scope = _scopeType createVehicle _position;
	_unit reveal _scope;
	_scope setDir (direction _unit);
	_scope setPos _position;
};

["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;

ADDON = true;
