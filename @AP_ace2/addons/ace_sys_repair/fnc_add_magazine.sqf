//#define DEBUG_MODE_FULL
#include "script_component.hpp"

[] spawn {
	_veh = GET_SELECTED_VEHICLE;
	_magazine = GET_SELECTED_DATA(66368);
	_cap = [] call FUNC(get_capacity);
	_index_turret = GET_SELECTED_TURRET;
	
	TRACE_4("",_veh,_magazine,_cap,_index_turret);

	_repairTime = 12; // TODO
	if (((_cap select 0) + getNumber(configFile >> "CfgMagazines" >> _magazine >> "count") <= _cap select 1)) then {
		if ((_veh isKindOf "Plane" || {_veh isKindOf "Helicopter"}) && {_index_turret select 0 < 1}) then {
				_veh removeMagazine _magazine; // Remove empty ones first
				_veh addMagazine _magazine;
				_magazine_not_compatible = true;
				{
					if (_magazine in getArray(configFile >> "CfgWeapons" >> _x >> "magazines")) then{
						_magazine_not_compatible = false;
					};
				} forEach (weapons _veh);
				if (_magazine_not_compatible) then {
					{
						{
							if (_magazine_not_compatible && {_magazine in (getArray(configFile >> "CfgWeapons" >> _x >> "magazines"))}) then {
								_magazine_not_compatible = false;
								_veh addWeapon _x;
							};
						} forEach _x;
					} forEach CHANGABLE_WEAPONS;
				};
		}else {
			[QGVAR(setBusyRea), [_veh, _repairTime]] call CBA_fnc_globalEvent;

			{ __HIDE(_x); } foreach [66371,66372,66373];
			_veh setVariable ["ACE_PB_Result", 0];
			[10,[localize "STR_CFG_CUTSCENES_REARM"],true,false,_veh] spawn ace_progressbar;
			waitUntil { (_veh getVariable "ACE_PB_Result" != 0) };
			if (_veh getVariable "ACE_PB_Result" == 1) then {
				TRACE_1("Adding magazine","");
				_veh addMagazineTurret [_magazine,GET_SELECTED_TURRET];
			};
			[QGVAR(unsetBusyRea), _veh] call CBA_fnc_globalEvent;
			{ __SHOW(_x); } foreach [66371,66372,66373];
		};
	};
	[] call FUNC(fill_current_magazines_list);
	[_veh] call FUNC(fill_transportMagazines);
};
