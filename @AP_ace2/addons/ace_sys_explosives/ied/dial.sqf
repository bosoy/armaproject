/* ace_sys_explosives | IED Phone | (c) 2012 by rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

disableSerialization;

#define __dsp (uiNamespace getVariable QGVAR(CELLPHONE_MENU))
#define __ctrl (__dsp displayCtrl _idc)

// 1000 = Display
private "_element";

PARAMS_2(_mine,_key);

_currentNumberOnDisplay = uiNameSpace getVariable QGVAR(CELLPHONE_CUR_NUM);
if (isNil "_currentNumberOnDisplay") then {
	_currentNumberOnDisplay = "";
	(__dsp displayCtrl 1000) ctrlSetText "";
};

TRACE_2("",_key,(typeName _key));

if (_key in ["1","2","3","4","5","6","7","8","9","0"]) then {
	_currentNumberOnDisplay = _currentNumberOnDisplay + _key;
	(__dsp displayCtrl 1000) ctrlSetText _currentNumberOnDisplay;
	uiNameSpace setVariable [QGVAR(CELLPHONE_CUR_NUM),_currentNumberOnDisplay];
};

if (_key == "CLEAR") then {
	_currentNumberOnDisplay = uiNameSpace getVariable QGVAR(CELLPHONE_CUR_NUM);
	if (_currentNumberOnDisplay == "") exitWith {};
	_currentNumberOnDisplay_Ar = toArray _currentNumberOnDisplay;
	_currentNumberOnDisplay_Ar = _currentNumberOnDisplay_Ar - [_currentNumberOnDisplay_Ar select ((count _currentNumberOnDisplay_Ar)-1)];
	_currentNumberOnDisplay = toString _currentNumberOnDisplay_Ar;
	(__dsp displayCtrl 1000) ctrlSetText _currentNumberOnDisplay;
	uiNameSpace setVariable [QGVAR(CELLPHONE_CUR_NUM),_currentNumberOnDisplay];	
};

if (_key == "DIAL") then {
	_currentNumberOnDisplay = uiNameSpace getVariable QGVAR(CELLPHONE_CUR_NUM);
	{
		// TODO: Add a delay for the connection to become established
		// TODO: Funkloch ?
		// TODO: Signalstrength on certain locs, depending on stuff, ACRE?
		// TODO: Jam mobile / Jam IED itself
		_element = _x; // [number,ied]
		if (_currentNumberOnDisplay == (_element select 0)) then {
			_mine = _element select 1;
			sleep 2;
			sleep random 3;
			["","",-1,_mine] call FUNC(detonate_IED);
		};
	} foreach GVAR(ied_phonenumbers);
	// Clean up slowly
	sleep 5;
	sleep random 5;
	_tmp_ied_phonenumbers = [];
	for "_i" from 0 to ((count GVAR(ied_phonenumbers))-1) do {
		_element_ar = GVAR(ied_phonenumbers) select _i;
		_number = _element_ar select 0;
		if (_number != _currentNumberOnDisplay) then {
			_tmp_ied_phonenumbers set [count _tmp_ied_phonenumbers, _element_ar];
		};
	};
	GVAR(ied_phonenumbers) = _tmp_ied_phonenumbers;
	publicVariable QGVAR(ied_phonenumbers);	
};
