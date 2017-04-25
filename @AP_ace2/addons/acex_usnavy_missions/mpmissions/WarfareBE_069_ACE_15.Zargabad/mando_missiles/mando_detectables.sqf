/*
mando_detectables.sqf by Mandoble

Checks for the presence of  detectable missiles, so they can be intercepted by other missiles.
And updates the global array of detectable missiles.

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

private ["_arraym", "_arrayt", "_numitems", "_i"];
_arraym = [];
_arrayo = [];
while {true} do
{
   While {!mando_detmissilereq} do
   {
      Sleep 0.2;
      _numitems = count mando_detmissiles;
      _arraym = [];
      _arrayo = [];
      for [{_i = 0},{_i < _numitems},{_i = _i + 1}] do
      {
         _item = mando_detmissiles select _i;
         if (!isNull _item) then
         {
            _arraym = _arraym + [_item];
            _arrayo = _arrayo + [mando_detowners select _i];
         };
      };
      mando_detmissiles = _arraym;
      mando_detowners   = _arrayo;
   };
   mando_detmissiles = mando_detmissiles + [mando_detmissile];
   mando_detowners = mando_detowners + [mando_detmissileowner];
   mando_detmissilereq = false;
};