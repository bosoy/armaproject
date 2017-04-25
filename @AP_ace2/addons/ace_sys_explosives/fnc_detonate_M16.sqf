/* ace_sys_explosives (.pbo)| M16 Bouncing Betty | (c) 2008, 2009 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_trigger,_list);
_mine = [_trigger] call FUNC(get_mine);
if (isNull _mine) exitwith { false };

_mine spawn {
	_pos = position _this;
	sleep 0.5;
	_this animate ["ace_mine_bouncing",1];
	sleep 0.1;
	[_this] call FUNC(spawnpellets_360);
	_realHeight = [_this] call CBA_fnc_realHeight;
	_height = (_this modelToWorld (_this selectionPosition "mine")) select 2;
	TRACE_2("",_pos,_realHeight);

	_pos set [2,(_height + _realHeight + 0.3)];
	"ACE_PomzExplosion" createVehicle _pos;
	[_this] call FUNC(removeMine);
};
