/* MMA HUD customization - lifting Mandoble - January 2010 */

DisableSerialization;

private["_camon","_cam", "_veh", "_to_sleep", "_pos", "_offset_x", "_offset_y", "_had_null_display", "_log", "_closest", "_closest_pos", "_mindist", "_dist", "_unit", "_old_closest"];
_veh = vehicle player;
_camon = false;

_offset_x = 0.85;
_offset_y = 0.95;
_had_null_display = true;
_log = "logic" createVehicleLocal [0,0,0];
_old_closest = objNull;

_to_sleep = 0.1;
while {!mando_exit_hud} do
{
   if (mando_key_pressed == mando_keyspecial) then
   {	
      mando_key_pressed = -1;
      if (_camon) then
      {
         _camon = false;
         _to_sleep = 0.1;
         _cam cameraeffect ["terminate", "back"];
         camDestroy _cam;
      }
      else
      {
         showCinemaBorder false;
         _cam = "camera" camcreate [0, 0, 0];
         _cam cameraeffect ["internal", "back"];
         _cam camSetFov 1;
         _cam camCommit 0;
         if (_veh isKindOf "UH1Y") then 
         {
            _cam attachTo [_veh, [0,-5,-5]];
         }
         else 
         {
            _cam attachTo [_veh, [0,0,-3]];
         };

         _cam attachTo [_veh, [0,0,-3]];
         _camon = true;
         _to_sleep = 0.01;
      };
   };

   if (_camon) then
   {
      _pos = getPos _veh;
      _dir = getdir _veh;
      _cam camSetTarget [(_pos select 0)+sin(_dir)*2, (_pos select 1)+cos(_dir)*2, -30];
      _cam camCommit 0;
   };

   _display = UINameSpace GetVariable "mandotarget_disp";
   if (!IsNull _display) then 
   {
      if (_had_null_display) then
      {
         _had_null_display = false;

         // Display setup
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlSetPosition [(_offset_x)-(0.08+0.01), _offset_y-(0.08 + 0.01)*4/3, 0.16+0.02, (0.16+0.02)*4/3];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlCommit 0;
         ((UINameSpace GetVariable "mandotarget_disp") displayCtrl 50) CtrlSetTextColor [0.2,0.2,0.2,0.5];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlSetText "mando_missiles\solid.jpg";


         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 51) CtrlSetPosition [_offset_x-0.025, _offset_y-0.025*4/3, 0.05, 0.05*4/3];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 51) CtrlCommit 0;
         ((UINameSpace GetVariable "mandotarget_disp") displayCtrl 51) CtrlSetTextColor [0.6,0.6,0.6,0.5];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 51) CtrlSetText getText (configFile>> "cfgVehicles" >> (typeOf _veh) >> "Icon");


         for [{_i=0},{_i<6},{_i=_i+1}] do
         {
            ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (52 + _i)) CtrlSetText "mando_missiles\mandotarget_circle.paa";
         };

         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 58) CtrlSetPosition [0, 0, 0.02, 0.02*4/3];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 58) CtrlCommit 0;
         ((UINameSpace GetVariable "mandotarget_disp") displayCtrl 58) CtrlSetTextColor [0.6,0.6,0.6,0.5];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 58) CtrlSetText "mando_missiles\mandocamera_rect.paa";

         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetPosition [_offset_x+(0.08+0.01-0.03), _offset_y-(0.08 + 0.01)*4/3+(0.16-0.03)*4/3, 0.03, 0.03*4/3];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlCommit 0;
         ((UINameSpace GetVariable "mandotarget_disp") displayCtrl 59) CtrlSetTextColor [0.6,0.6,0.6,0.5];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetText "";
         _old_closest = objNull;


         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetTextColor [1.0, 1.0, 1.0, 0.5];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["Camera: %1", mando_keyspecialname];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetPosition [(_offset_x)-(0.08+0.01), _offset_y-(0.08 + 0.01)*4/3+(0.16)*4/3, 0.16+0.02, 0.02];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlCommit 0;
      };

      _units = nearestObjects [[getPos _veh select 0, getPos _veh select 1, 0], ["Car", "Motorcycle", "ReammoBox", "Tank", "StaticWeapon"], 50];

      if (_veh in _units) then
      {
         _units = _units - [_veh];
      };

      _log setPos [getPos _veh select 0, getPos _veh select 1, 0];
      _log setDir getDir _veh;

      _min_dist = 9999;
      for [{_i=0},{_i<6},{_i=_i+1}] do
      {
         if (_i < count _units) then
         {
            _unit = _units select _i;
            _pos = _log worldToModel getPos _unit;

            // 0.08 = 50m.
            _pos = [_offset_x -0.01 + (_pos select 0)*0.08/50, _offset_y - 0.01 - (_pos select 1)*0.08/50*4/3, 0.02, 0.02*4/3];

            ((UINameSpace GetVariable "mandotarget_disp") displayCtrl (52 + _i)) CtrlSetTextColor [0.7,0.7,0.7,0.7];
            ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (52 + _i)) CtrlSetPosition _pos;
            ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (52 + _i)) CtrlCommit 0.02;

            _dist = _log distance _unit;
            if (_dist < _min_dist) then
            {
               _min_dist = _dist;
               _closest_pos = +_pos;
               _closest = _unit;
            };
         }
         else
         {
            ((UINameSpace GetVariable "mandotarget_disp") displayCtrl (52 + _i)) CtrlSetTextColor [1,1,1,0];
         };
      };

      if (_min_dist < 100) then
      {
         ((UINameSpace GetVariable "mandotarget_disp") displayCtrl 58) CtrlSetTextColor [0.6,0.6,0.6,0.5];
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 58) CtrlSetPosition _closest_pos;
         ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 58) CtrlCommit 0.0;

         if (_closest != _old_closest) then
         {
            _old_closest = _closest;
            ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetText getText (configFile>> "cfgVehicles" >> (typeOf _closest) >> "Icon");
            ((UINameSpace GetVariable "mandotarget_disp") displayCtrl 59) CtrlSetTextColor [0.6,0.6,0.6,0.5];
         };
      }
      else
      {
         ((UINameSpace GetVariable "mandotarget_disp") displayCtrl 58) CtrlSetTextColor [0.7,0.7,0.7,0];
         ((UINameSpace GetVariable "mandotarget_disp") displayCtrl 59) CtrlSetTextColor [0.6,0.6,0.6,0];
         _old_closest = objNull;
      };
   }
   else
   {
      _had_null_display = true;
   };

   Sleep _to_sleep;
};

_cam cameraeffect ["terminate", "back"];
camDestroy _cam;
deleteVehicle _log;