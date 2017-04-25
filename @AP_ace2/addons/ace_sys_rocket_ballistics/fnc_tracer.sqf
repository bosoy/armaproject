//Tracer effect for AT rockets
#include "script_component.hpp"
#define SCRIPTNAME QGVAR(fnc_tracer)

[_this select 4,_this select 6] spawn
{
	private ["_path","_t","_it","_tt","_rckt","_l","_s"];
	_path = configFile >> "cfgAmmo" >> (_this select 0);
	_rckt = _this select 1;
	_t = getNumber(_path >> "thrust");
	_s = getNumber(_path >> "ace_at_tracersize");
	if (_t > 0) then //wait until motor burns out
	{
		_it = getNumber(_path >> "inittime");
		_tt = getNumber(_path >> "thrusttime");
		sleep _it + _tt;
	};
	_l = "#lightpoint" createVehicleLocal [0,0,0];
	_l setLightColor [.2,.2,.2];
	_l setLightAmbient [0.2,0.2,0.2];
	_l setLightBrightness 0.05*_s/3.8;
	_l LightAttachObject [_rckt,[0,0,0]];
	while  { !isNull _rckt } do
	{
		drop ["\ca\data\koulesvetlo","","Billboard",100,0.03,_rckt modelToWorld [0,0,0],[0,0,0],0,1.27,1,0.05,[_s],[[1,0.1,0.1,0.8]],[0],0,0,"","",""];
		sleep 0.005;
	};
	deletevehicle _l;
};