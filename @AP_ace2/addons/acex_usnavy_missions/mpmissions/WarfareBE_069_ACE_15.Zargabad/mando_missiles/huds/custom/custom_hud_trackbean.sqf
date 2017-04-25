/* MMA HUD customization - lifting Mandoble - January 2010 */

DisableSerialization;

private["_camon","_cam", "_veh", "_to_sleep", "_pos", "_offset_x", "_offset_y", "_had_null_display", "_log", "_closest", "_closest_pos", "_mindist", "_dist", "_unit", "_old_closest"];
_veh = vehicle player;
_camon = false;

_offset_x = 0.85;
_offset_y = 0.95;
_had_null_display = true;

_to_sleep = 0.1;
while {!mando_exit_hud} do
{
   if (mando_key_pressed == mando_keyspecial) then
   {	
      _vehs = nearestObjects [_veh modelToWorld [0,100,0], ["Air"], 80];
      {
         if (_x != _veh) then
         {
            [_veh, _x] spawn
            {
               _veh = _this select 0;
               _target = _this select 1;
               _alt = (getPos _target) select 2;
               while {(abs(speed _veh) < 20) && (_alt > 2) && (alive _target)} do
               {
                  _pos = _veh worldToModel (getPos _target);
                  _pos set [2, (_pos select 2)-0.5];
                  _target attachTo [_veh, _pos];
                  _alt = (getPos _target) select 2;
                  Sleep 0.05; 
               };
               detach _target;
               4 cutText ["Target freed", "PLAIN"];		
            };
         };
      } forEach _vehs;
      mando_key_pressed = -1;
   };


   _display = UINameSpace GetVariable "mandotarget_disp";
   if (!IsNull _display) then 
   {
      if (_had_null_display) then
      {
         _had_null_display = false;

         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetTextColor [1.0, 1.0, 1.0, 0.5];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["Unlock: %1", mando_keyspecialname];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetPosition [(_offset_x)-(0.08+0.01), _offset_y-(0.08 + 0.01)*4/3+(0.16)*4/3, 0.16+0.02, 0.02];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlCommit 0;
      };
   }
   else
   {
      _had_null_display = true;
   };

   Sleep _to_sleep;
};