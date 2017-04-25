//fnc_fired.sqf
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
private ["_magazine", "_round", "_ammo", "_action", "_currentRound", "_oldRoundData", "_handle"];
private ["_newRoundData"];

PARAMS_1(_gun);
_handle = false;
// Better way of handling general locality.
if (gunner _gun == player) then {
	_handle = true;
} else {
	if (!isPlayer (gunner _gun) && {isServer}) then {
		_handle = true;
	};
};
if(_handle) then {
	_isAceArty = getNumber (configFile >> "CfgVehicles" >> typeOf _gun >> "ACE_ARTY_ISARTY");
	if (isNil "_isAceArty") exitWith { TRACE_1("NO ACE ARTY",""); };

	_magazine = _this select 5;
	_round = _this select 6;

	_ammo = getText(configFile >> "CfgMagazines" >> _magazine >> "ammo");
	_action = getText(configFile >> "CfgAmmo" >> _ammo >> "ACE_ARTY_FIRE_HANDLER");

	_this call FUNC(dispersion);

	_recoilFunc = getText(configFile >> "CfgVehicles" >> typeOf _gun >> "ACE_ARTY_RECOIL");
	_currentRound = _gun getVariable "ace_sys_arty_currentRound";

	TRACE_1("FIRED EH",_currentRound);
	if (_recoilFunc != "") then {
		[_gun, _currentRound] call COMPILE_FILE2_SYS(_recoilFunc);
	};

	_currentRound = [_round] + _currentRound; // TODO: Use SET
	TRACE_1("FIRED EH 2",_currentRound);
	_newRoundData = [_currentRound]; TRACE_1("FIRED EH 4",_newRoundData);

	_gun setVariable ["ace_sys_arty_roundData",_newRoundData,true];
	_gun setVariable ["ace_sys_arty_currentRound",[],true];

	if (!isNil "_action" && {_action != ""}) then {
		_this call COMPILE_FILE2_SYS(_action);
	};

	_shotOn = _gun getVariable QGVAR(shoton); 
	if (isNil "_shotOn") then { _gun setVariable [QGVAR(shoton),true,true]; };
};
if(!isDedicated) then {
	if (!isNil QGVAR(TRAINING_SESSION)) then {
		private ["_shell", "_marker"];
		_this spawn {
			_shell = _this select 6;
			_marker = createMarkerLocal [format["m%1", GVAR(sc)], getPos _shell];
				
			_marker setMarkerTypeLocal "Dot";
			_marker setMarkerColorLocal "ColorRed";
			_marker setMarkerSizeLocal [0.25, 0.25];
			//_marker setMarkerTextLocal format["%1", GVAR(sc)];
				
			waitUntil {
				if (alive _shell) then {
					_marker = createMarkerLocal [format["m%1", GVAR(sc)], getPos _shell];
					_marker setMarkerTypeLocal "Dot";
					_marker setMarkerColorLocal "ColorRed";
					_marker setMarkerSizeLocal [0.25, 0.25];
					_marker setMarkerPosLocal (getPos _shell);
					INC(GVAR(sc));
				};
				!alive _shell;
			};
		};
	};
};