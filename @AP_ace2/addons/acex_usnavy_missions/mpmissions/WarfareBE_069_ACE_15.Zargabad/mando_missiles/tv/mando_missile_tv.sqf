/*********************************************************************************
   mando_missile_tv.sqf v1.4
   by Mandoble, June 2010

   Example activation action scripts for several systems can be found into mando_missiles\tv\tv_types folder. These scripts are used as sixth parameter for mando_mccallow_by_name.sqf or mando_mccallow_by_type.sqf.

   Globals required (set them from the corresponding activation action script)

   mando_tv_info: Short description, displayed at the bottom of the camera
   mando_tv_ang_to_lock: Max deviation angle between camera center and a displayed potential target to lock it on
   mando_tv_no_manauto: Manual/Semiauto buttom disabled?
   mando_tv_no_remloc: Remote/Local buttom disabled?
   mando_tv_man: Manual as initial guidance mode? (if not, semi auto).
   mando_tv_remote: Remote as initial mode? (if not, local).
   mando_tv_max_ang: Maximum camera angle deviation with default camera heading in X/Y plane.
   mando_tv_wtype: "MISSILE" or "GUN"
   mando_tv_sensor_rng_w: Sensor range (width of the area)
   mando_tv_sensor_rng_l: Sensor range (Length of the area)
   mando_tv_ammo_base: If BIS weapons are used, base or particular class of the BIS ammo (usually "MissileBase", "LaserBombCore" or "RocketBase")
   
   mando_tv_gun_ammo: Ammo type for gun, for example "B_23mm_AA".
   mando_tv_gun_sound: Sound defined resource for gun salvo, for example "mando_gun_lite".
   mando_tv_gun_dispersion: Gun max dispersion in degrees [xy,z], for example [0.6,0.6].


   Note about missile idx (set from mando_mccallow_by_name.sqf or mando_mccallow_by_type.sqf): This idx is >= 0 for virual missiles or bombs, else the idx is the BIS weapon index + 1 and as negative number, for example, to use BIS weapon index 3, the missile index would be -4.

   Note about mando_mccallow_by_name.sqf and mando_mccallow_by_type.sqf fixed direction parameter: For TV systems this parameter indicates the default camera direction relative to direction of the vehicle. For example, -90 means the camera initial direction will be looking at the left of the vehicle. The camera limits in XY axis is determined by mando_tv_max_ang, in Z the limits are fixed to +-85 degrees.

   Note about mando_mccallow_by_name.sqf and mando_mccallow_by_type.sqf fixed direction parameter: For TV systems this parameter indicates the number of seconds to wait between firing and firing again (you may use fraction of seconds too, for example, for gun salvoes).

*********************************************************************************/


if (isNil "MandoWorldToScreen2tv") then
{
   MandoWorldToScreen2tv = 
   {
      private["_vehicle", "_target", "_pos", "_posu", "_disth", "_distv", "_hscreen", "_vscreen", "_sinhscreen", "_sinvscreen", "_angh", "_angv", "_vdir"];
      _vehicle = _this select 0;
      _target  = _this select 1;
      _vdir    = _this select 2;   


      if (count _vdir == 0) then 
      {
         _pos = _vehicle worldToModel (getPos _target);
         _disth = sqrt((_pos select 0)^2+(_pos select 1)^2);
         _distv = sqrt(((getPosASL _target select 2) - (getPosASL _vehicle select 2))^2+_disth^2);

         if (_disth < 0.1) then
         {
            _disth = 0.1;
         };
         if (_distv < 0.1) then
         {
            _distv = 0.1;
         };
         _sinvscreen = (_pos select 2)/_distv;
         _angh = (_pos select 0) atan2 (_pos select 1);
         _angv  = asin(_sinvscreen);
      }
      else
      {
         _pos = getPosASL _target;
         _posu = getPosASL _vehicle;

         _angh = (((_pos select 0)-(_posu select 0)) atan2 ((_pos select 1)-(_posu select 1))) - ((_vdir select 0) atan2 (_vdir select 1));
         if (_angh > 180) then
         {
            _angh = _angh - 360;
         };
         if (_angh < -180) then
         {
            _angh = _angh + 360;
         };

         _angv = asin(((_pos select 2)-(_posu select 2))/(_target distance _vehicle)) - (asin(_vdir select 2));
      };

   // 32.5 degrees = 0.5 screen
      _hscreen = _angh*0.5/45;
      _vscreen = _angv*0.5/35;

      [_hscreen, _vscreen, _angh, _angv]
   };
};


disableSerialization;

private ["_event", "_params", "_display", "_i", "_first","_marker", "_missparam", "_target", "_target1", "_target2", "_continue", "_mis", "_firing_dir", "_rects", "_texts"];



_first = false;
if (count _this == 0) then
{
   _first = true;
}
else
{
   if (typeName (_this select 0) != "STRING") then
   {
      _first = true;
   }
   else
   {      
      _event = _this select 0;
      _params = _this select 1;
   };
};


if (_first) exitWith
{
   disableSerialization;

   if (isNil "mandotarget_disp_on") then
   {
      mandotarget_disp_on = false;
   };
   mandotarget_disp_on_old = mandotarget_disp_on;
   mandotarget_disp_on = false;
   3 cutText["", "PLAIN"];
   mando_rec_flir = false;

   if (isNil "mando_missile_tv") then
   {
      mando_missile_tv = compile (preprocessFileLineNumbers (mando_missile_path+"tv\mando_missile_tv.sqf"));
   };


   if (isNil "mando_tv_backcolor") then
   {
      // HELP, MAP, TGT, MODE, FLIR, FIRE, XMIT, UP, DOWN
      mando_tv_backcolor = [mando_missile_path+"mfds\raptor6_mfd1.paa", [
[-0.086, 0.155,0.076, 0.075*4/3],
[-0.084, 0.31,0.076,0.075*4/3],
[-0.081, 0.46,0.0765,0.075*4/3],
[-0.082, 0.61,0.076,0.075*4/3],
[-0.082, 0.755,0.076,0.075*4/3],
[1.005, 0.155, 0.075, 0.075*4/3],
[1.005, 0.31, 0.075, 0.075*4/3],
[1.005, 0.61, 0.075,0.075*4/3],
[1.005, 0.755, 0.075,0.075*4/3]]];
   };

   if (typeName mando_tv_backcolor == "ARRAY") then
   {
      if (count mando_tv_backcolor != 2) then
      {
      // HELP, MAP, TGT, MODE, FLIR, FIRE, XMIT, UP, DOWN
         mando_tv_backcolor = [mando_missile_path+"mfds\raptor6_mfd1.paa", [
[-0.086, 0.155,0.076, 0.075*4/3],
[-0.084, 0.31,0.076,0.075*4/3],
[-0.081, 0.46,0.0765,0.075*4/3],
[-0.082, 0.61,0.076,0.075*4/3],
[-0.082, 0.755,0.076,0.075*4/3],
[1.005, 0.155, 0.075, 0.075*4/3],
[1.005, 0.31, 0.075, 0.075*4/3],
[1.005, 0.61, 0.075,0.075*4/3],
[1.005, 0.755, 0.075,0.075*4/3]]];
      }
      else
      {
         if (count (mando_tv_backcolor select 1) == 0) then
         {
            mando_tv_backcolor set [1, [
[-0.086, 0.155,0.076, 0.075*4/3],
[-0.084, 0.31,0.076,0.075*4/3],
[-0.081, 0.46,0.0765,0.075*4/3],
[-0.082, 0.61,0.076,0.075*4/3],
[-0.082, 0.755,0.076,0.075*4/3],
[1.005, 0.155, 0.075, 0.075*4/3],
[1.005, 0.31, 0.075, 0.075*4/3],
[1.005, 0.61, 0.075,0.075*4/3],
[1.005, 0.755, 0.075,0.075*4/3]]];
         };
      };
   };


   if (isNil "mando_tv_cam_pos") then
   {
      mando_tv_cam_pos = [0,3,-2];
   };

   if (isNil "mando_tv_firing_pos") then
   {
      mando_tv_firing_pos = mando_tv_cam_pos;
   };


   if (isNil "mando_tv_man") then
   {
      mando_tv_man = false;
   };

   if (isNil "mando_tv_remote") then
   {
      mando_tv_remote = false;
   };

   if (isNil "mando_tv_no_manauto") then
   {
      mando_tv_no_manauto = false;
   };

   if (isNil "mando_tv_no_remloc") then
   {
      mando_tv_no_remloc = false;
   };

   if (isNil "mando_tv_max_ang") then
   {
      mando_tv_max_ang = 181;
   };

   if (isNil "mando_tv_wtype") then
   {
      mando_tv_wtype = "MISSILE";
   };

   if (isNil "mando_tv_pilon") then
   {
      mando_tv_pilon = 1;
   };


   if (isNil "mando_tv_sensor_rng_w") then
   {
      mando_tv_sensor_rng_w = 1000;
   };

   if (isNil "mando_tv_sensor_rng_l") then
   {
      mando_tv_sensor_rng_l = 3000;
   };


   if (isNil "mando_tv_faf") then
   {
      mando_tv_faf = true;
   };

   if (isNil "mando_tv_keepgeo") then
   {
      mando_tv_keepgeo = false;
   };

   _ok = createDialog "MandoMissileTVDlg";
};



