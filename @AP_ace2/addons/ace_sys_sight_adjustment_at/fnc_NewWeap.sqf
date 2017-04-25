#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

private["_wpn","_wcfg","_lst"];
_wpn = _this;

if (getNumber(configFile >> "cfgWeapons" >> _wpn >> "ace_sa_enabled") == 0) exitwith {};	//SA not supported

_wpn_in_the_list = false;
_wcfg = configFile >> "cfgWeapons" >> _wpn;

ACE_SYS_SA_AT = ACE_SYS_SA_NEW;
ACE_SYS_SA_SET_DEFAULTELEVATION(getNumber (_wcfg >> "ace_sa_defaultelevation"));
//ACE_SYS_SA_SET_MINELEVATION(getNumber (_wcfg >> "ace_sa_minrange"));
//ACE_SYS_SA_SET_MAXELEVATION(getNumber (_wcfg >> "ace_sa_maxrange"));
//ACE_SYS_SA_SET_ADJELEVATION(getNumber (_wcfg >> "ace_sa_steprange"));
//ACE_SYS_SA_SET_TABLE(getArray (_wcfg >> "ace_sa_table_elev"));

ACE_SYS_SA_SET_ENABLED(true);
ACE_SYS_SA_SET_CURUNIT(player);
ACE_SYS_SA_SET_CURWEAPON(_wpn);
ACE_SYS_SA_SET_CURELEVATION(0);
0 call FUNC(setDegrees);

{ // looking if player has already used this weapon and setting last recorded elevation
	if (_wpn == _x select 0) exitwith {
		ACE_SYS_SA_SET_CURELEVATION(_x select 1);
		0 call FUNC(setDegrees);
		_wpn_in_the_list = true;
	};
} foreach ACE_SYS_SA_AT_LIST;

//if the weapon hasnt been used before, add it to the list
if !(_wpn_in_the_list) then {
	_lst = ACE_SYS_SA_AT_LIST;
	_entry = [_wpn, ACE_SYS_SA_CURELEVATION];
	PUSH(_lst,_entry);
	ACE_SYS_SA_SET_AT_LIST(_lst);
};

cutRsc ["ACE_RscGeneric","PLAIN"];
#define __dsp (uiNameSpace getVariable "ACE_RscGeneric")
#define __ctrl __dsp displayCtrl 135136
__ctrl ctrlSetText format["%1: %2 m", localize "STR_ACE_SA_ATGL_RANGE", ACE_SYS_SA_CURELEVATION];
