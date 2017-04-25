/*
mando_remotes_e.sqf v1.0
July 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/
private["_old_remote", "_deleted", "_list", "_target"];

mando_remote_e         = objNull;
mando_remote_selected  = -1;
_old_remote            = objNull;
_deleted               = false;
mando_remote_targets_e = [];
_list                  = [];
_target                = objNull;

while {true} do
{
   while {(mando_remote_e == _old_remote) || isNull mando_remote_e} do
   {
      _deleted = false;
      _list = [];

      for [{_i = 0}, {_i < (count mando_remote_targets_e)},{_i = _i + 1}] do
      {
         _target = mando_remote_targets_e select _i;
         if ((!isNull _target)&&(damage _target < 0.3)) then
         {
            _list = _list + [mando_remote_targets_e select _i];
         }
         else
         {
            _deleted = true;  
         };
      };

      if (_deleted) then
      {
         mando_remote_targets_e = [];
         mando_remote_targets_e = mando_remote_targets_e + _list;
      };
      Sleep 0.5;
   };

   if (!(mando_remote_e in mando_remote_targets_e) && !(isNull mando_remote_e)) then
   {
      mando_remote_targets_e = mando_remote_targets_e + [mando_remote_e];
   };
   _old_remote = mando_remote_e;
};
