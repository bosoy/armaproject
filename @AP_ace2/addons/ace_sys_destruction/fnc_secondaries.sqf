//Small secondary fuel explosions
//By Maddmatt for ArmA 2
#include "script_component.hpp"
private ["_list", "_lifecheck", "_i", "_t", "_effect2pos", "_b", "_secondarytype"];
PARAMS_2(_veh,_int);

_list=[];
_lifecheck = if (count _this > 2) then {_this select 2} else {true}; //if true then script will only run while unit is 'dead'

//Generate intervals between explosions
while {_int > 1} do {
	_int = _int - 1;
	_t = (random 45) + 1;
	_list set [count _list, _t];
};

_secondarytype = if (sizeOf (typeOf _veh) < 5) then {"ace_fuelexpspark"} else {"SmallSecondary"};

_effect2pos = _veh selectionposition "destructionEffect2";
//Create the explosions
{
	sleep _x;
	if ((_lifecheck && {alive _veh}) || {isnull _veh} || {((getposASL _veh) select 2) < 0}) exitWith {};
	// hm, how about createvehiclelocal only ?
	_b = _secondarytype createvehicle (_veh modelToWorld _effect2pos);
} foreach _list;
