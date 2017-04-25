#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

private ["_zchange","_type"];
//if (ctrlVisible 4000) exitwith {false}; //range card scrolling
_type = _this select 1;
_zChange = (_this select 0) select 1;
//hint format ["%1",_this select 0];
if !(GVAR(shiftdown)) then	//no shift pressed - elevation
{
	if (_zchange > 0) then
	{
		if (_type == 0) then
		{
			call FUNC(NextElev);
		} else
		{
			call FUNC(NextRng);
		};
	} else
	{
		if (_type == 0) then
		{
			call FUNC(PrevElev);
		} else
		{
			call FUNC(PrevRng);
		};
	};
} else	//shift pressed - windage
{
	if (_zchange > 0) then
	{
		call FUNC(NextWnd);
	} else
	{
		call FUNC(PrevWnd);
	};
};

true
