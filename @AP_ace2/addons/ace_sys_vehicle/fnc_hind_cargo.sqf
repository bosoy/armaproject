// Script by zGuba A.D. 2009
// Lock aircraft cargo when airborne
// Automated AI cargo doors

#include "script_component.hpp"

//#define __cargoCapacity (getNumber (configFile >> "CfgVehicles" >> _typeOf >> "transportSoldier"))
#define __doorsClosed ((_vehicle animationPhase "dvere_l_vrch" == 0) && (_vehicle animationPhase "dvere_p_vrch" == 0)) && alive _vehicle
#define __doorsOpened ((_vehicle animationPhase "dvere_l_vrch" == 1) || (_vehicle animationPhase "dvere_p_vrch" == 1)) && alive _vehicle

PARAMS_1(_vehicle);

//	_typeOf = typeOf _vehicle;
//	_cargoCapacity = __cargoCapacity;

while {alive _vehicle} do {
	_pilot = driver _vehicle;
	_gunner = gunner _vehicle;
	if !(isNull _pilot && {isNull _gunner}) then {
		_crew = [_pilot, _gunner];
		_cargo = (crew _vehicle) - [driver _vehicle, gunner _vehicle];
		_assignedCargo = assignedCargo _vehicle;
		_flightHeight = (getPos _vehicle) select 2;
		_velocity = (velocity _vehicle) call ACE_fnc_magnitude;
		if (__doorsClosed) then {
			if (_velocity < 5 && {_flightHeight < 6}) then {
				if (({!isPlayer _x && (_x distance _vehicle < 50)} count _assignedCargo) != {!isPlayer _x} count _cargo) then {
					if (player in _crew) then {
						localize "STR_EP1_DN_C130J_STATIC_EP1_USERACTIONS_CARGOOPEN" spawn ace_fnc_visual;
					} else {
						if !(isPlayer _pilot || {isPlayer _gunner}) then {
							if (local _vehicle) then {
								{
									_vehicle animate [_x, 1]
								} forEach ["dvere_l_vrch","dvere_l_spod","dvere_p_vrch","dvere_p_spod"];
							//	[_vehicle, "doors"] call CBA_fnc_globalSay3D;
							};
						};
					};
				};
			};
		};

		if (__doorsOpened) then {
			if (_velocity >= 5 || {_flightHeight >= 6}) then {
				if (player in _crew) then {
					localize "STR_EP1_DN_C130J_STATIC_EP1_USERACTIONS_CARGOCLOSE" spawn ace_fnc_visual;
				} else {
					if !(isPlayer _pilot || {isPlayer _gunner}) then {
						if (local _vehicle) then {
							{
								_vehicle animate [_x, 0]
							} forEach ["dvere_l_vrch","dvere_l_spod","dvere_p_vrch","dvere_p_spod"];
						//	[_vehicle, "doors"] call CBA_fnc_globalSay3D;
						};
					};
				};
			};
		};
	};

	sleep 4;
};