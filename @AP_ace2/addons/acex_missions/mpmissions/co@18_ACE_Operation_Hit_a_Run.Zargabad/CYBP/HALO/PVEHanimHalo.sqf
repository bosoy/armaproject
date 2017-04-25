/*
===============================================================================================
PVEHanimHalo - by Cyborg11
Version: 1.0
Date: 07.07.2010
Description: Script to broadcast the HALO animation in MP
				
Parameter:	CYBP_animHalo = [_unit, _anim, _cmd];
			publicVariable "CYBP_animHalo";
			
			_unit = object which is using HALO
			_anim = the animation
			_cmd = either "switchMove" or "playMoveNow" 
===============================================================================================
*/


_unit = _this select 0;
_anim = _this select 1;
_cmd = _this select 2;

switch (_cmd) do
{
	case "switchMove" : {_unit switchMove _anim};
	case "playMoveNow" : {_unit playMoveNow _anim};
};