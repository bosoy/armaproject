#include "script_component.hpp"

#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
#define __ctrl (__dsp displayCtrl 1)
#define __ctrlRing (__dsp displayCtrl 2)
#define __wcfg configfile>>"cfgweapons">>_wpn
#define __scfg configfile>>"ace_config">>"cfgOpticsReticles">>_type

private ["_ratio","_mil","_exit","_checkfov","_fovarray","_maxfov","_minfov","_mz","_type","_kring","_kmap","_kpxpermil","_fov0","_texsize","_kup","_kres","_milX","_milY","_res","_resX","_resY","_viewportX","_viewportY","_k","_scale","_wpn","_xoff","_yoff","_pos","_maxWidth","_h","_w"];
_wpn = currentweapon player;
_mz = currentmuzzle player;

//checking if it's optics that are being used
_fovarray = [_wpn,_mz] call FUNC(opticsconfig);
_minfov = _fovarray select 0;
_maxfov = _fovarray select 1;
_exit = false;
if (count _fovarray == 4) then { //there are several optics
	if (((call cba_fnc_getfov) select 0) > 1.1*_maxfov) then { _exit = true } else { _checkfov = {((call cba_fnc_getfov) select 0) > 1.1*_this}; };
} else {
	_checkfov = {false};
};
if (_exit) exitwith {
	GVAR(sightup) = false;
	if !(isNull __dsp) then { 13506 cutRsc ["Default", "PLAIN",0] };
};
_type = getText(__wcfg>>"ace_sys_reticles_scope");

// scaling ze reticle
if(_minfov != _maxfov && {(getNumber(__scfg >> "ace_sys_reticles_scalereticle")==1)}) then {
	//spawn reticle-adjusting loop
	sleep 0.1;
	GVAR(fov) = ((call cba_fnc_getfov) select 0);
	if (abs(1-GVAR(fov)/_maxfov)<0.01) then {GVAR(fov) = _maxfov}; //cba func has 0.5-1% margin of error
	[] spawn {
		private ["_curfov"];
		call FUNC(scale);
		while {GVAR(sightup)} do {
			waituntil  {
				_curfov = ((call cba_fnc_getfov) select 0);
				//hint format ["%1",_curfov];
				(abs(_curfov - GVAR(fov))/GVAR(fov) > 0.01) || {!GVAR(sightup)}
			};
			if !(GVAR(sightup)) exitwith {};
			GVAR(fov) = _curfov;
			call FUNC(scale);
			sleep 0.01;
		};
	};
	_fov0 =  getNumber(__scfg >> "ace_sys_reticles_fov0"); //FOV at which the reticle is scaled correctly
} else {
	GVAR(fov) = _maxfov;
	_fov0 = _maxfov;
};


//reset reticle if different rifle
if (getNumber(__wcfg >> "ace_sys_reticles_enable_sa") == 1) then {
	if (ACE_SYS_SA_RFL select 2 != _wpn) then {
		_wpn call ace_sys_sight_adjustment_rifle_fnc_newweap;
	};
} else {
	GVAR(el) = 0;
	GVAR(wnd) = 0;
};

sleep 0.001;
call FUNC(rsc);

__ctrl ctrlsetText (getText(__scfg >> "ace_sys_reticles_texreticle")); //"\x\ace\addons\m_wep_optics\t\PSO-1.paa";
__ctrlRing ctrlsetText (getText(__scfg >> "ace_sys_reticles_texring")); "\x\ace\addons\m_wep_optics\t\scopering_new.paa";

if (getNumber(__scfg >> "ace_sys_reticles_illum")==1) then {
	if !(GVAR(illum)) then {__ctrl ctrlSetTextColor [0,0,0,1]} else {__ctrl ctrlsetTextColor (getArray(__scfg >> "ace_sys_reticles_illumcolor"))};
} else {
	__ctrl ctrlSetTextColor [1,1,1,1];
};
__ctrlRing ctrlSetTextColor [1,1,1,1];

_pos = ctrlposition __ctrl;
_res = getresolution;
_resX = _res select 0;
_resY = _res select 1;
_viewportX = _res select 2;
_viewportY = _res select 3;
_kmap = getNumber(__scfg >> "ace_sys_reticles_texmap");//reticle texture mapping (1-whole surface of model, 0.5 - half etc)
_kpxpermil = getNumber(__scfg >> "ace_sys_reticles_pxmil"); //pxels per mil in optics texture
_texsize = getNumber(__scfg >> "ace_sys_reticles_texsize"); //optics texture size
_kup = 1.36*_kmap; //upscale coefficient
_kres = _resY/_texsize;
_kring = getNumber(__scfg >> "ace_sys_reticles_ringscale");
_ratio = _fov0/GVAR(fov);
_mil = _kpxpermil*_kres*_kup;

//GVAR(milx) = _mil/_viewportX;
GVAR(milx) = _mil*0.749351/_viewportY;
GVAR(mily) = _mil/_viewportY;

_milX = _ratio*GVAR(milx); //size of one mil in screen coords
_milY = _ratio*GVAR(mily);

//diag_log format ["ratio %1 kup %2 vpY %3 vpX %4 fov0 %5",_ratio,_kup,_viewportY,_viewportX,_fov0];

//takes the min dimension when 'keep aspect ratio' type
_w = _ratio*_kup*safezoneH*0.749351;
//_w = _ratio*_kup*_viewportY*safezoneH/_viewportX;//this is to always keep it 1:1
_h = _ratio*_kup*SafeZoneH;
_xoff = _w/2;
_yoff = _h/2;
GVAR(retpos) = [0.5-_xoff-GVAR(wnd)*_milX,0.5-_yoff+GVAR(el)*_milY,_w,_h];
//diag_log GVAR(retpos);

_w = _kring*_kup*safezoneH*0.749351/_kmap;
//_w = _kring*_kup*_viewportY*safezoneH/(_viewportX*_kmap);
_h = _kring*_kup*SafeZoneH/_kmap;
_xoff = _w/2;
_yoff = _h/2;
GVAR(ringpos) = [0.5-_xoff,0.5-_yoff,_w,_h];

if (ctrlCommitted __ctrl && {ctrlCommitted __ctrlRing}) then {
	__ctrl ctrlsetposition GVAR(retpos);
	__ctrlRing ctrlsetposition GVAR(ringpos);

	__ctrl ctrlcommit 0;
	__ctrlRing ctrlcommit 0;
};

sleep 0.1;
call FUNC(deh_add); //add DEH to switch the reticle off as soon as the key is pressed
waituntil {_this != player || {player != vehicle player} || {cameraview != "GUNNER"} || {currentmuzzle player != _mz} || {(_maxfov call _checkfov)} || {visibleMap} };
GVAR(sightup) = false;
call FUNC(deh_remove);
if !(isNull __dsp) then { 13506 cutRsc ["Default", "PLAIN",0] };
