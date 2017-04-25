//#define DEBUG_MODE_FULL
#include "script_component.hpp"

TRACE_1("Cluster","");

// Create 6 other flares of same color
_cl_type = _this select 4;
_cl_flare = _this select 6;

waituntil {sleep 1; ((velocity _cl_flare) select 2) < 0 || {!(alive _cl_flare)}};
_cl_flare_pos = getPos _cl_flare;
deleteVehicle _cl_flare;

{
	_cl = _cl_type createVehicle _cl_flare_pos;
	_cl setPos [(_cl_flare_pos select 0) + random 3,(_cl_flare_pos select 1) - random 3,(_cl_flare_pos select 2)+random 4];
	if (getNumber(configFile >> "CfgAmmo" >> _cl_type >> QGVAR(DAY)) == 1) then {
		if (_x mod 2 == 0) then  {
			[QGVAR(fired), ["","","","",_cl_type,"",_cl]] call CBA_fnc_globalEvent;
		};
	};
	sleep 0.05;
} foreach [1,2,3,4,5,6,7];
