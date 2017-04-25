Private ['_config','_faction','_group','_kind','_side','_type'];
_side = _this select 0;
_faction = _this select 1;
_kind = _this select 2;
_type = _this select 3;

_config = configFile >> "CfgGroups" >> _side >> _faction >> _kind >> _type;
_group = [];

if (isClass _config) then {
	for "_j" from 0 to ((count _config) - 1) do {
		private ["_mclass"];
		_mclass = _config select _j;
		
		if (isClass (_mclass)) then {
			_group = _group + [getText(_mclass >> "vehicle")];
		};
	};
} else {
	diag_log Format ["[WFBE (ERROR)][frameno:%1 | ticktime:%2] Common_GetGroupFromConfig: Entry (configFile >> 'CfgGroups' >> '%3' >> '%4' >> '%5' >> '%6') is not a valid group config.",diag_frameno,diag_tickTime,_side,_faction,_kind,_type];
};

_group