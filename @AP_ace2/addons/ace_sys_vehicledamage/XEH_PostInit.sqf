#include "script_component.hpp"

//#define __dummyPos [100,100,0]
#define __dummyPos getArray (configFile >> "CfgWorlds" >> worldname >> "centerPosition")

#define __dummyPosSet [__dummyPos select 0, __dummyPos select 1, random 3000]

[] spawn { //this spawns on server when mission starts
	private ["_dummy","_civside"];

	waituntil {time > 1};

	_civside = createCenter civilian;
	ace_vehdmg_dummygroup = createGroup _civside;
	//ACE_CivDummy
	_dummy = ace_vehdmg_dummygroup createUnit ["Priest",__dummyPos,[], 0, "FORM"];
	waitUntil { alive _dummy };
	_dummy disableAI "TARGET";
	_dummy disableAI "AUTOTARGET";
	_dummy disableAI "MOVE";
	_dummy disableAI "ANIM";
	[_dummy] join ace_vehdmg_dummygroup;

	TRACE_3("",_civside,GVAR(dummygroup),_dummy);
};
