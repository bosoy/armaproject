private ["_magazines","_muzzles","_p","_primw","_s","_weapons"];

_weapons = [];
_magazines = [];

if (isNil "x_weapon_respawn") then {x_weapon_respawn = false};
if (isNil "x_weapon_array") then {x_weapon_array = []};
if (isNil "x_teamstatus_dialog") then {x_teamstatus_dialog = false};
if (isNil "x_backpack") then {x_backpack = false};
if (isNil "x_player_is_dropman") then {x_player_is_dropman = false};

while {true} do {
	waitUntil {!alive player};
	_p = player;
	if (x_weapon_respawn) then {
		if (count x_weapon_array == 0) then {
			_weapons = weapons _p;
			_magazines = magazines _p;
		} else {
			_weapons = x_weapon_array select 0;
			_magazines = x_weapon_array select 1;
			x_weapon_array = [];
		};
	};

	_hasruck = false;
	_ruckmags = [];
	_ruckweapons = [];
	if (_p call ace_sys_ruck_fnc_hasRuck) then {
      _ruckmags = _p getvariable "ACE_RuckMagContents";
      _hasruck = true;
      _ruckweapons = _p getvariable "ACE_RuckWepContents";
   };

	if (x_show_settings) then {
		_p removeAction x_settings_action;
	};
	if (x_backpack) then {
		if (pbp_id != -1) then {
			_p removeAction pbp_id;
		};
	};
	if (x_teamstatus_dialog) then {
		_p removeAction ts_id;
	};

	if (x_player_is_dropman) then {
		_p removeAction x_drop_action_id;
	};
	removeAllItems _p;
	removeAllWeapons _p;
	waitUntil {alive player};
	_p = player;
	if (x_weapon_respawn) then {
		removeAllItems _p;
		removeAllWeapons _p;
		{_p addMagazine _x;} forEach _magazines;
		{_p addWeapon _x;} forEach _weapons;
		_primw = primaryWeapon _p;
		if (_primw != "") then {
			_p selectWeapon _primw;
			_muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
			_p selectWeapon (_muzzles select 0);
		};
	};

	if (_hasruck) then {
		if (!isNil "_ruckmags") then {
			_p setvariable ["ACE_RuckMagContents", _ruckmags];
		};
		if (!isNil "_ruckweapons") then {
			_p setvariable ["ACE_RuckWepContents", _ruckweapons];
		};
   };

	if (x_show_settings) then {
		x_settings_action = _p addAction ["Settings", "x_scripts\x_showsettings.sqf",[],-1,false];
	};

	if (x_backpack) then {
		if (count player_backpack == 0) then {
				if (primaryWeapon _p != "") then {
					_s = format ["%1 to Backpack", primaryWeapon _p];
					pbp_id = _p addAction [_s, "x_scripts\x_backpack.sqf",[],-1,false];
				};
		} else {
			_s = format ["Weapon %1", (player_backpack select 0)];
			pbp_id = _p addAction [_s, "x_scripts\x_backpack.sqf",[],-1,false];
		};
	};


	if (x_dynamic_weather) then {
		0 setFog 0.0;
		0 setOvercast 0.0;
		0 setRain 0.0;
		if (x_dynamic_weather_sandstorm) then {x_do_sandstorm = false;};
	} else {
		if (!(isNil "rainy")) then {
			0 setFog 0.0;
			0 setOvercast 0.0;
			0 setRain 0.0;
			if (x_dynamic_weather_sandstorm) then {x_do_sandstorm = false;};
		};
	};
	"RadialBlur" ppEffectAdjust [0.0, 0.0, 0.0, 0.0];
	"RadialBlur" ppEffectCommit 0;
	"RadialBlur" ppEffectEnable false;
	"DynamicBlur" ppEffectEnable false;
};

if (true) exitWith {};