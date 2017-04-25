//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090930
// Contact: http://creobellum.org
// Purpose: Rearm enemy emplacements
///////////////////////////////////////////////////////////////////
if (!isServer) exitWith{};
_marker = _this select 0;
_pos = markerPos _marker;
_size = markerSize _marker;

if (_size select 0 > _size select 1) then {
	_size = _size select 0;
} else {
	_size = _size select 1;
};

sleep 60;
_mgs = nearestObjects [_pos, ["DSHKM", "AGS", "D30", "RU_WarfareBMGNest_PK", "KORD_high"], _size * 1.4];
//hint str _mgs;
while {true} do {
	{
		if (!someAmmo _x) then {
			sleep 5;
			_x setVehicleAmmo 1;
		};
		sleep 1;
	} forEach _mgs;
};
