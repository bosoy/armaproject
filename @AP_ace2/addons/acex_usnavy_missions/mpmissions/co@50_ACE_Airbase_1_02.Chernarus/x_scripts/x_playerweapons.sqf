// by Xeno
private ["_p", "_weapons", "_magazines", "_hasruck", "_ruckmags", "_ruckweapons", "_primw", "_muzzles"];
if (!(local player)) exitWith {};

player setVariable ["BIS_noCoreConversations", true];

while {true} do {
   waitUntil {!alive player};
   _p = player;
   _weapons = weapons _p;
   _magazines = magazines _p;
   _hasruck = false;
   _ruckmags = [];
   _ruckweapons = [];
   if (_p call ace_sys_ruck_fnc_hasRuck) then {
      _ruckmags = _p getvariable "ACE_RuckMagContents";
      _hasruck = true;
      _ruckweapons = _p getvariable "ACE_RuckWepContents";
   };
   removeAllItems _p;
   removeAllWeapons _p;
   waitUntil {alive player};
   player setVariable ["BIS_noCoreConversations", true];
   _p = player;
   removeAllItems _p;
   removeAllWeapons _p;
   {_p addMagazine _x;} forEach _magazines;
   {_p addWeapon _x;} forEach _weapons;
    _primw = primaryWeapon _p;
    if (_primw != "") then {
        _p selectWeapon _primw;
      //  Fix for weapons with grenade launcher
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

if (true) exitWith {};
