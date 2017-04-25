//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_target,_ruck_cont);
private ["_magAry", "_wepAry", "_lock_scope"];

_magAry = _ruck_cont select 0;
_wepAry = _ruck_cont select 1;
//TODO: Temporarily disable own ruck usage
{
	if (count _x < 3) then {
		_newar = [];
		_newac = getNumber(configFile/"CfgMagazines"/(_x select 0)/"count");
		for "_ez" from 1 to (_x select 1) do {
			_newar set [count _newar, _newac];
		};
		_x set [count _x, _newar];
	};
} forEach _magAry;
_target setVariable ["ACE_RuckMagContents", _magAry];
_target setVariable ["ACE_RuckWepContents", _wepAry];
_target setVariable ["ACE_RuckContents_Net", nil, true];
_lock_scope = _target getVariable ["ACE_Ruck_Lock_Scope", "Team"];
TRACE_1("",_lock_scope);
_target setVariable ["ACE_Ruck_Lock", _lock_scope, true];
_target setVariable ["ACE_Ruck_Lock_Unit", nil];
