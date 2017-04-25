#include "script_component.hpp"
#define __cfg (configFile >> "CfgMagazines" >> currentMagazine player)
#define __step 0.05

#define __dsp (uiNamespace getVariable "ACE_RscCursorG")
#define __ctrlCursor (__dsp displayCtrl 159155)
#define __ctrlbg (__dsp displayCtrl 1)
#define __ctrl (__dsp displayCtrl 2)

private["_k","_pos","_p1","_p0","_width","_type","_maxspeed","_minspeed","_key","_btnhold","_btncook"];

if (dialog) exitwith {false};
if (count _this != 2) exitwith {false};
if (player != vehicle player) exitwith {false};
if (currentWeapon player != "Throw") exitwith {false};
if (player ammo (currentMuzzle player) < 1) exitwith {false};
//player sidechat format ["mkey pressed %1",_this];
_key = _this select 0;
_type = _this select 1;

if (GVAR(opt_invmb) == 0) then //inverse MB functions
{
	_btnhold = 0;
	_btncook = 1;
} else
{
	_btnhold = 1;
	_btncook = 0;
};

if ((_key select 1) == _btncook) exitwith //start cooking
{
	if (GVAR(holding) && _type == 0) then
	{
		if (time - GVAR(cookclicktime) < 0.5) then
		{
			_this call FUNC(keypressed_cook);
		} else
		{
			GVAR(cookclicktime) = time;
		};
	};
	if (cameraview != "GUNNER") then {player switchcamera cameraview} else {player switchcamera "INTERNAL"};
	true
};
if ((_key select 1) != _btnhold) exitwith {false};
_maxspeed = getNumber(__cfg>>"initSpeed");
_minspeed = 0; //8 min _maxspeed*0.5;
_width = _maxspeed - _minspeed;
switch (_type) do 
{
	case 0: //hold down to throw
	{
			GVAR(speed) = 0;
			GVAR(initholdtime)=time;
			GVAR(holding)=true;
			GVAR(holdtime) = 0;
			0 = _maxspeed spawn
			{
				while {GVAR(holding) && GVAR(speed)<=0.999 } do
				{
					GVAR(holdtime) = time - GVAR(initholdtime);
					if(GVAR(holdtime)>0.25) then
					{
						__ctrl ctrlShow true;
						__ctrlbg ctrlShow true;
						GVAR(speed) = ((GVAR(holdtime)-0.25)*GVAR(opt_velrate)) min 1;
						//GVAR(speed) = 0.125 * ceil(8*GVAR(speed));
						GVAR(speed) call FUNC(indicator);
					};
					sleep 0.01;
				};
			};
	};
	default //release button
	{
		GVAR(holding)=false;
		if (GVAR(holdtime)<0.25) then {GVAR(speed)=(1 min GVAR(opt_1clickampl));GVAR(speed) call FUNC(indicator)};
		GVAR(throwdir) = player weapondirection "Put"; //unsafe if turning while throwing but more precise
		__ctrl ctrlShow false;
		__ctrlbg ctrlShow false;
	};
};
GVAR(speed) call FUNC(indicator);

true