#include "script_component.hpp"
#define SCRIPTNAME QGVAR(fnc_fired)
#define __cfgw configFile >> "CfgWeapons" >> _weapon

//#define DEBUG_MODE_FULL
//	This script makes rockets turn into the trajectory
//	as opposed to them keeping the initial facing/pitch during the whole flight.
//	On each iteration the new direction is calculated based on current speed vector.

//	This version handles hand-held AT launchers

private ["_bullet", "_el","_zerofov"];

PARAMS_2(_unit,_weapon);
_bullet = _this select 6; // uses BIS Fired EH

if (isNull _bullet) exitwith {
	WARNING("Rocket NOT Captured");
	TRACE_2("",_unit,_weapon);
};

if (player == gunner _unit) then {
	//sight adjustment for AT launchers - turns the rocket before applying dispersion
	//fixed zero for BDC optics when current fov equals that of the optics

	if (isNumber(__cfgw >> "ace_at_zero")) then
	{
		_zerofov = getNumber(__cfgw >> "ace_at_zero_fov");
		_el = if (_zerofov > 0) then { abs(1 - ((call cba_fnc_getfov) select 0)/_zerofov)} else {999};
		if (getNumber(__cfgw >> "ace_sa_enabled") == 0 || _el <= 0.1) then
		{
			_el = getNumber(__cfgw >> "ace_at_zero");
			_el = deg (_el/1000);
			[_bullet, _el] call ace_sys_sight_adjustment_at_fnc_fired;
		} else
		{
			if !(isNil "ACE_SYS_SA_AT") then
			{
				if (_weapon == ACE_SYS_SA_AT select 2) then
				{
					[_bullet, ACE_SYS_SA_AT select 4] call ace_sys_sight_adjustment_at_fnc_fired;
				};
			};
		};
	} else
	{
		if !(isNil "ACE_SYS_SA_AT") then
		{
			if (_weapon == ACE_SYS_SA_AT select 2) then
			{
				[_bullet, ACE_SYS_SA_AT select 4] call ace_sys_sight_adjustment_at_fnc_fired;
			};
		};
	};
	//dispersion
	[_this,_bullet,1] call FUNC(dispersion);
	//find and set proper vectorup continuosly
	[_bullet, 0.05, 0] spawn FUNC(turnrocket);

} else { //AI dispersion
	_skill = (skill _unit) max 0.1;	//happens to be zero!
	_aidisp = 2 + 0.2/_skill;
	/*if (_unit isKindOf "Man") then {
		_aidisp = 7 + 0.2/_skill;
	};*/
	TRACE_3("",_unit,_weapon,_aidisp);
	[_this,_bullet,_aidisp] call FUNC(dispersion);
};
