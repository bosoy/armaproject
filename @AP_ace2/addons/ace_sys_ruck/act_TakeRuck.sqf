//#define DEBUG_MODE_FULL
#include "script_component.hpp"

/* Called by object action (Cannot be a function). Will now use getWeaponCargo (Locality?)
	If possible, will give player the ruck and remaining ruck crate contents.
	Now relies on reverse ruck lookup
*/
private ["_orgRuck", "_orgPack", "_magGet", "_wepGet", "_magAry", "_pshd", "_wepAry", "_ruckcrateCls", "_rcCnt", "_volume"];
PARAMS_4(_crate,_unit,_actID,_args);

//get free slots
_weapon_on_back = _unit getVariable ["ACE_weapononback",""];
_secondary_slot = secondaryWeapon _unit;
_free_slot = switch (true) do {
	case ( _secondary_slot == "" ): {1};
	case ( _weapon_on_back == "" ): {2};
	default {0};
};

if ( _free_slot != 0 && {!(_unit call FUNC(hasRuck))} ) then {
	_orgRuck = _args;
	_orgPack = getNumber(__CONF_WEAPONS >> _orgRuck >> "ACE_PackSize");
	if (_orgPack == 0) then {
		_ruckcrateCls = toArray(typeOf _crate);
		_rcCnt = count _ruckcrateCls;
		for "_x" from (_rcCnt - 6) to (_rcCnt - 1) do {
			_ruckcrateCls set [_x, nil];
		};
		_orgRuck = toString(_ruckcrateCls);
		_orgPack = getNumber(__CONF_WEAPONS >> _orgRuck >> "ACE_PackSize");
		if (_orgPack == 0) then {
			_orgRuck = "ACE_CharliePack";
			_orgPack = getNumber(__CONF_WEAPONS >> _orgRuck >> "ACE_PackSize");
		};
	};
	//format getTocargo	
	_magGet = getMagazineCargo _crate;
	_wepGet = getWeaponCargo _crate;
	_volume = 0;
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
		_volume = _volume + (getNumber(__CONF_MAGAZINES >> _mag >> "ACE_Size") * _cnt); 
	};
	_wepAry = [];
	for "_x" from 0 to ((count (_wepGet select 0)) - 1) do {
		private ["_wep", "_cnt"];
		_wep = (_wepGet select 0) select _x;
		_cnt = (_wepGet select 1) select _x;
		_pshd = [_wep, _cnt];
		PUSH(_wepAry,_pshd);
		_volume = _volume + (getNumber(__CONF_WEAPONS >> _wep >> "ACE_Size") * _cnt);
	};
	
	if (_volume <= _orgPack) then {
		//Add Ruck to Slot
		if ( _free_slot == 2 ) then {
			_unit setVariable ["ACE_weapononback", _orgRuck, true];
		} else {
			_unit addWeapon _orgRuck;
		};
		//Add Contents
		_unit setvariable ["ACE_RuckMagContents", _magAry];
		_unit setvariable ["ACE_RuckWepContents", _wepAry];
		//Cleanup
		deleteVehicle _crate;
	} else {
		[localize "STR_ACE_SYS_RUCK_CRATE_OVER", [1,0,0,1], 1, 10] spawn ace_fnc_visual;
	};
} else {
	[localize "STR_ACE_SYS_RUCK_ROOM", [1,0,0,1], 1, 10] spawn ace_fnc_visual;
};
