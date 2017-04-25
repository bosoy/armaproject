#include "script_component.hpp"

#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
#define __ctrl (__dsp displayCtrl 1)
#define __ctrlStatic (__dsp displayCtrl 2)
#define __vcfg configfile>>"cfgvehicles">>_vehclass
#define __scfg configfile>>"ace_config">>"cfgVehicleOpticsReticles">>_type


private ["_abort","_vehwpns","_checkweapon","_treticleN","_tstatic","_treticle","_illumcolor","_vehclass","_veh","_ratio","_mil","_exit","_checkfov","_fovarray","_maxfov","_minfov","_mz","_type","_kring","_kmap","_kpxpermil","_fov0","_texsize","_kup","_kres","_milX","_milY","_res","_resX","_resY","_viewportX","_viewportY","_k","_scale","_wpn","_xoff","_yoff","_pos","_maxWidth","_h","_w"];
_veh = vehicle _this;
_wpn = currentweapon _veh;
sleep 0.1;
if (GVAR(sightup_veh)) exitwith {};
if (cameraview != "GUNNER" || {visiblemap}) then {
	waituntil {(cameraview == "GUNNER" && {!visiblemap}) || {player != gunner _veh} };
};
if (player != (gunner _veh)) exitwith {GVAR(sightup_veh) = false};

_vehclass = typeof _veh;
_type = getText (__vcfg>>"ace_sys_reticles_gunnersight");
_checkweapon = getText (__scfg>>"ace_sys_reticles_checkweapon");
_vehwpns = _veh weaponsturret ((assignedvehiclerole player) select 1);
//check for presence of required weapon (to avoid triggering on unintended inheriting classes) 
_abort = true;
{
	if (_checkweapon == _x || {[configfile>>"cfgweapons">>_x,configfile>>"cfgweapons">>_checkweapon] call CBA_fnc_inheritsFrom}) exitwith {_abort = false};
} foreach _vehwpns;
if (_abort) exitwith {};

GVAR(sightup_veh) = true;
_fov0 = getNumber (__scfg>>"ace_sys_reticles_fov0");
_fovarray = [_veh,_wpn] call FUNC(veh_opticsconfig);
//if (count _fovarray > 1) then
//{
_maxfov = (_fovarray select 0) select 0;
_minfov = (_fovarray select 0) select 1;

if (count _fovarray > 1 || {_maxfov != _minfov}) then //variable zoom
{
	//spawn reticle-adjusting loop
	sleep 0.1;
	GVAR(fov_veh) = ((call cba_fnc_getfov) select 0);
	if (abs(1-GVAR(fov_veh)/_maxfov)<0.07) then {GVAR(fov_veh) = _maxfov}; //cba func has 0.5-1% margin of error
	_type spawn
	{
		private ["_curfov"];
		_this call FUNC(veh_scale);
		while {GVAR(sightup_veh)} do
		{
			waituntil 
			{
				sleep 0.1;
				_curfov = ((call cba_fnc_getfov) select 0);
				//hint format ["%1",_curfov];
				(abs(_curfov - GVAR(fov_veh))/GVAR(fov_veh) > 0.07) || !GVAR(sightup_veh)
			};
			if !(GVAR(sightup_veh)) exitwith {};
			GVAR(fov_veh) = _curfov;
			_this call FUNC(veh_scale);
			sleep 0.1;
		};
	};
} else
{
	GVAR(fov_veh) = _maxfov;
};

//_fov0 = 0.05689;

sleep 0.001;
call FUNC(rsc);

_treticle = (getText(__scfg>>"ace_sys_reticles_texreticle"));
_tstatic = (getText(__scfg>>"ace_sys_reticles_texstatic"));
_treticleN = (getText(__scfg>>"ace_sys_reticles_texreticle_n"));
__ctrl ctrlsetText _treticle;
__ctrlStatic ctrlsetText _tstatic;

