#include "script_component.hpp"
#define DO_INFO [0] call FUNC(menu_dac)
#define DO_MENU [] spawn COMPILE_FILE(menu_bc)
#define DAC_DEFAULT_CAMPS [2,2,50,0,100,10]
#define DAC_DEFAULT_AIR [2, 2, 8]

switch (_this select 0) do {
	// Hint current settings
	case 0: {
		hint str(GVAR(DAC_Settings));
	};

	// Save DAC Zone
	case 1: {
		// TODO: Add Sanity checks - zone size versus if there are tanks/air/camps selected, etc?
		_ar = [0, GVAR(DAC_SIDE), 0, call compile str(GVAR(DAC_Settings))]; // Dupplicate the DAC_Settings so that the arrays don't link anymore.
		_bla = []; { PUSH(_bla,_x) } forEach GVAR(zone_pos); _ar set [0, _bla];
		_bla = []; { PUSH(_bla,_x) } forEach GVAR(zone_size); _ar set [2, _bla];
		_bla = []; { PUSH(_bla,_x) } forEach (GVAR(AI) select 1); _ar set [5, [GVAR(AI) select 0, _bla]];
		_ar call FUNC(addZone);
		hint format["Zone added: %1", _ar];
		DO_MENU;
	};

	// Switch between Camp/Air
	case 5: {
		if (count (GVAR(DAC_Settings) select DACAIR) > 3) then {
			// camps
			GVAR(DAC_Settings) set [DACAIR, DAC_DEFAULT_AIR];
			hint "Swapped to Air";
		} else {
			// air
			GVAR(DAC_Settings) set [DACAIR, DAC_DEFAULT_CAMPS];
			hint "Swapped to Camps";
		};
		DO_INFO;
		DO_MENU;
	};

	// Switch On/Off
	case 10: {
		_idx = _this select 1;
		_ar = GVAR(DAC_Settings) select _idx;
		if (count _ar > 0) then {
			GVAR(DAC_Settings) set [_idx, []];
			hint "Disabled";
		} else {
			GVAR(DAC_Settings) set [_idx, GVAR(DAC_Settings_Default) select _idx];
			hint "Enabled";
		};
		DO_INFO;
		DO_MENU;
	};

	// Set generic atm
	case 11: {
		_data = _this select 1;
		_idx = (_data select 1) select 1;
		_ar = GVAR(DAC_Settings) select _idx;
		_ar set [(_data select 1) select 0, _data select 0];
		DO_INFO;
		// DO_MENU; - , "noclose" instead
	};

	// Set zoneID
	case 12: {
		_ar = GVAR(DAC_Settings) select 0;
		_ar set [0, _this select 1];
		DO_INFO;
		// DO_MENU; - , "noclose" instead
	};

	// Switch between waypointOnly-Full
	case 13: {
		_idx = _this select 1;
		_ar = GVAR(DAC_Settings) select _idx;
		if (count _ar > 1) then {
			GVAR(DAC_Settings) set [_idx, [10]];
			hint "Switched to WaypointOnly";
		} else {
			GVAR(DAC_Settings) set [_idx, GVAR(DAC_Settings_Default) select _idx];
			hint "Switched to Full";
		};
		DO_INFO;
		DO_MENU;
	};


	// Set side inside DACSIDE (5)
	case 21: {
		GVAR(DAC_SIDE) = _this select 1;
		_ar = GVAR(DAC_Settings) select DACSIDE;
		_ar set [0, GVAR(DAC_SIDE)];
		// For now - also set behaviour, unitconfig and camp together with side.
		_ar set [1, GVAR(DAC_SIDE)];
		_ar set [2, GVAR(DAC_SIDE)];
		_ar set [3, GVAR(DAC_SIDE)];
		DO_INFO;
		DO_MENU;
	};
	// Set unitconfig
	case 22: {
		_ar = GVAR(DAC_Settings) select DACSIDE;
		_ar set [1, _this select 1];
		DO_INFO;
	};
};
