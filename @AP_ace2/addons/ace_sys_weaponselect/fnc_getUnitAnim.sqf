#include "script_component.hpp"
private ["_anim","_w","_wpnstr"];
_anim = toArray(toLower(animationState _this));
_w = -1;
if (vehicle _this != _this) then
{
	_w = 0;
} else {
	if ((animationState _this) == "ACE_launcherProne") exitWith {_w = 2};
	if (count _anim < 20) exitWith {_w = 0};
	_wpnstr = toString [_anim select 16, _anim select 17, _anim select 18, _anim select 19];
	_w = switch (toLower _wpnstr) do
	{
		case "wrfl": { 0 };
		case "wpst": { 1 };
		case "wlnr": { 2 }; // was 0, but why?
		case "wbin": { 0 };
		default { -1 };
	};
};
_w