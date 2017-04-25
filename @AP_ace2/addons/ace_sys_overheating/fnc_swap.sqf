/* ace_sys_overheating | Barrel Swap | (c) 2011 rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

player spawn {
	_unit = _this;
	_anim = if ((_unit call CBA_fnc_getUnitAnim) select 0 == "prone") then { "MGunMagazineReloadProne" } else { "MGunMagazineReloadKneel" };
	_unit playMove _anim;
	_unit setVariable ["ACE_PB_Result", 0];
	[3.8,[localize "STR_ACE_SWAPBARRELACT"],true,true] spawn ace_progressbar;
	waitUntil { (_unit getVariable "ACE_PB_Result" != 0) };
	if (_unit getVariable "ACE_PB_Result" == 1) then { _unit playMove _anim; };
	_unit setVariable ["ACE_PB_Result", 0];
	[3.8,[localize "STR_ACE_SWAPBARRELACT"],true,true] spawn ace_progressbar;
	waitUntil { (_unit getVariable "ACE_PB_Result" != 0) };
	if (_unit getVariable "ACE_PB_Result" == 1) then {
		_lst = _unit getVariable [QGVAR(lst),0]; //lastSwapTime
		_cbh = _unit getVariable [QGVAR(cbh),0]; //currentBarrelHeat
		_dif = time - _lst;
		_unit setVariable [QGVAR(lst), time, false];
		_unit setVariable [QGVAR(cbh),(GVAR(cur) select 1),false];
		_temp = _cbh - (GVAR(cur) select 2)*_dif;
		if (_temp < 0) then { _temp = 0 };
		GVAR(cur) set [1,_temp];
	};
};
