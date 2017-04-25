#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(loop);

// MFD
PREP(ah1z_mfdInit);
PREP(ah64_mfdinit);
PREP(ah6_mfdinit);
PREP(mfdloop);
// First of all, why precompile a script in preInit instead of preClientInit if it isn't needed on a dedi server at all ?
// second, spawning a script with an empry array which expects three parameters is not a good idea at all
//PREP(playerinit); // not needed on dedi

// Generic Russian rangefinder display
PREP(rfinit);
PREP(rfloop);

// FCS
PREP(elev);
PREP(fired);
PREP(setsolution);
PREP(findrange);
PREP(findrangePFH);
PREP(keypressed_lase);

// maths
PREP(mat_normalize3d);

GVAR(presstime) = 0;

FUNC(enableDot) = {};
/*
	disableSerialization;
	1234 cutRsc [QGVAR(dot), "PLAIN"];
	_disp = uiNamespace getVariable "ace_test_dot";
	_char_n = _disp displayCtrl 66666; // spawn

	_char_n ctrlSetPosition [0.3, 0.3, 0.1, 0.1];
};*/

FUNC(disableDot) = {};
/*
	disableSerialization;
	1234 cutRsc ["Default","PLAIN"]; // kill
};
*/
GVAR(validLD) = false;
FUNC(findLD) = {
	private ["_vic", "_laserCode"];
	_vic = _this select 0;
	_laserCode = _this select 1;
	_func = {
		private ["_params", "_vic", "_laserCode", "_result"];
		_params = _this select 0;
		_vic = _params select 0;
		_laserCode = _params select 1;
		_result = [_vic, _laserCode] call ace_sys_missileguidance_fnc_findLaserDesignator;
		GVAR(validLD) = _result select 0;
		[_this select 1] call cba_fnc_removePerFrameHandler;
	};
	[_func, 0, [_vic, _laserCode]] call cba_fnc_addPerFrameHandler;
};

FUNC(ru_gunner) = {
	hintSilent "gunner";
};
FUNC(ru_pilot) = {
	hintSilent "pilot";
};

[QUOTE(ADDON), "Lase", { _this call FUNC(keyPressed_lase)}] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
