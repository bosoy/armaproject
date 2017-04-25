/* ace_sys_spacebar | (c) 2009 by rocko */

private["_t","_s"];
_t = group _this;
_s = "HOSTILE";
switch (side _t) do {
	case WEST: {
		if (player countFriendly [_t] == 1) then { _s = "FRIENDLY"; };
	};
	case EAST: {
		if (player countFriendly [_t] == 1) then { _s = "FRIENDLY"; };
	};
	case CIVILIAN: {
		if (_this isKindOf "Reammobox" && {!(_this isKindOf "ACE_Explosive_Object")}) then {
			_s = "FRIENDLY";
		};
	};
	case RESISTANCE: {
		if (player countFriendly [_t] == 1) then { _s = "FRIENDLY"; };
	};
	default {
		if (_this isKindOf "ACE_Rucksack_crate" || _this isKindOf "Reammobox") then {
			_s = "FRIENDLY";
		};
	};
};

_s
