// 2009 by Xeno

#include "script_component.hpp"

private ["_ar", "_fencenames", "_ret", "_i", "_fou", "_r", "_fencename", "_fi", "_o"];
_ar = toArray _this;
// to add more just do a diag_log toArray("WALL_FENCEX"); and add the array to fencenames (all chars uppercase)
_fencenames = [
	[87,65,76,76,95,73,78,68,70,78,67], 						// WALL_INDFNC
	[87,65,76,76,95,70,69,78,49,95,53], 						// WALL_FEN1_5
	[80,76,69,84,73,86,79,95,87,73,82,69,68], 					// PLETIVO_WIRED
	[70,79,82,84,95,82,65,90,79,82,87,73,82,69], 				// FORT_RAZORWIRE
	[80,76,79,84,95,80,82,79,86,73,90,79,82,78,73], 			// PLOT_PROVIZORNI
	[66,65,82,66,69,68,87,73,82,69], 							// BARBEDWIRE
	[66,65,82,66,71,65,84,69], 									// BARBGATE
	[65,67,69,95,67,79,78,67,69,82,84,73,78,65,87,73,82,69]		// ACE_CONCERTINA_WIRE
];
_ret = false;
for "_i" from 0 to count _ar - 2 do {
	if ((_ar select _i) == 58 && {(_ar select (_i + 1)) == 32}) exitWith {
		_fou = false;
		for "_r" from 0 to count _fencenames - 1 do {
			_fencename = _fencenames select _r;
			_fi = 0;
			for "_o" from (_i + 2) to count _ar - 2 do {
				if ((_ar select _o) != (_fencename select _fi)) exitWith {};
				_fi = _fi + 1;
				if (_fi == count _fencename) exitWith {_fou = true};
			};
			if (_fou) exitWith {_ret = true};
		};
	};
};
_ret
