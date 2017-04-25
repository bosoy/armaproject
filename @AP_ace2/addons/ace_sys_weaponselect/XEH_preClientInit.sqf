#include "script_component.hpp"
#define __enableF (["ACE", "ACE_WEAPONSELECT", "firemodes_only"] call ace_settings_fnc_getNumber)
ADDON = false;

LOG(MSG_INIT);

PREP(keypressed);
PREP(keypressed_veh);
PREP(keypressed_F);
PREP(hasGL);
PREP(hasStuff);
PREP(throwputmuzzles);
PREP(getunitanim);
PREP(GL_sight);
PREP(GL_sight_alt); //safer alternative, ammo count not preserved
PREP(changeLight);

GVAR(Fdown) = false;
GVAR(GLinprogress) = false;
GVAR(LastUseSoundLogic) = -3;
GVAR(SwitchSound) = {
	private "_t";
	_t = time - GVAR(LastUseSoundLogic);
	GVAR(LastUseSoundLogic) = time;
	if (_t >= 3 ) then {
		GVAR(logic) attachto [player,[0,0,0],"righthand"];
		0 spawn {
			waituntil {time - GVAR(LastUseSoundLogic) >= 3};
			detach GVAR(logic);
			GVAR(logic) setpos [0,0,200];
		};
	};
	GVAR(logic) say _this;
};

FUNC(clientGetOut) = {
	PARAMS_3(_x,_y,_unit);
	_data = _unit getVariable [QGVAR(safety),[]];
	if (count _data < 2) exitWith {};
	if (_data select 1) then {
		if (primaryWeapon player != "" && {currentWeapon player == _data select 0}) then {
			if !(player hasweapon "ace_safe") then { player addweapon "ace_safe" };
			player setVariable [QGVAR(safety),[(currentWeapon player),true]];
			player selectweapon "ace_safe";
		} else { player setVariable [QGVAR(safety),[]] };
	};
};


[QUOTE(ADDON), "Safe", { [_this, -1] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Rifle", { [_this, 0] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "GL", { [_this, 1] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Throw", { [_this, 2] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Launcher", { [_this, 3] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Gunlight_Change", { [_this, 4] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;

[QUOTE(ADDON), "Firemodes", {if (__enableF == 1) then { _this call FUNC(keypressed_F) } else {false} }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Firemodes", {if (__enableF == 1) then { GVAR(Fdown) = false; true } else {false}},"keyup"] call CBA_fnc_addKeyHandlerFromConfig;

[QUOTE(ADDON), "Vehicle_Safe", { [_this, -1] call FUNC(keypressed_veh) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Vehicle_Main", { [_this, 0] call FUNC(keypressed_veh) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Vehicle_Launcher", { [_this, 1] call FUNC(keypressed_veh) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Vehicle_Other", { [_this, 2] call FUNC(keypressed_veh) }] call CBA_fnc_addKeyHandlerFromConfig;

[QGVAR(gesture), {_this playAction "gesturePoint"}] call CBA_fnc_addEventHandler;

PREP(keypressed_B);
PREP(getBinoculars);
GVAR(KP_B) = ["KeyDown", QUOTE(_this call FUNC(keypressed_B))] call CBA_fnc_addDisplayHandler;

ADDON = true;
