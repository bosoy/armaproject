//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_4(_unit,_weapon,_muzzle,_ammoCount);

_unit setVariable [QGVAR(jammed),_muzzle,true];

private ["_actionId"];
_actionId = -1;
if (getNumber (configFile >> "CfgActions" >> "LoadEmptyMagazine" >> "showwindow") == 1) then {
	#define ACE_TEXT_ORANGE(Text) ("<t color='#ffa500'>" + ##Text + "</t>")
	_actionId = _unit addAction [ACE_TEXT_ORANGE(localize "STR_ACE_JAMCLEARACT"), QPATHTO_F(action_unjam)];
};

_handle = [
	{ /* Run code */
		(vehicle player) setWeaponReloadingTime [player, _muzzle, 1];
		
		// Don't run forever if player has dropped weapon
		if !(_weapon in (weapons (vehicle player))) then {
			_outTime = _outTime + (time - _prevTime);
		};
		_prevTime = time;
	},
	[ /* Parameters */
		_unit,
		_weapon,
		_muzzle,
		_ammoCount,
		_actionId
	],
	0, /* Delay */
	{ /* Init code */
		_unit = _this select 0;
		_weapon = _this select 1;
		_muzzle = _this select 2;
		_ammoCount = _this select 3;
		_actionId = _this select 4;
		
		_outTime = 0;
		_prevTime = time;
	},
	{ /* Exit code */
		_unit setVariable [QGVAR(jammed),nil,true];
		_unit setVariable [QGVAR(unjammed),nil,true];
		if ((alive player) && {(_unit == vehicle player)}) then {
			(localize "STR_ACE_JAMCLEAR") spawn ace_fnc_visual;
		};
		if (_actionId > -1) then {_unit removeAction _actionId};
		GVAR(jammed) = false;
	},
	{ /* Run condition - default true */
		true
	},
	{ /* Exit condition */
		!((alive player) && {_outTime < 3} && {_unit == vehicle player} && {isNil {_unit getVariable QGVAR(unjammed)}} && {(vehicle player) ammo _muzzle <= _ammoCount})
	},
	[ /* Private variables, available throughout all states and conditions */
		"_unit","_weapon","_muzzle","_ammoCount","_actionId",
		"_outTime","_prevTime"
	]
] call cba_common_fnc_addPerFrameHandlerLogic;
