#include "script_component.hpp"

#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
#define __ctrl (__dsp displayCtrl 1)
#define __ctrlRing (__dsp displayCtrl 2)
#define __wcfg configfile>>"cfgweapons">>_weapon

private ["_r1","_r2","_amp","_rec","_recpath","_hor","_ver","_xoff","_yoff","_pos","_maxWidth","_h","_w","_scale"];
PARAMS_7(_unit,_weapon,_muzzle,_mode,_ammo,_mag,_bullet);

_pos = GVAR(retpos);
_w = _pos select 2;
_h = _pos select 3;
_xoff = _w/2;
_yoff = _h/2;


if (_muzzle == _weapon) then 
{
	if (_mode==_muzzle) then
	{
		_recpath = __wcfg;
	} else
	{
		_recpath = __wcfg>>_mode;
	};
} else 
{
	if (_mode==_muzzle) then
	{
		_recpath = __wcfg>>_muzzle;
	} else
	{
		_recpath = __wcfg>>_muzzle>>_mode;
	};
};
//diag_log [_weapon,_muzzle,_mode,_recpath];
_rec = getText(_recpath>>"recoil");
_rec = getArray(configfile>>"cfgrecoils">>_rec);
//diag_log format ["recoil: %1",_rec];
_r1 = if (typeName (_rec select 1)=="SCALAR") then {_rec select 1} else {call compile (_rec select 1)};
if (count _rec >= 5) then
{
	_r2 = if (typeName (_rec select 4)=="SCALAR") then {_rec select 4} else {call compile (_rec select 4)};
	_amp = _r1 max _r2;
} else
{
	_amp = _r1;
};
_scale = ((1.045*_amp/0.006) min 1.07) max 1.03;

//_t = (_scale-1) max 0;
_hor = -1+random 2; //mil
_ver = -1+random 2; //mil

__ctrl ctrlsetposition [0.5+(-_xoff+(-GVAR(wnd)+_hor)*GVAR(milx))*_scale,0.5+(-_yoff+(GVAR(el)+_ver)*GVAR(mily))*_scale,_w*_scale,_h*_scale];

_pos = GVAR(ringpos);
_w = _pos select 2;
_h = _pos select 3;
_xoff = _w/2;
_yoff = _h/2;

__ctrlRing ctrlsetposition [0.5+(-_xoff+_hor*GVAR(milx))*_scale,0.5+(-_yoff+_ver*GVAR(mily))*_scale,_w*_scale,_h*_scale];

//[0.5-_xoff*_scale,0.5-_yoff*_scale,_w*_scale,_h*_scale];

__ctrl ctrlcommit 0.03;
__ctrlRing ctrlcommit 0.03;

// Changed logics
GVAR(reticle_lastshottime) = time;

// Say goodbye to scheduler impact
[
	{}, /* Run code */
	[], /* parameters */
	0.01, // delay
	{ /* Init code */
		_shotTime = GVAR(reticle_lastshottime);
		_frameNo = diag_frameNo;	// disallow immediate skipping
	},
	{ /* Exit code */
		if (GVAR(reticle_lastshottime) == _shotTime) then {
			__ctrl ctrlsetposition GVAR(retpos);
			__ctrlRing ctrlsetposition GVAR(ringpos);
			__ctrl ctrlcommit 0.08;
			__ctrlRing ctrlcommit 0.08;
		};
	},
	{ /* Run condition - default true */
		true
	},
	{ /* Exit condition */
		(diag_frameNo > _frameNo) && {(ctrlCommitted __ctrl && {ctrlCommitted __ctrlRing})} || {(GVAR(reticle_lastshottime) != _shotTime)}
	},
	[ /* Private variables, available throughout all states and conditions */
		"_shotTime","_frameNo"
	]
] call cba_common_fnc_addPerFrameHandlerLogic;
