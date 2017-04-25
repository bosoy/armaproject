// Displays warning when player's turret is outside guidance limits

#include "script_component.hpp"

#define __MainTurret configFile >> "CfgVehicles" >> _vType >> "Turrets" >> "MainTurret"
private ["_vehicle","_clear","_vehicle","_vType","_sleep_time"];

if (!isDedicated) then
{
	while {true} do
	{
		if (isNull player) then
		{
			waitUntil {sleep 5; !isNull player};
		};

		_vehicle 	= vehicle player;
		_sleep_time = 5;
		
		if (_vehicle != player) then
		{
			_vType = typeOf _vehicle;
			if (getNumber (__MainTurret >> QGVAR(limitsOn)) > 0) then
			{
				if ((player in [driver _vehicle, gunner _vehicle]) && {(isNil {_vehicle getVariable QGVAR(missile_flying)})}) then
				{
					_sleep_time = 0.125;
					_guidanceDir = [_vehicle, _vType, _vehicle weaponDirection (getText (__MainTurret >> QGVAR(tracker))),false,__MainTurret] call FUNC(opt_limits);

					if (_guidanceDir select 1) then
					{
						_vehicle setVariable [QGVAR(exceeded),1];
					/*	// TODO: Graphical indication for pilot
						if (((currentWeapon _vehicle) isKindOf "MissileLauncher") && {!_clear}) then
						{
							hint format [localize "STR_ACE_TARGETOUTSIDESEEKERLIMITS", _guidanceDir select 2, _guidanceDir select 3];
						}
						else
						{
							hintSilent format [localize "STR_ACE_TARGETOUTSIDESEEKERLIMITS", _guidanceDir select 2, _guidanceDir select 3];
						};
					*/
					}
					else
					{
						_vehicle setVariable [QGVAR(exceeded),nil];
					};
				};
			};
		};
		
		sleep _sleep_time;
	};
};
