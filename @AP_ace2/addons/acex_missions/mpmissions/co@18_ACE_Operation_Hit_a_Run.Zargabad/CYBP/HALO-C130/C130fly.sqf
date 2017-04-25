/*
===============================================================================================
C130fly - by Cyborg11
Version: 1.0
Date: 07.07.2010
Description: Script to exchange a static to a real c130 if no soldier is in the static
				
Parameter:	nul = [_fake, _real] execVM "C130fly.sqf";
		
			_fake = name of static c130
			_real = name of real c130
===============================================================================================
*/

If (!isServer) exitWith{};	// Need to be run on the server only

_fake = _this select 0;
_real = _this select 1;

_real attachTo [_fake, [0,0,0]];
_real flyInHeight 2000; 
_real hideObject true; 
CYBP_setVel = ["", "", "hide"]; 
publicVariable "CYBP_setVel";
_real animate ["ramp_bottom", 1]; 
_real animate ["ramp_top", 1];

While {alive _fake} do {
	_unitArray = (position _fake) nearObjects ["Man", 10];
	If (count _unitArray == 0) then {
		_real hideObject false; 
		deTach _real; 
		deleteVehicle _fake; 
		_real setDir (direction _fake - 180); 
		_vel = velocity _real;
		_dir = direction _real;
		_speed = 500;
		_velocity = [(_vel select 0)+(sin _dir*_speed),(_vel select 1)+ (cos _dir*_speed),(_vel select 2)];
		CYBP_setVel = [_real, _velocity, "hideno"]; 
		publicVariable "CYBP_setVel";
		_real animate ["ramp_bottom", 0]; 
		_real animate ["ramp_top", 0];
	};
	sleep 1;
};