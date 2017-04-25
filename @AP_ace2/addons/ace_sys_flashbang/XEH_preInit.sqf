/* ace_sys_flashbang (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

["shotFlashbang", COMPILE_FILE(fnc_fired)] call ACE_fnc_registerSimulation;
["shotFlashbangGL", COMPILE_FILE(fnc_firedGL)] call ACE_fnc_registerSimulation;

PREP(fired_bang);
PREP(fired_bangGL);
PREP(fx);

[QGVAR(fired), {_this spawn FUNC(fired_bang)}] call CBA_fnc_addEventHandler;
[QGVAR(firedGL), {_this spawn FUNC(fired_bangGL)}] call CBA_fnc_addEventHandler;

FUNC(fx_visual) = {
	PARAMS_2(_flashbang,_ammo);
	if (isDedicated) exitWith {};
	_delay = __DBFX;
	_no = __NOFX;
	_snd = __SND;
	for "_i" from 0 to (_no-1) do {
		_flashbang say3D _snd;
		//ExploAmmoFlash
		drop [ ["\ca\Ca_E\data\ParticleEffects\Universal\Universal", 16, 0, 32], "", "Billboard", 1, 0.2, [0, 0, 0], [0, 1, 0], 1, 10, 7.9, 0.1, [1.5, 1, 1, 1], [[1, 1, 1, -30], [1, 1, 1, -10], [1, 1, 0.7, -6], [1, 1, 0.7, -4]], [-2, 1, 1], 0.2, 0.2, "", "", _flashbang ];   
		// ExploSparks
		for "_y" from 0 to 11 do {
			drop [["\ca\Ca_E\data\ParticleEffects\Universal\Universal", 16, 0, 2], "", "Billboard", 0.1, 1, [0, 0, 0], [(2 + random 6),(2 + random 6),(2 + random 8)], 9, 400, 5, 10, [0.1, 0.05, 0.05], [[1, 1, 0.7, -10], [1, 1, 0.7, -8],[1, 1, 0.7, -6], [1, 1, 0.7, -4]], [-2, 1, 1], 0.3, 0.3, "", "", _flashbang];   
		};
		// ExploAmmoLight
		_light = "#lightpoint" createVehicleLocal getPos _flashbang;
		_light setLightAmbient [1,0.95,0.887];
		_light setLightBrightness 0.1;
		_light setLightColor [10,9.5,8.87];
		_light lightAttachObject [_flashbang, [0,0,0]];
		// LensFlare
		drop [["\x\ace\addons\sys_flashbang\data\flare.p3d", 1, 0, 1], "", "Billboard", 0.1, 1, [0, 0, 0], [6, 6, 4], 1.285, 1, 0.05, 10, [5, 3, 0], [[1,1,1,0.9], [1,1,1,0]], [-2, 1, 1], 0.3, 0.3, "", "", _flashbang];   
		// Smoke
		drop [["\ca\Ca_E\data\ParticleEffects\Universal\Universal", 16, 12, 8], "", "Billboard", 1, 7, [0, 0, 0], [0.4, 0.4, 0.4], 1, 1, 0.8, 0.5, [1.5, 2.7, 1.7, 0.5], [[1, 1, 1, 1], [1, 1, 1, 0.5], [1, 1, 1, 0.25], [1, 1, 1, 0]], [1], 0.1, 0.1, "", "", _flashbang];
		sleep 0.1;
		deleteVehicle _light;
		sleep (_delay-0.1);
	};
};


ADDON = true;
