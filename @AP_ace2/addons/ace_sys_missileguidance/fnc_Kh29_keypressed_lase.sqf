#include "script_component.hpp"
private ["_veh"];

_veh = vehicle player;

if !(_veh isKindOf "Su25_Base" || {_veh isKindOf "Plane_LG"} || {_veh isKindOf "Su34"} || {_veh isKindOf "ACE_Su30"}) exitwith {false};
if !(getNumber(configFile>>"cfgWeapons">>currentWeapon _veh>>QGVAR(enableAirDesignator)) == 1) exitwith {false};
if (GVAR(presstime_Kh29) == time) exitWith {false};
if (GVAR(Kh29_lasinginprogress)) exitWith {false};
GVAR(Kh29_lasinginprogress) = true;
GVAR(presstime_Kh29) = time;
if (count _this >= 3) then {[_veh,_this select 1,_this select 2] call FUNC(Kh29_LasePFH)} else {[_veh,0,0] call FUNC(Kh29_LasePFH)};

true