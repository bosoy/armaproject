// W80 nuclear warhead
// w80.sqf v1.0
// Aug 2010 Evil Echo
// 
// Nuclear weapon
// This script may be used as explosion script argument for mando_missile.sqf

private [
	"_pos",
	"_target",
	"_side",
	"_launcher",
	"_handle"
];

_pos = _this select 0;
_target = _this select 1;
_side = _this select 2;
_launcher = _this select 3;

_handle = [_pos, 5.0] execVM "mando_missiles\warheads\echo\nuclear_explosion.sqf";
