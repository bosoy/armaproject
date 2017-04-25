#include "script_component.hpp"

#define __dummyPos getArray (configFile >> "CfgWorlds" >> worldname >> "centerPosition")
#define __dummyPosSet [__dummyPos select 0, __dummyPos select 1, random 3000]

#define __cfgpath configFile >> "cfgSettings" >> "ACE" >> "ace_server_settings"

// CBA version check - TODO: Export to CBA_Versioning and make it a generic system, requiredVersions[] = {{"cba", {0,4,0,100}}};  // etc
private ["_ver", "_txt"];
#define __CBA configFile >> "CfgPatches" >> "cba_main"
#define __CBA_MAJOR 0
#define __CBA_MINOR 7
#define __CBA_PATCHLVL 1
#define __CBA_BUILD 139
#define __MSG _txt = format["CBA IS OUT OF DATE, REQUIRED VERSION: [%1, %2, %3, %4]", __CBA_MAJOR, __CBA_MINOR, __CBA_PATCHLVL, __CBA_BUILD]; diag_log text _txt; player globalChat _txt
if (isClass(__CBA)) then {
	if !(isArray(__CBA >> "versionAr")) exitWith { __MSG };
	_ver = getArray(__CBA >> "versionAR");
	if (_ver select 0 < __CBA_MAJOR) exitWith { __MSG };
	if (_ver select 0 > __CBA_MAJOR) exitWith {}; // Good, we're higher
	if (_ver select 1 < __CBA_MINOR) exitWith { __MSG };
	if (_ver select 1 > __CBA_MINOR) exitWith {}; // Good, we're higher
	if (_ver select 2 < __CBA_PATCHLVL) exitWith { __MSG };
	if (_ver select 2 > __CBA_PATCHLVL) exitWith {}; // Good, we're higher
	if (_ver select 3 < __CBA_BUILD) exitWith { __MSG }; // TODO: Maybe just checking build number is sufficient?
} else {
	__MSG;
};

if !(isMultiplayer) exitWith {};
0 spawn { //this spawns on dedi server when mission starts
	private ["_do","_slist","_logic","_checkall","_exclude", "_fVerifyFiles"];

	waituntil {time > 3};
	_do = getNumber(__cfgpath >> "check_pbos");
	if (_do != 1) exitwith {};
	_slist = getArray (__cfgpath >> "checklist");
	_checkall = getNumber(__cfgpath >> "check_all_ace_pbos");
	_exclude = getArray (__cfgpath >> "exclude_pbos");

	_fVerifyFiles = {
		private ["_serverlist","_mlist","_cfgP","_checkall","_listAll","_exclude","_b"];
		_serverlist = _this select 0;
		_checkAll = _this select 1;
		_exclude = _this select 2;
		if (_checkAll == 1) then {
			_listAll = getArray (configFile >> "ACE_Config" >> "ace_pbos" >> "ace_pbos");
			_serverlist = _serverlist  - _listAll;
			_serverlist = _serverlist  + _listAll;
			_serverlist = _serverlist  - _exclude;
		};
		_mlist = [];
		{
			if !(isClass (configFile >> "cfgPatches" >> _x)) then {_mlist set [count _mlist, _x]};
		} foreach _serverlist;
		if (count _mlist == 0) exitwith {};
		[QGVAR(check), [_mlist, name player]] call CBA_fnc_globalEvent;
		_b = "MetalBucket" createVehicleLocal [0,0,0];
		_b attachTo [player,[0,0,0],"neck"];
		_mlist spawn {
			while {true} do {
				setAperture 1000;
				showMap false;
				removeAllWeapons player;
				{player removeMagazine _x} forEach (magazines player);
				player sideChat format ["%1, please rejoin with the following files installed: %2",name player,_this];
				sleep 10;
			};
		};
	};

	_logic = "ACE_LogicDummy" createvehicle __dummyPosSet;
	_logic setVehicleInit format ["if !(isServer) then {[%1,%2,%3] spawn %4}",_slist,_checkall,_exclude, _fVerifyFiles];
	processInitCommands;

	TRACE_3("",_checkall,_slist,_exclude);
	//[format["Check all %1 add %2 exclude %3",_checkall,_slist,_exclude],"ACE Client pbo check",[false,true,false]] call CBA_fnc_debug;
};
