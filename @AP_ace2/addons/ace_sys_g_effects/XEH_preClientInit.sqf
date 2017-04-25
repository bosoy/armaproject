/* ace_sys_g_effects (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

LOG(MSG_INIT);

ADDON = false;

PREP(checkp);
PREP(rocko_g);

[QUOTE(GVAR(engineon)), {(_this select 0) setVariable [QUOTE(GVAR(eon)),_this select 1];if (_this select 1) then {[_this select 0] spawn FUNC(rocko_g)}}] call CBA_fnc_addEventHandler;

#define __crewProtection (getNumber(configFile >> "CfgVehicles" >> (typeOf player) >> "ACE_CrewProtection"))

GVAR(sound_last_played) = -1;

FUNC(g_func) = {
	private "_g";
	PARAMS_1(_o);
	if (time >= GVAR(sleepend) && {alive _o} && {alive player}) then {
		if (count GVAR(v0) == 0) then {
			GVAR(v0) = velocity _o;
		};
		if (GVAR(next_checkg) == -1) then {
			GVAR(next_checkg) = time + 0.1;
		};
		if (time >= GVAR(next_checkg)) then {
			GVAR(v1) = velocity _o;

			_a_x = (( GVAR(v0) select 0 ) - ( GVAR(v1) select 0 )) / 9.8;
			_a_y = (( GVAR(v0) select 1 ) - ( GVAR(v1) select 1 )) / 9.8;
			_a_z = (( GVAR(v0) select 2 ) - ( GVAR(v1) select 2 )) / 9.8;
			_g = (sqrt( (_a_x * _a_x) + (_a_y * _a_y) + (_a_z * _a_z))) * 10; // * 8

			/*_msg = format["G: %1", _g];
			TRACE_1("",_msg);*/

			if (__crewProtection == 1 || {_crpt = player getVariable "ACE_CrewProtection";if (isNil "_crpt") then {_crpt = 0};_crpt == 1}
				|| {_crpt2 = player getVariable "ACE_CrewProtection_g-effects";if (isNil "_crpt2") then {_crpt2 = false};_crpt2}) then {
				_g = _g - (_g * 0.5)
			} else {
				if (player != (driver _o)) then {_g = _g - (_g * 0.5)};
			};

			_g_s = 0;
			if (_g >= 5) then {
				switch (true) do {
					case (_g < 5): {_g_s = 0};
					case (_g >= 5 && {_g < 6}): {_g_s = 1};
					case (_g >= 6 && {_g < 7}): {_g_s = 2};
					case (_g >= 7 && {_g < 8}): {
						_g_s = 3;
						if (time >= GVAR(sound_last_played)) then {
							playSound (switch (playerSide) do {
								case east: {"ACE_OverGLimit_RU"};
								default {"ACE_OverGLimit_US"};
							});
							GVAR(sound_last_played) = time + 2.5;
						};
					};
					case (_g >= 8 && {_g < 9}): {
						_g_s = 4;
						if (time >= GVAR(sound_last_played)) then {
							playSound (switch (playerSide) do {
								case east: {"ACE_OverGLimit_RU"};
								default {"ACE_OverGLimit_US"};
							});
							GVAR(sound_last_played) = time + 2.5;
						};
					};
					case (_g >= 9): {
						_g_s = 5;
						if (time >= GVAR(sound_last_played)) then {
							playSound (switch (playerSide) do {
								case east: {"ACE_MaximumG_RU"};
								default {"ACE_MaximumG_US"};
							});
							GVAR(sound_last_played) = time + 2.5;
						};
					};
				};
			};

			/*if (ace_sys_afterburner_afterburner) then {
				_g = _g / 2;
				_g_s = 0;
			};*/
			/*_msg = format["_g_s: %1", _g_s];
			TRACE_1("",_msg);*/
			_o setVariable ["ACE_gforce", _g];
			_o setVariable ["ACE_g_s", _g_s];
			GVAR(next_checkg) = -1;
			GVAR(v0) = [];
			GVAR(sleepend) = time + 0.5;
		};
	};
};

