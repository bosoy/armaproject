/* mando_laser.sqf
By Mandoble Oct 2007

*/

private ["_unit", "_params", "_weapon", "_activate", "_pos", "_delta", "_log", "_logt", "_vdir", "_hitground", "_first"];

_unit = _this select 0;
_params = (_this select 3);
_weapon = _params select 0;
_activate = _params select 1;
_unit removeAction mando_laseraction;
_unit removeAction mando_laseraction2;

if (!_activate) exitWith
{
   mando_laser_on = false;
   mando_laseraction = _unit addAction ["Laser ON", mando_missile_path+"units\mando_laser.sqf", [_weapon, true]];
   mando_laseraction2 = 1;
};


mando_laser_on = true;
_logt = "logic" createVehicle [0,0,0];
_log = "logic" createVehicleLocal [0,0,0];
mando_laseraction = _unit addAction ["Laser OFF", mando_missile_path+"units\mando_laser.sqf", [_weapon, false]];
mando_laseraction2 = _unit addAction ["Transmit laser target", mando_missile_path+"units\mando_laserok.sqf", [_logt, side player]];

_maxscanrange = 2000;
_first = true;
while {mando_laser_on} do
{

   _vdir = [0,0,0];
   if (_weapon == "") then 
   {
      _vdir = vectorDir _unit;
   }
   else
   {
      _vdir = _unit weaponDirection _weapon;
   };
   _dst = 10;
   _posini = [getPosASL _unit select 0,getPosASL _unit select 1,(getPosASL _unit select 2)+1.7];

   _delta = 10;
   _hitground = false;
   while {(_dst < _maxscanrange) && !_hitground} do
   {
      _pos = [(_posini select 0)+(_vdir select 0)*_dst, 
              (_posini select 1)+(_vdir select 1)*_dst, 
              (_posini select 2)+(_vdir select 2)*_dst];

      _log setPosASL _pos;
      if ((getPos _log select 2) < 0.05) then
      {
         _hitground = true;
      }
      else
      {
         _dst = _dst + _delta;
      };
   };

   if (_hitground) then
   {
      _logt setPosASL _pos;
   };
   Sleep 0.2;
};

deleteVehicle _log;
deleteVehicle _logt;