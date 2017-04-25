//#define DEBUG_MODE_FULL
/*ArmA 2 smokscreen, by Maddmatt
Uses code from VBS2 Smoke launcher by Philipp Pilhofer (raedor) & Andrew Barron
*/
#include "script_component.hpp"
private ["_vec", "_doexit", "_shells", "_num", "_vel", "_useTDir", "_angle", "_type", "_dir", "_deltaDir", "_arc", "_initDist", "_logic", "_i", "_Hdir", "_Vdir", "_vH", "_vV", "_Gvel", "_pH", "_pV", "_smokeg", "_sm","_hascom"];
PARAMS_1(_veh);
if !(_veh call ace_v_alive) exitWith {
	TRACE_1("vehicle not alive, exiting",_veh);
};

_num = getNumber (configFile >> "CfgVehicles" >> typeOf _veh >> "smokeLauncherGrenadeCount");
if (_num < 1) exitWith {};

_doexit = false;
// TODO: Check for Wheeled_APC too ?
_hascom = str(inheritsFrom(configFile >> "CfgVehicles" >> typeOf _veh >> "Turrets" >> "MainTurret" >> "Turrets")) != ""; // Check if the vehicle can actually have a commander
if (_veh isKindOf "Tank" && _hascom) then {
	_commander = commander _veh;
	if (isNull _commander) exitWith {
		TRACE_1("commander null, exiting",_veh);
		_doexit = true;
	};
	if (!isPlayer _commander) then {
		if (!alive _commander || {[_commander] call ace_sys_wounds_fnc_isUncon}) exitWith {
			TRACE_1("commander not alive or unconscious, exiting",_veh);
			_doexit = true;
		};
		// TODO: check if turret points to 6 o'clock then deploy smoke. Tank might retreat
		if (speed _veh > 6) exitWith {
			TRACE_1("vehicle speed to high, not deploying smoke, exiting",_veh);
			_doexit = true;
		};
		_lastt = _veh getVariable [QGVAR(last_smoke), -1000];
		if (time - _lastt > 90) then {
			TRACE_1("fine to shoot",_veh);
			_veh setVariable [QGVAR(last_smoke), time];
		} else {
			TRACE_1("not enough time gone since last shot",_veh);
			_doexit = true;
		};
	};
};
if (_doexit) exitWith {
	TRACE_1("_doexit",_veh);
};
_vec = vectorDir _veh;
_shells = [];

//Read values from config
_vel = getNumber (configFile >> "CfgVehicles" >> typeOf _veh >> "smokeLauncherVelocity");
_useTDir = getNumber (configFile >> "CfgVehicles" >> typeOf _veh >> "smokeLauncherOnTurret");
_angle = getNumber (configFile >> "CfgVehicles" >> typeOf _veh >> "smokeLauncherAngle");

_dir = direction _veh;
if (_useTDir ==1 && {(count weapons _veh > 0)}) then {
	_dir = _veh weaponDirection ((weapons _veh) select 0);
	_dir = (((_dir select 0) atan2 (_dir select 1))+360)%360;
};

_deltaDir = _angle/_num;		//degrees between grenades.
_arc = _deltaDir*(_num-1);		//total arc to cover, in degrees

//distance from vehicle center where grenades are created; base it on vertical height
_initDist = (((boundingBox _veh) select 1) select 2) - (((boundingBox _veh) select 0) select 2);

// TODO: What is this logic doing here?
// _logic = "ACE_LogicDummy" createVehicleLocal (getPos _veh);
//_logic setDir _dir;

TRACE_6("",_veh,_vec,_num,_vel,_useTdir,_angle);
//sleep 0.25;
for "_i" from 0 to (_num - 1) do {
	//find starting parameters
	_Hdir = (_i*_deltaDir) - _arc/2; //relative direction around vehicle
	_Vdir = 30;	                     //angle of elevation. Temporary: launch all grenades at same angle

	//derive velocity
	_vH = _vel * cos _Vdir;          //horizontal component of velocity
	_vV = _vel * sin _Vdir;          //vertical component
	_Gvel = [_vH*sin (_Hdir+_dir), _vH*cos (_Hdir+_dir), _vV]; //initial grenade velocity

	//find starting position for grenades
	_pH = _initDist * cos _Vdir;     //initial distance horizontally away from vehicle center to create grenade
	_pV = _initDist * sin _Vdir;     //vertical distance

	//create / launch the grenade
	_smokeg="SmokeShellVehicle" createVehicleLocal (_veh modelToWorld [_pH * sin _Hdir, _pH * cos _Hdir, _pV]);
	_smokeg setVelocity _Gvel;
	_smokeg setVectorDir _Gvel;
	_shells set [count _shells, _smokeg];
};
//deletevehicle _logic;

if (isDedicated) exitWith {};

{ [_x, [1,1,1,1]] spawn FUNC(smokeshellparticles) } foreach _shells;