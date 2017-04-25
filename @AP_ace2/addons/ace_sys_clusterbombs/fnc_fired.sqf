/* ace_sys_clusterbombs (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __cfg configFile >> "CfgAmmo" >> _ammo
#define __CLUSTERAMMO getArray(__cfg >> "ACE" >> "ACE_CLUSTERBOMBS" >> "ammo")
#define __CLUSTERCOUNT (getArray(__cfg >> "ACE" >> "ACE_CLUSTERBOMBS" >> "count") select 0)
#define __DROPHEIGHT_MIN (getArray(__cfg >> "ACE" >> "ACE_CLUSTERBOMBS" >> "deployHight") select 0)
#define __DROPHEIGHT_MAX (getArray(__cfg >> "ACE" >> "ACE_CLUSTERBOMBS" >> "deployHight") select 1)
#define __SIMULATION getText(__cfg >> "ACE" >> "ACE_CLUSTERBOMBS" >> "simulation")
#define __DEPLOYTIME 8

private["_unit","_weapon","_ammo","_bomb","_pos"];
PARAMS_7(_unit,_weapon,_muzzle,_mode,_ammo,_magazine,_bomb);

_pos = (getPosASL _bomb) select 2;

TRACE_5("",_unit,_weapon,_ammo,_bomb,_pos);
TRACE_6("",__CLUSTERAMMO,__CLUSTERCOUNT,__DROPHEIGHT_MIN,__DROPHEIGHT_MAX,__SIMULATION,__DEPLOYTIME);

if (_pos < __DROPHEIGHT_MIN || {_pos > __DROPHEIGHT_MAX}) exitWith {
	// TODO: Bomb cannot deploy and falls to ground creating an UXO
	// TODO: Bomblets become spread too far
	TRACE_1("Too low / too high", _pos);
};

switch (toUpper(__SIMULATION)) do {
	case "ACE_CEM": {
		TRACE_1("CEM","");
		[_unit,_bomb,__CLUSTERAMMO,__CLUSTERCOUNT,__DEPLOYTIME] spawn FUNC(CEM);
	};
	case "ACE_SFW": {
		TRACE_1("SWF","");
		[_unit,_bomb,__CLUSTERAMMO,__CLUSTERCOUNT,__DEPLOYTIME] spawn FUNC(SFW);
	};
	case "ACE_RUNWAY": {
		TRACE_1("Durandal","");
		[_unit,_bomb] spawn FUNC(durandal);
	};
};
