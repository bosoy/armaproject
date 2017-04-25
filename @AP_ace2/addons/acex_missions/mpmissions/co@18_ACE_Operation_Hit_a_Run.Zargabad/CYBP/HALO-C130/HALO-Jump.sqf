/*
===============================================================================================
HALO-Jump - by Cyborg11
Version: 1.0
Date: 07.07.2010
Description: Script to use HALO if you jump out of a static c130
				
Parameter:	nul = [_unit, _c130] execVM "HALO-Jump.sqf";

			_unit = name of soldier which can be use the HALO jump
			_c130 = name of the static c130
===============================================================================================
*/


_unit = _this select 0;
If (!local _unit) exitWith{};

_c130 = _this select 1;
_jumpdist = 14;

While {alive _unit} do
{
	If (_unit getVariable "bis_fnc_halo_now") exitWith{};
	_dist = _unit distance (_c130 modelToWorld [0,-8,-5]);
	If (_dist >= _jumpdist && ((_c130 animationPhase "ramp_bottom") >= 0.6) && ((_c130 animationPhase "ramp_top") >= 0.6)) then 
	{
		//[_unit, (getPosATL _unit) select 2] spawn BIS_fnc_halo;
		[_unit, (getPosATL _unit) select 2] exec "ca\air2\halo\data\Scripts\HALO_init.sqs"; 
	};
	sleep 1;
};