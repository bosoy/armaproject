//In each unit's init write:
//nul = [this] execVM "goggles.sqf";

if (isDedicated) exitWith {};

_unit = _this select 0;
if (local player) then { if (player != _unit) exitWith {}; };
//_unit setVariable ["ACE_Identity", "ACE_Original_Identity"];
 
[_unit, "ACE_GlassesLHD_glasses"] execFSM "x\ace\addons\sys_goggles\use_glasses.fsm";