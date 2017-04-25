/*
mando_remotes_r.sqf v1.0
July 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/
private["_old_remote", "_deleted", "_list", "_target"];

mando_remote_r         = objNull;
mando_remote_selected  = -1;
_old_remote            = objNull;
_deleted               = false;
mando_remote_targets_r = [];
_list                  = [];
_target                = objNull;

while {true} do
{
   while {(mando_remote_r == _old_remote) || isNull mando_remote_r} do
   {
      _deleted = false;
      _list = [];

      for [{_i = 0}, {_i < (count mando_remote_targets_r)},{_i = _i + 1}] do
      {
         _target = mando_remote_targets_r select _i;
         if ((!isNull _target)&&(damage _target < 0.3)) then
         {
            _list = _list + [mando_remote_targets_r select _i];
         }
         else
         {
            _deleted = true;  
         };
      };

      if (_deleted) then
      {
         mando_remote_targets_r = [];
         mando_remote_targets_r = mando_remote_targets_r + _list;
      };
      Sleep 0.5;
   };

   if (!(mando_remote_r in mando_remote_targets_r) && !(isNull mando_remote_r)) then
   {
      mando_remote_targets_r = mando_remote_targets_r + [mando_remote_r];
   };
   _old_remote = mando_remote_r;
};
