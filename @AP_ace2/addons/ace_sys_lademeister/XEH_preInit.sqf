/* ace_sys_lademeister (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

//#define __KNL ["ACE_Knicklicht_IR","ACE_Knicklicht_R","ACE_Knicklicht_B","ACE_Knicklicht_G","ACE_Knicklicht_W","ACE_Knicklicht_Y","ACE_Knicklicht_IR_Used","ACE_Knicklicht_R_Used", "ACE_Knicklicht_W_Used", "ACE_Knicklicht_G_Used", "ACE_Knicklicht_Y_Used", "ACE_Knicklicht_B_Used"]
//#define __GAS ["ACE_M7A3"]
//#define __SMOKE []
//#define __HG ["HandGrenade","HandGrenade_West","HandGrenade_East"]
//#define __MAGS (__KNL + __SMOKE + __HG)
ADDON = false;

LOG(MSG_INIT);

PREP(cam);
PREP(init);
PREP(getIn);
PREP(getOut);

GVAR(ADDMOUSEMOVEMENT) = { GVAR(MM) = ["MouseMoving", "_this call ACE_SYS_LADEMEISTER_MOUSE"] call CBA_fnc_addDisplayHandler; };
GVAR(REMOVEMOUSEMOVEMENT) = { ["MouseMoving", GVAR(MM)] call CBA_fnc_removeDisplayHandler; };
GVAR(ADDKEYPRESS) = { GVAR(KP) = ["KeyDown", "_this call ACE_SYS_LADEMEISTER_KEYPRESS"] call CBA_fnc_addDisplayHandler; };
GVAR(REMOVEKEYPRESS) = { ["KeyDown", GVAR(KP)] call CBA_fnc_removeDisplayHandler; };
GVAR(X) = 0;
GVAR(Y) = 0;
GVAR(MOUSE) = {
	_dataX = (_this select 1) / 10;
	GVAR(X) = GVAR(X) + _dataX; if (GVAR(X) > 75) then { GVAR(X) = 75; }; if (GVAR(X) < -75) then { GVAR(X) = -75; };
	_dataY = (_this select 2)*([-1,1] select reversedMouseY);
	GVAR(Y) = GVAR(Y) + _dataY; if (GVAR(Y) > 90) then { GVAR(Y) = 90; }; if (GVAR(Y) < -90) then { GVAR(Y) = -90; };
};

_throw_array = [
	"HandGrenade_Stone","HandGrenadeMuzzle","SmokeShellMuzzle",
	"ACE_SmokeShellMuzzle_RU",
	//"ACE_IRStrobeMuzzle",
	//"ACE_M86PDMMuzzle",
	//"ACE_FlashbangMuzzle",
	//"ACE_TeargasMuzzle",
	//"ACE_WPMuzzle",
	"ACE_KnicklichtMuzzle",
	"ACE_Knicklicht_UsedMuzzle"
];
private "_tmp";
_tmp = [];
{
	_ar = getArray(configFile >> "CfgWeapons" >> "Throw" >> _x >> "magazines");
	_tmp = _tmp + _ar;
} foreach _throw_array;
GVAR(trhow) = _tmp;

GVAR(KEYPRESS) = {
	if !((vehicle player) isKindOf "Helicopter") exitWith { TRACE_1("No helicopter",""); false; };
	if (cameraView in ["EXTERNAL","GROUP"]) exitWith { TRACE_1("Not in 1st person",""); false; };
	if !(((assignedVehicleRole player) select 0) == "TURRET") exitWith { TRACE_1("No gunner",""); false; };

	// W
	if ((_this select 1) in (actionKeys "MoveForward")) then {
		if (isNil QGVAR(RUNNING)) then { GVAR(RUNNING) = false; };
		if !(GVAR(RUNNING)) then { call FUNC(cam); };
		GVAR(ABORT) = false;
	};

	// S
	if ((_this select 1) in (actionKeys "MoveBack")) then {
		GVAR(ABORT) = true; player setVariable [QGVAR(lm_knl_pressed),false,false];
	};

	// ToggleWeapons
	// Only chemlights for now
	if (GVAR(RUNNING) && {(_this select 1) in (actionKeys "toggleWeapons")}) then {
		_local_magazines = [];
		_magazines = magazines player;
		{
			if (_x in _magazines) then { _local_magazines set [(count _local_magazines), _x]; };
		} foreach GVAR(trhow);

		GVAR(choices) = count _local_magazines;
		if (GVAR(choices) == 0) exitWith { false };
		_pressed = player getVariable QGVAR(lm_knl_pressed);
		if (isNil "_pressed") then { _pressed = false; player setVariable [QGVAR(lm_knl_pressed),true,false]; };
		if (_pressed) then {
			_tmp = player getVariable QGVAR(lm_knl_count); // + 1 doenst work ?
			_tmp = _tmp + 1;
			player setVariable [QGVAR(lm_knl_count),_tmp,false];
		} else { player setVariable [QGVAR(lm_knl_count),1,false]; };

		_number = player getVariable QGVAR(lm_knl_count);
		if (_number > GVAR(choices)) then { player setVariable [QGVAR(lm_knl_count),1,false]; _number = 1; };
		GVAR(sel) = _local_magazines select (_number - 1);
		GVAR(name) = getText(configFile >> "CfgMagazines" >> GVAR(sel) >> "displayName");
		GVAR(name) spawn ace_fnc_visual;
	};

	// SPACEBAR
	if (GVAR(RUNNING) && {(_this select 1) == 57}) then {
		if (isNil QGVAR(sel)) exitWith { false };
		if !(GVAR(sel) in _local_magazines) exitWith { false };
		if (GVAR(sel) in (magazines player)) then {
			player removeMagazine GVAR(sel);
			_ammo = getText(configFile >> "CfgMagazines" >> GVAR(sel) >> "ammo");
			_simulation = getText(configFile >> "CfgAmmo" >> _ammo >> "ACE_Simulation");

			_speed = (velocity (vehicle player)) call ACE_fnc_magnitude;
			_emitPos0 = positionCameraToWorld [0,0,0];
			_emitPos1 = positionCameraToWorld [0,0,10];
			_vector = [_emitPos0,_emitPos1] call ACE_fnc_vectorFromXToY;
			_velocity = [_vector,20] call ACE_fnc_vectorMultiply;
			_sexvelocity = [_velocity, (velocity (vehicle player))] call ACE_fnc_vectorAdd;
			_object = _ammo createVehicle [(getPos player select 0), (getPos player select 1), (getPos player select 2) - 3];
			_object setVelocity _sexvelocity;

			//_object spawn { while { alive _this } do { sleep 0.1; diag_log (velocity _this); }; };

			[_simulation,_ammo,_object] spawn {
				PARAMS_3(_simulation,_ammo,_object);
				//_object setVelocity [0,0, -9.81];
				switch (toLower _simulation) do {
					case "shotknicklicht": { [player,"","","",_ammo,_object] spawn ace_sys_knicklicht_fnc_fired };
					case "shotsmoke":  { [player,"","","",_ammo,_object] spawn ace_sys_viewblock_fnc_fired };
					//case "shotcs": { [player,"","","",_ammo,_object] spawn ace_sys_gas_fnc_fired_gas };
					//case "shotwp": {};
					//case "shotflashbang": {};
				};
			};
			GVAR(sel) = nil;
		};
	};
	false;
};

ADDON = true;
