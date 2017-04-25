//move reticle to given pos

	#include "script_component.hpp"
	#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
	#define __ctrl (__dsp displayCtrl 1)
	#define __vcfg configfile>>"cfgvehicles">>typeof (vehicle player)
	#define __scfg configfile>>"ace_config">>"cfgVehicleOpticsReticles">>_type

	private ["_vehclass","_type","_fov0","_ratio","_wpn","_kup","_xoff","_yoff","_kmap","_h","_w"];
	GVAR(el_veh) = GVAR(el_veh) + (_this select 0)/4;
	GVAR(wnd_veh) = GVAR(wnd_veh) + (_this select 1);
	if !(isNull __dsp) then 
	{
		_type = getText (__vcfg>>"ace_sys_reticles_gunnersight");
		_kmap = getNumber(__scfg>>"ace_sys_reticles_texmap");
		_fov0 = getNumber (__scfg>>"ace_sys_reticles_fov0");
		_kup = 1.36*_kmap;
		_ratio = _fov0/GVAR(fov_veh);
		if (_ratio == 0) then {_ratio = 1};
		_w = _ratio*_kup*safezoneH*0.749351;
		_h = _ratio*_kup*SafeZoneH;
		_xoff = _w/2;
		_yoff = _h/2;
		GVAR(retpos_veh) = [0.5-_xoff-_ratio*GVAR(wnd_veh)*GVAR(milx_veh),0.5-_yoff-_ratio*GVAR(el_veh)*GVAR(mily_veh),_w,_h];
		__ctrl ctrlsetposition GVAR(retpos_veh);
		__ctrl ctrlcommit 0;
	};
