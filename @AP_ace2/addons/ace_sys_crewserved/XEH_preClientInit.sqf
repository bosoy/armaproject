#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

FUNC(getInDragon) = {
	PARAMS_3(_launcher,_pos,_unit);
	if (_unit == player) then {
		if ("ACE_M47_Daysight" in (weapons player)) then {
			GVAR(dragonLauncher) = _this select 0;
			GVAR(dragonLauncher) animate ["optic_hide", 0];
			GVAR(dragonLauncher) animate ["rest_rotate", 0];
			if(GVAR(dragonLauncher) animationPhase "missile_hide" == 0) then {
				GVAR(dragonLauncher) removeWeapon "ACE_M47StaticLauncher";
				GVAR(dragonLauncher) addMagazine "Dragon_EP1";
				GVAR(dragonLauncher) addWeapon "ACE_M47StaticLauncher";
				GVAR(dragonLauncher) selectWeapon "ACE_M47StaticLauncher";
				reload GVAR(dragonLauncher);
			};
		} else {
			player leaveVehicle (_this select 0);
			player action ["getout",(_this select 0)];
			unassignVehicle player;
		};
	};
};

FUNC(getOutDragon) = {
	PARAMS_3(_launcher,_pos,_unit);
	if (_unit == player) then {
		GVAR(dragonLauncher) animate ["optic_hide", 1];
		GVAR(dragonLauncher) animate ["rest_rotate", -0.35];
		GVAR(dragonLauncher) removeMagazines "Dragon_EP1";
		GVAR(dragonLauncher) = nil;
	};
};

FUNC(dragonLauncherFired) = {
	GVAR(dragonLauncher) animate ["missile_hide", 1];
};

FUNC(deployDragon) = {
	[5,[localize "STR_ACE_CREW_DRAGON"],false,true,player,true] spawn ace_progressbar;
	waitUntil { 
		if !(player hasWeapon "M47Launcher_EP1") then {
			player setVariable ["ACE_PB_Abort", true];
			player setVariable ["ACE_PB_Result", -1];
		};
		player getVariable "ACE_PB_Result" != 0 
	};
	_exit = (player getVariable "ACE_PB_Result" != 1);
	player setVariable ["ACE_PB_Abort", false];
	player setVariable ["ACE_PB_Result", 0];
	if(!_exit) then {
		player removeWeapon "M47Launcher_EP1";
		_pos = player modelToWorld [0,1,0];
		_pos set[2, (getPosATL player) select 2];
		_dragonLauncher = "ACE_M47_Static" createVehicle _pos;
		_dragonLauncher setDir (getDir player)-90;
		_dragonLauncher setPos _pos;
		_nearUnits = (getPos player) nearEntities ["CAManBase", 20];
		{
			_x reveal _dragonLauncher;
		} forEach _nearUnits;
	};
};

FUNC(packDragon) = {
	PARAMS_2(_unit,_dragon);
	[5,[localize "STR_ACE_CREW_UNMOUNTDRAGON"],false,true,player,true] spawn ace_progressbar;
	waitUntil {
		if (count (crew _dragon) != 0 || {secondaryWeapon player != ""}) then {
			player setVariable ["ACE_PB_Abort", true];
			player setVariable ["ACE_PB_Result", -1];
		};
		player getVariable "ACE_PB_Result" != 0 
	};
	_exit = (player getVariable "ACE_PB_Result" != 1);
	player setVariable ["ACE_PB_Result", 0];
	player setVariable ["ACE_PB_Abort", false];
	if(!_exit) then {
		deleteVehicle _dragon;
		player addWeapon "M47Launcher_EP1";
	};
};

FUNC(dragonMonitorInventory) = {
	if (secondaryWeapon player == "M47Launcher_EP1") then {
		if (!("ACE_M47_Daysight" in (weapons player)) && {"Dragon_EP1" in (magazines player)}) then {
			player removeMagazines "Dragon_EP1";
			player addWeapon "ACE_M47_Daysight";
		};
	};
	if (secondaryWeapon player != "M47Launcher_EP1") then {
		if ("Dragon_EP1" in (magazines player)) then {
			player removeMagazines "Dragon_EP1";
			if (secondaryWeapon player == "") then {
				player addWeapon "M47Launcher_EP1";
			};
		};
	};
};

["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;

ADDON = true;
