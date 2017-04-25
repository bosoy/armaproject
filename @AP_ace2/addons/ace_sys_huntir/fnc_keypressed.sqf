#include "script_component.hpp"

private "_ret";
_ret = false;

switch (_this select 1) do {
	// A = Lower zoom level
	case 30: {
		if (GVAR(ZOOM) > 0) then {
			GVAR(ZOOM) = GVAR(ZOOM) - 1;
		};
		switch (GVAR(ZOOM)) do {
			case 0: { ctrlSetText [4, "0X"];};
			case 1: { ctrlSetText [4, "2X"];};
			case 2: { ctrlSetText [4, "4X"];};
			case 3: { ctrlSetText [4, "8X"];};
		};
		_ret = true;
	};
	// D = Increase zoom level
	case 32: {
		if (GVAR(ZOOM) < 3) then {
			GVAR(ZOOM) = GVAR(ZOOM) + 1;
		};
		switch (GVAR(ZOOM)) do {
			case 0: { ctrlSetText [4, "0X"];};
			case 1: { ctrlSetText [4, "2X"];};
			case 2: { ctrlSetText [4, "4X"];};
			case 3: { ctrlSetText [4, "8X"];};
		};
		_ret = true;
	};
	//N key ( Toggle NV and TI modes )
	case 49: {
		if (GVAR(NV) == 0) then {
			setAperture -1;
			camUseNVG true;
			GVAR(NV) = 1;
			if (!GVAR(IRON)) then {
				GVAR(IRON) = true;
				["ace_ir_on", []] call CBA_fnc_localEvent;
			};
		} else {
			setAperture -1;
			camUseNVG false;
			GVAR(NV) = 0;
			GVAR(IRON) = false;
			["ace_ir_off", []] call CBA_fnc_localEvent; // TODO: also on death etc?
		};
		_ret = true;
	};
	// S = Next camera
	case 31: {
		if (GVAR(SELECT) < ((count GVAR(no_cams)) - 1)) then {
			GVAR(SELECT) = GVAR(SELECT) + 1;
		};
		_ret = true;
	};
	// W = Previous camera
	case 17: {
		if (GVAR(SELECT) > 0) then {
			GVAR(SELECT) = GVAR(SELECT) - 1;
		};
		_ret = true;
	};
	// Rotate camera anticlockwise
	case 203: {
		GVAR(ROTATE) = GVAR(ROTATE) - 3;
		_ret = true;
	};
	// Rotate camera clockwise
	case 205: {
		GVAR(ROTATE) = GVAR(ROTATE) + 3;
		_ret = true;
	};
	// Raise camera
	case 200: {
		if (GVAR(ELEVAT) < 4.01) then {
			GVAR(ELEVAT) = GVAR(ELEVAT) + 0.12;
		};
		_ret = true;
	};
	// Lower camera
	case 208: {
		if (GVAR(ELEVAT) > -3.99) then {
			GVAR(ELEVAT) = GVAR(ELEVAT) - 0.12;
		};
		_ret = true;
	};
	// Reset camera
	case 19: {
		GVAR(ROTATE) = 0;
		GVAR(ELEVAT) = 0.01;
		GVAR(ZOOM) = 0;
		ctrlSetText [4, "0X"];
		GVAR(NV) = 0;
		camUseNVG false;
		setAperture -1;
		_ret = true;
	};
};
_ret
