//In each unit's init write:
//nul = [this] execVM "earplugs.sqf";

if (isDedicated) exitWith {};

_unit = _this select 0;

waitUntil {_unit == player};

if (_unit hasWeapon "ACE_Earplugs") then {
	[_unit] execFSM "\x\ace\addons\sys_goggles\use_earplug.fsm";
};