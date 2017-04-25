//mark damaged vehicle as knocked out, "neutralize" it by making civilian and locking
//should only run on server
//neutralizing doesnt work :/
//so the vehicle is just killed without explosion


//#define __dummyPos [100,100,0]
#define __dummyPos getArray (configFile >> "CfgWorlds" >> worldname >> "centerPosition")
#include "script_component.hpp"

//if (! local _this) exitwith {};
if (! alive _this) exitwith {};
if (_this getvariable "ace_ko") exitwith {};
if ({alive _x} count (crew _this) > 0) exitwith {};

//run it on server only
//if !(isServer) exitwith
//{
//	[0,{_this spawn FUNC(set_ko)},_this] call CBA_fnc_globalExe_cute;
//};

private ["_dummy","_dummy2","_dummy3"];

_this setvariable ["ace_ko",true,true];
_this setfuel 0;
_this setvehicleammo 0;
[_this] call FUNC(killcrew);
_this setdamage 1;

[QGVAR(lock), [_this, true]] call ACE_fnc_receiverOnlyEvent;



// OLD CODE //

//{moveout _x} foreach (crew _this);
/*
//_this setcaptive true;
//Priest
_dummy = ace_vehdmg_dummygroup createUnit ["ACE_CivDummy",__dummyPos,[], 0, "NONE"];
_dummy2 = ace_vehdmg_dummygroup createUnit ["ACE_CivDummy",__dummyPos,[], 0, "NONE"];
_dummy3 = ace_vehdmg_dummygroup createUnit ["ACE_CivDummy",__dummyPos,[], 0, "NONE"];

waitUntil { alive _dummy && alive _dummy2 && alive _dummy3};

[_dummy,_dummy2,_dummy3] join ace_vehdmg_dummygroup;
{
_x setpos (getpos _this);
_x disableAI "TARGET";
_x disableAI "AUTOTARGET";
_x disableAI "MOVE";
_x disableAI "ANIM";
//_x setskill 0.01;
_x allowfleeing 0;

} foreach [_dummy,_dummy2,_dummy3];

_dummy assignAsCommander _this;
_dummy moveincommander _this;
_dummy2 assignAsDriver _this;
_dummy2 moveindriver _this;
_dummy3 assignAsGunner _this;
_dummy3 moveinGunner _this;

sleep 2;
{
//_x action ["EJECT",_this];
moveout _x;
_x setpos __dummyPos;
_x setdamage 1;
deletevehicle _x;
} foreach [_dummy,_dummy2,_dummy3];

[-1,{_this lock true},_this] call CBA_fnc_globalExe_cute;


if (5 > random 10) then {_this setHit ["vez",1]};
if (5 > random 10) then {_this setHit ["gun",1]};
if (5 > random 10) then {_this setHit ["telo",0.9]};
if (5 > random 10) then {_this setHit ["pas_l",1]};
if (5 > random 10) then {_this setHit ["pas_p",1]};
*/

//marking ko'd for test
//_dummy = "MetalBucket" createvehicle (getpos _this);
//_dummy attachto [_this,[0,0,3]];
#ifdef DEBUG_MODE_FULL1
[format["%1 is knocked out",_this]] call CBA_fnc_debug;
#endif
