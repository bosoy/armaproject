//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private["_display", "_key", "_shift", "_ctrl", "_alt"];
PARAMS_1(_params);
_display = _params select 0;
_key = _params select 1;
_shift = _params select 2;
_ctrl = _params select 3;
_alt = _params select 4;

if (isNil QGVAR(currentDialog)) exitWith {false};
 
_handledCode = false;

GVAR(lastKeyPressed) = "-1";

// NOTE: These are hard-coded and not modifiable via ACE config
// however, they also are only applicable when the MFD is open, and override all keys in this setting
// Therefore, we are only breaking 1 thing: the default "3rd person" view when the MFD is open in a air vehicle. Oh well.

// zGuba: Not only 3rd person. Also default zoom binding [ num +/- ] is locked. Seems like design fault since these keys are needed only in one screen.

switch (_key) do {
	//NUM_0 
	case 82: {
		GVAR(lastKeyPressed) = "0";
		_handledCode = true;
	};
	// NUM_1 
	case 79 : {
		GVAR(lastKeyPressed) = "1";
		_handledCode = true;
	};
	// NUM_2 
	case 80 : {
		GVAR(lastKeyPressed) = "2";
		_handledCode = true;
	};
	// NUM_3 
	case 81 : {
		GVAR(lastKeyPressed) = "3";
		_handledCode = true;
	};
	// NUM_4 
	case 75 : {
		GVAR(lastKeyPressed) = "4";
		_handledCode = true;
	};
	// NUM_5 
	case 76 : {
		GVAR(lastKeyPressed) = "5";
		_handledCode = true;
	};
	// NUM_6 
	case 77 : {
		GVAR(lastKeyPressed) = "6";
		_handledCode = true;
	};
	// NUM_7 
	case 71 : {
		GVAR(lastKeyPressed) = "7";
		_handledCode = true;
	};
	// NUM_8 
	case 72 : {
		GVAR(lastKeyPressed) = "8";
		_handledCode = true;
	};
	// NUM_9 
	case 73 : {
		GVAR(lastKeyPressed) = "9";
		_handledCode = true;
	};
	// NUM_+ 
	case 78 : {

		_handledCode = true;
	};
	// NUM_=
	case 69 : {

		_handledCode = true;
	};
	// NUM_/ 
	case 181 : {

		_handledCode = true;
	};
	// NUM_* 
	case 55 : {

		_handledCode = true;
	};
	// NUM_- 
	case 74 : {

		_handledCode = true;
	};
	// NUM_. 
	case 83 : {

		_handledCode = true;
	};
};

if (_handledCode) then {
	TRACE_2("", GVAR(lastKeyPressed), _key);
	GVAR(lastKeyPressTime) = diag_tickTime;
	[] call FUNC(renderDisplay);
};

_handledCode