switch (_event) do
{

   case "onLoad":
   {

      // player action ["nvGogglesOff", player];
	  camUseNVG false;

      if ((typeName mando_tv_missileidx) != "SCALAR") then
      {
         mando_tv_weaponname = mando_tv_missileidx;
         mando_tv_missileidx = -1;
      };

      if ((mando_tv_missileparams select 1) == "") then
      {
         _magazines = getArray (configFile>>"cfgWeapons" >> mando_tv_weaponname >> "magazines");
         _ammo_class = getText (configFile>>"CfgMagazines" >> (_magazines select 0) >> "ammo");
         mando_tv_missileparams set [1, _ammo_class];
      };


      mando_cam_scale = 1;
      mando_take_pic = false;
      mando_tv_map_on = false;
      mando_irtone_on = false;

      mando_tvcam_scale = 1;
      mando_tvcam_angles = [0,0];
      if (isNil "mando_tv_plane") then
      {
         mando_tv_plane = vehicle player;
      };

      if (isNil "mando_tv_laserlogic_target") then
      {
         mando_tv_laserlogic_target = objNull;
      };

      if (isNil "mando_tv_plane_old") then
      {
         mando_tv_plane_old = objNull;
      };

      if (isNil "mando_tv_target_types_old") then
      {
         mando_tv_target_types_old = "";
      };

      if (isNil "mando_tv_laserlogic") then
      {
         mando_tv_laserlogic = objNull;
      };

      if (isNil "mando_take_pic_on") then
      {
         mando_take_pic_on = false;
      };

      if ((mando_tv_plane_old != mando_tv_plane) || (mando_tv_target_types_old != (mando_tv_target_types select 0))) then
      {
         mando_tv_dest = [(getPos mando_tv_plane select 0)+(sin (getDir mando_tv_plane)*2000),(getPos mando_tv_plane select 1)+(cos (getDir mando_tv_plane)*2000), 0];

         if (!isNull mando_tv_laserlogic) then
         {
            deleteVehicle mando_tv_laserlogic;
         };
         mando_take_pic_on = false;
         mando_tv_laserlogic_target = objNull;
      };
      

      mando_tv_plane_old = mando_tv_plane;
      mando_tv_target_types_old = mando_tv_target_types select 0;
 
      mando_tv_cam = 0;
      mando_tv_move = false;

      if (isNil "mando_last_missile") then
      {
         mando_last_missile = objNull;
      };

      if (isNil "mando_last_missile_target") then
      {
         mando_last_target = objNull;
      };

      if (isNil "mando_last_target") then
      {
         mando_last_target = objNull;
      };

      _display = _params select 0;

// Back color has no effect, use only pic if exist

      if (typeName (mando_tv_backcolor select 0) == "STRING") then
      {
         (_display displayCtrl 23901) ctrlSetText (mando_tv_backcolor select 0);
      }
      else
      {
         (_display displayCtrl 23901) ctrlSetBackgroundColor mando_tv_backcolor;
      };


      (_display displayCtrl 23903) ctrlSetText (mando_missile_path+"mando_steer.paa");
      (_display displayCtrl 23904) ctrlSetText (mando_missile_path+"mandocamera_circle.paa");
      (_display displayCtrl 23905) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23929) ctrlSetText (mando_missile_path+"mandocamera_rombe.paa");
      (_display displayCtrl 23930) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23931) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23932) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23933) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23934) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23935) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");


      (_display displayCtrl 23950) ctrlSetText (mando_missile_path+"mandocamera_left.paa");
      (_display displayCtrl 23951) ctrlSetText (mando_missile_path+"mandocamera_right.paa");

      if (mando_tv_man) then
      {
         (_display displayCtrl 23921) ctrlSetText "Man F4";
      }
      else
      {
         if (!mando_tv_faf) then
         {
            (_display displayCtrl 23921) ctrlSetText "S.Au F4";
         }
         else
         {
            (_display displayCtrl 23921) ctrlSetText "Auto F4";
         };
      };

      if (mando_tv_remote) then
      {
         (_display displayCtrl 23922) ctrlSetText "Rem F3";
      }
      else
      {
         (_display displayCtrl 23922) ctrlSetText "Loc F3";
      };

      if (mando_tv_no_manauto) then
      {
         (_display displayCtrl 23921) ctrlEnable false;
      };

      if (mando_tv_no_remloc) then
      {
         (_display displayCtrl 23922) ctrlEnable false;
      };

      // up/down
      if (!(mando_tv_plane isKindOf "Air")) then
      {
         (_display displayCtrl 23960) ctrlEnable false;
         (_display displayCtrl 23961) ctrlEnable false;
      };


      (_display displayCtrl 23923) ctrlSetText mando_tv_info;


      if (mando_rec_flir) then
      {
         if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
         {
            call compile "true SetCamUseTi 0";
/*
            if (!isNil "mando_tv_camppe") then
            {
               switch (mando_tv_camppe) do
               {    
                  case 0:
                  {
                     call compile "true SetCamUseTi 2";
                  };

                  case 1:
                  {
                     call compile "true SetCamUseTi 4";
                  };

                  case 2:
                  {
                     call compile "true SetCamUseTi 0";
                  };
               };
            };
*/
         }
         else
         {
            ppEffectDestroy mando_ppccor;
            ppEffectDestroy mando_ppcinv;
            ppEffectDestroy mando_ppdyblur;

            setAperture 0.08;
            mando_ppccor = ppEffectCreate ["ColorCorrections", 1];
            mando_ppccor ppEffectEnable true;
            mando_ppccor ppEffectAdjust [1, 1, -0.002, [1, 1, 1, 0.1], [1, 1, 1, 0], [1, 1, 1, 0]];
            mando_ppccor ppEffectCommit 0;
  
            mando_ppcinv = ppEffectCreate ["colorInversion", 2];
            mando_ppcinv ppEffectEnable true;
            mando_ppcinv ppEffectAdjust [0.2,0.2,0.2];
            mando_ppcinv ppEffectCommit 0;

            mando_ppdyblur = ppEffectCreate ["dynamicBlur", 0];
            mando_ppdyblur ppEffectEnable true;  
            mando_ppdyblur ppEffectAdjust [0.4];
            mando_ppdyblur ppEffectCommit 0;
         };
      };


      if (mando_tv_missileidx >= 0) then
      {
         (_display displayCtrl 23918) ctrlSetText format["Fire: %1", mando_tv_plane getVariable format["mando_missilesleft%1", mando_tv_missileidx]];
         if ((isNull (gunner mando_tv_plane)) && 
             (count (configFile>>"cfgVehicles" >> (typeOf mando_tv_plane) >> "Turrets") > 0)) then
         {
               player action ["MANUALFIRE", vehicle player];
         };
      }
      else
      {
         if (mando_tv_weaponname != "") then
         {
            (_display displayCtrl 23918) ctrlSetText format["Fire: %1", (mando_tv_plane ammo mando_tv_weaponname) max (player ammo mando_tv_weaponname)];
            if ((isNull (gunner mando_tv_plane)) && 
                (count (configFile>>"cfgVehicles" >> (typeOf mando_tv_plane) >> "Turrets") > 0)) then
            {
                  player action ["MANUALFIRE", vehicle player];
            };
         };
      };
      mando_tv_cam = 1;

      _marker = createMarkerLocal ["mk_mma_tv", [getPos mando_tv_plane select 0, getPos mando_tv_plane select 1]];
      "mk_mma_tv" setMarkerTypeLocal "Arrow";
      "mk_mma_tv" setMarkerColorLocal "ColorGreen";
      "mk_mma_tv" setMarkerSizeLocal [0.5, 0.5];
      "mk_mma_tv" setMarkerTextLocal "";


      _marker = createMarkerLocal ["mk_mma_tv_dest", [getPos mando_tv_plane select 0, getPos mando_tv_plane select 1]];
      "mk_mma_tv_dest" setMarkerTypeLocal "End";
      "mk_mma_tv_dest" setMarkerColorLocal "ColorWhite";
      "mk_mma_tv_dest" setMarkerSizeLocal [0.5, 0.5];
      "mk_mma_tv_dest" setMarkerTextLocal "";



      if (mando_tv_wtype != "GUN") then
      {
         mando_maxthrustedrange_tv = 1/2*((mando_tv_missileparams select 6)^2)/(mando_tv_missileparams select 7);
         mando_maxthrustedrange_tv = mando_maxthrustedrange_tv + (mando_tv_missileparams select 5)*(mando_tv_missileparams select 6)/(mando_tv_missileparams select 7);
         mando_maxthrustedrange_tv = mando_maxthrustedrange_tv + (mando_tv_missileparams select 6)*((mando_tv_missileparams select 17) - ((mando_tv_missileparams select 6)/(mando_tv_missileparams select 7)));
      }
      else
      {
         mando_maxthrustedrange_tv = 3000;
      };


      _rects = [];
      _rects = _rects + [_display displayCtrl 23930];
      _rects = _rects + [_display displayCtrl 23931];
      _rects = _rects + [_display displayCtrl 23932];
      _rects = _rects + [_display displayCtrl 23933];
      _rects = _rects + [_display displayCtrl 23934];
      _rects = _rects + [_display displayCtrl 23935];

      _texts = [];
      _texts = _texts + [_display displayCtrl 23940];
      _texts = _texts + [_display displayCtrl 23941];
      _texts = _texts + [_display displayCtrl 23942];
      _texts = _texts + [_display displayCtrl 23943];
      _texts = _texts + [_display displayCtrl 23944];
      _texts = _texts + [_display displayCtrl 23945];

      for [{_i=0},{_i<6},{_i=_i+1}] do
      { 
         (_rects select _i) ctrlSetTextColor [1,0,0,0];
         (_texts select _i) ctrlSetTextColor [1,0,0,0];
         (_texts select _i) ctrlSetText "";
      };
      

      []spawn
      { 
         setMousePosition [0.5, 0.5];
      };

      []spawn
      {
         sleep 0.2;
         ((findDisplay 23900) displayCtrl 23924) ctrlShow false;
         ((findDisplay 23900) displayCtrl 23920) ctrlShow false;

         _i = 0;
         {
            ((findDisplay 23900) displayCtrl _x) ctrlSetPosition ((mando_tv_backcolor select 1) select _i);
            ((findDisplay 23900) displayCtrl _x) ctrlCommit 0;
            _i = _i + 1;
         } forEach [23925,23926,23922,23921,23919,23918,23927,23960,23961];
      };


      onMapSingleClick "true";

      []spawn
      {
         disableSerialization;

         private ["_cam", "_commdisplay", "_pos", "_posold", "_loglos", "_poslos", "_dirlos", "_i", "_dist", "_mando_cam_scale_old", "_mando_ingress_dir_old", "_angh", "_ratev", "_asl1", "_asl2", "_mando_tv_cam_old", "_warning"];

         showCinemaBorder false;
         _cam = "camera" camcreate [0, 0, 0];
         _cam cameraeffect ["internal", "back"];
         _cam camSetFov 1;
//         _cam camCommit 0;
         _loglos = "logic" createVehicleLocal [0,0,0];
         mando_tv_camera = _cam;

         _commdisplay = findDisplay 23900;
         _pos = [-1,-1];
         _posold = [-1,-1,-1];
         _mando_cam_scale_old = mando_cam_scale;
         _mando_ingress_dir_old = mando_ingress_dir;

// SPAWN CAMERA
         [_cam, _commdisplay]spawn
         {      
            disableSerialization;
            private["_cam", "_commdisplay", "_old"];
            _cam = _this select 0;
            _commdisplay = _this select 1;


            if (!isNil "mando_tv_camppe") then
            {
               switch (mando_tv_camppe) do
               {    
                  case 0:
                  {
                  };

                  case 1:
                  {
                     mando_ppccor = ppEffectCreate ["ColorCorrections", 1];
                     mando_ppccor ppEffectEnable true;
                     mando_ppccor ppEffectAdjust [0.20, 2.00, 0.00, [1.00, 1.00, 1.00, 0.00], [1.00, 1.00, 1.00, 0.00], [1.00, 1.00, 1.00, 1.00]];

                     mando_ppccor ppEffectCommit 0;

                     mando_ppfgrain = ppEffectCreate ["FilmGrain", 0];
                     mando_ppfgrain ppEffectEnable true;
                     mando_ppfgrain ppEffectAdjust [0.1, 0.1, 2.0, 0.1, 1.0, true];
                     mando_ppfgrain ppEffectCommit 0;
                  };
                  case 2:
                  {
                     mando_ppccor = ppEffectCreate ["ColorCorrections", 1];
                     mando_ppccor ppEffectEnable true;
                     mando_ppccor ppEffectAdjust [1.05, 0.95, 0.00, [0.80, 0.90, 1.00, -0.10], [1.00, 1.00, 1.00, 0.75], [1.00, 1.00, 1.00, 1.00]];
                     mando_ppccor ppEffectCommit 0;

                     mando_ppfgrain = ppEffectCreate ["FilmGrain", 0];
                     mando_ppfgrain ppEffectEnable true;
                     mando_ppfgrain ppEffectAdjust [0.1, 0.1, 2.0, 0.1, 1.0, true];
                     mando_ppfgrain ppEffectCommit 0;
                  };
               };
            };

//            _cam attachTo [mando_tv_plane, mando_tv_cam_pos]; 


// mando_cam_angles = [0,0];
            _old = objNull;
            mando_last_missile = objNull;

            while {!isNull _commdisplay} do
            {

                           mando_cam_angles set [0, (mando_cam_angles select 0)+(mando_tvcam_angles select 0)];
   
                           if (abs((mando_cam_angles select 1)+(mando_tvcam_angles select 1)) < 89) then
                           {
                              mando_cam_angles set [1, (mando_cam_angles select 1)+(mando_tvcam_angles select 1)];
                           };


                           if ((mando_cam_angles select 0) > 360) then
                           {
                              mando_cam_angles set [0, (mando_cam_angles select 0) - 360];
                           }
                           else
                           {
                              if ((mando_cam_angles select 0) < 0) then
                              {
                                 mando_cam_angles set [0, 360 + (mando_cam_angles select 0)];
                              }
                           };


               if (mando_tv_cam == 1) then
               {
                  if (!isNull mando_last_missile) then
                  {
                     if (_old != mando_last_missile) then
                     {
         _cam cameraeffect ["terminate", "back"];
         camDestroy _cam;

         _cam = "camera" camcreate [0, 0, 0];
         _cam cameraeffect ["internal", "back"];
         _cam camSetFov 1;
         mando_tv_camera = _cam;

//                        _cam attachTo [mando_last_missile, [0,15,0]]; 
                        _old = mando_last_missile;
                     };
                     _cam camSetPos (mando_last_missile modelToWorld [0,15,0]);
                     _cam camSetTarget (mando_last_missile modelToWorld [0,50,0]);
                     _cam camSetFov mando_tvcam_scale;
                     _cam camCommit 0;   
                  }
                  else
                  {
                     if (!isNil "mando_tv_cam_pos" && !isNil "mando_tv_cam_target") then
                     {
                        if (_old != mando_tv_plane) then
                        {
         _cam cameraeffect ["terminate", "back"];
         camDestroy _cam;

         _cam = "camera" camcreate [0, 0, 0];
         _cam cameraeffect ["internal", "back"];
         _cam camSetFov 1;
         mando_tv_camera = _cam;

                           _cam attachTo [mando_tv_plane, mando_tv_cam_pos];
                           _old = mando_tv_plane;
                        };

//                        _cam camSetPos (mando_tv_plane modelToWorld mando_tv_cam_pos);
                        if (!mando_take_pic_on) then
                        {
//                           _pos = [(getPos mando_tv_plane select 0)+sin(mando_cam_angles select 0)*mando_tv_sensor_rng_l*cos(mando_cam_angles select 1), (getPos mando_tv_plane select 1)+cos(mando_cam_angles select 0)*mando_tv_sensor_rng_l*cos(mando_cam_angles select 1), (getPos mando_tv_plane select 2)+sin(mando_cam_angles select 1)*mando_tv_sensor_rng_l];


                           _pos = [(getPos mando_tv_plane select 0)+sin(mando_cam_angles select 0)*200000*cos(mando_cam_angles select 1), (getPos mando_tv_plane select 1)+cos(mando_cam_angles select 0)*200000*cos(mando_cam_angles select 1), (getPos mando_tv_plane select 2)+sin(mando_cam_angles select 1)*200000];

                           _cam camSetTarget _pos;
                           _cam camSetFov mando_tvcam_scale;
                           _cam camCommit 0.0;       

                        }
                        else
                        {
                           Sleep 0.05;
                           _cam camSetTarget mando_tv_cam_target;
                           _cam camSetFov mando_tvcam_scale;
                           _cam camCommit 0.0;  
                        };
                     };
                  };                
                  sleep 0.005;
               }
               else
               {
                  Sleep 0.5;
               };
               "mk_mma_tv_dest" setMarkerPosLocal mando_tv_dest;
            };
            if (!isNil "mando_last_onmapsclick") then
            {
               onMapSingleClick mando_last_onmapsclick;
            }
            else
            {
               onMapSingleClick "";
            };
         };


// SPAWN INIT
         [_cam, _commdisplay]spawn
         {
            disableSerialization;

            private ["_cam", "_commdisplay","_mando_tv_cam_old", "_angles", "_dirlos", "_ratev", "_i", "_loglos", "_pos", "_poslos", "_dist", "_screen", "_hscreen", "_vscreen", "_mark", "_rect", "_rombe", "_textdata", "_texthelp", "_zoom", "_endcolor", "_rangecolor","_mando_tv_cam_target", "_fire_button", "_flir_button", "_mode_button", "_targets_button", "_line", "_posm", "_poss", "_post", "_trigger", "_rects", "_texts", "_vdir", "_logasl", "_list", "_dirsc", "_range_to_target","_color_l", "_color_h", "_elapsed","_elapsedt","_deltaz", "_target", "_air_targets","_radar_targets", "_remote_targets", "_min_targets_alt", "_max_targets_alt","_vdirr", "_sensor_x", "_sensor_y", "_sine", "_rombe_ok", "_firing_dir", "_tgt_arrow_left", "_tgt_arrow_right", "_logcam"];


            _sensor_x = mando_tv_sensor_rng_w/2;
            _sensor_y = mando_tv_sensor_rng_l/2;

            _cam = _this select 0;
            _commdisplay = _this select 1;
            _mando_tv_cam_old = 0;
            _mando_tv_plane_old = objNull;
            _loglos  = "logic" createVehicleLocal [0,0,0];
            _logasl  = "logic" createVehicleLocal [0,0,0];
            _logcam  = "logic" createVehicleLocal [0,0,0];

            _mark = _commdisplay displayCtrl 23904;
            _rect = _commdisplay displayCtrl 23905;
            _rombe = _commdisplay displayCtrl 23929;
            _textdata = _commdisplay displayCtrl 23916;
            _fire_button = _commdisplay displayCtrl 23918;
            _flir_button = _commdisplay displayCtrl 23919;
            _mode_button = _commdisplay displayCtrl 23921;
            _targets_button = _commdisplay displayCtrl 23922;


            _fire_button ctrlShow false; 
            _flir_button ctrlShow false;
            _mode_button ctrlShow false;
            _targets_button ctrlShow false;


            _line = _commdisplay displayCtrl 23917;
            _rects = [];
            _rects = _rects + [_commdisplay displayCtrl 23930];
            _rects = _rects + [_commdisplay displayCtrl 23931];
            _rects = _rects + [_commdisplay displayCtrl 23932];
            _rects = _rects + [_commdisplay displayCtrl 23933];
            _rects = _rects + [_commdisplay displayCtrl 23934];
            _rects = _rects + [_commdisplay displayCtrl 23935];

            _texts = [];
            _texts = _texts + [_commdisplay displayCtrl 23940];
            _texts = _texts + [_commdisplay displayCtrl 23941];
            _texts = _texts + [_commdisplay displayCtrl 23942];
            _texts = _texts + [_commdisplay displayCtrl 23943];
            _texts = _texts + [_commdisplay displayCtrl 23944];
            _texts = _texts + [_commdisplay displayCtrl 23945];
            _texthelp = _commdisplay displayCtrl 23902;


            _tgt_arrow_left = _commdisplay displayCtrl 23950;
            _tgt_arrow_right = _commdisplay displayCtrl 23951;


            if (mando_tv_camppe == 1) then
            {
               _tgt_arrow_left ctrlSetTextColor [1,1,1,1];
               _tgt_arrow_right ctrlSetTextColor [1,1,1,1];
            };

            if (!isNull mando_tv_laserlogic) then 
            {
               _mando_tv_cam_target = getPos mando_tv_laserlogic;
               mando_tv_cam_target = _mando_tv_cam_target;
            };

            _dirsc = [];
            {
               _dirsc = _dirsc + [_commdisplay displayCtrl _x];

               if (mando_tv_camppe == 1) then
               {
                  (_commdisplay displayCtrl _x) ctrlSetTextColor [1,1,1,1];
               };
            } forEach [23912,23913,23914,23915];

            _warning = "none";
            _trigger = objNull;            
            mando_tvcam_angles = [0,0];
            _angles = [mando_tv_init_ang + (getDir mando_tv_plane),0];
            mando_cam_angles = [mando_tv_init_ang + (getDir mando_tv_plane),0];

            _elapsed = (dayTime * 3600);
            _elapsedt = (dayTime * 3600);
            _list = [];

            _deltaz = ((mando_tv_plane modelToWorld mando_tv_cam_pos) select 2) - (getPos mando_tv_plane select 2);
            if ("Air" in mando_tv_target_types) then
            {
               _air_targets = true;
               _min_targets_alt = 10;
               _max_targets_alt = 40000;
            }
            else
            {
               _air_targets = false;
               _min_targets_alt = -3;
               _max_targets_alt = 4;
            };

            _radar_targets = false;
            if ("RADAR" in mando_tv_target_types) then
            {
               _radar_targets = true;
            };

            _remote_targets = false;
            if ("REMOTE" in mando_tv_target_types) then
            {
               _remote_targets = true;
            };


            while {!isNull _commdisplay} do
            {
               if (mando_tv_cam == 1) then
               {
                  if ((alive mando_tv_plane) || (alive mando_last_missile)) then
                  {
                     if (!isNull mando_tv_laserlogic) then
                     {
                        if (!isNull mando_tv_laserlogic_target) then
                        {
                           mando_tv_laserlogic setPos getPos mando_tv_laserlogic_target;
                        };
                     }; 


                     if (!isNull mando_last_missile) then
                     {
                        (_commdisplay displayCtrl 23903) ctrlSetTextColor [0.5,0.5,0.5,1];

                        _texthelp ctrlSetStructuredText parseText "Camera steerable area (move the mouse in the area to guide the missile)";

                        "mk_mma_tv" setMarkerPosLocal getPos mando_last_missile;
                        "mk_mma_tv" setMarkerDirLocal getDir mando_last_missile;


                        if (isNull _trigger) then
                        {
                           _trigger = createTrigger ["EmptyDetector", [(getPos mando_last_missile select 0)+900*sin(getDir mando_last_missile),(getPos mando_last_missile select 1)+900*cos(getDir mando_last_missile), 0]];
                           _trigger setTriggerActivation ["ANY", "PRESENT", false];
                           _trigger setTriggerArea [750, 750, getDir mando_last_missile, true];
                           _trigger setTriggerType "NONE";
                           _trigger setTriggerStatements ["this", "", ""];
                           _trigger setTriggerTimeout [0, 0, 0, false ];
                        }
                        else
                        {
                           _trigger setPos [(getPos mando_last_missile select 0)+900*sin(getDir mando_last_missile),(getPos mando_last_missile select 1)+900*cos(getDir mando_last_missile), 0];
                           _trigger setTriggerArea [750, 750, getDir mando_last_missile, true];
                        };

                        if (!mando_tv_remote) then
                        {
                           if (mando_tv_camppe == 1) then
                           {
                              _color_l = [0.75, 0.75, 0.75, 1];
                              _color_h = [1, 1, 1, 1];
                           }
                           else
                           {
                              _color_l = [0.25, 0.5, 0.25, 1];
                              _color_h = [0.5, 1, 0.5, 1];  
                           };
                        }
                        else
                        {
                           if ((dayTime * 3600) > (_elapsed + 2)) then
                           {
                              _elapsed = (dayTime * 3600);
                           };
                           _color_l = [0.75, 0.75, 0.75, 1];
                           _color_h = [1, 1, 1, 1];
                        };

                        _zoom = mando_tvcam_scale;

					   _list = [];
					   _list = _list + mando_tv_targets;
						
                        if (count _list > 0) then
                        {
                           for [{_i=0},{_i<6},{_i=_i+1}] do
                           { 
                              if (_i < count _list) then
                              {
                                 _screen = [mando_last_missile, _list select _i, []] call MandoWorldToScreen2tv;

                                 _hscreen = 0.5 + (_screen select 0)/_zoom - 0.04/2;
                                 _vscreen = 0.5 - (_screen select 1)/_zoom - 0.05/2;

                                 _hscreen = _hscreen min (0.7-0.04);
                                 _hscreen = _hscreen max (0.3);

                                 _vscreen = _vscreen min (0.7-0.05);
                                 _vscreen = _vscreen max (0.3);

                                 _angh = _screen select 2;
                                 _angv = _screen select 3;
    
                                 if (mando_tv_sensor_rects) then
                                 {
                                    if ((abs(_angh) < 5) && (abs(_angv) < 5)) then
                                    {
                                       (_rects select _i) ctrlSetTextColor _color_h;
                                       (_texts select _i) ctrlSetTextColor _color_h;
                                       (_texts select _i) ctrlSetText typeOf (_list select _i);
                                    }
                                    else
                                    {
                                       (_rects select _i) ctrlSetTextColor _color_l;
                                       (_texts select _i) ctrlSetTextColor _color_l;
                                       (_texts select _i) ctrlSetText "";
                                    };
                                 };

                                 (_rects select _i) ctrlSetPosition [_hscreen, _vscreen];
                                 (_rects select _i) ctrlCommit 0;
                                 (_texts select _i) ctrlSetPosition [_hscreen, _vscreen-0.02];
                                 (_texts select _i) ctrlCommit 0;
                              }
                              else
                              {
                                 (_rects select _i) ctrlSetTextColor [0, 0, 0, 0];
                                 (_texts select _i) ctrlSetTextColor [0, 0, 0, 0];
                              };
                           };
                        }
                        else
                        {
                           {
                              _x ctrlSetTextColor [0, 0, 0, 0];
                           } forEach _rects;

                           {
                              _x ctrlSetTextColor [0, 0, 0, 0];
                           } forEach _texts;
                        };


                        _fire_button ctrlShow false; 
                        _mode_button ctrlShow false;
                        _targets_button ctrlShow false;

                        _flir_button ctrlShow true;

                        _line ctrlSetTextColor [0, 1, 0, 0];

                        _screen = [mando_last_missile, mando_last_target, []] call MandoWorldToScreen2tv;

                        _hscreen = 0.5 + (_screen select 0)/_zoom - 0.04/2;
                        _vscreen = 0.5 - (_screen select 1)/_zoom - 0.05/2;

                        _hscreen = _hscreen min (0.7-0.04);
                        _hscreen = _hscreen max (0.3);

                        _vscreen = _vscreen min (0.7-0.05);
                        _vscreen = _vscreen max (0.3);

                        _angh = _screen select 2;
                        _angv = _screen select 3;

                        if ((abs(_angh) < 10) && (abs(_angv) < 10)) then
                        {
                           if (mando_tv_camppe == 1) then
                           {
                              _mark ctrlSetTextColor [1, 1, 1, 1];
                           }
                           else
                           {
                              _mark ctrlSetTextColor [0.5, 1, 0.5, 1];
                           };
                        }
                        else
                        {
                           if (mando_tv_camppe == 1) then
                           {
                              _mark ctrlSetTextColor [0.5, 0.5, 0.5, 1];
                           }
                           else
                           {
                              _mark ctrlSetTextColor [0.25, 0.5, 0.25, 0.5];
                           };
                        };
 
                        _dist = floor (mando_last_missile distance mando_last_target);
                        if (_dist < 1500) then
                        {
                           if (mando_tv_camppe == 1) then
                           {
                              _rect ctrlSetTextColor [0.5, 0.5, 0.5, 1];
                           }
                           else
                           {
                              _rect ctrlSetTextColor [0, 0.5, 0, 1];
                           };
                           _rect ctrlSetPosition [_hscreen, _vscreen];
                           _rect ctrlCommit 0;
                           _rangecolor = format["<t color='#ff0000'> %1</t>", _dist];
                        }
                        else
                        {
                           _rect ctrlSetTextColor [0, 0, 0, 0];
                           _rangecolor = format["<t color='#ffffff'> %1</t>", _dist];
                        };

                        if (mando_lockedon == mando_last_missile) then
                        {
                           if (_warning == "none") then
                           {
                              []spawn
                              {
                                 playSound "mando_lockedon";
                                 Sleep 2;
                                 mando_lockedon = objNull;
                              }; 
                           };
                           _warning = "<t color='#ff0000'> ANTIMISSILE RADAR LOCK</t>";
                        }
                        else
                        {
                           _warning = "none";
                        };

                        if (mando_missile_endurance < 10) then
                        {
                           _endcolor = format["<t color='#ff0000'> %1</t>", mando_missile_endurance];
                        }
                        else
                        {
                           _endcolor = format["<t color='#ffffff'> %1</t>", mando_missile_endurance];
                        };

                        _mark ctrlSetPosition [_hscreen, _vscreen];
                        _mark ctrlCommit 0;

                        _angh = getDir mando_last_missile;  
                        _i = 0;
                        {
                           _x ctrlSetPosition [(0.5+sin(_i-_angh)*0.1*5/6)-0.01, (0.5-cos(_i-_angh)*0.1)-0.01, 0.02, 0.02];
                           _x ctrlCommit 0;
                           _i = _i + 90;
                        } forEach _dirsc;

                        _rombe ctrlSetTextColor [0,0,0,0];

                        if (mando_tv_map_on) then
                        {
                           (_commdisplay displayCtrl 23920) ctrlMapAnimAdd [0, 1, getPos mando_last_missile];
                           ctrlMapAnimCommit (_commdisplay displayCtrl 23920);
                        };

//                        _textdata ctrlSetStructuredText parseText format["Missile range to target: %1 m<br />Missile endurance: %2 seconds<br />Missile altitude ASL: %3 m<br />Missile guidance:<t color='#ff0000'> Manual</t><br />Warning: %4<br />Zoom: %5", _rangecolor, _endcolor, floor(getPosASL mando_last_missile select 2),_warning, floor((1 - mando_tvcam_scale)*100/0.99)];
                        _textdata ctrlSetStructuredText parseText format["Missile range to target: %1 m<br />Missile endurance: %2 seconds<br />Missile altitude ASL: %3 m<br />Missile guidance:<t color='#ff0000'> Manual</t><br />Warning: %4<br />Zoom: %5x", _rangecolor, _endcolor, floor(getPosASL mando_last_missile select 2),_warning, floor(1/(atan(mando_tvcam_scale)/45))];
												

                        mando_last_missile_target setPos (mando_last_missile modelToWorld [sin((mando_tvcam_angles select 0)*3)*100, cos ((mando_tvcam_angles select 0)*3)*100, sin((mando_tvcam_angles select 1)*3)*100]);

//                        _cam camSetPos (mando_last_missile modelToWorld [0,7,0]);
//                        _cam camSetTarget (mando_last_missile modelToWorld [0,50,0]);
                     }
                     else
                     {
// *****************************************************************************
// PLANE

                        if (alive mando_tv_plane) then
                        { 
/*
                           _angles set [0, (_angles select 0)+(mando_tvcam_angles select 0)];
   
                           if (abs((_angles select 1)+(mando_tvcam_angles select 1)) < 89) then
                           {
                              _angles set [1, (_angles select 1)+(mando_tvcam_angles select 1)];
                           };


                           if ((_angles select 0) > 360) then
                           {
                              _angles set [0, (_angles select 0) - 360];
                           }
                           else
                           {
                              if ((_angles select 0) < 0) then
                              {
                                 _angles set [0, 360 + (_angles select 0)];
                              }
                           };
                           mando_cam_angles = _angles;
*/
                           _angles = mando_cam_angles;
                           "mk_mma_tv" setMarkerPosLocal getPos mando_tv_plane;
                           "mk_mma_tv" setMarkerDirLocal getDir mando_tv_plane;

                           _texthelp ctrlSetStructuredText parseText "Camera steerable area (move the mouse in the area to move the camera)<br />Left click to lock on, SHIFT + left click to change destination, right click to fire";


                           if (mando_tv_map_on) then
                           {
                              (_commdisplay displayCtrl 23920) ctrlMapAnimAdd [0, 1, getPos mando_tv_plane];
                              ctrlMapAnimCommit (_commdisplay displayCtrl 23920);
                           };

                           _mark ctrlSetTextColor [0.75, 0.75, 0.75, 1];
                           _rect ctrlSetTextColor [0, 0, 0, 0];
                           _fire_button ctrlShow true;
                           _flir_button ctrlShow true;
                           _mode_button ctrlShow true;
                           _targets_button ctrlShow true;


                           if (mando_lockedon == mando_tv_plane) then
                           {
                              if (_warning == "none") then
                              {
                                 []spawn
                                 {
                                    playSound "mando_lockedon";
                                    Sleep 2;
                                    mando_lockedon = objNull;
                                 }; 
                              };
                              _warning = "<t color='#ff0000'> RADAR LOCK</t>";
                           }
                           else
                           {
                              _warning = "none";
                           };         
  
// CAM MOD                           _cam camSetPos (mando_tv_plane modelToWorld mando_tv_cam_pos);


                           if (!mando_take_pic_on) then
                           {

                              _mando_tv_cam_target = [(getPos mando_tv_plane select 0)+sin(_angles select 0)*mando_tv_sensor_rng_l*cos(_angles select 1), (getPos mando_tv_plane select 1)+cos(_angles select 0)*mando_tv_sensor_rng_l*cos(_angles select 1), (getPos mando_tv_plane select 2)+sin(_angles select 1)*mando_tv_sensor_rng_l];

                              (_commdisplay displayCtrl 23903) ctrlSetTextColor [0.5,0.5,0.5,1];
                           }
                           else
                           { 
                              if (mando_tv_camppe == 1) then
                              {
                                 (_commdisplay displayCtrl 23903) ctrlSetTextColor [1,1,1,1];
                              }
                              else
                              {
                                 (_commdisplay displayCtrl 23903) ctrlSetTextColor [1,0,0,1];
                              };
                           };


                           if (!isNull mando_tv_laserlogic_target) then
                           {

                              if ((dayTime * 3600) > (_elapsedt + 2)) then
                              {

                                 _elapsedt = (dayTime * 3600);

                                 if ((getPos mando_tv_laserlogic_target select 2) > 10) then
                                 {
                                    if (!([_loglos, mando_tv_plane, mando_tv_laserlogic_target, 50, _deltaz] call mando_check_los)) then
                                    {
                                       mando_take_pic = true;
                                       mando_tv_laserlogic_target = objNull;
                                    };
                                 }
                                 else
                                 {
                                    if (!mando_tv_remote) then
                                    {
                                       if (!([_loglos, mando_tv_plane, mando_tv_laserlogic_target, 20, _deltaz] call mando_check_los)) then
                                       {
                                          mando_take_pic = true;
                                          mando_tv_laserlogic_target = objNull;
                                       };
                                    };
                                 };
                              };
                           };


                           if (!isNull mando_tv_laserlogic_target) then
                           {
// CAM MOD                              _cam camSetTarget mando_tv_laserlogic_target;
                              mando_tv_cam_target = mando_tv_laserlogic_target;

                              _posm = mando_tv_plane worldToModel (getPos mando_tv_laserlogic_target);
                              _post = (getPos mando_tv_laserlogic_target);
                           }
                           else
                           {
// CAM MOD                              _cam camSetTarget _mando_tv_cam_target;
                              mando_tv_cam_target = _mando_tv_cam_target;

                              _posm = mando_tv_plane worldToModel _mando_tv_cam_target;
                              _post = _mando_tv_cam_target;
                           };
                           _dist = mando_tv_plane distance _post;
 
                           if (mando_take_pic_on) then
                           {
                              if (mando_maxthrustedrange_tv > _dist) then 
                              {
                                 _range_to_target = format["<br />Range to target:<t color='#00ff00'> %1 Km</t>", floor (_dist/100)/10]; 
                              }
                              else
                              {
                                 _range_to_target = format["<br />Range to target: %1 Km", floor (_dist/100)/10]; 
                              };

                              if (!isNull mando_tv_laserlogic_target) then
                              {
                                 _range_to_target = _range_to_target + format["<br />Target: %1", typeOf mando_tv_laserlogic_target]; 
                              };
                           }
                           else
                           {
                              _range_to_target = "";
                           };
                           
                           _range_to_target = _range_to_target + format["<br />Weapon range: %1 Km", floor (mando_maxthrustedrange_tv/100)/10];

                           _textdata ctrlSetStructuredText parseText format["Warning: %1<br />Zoom: %2x<br />Range to destination: %3 Km%4", _warning, floor(1/(atan(mando_tvcam_scale)/45)), floor ((mando_tv_plane distance mando_tv_dest)/100)/10, _range_to_target];


                           if (mando_tv_camppe == 1) then
                           {
                              _line ctrlSetTextColor [1, 1, 1, 1];
                           }
                           else
                           {
                              _line ctrlSetTextColor [0.5, 1, 0.5, 1]; 
                           };

                           _angv = -((_posm select 0) atan2 (_posm select 1));
                           _poss = [0.5+sin(_angv)*0.08*4/5, 0.5-cos(_angv)*0.08];
                           _line ctrlSetPosition [0.5, 0.5, (_poss select 0)-0.5, (_poss select 1)-0.5];

                           _line ctrlCommit 0;


                           _logasl setPos _post;
                           _vdir = [((_post select 0)-(getPos mando_tv_plane select 0))/_dist,((_post select 1)-(getPos mando_tv_plane select 1))/_dist,((getPosASL _logasl select 2)-(getPosASL mando_tv_plane select 2))/_dist];




                           _vdirr = mando_tv_plane worldToModel _post;
                           _vdirr = [(_vdirr select 0) / _dist,(_vdirr select 1) / _dist,(_vdirr select 2) / _dist];


                           _angh = (_vdirr select 0) atan2 (_vdirr select 1);
                           _angv = asin (_vdirr select 2);

                           _difang = (_angh - mando_tv_init_ang) mod 360;
                           if (_difang < 0) then {_difang = 360 + _difang;};
                           if (_difang > 180) then {_difang = _difang - 360;};
                           _angh = _difang;

                           if ((abs(_angh) > mando_tv_max_ang) || (abs(_angv) > 90)) then
                           {
                              if (abs(_angh) > mando_tv_max_ang) then
                              {
                                 if (_angh < 0) then
                                 {
                                    _angh = -mando_tv_max_ang + mando_tv_init_ang;
                                 }
                                 else
                                 {
                                    _angh = mando_tv_max_ang + mando_tv_init_ang;
                                 };
                              };

                              if (abs(_angv) > 90) then
                              {
                                 if (_angv < 0) then
                                 {
                                    _angv = -90;
                                 }
                                 else
                                 {
                                    _angv = 90;
                                 };
                              };


                              _vdirr = [sin(_angh)*cos(_angv), cos(_angh)*cos(_angv), sin(_angv)];
                              _pos = getPos mando_tv_plane;
                              _post = mando_tv_plane modelToWorld [(_vdirr select 0)*200,(_vdirr select 1)*200,(_vdirr select 2)*200];

                              _dirlos = ((_post select 0)-(_pos select 0)) atan2 ((_post select 1)-(_pos select 1));
                              _loglos setPos _post; 

                              _angles set [0, _dirlos];
                              _sine = ((getPosASL _loglos select 2)-(getPosASL mando_tv_plane select 2))/(mando_tv_plane distance _post);
                              if (abs (_sine) > 1) then
                              {
                                 if (_sine > 0) then 
                                 {
                                    _sine = sin(90);
                                 }
                                 else
                                 {
                                    _sine = sin(-90);
                                 };
                              };
                              _angles set [1, asin(_sine)];

                              mando_cam_angles = _angles;

                              mando_take_pic_on = false;
                              if (!isNull  mando_tv_laserlogic) then 
                              {
                                 deleteVehicle mando_tv_laserlogic;
                              };
                              if (!isNull  mando_tv_laserlogic_target) then 
                              {
                                 mando_tv_laserlogic_target = objNull;
                              };
                           };




//                           _logasl setPos waypointPosition [group driver mando_tv_plane, 1];
                           _logasl setPos mando_tv_dest;

                           _screen = [mando_tv_plane, _logasl, _vdir] call MandoWorldToScreen2tv;
                           _zoom = mando_tvcam_scale;
                           _hscreen = 0.5 + (_screen select 0)/(_zoom*1.5) - 0.04/2;
                           _vscreen = 0.5 - (_screen select 1)/(_zoom*1.5) - 0.05/2;
                           _hscreen = _hscreen min (0.7-0.04);
                           _hscreen = _hscreen max (0.3);
   
                           _vscreen = _vscreen min (0.7-0.05);
                           _vscreen = _vscreen max (0.3);

                           _angh = _screen select 2;
                           _angv = _screen select 3;
                           _mark ctrlSetPosition [_hscreen, _vscreen];
                           _mark ctrlCommit 0;

                           _angh = (_vdir select 0) atan2 (_vdir select 1);
                           _angv = (_posm select 0) atan2 (_posm select 1);
                           _i = 0;
                           {
                              _x ctrlSetPosition [(0.5+sin(_i-_angh)*0.1*5/6)-0.01, (0.5-cos(_i-_angh)*0.1)-0.01, 0.02, 0.02];
                              _x ctrlCommit 0;
                              _i = _i + 90;
                           } forEach _dirsc;



                           if (isNull _trigger) then
                           {
                              _trigger = createTrigger ["EmptyDetector", [(getPos mando_tv_plane select 0)+(_sensor_y+25)*sin(getDir mando_tv_plane),(getPos mando_tv_plane select 1)+(_sensor_y+25)*cos(getDir mando_tv_plane), 0]];
                              _trigger setTriggerActivation ["ANY", "PRESENT", false];
                              _trigger setTriggerArea [_sensor_x, _sensor_y, getDir mando_tv_plane, true];
                              _trigger setTriggerType "NONE";
                              _trigger setTriggerStatements ["this", "", ""];
                              _trigger setTriggerTimeout [0, 0, 0, false ];
							  
							  mando_tv_targets = [];
															 
							  [_commdisplay, _trigger, _radar_targets, _min_targets_alt, _max_targets_alt, _loglos, _deltaz] spawn 
							  {
							     disableSerialization;
									  
								 private ["_commdisplay", "_trigger", "_radar_targets", "_min_targets_alt", "_max_targets_alt", "_loglos", "_deltaz", "_list", "_elapsed", "_org"];
								 _commdisplay = _this select 0;
								 _trigger = _this select 1;
								 _radar_targets = _this select 2;
								 _min_targets_alt = _this select 3;
								 _max_targets_alt = _this select 4;
								 _loglos = _this select 5;
								 _deltaz = _this select 6;
								 _elapsed = (dayTime * 3600);
								 
							     Sleep 1;
							     while {!isNull _commdisplay} do
								 {									
									   if (!mando_tv_remote) then
									   {
										  if ((dayTime * 3600) > (_elapsed + 2)) then
										  {
											 _elapsed = (dayTime * 3600);

											 _list = [];
											 if (!isNull mando_last_missile) then
											 {
											    _org = mando_last_missile;
											 }
											 else
											 {
											    _org = mando_tv_plane;
											 };
											 
											 if (!_radar_targets) then
											 {
												{
												   if ((count _list) < 6) then
												   {
													  if (fuel _x < 1) then
													  {
														 if (isEngineOn _x) then
														 {
															if (side _x != side mando_tv_plane) then 
															{
															   if (((getPos _x select 2) > _min_targets_alt) &&
																   ((getPos _x select 2) < _max_targets_alt)) then
															   {
																  if ([_loglos, _org, _x, 20, _deltaz] call mando_check_los) then
																  {
																	 _list = _list + [_x];
																  };
															   };
															};
														 };
													  };
												   };
												} forEach list _trigger;
											 }
											 else
											 {
												{
												   if ((getPos _x select 2) < 10) then 
												   {
													  _list = _list + [_x];
												   };
												} forEach mando_radars;
											 };
											 mando_tv_targets = [];
											 mando_tv_targets = mando_tv_targets + _list;

										  };
									   }
									   else
									   {
										  if ((dayTime * 3600) > (_elapsed + 2)) then
										  {
											 _elapsed = (dayTime * 3600);
											 _list = [];
											 switch (side mando_tv_plane) do
											 {    
												case west:
												{
												   {
													  _list = _list + [_x];
												   } forEach mando_remote_targets_w;
												};

												case east:
												{
			  
												   {
													  _list = _list + [_x];
												   } forEach  mando_remote_targets_e;
												};

												case resistance:
												{
												   {
													  _list = _list + [_x];
												   } forEach  mando_remote_targets_r;
												};
											 };
											 mando_tv_targets = [];
											 mando_tv_targets = mando_tv_targets + _list;											 
										  };
									   };
									   
									   // List ready

									Sleep 1;
								};
							  
							  };
                           }
                           else
                           {
                              _trigger setPos [(getPos mando_tv_plane select 0)+(_sensor_y+25)*sin(_angh),(getPos mando_tv_plane select 1)+(_sensor_y+25)*cos(_angh), 0];
                              _trigger setTriggerArea [_sensor_x, _sensor_y, _angh, true];
                           };


                           if (!mando_tv_remote) then
                           {
                              if ((dayTime * 3600) > (_elapsed + 2)) then
                              {
                                 _elapsed = (dayTime * 3600);

                                 if (!_radar_targets) then
                                 {
                                    if (mando_tv_camppe == 1) then
                                    {
                                       _color_l = [0.75, 0.75, 0.75, 1];
                                       _color_h = [1, 1, 1, 1];
                                    }
                                    else
                                    {
                                       _color_l = [0.25, 0.5, 0.25, 1];
                                       _color_h = [0.5, 1, 0.5, 1];  
                                    };
                                 }
                                 else
                                 {
                                    if (mando_tv_camppe == 1) then
                                    {
                                       _color_l = [0.75, 0.75, 0.75, 1];
                                       _color_h = [1, 1, 1, 1];
                                    }
                                    else
                                    {
                                       _color_l = [0.5, 0.5, 0.4, 0.7];
                                       _color_h = [1, 1, 0.8, 0.9];
                                    };
                                 };
                              };
                           }
                           else
                           {
                              if ((dayTime * 3600) > (_elapsed + 2)) then
                              {
                                 _elapsed = (dayTime * 3600);
                              };
                              _color_l = [0.75, 0.75, 0.75, 1];
                              _color_h = [1, 1, 1, 1];

                           };

                           _target = objNull;
                           _rombe_ok = false;
						   _list = [];
						   _list = _list + mando_tv_targets;
						   
                           if (count _list > 0) then
                           {
                              for [{_i=0},{_i<6},{_i=_i+1}] do
                              { 
                                 if (_i < count _list) then
                                 {
                                    if (!isNull (_list select _i)) then
                                    {
                                       _screen = worldToScreen getPos (_list select _i); 
                                       if (count _screen != 2) then
                                       {                              
                                          _screen = [-1,-1];
                                       };

                                       _hscreen = ((_screen select 0) - 0.04/2) min (0.7-0.04);
                                       _hscreen = _hscreen max (0.3);
   
                                       _vscreen = ((_screen select 1) - 0.05/2) min (0.7-0.05);
                                       _vscreen = _vscreen max (0.3);

                                       _angh = (0.5-(_screen select 0))/0.5*45;
                                       _angv = (0.5-(_screen select 1))/0.5*35;


                                       if ((abs(_angh) < 5) && (abs(_angv) < 5)) then
                                       {
                                          if (mando_tv_sensor_rects || mando_tv_remote) then
                                          {
                                             (_rects select _i) ctrlSetTextColor _color_h;
                                             (_texts select _i) ctrlSetTextColor _color_h;
                                             (_texts select _i) ctrlSetText typeOf (_list select _i);
                                          }
                                          else
                                          { 
                                             (_rects select _i) ctrlSetTextColor [0,0,0,0];
                                             (_texts select _i) ctrlSetTextColor [0,0,0,0];
                                             (_texts select _i) ctrlSetText "";
                                          };


                                          if ((abs(_angh) < (mando_tv_ang_to_lock*mando_tvcam_scale max 1)) && (abs(_angv) < (mando_tv_ang_to_lock*mando_tvcam_scale max 1))) then
                                          {                             
                                             _target = _list select _i;
                                          };
                                       }
                                       else
                                       {
                                          if (mando_tv_sensor_rects || mando_tv_remote) then
                                          {
                                             (_rects select _i) ctrlSetTextColor _color_l;
                                             (_texts select _i) ctrlSetTextColor _color_l;
                                             (_texts select _i) ctrlSetText "";
                                          }
                                          else
                                          { 
                                             (_rects select _i) ctrlSetTextColor [0,0,0,0];
                                             (_texts select _i) ctrlSetTextColor [0,0,0,0];
                                             (_texts select _i) ctrlSetText "";
                                          };                                          
                                       };

                                       if ((_list select _i) == mando_tv_laserlogic_target) then
                                       {
                                          _rombe ctrlSetTextColor _color_h;
                                          _rombe ctrlSetPosition [_hscreen+random(0.005)-0.00025, _vscreen+random(0.005)-0.00025];
                                          _rombe ctrlCommit 0;
                                          _rombe_ok = true;

                                          if (!mando_irtone_on && (mando_tv_wtype != "GUN")) then
                                          {
                                             mando_irtone_on = true;
                                             [] spawn
                                             {
                                                if ((getPos mando_tv_laserlogic_target select 2) < 10) then
                                                {
                                                   vehicle player say "mando_irtone";
                                                   Sleep 1.3;
                                                }
                                                else
                                                {
                                                   vehicle player say "mando_irgrowl";
                                                   Sleep 0.5;
                                                };
                                                
                                                mando_irtone_on = false;
                                             };
                                          };
                                       };

                                       (_rects select _i) ctrlSetPosition [_hscreen, _vscreen];
                                       (_rects select _i) ctrlCommit 0;
                                       (_texts select _i) ctrlSetPosition [_hscreen, _vscreen-0.02];
                                       (_texts select _i) ctrlCommit 0;
                                    }
                                    else
                                    {
                                       (_rects select _i) ctrlSetTextColor [0, 0, 0, 0];
                                       (_texts select _i) ctrlSetTextColor [0, 0, 0, 0];
                                    };
                                 }
                                 else
                                 {
                                    (_rects select _i) ctrlSetTextColor [0, 0, 0, 0];
                                    (_texts select _i) ctrlSetTextColor [0, 0, 0, 0];
                                 };
                              };
                           }
                           else
                           {
                              {
                                 _x ctrlSetTextColor [0, 0, 0, 0];
                              } forEach _rects;
                              {
                                 _x ctrlSetTextColor [0, 0, 0, 0];
                              } forEach _texts;
                           };

                           if (!_rombe_ok) then 
                           {
                              _rombe ctrlSetTextColor [0,0,0,0];
                           };





// FIRING DIRECTIONS HERE
                           if (mando_tv_missileidx >= 0) then
                           {
                              if (mando_tv_init_dir >= 0) then
                              {
                                 _firing_dir = mando_tv_init_dir + getDir mando_tv_plane;
                              };
                           }
                           else
                           {
                              if (mando_tv_weaponname != "") then
                              {
                                 _firing_dir = ((mando_tv_plane weaponDirection mando_tv_weaponname) select 0) atan2 ((mando_tv_plane weaponDirection mando_tv_weaponname) select 1);
                              }
                              else
                              {
                                 _firing_dir = mando_tv_init_dir + getDir mando_tv_plane;
                              };
/*
                              if (_firing_dir < 0) then 
                              {
                                 _firing_dir = _firing_dir + 360;
                              };
*/
                           };


                           _pos = mando_tv_plane modelToWorld mando_tv_cam_pos;

                           _dist = _pos distance mando_tv_cam_target;
                           _pos = [(_pos select 0)+sin(_firing_dir)*_dist,(_pos select 1)+cos(_firing_dir)*_dist, _pos select 2];
                           _loglos setPos _pos;
                           _screen1 = [mando_tv_plane, _loglos, _vdir] call MandoWorldToScreen2tv;


                           {                               
                              _angh = _firing_dir + (_x select 1);

                              _pos = mando_tv_plane modelToWorld mando_tv_cam_pos;
                              _dist = _pos distance mando_tv_cam_target;
                              _pos = [(_pos select 0)+sin(_angh)*_dist,(_pos select 1)+cos(_angh)*_dist, _pos select 2];      



                              _loglos setPos _pos;
                              _screen = [mando_tv_plane, _loglos, _vdir] call MandoWorldToScreen2tv;


                              if (abs(_screen select 0) > 0.5) then
                              {

                                 if (abs(_screen1 select 2) < abs(_x select 1)) then
                                 {
                                    if ((_x select 0) == _tgt_arrow_left) then
                                    {
                                       _screen set [0, -0.5]; 
                                    }
                                    else
                                    {
                                       _screen set [0, 0.5];
                                    };
                                 }
                                 else
                                 {
                                    if ((_x select 0) == _tgt_arrow_left) then
                                    {
                                       _screen set [0, 0.5];
                                    }
                                    else
                                    {
                                       _screen set [0, -0.5];
                                    };
                                 };
                              };

                              _hscreen = 0.5 + (_screen select 0)/(_zoom*1.5) - 0.04/2;
                              _hscreen = _hscreen min (0.7-0.04);
                              _hscreen = _hscreen max (0.3);
                              _vscreen = 0.5 - 0.05/2;

                              (_x select 0) ctrlSetPosition [_hscreen, _vscreen];
                              (_x select 0) ctrlCommit 0;


                           } forEach [[_tgt_arrow_left, -(mando_tv_missileparams select 29)], [_tgt_arrow_right,mando_tv_missileparams select 29]];





                           if (mando_take_pic && (alive mando_tv_plane)) then
                           {
                              mando_take_pic = false;
                              if (!mando_take_pic_on || mando_tv_move) then
                              { 
                                 _loglos setPos _mando_tv_cam_target;
                                 _pos = getPosASL _loglos;
                                 _loglos setPos (mando_tv_plane modelToWorld mando_tv_cam_pos);
                                 _poslos = getPosASL _loglos;
   
                                 _dist = 0.001 + sqrt(((_poslos select 0) - (_pos select 0))^2 + ((_poslos select 1) - (_pos select 1))^2);
                                 _dirlos = ((_pos select 0)-(_poslos select 0)) atan2 ((_pos select 1)-(_poslos select 1));       
                                 _ratev = ((_pos select 2) - (_poslos select 2))/_dist;


/*
                                 for [{_i = 20},{_i < _dist},{_i=_i + 3}] do
                                 {
                                    _loglos setPosASL [(_poslos select 0)+sin(_dirlos)*_i,(_poslos select 1)+cos(_dirlos)*_i, (_poslos select 2)+_ratev*_i];


                                    if ((getPos _loglos select 2) <= 0) then
                                    {             
                                       _mando_tv_cam_target = getPos _loglos;
                                       _i = 9999; 
                                    };
                                 };                           
*/

                                 _loglos setPos screenToWorld [0.5,0.5];

                                 _i = 9999;
                                 if ((_loglos distance (mando_tv_plane modelToWorld mando_tv_cam_pos)) > mando_tv_sensor_rng_l) then
                                 {
                                    _i = 0;
                                 }
                                 else
                                 {
                                    _mando_tv_cam_target = getPos _loglos;
                                 };


                                 if ((_air_targets || _radar_targets) && !mando_tv_move) then
                                 {
                                    _i = 0;
                                 };

                                 if (mando_take_pic_on && mando_tv_move) then
                                 {
                                    _i = 9999;
                                 };

                                 if (_i >= 9999) then
                                 {
                                    if (!mando_tv_move) then
                                    {
                                       if (isNull mando_tv_laserlogic) then
                                       {

                                          if (isNil "mando_tv_laserlogic_center") then
                                          {
                                             mando_tv_laserlogic_center = createCenter sideLogic;
                                             mando_tv_laserlogic_group = createGroup mando_tv_laserlogic_center;
                                          };

                                          mando_tv_laserlogic = mando_tv_laserlogic_group createUnit ["LOGIC", [0, 0, 0], [], 0, ""];
                                          mando_tv_laserlogic setPos [getPos _loglos select 0, getPos _loglos select 1, 1.5];
                                       };

                                       if (count (nearestObjects [[getPos _loglos select 0, getPos _loglos select 1, 0], ["Ship", "LandVehicle"], (20*mando_tvcam_scale) max 12]) > 0) then     
                                       {
                                          mando_tv_laserlogic_target = (nearestObjects [[getPos _loglos select 0, getPos _loglos select 1, 0], ["Ship", "LandVehicle"], (20*mando_tvcam_scale) max 12]) select 0;
                                          playSound "mando_target1";
                                       }
                                       else
                                       {
                                          if (!isNull _target) then
                                          {
                                             mando_tv_laserlogic_target = _target;
                                             playSound "mando_target1";
                                          };
                                       };
                                       mando_take_pic_on = true;
                                    }
                                    else
                                    {
                                       mando_tv_move = false;


                                       if (mando_take_pic_on) then
                                       {
                                          mando_tv_dest = [_post select 0, _post select 1, 0];

                                       }
                                       else
                                       {
                                          mando_tv_dest = getPos _loglos;                                       
                                       };
                                       (driver mando_tv_plane) setBehaviour "CARELESS";
                                       (driver mando_tv_plane) commandMove mando_tv_dest;
                                    };
                                 }
                                 else
                                 {
                                    if (!isNull _target) then
                                    {
                                       mando_tv_laserlogic_target = _target;
                                       playSound "mando_target1";


                                       if (isNull mando_tv_laserlogic) then
                                       {
                                          if (isNil "mando_tv_laserlogic_center") then
                                          {
                                             mando_tv_laserlogic_center = createCenter sideLogic;
                                             mando_tv_laserlogic_group = createGroup mando_tv_laserlogic_center;
                                          };
                                          mando_tv_laserlogic = mando_tv_laserlogic_group createUnit ["LOGIC", [0, 0, 0], [], 0, ""];
                                          mando_tv_laserlogic setPos (getPos _target);
                                       };
                                       mando_take_pic_on = true;
                                    };
                                 };         
                              }
                              else
                              {
                                 _pos = getPos mando_tv_plane;
                                 if (!isNull mando_tv_laserlogic_target) then
                                 {
                                    _post = (getPos mando_tv_laserlogic_target);
                                 }
                                 else
                                 {
                                    _post = _mando_tv_cam_target;
                                 };
                                 _logcam setPos (mando_tv_plane modelToWorld mando_tv_cam_pos);
                                 _logcam setDir 0;
                                 _pos = _logcam worldToModel _post;
                                 _angles set [0, (_pos select 0) atan2 (_pos select 1)];
                                 _angles set [1, asin((_pos select 2)/(_post distance _logcam))];
/*
                                 _dirlos = ((_post select 0)-(_pos select 0)) atan2 ((_post select 1)-(_pos select 1));
                                 _loglos setPos _post; 

                                 _angles set [0, _dirlos];
                                 _angles set [1, asin(((getPosASL _loglos select 2)-(getPosASL mando_tv_plane select 2))/(mando_tv_plane distance _post))];
*/
                                 mando_cam_angles = _angles;

                                 mando_take_pic_on = false;
                                 if (!isNull  mando_tv_laserlogic) then 
                                 {
                                    deleteVehicle mando_tv_laserlogic;
                                 };
                                 if (!isNull  mando_tv_laserlogic_target) then 
                                 {
                                    mando_tv_laserlogic_target = objNull;
                                 };
                              };

                              mando_tv_move = false;
                           };
                        };
                     };
/* CAM MOD
                     _cam camSetFov mando_tvcam_scale;
                     _cam camCommit 0; 
*/
                  }
                  else
                  {
                     mando_tv_cam = 0;
                  };
                  sleep 0.002;
               }
               else
               {
                  _fire_button ctrlShow false; 
                  _flir_button ctrlShow false;

                  mando_last_missile_target setPos (getPos mando_last_target);
                  Sleep 1;
               };
            };
            deleteVehicle _loglos;
            deleteVehicle _logcam;
            deleteVehicle _logasl;
            deleteVehicle _trigger;
            mando_last_missile_target setPos (getPos mando_last_target);

            mando_rec_flir = false;
            if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
            {
               call compile "false SetCamUseTi 0";
            }
            else
            {
               setAperture -1;
            };
            ppEffectDestroy mando_ppccor;
            ppEffectDestroy mando_ppcinv;
            ppEffectDestroy mando_ppdyblur;
            ppEffectDestroy mando_ppfgrain;
         };

         _mando_tv_cam_old = 0;

         _vel_to_keep = velocity mando_tv_plane;
         _dir_to_keep = vectorDir mando_tv_plane;     
         _up_to_keep = vectorUp mando_tv_plane;     
         while {!isNull _commdisplay} do
         {
            if (!alive player || !alive mando_tv_plane) then
            {
               CloseDialog 23900;
            };
            if ((player == driver mando_tv_plane) && ((getPos mando_tv_plane select 2) > 10))then
            {
               mando_tv_plane setVectorUp _up_to_keep;
               mando_tv_plane setVectorDir _dir_to_keep;
               mando_tv_plane setVelocity _vel_to_keep;
               Sleep 0.01;
            }
            else
            {
               Sleep 0.1;
            };
         };
         mando_tv_camera cameraeffect ["terminate", "back"];
         camDestroy mando_tv_camera;
         deleteVehicle _loglos;
         deleteMarkerLocal "mk_mma_tv";
         deleteMarkerLocal "mk_mma_tv_dest";
         mandotarget_disp_on = mandotarget_disp_on_old;
         mandotarget_disp_on = true;


         if (!isNull  mando_tv_laserlogic_target) then 
         {
            _continue = false;
            switch (side mando_tv_plane) do
            {    
               case west:
               {
                  if (mando_tv_laserlogic_target in mando_remote_targets_w) then 
                  {
                     _continue = true;
                  };
               };

               case east:
               {
                  if (mando_tv_laserlogic_target in mando_remote_targets_e) then 
                  {
                     _continue = true;
                  };
               };

               case resistance:
               {
                  if (mando_tv_laserlogic_target in mando_remote_targets_r) then 
                  {
                     _continue = true;
                  };
               };
            };

			 _continue = true; // <<<<<< Quitar comentario para mantar local targets aun saliendo de la camara
			
            if (!_continue) then
            {
               mando_tv_laserlogic_target = objNull;
               if (!isNull  mando_tv_laserlogic) then 
               {
                  deleteVehicle mando_tv_laserlogic;
               };
               mando_take_pic_on = false;
            };
         };
      };
   };



   case "onMouseMoving":
   {
      if ((abs(((_this select 1) select 1)-0.5) > 0.002) || (abs(((_this select 1) select 2)-0.5) > 0.002)) then
      {

         _temp_angles = [(((_this select 1) select 1)-0.5)/0.2,(0.5-((_this select 1) select 2))/0.2];

   // 4 is max (decrease or increase for more angular speed)
         if ((abs(_temp_angles select 0) <= 1) && (abs(_temp_angles select 1) <= 1)) then
         {
            mando_tvcam_angles set [0, (_temp_angles select 0)*4*(mando_tvcam_scale max 0.06)];
            mando_tvcam_angles set [1, (_temp_angles select 1)*4*(mando_tvcam_scale max 0.06)];
         }
         else
         {
            mando_tvcam_angles = [0,0];
         };
      }
      else
      {
         mando_tvcam_angles = [0,0];
      };
   };


   case "onMouseZChanged":
   {
      if (((_this select 1) select 1) > 0) then
      {
         if (mando_cam_scale > 0.2) then
         {
            mando_cam_scale = mando_cam_scale - 0.1;
         };
   
		  if (mando_tvcam_scale > 0.05) then
		  {
			 mando_tvcam_scale = mando_tvcam_scale - 0.05;
		  }
		  else
		  {
			  if (mando_tvcam_scale > 0.01) then
			  {
				 mando_tvcam_scale = (mando_tvcam_scale - 0.01) max 0.01;
			  }	  
		  };
      }
      else
      {
         if (mando_cam_scale < 1) then
         {
            mando_cam_scale = mando_cam_scale + 0.1;
         };

		  if (mando_tvcam_scale < 1) then
		  {
			  if (mando_tvcam_scale > 0.05) then
			  {	  
				  mando_tvcam_scale = (mando_tvcam_scale + 0.05) min 1;
			  }
			  else
			  {
				  mando_tvcam_scale = mando_tvcam_scale + 0.01;		  
			  };
		  };
      };
   };

   case "onCameraClick":
   {
      if (((_this select 1) select 1) == 0) then
      {
         if ((_this select 1) select 4) then
         {
            mando_tv_move = true;
         };
         mando_take_pic = true;
      }
      else
      {
         ["CALL_TV_FIRE", []] call mando_missile_tv;
      };
   };


   case "ZOOM_IN":
   {
// fov = tan (1/zoom*45)
// zoom = 1/atan(fov)/45
      if (mando_cam_scale > 0.2) then
      {
         mando_cam_scale = mando_cam_scale - 0.1;
      };

      if (mando_tvcam_scale > 0.05) then
      {
         mando_tvcam_scale = mando_tvcam_scale - 0.05;
      }
	  else
	  {
		  if (mando_tvcam_scale > 0.01) then
		  {
			 mando_tvcam_scale = (mando_tvcam_scale - 0.01) max 0.01;
		  }	  
	  };
   };


   case "ZOOM_OUT":
   {
      if (mando_cam_scale < 1) then
      {
         mando_cam_scale = mando_cam_scale + 0.1;
      };

      if (mando_tvcam_scale < 1) then
      {
		  if (mando_tvcam_scale > 0.05) then
		  {	  
		      mando_tvcam_scale = (mando_tvcam_scale + 0.05) min 1;
		  }
		  else
		  {
		      mando_tvcam_scale = mando_tvcam_scale + 0.01;		  
		  };
      };
   };


   case "CALL_TV_FIRE":
   {
      if (!ctrlEnabled ((findDisplay 23900) displayCtrl 23918)) exitWith {};


      if (alive mando_tv_plane && !(isNil "mando_missile_init")) then
      {
         _target = objNull;

         if (!isNull mando_tv_laserlogic || (!isNull mando_tv_laserlogic_target && mando_tv_faf)) then
         {
            if (!isNull mando_tv_laserlogic_target && (mando_tv_faf || (mando_tv_wtype == "GUN"))) then
            {
               _target = mando_tv_laserlogic_target;
            }
            else
            { 
               if (mando_tv_wtype == "GUN") then
               {
                  _target = mando_tv_laserlogic;
               }
               else
               {
                  if (mando_tv_faf) then
                  {
                     _target = "logic" createVehicleLocal [0,0,0];
                     _target setPos (getPos mando_tv_laserlogic);
                     [_target] spawn
                     {
                        Sleep ((mando_tv_missileparams select 17) + 3);
                        deleteVehicle (_this select 0);
                     };
                  }
                  else
                  {
                     _target = mando_tv_laserlogic;
                  };
               };
            };
         }; 


         if ((isNull _target && (mando_tv_wtype == "GUN")) || ((mando_tv_wtype == "GUN") && !("Air" in mando_tv_target_types))) then
         {
            _pos = mando_tv_camera modelToWorld [0,1000,0];

            _target = "logic" createVehicleLocal [0,0,0];
            _target setPos _pos;
            [_target] spawn
            {
               Sleep 3;
               deleteVehicle (_this select 0);
            };
         };
         

         if (isNull _target) then
         {
            _target = "logic" createVehicleLocal [0,0,0];
            _target setPos (screenToWorld [0.5, 0.5]);
            [_target] spawn
            {
               private["_elapsed", "_mis", "_pos"];
               _elapsed = (dayTime * 3600);
			   _mis = objNull;
               while {(dayTime * 3600) < (_elapsed + 15)} do
               {
                  if (!isNull mando_tv_laserlogic_target) then
                  {
                     (_this select 0) setPosASL (getPosASL mando_tv_laserlogic_target);
                  }
                  else
                  {
						if (isNull _mis) then
						{
							if (!isNull (mando_tv_plane getVariable "mando_missile_fired")) then
							{
								_mis = mando_tv_plane getVariable "mando_missile_fired";
							};
						};
						
					  _pos = positionCameraToWorld [0,0,10000];
					  if ((_pos select 2) < 0) then
					  {
                        (_this select 0) setPos (screenToWorld [0.5, 0.5]);
					  }
					  else
					  {
						(_this select 0) setPos positionCameraToWorld [0,0,(mando_tv_plane distance _mis)+30];
					  };
                  };
                  Sleep 0.01;
               };
               deleteVehicle (_this select 0);
            };
         };


         if (!isNull _target) then
         {
            _continue = true;

            if (mando_tv_missileidx >= 0) then
            {

               if ((mando_tv_plane getVariable format["mando_missilesleft%1", mando_tv_missileidx]) > 0) then
               {               
                  mando_tv_plane setVariable [format["mando_missilesleft%1", mando_tv_missileidx], (mando_tv_plane getVariable format["mando_missilesleft%1", mando_tv_missileidx]) - 1];
                  ((findDisplay 23900) displayCtrl 23918) ctrlSetText format["Fire: %1", mando_tv_plane getVariable format["mando_missilesleft%1", mando_tv_missileidx]];

                  if ((mando_tv_plane getVariable format["mando_missilesleft%1", mando_tv_missileidx]) == 0) then
                  {
                     playSound "mando_noammo1";
                     playSound "mando_noammo2";
                  };
               }
               else
               {
                  _continue = false;
               };
            }
            else
            {
               if (mando_tv_weaponname != "") then
               {
                  _ammo_left = (mando_tv_plane ammo mando_tv_weaponname) max (player ammo mando_tv_weaponname);
                  if (_ammo_left > 0) then
                  {
                     ((findDisplay 23900) displayCtrl 23918) ctrlSetText format["Fire: %1", _ammo_left-1];
                     if (_ammo_left == 1) then
                     {
                        playSound "mando_noammo1";
                        playSound "mando_noammo2";
                     };
                  }
                  else
                  {
                     _continue = false;
                  };
               }
               else
               {
                  _continue = false;
               };
            };



            if (_continue) then
            {

               if (mando_tv_wtype == "GUN") exitWith
               {
                  [_target] spawn
                  {
                     private["_target"];
                     _target = _this select 0;

                     mando_gun_lite_sound = mando_tv_gun_sound;
                     mando_gun_lite = mando_tv_plane;
               
                     publicVariable "mando_gun_sound";
                     publicVariable "mando_gun";
               
                     if (!("Air" in mando_tv_target_types) && (!isNull mando_tv_laserlogic_target)) then
                     {
                        _target setPosASL [(getPosASL mando_tv_laserlogic_target select 0)+(velocity mando_tv_laserlogic_target select 0)*0.5,(getPosASL mando_tv_laserlogic_target select 1)+(velocity mando_tv_laserlogic_target select 1)*0.5,(getPosASL mando_tv_laserlogic_target select 2)+(velocity mando_tv_laserlogic_target select 2)*0.5];
                     };
                     [mando_tv_plane, mando_tv_firing_pos, "", mando_tv_weapon_length, _target, mando_tv_gun_dispersion,true,mando_tv_gun_ammo,1000,true] execVM mando_missile_path+"mando_gun_lite\mando_gun_lite.sqf";
                     Sleep 0.1;


                     if (!("Air" in mando_tv_target_types) && (!isNull mando_tv_laserlogic_target)) then
                     {
                        _target setPosASL [(getPosASL mando_tv_laserlogic_target select 0)+(velocity mando_tv_laserlogic_target select 0)*1,(getPosASL mando_tv_laserlogic_target select 1)+(velocity mando_tv_laserlogic_target select 1)*1,(getPosASL mando_tv_laserlogic_target select 2)+(velocity mando_tv_laserlogic_target select 2)*1];
                     };
                     [mando_tv_plane, mando_tv_firing_pos, "", mando_tv_weapon_length, _target, mando_tv_gun_dispersion,true,mando_tv_gun_ammo,1000,true] execVM mando_missile_path+"mando_gun_lite\mando_gun_lite.sqf";
                     Sleep 0.1;

                     if (!("Air" in mando_tv_target_types) && (!isNull mando_tv_laserlogic_target)) then
                     {
                        _target setPosASL [(getPosASL mando_tv_laserlogic_target select 0)+(velocity mando_tv_laserlogic_target select 0)*1.5,(getPosASL mando_tv_laserlogic_target select 1)+(velocity mando_tv_laserlogic_target select 1)*1.5,(getPosASL mando_tv_laserlogic_target select 2)+(velocity mando_tv_laserlogic_target select 2)*1.5];
                     };
                     [mando_tv_plane, mando_tv_firing_pos, "", mando_tv_weapon_length, _target, mando_tv_gun_dispersion,true,mando_tv_gun_ammo,1000,true] execVM mando_missile_path+"mando_gun_lite\mando_gun_lite.sqf";
                     Sleep 0.1;

                     if (!("Air" in mando_tv_target_types) && (!isNull mando_tv_laserlogic_target)) then
                     {
                        _target setPosASL [(getPosASL mando_tv_laserlogic_target select 0)+(velocity mando_tv_laserlogic_target select 0)*2,(getPosASL mando_tv_laserlogic_target select 1)+(velocity mando_tv_laserlogic_target select 1)*2,(getPosASL mando_tv_laserlogic_target select 2)+(velocity mando_tv_laserlogic_target select 2)*2];
                     };
                     [mando_tv_plane, mando_tv_firing_pos, "", mando_tv_weapon_length, _target, mando_tv_gun_dispersion,true,mando_tv_gun_ammo,1000,true] execVM mando_missile_path+"mando_gun_lite\mando_gun_lite.sqf";
                     Sleep 0.1;

                     if (!("Air" in mando_tv_target_types) && (!isNull mando_tv_laserlogic_target)) then
                     {
                        _target setPosASL [(getPosASL mando_tv_laserlogic_target select 0)+(velocity mando_tv_laserlogic_target select 0)*2.5,(getPosASL mando_tv_laserlogic_target select 1)+(velocity mando_tv_laserlogic_target select 1)*2.5,(getPosASL mando_tv_laserlogic_target select 2)+(velocity mando_tv_laserlogic_target select 2)*2.5];
                     };
                     [mando_tv_plane, mando_tv_firing_pos, "", mando_tv_weapon_length, _target, mando_tv_gun_dispersion,true,mando_tv_gun_ammo,1000,true] execVM mando_missile_path+"mando_gun_lite\mando_gun_lite.sqf";

                     [] spawn
                     {
                        disableSerialization;
                        ((findDisplay 23900) displayCtrl 23918) ctrlEnable false;
                        Sleep mando_tv_firing_delay;
                        ((findDisplay 23900) displayCtrl 23918) ctrlEnable true;
                     };
                  }; 
               };


               mando_tv_pilon = -mando_tv_pilon;                  
               if (!mando_tv_man) then
               {
                  _missparam = [];
                  _missparam = _missparam + mando_tv_missileparams;
                  _missparam set [0, mando_tv_plane];
                  _missparam set [8, _target];
                  _missparam set [23, false];

                  if (mando_tv_ammo_base == "LaserBombCore") then
                  {
                     _missparam set [6, (_missparam select 6) max ((speed mando_tv_plane)/3.6)];
                     _missparam set [17, sqrt((getPos mando_tv_plane select 2)*2/9.8)+1];
                  };


                  if (mando_tv_missileidx >= 0) then
                  {
                     _missparam set [2, [((_missparam select 2) select 0)*mando_tv_pilon, ((_missparam select 2) select 1),((_missparam select 2) select 2)]];

                     if (mando_tv_init_dir >= 0) then
                     {
                        _firing_dir = mando_tv_init_dir + getDir mando_tv_plane;
                     }
                     else
                     {
                        _firing_dir = ((getPos _target select 0)-(getPos mando_tv_plane select 0)) atan2 ((getPos _target select 1)-(getPos mando_tv_plane select 1));
                     };
                     _missparam set [3, _firing_dir];

                     _missparam execVM "mando_missiles\mando_missile.sqf";

                     [] spawn
                     {
                        disableSerialization;
                        ((findDisplay 23900) displayCtrl 23918) ctrlEnable false;
                        Sleep mando_tv_firing_delay;
                        ((findDisplay 23900) displayCtrl 23918) ctrlEnable true;
                     };
                  }
                  else
                  {
                  // BIS missile

                     mando_firing = true;
                     _ammo = (mando_tv_plane ammo mando_tv_weaponname) max (player ammo mando_tv_weaponname);
                     _firer1 = player;
                     _firer2 = player;
                     if (player == driver mando_tv_plane) then
                     {
                        _firer1 = driver mando_tv_plane;
                        _firer2 = gunner mando_tv_plane;
                     } 
                     else
                     {
                        _firer1 = gunner mando_tv_plane;
                        _firer2 = driver mando_tv_plane;
                     };


                     if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
                     {
                        if (mando_tv_missileidx < -1) then
                        {
                           mando_tv_plane action ["useWeapon",mando_tv_plane, _firer1, abs(mando_tv_missileidx)-1];
                        }
                        else
                        {
                           call compile format["_handle = mando_tv_plane fireAtTarget [objNull, '%1']", mando_tv_weaponname];
                        };
                     }
                     else
                     {
                        mando_tv_plane action ["useWeapon",mando_tv_plane, _firer1, [mando_tv_plane, mando_tv_weaponname] call mando_weaponindex];
                     };

                     _mis = (getPos mando_tv_plane) nearestObject mando_tv_ammo_base;
                     if (isNull _mis) then
                     {
                        if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
                        {
                           call compile format["_handle = mando_tv_plane fireAtTarget [objNull, '%1']", mando_tv_weaponname];
                        }
                        else
                        {
                           mando_tv_plane action ["useWeapon",mando_tv_plane, _firer2, [mando_tv_plane, mando_tv_weaponname] call mando_weaponindex];
                        };
                        _mis = (getPos mando_tv_plane) nearestObject mando_tv_ammo_base;
                     };

                     if (!isNull _mis) then
                     {
                        [_mis, _missparam]spawn
                        {
                           private["_mis", "_missparam", "_pos", "_firing_dir"];
                           _mis = _this select 0;
                           _missparam = _this select 1;
                           if (mando_tv_ammo_base == "LaserBombCore") then
                           {
                              sleep 1;
                           }
                           else
                           {
                              sleep 0.1;
                           };
                           if (!mando_tv_keepgeo) then
                           {
                              _pos = mando_tv_plane worldToModel (getPos _mis);   
                              if ((getPos mando_tv_plane select 2) > 10) then
                              {
                                 if ((_pos select 2) > -2) then
                                 {
                                    _pos set [2, ((_missparam select 2) select 2)];
                                 };
                              };
                              _missparam set [2, _pos];
                              _missparam set [3, getDir _mis];
                              _missparam set [4, asin (vectorDir _mis select 2) - asin(vectorDir mando_tv_plane select 2)];
                              _missparam set [5, (((speed _mis)/3.6 - (speed mando_tv_plane)/3.6) min (_missparam select 6)) min 200];

                           }
                           else
                           {
                              _missparam set [2, [((_missparam select 2) select 0)*mando_tv_pilon, ((_missparam select 2) select 1),((_missparam select 2) select 2)]];

                              if (mando_tv_init_dir >= 0) then
                              {
                                 _firing_dir = mando_tv_init_dir + getDir mando_tv_plane;
                              }
                              else
                              {
                                 _firing_dir = ((getPos _target select 0)-(getPos mando_tv_plane select 0)) atan2 ((getPos _target select 1)-(getPos mando_tv_plane select 1));
                              };
                              _missparam set [3, _firing_dir];
                           };
						   
				   		   _mis setPos [60000,60000,60000];
                           [_mis] spawn
                           {
                              _missile = _this select 0;            
                              Sleep 6;
                              if (alive _missile) then
                              { 
                                 deleteVehicle _missile;
                              };
                           };

                           _missparam execVM "mando_missiles\mando_missile.sqf";
                          
                        };   

                        [] spawn
                        {
                           disableSerialization;
                           ((findDisplay 23900) displayCtrl 23918) ctrlEnable false;
                           Sleep mando_tv_firing_delay;
                           ((findDisplay 23900) displayCtrl 23918) ctrlEnable true;
                        };
                     }
                     else
                     {
                        if (((mando_tv_plane ammo mando_tv_weaponname) max (player ammo mando_tv_weaponname)) < _ammo) then
                        {
                           _missparam set [2, [((_missparam select 2) select 0)*mando_tv_pilon, ((_missparam select 2) select 1),((_missparam select 2) select 2)]];

                           if (mando_tv_init_dir >= 0) then
                           {
                              _firing_dir = mando_tv_init_dir + getDir mando_tv_plane;
                           }
                           else
                           {
                              _firing_dir = ((getPos _target select 0)-(getPos mando_tv_plane select 0)) atan2 ((getPos _target select 1)-(getPos mando_tv_plane select 1));
                           };
                           _missparam set [3, _firing_dir];

                           _missparam execVM "mando_missiles\mando_missile.sqf";

                           [] spawn
                           {
                              disableSerialization;
                              ((findDisplay 23900) displayCtrl 23918) ctrlEnable false;
                              Sleep mando_tv_firing_delay;
                              ((findDisplay 23900) displayCtrl 23918) ctrlEnable true;
                           };
                        }
                        else
                        {
                           playSound "mando_noammo1";
                           playSound "mando_noammo2";
                        };
                     };
                  };
               }
               else
               {
// Manual
                  mando_tvcam_scale = 1;
                  []spawn
                  { 
                     setMousePosition [0.5, 0.5];
                  };

                  _target1 = "logic" createVehicleLocal [0,0,0];
                  _target2 = "logic" createVehicleLocal [0,0,0];

                  _target1 setPos (getPos _target);
                  _target2 setPos (getPos _target);

                  _missparam = [];
                  _missparam = _missparam + mando_tv_missileparams;
                  _missparam set [0, mando_tv_plane];
                  _missparam set [8, _target1];

                  if (mando_tv_ammo_base == "LaserBombCore") then
                  {
                     _missparam set [6, (_missparam select 6) max ((speed mando_tv_plane)/3.6)];
                  };

                  _missparam set [6, (_missparam select 6)*.7];
                  _missparam set [19, 0];
                  _missparam set [25,15];
                  _missparam set [26,15];

                  if (mando_tv_missileidx >= 0) then
                  {
                     _missparam set [2, [((_missparam select 2) select 0)*mando_tv_pilon, ((_missparam select 2) select 1),((_missparam select 2) select 2)]];

                     if (mando_tv_init_dir >= 0) then
                     {
                        _firing_dir = mando_tv_init_dir + getDir mando_tv_plane;
                     }
                     else
                     {
                        _firing_dir = ((getPos _target select 0)-(getPos mando_tv_plane select 0)) atan2 ((getPos _target select 1)-(getPos mando_tv_plane select 1));
                     };
                     _missparam set [3, _firing_dir];

                     _missparam execVM "mando_missiles\mando_missile.sqf";

                     [] spawn
                     {
                        disableSerialization;
                        ((findDisplay 23900) displayCtrl 23918) ctrlEnable false;
                        Sleep mando_tv_firing_delay;
                        ((findDisplay 23900) displayCtrl 23918) ctrlEnable true;
                     };
                  }
                  else
                  {
// BIS Missile
                     mando_firing = true;
                     _ammo= (mando_tv_plane ammo mando_tv_weaponname) max (player ammo mando_tv_weaponname);

                     if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
                     {
                        call compile format["_handle = mando_tv_plane fireAtTarget [objNull, '%1']", mando_tv_weaponname];
                     }
                     else
                     {
                        mando_tv_plane action ["useWeapon",mando_tv_plane, driver mando_tv_plane, [mando_tv_plane, mando_tv_weaponname] call mando_weaponindex];
                     };

                     _mis = (getPos mando_tv_plane) nearestObject mando_tv_ammo_base;
                     if (isNull _mis) then
                     {
                        if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
                        {
                           call compile format["_handle = mando_tv_plane fireAtTarget [objNull, '%1']", mando_tv_weaponname];
                        }
                        else
                        {
                           mando_tv_plane action ["useWeapon",mando_tv_plane, gunner mando_tv_plane, [mando_tv_plane, mando_tv_weaponname] call mando_weaponindex];
                        };
                        _mis = (getPos mando_tv_plane) nearestObject mando_tv_ammo_base;
                     };                        

                     if (!isNull _mis) then
                     {
                        [_mis, _missparam]spawn
                        {
                           private["_mis", "_missparam", "_pos", "_firing_dir"];
                           _mis = _this select 0;
                           _missparam = _this select 1;

                           if (mando_tv_ammo_base == "LaserBombCore") then
                           {
                              sleep 1;
                           }
                           else
                           {
                              sleep 0.1;
                           };

                           _pos = mando_tv_plane worldToModel (getPos _mis);
                           if ((getPos mando_tv_plane select 2) > 10) then
                           {
                              if ((_pos select 2) > -2) then
                              {
                                 _pos set [2, ((_missparam select 2) select 2)];
                              };
                           };
                           _missparam set [2, _pos];
                           _missparam set [3, getDir _mis];
                           _missparam set [5, ((speed _mis)/3.6 - (speed mando_tv_plane)/3.6) min (_missparam select 6)];


				   		   _mis setPos [60000,60000,60000];
                           [_mis] spawn
                           {
                              _missile = _this select 0;            
                              Sleep 6;
                              if (alive _missile) then
                              { 
                                 deleteVehicle _missile;
                              };
                           };

                           _missparam execVM "mando_missiles\mando_missile.sqf";
                        };

                        [] spawn
                        {
                           disableSerialization;
                           ((findDisplay 23900) displayCtrl 23918) ctrlEnable false;
                           Sleep mando_tv_firing_delay;
                           ((findDisplay 23900) displayCtrl 23918) ctrlEnable true;
                        };

                     }
                     else
                     {
                        if (((mando_tv_plane ammo mando_tv_weaponname) max (player ammo mando_tv_weaponname)) < _ammo) then
                        {
                           _missparam set [2, [((_missparam select 2) select 0)*mando_tv_pilon, ((_missparam select 2) select 1),((_missparam select 2) select 2)]];

                           if (mando_tv_init_dir >= 0) then
                           {
                              _firing_dir = mando_tv_init_dir + getDir mando_tv_plane;
                           }
                           else
                           {
                              _firing_dir = ((getPos _target select 0)-(getPos mando_tv_plane select 0)) atan2 ((getPos _target select 1)-(getPos mando_tv_plane select 1));
                           };
                           _missparam set [3, _firing_dir];

                           _missparam execVM "mando_missiles\mando_missile.sqf";

                           [] spawn
                           {
                              disableSerialization;
                              ((findDisplay 23900) displayCtrl 23918) ctrlEnable false;
                              Sleep mando_tv_firing_delay;
                              ((findDisplay 23900) displayCtrl 23918) ctrlEnable true;
                           };
                        }
                        else
                        {
                           playSound "mando_noammo1";
                           playSound "mando_noammo2";
                        };
                     };
                  };


                  [_target1, _target2]spawn
                  {          
                     waitUntil {!isNull mando_missile};
                     mando_last_missile = mando_missile;

                     mando_last_missile_target = (_this select 0); 
                     mando_last_target = (_this select 1);

                     Sleep 21;
                     deleteVehicle (_this select 0);

                     deleteVehicle (_this select 1);

                  };
               }; 
            }
            else
            {
            };
         };
      };
   };

   case "CALL_TV_FLIR":
   {  
      if (mando_rec_flir) then
      {
         mando_rec_flir = false;
         if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
         {
            call compile "false SetCamUseTi 0";
         }
         else
         {
            setAperture -1;
         };
         ppEffectDestroy mando_ppccor;
         ppEffectDestroy mando_ppcinv;
         ppEffectDestroy mando_ppdyblur;
         ppEffectDestroy mando_ppfgrain;

            if (!isNil "mando_tv_camppe") then
            {
               switch (mando_tv_camppe) do
               {    
                  case 0:
                  {
                  };

                  case 1:
                  {
                     mando_ppccor = ppEffectCreate ["ColorCorrections", 1];
                     mando_ppccor ppEffectEnable true;
                     mando_ppccor ppEffectAdjust [0.20, 2.00, 0.00, [1.00, 1.00, 1.00, 0.00], [1.00, 1.00, 1.00, 0.00], [1.00, 1.00, 1.00, 1.00]];
                     mando_ppccor ppEffectCommit 0;

                     mando_ppfgrain = ppEffectCreate ["FilmGrain", 0];
                     mando_ppfgrain ppEffectEnable true;
                     mando_ppfgrain ppEffectAdjust [0.1, 0.1, 2.0, 0.1, 1.0, true];
                     mando_ppfgrain ppEffectCommit 0;
                  };
                  case 2:
                  {
                     mando_ppccor = ppEffectCreate ["ColorCorrections", 1];
                     mando_ppccor ppEffectEnable true;
                     mando_ppccor ppEffectAdjust [1.05, 0.95, 0.00, [0.80, 0.90, 1.00, -0.10], [1.00, 1.00, 1.00, 0.75], [1.00, 1.00, 1.00, 1.00]];
                     mando_ppccor ppEffectCommit 0;

                     mando_ppfgrain = ppEffectCreate ["FilmGrain", 0];
                     mando_ppfgrain ppEffectEnable true;
                     mando_ppfgrain ppEffectAdjust [0.1, 0.1, 2.0, 0.1, 1.0, true];
                     mando_ppfgrain ppEffectCommit 0;
                  };
               };
            };

      }
      else
      {
         mando_rec_flir = true;
//         setAperture 0.065;

         if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
         {
            ppEffectDestroy mando_ppccor;
            ppEffectDestroy mando_ppcinv;
            ppEffectDestroy mando_ppdyblur;
            ppEffectDestroy mando_ppfgrain;

            call compile "true SetCamUseTi 0";
/*
            if (!isNil "mando_tv_camppe") then
            {
               switch (mando_tv_camppe) do
               {    
                  case 0:
                  {
                     call compile "true SetCamUseTi 2";
                  };

                  case 1:
                  {
                     call compile "true SetCamUseTi 4";
                  };

                  case 2:
                  {
                     call compile "true SetCamUseTi 0";
                  };
               };
            };
*/

         }
         else
         {
            if ((daytime < 6) || (daytime > 18)) then
            {
               setAperture 0.08;
            };


            ppEffectDestroy mando_ppccor;
            ppEffectDestroy mando_ppcinv;
            ppEffectDestroy mando_ppdyblur;
            ppEffectDestroy mando_ppfgrain;

            mando_ppccor = ppEffectCreate ["ColorCorrections", 1];
            mando_ppccor ppEffectEnable true;
            mando_ppccor ppEffectAdjust [1, 1, -0.002, [1, 1, 1, 0.1], [1, 1, 1, 0], [1, 1, 1, 0]];
            mando_ppccor ppEffectCommit 0;

            mando_ppcinv = ppEffectCreate ["colorInversion", 2];
            mando_ppcinv ppEffectEnable true;
            mando_ppcinv ppEffectAdjust [0.2,0.2,0.2];
            mando_ppcinv ppEffectCommit 0;

            mando_ppdyblur = ppEffectCreate ["dynamicBlur", 0];
            mando_ppdyblur ppEffectEnable true;  
            mando_ppdyblur ppEffectAdjust [0.4];
            mando_ppdyblur ppEffectCommit 0;
         };
      };
   };

   case "CALL_TV_MODE":
   {
      if ( ctrlEnabled ((findDisplay 23900) displayCtrl 23921)) then
      {
         if ( ctrlText ((findDisplay 23900) displayCtrl 23921) == "Man F4") then
         {
            if (!mando_tv_faf) then
            {
               ((findDisplay 23900) displayCtrl 23921) ctrlSetText "S.Au F4"; 
            }
            else
            {
               ((findDisplay 23900) displayCtrl 23921) ctrlSetText "Auto F4"; 
            };
            mando_tv_man = false;
         }
         else
         {
            ((findDisplay 23900) displayCtrl 23921) ctrlSetText "Man F4";
            mando_tv_man = true;
         };
      };
   };

   case "CALL_TV_TARGETS":
   {  
      if ( ctrlEnabled ((findDisplay 23900) displayCtrl 23922)) then
      {
         if ( ctrlText ((findDisplay 23900) displayCtrl 23922) == "Loc F3") then
         {
            ((findDisplay 23900) displayCtrl 23922) ctrlSetText "Rem F3";
            mando_tv_remote = true;
         }
         else
         {
            ((findDisplay 23900) displayCtrl 23922) ctrlSetText "Loc F3";
            mando_tv_remote = false;
         };

         for [{_i=0},{_i<6},{_i=_i+1}] do
         { 
            (_rects select _i) ctrlSetTextColor [0,0,0,0];
            (_texts select _i) ctrlSetTextColor [0,0,0,0];
            (_texts select _i) ctrlSetText "";
         };
      };
   };

   case "CALL_TV_XMIT":
   {  
      if ( ctrlEnabled ((findDisplay 23900) displayCtrl 23927)) then
      {
         if (!isNull mando_tv_laserlogic) then
         { 
            if (mando_tv_wtype != "GUN") then
            {
               [side mando_tv_plane, mando_tv_laserlogic]execVM "mando_missiles\units\mando_addremotetarget.sqf";

               []spawn
               {
                  playSound "mando_target1";
                  ((findDisplay 23900) displayCtrl 23927) ctrlsetTextColor [0.5,1,0.5,1];
                  Sleep 0.2;
                  ((findDisplay 23900) displayCtrl 23927) ctrlsetTextColor [0,1,0,1];
                  Sleep 0.2;
                  ((findDisplay 23900) displayCtrl 23927) ctrlsetTextColor [0.5,1,0.5,1];
                  Sleep 0.2;
                  ((findDisplay 23900) displayCtrl 23927) ctrlsetTextColor [0,1,0,1];
                  Sleep 0.2;
                  ((findDisplay 23900) displayCtrl 23927) ctrlsetTextColor [0.5,1,0.5,1];
                  Sleep 0.2;
                  ((findDisplay 23900) displayCtrl 23927) ctrlsetTextColor [0,1,0,1];
                  Sleep 0.2;
                  ((findDisplay 23900) displayCtrl 23927) ctrlsetTextColor [1,1,1,1];
               };
            };         
         }
         else
         {
         // Nothing to transmit
         };
      };
   };

   case "CALL_TV_UP":
   {  
      if (ctrlEnabled ((findDisplay 23900) displayCtrl 23960)) then
      {
         if (!isPlayer (driver mando_tv_plane)) then
         {
            mando_tv_plane flyinHeight ((getPos mando_tv_plane select 2)+30);
            if ((expectedDestination (driver mando_tv_plane) select 1) != "DoNotPlan") then
            {
               driver mando_tv_plane commandMove (expectedDestination (driver mando_tv_plane) select 0);
            }
            else
            {
               driver mando_tv_plane commandMove [getPos mando_tv_plane select 0,getPos mando_tv_plane select 1,(getPos mando_tv_plane select 2)+30];
            };
         };
      };
   };

   case "CALL_TV_DOWN":
   {  
      if (ctrlEnabled ((findDisplay 23900) displayCtrl 23961)) then
      {         
         if (!isPlayer (driver mando_tv_plane)) then
         {
            mando_tv_plane flyinHeight (((getPos mando_tv_plane select 2)-30) max 20);

            if ((expectedDestination (driver mando_tv_plane) select 1) != "DoNotPlan") then
            {
               driver mando_tv_plane commandMove (expectedDestination (driver mando_tv_plane) select 0);
            }
            else
            {
               driver mando_tv_plane commandMove [getPos mando_tv_plane select 0,getPos mando_tv_plane select 1,(getPos mando_tv_plane select 2)-30];
            };
         };
      };
   };


   case "CALL_TV_MAP":
   {  
      if (ctrlVisible 23920) then
      {
         mando_tv_map_on = false;
         ((findDisplay 23900) displayCtrl 23920) ctrlShow false;
         []spawn
         { 
            setMousePosition [0.5, 0.5];
         };
      }
      else
      {
         mando_tv_map_on = true;
         ((findDisplay 23900) displayCtrl 23920) ctrlShow true;
      };
   };

   case "CALL_TV_HELP":
   {  
      if (ctrlVisible 23924) then
      {
         ((findDisplay 23900) displayCtrl 23924) ctrlShow false;
         []spawn
         { 
            setMousePosition [0.5, 0.5];
         };
      }
      else
      {
         ((findDisplay 23900) displayCtrl 23924) ctrlShow true;
         ((findDisplay 23900) displayCtrl 23924) htmlLoad "mando_missiles\tv\tv_help.html";
      };
   };


   case "onMapClick":
   {
      if (((_this select 1) select 1) == 0) then
      {
// Returns the control, the pressed button, the x and y coordinates and the state of Shift, Ctrl and Alt. 

//         hint format["%1",((findDisplay 23900) displayCtrl 23920) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3]];

         mando_tv_dest = ((findDisplay 23900) displayCtrl 23920) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3];
         (driver mando_tv_plane) setBehaviour "CARELESS";
         (driver mando_tv_plane) commandMove mando_tv_dest;

         if ((_this select 1) select 4) then
         {
         }
         else
         {
         };
      };
   };


   case "onKeyDown":
   {
// F1 HELP, F2 MAP, F3 TARGETS, F4 MODE, F5 FLIR

// "CALL_TV_MAP"", []] call mando_missile_tv"
      

      switch ((_this select 1) select 1) do
      {
         case 59: // F1 HELP
         {
            ["CALL_TV_HELP", []] call mando_missile_tv;
         };

         case 60: // F2 MAP
         {
            ["CALL_TV_MAP", []] call mando_missile_tv;
         };

         case 61: // F3 TARGETS LOCAL/REMOTE
         {
            ["CALL_TV_TARGETS", []] call mando_missile_tv;
         };

         case 62: // F4 MODE MAN/AUTO/SEMI
         {
            ["CALL_TV_MODE", []] call mando_missile_tv;
         };

         case 63: // F5 FLIR
         {
            ["CALL_TV_FLIR", []] call mando_missile_tv;
         };

         case 64: // F6 XMIT TARGET
         {
            ["CALL_TV_XMIT", []] call mando_missile_tv;
         };

         case 65: // F7 MOVE UP
         {
            ["CALL_TV_UP", []] call mando_missile_tv;
         };

         case 66: // F8 MOVE DOWN
         {
            ["CALL_TV_DOWN", []] call mando_missile_tv;
         };

         case 78: // ZOOM IN
         {
            ["ZOOM_IN", []] call mando_missile_tv;
         };

         case 74: // ZOOM OUT
         {
            ["ZOOM_OUT", []] call mando_missile_tv;
         };

         case mando_keylock: // Lock
	 {
            ["onCameraClick", [displayNull, 0, 0, 0, false]] call mando_missile_tv;
            ["onMouseMoving", [displayNull, 0.5, 0.5,true]] call mando_missile_tv;
	 };

         case mando_keyfire: // Fire
	 {

            ["CALL_TV_FIRE", []] call mando_missile_tv;
	 };

	 case 75: // KBN L
	 {
	    if (isNil "mando_tv_mouse_dir_x") then
	    {
	       mando_tv_mouse_dir_x = 0;
	    };

	    if (isNil "mando_tv_mouse_x") then
	    {
	       mando_tv_mouse_x = 0.5;
	    };
	    if (isNil "mando_tv_mouse_y") then
	    {
	       mando_tv_mouse_y = 0.5;
	    };


            if (mando_tv_mouse_dir_x != -1) then
	    {
               mando_tv_mouse_dir_x = -1;
               mando_tv_mouse_x = 0.5 + 0.0025;
	    };

	    if (mando_tv_mouse_x > 0.35) then
	    {
	       mando_tv_mouse_x = mando_tv_mouse_x - 0.0025;
               ["onMouseMoving", [displayNull, mando_tv_mouse_x, mando_tv_mouse_y,true]] call mando_missile_tv;
	    };
	 };

	 case 77: // KBN R
	 {
	    if (isNil "mando_tv_mouse_dir_x") then
	    {
	       mando_tv_mouse_dir_x = 0;
	    };

	    if (isNil "mando_tv_mouse_x") then
	    {
	       mando_tv_mouse_x = 0.5;
	    };
	    if (isNil "mando_tv_mouse_y") then
	    {
	       mando_tv_mouse_y = 0.5;
	    };

            if (mando_tv_mouse_dir_x != 1) then
	    {
               mando_tv_mouse_dir_x = 1;
               mando_tv_mouse_x = 0.5 - 0.0025;
	    };
	    if (mando_tv_mouse_x < 0.65) then
	    {
	       mando_tv_mouse_x = mando_tv_mouse_x + 0.0025;
               ["onMouseMoving", [displayNull, mando_tv_mouse_x, mando_tv_mouse_y,true]] call mando_missile_tv;
	    };
	 };

	 case 72: // KBN U
	 {
	    if (isNil "mando_tv_mouse_dir_y") then
	    {
	       mando_tv_mouse_dir_y = 0;
	    };

	    if (isNil "mando_tv_mouse_x") then
	    {
	       mando_tv_mouse_x = 0.5;
	    };
	    if (isNil "mando_tv_mouse_y") then
	    {
	       mando_tv_mouse_y = 0.5;
	    };


            if (mando_tv_mouse_dir_y != -1) then
	    {
               mando_tv_mouse_dir_y = -1;
               mando_tv_mouse_y = 0.5 + 0.0025;
	    };

	    if (mando_tv_mouse_y > 0.35) then
	    {
	       mando_tv_mouse_y = mando_tv_mouse_y - 0.0025;
               ["onMouseMoving", [displayNull, mando_tv_mouse_x, mando_tv_mouse_y,true]] call mando_missile_tv;
	    };
	 };

	 case 80: // KBN D
	 {
	    if (isNil "mando_tv_mouse_dir_y") then
	    {
	       mando_tv_mouse_dir_y = 0;
	    };

	    if (isNil "mando_tv_mouse_x") then
	    {
	       mando_tv_mouse_x = 0.5;
	    };
	    if (isNil "mando_tv_mouse_y") then
	    {
	       mando_tv_mouse_y = 0.5;
	    };

            if (mando_tv_mouse_dir_y != 1) then
	    {
               mando_tv_mouse_dir_y = 1;
               mando_tv_mouse_y = 0.5 - 0.0025;
	    };

	    if (mando_tv_mouse_y < 0.65) then
	    {
	       mando_tv_mouse_y = mando_tv_mouse_y + 0.0025;
               ["onMouseMoving", [displayNull, mando_tv_mouse_x, mando_tv_mouse_y,true]] call mando_missile_tv;
	    };
	 };




         default 
         {
// Down 80
// Up   72
// Left 75
// Right 77
// UR 73
// UL 71
// DR 81
// DL 79
// LOCK 76 
//            titleText [format["\n%1", _this], "PLAIN DOWN"];
         };
      };
   };   


   default {};
};

if (_event == "onKeyDown") then
{
   false
}
else
{
   true
};