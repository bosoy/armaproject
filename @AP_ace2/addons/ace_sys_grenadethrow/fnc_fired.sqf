//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfg (configFile >> "CfgMagazines" >> (_this select 5))

#define __dsp (uiNamespace getVariable "ACE_RscCursorG")
#define __ctrl (__dsp displayCtrl 159155)

PARAMS_7(_unit,_weapon,_muzzle,_mode,_ammo,_mag,_bullet);

private ["_sim","_p0","_p1","_cookie","_reset", "_resvel", "_respos", "_vectorUp", "_vel", "_pos", "_cos", "_sin", "_dir", "_spd", "_upx", "_elev", "_upz", "_x1", "_y1", "_z1", "_k", "_geometry","_z"];

if (player != _unit) exitwith {};
if (currentweapon _unit != "throw") exitwith
{
	-2 call FUNC(indicator);
};
if !(GVAR(grenadecursor)) exitwith {};
//reset cursor color if it's red (cooking)
switch (GVAR(opt_cursortype)) do
{
	case 1: {__ctrl ctrlSetTextColor [0.4,0.7,0.28,1]};
	case 2: {__ctrl ctrlSetTextColor [1,1,1,1]};
	default {};
};
_mode = GVAR(mode);
_k = (GVAR(opt_startvel) + GVAR(speed)*(1 - GVAR(opt_startvel)) )*getNumber(__cfg>>"initSpeed");
//_k = GVAR(speed)*getNumber(__cfg>>"initSpeed");
GVAR(holding)=false;
TRACE_4("",_mode,GVAR(opt_startvel),GVAR(speed),_k);

if (isNull _bullet) exitwith {};
_pos = getposASL _bullet;
_vel = velocity _bullet;
_vectorUp = [0,0,1];
/*
//cancel throw
if (GVAR(cancelthrow)) exitwith
{
	_bullet setpos [0,0,100];
	deletevehicle _bullet;
	_unit addmagazine _mag;
	GVAR(cancelthrow) = false;
	_unit setvariable ["ace_sys_grenadethrow_cookie",objNull];
};
*/
//cooked grenade
if !(isNil {_unit getvariable "ace_sys_grenadethrow_cookie"}) then
{
	if !(isNull (_unit getvariable "ace_sys_grenadethrow_cookie")) then 
	{
		_bullet setpos [0,0,100];
		[_bullet] call ace_sys_frag_fnc_denyFrag;
		deletevehicle _bullet;
		_bullet = (_unit getvariable "ace_sys_grenadethrow_cookie");
		[_bullet] call ace_sys_frag_fnc_addManualTrack;
		detach _bullet;
		_unit setvariable ["ace_sys_grenadethrow_cookie",objNull];
	};
};

// IRStrobe automatically on mode 3
if (getNumber(configFile >> "CfgAmmo" >> _ammo >> "ACE_ThrowOverride") == 1) then {
	if !(_mode == 3) then { _mode = 3 };
};

switch (_mode) do {
	//normal throw
	case 0: {
		_spd = _vel call ACE_fnc_magnitude;
		if !(_bullet isKindOf "SmokeShell") then {
			_resvel = [_k*(_vel select 0)/_spd,_k*(_vel select 1)/_spd,_k*(_vel select 2)/_spd];
		} else { // arc throw for smoke grenades
			_vel = _unit weapondirection "Put";
			_x1 = _vel select 0;
			_y1 = _vel select 1;
			_z = sqrt(_x1^2 + _y1^2);
			_elev = (19.5 + (_vel select 2) atan2 _z) min 89;
			_cos = cos(_elev)*_x1/_z;
			_sin = cos(_elev)*_y1/_z;
			_z1 = sin(_elev);
			_resvel = [_cos*_k,_sin*_k,_z1*_k];
		};
		_respos = _pos;
		TRACE_4("normal throw",_vel,_cos,_resvel,_respos);
	};
	//direct throw
	case 1: {
		_vel = _unit weapondirection "Put"; //GVAR(throwdir);
		_cos = [_vel,GVAR(throwdir)] call ace_sys_missileguidance_fnc_mat_cos3Dvec;
		TRACE_4("",_vel,GVAR(throwdir),_cos,(acos _cos));
		//hint format ["cos %1 angle %2",_cos,acos _cos];
		 if (acos _cos < 3) then { //cancel dir set when releasing m.button if turned too much during throwing
			 _vel = GVAR(throwdir);
		 };
		_resvel = [_k*(_vel select 0),_k*(_vel select 1),_k*(_vel select 2)];
		_respos = _unit modeltoworld (_unit selectionPosition "neck");
		//_respos set [2,(_respos select 2) + ((getposASL _unit) select 2)-((getposATL _unit) select 2)];
		_respos set [0,(_respos select 0) + 0.2*(_vel select 0)];
		_respos set [1,(_respos select 1) + 0.2*(_vel select 1)];
		_respos set [2,0.1+(_respos select 2) + ((getposASL _unit) select 2)-((getposATL _unit) select 2) + 0.2*(_vel select 2)];
		TRACE_4("direct throw",_vel,_cos,_resvel,_respos);
	};
	//roll
	case 2: {
		//_vel = 18;	//8 for slow
		_elev = 4; //degrees //10 for slow
		_vel = _unit weapondirection "Put";
		_x1 = _vel select 0;
		_y1 = _vel select 1;
		_z = sqrt(_x1^2 + _y1^2);

		//normalizing 3d vector - same x-y direction as originally, but with a new fixed elevation
		_cos = cos(_elev)*_x1/_z;
		_sin = cos(_elev)*_y1/_z;
		_z1 = sin(_elev);

		//rotating grenade so its horizontal - not used as its less bouncy this way
		_vectorUp = [_y1/_z,-_x1/_z, 0];

		_resvel = [_cos*_k,_sin*_k,_z1*_k];
		_respos = [(_pos select 0)+0.3*_cos,(_pos select 1)+0.3*_sin, 0.3*_z1 + 0.3 + ((getPosASL _unit) select 2)];
		//_respos = [_pos select 0,_pos select 1, 0.3 + ((getPosASL _unit) select 2)];
		TRACE_4("roll",_vel,_cos,_resvel,_respos);
	};
	// drop
	case 3: {
		_resvel = [0,0,0];
		_respos = _pos;
	};
	default {};
};
//_sim = gettext(configfile>>"cfgammo">>_ammo>>"ace_simulation");
//if (_bullet isKindOf "smokeshell" || _sim == "shotWP" ) then
//{
	_geometry = "ACE_Grenade_Geometry" createVehicle [_respos select 0,_respos select 1,((getpos _unit) select 2)+ 500];
	[_respos,_resvel,_bullet,_geometry,_unit] call FUNC(applyPosVelpfh);
//} else
//{
//	[QGVAR(setposvelremote), [_respos,_resvel,_bullet,_unit]] call CBA_fnc_globalEvent;
//};

GVAR(speed) = 1;
1 call FUNC(indicator);

if (_unit == player) then {
	//resetting back no normal throw automatically if specified in client config
	if (GVAR(opt_resetmode) == 1) then { GVAR(mode) = 0};
	//selecting main weapon (currently in hands) after throw
	if (GVAR(opt_slctprimwpn) == 1) then {
		[1,0] call ace_sys_weaponselect_fnc_keypressed;
	};
};
if (cameraview != "GUNNER") then {player switchcamera cameraview} else {player switchcamera "INTERNAL"};