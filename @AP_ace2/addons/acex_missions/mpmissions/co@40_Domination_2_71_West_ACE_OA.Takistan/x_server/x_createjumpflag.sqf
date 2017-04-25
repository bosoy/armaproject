// by Xeno
#define THIS_FILE "x_createjumpflag.sqf"
#include "x_setup.sqf"
private ["_posi", "_ftype", "_flag", "_jump_flags"];
if (!isServer) exitWith {};

// create random position
_posi = [GVAR(old_target_pos), GVAR(old_radius) select 0] call FUNC(GetRanPointCircleOld);
while {count _posi == 0} do {
	_posi = [GVAR(old_target_pos), GVAR(old_radius) select 0] call FUNC(GetRanPointCircleOld);
	sleep 0.04;
};

if (count _posi > 0) then {
	_flag = createVehicle [(call FUNC(GetOwnFlagType)), _posi, [], 0, "NONE"];
	_jump_flags = __XJIPGetVar(jump_flags);
	_jump_flags set [count _jump_flags, _flag];
	["jump_flags",_jump_flags] call FUNC(NetSetJIP);
	
	[QGVAR(n_jf), _flag] call FUNC(NetCallEventToClients);
	_s = if (GVAR(jumpflag_vec) == "") then {"NewJumpFlag"} else {"NewJumpVehFlag"};
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),_s,true];
};