/* ace_sys_groundmarker | (c) 2010,2011,2012 by rocko */

#include "script_component.hpp"

PARAMS_2(_panel,_type);

private ["_anim","_value","_isFlipped","_isTurned","_isCamo","_hasCL","_fnc_turnCL"];

_isFlipped = (_panel animationPhase "flip") == 1;
_isTurned = (_panel animationPhase "rotate") == 1;
_isCamo = (_panel animationPhase "camo") == 0;
_hasCL = _panel getVariable [QGVAR(hasCL),false];
_fnc_turnCL = {
	private ["_panel","_anim","_value"];
	_panel = _this select 0;
	_anim = _this select 1;
	_value = _this select 2;
	_knicklicht_attach = _panel getVariable [QGVAR(CL),objNull];
	if (!isNull _knicklicht_attach) then {
		waitUntil { _panel animationPhase _anim == _value };
		_knicklicht_attach attachTo [_panel,[0,0,0],"clp1"];
	};
};

switch (_type) do {
	case 0: {
		_anim = "rotate";
		if (typeOf _panel == "ACE_VS17PANEL") then {
			_value = if (_isTurned) then {0} else {1};
		} else {
			_value = _panel animationPhase _anim;
			switch (_value) do {
				case 0: { _panel setVariable [QGVAR(mrt),false,true] };
				case 1: { _panel setVariable [QGVAR(mrt),true,true] };
				default {};
			};
			if !(_panel getVariable [QGVAR(mrt),false]) then { ADD(_value,0.25) } else { SUB(_value,0.25) }; 
		};
		_panel animate [_anim,_value];
		if (_hasCL) then { [_panel,_anim,_value] spawn _fnc_turnCL; }; 
	};
	case 1: {
		_value = if (_isFlipped) then {0} else {1};
		{ _panel animate [_x,_value]; } foreach ["flip","hide"];
		if (_hasCL) then { [_panel,"flip",_value] spawn _fnc_turnCL; }; 
	};
	case 2: {
		if (_isCamo) then { _panel animate ["camo",1]; } else { _panel animate ["camo",0]; }; 
	};
};
