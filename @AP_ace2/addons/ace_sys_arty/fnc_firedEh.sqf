// #define DEBUG_MODE_FULL
#include "script_component.hpp"

_shell = _this select 6;
_deploy = getText (configFile >> "cfgAmmo" >> typeOf _shell >> QGVAR(deploy));
if (_deploy == "") exitWith {};

[_this, _deploy] spawn {
	PARAMS_2(_data,_deploy);
	_shell = _data select 6;

	_deployOnImpact = getNumber (configFile >> "cfgAmmo" >> typeOf _shell >> QGVAR(deployOnImpact));
	_deployaltitude = getNumber (configFile >> "cfgAmmo" >> typeOf _shell >> QGVAR(deployAltitude));
	if (_deployOnImpact == 1) then {
		if (isServer) then {
			[_shell] spawn {
				PARAMS_1(_shell);
				while {alive _shell} do {
					TRACE_1("", getPos _shell);
					sleep 0.01;
				};
			};
			_shellPos = getPos _shell;
			waitUntil {sleep 0.01; if (alive _shell) then { _shellPos = getPos _shell }; !alive _shell};
			_smoke = _deploy createVehicle _shellPos;
			//_smoke setPos _shellPos;
		};
	} else {
		if (_deployaltitude > 0) then {
			if (isServer) then {
				waitUntil {sleep 0.01; (velocity _shell select 2) < 0 && {(getPos _shell select 2) < _deployaltitude} };
				_flare = _deploy createVehicle getPos _shell;
				[nil, nil, nil, nil, nil, nil, _flare] spawn ace_sys_flares_fnc_slowdescent;
				[nil, nil, nil, nil, _deploy, nil, _flare] execFSM "\x\ace\addons\sys_flares\fnc_rocko_flares.fsm";
			} else {
				waitUntil {sleep 0.1; (velocity _shell select 2) < 0 && (getPos _shell select 2) < _deployaltitude};
			};
			deleteVehicle _shell;
		};
	};
};

_shotOn = _gun getVariable QGVAR(shoton); if (isNil "_shotOn") then { _gun setVariable [QGVAR(shoton),true,true]; };