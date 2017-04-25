//scale reticle acc. to current magnification

	#include "script_component.hpp"
	#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
	#define __ctrl (__dsp displayCtrl 1)
	#define __wcfg configfile>>"cfgweapons">>_wpn
	#define __scfg configfile>>"ace_config">>"cfgOpticsReticles">>_type

	private ["_ret","_curret","_type","_ratio","_wpn","_fov0","_kup","_xoff","_yoff","_kmap","_h","_w"];
	//GVAR(el) = (_this select 0);
	//GVAR(wnd) = (_this select 1);
	if !(isNull __dsp) then 
	{
		_wpn = currentweapon player;
		_type = getText(__wcfg>>"ace_sys_reticles_scope");
		_kmap = getNumber(__scfg>>"ace_sys_reticles_texmap");
		_fov0 =  getNumber(__scfg>>"ace_sys_reticles_fov0"); //FOV at which reticle is scaled correctly
		_fovlod =  getNumber(__scfg>>"ace_sys_reticles_fov_switchlod");
		if (_fovlod != 0) then //switching to full-sized reticle at lower magnification
		{
			if (GVAR(fov)>_fovlod) then
			{
				_ret = getText(__scfg>>"ace_sys_reticles_texreticle_lod1");
				_curret = ctrlText __ctrl;
				if (_ret != _curret) then
				{
					__ctrl ctrlsettext _ret;
				};
				_kmap = 2*_kmap;
			} else
			{
				_ret = getText(__scfg>>"ace_sys_reticles_texreticle");
				_curret = ctrlText __ctrl;
				if (_ret != _curret) then
				{
					__ctrl ctrlsettext _ret;
				};
			};
		};
		_kup = 1.36*_kmap;
		_ratio = _fov0/GVAR(fov);
		//_w = _ratio*_kup*(getresolution select 3)*safezoneH/(getresolution select 2);
		_w = _ratio*_kup*safezoneH*0.749351;
		_h = _ratio*_kup*SafeZoneH;
		_xoff = _w/2;
		_yoff = _h/2;
		GVAR(retpos) = [0.5-_xoff-_ratio*GVAR(wnd)*GVAR(milx),0.5-_yoff+_ratio*GVAR(el)*GVAR(mily),_w,_h];
		//diag_log format ["scale: ratio %1 kup %2 fov0 %3 pos %4",_ratio,_kup,_fov0,GVAR(retpos)];
		__ctrl ctrlsetposition GVAR(retpos);
		__ctrl ctrlcommit 0;
	};
