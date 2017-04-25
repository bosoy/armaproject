#include "script_component.hpp"
private ["_blackl", "_oldstance", "_oldspeed", "_ar", "_stance", "_speed", "_char", "_color"];
#define __huddisp ((uiNamespace getVariable "ACE_PHud_Stance") displayCtrl 1000)
#define __togglespeeddisp ((uiNamespace getVariable "ACE_PHud_Stance") displayCtrl 1001)

#define __green [0.4, 0.6745, 0.2784, 0.7]
#define __yellow [1, 1, 0, 0.7]
#define __orange [0.8, 0.4, 0, 0.7]
#define __red [1, 0, 0, 0.7]
#define __skydive_stances [ QPATHTO_T(data\para_15b.paa), QPATHTO_T(data\para_00.paa), QPATHTO_T(data\para_15.paa), QPATHTO_T(data\para_30.paa), QPATHTO_T(data\para_45.paa), QPATHTO_T(data\para_60.paa), QPATHTO_T(data\para_75.paa), QPATHTO_T(data\para_90.paa), QPATHTO_T(data\para_90.paa) ] 

waitUntil {!isNull player};
waitUntil {local player};

_blackl = ["weaponmagazinereloadprone","amovpercmrunslowwrfldf_amovppnemstpsraswrfldnon","pistolmagazinereloadprone"];

_oldstance = "";
_oldspeed = "";
_previous = time - 4;
_hud_on = false;
_oldplayer = player;
135499 cutRsc ["Default", "PLAIN"];
while {true} do {
	if (!visibleMap && {alive player} && {vehicle player == player} && {!(player call ace_sys_wounds_fnc_isUncon)} && {!ace_sys_spectator_SPECTATINGON}) then {
		// Delayed check
		if (time > _previous + 3) then {
			_previous = time;
			while {true} do {
				if ((["ACE", "ACE_STANCEINDICATOR", "enabled"] call ace_settings_fnc_getNumber) == 1) exitWith {
					if (!_hud_on) then {
						135499 cutRsc ["ACE_PHud_Stance", "PLAIN"];
						__huddisp ctrlSetText "";
						__togglespeeddisp ctrlSetText "";
						_oldstance = "x";
						_hud_on = true;
					};
				};
				if (_hud_on) then {
					135499 cutRsc ["Default", "PLAIN"];
					_hud_on = false;
				};
				sleep 3;
			};
		};
		if (_oldplayer != player) then {
			135499 cutRsc ["Default", "PLAIN"];
			_hud_on = false;
			_oldplayer = player;
		};
		_ar = player call CBA_fnc_getUnitAnim;
		_stance = if (player getVariable ["ace_sys_eject_skydiving",false]) then { "skydive" } else { _ar select 0; };
		_speed = _ar select 1;
		if (!_hud_on) then {
			135499 cutRsc ["ACE_PHud_Stance", "PLAIN"];
		};
		if (!isWalking player) then {
			__togglespeeddisp ctrlSetText QPATHTO_T(data\speedtoggle.paa); __togglespeeddisp ctrlCommit 0;
		} else {
			__togglespeeddisp ctrlSetText ""; __togglespeeddisp ctrlCommit 0;
		};
		if (_stance != _oldstance && {!((animationState player) in _blackl)}) then {
			_char = switch (toLower _stance) do {
				case "stand": {QPATHTO_T(data\stand.paa)};
				case "kneel": {QPATHTO_T(data\kneel.paa)};
				case "prone": {QPATHTO_T(data\prone.paa)};
				case "skydive": {
					__skydive_stances select (round (7 * (-ace_sys_eject_newPitch + 0.085)));
				};
				default {""};
			};
			_oldstance = if (player getVariable ["ace_sys_eject_skydiving",false]) then { "" } else { _stance };
			__huddisp ctrlSetText _char;
		};
		if (_speed != _oldspeed) then {
			_color = switch (toLower _speed) do {
				case "slow": {__yellow};
				case "normal": {__orange};
				case "fast": {__red};
				default {__green};
			};
			_oldspeed = _speed;
			__huddisp ctrlSetTextColor _color;
			__togglespeeddisp ctrlSetTextColor _color;
		};
	} else {
		if (ctrlText __huddisp != "") then {
			__huddisp ctrlSetText "";
			__togglespeeddisp ctrlSetText "";
			_oldstance = "x";
			_hud_on = false;
			135499 cutRsc ["Default", "PLAIN"];
		};
	};
	sleep 0.312;
};