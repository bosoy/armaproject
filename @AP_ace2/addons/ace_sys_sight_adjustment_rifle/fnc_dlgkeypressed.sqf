#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

private ["_key","_type","_h"];
_type = _this select 1;
_key = (_this select 0) select 1;
//hint format ["%1",_this];
_h = true;
switch (_key) do
{
	case 200: //up
	{
		if (_type == 0) then
		{
			call FUNC(NextElev);
		} else
		{
			call FUNC(NextRng);
		};
	};
	case 208: //down
	{
		if (_type == 0) then
		{
			call FUNC(PrevElev);
		} else
		{
			call FUNC(PrevRng);
		};
	};
	case 203: //left
	{
		call FUNC(PrevWnd);
	};
	case 205: //right
	{
		call FUNC(NextWnd);
	};
	case 28: //Enter to close and apply
	{
		if (_type == 0) then
		{
			call FUNC(ApplyElevChanges);
		}  else
		{
			call FUNC(ApplyRngChanges);
		};
	};
	case 156: //NUM Enter to close and apply
	{
		if (_type == 0) then
		{
			call FUNC(ApplyElevChanges);
		}  else
		{
			call FUNC(ApplyRngChanges);
		};
	};
	case 42: //shift
	{
		GVAR(shiftdown) = true;
	};
	default {_h = false};
};

_h
