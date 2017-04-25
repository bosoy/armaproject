// mando_getpos.sqf
// By Mandoble April 2007
//
// MODIFIED by Homer Johnston Feb 2009 to work in buildings, using modelToWorld
//
// Check prone, crouch or standing up state of a soldier
//
//
// Returns 0 for standing up, 1 for crouch, 2 for prone, -1 for unkown.
// calling example:
// (first get the code handle: mando_getpos = compile (preprocessFileLineNumbers "mando_getpos.sqf")
// then call the function as many times as needed:
// _pos = [player] call mando_getpos
//
// Note: Adjust _alts array if needed for different soldier heights

private ["_unit", "_alts", "_found", "_vdir", "_dir", "_i", "_pos1", "_pos2", "_selection"];
_unit = _this select 0;

_Offset = [0,0,0];
_worldPos = _unit modelToWorld _Offset;
_Hgt = _worldPos select 2; // this will later be returned as a result of this function, for possible use
_alts = [1.4+_Hgt,1+_Hgt,0.2+_Hgt];

_found = -1;
_vdir = vectorDir _unit;
_dir = (_vdir select 0) atan2 (_vdir select 1);
for [{_i = 0},{_i < 3},{_i = _i + 1}] do
{
   _pos1 = [(getPos _unit select 0)+sin(_dir+180)*2, (getPos _unit select 1)+cos(_dir+180)*2, (getPos _unit select 2)+(_alts select _i)-(_vdir select 2)*2];
   _pos2 = [(getPos _unit select 0)+sin(_dir)*2, (getPos _unit select 1)+cos(_dir)*2, (getPos _unit select 2)+(_alts select _i)+(_vdir select 2)*2];
   _selection = [_unit, "FIRE"] intersect [_pos1, _pos2];
   if ((count _selection > 0) && (_found == -1)) then
   {
      _found = _i;
   }
};
[_found, _Hgt]