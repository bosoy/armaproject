// _________________________________________________________________________________________________________________
// | Coop Essential Pack by -eutf-Myke                                                                             |
// |_______________________________________________________________________________________________________________|
// | Do not change this scrip!                                                                                     |
// |_______________________________________________________________________________________________________________|
// | cep initialization script                                                                                     |
// |_______________________________________________________________________________________________________________|
// Heavily modified by Wolffy.au
// Usage: _cep_init = [TriggerDistance] execVM "coop_essential\cep_init.sqf";

if (!isServer) exitwith {};
_trigDist = 1000;
if(count _this > 0) then {
	_trigDist = _this select 0;
};
_delay = 30;
if(count _this > 1) then {
	_delay = _this select 1;
};
cep_cached_grps = [];
cep_fcache = compile preprocessFileLineNumbers "coop_essential\cep_cache_units.sqf";

waitUntil{typeName allGroups == "ARRAY"};

while{count allGroups > 0} do {
	sleep _delay;
	{
		_disable = (group _x) getVariable "crB_disableCache";
		_disable = if(isNil "_disable") then { false; } else {_disable;};
		if(!_disable) then {
			(group _x) setVariable ["crB_disableCache", true];
		};
	} forEach (playableUnits + switchableUnits);

	{
		_disable = _x getVariable "crB_disableCache";
		_disable = if(isNil "_disable") then { false; } else {_disable;};
		if (!_disable && !(_x in cep_cached_grps)) then {
			cep_cached_grps = cep_cached_grps + [_x];
			[leader _x, _trigDist] spawn cep_fcache;
			sleep 0.2;
		};
	} forEach allGroups;
};
