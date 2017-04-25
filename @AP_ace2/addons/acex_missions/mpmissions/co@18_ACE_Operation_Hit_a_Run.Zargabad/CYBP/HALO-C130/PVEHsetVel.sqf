/*
===============================================================================================
PVEHanimHalo - by Cyborg11
Version: 1.0
Date: 07.07.2010
Description: Script to broadcast the setVelocity and the hideObject command in MP
				
Parameter:	CYBP_setVel = [_c130, _vel, _cmd];
			publicVariable "CYBP_setVel";
			
			_c130 = name of real c130
			_vel = the new velocity array
			_cmd = either "hide" or "hideno" 
===============================================================================================
*/

_unit = _this select 0;
_vel = _this select 1;
_cmd = _this select 2;

If (_unit != "" && _vel != "") then {_unit setVelocity _vel};

switch (_cmd) do 
{
	case "hide" : {_unit hideObject true};
	case "hideno" : {_unit hideObject false};
	default {};
};