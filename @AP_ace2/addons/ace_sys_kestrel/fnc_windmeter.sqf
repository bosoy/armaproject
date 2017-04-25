/* ACE2 Kestrel 4500 Windmeter */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// Kestrel 4500

#define __dsp (uiNamespace getVariable "ACE_Kestrel4500")
#define __mode (__dsp displayCtrl 10)
#define __value (__dsp displayCtrl 11)
#define __text1 (__dsp displayCtrl 12)
#define __text2 (__dsp displayCtrl 13)

private["_w"];
GVAR(mode) = 1;
GVAR(cal) = 0;

__text1 ctrlSetText "";
__text2 ctrlSetText "";

if (isNil QUOTE(FUNC(dir_to_string))) then {
	FUNC(dir_to_string) = {
		private["_directions","_index"];
		_directions =
		[
			"N",  "NbE",  "NNE", "NEbN",
			"NE", "NEbE", "ENE", "EbN",
			"E",  "EbS",  "ESE", "SEbE",
			"SE", "SEbS", "SSE", "SbE",
			"S",  "SbW",  "SSW", "SWbS",
			"SW", "SWbW", "WSW", "WbS",
			"W",  "WbN",  "WNW", "NWbW",
			"NW", "NWbN", "NNW", "NbW"
		];
		_index = (round((direction player) * 16 / 360) * (32 / 16)) mod 32;
		_directions select _index;
	};
};
if (isNil QUOTE(FUNC(crosswind))) then {
	FUNC(crosswind) = {
		// (c) by q1184
		private["_windx","_windy","_winddeg","_windstr","_wd","_sidewind"];
		_wind = ACE_wind;
		_windx = _wind select 0;
		_windy = _wind select 1;
		_winddeg = _windx atan2 _windy;
		if (_winddeg<0) then { _winddeg = 360 + _winddeg; };
		_windstr = sqrt(_windx^2+_windy^2);
		_wd = direction player;
		_sidewind = abs ( _windstr*sin (_winddeg-_wd) );
		TRACE_1("crosswind",_sidewind);
		((round (_sidewind * 100)) / 100)
	};
};
if (isNil QUOTE(FUNC(headwind))) then {
	FUNC(headwind) = {
		// (c) by q1184
		private["_windx","_windy","_winddeg","_windstr","_wd","_sidewind"];

		_windx = wind select 0;
		_windy = wind select 1;
		_winddeg = _windx atan2 _windy;
		if (_winddeg<0) then { _winddeg = 360 + _winddeg; };
		_windstr = sqrt(_windx^2+_windy^2);
		_wd = direction player;
		_sidewind = -( _windstr*cos (_winddeg-_wd) );
		TRACE_1("headwind",_sidewind);
		((round (_sidewind * 100)) / 100)
	};
};

while { dialog } do {
	private ["_cal"];
	TRACE_1("",GVAR(mode));
	if (GVAR(mode) > 4) then { GVAR(mode) = 4; };
	if (GVAR(mode) < 1) then { GVAR(mode) = 1; };

	sleep 0.5;

	_cal = player getVariable "kestrel_calibrated";
	if (isNil "_cal") then {
		_cal = false;
		player setVariable ["kestrel_calibrated", false];
	};
	if (!(_cal) && {(GVAR(mode) in [2,3])})  then {
		__text1 ctrlSetText "uncalibrated";__text1 ctrlSetFontHeight 0.022;__text1 ctrlCommit 0;
		__text2 ctrlSetText "--  set heading";__text2 ctrlSetFontHeight 0.022;__text2 ctrlCommit 0;
	} else {
		__text1 ctrlSetText "";
		__text2 ctrlSetText "";
	};
	switch (GVAR(mode)) do {
		case 1: {
			__mode ctrlSetText "HEADING";__mode ctrlSetFontHeight 0.022;__mode ctrlCommit 0;
			__value ctrlSetText format["%1     %2 °",((direction player) call FUNC(dir_to_string)),(round(direction player))];
			__text2 ctrlSetText "True North         ";__text2 ctrlSetFontHeight 0.022;__text2 ctrlCommit 0;
		};
		case 2: {
			__mode ctrlSetText "CROSSWIND  ms";__mode ctrlSetFontHeight 0.022;__mode ctrlCommit 0;
			__value ctrlSetText "";
			_w = call FUNC(headwind);
			if ((_cal) && {((direction player) == (player getVariable "kestrel_cal_dir"))}) then { _w = call FUNC(crosswind); } else { _cal = false;player setVariable ["kestrel_calibrated", false]; };
			__value ctrlSetText format ["%1  ",_w];
		};
		case 3: {
			__mode ctrlSetText "HEADWIND  ms";__mode ctrlSetFontHeight 0.022;__mode ctrlCommit 0;
			__value ctrlSetText "";
			_w = call FUNC(crosswind);
			if ((_cal) && {((direction player) == (player getVariable "kestrel_cal_dir"))}) then { _w = call FUNC(headwind); } else { _cal = false;player setVariable ["kestrel_calibrated", false]; };
			__value ctrlSetText format ["%1  ",_w];
		};
		case 4: {
			__mode ctrlSetText "ALTITUDE  m";__mode ctrlSetFontHeight 0.022;__mode ctrlCommit 0;
			__value ctrlSetText format["%1   ", round((getPosASL player) select 2)];
		};
	};
	if (GVAR(cal) == 1) then {
		if (GVAR(mode) != 1) exitWith { GVAR(cal) = 0; };
		__mode ctrlSetText "CALIBRATE";
		__text2 ctrlSetText "";
		[] spawn {
			for "_i" from 0 to 0 do {
				__value ctrlSetText ".";
				sleep 0.1;
				__value ctrlSetText "..";
				sleep 0.1;
				__value ctrlSetText "...";
				sleep 0.1;
			};
			__value ctrlSetText "SET";
			player setVariable ["kestrel_calibrated", true];
			player setVariable ["kestrel_cal_dir", (direction player)];
			sleep 0.4;
			GVAR(cal) = 0;
		};
	};
	waitUntil { (GVAR(cal) == 0) };
};
