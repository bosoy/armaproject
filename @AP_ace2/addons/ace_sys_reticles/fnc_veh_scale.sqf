//scale reticle acc. to current magnification

	#include "script_component.hpp"
	#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
	#define __ctrl (__dsp displayCtrl 1)
	#define __ctrl2 (__dsp displayCtrl 2)
	#define __scfg configfile>>"ace_config">>"cfgVehicleOpticsReticles">>_this

	private ["_type","_ratio","_wpn","_fov0","_kup","_xoff","_yoff","_kmap","_h","_w"];
	if !(isNull __dsp) then 
	{
		_kmap = getNumber(__scfg>>"ace_sys_reticles_texmap");
		_fov0 =  getNumber(__scfg>>"ace_sys_reticles_fov0"); //FOV at which reticle is scaled correctly
		_kup = 1.36*_kmap;
		_ratio = _fov0/GVAR(fov_veh);
		_w = _ratio*_kup*safezoneH*0.749351;
		_h = _ratio*_kup*SafeZoneH;
		_xoff = _w/2;
		_yoff = _h/2;
		GVAR(retpos_veh) = [0.5-_xoff-_ratio*GVAR(wnd_veh)*GVAR(milx_veh),0.5-_yoff-_ratio*GVAR(el_veh)*GVAR(mily_veh),_w,_h];
		GVAR(staticpos_veh) = [0.5-_xoff,0.5-_yoff,_w,_h];

		__ctrl ctrlsetposition GVAR(retpos_veh);
		__ctrl2 ctrlsetposition GVAR(staticpos_veh);
		__ctrl ctrlcommit 0;
		__ctrl2 ctrlcommit 0;
	};