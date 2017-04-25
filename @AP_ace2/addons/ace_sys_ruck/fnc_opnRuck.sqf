//#define DEBUG_MODE_FULL
#include "script_component.hpp"

/* Access Dead dropped rucks.
	Now uses getWeaponCargo, but currently uses an older method than manually dropped rucks.
	Ruck crates not used.
*/
private ["_unit", "_objs", "_wephld", "_body", "_ruckNam", "_def", "_ruckAry", "_magAry", "_wepAry", "_unitpos", "_dummy", "_magGet", "_wepGet", "_pshd"];
_unit = _this select 0;
_objs = _this select 3;
_wephld = _objs select 0;
_body = _objs select 1;
_ruckNam = _objs select 2;

if (local _unit && {(_body hasWeapon _ruckNam)}) then {
	[QGVAR(glbRuckAR), [_body,_ruckNam,true]] call CBA_fnc_globalEvent;
//grab object PV contents array
	_ruckAry = _wephld getVariable ["ACE_RuckContents",[[],[]]];
	TRACE_1("dRuck Open",_ruckAry);
	_magAry = _ruckAry select 0;
	_wepAry = _ruckAry select 1;
//create empty gear box
	_unitpos = position _unit;
	_dummy = "ACE_EmptyBox" createVehicleLocal [_unitpos select 0, _unitpos select 1, 0];
    _dummy setPos [_unitpos select 0, _unitpos select 1, -5]; //hide underground
	_unit reveal _dummy; // Handles delays in MP?
	clearMagazineCargo _dummy;
	clearWeaponCargo _dummy;
	_dummy allowDamage false;
//remove all and add from array
	{_dummy addMagazineCargo [_x select 0, _x select 1]} forEach _magAry;
	{_dummy addWeaponCargo _x} forEach _wepAry;
//open dialog
	_unit action ["GEAR",_dummy];
	waitUntil{dialog};
	waitUntil{!dialog};
	_magGet = getMagazineCargo _dummy;
	_wepGet = getWeaponCargo _dummy;
	TRACE_2("Get",_magGet,_wepGet);
//format getTocargo
	_magAry = [];
	for "_x" from 0 to ((count (_magGet select 0)) - 1) do {
		private ["_mag", "_cnt", "_nnar"];
		_mag = (_magGet select 0) select _x;
		_cnt = (_magGet select 1) select _x;
		_nnar = [];
		_ammoc = getNumber(configFile>>"CfgMagazines">>_mag>>"count");
		for "_o" from 1 to _cnt do {
			_nnar set [count _nnar, _ammoc];
		};
		_pshd = [_mag, _cnt, _nnar];
		PUSH(_magAry,_pshd);
	};
	_wepAry = [];
	for "_x" from 0 to ((count (_wepGet select 0)) - 1) do {
		_pshd = [(_wepGet select 0) select _x, (_wepGet select 1) select _x];
		PUSH(_wepAry,_pshd);
	};
	_ruckAry = [_magAry,_wepAry];
//cleanup
	deleteVehicle _dummy;
	_wephld setVariable ["ACE_RuckContents", _ruckAry, true]; //rebroadcast object PV
	if ( count _magAry == 0 && {count _wepAry == 0} ) then { deleteVehicle _wephld; TRACE_1("Empty",_wephld); };
	[QGVAR(glbRuckAR), [_body,_ruckNam,false]] call CBA_fnc_globalEvent;
	TRACE_1("dRuck Close",_ruckAry);
};
