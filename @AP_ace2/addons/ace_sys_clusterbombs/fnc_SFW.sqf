/* ace_sys_clusterbombs (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */

// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_5(_unit,_bomb,_ammo,_count,_time);

sleep 3;

_vel = velocity _bomb;
_pos = getPos _bomb;
_dir = getDir _bomb;
_vdir = vectorDir _bomb;
_ammo = (_ammo select 0);
TRACE_4("",_vel,_pos,_dir,_vdir);

// Pop Fx
[QGVAR(popfx), _bomb] call CBA_fnc_globalEvent;

deleteVehicle _bomb;

// Spawn 4 bomb shell particles
// TODO: Try particleEffects
_s1 = "ACE_CBU87_Shell_1" createVehicle _pos;
_s2 = "ACE_CBU87_Shell_2" createVehicle _pos;
_s3 = "ACE_CBU87_Shell_1" createVehicle _pos;
//_s4 = "ACE_CBU87_Shell_2" createVehicle _pos;
// Spawn bomb core
_c = "ACE_CBU_87_Core" createVehicle _pos;

{ _x setPos _pos; _x setVectorDir _vdir; /*_x setVelocity _vel;*/ } foreach [_s1,_s2,_s3,_s4,_c];

sleep 1;

// Create bomblets
// Create MASTER bomblet
_bomblet_m = _ammo createvehicle [(_pos select 0) + random 30,(_pos select 1) + random 30,_pos select 2];

// jaynus addition:
// get the master vehicle to see if the MFD set a det altitude
// default to the old 50
_burstAltitude = (vehicle _unit) getVariable[QGVAR(burst_altitude), 50];

_bomblet_m setpos [(_pos select 0) + random 30,(_pos select 1) + random 30,_pos select 2];

// Track _bomblets
private ["_bomblet_tracker"];
_bomblet_tracker = [_bomblet_m];

// Create 9 followers
for "_i" from 0 to (_count - 1) do {
	_pos = getPos _bomblet_m;
	_pos_new = [(_pos select 0) + (sin _dir * ((random 20 + 20)*_i)), (_pos select 1) + (cos _dir * ((random 20 + 20)*_i)), (_pos select 2) + (1*_i)];
	_bomblet = _ammo createvehicle _pos_new;
	_bomblet setPos _pos_new;
	sleep 0.1;
	_bomblet_tracker set [count _bomblet_tracker, _bomblet];
};

// Wait until MASTER bomblet is at 25m height


while { ((getPosATL _bomblet_m) select 2 > _burstAltitude) && {alive _bomblet_m} } do {
	sleep 5;
	TRACE_1("Master bomblet flying",((getPosATL _bomblet_m) select 2));
};
// Bomblet #1 is in attack height
TRACE_1("Bomblet reaches 25m",nil);

// Hide parachute
// { sleep 3;} foreach _bomblet_tracker;

// Boost BLUs up
// { sleep 2;} foreach _bomblet_tracker;


// Each BLU releases 4 Skeets
// Center skeet position is the BLU container position
// Skeets are distributed in 4 directions 10 meters from BLU
// Each skeet scans a circle of 15m radius / 30 m diameter (assumed)
// => Each BLU has a scanning pattern of ~50m +- 10m (-> 25 + random 10 from its center position for scripting)
// Each BLU scans for a maximum of 4 targets

// Possibility 2 skeets attack the same target
// _prob = 30;

// TODO: Fail to recognize targets under camonettings or in buildings

// TODO: Randomize skeet order
// Shuffle!!

private ["_targets","_v_targets"];
// Execute tracking seq. for each BLU
{
	//_x = actual BLU
	// Get center position of BLU
	_pos_center_x = getPos _x;
	_px = _pos_center_x select 0;
	_py = _pos_center_x select 1;
	_pz = _pos_center_x select 2;
	if (_pz < 15) then { _pz = 15; };

	_scanrange = 40 + (random 15);
	_prob = 0.3; // Double Shot Probability
	// Find targets
	_targets = [_px, _py, 0] nearEntities [["Car","Tank","StaticCannon"], _scanrange];
	_v_targets = [];
	{ if (alive _x) then {_v_targets set [(count _v_targets), _x];}; } forEach _targets;

	TRACE_1("V_TAR",_v_targets);

	// Max 4 targets
	_count = count _v_targets;
	// More than 4 targets
	if (_count > 4) then { _v_targets resize 4; };

	// No targets = Selfdestruct
	_selfdestruct = _count == 0;

	// TODO: Double shot

	// Attack
	// TODO: Scheduling? Bring into a function?
	{
		// _burst = "ARTY_SADARM_BURST" createVehicleLocal [_px, _py, _pz + 5];
		//  _burst setPos [_px, _py, _pz + 5];
		if (_selfdestruct) then {
			0 spawn {
				// Create Explosion on ground
				{
					_sd = "GrenadeHand" createVehicle [_px, _py, 0];
					_sd setPos [_px + random 10, _py + random 10, 0];
					sleep 1;
				} foreach [1,1,1,1];
			};
		} else {
			// TODO: Selfdestruct to skeets that have not yet found a target
			_targetToHit = _x;
			TRACE_1("T", _targetToHit);
			_p = "ACE_BLU108B_PROJO" createVehicle [_px, _py, _pz + 5];
			_p setPos [_px, _py, _pz + 5];
			_xoff = (getPos _targetToHit select 0) - _px;
			_yoff = (getPos _targetToHit select 1) - _py;
			_zoff = - _pz;
			_mag = sqrt(_xoff*_xoff + _yoff*_yoff + _zoff*_zoff);
			_dir = [_xoff/_mag, _yoff/_mag, _zoff/_mag];
			_dx = _dir select 0;
			_dy = _dir select 1;
			_dz = _dir select 2;
			_hmag = sqrt(_dx*_dx + _dy*_dy);
			_zcomp = -_dz/_hmag;
			_ux = _zcomp*_dx;
			_uy = _zcomp*_dy;
			_uz = _hmag;
			_p setVectorDir _dir;
			_p setVectorUp [_ux,_uy,_uz];
			_p setVelocity [(_dir select 0) * 300, (_dir select 1) * 300, (_dir select 2) * 300];
		};
		sleep 0.5
	} foreach _v_targets;
	sleep 0.5;
} foreach _bomblet_tracker;

// Clean up
[QGVAR(trash), [_s1,_s2,_s3,_c]] call ACE_fnc_clientToServerEvent;
