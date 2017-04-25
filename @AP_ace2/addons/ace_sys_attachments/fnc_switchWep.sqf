//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_something,_newWeap);

if (!(isClass(configFile>>"CfgWeapons">>_newWeap))) exitWith {ERROR(format["Weapon Attachment Variant does not Exist, please bug-report! (%1)", _newWeap]);};

_unit = player;
_oldWeap = currentWeapon _unit;
_newType = getNumber(configFile>>"CfgWeapons">>_newWeap>>"type");
_oldType = getNumber(configFile>>"CfgWeapons">>_oldWeap>>"type");
TRACE_4("Type",_oldWeap,_oldType,_newWeap,_newType);
if (_oldType != _newType) exitWith {TRACE_2("Type Mismatch",_oldType,_newType);};
if (vehicle _unit != _unit) exitWith {TRACE_1("In Veh",vehicle _unit);};
if (_oldWeap == _newWeap) exitWith {TRACE_2("Cant Dupe",_oldWeap,_newWeap);};
if !(isNil QUOTE(GVAR(doCQB)))	exitWith {TRACE_1("Inpro",GVAR(doCQB));};

GVAR(doCQB) = true;
//Create dummy
_dummy = createAgent ["ACE_CivDummy", [0,0,0], [], 0, "FORM"];
TRACE_1("Created",group _dummy); //null-group needs no cleanup
_unit reveal _dummy; //prevent slowdowns during MP
removeAllWeapons _dummy;
removeAllItems _dummy;
_dummy addWeapon _newWeap;
waitUntil{_dummy hasWeapon _newWeap};
TRACE_1("Dummy",weapons _dummy);
//Take weapon seamlessy, without auto-reload using action
_unit action ["TAKEWEAPON",_dummy,_newWeap];
waitUntil{_unit hasWeapon _newWeap};
_unit removeWeapon _oldWeap;
//Recover stray mags
TRACE_1("Dummy",magazines _dummy);
{_bfMags = count(magazines _dummy); _dummy action ["PUTMAGAZINE",_unit,_x]; waitUntil{_bfMags != count (magazines _dummy)}; TRACE_1("Recover",_x);} forEach (magazines _dummy);
//Clean up
deleteVehicle _dummy;
GVAR(doCQB) = Nil;