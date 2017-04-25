#include "script_component.hpp"
private ["_anim","_w","_wpnstr"];
_anim = toArray(toLower(animationState _this));
_w = 0;
if (vehicle _this != _this) then
{
	_w = 0;
} else {
	//if(_anim == "ACE_launcherProne") exitWith {_w = 0};
	if (count _anim < 20) exitWith {_w = 0};
	_wpnstr = toString [_anim select 16, _anim select 17, _anim select 18, _anim select 19];
	_w = switch (toLower _wpnstr) do
	{
		case "wrfl": { 0 }; //rifle
		case "wpst": { 1 }; //pistol
		case "wlnr": { 2 }; //launcher
		case "wbin": { 3 }; //binocular
		default { 0 };
	};
};
_w