FUNC(g_blackout) = {
	private ["_o", "_ti"];
	PARAMS_1(_o);
	_g_s = _o getVariable "ACE_g_s";
	if (_g_s >= 3 && {GVAR(b_blackout_timeend) == -1} && {alive _o} && {alive player}) then {
		_ti = switch (_g_s) do {
			case 3: {0.5 * (_o getVariable "ACE_gforce")};
			case 4: {1.5 * (_o getVariable "ACE_gforce")};
			case 5: {2.5 * (_o getVariable "ACE_gforce")}; // death after some time ?
			default {1};
		};

		13526 cutText["","BLACK OUT", 2];
		13526 cutFadeOut _ti;
		GVAR(b_blackout_timeend) = time + _ti + 1;
	};

	if (GVAR(b_blackout_timeend) != -1 || {!alive _o} || {!alive player}) then {
		if (time >= GVAR(b_blackout_timeend) || {!alive _o} || {!alive player}) then {
			GVAR(b_blackout_timeend) = -1;
			ace_sys_g_effects_doblacko = -1;
			if (!alive _o || {!alive player}) then {
				13526 cutFadeOut 0;
			};
		};
	};
};

FUNC(g_blurr) = {
	private ["_o", "_t"];
	PARAMS_1(_o);
	_g_s = _o getVariable "ACE_g_s";
	if (!GVAR(g_blurr_reson) && {_g_s >= 2} && {GVAR(g_blurr_timeend) == -1} && {alive _o} && {alive player}) then {
		"dynamicBlur" ppEffectEnable true;
		"dynamicBlur" ppEffectAdjust [(_o getVariable "ACE_gforce")/5];
		"dynamicBlur" ppEffectCommit ((_o getVariable "ACE_gforce")/2);
		GVAR(g_blurr_reson) = true;
	};

	if (GVAR(g_blurr_reson) && {_g_s < 2} && {GVAR(g_blurr_timeend) == -1} && {alive _o} && {alive player}) then {
		"dymamicBlur" ppEffectAdjust [0];
		_t = _o getVariable "ACE_gforce";
		"dynamicBlur" ppEffectCommit _t;
		GVAR(g_blurr_timeend) = time + _t - 0.3;
	};

	if ((GVAR(g_blurr_timeend) != -1 && {GVAR(g_blurr_reson)}) || {!alive _o} || {!alive player}) then {
		if (time >= GVAR(g_blurr_timeend) || {!alive _o} || {!alive player}) then {
			"dynamicBlur" ppEffectEnable false;
			GVAR(g_blurr_timeend) = -1;
			GVAR(g_blurr_reson) = false;
		};
	};
};

FUNC(g_round) = {
	private "_o";
	PARAMS_1(_o);
	_g_s = _o getVariable "ACE_g_s";
	if (GVAR(g_round_timeend) == -1 && {_g_s > 0} && {alive _o} && {alive player}) then {
		135887 cutRsc ["ACE_geffectsfb","PLAIN"];
		GVAR(g_round_timeend) = time + (_o getVariable "ACE_gforce");
	};

	if (GVAR(g_round_timeend) != -1 || {!alive _o} || {!alive player}) then {
		if ((time >= GVAR(g_round_timeend) && {_g_s <= 0}) || {!alive _o} || {!alive player}) then {
			135887 cutRsc ["ACE_geffectsfb_nothing","PLAIN"];
			GVAR(g_round_timeend) = -1;
		};
	};
};

// FUNC(GERedout) = {
	// private ["_o"];
	// PARAMS_1(_o);
	// while {_o getVariable "ACE_pinplane"} do {
		// waitUntil {(_o getVariable "ACE_g_s") <= -2 || !(_o getVariable "ACE_pinplane")};
		// if (!(_o getVariable "ACE_pinplane")) exitWith {};
		// "colorInversion" ppEffectEnable true;
		// "colorInversion" ppEffectAdjust [1, 0, 0];
		// "colorInversion" ppEffectCommit 3;
		// sleep 3;
		// waitUntil {(_o getVariable "ACE_g_s") > -2 || !(_o getVariable "ACE_pinplane")};
		// "colorInversion" ppEffectAdjust [0, 0, 0];
		// "colorInversion" ppEffectCommit 1;
		// sleep 1;
		// "colorInversion" ppEffectEnable false;
	// };
// };

ADDON = true;
