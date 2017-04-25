//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

ADDON = false;

LOG(MSG_INIT);

FUNC(partcheck) = {
	/* (C) by rocko 2011 */
	PARAMS_1(_unit);
	if !("ACE_SpareBarrel" in (weapons _unit)) then {
		_unit addWeapon "ACE_SpareBarrel";
	};
};

FUNC(jam_static_loop) = {
	/* (C) by rocko 2011 */
	PARAMS_1(_vehicle);
	_ammocount = _vehicle getVariable [QGVAR(ac),0];
	_magazine = _vehicle getVariable [QGVAR(mag),"FakeMagazine"]; _magazinecapacity = getNumber(configFile >> "CfgMagazines" >> _magazine >> "count");
	_weapon = _vehicle getVariable [QGVAR(wep),"FakeWeapon"];
	_action_id = _vehicle getVariable [QGVAR(aid),0];
	waituntil {
		sleep 0.5;
		TRACE_1("wait",_vehicle);
		((_vehicle ammo _weapon)>_ammocount || {isNil {_vehicle getVariable QGVAR(jammed)}} || {isNull gunner _vehicle} || {!(alive gunner _vehicle)})
	};
	_vehicle removeAction _action_id;
	_vehicle setVariable [QGVAR(aid),-1,true];
	if ((_vehicle ammo _weapon)>_ammocount || {isNil {_vehicle getVariable QGVAR(jammed)}}) then {
		_vehicle addMagazine _magazine;
		_vehicle setVehicleAmmo _ammocount/_magazinecapacity;
		if (vehicle player == _vehicle) then {
			localize "STR_ACE_JAMCLEAR" spawn ace_fnc_visual;
		};
	};
};

FUNC(cookoff) = {
	/* (C) by rocko 2011,2012 */
	PARAMS_3(_unit,_weapon,_mode);
	
	_unit setVariable [QGVAR(cookoff),true];
	_cur_temp1 = GVAR(cur) select 1;
	_duration = time + 10;
	while { time < _duration } do {
		sleep 5; // Sleep to wait until cartridge is heated up
		// Check wether temperature has risen after heating time
		_cur_temp2 = (GVAR(cur) select 1) - (GVAR(cur) select 2)*5;
		if (!GVAR(jammed) && {_cur_temp2 >= _cur_temp1} && {currentWeapon _unit == _weapon}) then {
		// tadadadada!
			// useless, does not work for player and overheating is only available for players
			// the goal behind it is to make the weapon fire without the player pulling the trigger
			//_unit fireAtTarget [objNull,_weapon];
		};
	};
	_unit setVariable [QGVAR(cookoff),false];
};

FUNC(cookoff_static) = {
	/* (C) by rocko 2011 */
	// TODO: Finish
};

ADDON = true;
