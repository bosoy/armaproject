#include "script_component.hpp"

#define __sideangle 60	//60 -> 120 deg sector
#define __rightmin 90 - __sideangle
#define __rightmax 90 + __sideangle
#define __leftmin 270 - __sideangle
#define __leftmax 270 + __sideangle

private ["_A_ID","_mine"];
_ar = _this;

if (count _this > 2) then {
	_A_ID = _this select 2;
	_mine = _this select 3;
	player removeAction _A_ID;
} else {
	_trigger = _this select 0;
	_mine = [_trigger] call FUNC(get_mine);
	// TODO: Workaround, fix later properly with own function
	if (isNull _mine) then {
		_mine = _trigger; 
	};
};

if (isNull _mine) exitwith { false };

_vlist = (position _mine) nearEntities [["Car","Tank"],45];
_vlist1 = [];
{if (alive _x) then {_vlist1 set [(count _vlist1),_x]}} foreach _vlist;

_processveh = false;
_v = objNull;
_dir = direction _mine;
_diffmin = 180;
if (count _vlist1 > 0) then {
	_p = getpos _mine;
	{
		_pveh = getpos _x;
		_vdir = [(_pveh select 0)-(_p select 0),(_pveh select 1)-(_p select 1),(_pveh select 2)-(_p select 2)];
		_a = (_vdir select 0) atan2 (_vdir select 1); //direction from mine to veh
		if (_a < 0) then {_a = _a + 360};
		_diff = abs (_a - _dir);
		if (_diff > 180) then {_diff = 360 - _diff}; //angle between dir of mine and dir to veh center
		if (_diff <= 85 && {_diff < _diffmin}) then {_diffmin = _diff;_v = _x};
	} foreach _vlist1;
	if (! isNull _v) then {_processveh = true};
};

_a = "ACE_SLAMSideEFP";
if (_processveh) then {
	_vdir = getdir _v;
	_vdir = 180 + _dir - _vdir;
	if (_vdir < 0) then {_vdir = _vdir + 360};
	if (_vdir > 360) then {_vdir = _vdir - 360};
	if (true) then {
		if (_vdir >= __leftmax || {_vdir <= __rightmin}) exitwith {_a = "ACE_SLAMSideEFP_0"};	//a=[front,left,right,back,top]
		if (_vdir > __rightmin && {_vdir < __rightmax}) exitwith {_a = "ACE_SLAMSideEFP_2"};
		if (_vdir >= __rightmax && {_vdir <= __leftmin}) exitwith {_a = "ACE_SLAMSideEFP_3"};
		if (_vdir > __leftmin && {_vdir < __leftmax}) exitwith {_a = "ACE_SLAMSideEFP_1"};
	};
};

"ACE_ClaymoreExplosion" createVehicle [(position _mine) select 0,(position _mine) select 1, (0.8 + ([_mine] call CBA_fnc_realHeight))];
_explosion = _a createVehicle [(position _mine) select 0,(position _mine) select 1, (0.8 + ([_mine] call CBA_fnc_realHeight))];
_explosion setDir _dir;
_explosion setVelocity [(sin _dir) * 200, (cos _dir) * 200, ((vectorDir _mine) select 2) * 200];
[_mine] call FUNC(removeMine);
