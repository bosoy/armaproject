// #define DEBUG_MODE_FULL
#include "script_component.hpp"
/*	actionmon.sqf

	Manages actions for player-controlled AI so that they can interact with
	the crewed weapons components (tripods, weapons and fully assembled
	weapons)

	These are the actions that we manage here. They were previously in
	a UserActions config class in ace_c_useractions but the performance
	penalty was too large - when you selected one or more of your units,
	the framerate dropped considerably.

	ACE_AIMountCrewMG		"Mount Machine Gun"
	ACE_AIPickupCrewTripod   "Pickup Tripod"
	ACE_AIRotateMGLeft	   "Rotate MG Left"
	ACE_AIRotateMGRight	  "Rotate MG Right"
	ACE_AILoadMGAmmo		 "Load/link Ammo"
	ACE_AIUnloadMGAmmo	   "Unload/unlink Ammo"
	ACE_AIUnmountCrewMG	  "Unmount MG"

*/
#define UPDATE_ACTIONS x\ace\addons\sys_crewserved\update_actions.sqf

#define TITLE_MOUNT localize "STR_ACE_CREW_MOUNT"
#define TITLE_UNMOUNT localize "STR_ACE_CREW_UNMOUNT"
#define TITLE_PICKUP localize "STR_ACE_CREW_PICKUP"
#define TITLE_LEFT localize "STR_ACE_CREW_LEFT"
#define TITLE_RIGHT localize "STR_ACE_CREW_RIGHT"
#define TITLE_LOAD localize "STR_ACE_CREW_LOAD"
#define TITLE_UNLOAD localize "STR_ACE_CREW_UNLOAD"
#define TITLE_DEPLOY localize "STR_ACE_CREW_TRIPOD"

#define SCRIPT_MOUNT QPATHTO_F(fnc_mount)
#define SCRIPT_UNMOUNT QPATHTO_F(fnc_unmount)
#define SCRIPT_PICKUP QPATHTO_F(pickupTripod)
#define SCRIPT_LEFT QPATHTO_F(fnc_rotate)
#define SCRIPT_RIGHT QPATHTO_F(fnc_rotate)
#define SCRIPT_LOAD QPATHTO_F(fnc_load)
#define SCRIPT_UNLOAD QPATHTO_F(fnc_unload)
#define SCRIPT_DEPLOY QPATHTO_F(deployTripod)


#define ARGS_MOUNT []
#define ARGS_UNMOUNT []
#define ARGS_PICKUP []
#define ARGS_LEFT [-10]
#define ARGS_RIGHT [10]
#define ARGS_LOAD []
#define ARGS_UNLOAD []
#define ARGS_DEPLOY []

// [title, filename, (arguments, priority, showWindow, hideOnUse, shortcut)]
#define AA_MOUNT [TITLE_MOUNT, SCRIPT_MOUNT, ARGS_MOUNT, -1]
#define AA_UNMOUNT [TITLE_UNMOUNT, SCRIPT_UNMOUNT, ARGS_UNMOUNT, -1]
#define AA_PICKUP [TITLE_PICKUP, SCRIPT_PICKUP, ARGS_PICKUP, -1]
#define AA_LEFT [TITLE_LEFT, SCRIPT_LEFT, ARGS_LEFT, -1]
#define AA_RIGHT [TITLE_RIGHT, SCRIPT_RIGHT, ARGS_RIGHT, -1]
#define AA_LOAD [TITLE_LOAD, SCRIPT_LOAD, ARGS_LOAD, -1]
#define AA_UNLOAD [TITLE_UNLOAD, SCRIPT_UNLOAD, ARGS_UNLOAD, -1]
#define AA_DEPLOY [TITLE_DEPLOY, SCRIPT_DEPLOY, ARGS_DEPLOY, -1]

private [
	"_grp","_fUpdateActions",
	"_fMount", "_fRotate", "_fLoad", "_fUnload", "_fUnmount","_fPickup",
	"_mountAction","_unmountAction","_pickupAction","_leftAction",
	"_rightAction","_loadAction","_unloadAction",
	"_fAddAction","_fRemoveAction"
];

_fUpdateActions = COMPILE_FILE2(UPDATE_ACTIONS);
_fMount   = {[_this,6,true] call FUNC(checkMountCrewMG)};
_fRotate  = {[_this,'rotate',6] call FUNC(checkNearCrewMG)};
_fLoad	= {[_this,'load',6] call FUNC(checkNearCrewMG)};
_fUnload  = {[_this,'unload',6] call FUNC(checkNearCrewMG)};
_fUnmount = {[_this,'unmount',6] call FUNC(checkNearCrewMG)};
_fPickup  = {[_this,6] call FUNC(checkPickupTripod)};
_fDeployTripod = { configName (inheritsFrom (configfile >> 'CfgWeapons' >> secondaryWeapon _this)) == 'ACE_CrewTripodProxy' };

_fAddAction = {
		private ["_aidVar","_aid","_params"];
		PARAMS_2(_unit,_action);
		_aidVar = format["ace_sys_crewserved_%1", _action];
		_aid = _unit getVariable [_aidVar, -1];
		if (_aid == -1) then {
			_params = [];
			switch (tolower _action) do {
				case "deploy":  { _params = AA_DEPLOY; };
				case "mount":   { _params = AA_MOUNT; };
				case "unmount": { _params = AA_UNMOUNT; };
				case "pickup" : { _params = AA_PICKUP;};
				case "left":	{ _params = AA_LEFT;};
				case "right":   { _params = AA_RIGHT;};
				case "load" :   { _params = AA_LOAD;};
				case "unload":  { _params = AA_UNLOAD;};
				default {};
			};
			if (count _params > 0) then {
				_aid = _unit addAction _params;
				_unit setVariable [_aidVar, _aid];
				#ifdef DDEBUG_MODE_FULL
					_unit globalChat format["fAddAction: %1, id %2, %3",_action, _aid,_params];
				#endif
		};
	};
};
_fRemoveAction = {
		private ["_aidVar","_aid"];
		PARAMS_1(_unit);
		_aidVar = "ace_sys_crewserved_" + str(_this select 1);
		_aid = _unit getVariable _aidVar;
		if (_aid > -1) then {
			_unit removeAction _aid;
			_unit setVariable [_aidVar, -1];
		};
};
_fRemoveActions = {
		{
			[_this, _x] call _fRemoveAction;
		} forEach GVAR(CSW_ACTIONS);
};
_fGrpRemoveActions = {
		private ["_grp","_units"];
		_grp = _this;
		_units = (units _grp)-[player];
		{_x call _fRemoveActions} forEach _units;
};
while {true} do {
		waitUntil {alive player};
		sleep 1;
		_grp = group player;
		while {alive player && {player == leader _grp}} do {
			_grp = group player;
			_grp call _fUpdateActions;
			sleep 2;
		};
		_grp call _fGrpRemoveActions;
		sleep 1;
};
