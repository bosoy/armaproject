if (isDedicated) exitWith {};

#include "script_component.hpp"

private ["_type","_cnv", "_cal", "_mass", "_cv", "_sh", "_weh", "_life"];

PARAMS_1(_veh);

_type = _this select 4;
_sh = _this select 6; // Uses Extended_FiredBIS


// zGuba: Decrease visible smoke on own weapon, especially in NV mode.
switch (currentVisionMode player) do {
	case 1: {
		if (cameraOn == _veh) then {
			switch (cameraView) do {
				case "GUNNER": {_cnv = 0.25};
				default {_cnv = 0.5};
			};
		} else {
			_cnv = 0.5
		};
	};
	default {_cnv = 1};
};

// zGuba: corelation between round size and amount of smoke. B_30mm_AP as ref.
_cal = getNumber (configFile >> "CfgAmmo" >> _type >> "ace_caliber") / 30;
_mass = getNumber (configFile >> "CfgAmmo" >> _type >> "ace_mass") / 40;
_multiplier = 1 max getNumber (configFile >> "CfgAmmo" >> _type >> "ace_smokemultiplier");

// zGuba: Apply only if sys_wounds is present.
_cv = if (_cal > 0 && {_mass > 0}) then { _cnv * sqrt(sqrt(_cal) * sqrt(_mass)) * sqrt(_multiplier) } else { _cnv * sqrt(_multiplier) };

if ((_veh iskindof "Helicopter") && {isengineOn _veh}) then {
	_weh = 1;
	_life = 0.8 * _cv;
} else {
	_weh = 0.104;
	_life = (1.3 + random 0.6) * _cv;
};

drop [["\ca\Data\ParticleEffects\Universal\Universal",16,12,8], "",
	"Billboard", 1, _life, [0, 0, 0], [0, 5 + random 4, 0], 0, _weh, 0.08, 0.2,
	[1.5*_cv, (5 + random 3)*_cv], [[0.7, 0.7, 0.7, (0.2 + random 0.1)*_cv], [0.8, 0.8, 0.8, 0]],
	[1/_life], 1, 0, "", "", _sh,random 360];
drop [["\ca\Data\ParticleEffects\Universal\Universal",16,12,8], "",
	"Billboard", 1, 0.3*_cv, [0, 0, 0], [0, 0, 0], 0, _weh, 0.08, 0.5,
	[0.4*_cv, 2.5*_cv],	[[0.3, 0.3, 0.3, 0],[0.5, 0.5, 0.5, 0.25*_cv], [0.7, 0.7, 0.7, 0]], [2/_cv], 1, 0, "", "", _sh,random 360]