//scripted grenade cursor, mode indicator, force indicator

#include "script_component.hpp"
#define __dsp (uiNamespace getVariable "ACE_RscCursorG")
#define __ctrl (__dsp displayCtrl 159155)
#define __ctrlmode (__dsp displayCtrl 159156)
#define __ctrlbgInd (__dsp displayCtrl 1)
#define __ctrlInd (__dsp displayCtrl 2)

private ["_mag","_mode","_magprev","_modeprev","_pth","_xoffm","_yoffm","_posm","_arrowtype","_plr","_xoff1","_yoff1","_xoff","_yoff","_color","_pos","_point","_point2","_dir","_z","_zpad","_zplr","_maxWidth"];

13538 cutRsc ["ACE_RscCursorG", "PLAIN",0];
__ctrlInd ctrlShow false;
__ctrlbgInd ctrlShow false;
sleep 0.3;
waituntil {! (isNull __dsp) };

_pos = ctrlposition __ctrl;
_xoff = 0.3*(SafeZoneH/SafeZoneW)*(_pos select 2)/2;
_yoff = 0.3*(_pos select 3)/2;

_posm = ctrlposition __ctrlmode;
_xoffm = 0.2*(SafeZoneH/SafeZoneW)*(_posm select 2)/2;
_yoffm = 0.2*(_posm select 3)/2;

__ctrl ctrlsetposition [0.5-_xoff,0.5-_yoff,2*_xoff,2*_yoff];
__ctrlmode ctrlsetposition [0.5+0.5*_xoff,0.5-_yoffm,2*_xoffm,2*_yoffm];

//displaying grenade icon as cursor
_magprev = currentmagazine player;

switch (GVAR(opt_cursortype)) do
{
	case 1:
	{
		__ctrl ctrlsetText "\ca\UI\Data\cursor_w_grenade_gs.paa";
		__ctrl ctrlSetTextColor [0.4,0.7,0.28,1];
	};
	case 2:
	{
		_pth = gettext(configfile>>"cfgmagazines">>_magprev>>"picture");
		__ctrl ctrlsetText _pth; //"\ca\weapons\Data\Equip\m_m67_ca.paa";
		__ctrl ctrlSetTextColor [1,1,1,1];
	};
	default
	{
		__ctrl ctrlsetText "";
		__ctrl ctrlSetTextColor [0,0,0,0];
	};
};

_arrowtype = format ["\x\ace\addons\sys_grenadethrow\data\arw_%1.paa",GVAR(mode)];
__ctrlmode ctrlsetText _arrowtype;
__ctrlmode ctrlSetTextColor [0.4,0.7,0.28,1];

__ctrl ctrlcommit 0;
__ctrlmode ctrlcommit 0;

_maxWidth = 0.5*((ctrlPosition __ctrlbgInd select 2));
_pos = ctrlPosition __ctrlInd;
_pos set [2, _maxWidth];
__ctrlInd ctrlSetPosition _pos;
__ctrlInd ctrlCommit 0;
__ctrlbgInd ctrlSetPosition _pos;
__ctrlbgInd ctrlCommit 0;

_pos = ctrlposition __ctrlInd;
_xoff1 = (_pos select 2)/2;
_yoff1 = (_pos select 3)*2;

GVAR(speed) = 1;
1 call FUNC(indicator);

_zpad = "HeliHEmpty" createvehiclelocal [0,0,0];
_plr = player;
_modeprev = GVAR(mode);
while {GVAR(grenadecursor)} do
{
	if (currentweapon player != "Throw" || player != _plr || ! (alive player)) exitwith {GVAR(grenadecursor) = false};

	_dir = player weapondirection "Put";
	_pos = player selectionposition "neck";
	_point = player modeltoworld _pos;
	_point2 = [(_point select 0)+1000*(_dir select 0),(_point select 1)+1000*(_dir select 1),(_point select 2)+1000*(_dir select 2)];

	_zpad setpos [_point2 select 0,_point2 select 1,0];
	_z = (getposASL _zpad) select 2;
	//_z = getTerrainHeightASL [_point2 select 0,_point2 select 1];

	_zpad setpos [_point select 0,_point select 1,0];
	_zplr = (getposASL _zpad) select 2;
	//_zplr = getTerrainHeightASL [_point select 0,_point select 1];

	_point2 set [2,(_point2 select 2) + _zplr - _z];
	
	_pos = worldtoscreen _point2;
	//GVAR(cursorpos) = _pos;
	
	if (count _pos == 2) then
	{
		__ctrl ctrlsetposition [(_pos select 0)-_xoff,(_pos select 1)-_yoff];
		
		if (GVAR(opt_cursortype)==2) then //tracking the current grenade type
		{
			_mag = currentmagazine player;
			if (_mag != _magprev) then 
			{
				_pth = gettext(configfile>>"cfgmagazines">>_mag>>"picture");
				__ctrl ctrlsetText _pth;
				//__ctrl ctrlSetTextColor [1,1,1,1];
				_magprev = _mag;
			};
		};
		__ctrl ctrlcommit 0;

		__ctrlmode ctrlsetposition [(_pos select 0)+0.5*_xoff,(_pos select 1)-_yoffm];
		if (GVAR(mode) != _modeprev) then
		{
			_arrowtype = format ["\x\ace\addons\sys_grenadethrow\data\arw_%1.paa",GVAR(mode)];
			__ctrlmode ctrlsetText _arrowtype;
			_modeprev = GVAR(mode);
		};
		__ctrlmode ctrlcommit 0;

		__ctrlInd ctrlsetposition [(_pos select 0)-_xoff1,(_pos select 1)+_yoff1];
		__ctrlInd ctrlcommit 0;
		__ctrlbgInd ctrlsetposition [(_pos select 0)-_xoff1,(_pos select 1)+_yoff1];
		__ctrlbgInd ctrlcommit 0;
	};
	sleep 0.01;
};
if !(isNull __dsp) then { 13538 cutRsc ["Default", "PLAIN",0] };
GVAR(grenadecursor) = false;
GVAR(mode) = 0;
deletevehicle _zpad;
call GVAR(mkey_remove);