private["_veh", "_i", "_j", "_modes", "_muzzles", "_weapons", "_idx", "_weapon"];
_veh = _this select 0;
_weapon = _this select 1;
_modes = [];
_weapons = [];
_weapons = _weapons + weapons _veh;
_i = 0;
_idx = -1;
for [{_j=0},{(_j < count _weapons) && (_idx == -1)},{_j=_j+1}] do
{
   if ((_weapons select _j) == _weapon) then
   {
      _idx = _i;
   };
   _modes = getArray(configFile>>"cfgWeapons" >> (_weapons select _j) >> "modes"); 
   _i = _i + ((count _modes) max 1);
} forEach _weapons;

_idx