if (getNumber (__scfg>>"ace_sys_reticles_illum")==1) then
{
	_illumcolor = getArray(__scfg>>"ace_sys_reticles_illumcolor");
	if (GVAR(illum_veh)) then
	{
		__ctrl ctrlSetTextColor _illumcolor;
		__ctrlStatic ctrlSetTextColor _illumcolor;
	} else
	{
		__ctrl ctrlSetTextColor [0,0,0,1];
		__ctrlStatic ctrlSetTextColor [0,0,0,1];
	};
} else
{
	_illumcolor = [1,1,1,1];
	__ctrl ctrlSetTextColor [1,1,1,1];
	__ctrlStatic ctrlSetTextColor [1,1,1,1];
};
//only for bpk-2-42
[_veh,_treticle,_tstatic,_treticleN,_illumcolor] spawn
{
	private ["_tstatic","_treticle","_treticleN","_illumcolor","_veh","_wpn","_vmode","_check","_w","_h"];
	_veh = _this select 0;
	_treticle = _this select 1;
	_tstatic = _this select 2;
	_treticleN = _this select 3;
	_illumcolor = _this select 4;
	_wpn = currentweapon _veh;
	_vmode = currentvisionmode player;
	_check = true;
	while {GVAR(sightup_veh)} do
	{
		if (_check || {currentweapon _veh != _wpn}) then
		{
			_wpn = currentweapon _veh;
			if ([configfile>>"cfgweapons">>_wpn,configfile>>"cfgweapons">>"MissileLauncher"] call CBA_fnc_inheritsFrom) then
			{
				__ctrl ctrlsetText "\x\ace\addons\m_veh_optics\data\atgm_ca.paa";
				__ctrl ctrlSetTextColor [1,1,1,1];
				__ctrlStatic ctrlSetTextColor [0,0,0,0];
				_w = 1.7*safezoneH*0.749351;
				_h = 1.7*SafeZoneH;
				__ctrl ctrlsetposition [0.5-_w/2,0.5-_h/2,_w,_h];
				__ctrl ctrlcommit 0;
			} else
			{
				_check = true;
				__ctrl ctrlsetposition GVAR(retpos_veh);
				__ctrl ctrlcommit 0;
			};
		};
		if (_check || {currentvisionmode player != _vmode}) then
		{
			_vmode = currentvisionmode player;
			if (_vmode == 0) then
			{
				if !([configfile>>"cfgweapons">>_wpn,configfile>>"cfgweapons">>"MissileLauncher"] call CBA_fnc_inheritsFrom) then
				{
					__ctrl ctrlsetText _treticle;
					__ctrlStatic ctrlsetText _tstatic;
					if !(GVAR(illum_veh)) then 
					{
						__ctrl ctrlSetTextColor [0,0,0,1];
						__ctrlStatic ctrlSetTextColor [0,0,0,1];
					} else
					{
						__ctrl ctrlSetTextColor _illumcolor;
						__ctrlStatic ctrlSetTextColor _illumcolor;
					};
				};
			} else
			{
				if !([configfile>>"cfgweapons">>_wpn,configfile>>"cfgweapons">>"MissileLauncher"] call CBA_fnc_inheritsFrom) then
				{
					__ctrl ctrlsetText _treticleN;
					__ctrl ctrlSetTextColor [0,0,0,1];
					__ctrlStatic ctrlSetTextColor [0,0,0,0];
				};
			};
		};
		_check = false;
		sleep 0.1;
	};
};

_pos = ctrlposition __ctrl;
_res = getresolution;
_resX = _res select 0;
_resY = _res select 1;
_viewportX = _res select 2;
_viewportY = _res select 3;
_kmap = getNumber(__scfg>>"ace_sys_reticles_texmap");
_kpxpermil = getNumber(__scfg>>"ace_sys_reticles_pxmil");
_texsize = getNumber(__scfg>>"ace_sys_reticles_texsize");
_kup = 1.36*_kmap;
_kres = _resY/_texsize;
_ratio = _fov0/GVAR(fov_veh);
_mil = _kpxpermil*_kres*_kup;
GVAR(wnd_veh) = getNumber(__scfg>>"ace_sys_reticles_horizshift");

GVAR(milx_veh) = _mil*0.749351/_viewportY;
GVAR(mily_veh) = _mil/_viewportY;

_milX = _ratio*GVAR(milx_veh); //size of one mil in screen coords
_milY = _ratio*GVAR(mily_veh);

_w = _ratio*_kup*safezoneH*0.749351;
_h = _ratio*_kup*SafeZoneH;
_xoff = _w/2;
_yoff = _h/2;

GVAR(retpos_veh) = [0.5-_xoff-GVAR(wnd_veh)*_milX,0.5-_yoff-GVAR(el_veh)*_milY,_w,_h];
GVAR(staticpos_veh) =  [0.5-_xoff,0.5-_yoff,_w,_h];

__ctrl ctrlsetposition GVAR(retpos_veh);
__ctrlStatic ctrlsetposition GVAR(staticpos_veh);

__ctrl ctrlcommit 0;
__ctrlStatic ctrlcommit 0;

sleep 0.1;
call FUNC(deh_add);

waituntil {_this != player || {cameraview != "GUNNER"} || {player != gunner _veh} || {visibleMap} };

GVAR(sightup_veh) = false;
call FUNC(deh_remove);
if !(isNull __dsp) then { 13506 cutRsc ["Default", "PLAIN",0] };