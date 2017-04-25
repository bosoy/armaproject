// laser rangefinder. returns: range to target, position of target in world and ASL coords, angle between sight center and weapon direction,vec to target,inclination angle to target]

private ["_d","_tarveh","_l1","_l2","_l3","_vehicle", "_weapon", "_offset", "_newPos", "_spd", "_laserVec","_pulsePos", "_pulse", "_range", "_target","_projectile","_newposASL","_p","_p1","_wdir","_welev","_vecangle","_diff","_y"];

_vehicle = vehicle player;
_weapon = currentweapon _vehicle;
_offset = [0,0,5];
_newPos = [0,0,0];
_spd = 600000;

// Get direction of the weapon. The pulse will be fired along the bore axis.
//_laserVec = _vehicle weaponDirection _weapon;
//_wdir = _vehicle weapondirection _weapon;
//_welev =  (_wdir select 2) atan2 sqrt((_wdir select 1)^2 + (_wdir select 0)^2);

_pulsePos = positionCameraToWorld _offset;
_pulse = "ACE_Missileguidance_LaserPulse" createVehicleLocal _pulsePos;
_pulse setPos _pulsePos;
_p = getposASL _pulse;
_p1 = positionCameraToWorld [_offset select 0,_offset select 1,1 + (_offset select 2)];
_pulse setPos _p1;
_p1 = getposASL _pulse;

_laservec = [(_p1 select 0)-(_p select 0),(_p1 select 1)-(_p select 1),(_p1 select 2)-(_p select 2)];
_pulse setPos _pulsePos;
_pulse setVelocity [(_laserVec select 0) * _spd, (_laserVec select 1) * _spd, (_laserVec select 2) * _spd];
_range = 0;

/*
// difference between bore and optics elevation
_wdir = _laservec;
_vecangle = (_wdir select 2) atan2 sqrt((_wdir select 1)^2 + (_wdir select 0)^2);
_diff = _vecangle - _welev;
*/

waitUntil {
	if (alive _pulse) then {
		_d = _pulse distance _vehicle;
		if (_d < 9999 && {_d > 25}) then { _range = _d; _newPos = getPos _pulse; _newposASL = getPosASL _pulse };
	};
      !(alive _pulse)
};

// Trigger incoming laser detection on targeted vehicle
_tarVeh = objNull;
{ if !(_x isKindOf "StaticWeapon") exitWith { _tarVeh = _x } } forEach (_newpos nearEntities [["LandVehicle", "Air", "Ship"],12]);
if !(isNull _tarVeh) then {
	["ace_lasertarget", [_vehicle, _tarVeh, objNull]] spawn CBA_fnc_globalEvent;
};


// relative height of target
//_y = 2 + (_newposASL select 2) - ((getposASL _vehicle) select 2);

_l1 = _laservec select 0;
_l2 = _laservec select 1;
_l3 = _laservec select 2;

// elevation of target
_p =  _l3 atan2 sqrt(_l1^2+_l2^2);

//player sidechat format ["laser vec %1 weapon dir %2",_vecangle,_welev];
/*
_vehicle setvariable ["ace_fcs_lrfdata",[_range, _newpos,_newposASL,_diff,_y,_laservec,_p]];

[_range,_newpos,_newposASL,_diff,_y,_laservec,_p]
*/

_vehicle setvariable ["ace_fcs_lrfdata",[_range,_newpos,_newposASL,_laservec,_p]];

[_range,_newpos,_newposASL,_laservec,_p]
