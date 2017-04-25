//move reticle to given pos

	#include "script_component.hpp"
	#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
	#define __ctrl (__dsp displayCtrl 1)
	#define __wcfg configfile>>"cfgweapons">>_wpn
	#define __scfg configfile>>"ace_config">>"cfgOpticsReticles">>_type

	private ["_type","_fov0","_ratio","_wpn","_kup","_xoff","_yoff","_kmap","_h","_w"];
	GVAR(el) = (_this select 0);
	GVAR(wnd) = (_this select 1);
	if !(isNull __dsp) then 
	{
		_wpn = currentweapon player;
		_type = getText(__wcfg>>"ace_sys_reticles_scope");
		_kmap = getNumber(__scfg>>"ace_sys_reticles_texmap");
		_fov0 =  getNumber(__scfg>>"ace_sys_reticles_fov0"); //FOV at which reticle is scaled correctly
		_kup = 1.36*_kmap;
		_ratio = _fov0/GVAR(fov);
		if (_ratio == 0) then {_ratio = 1};
		//_w = _ratio*_kup*(getresolution select 3)*safezoneH/(getresolution select 2);
		_w = _ratio*_kup*safezoneH*0.749351;
		_h = _ratio*_kup*SafeZoneH;
		_xoff = _w/2;
		_yoff = _h/2;
		GVAR(retpos) = [0.5-_xoff-_ratio*GVAR(wnd)*GVAR(milx),0.5-_yoff+_ratio*GVAR(el)*GVAR(mily),_w,_h];
		__ctrl ctrlsetposition GVAR(retpos);
		__ctrl ctrlcommit 0;
	};
