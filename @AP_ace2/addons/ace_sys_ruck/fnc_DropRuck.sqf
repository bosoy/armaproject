//#define DEBUG_MODE_FULL
#include "script_component.hpp"

/* Manually dropped ruck. (Drop Ruck button via handleGear functions)
	Moves ruck contents from player object variable to cargo in a ruck crate, and adds a Take object action.
*/
private ["_magAry", "_wepAry", "_ruck", "_orgRuck", "_cratyp", "_crate", "_unitdir", "_unitpos"];
PARAMS_1(_unit);

//grab initial info
_magAry = _unit getVariable ["ACE_RuckMagContents",[]];
_wepAry = _unit getVariable ["ACE_RuckWepContents",[]];
_ruck = _unit call FUNC(FindRuck);
_orgRuck = ""; //only needed if ruckcrate not found
//format ruck-ruckcrate
_cratyp = _ruck + "_crate";
if !(isClass(__CONF_VEHICLES >> _cratyp)) then {
	_orgRuck = _ruck;
	_cratyp = "ACE_Rucksack_crate";
};

//cannot be done in a vehicle, misc checks.
if ( alive _unit && {vehicle _unit == _unit} && {(_unit call FUNC(HasRuck)) && _cratyp != ""} ) then {
	//remove ruck weapon from correct slot
	if (_unit hasWeapon _ruck) then {_unit removeWeapon _ruck} else {_unit setVariable ["ACE_weapononback", "", true];};

	//remove ruck contents from player
	_unit setvariable ["ACE_RuckMagContents", []];
	_unit setvariable ["ACE_RuckWepContents", []];

	//create ruck crate
	_crate = createVehicle [_cratyp,[0,0,0],[],0,"NONE"];
	_unitdir = getDir _unit;
	_unitpos = getPosATL _unit;
	_unitpos = [(_unitpos select 0) + (sin _unitdir),(_unitpos select 1) + (cos _unitdir),_unitpos select 2];

	_crate setPosATL _unitpos;
	_crate setVectorDirAndUp [[-0.0204803,-0.585819,0.810183],[0.00794978,-0.810423,-0.585792]];
	_unit reveal _crate; //reveal to owner (less wait)

	_crate setVariable ["ACE_RuckOwner",format[localize "STR_ACE_SYS_RUCK_OWNRUCK",name _unit],true]; //global name tag

	{_crate addMagazineCargoGlobal [_x select 0, _x select 1]} forEach _magAry;
	{_crate addWeaponCargoGlobal _x} forEach _wepAry;
	[QGVAR(glbRuckAct), [_crate,_orgRuck]] call CBA_fnc_globalEvent; //global handling (will add take action)
	TRACE_3("glbRuckAct",_magAry,_wepAry,_orgRuck);
};

TRACE_3("Player DRuck",_ruck,_cratyp,_crate);
