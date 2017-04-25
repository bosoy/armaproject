#include "script_component.hpp"

#define __factionLanguage getText(configFile >> "CfgFactionClasses" >> (faction _this) >> "ACE_Language")
#define __unitLanguage getArray(configFile >> "CfgVehicles" >> (typeOf _this) >> "languages")
#define __unitSide getNumber(configFile >> "CfgVehicles" >> (typeOf _this) >> "side")

ADDON = false;

if (isNil QGVAR(talkforplayer)) then {GVAR(talkforplayer) = false};

PREP(talker);
PREP(hit);
PREP(fired);
PREP(firednear);
PREP(vehicleradio);

FUNC(getfaction) = {
	private ["_fac"];
	_fac = _this getVariable QGVAR(faclang);
	if (isNil "_fac") then {
		_fac = switch (toLower(__factionLanguage)) do {
			case "english": {GVAR(talkwest)};
			case "russian": {GVAR(talkeast)};
			case "arab": {GVAR(talkarab)};
			default {
				if (count __unitLanguage > 0) then {
					switch (toUpper(__unitLanguage select 0)) do {
						case "EN": {GVAR(talkwest)};
						case "RU": {GVAR(talkeast)};
						case "CZ": {GVAR(talkeast)};
						case "TK": {GVAR(talkarab)};
						default {
							switch (__unitSide) do {
								case 0: {GVAR(talkeast)};
								case 1: {GVAR(talkwest)};
								case 2: {GVAR(talkeast)};
								case 3: {GVAR(talkeast)};
								default {[]};
							};
						};
					};
				} else {
					switch (__unitSide) do {
						case 0: {GVAR(talkeast)};
						case 1: {GVAR(talkwest)};
						case 2: {GVAR(talkeast)};
						case 3: {GVAR(talkeast)};
						default {[]};
					};
				};
			};
		};
		_this setVariable [QGVAR(faclang), _fac];
	};
	_fac
};

FUNC(getvecfaction) = {
	private ["_fac"];
	_fac = _this getVariable QGVAR(faclang);
	if (isNil "_fac") then {
		_fac = switch (toLower(__factionLanguage)) do {
			case "english": {1};
			case "russian": {0};
			case "arab": {-1};
			default {
				switch (__unitSide) do {
					case 0: {0};
					case 1: {1};
					case 2: {0};
					default {-1};
				};
			};
		};
		_this setVariable [QGVAR(faclang), _fac];
	};
	_fac
};

ADDON = true;
