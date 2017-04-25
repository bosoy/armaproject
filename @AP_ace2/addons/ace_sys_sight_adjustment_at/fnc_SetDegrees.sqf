#include "script_component.hpp"
//sets current elevation in degrees
#include "Script_SightAdjustmentConfig.hpp"

#define __mcfg configFile >> "cfgMagazines" >> _mag
#define __wcfg configFile >> "cfgWeapons" >> ACE_SYS_SA_CURWEAPON

private["_el","_table","_mag","_cfg","_cnt","_range","_cur","_j"];
_mag = currentmagazine player;
_cfg = __wcfg;

if (isClass(configFile >> "cfgMagazines" >> _mag)) then {
	if (isArray(__mcfg >> "ace_sa_table_elev")) then {
		_cfg = __mcfg;
	};
};

_table = getArray(_cfg >> "ace_sa_table_elev");
_cnt = count _table - 1;
_range = ACE_SYS_SA_CURELEVATION;

//current range not in the table, defaulting to min range
_j = 1;
for "_i" from 1 to _cnt do {
	if (_range == (_table select _i) select 0) exitwith {_j = _i + _this};
};
if (_j <= 0) then {
	_j = 1;
} else {
	if (_j > _cnt) then {_j = _cnt};
};

_cur = _table select _j;
_range = _cur select 0;
_el = deg (((_cur select 1) - ACE_SYS_SA_DEFAULTELEVATION)/1000);
ACE_SYS_SA_SET_CURELEVATION(_range);
if (ACE_SYS_SA_CURELEVATION_DEG != _el) then {
	ACE_SYS_SA_SET_CURELEVATION_DEG(_el);
};
