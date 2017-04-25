#include "script_component.hpp"

comment " FuncfindClosestTown.sqf - Find the closest to player excuting the script [player]";
comment " Script should work on any island providing the island config file includes the 'type'. for towns";
comment " By Hoz - July 2007";
comment " Version v.3 - slightly altered for the purpose of checking a pos array opposed to a unit";
private["_towns", "_mindist","_dist", "_mindistidx", "_typecity", "_i", "_cfgPath", "_ntowns",  "_postown", "_return", "_msg", "_dir", "_FunctionMode"];

PARAMS_2(_unit,_maxdist);

#define __cfgTowns (configFile >> "cfgWorlds" >> WorldName >> "Names")

_towns = [];
_mindist =  99999;
_dist    =  99999;
_mindistidx = -1;
_typecity = "";

for "_i" from 0 to ((Count __cfgTowns)-1) do {
	_cfgPath = __cfgTowns Select _i;
	_typecity = getText (_cfgPath >> "type");
	if (_typecity == "NAMECITY" || {_typecity == "NAMEVILLAGE"} || {_typecity == "NAMECITYCAPITAL"} || {_typecity == "NAMELOCAL"}) then {
		_towns Set [_i,[getText (_cfgPath >> "name"),getArray (_cfgPath >> "position"), _typecity]];
	};
};

for "_i" from 0 to (count _towns) - 1 do {
	_postown = (_towns select _i) select 1;
	_dist = _unit distance _postown;
	if (_dist < _mindist && _dist < _maxdist) then {
		_mindist = _dist;
		_mindistidx = _i;
	};
};
if (_mindistidx != -1) then {
	_postown = (_towns select _mindistidx) select 1;
	_dir = ((_postown select 0)-(_unit select 0)) atan2 ((_postown select 1)-( _unit select 1));

	_msg = switch (true) do {
		case (_dir < 23 && _dir > -23): {"North"};
		case (_dir >= 23 && _dir < 68): {"North East"};
		case (_dir >= 68 && _dir < 113): {"East"};
		case (_dir >= 113 && _dir < 136): {"East"};
		case (_dir >= 136 && _dir < 159): {"South East"};
		case (_dir >= 159 || _dir < -158): {"South"};
		case (_dir >= -158 && _dir < -113): {"South West"};
		case (_dir >= -113 && _dir < -68): {"West"};
		default {"North West"};
	};

	_return = [(_towns select _mindistidx) select 0, _msg, _mindist];
} else {
	_return = ["", "", 0];
};

_return
