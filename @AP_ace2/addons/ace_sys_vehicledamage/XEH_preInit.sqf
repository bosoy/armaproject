#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

ace_v_alive = COMPILE_FILE(isvehalive);

PREP(incoming_missile);
PREP(shtora);
PREP(shtora_targeted);
PREP(targeted);
PREP(alarm);
PREP(weaponDir);
PREP(verifyWeaponDir);
["ace_lasertarget", { if !((_this select 1) isKindOf "CAManBase") then { _this call FUNC(targeted) } }] call CBA_fnc_addEventHandler;
if !(isDedicated) then
{
	[QGVAR(alarm), { _this call FUNC(alarm) }] call CBA_fnc_addEventHandler;
};

PREP(shooter_direction);
PREP(sethit);
PREP(addhit);
PREP(setvar);
PREP(getpartname);
PREP(threshold);
PREP(set_ko);
PREP(burn);
PREP(playsound);
PREP(playsound_electricspark);
PREP(mat_cos3Dvec);
PREP(injurecrew);
PREP(injureman);
PREP(killcrew);
PREP(burnindicator);
PREP(rep_tracks_n_wheels);
PREP(killengine);
PREP(fullrepair);

PREP(tank_add_hdeh);
PREP(tank_hd);
PREP(tank_setfx);
PREP(tank_getarmor);
PREP(tank_deploysmoke);
PREP(tank_abandon);
PREP(tank_analyzedamage);
PREP(tank_startfire);
PREP(tank_fireloop);
PREP(tank_modifypart);
PREP(t72_catastrophicdestruction);

PREP(wAPC_add_hdeh);
PREP(wAPC_hd);
PREP(wAPC_setFX);
PREP(wAPC_hitpart);
PREP(wAPC_modifypart);

PREP(heli_add_hdeh);
PREP(heli_hd);

PREP(AA_missile);

PREP(survival);

// [p1,"turret"] call ace_sys_vehicledamage_fnc_detonate
FUNC(detonate) = {
	// huh ? A function which spawns a script inside and does nothing else ?
	_this spawn {
		#define __cfgMag configfile>>"cfgMagazines">>_mag
		#define __cfgAmmo configfile>>"cfgAmmo">>_ammo
		private ["_s","_ammo"];
		PARAMS_2(_u,_p);
		//if !(alive _u) exitwith {};
		[_u,_p,1,_u,_u] call FUNC(tank_startfire);
		_ammo = switch (_p) do {
			case "engine": { //fuel explosion
				"ace_fuelexpbig"
			};
			default	{ //ammo explosion fur turret und hull ja
				"ace_fuelexpsmall"
			};
		};
		_s = _ammo createvehicle (_u modeltoworld [0,0,0.7]);
		_s setpos (_u modelToWorld [-0.5+random 1,-0.5+random 1,0.5+random 1]);
		_s setvelocity [0,0,-100];
		sleep 0.3;
		_u setdamage 1;
	};
};

// Overall switch, useful for testing
if (isNil 'GVAR(enabled)') then { GVAR(enabled) = true };

FUNC(enabled) = {
	if !(GVAR(enabled)) exitWith { false };

	private ["_cfg"];
	PARAMS_1(_unit);
	_cfg = configFile >> "cfgVehicles" >> typeof _unit;
	if !(isNumber(_cfg >> "ace_era")) exitwith { false };
	if (isNumber(_cfg >> "ace_dmgsys_enable") && {getNumber(_cfg >> "ace_dmgsys_enable") == 0}) exitwith { false };
	if !(_unit getVariable [QGVAR(enable), true]) exitWith { false };
	true;
};

FUNC(survival_add_hdeh) = {
	//(vehicle (_this select 0)) allowCrewInImmobile true; // TODO: Make driver of type CAR vehicle exit on immobility kill and have the gunner defend the shit ... Needs lotta scripting stuff
	(_this select 0) setVariable [QGVAR(hdeh), (_this select 0) addEventHandler ["HandleDamage", { _this call FUNC(survival) }]];
};

FUNC(handleAmmoTrucks) = {
	_vic = _this select 0;
	_ammosize = getNumber(configFile >> "CfgVehicles" >> (typeOf _vic) >> "transportammo");
	if (_ammosize > 3000) then {
		["ace_sys_destruction_engineBurn", [_vic]] call CBA_fnc_globalEvent;
	};
};

[QGVAR(hide_turret), { PARAMS_3(_vehicle,_selection,_texture); _vehicle setObjectTexture [_selection,_texture]; }] call CBA_fnc_addEventhandler;

[QGVAR(eject), { PARAMS_2(_vehicle,_units); { if (local _x) then { unassignVehicle _x; _x action ["eject", _vehicle] } } forEach _units }] call CBA_fnc_addEventhandler;

[QGVAR(handle_eh), {
	private "_eh";
	_eh = _this addeventhandler ["engine",{ if (local (_this select 0)) then {if (_this select 1) then {(_this select 0) setfuel 0}} }];
	_this setvariable ["ace_d_blockengine",_eh];
}] call CBA_fnc_addEventHandler;

[QGVAR(handle_remove_eh), {
	private "_eh";
	_eh = _this getvariable "ace_d_blockengine";
	if !(isNil "_eh") then {
		_this removeeventhandler ["engine",_eh];
		_this setvariable ["ace_d_blockengine",nil];
	};
}] call CBA_fnc_addEventHandler;


[QGVAR(handle_injurecrew), {
	{if (local _x) then {[_x] spawn ace_sys_vehicledamage_fnc_injureman}} foreach _this;
}] call CBA_fnc_addEventHandler;

[QGVAR(handle_killcrew), {
	{if (local _x) then {[_x, 1] call ace_sys_wounds_fnc_prdamcheck}} foreach _this;
}] call CBA_fnc_addEventHandler;

[QGVAR(burn), {_this spawn ace_sys_vehicledamage_fnc_burn}] call CBA_fnc_addEventHandler;
[QGVAR(fire), {_this spawn ace_sys_vehicledamage_fnc_tank_fireloop}] call CBA_fnc_addEventHandler;

if !(isDedicated) then
{
	[QGVAR(handle_playsound), {
		if (player in (_this select 0)) then {playsound (_this select 1)};
	}] call CBA_fnc_addEventHandler;

	[QGVAR(handle_playsound_electricspark), {
		if ((player in (_this select 0)) && {(cameraView in ["GUNNER","INTERNAL"])}) then {playSound (_this select 1)};
	}] call CBA_fnc_addEventHandler;
};

GVAR(plrinburn) = false;

[QGVAR(lock), {(_this select 0) lock (_this select 1)}] call ACE_fnc_addReceiverOnlyEventhandler;

ADDON = true;
