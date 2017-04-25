/*********************************************************************************
   mando_airsupportdlg.sqf v1.7
   by Mandoble, March 2010

   Creates and handles the air support console. From this console you may order bomb runs against selected position in the map, or close air support missions where the planes will engage any not friendly vehicle, ship or static weapon within a range of 500m around the marked center.


   This script doesnt require parameters, you may execute it as action menu, from a trigger, etc.
   This script requires mando_bombs.sqf, mando_bombs_sadarm.sqf and mando_bombs_effects.sqf.

   This script uses the following set of global variables:
   mando_support_left_WEST: Maximum number of west planes available for bomb run or cas missions (default value is 8).
   mando_support_left_EAST: Maximum number of east planes available for bomb run or cas missions (default value is 8).
   mando_support_left_GUER: Maximum number of res planes available for bomb run or cas missions (default value is 8).
   mando_support_left_CIV: Maximum number of civ planes available for bomb run or cas missions (default value is 8).
   mando_support_left_ca_WEST: Maximum number of west chopper attacks (default value is 8).
   mando_support_left_ca_EAST: Maximum number of east chopper attacks (default value is 8).
   mando_support_left_ca_GUER: Maximum number of res chopper attacks (default value is 8).
   mando_support_left_ca_CIV: Maximum number of civ chopper attacks (default value is 8).
   mando_support_left_pa_WEST: Maximum number of west airborne chopper assaults (default value is 8).
   mando_support_left_pa_EAST: Maximum number of east airborne chopper assaults  (default value is 8).
   mando_support_left_pa_GUER: Maximum number of res airborne chopper assaults  (default value is 8).
   mando_support_left_pa_CIV: Maximum number of civ airborne chopper assaults  (default value is 8).
   mando_support_left_cm_WEST: Maximum number of west cruise missile attacks (default value is 8).
   mando_support_left_cm_EAST: Maximum number of east cruise missile attacks (default value is 8).
   mando_support_left_cm_GUER: Maximum number of res cruise missile attacks (default value is 8).
   mando_support_left_cm_CIV: Maximum number of civ cruise missile attacks (default value is 8).
   mando_support_left_rc_WEST: Maximum number of west reconnaissance missions (default value is 8).
   mando_support_left_rc_EAST: Maximum number of east reconnaissance missions (default value is 8).
   mando_support_left_rc_GUER: Maximum number of res reconnaissance missions (default value is 8).
   mando_support_left_rc_CIV: Maximum number of civ reconnaissance missions (default value is 8).
   mando_support_left_am_WEST: Maximum number of west ammo supply missions (default value is 8).
   mando_support_left_am_EAST: Maximum number of east ammo supply missions (default value is 8).
   mando_support_left_am_GUER: Maximum number of res ammo supply missions (default value is 8).
   mando_support_left_am_CIV: Maximum number of civ ammo supply missions (default value is 8).
   mando_support_left_ve_WEST: Maximum number of west vehicle supply missions (default value is 8).
   mando_support_left_ve_EAST: Maximum number of east vehicle supply missions (default value is 8).
   mando_support_left_ve_GUER: Maximum number of res vehicle supply missions (default value is 8).
   mando_support_left_ve_CIV: Maximum number of civ vehicle supply missions (default value is 8).
   mando_support_left_re_WEST: Maximum number of west reinforcement missions (default value is 8).
   mando_support_left_re_EAST: Maximum number of east reinforcement missions (default value is 8).
   mando_support_left_re_GUER: Maximum number of res reinforcement missions (default value is 8).
   mando_support_left_re_CIV: Maximum number of civ reinforcement missions (default value is 8).
   mando_support_left_cp_WEST: Maximum number of west CAP missions (default value is 8).
   mando_support_left_cp_EAST: Maximum number of east CAP missions (default value is 8).
   mando_support_left_cp_GUER: Maximum number of res CAP missions (default value is 8).
   mando_support_left_cp_CIV: Maximum number of civ CAP missions (default value is 8).
   mando_support_left_sa_WEST: Maximum number of west cruise missile saturation attacks (default value is 8).
   mando_support_left_sa_EAST: Maximum number of east cruise missile saturation attacks (default value is 8).
   mando_support_left_sa_GUER: Maximum number of res cruise missile saturation attacks (default value is 8).
   mando_support_left_sa_CIV: Maximum number of civ cruise missile saturation attacks (default value is 8).
   mando_support_left_ev_WEST: Maximum number of west evacuation missions (default value is 8).
   mando_support_left_ev_EAST: Maximum number of east evacuation missions (default value is 8).
   mando_support_left_ev_GUER: Maximum number of res evacuation missions (default value is 8).
   mando_support_left_ev_CIV: Maximum number of civ evacuation missions (default value is 8).
   mando_support_left_la_WEST: Maximum number of west laser bombs missions (default value is 8).
   mando_support_left_la_EAST: Maximum number of east laser bombs missions (default value is 8).
   mando_support_left_la_GUER: Maximum number of res laser bombs missions (default value is 8).
   mando_support_left_la_CIV: Maximum number of civ laset bombs missions (default value is 8).
   mando_support_left_cb_WEST: Maximum number of west carpet bombing missions (default value is 8).
   mando_support_left_cb_EAST: Maximum number of east carpet bombing missions (default value is 8).
   mando_support_left_cb_GUER: Maximum number of res carpet bombing missions (default value is 8).
   mando_support_left_cb_CIV: Maximum number of civ carpet bombing missions (default value is 8).

   mando_airsupport_carpetcode: Code global var with code for carpet bombing, receives plane and target position as arguments.

   mando_airsupport_type: type of plane for the missions (default value is "AV8B2" for west and "Su34" for east).
   mando_airsupport_type_ca: type of chopper for chopper attack missions (default value is "AH1Z" for west and "Ka52" for east).
   mando_airsupport_type_pa: type of chopper for airborne assault jump missions (default value is "MH60S" for west and "Mi17_rockets_RU" for east).
   mando_airsupport_type_pal: type of chopper for airborne assault landing missions (default value is "MH60S" for west and "Mi17_rockets_RU" for east).

   mando_airsupport_type_rc: type of plane or chopper for reconnaissance missions (default is "AV8B" for west and "Su34" for east).
   mando_airsupport_type_ev: type of chopper for evacuation missions (default is "MH60S" for west and "Mi17_rockets_RU" for east).
   mando_airsupport_type_la: type of plane for laser bombs missions (default is "AV8B" for west and "Su34" for east).
   mando_airsupport_type_am: type of chopper for ammo supply missions (default value is "MH60S" for west and "Mi17_rockets_RU" for east).
   mando_airsupport_type_ambox: ammo box type to be used in ammo supply missions, default is "USBasicWeaponsBox" for west, etc.
   mando_airsupport_type_ve: type of chopper for vehicle supply missions (default value is "MH60S" for west and "Mi17_rockets_RU" for east).
   mando_airsupport_type_vehicle: vehicle type to be used in vehicle supply missions, default is "MTVR" for west, etc.
   mando_support_infantrytype: Array defining soldier classes for airborne assaults.
   mando_support_infantrytype_re: Array defining soldier classes for reinforcements missions.
   mando_airsupport_type_cp: type of plane or chopper for CAP missions (default is "AV8B" for west and "Su34" for east).
   mando_airsupport_type_cb: type of plane for carpet bombing missions (default is "AV8B" for west and "Su34" for east).

   mando_airsupport_code_cas: If defined, executed when a cas/br mission is created, receives first plane's crew group as argument
   mando_airsupport_code_ca: If defined, executed when gunship mission is created, receives crew group as argument
   mando_airsupport_code_pa: If defined, executed when airborne assault mission is created, receives crew group and infantry group as argument
   mando_airsupport_code_rc: If defined, executed when reco mission is created, receives crew group as argument
   mando_airsupport_code_ev: If defined, executed when evac mission is created, receives crew group as argument
   mando_airsupport_code_am: If defined, executed when ammo supply mission is created, receives crew group as argument
   mando_airsupport_code_ve: If defined, executed when vehicle supply mission is created, receives crew group as argument
   mando_airsupport_code_re: If defined, executed when reinforcements mission is created, receives crew group and infantry group as arguments
   mando_airsupport_code_la: If defined, executed when laser mission is created, receives crew group as argument
   mando_airsupport_code_cp: If defined, executed when CAP mission is created, receives crew group as argument
   mando_airsupport_code_cb: If defined, executed when carpet bombing mission is created, receives crew group as argument


   mando_airsupport_range: Range from target where the planes will be spawned (default and minimum value is 4500).
   mando_airsupport_range_he: Range from target where the choppers will be spawned (default and minimum value is 4500).
   mando_airsupport_fixedpos: If defined, fixed spawn initial pos for support missions

   mando_airsupport_max_cas: In close air support, maximum number of attacks per plane (default value is 2).
   mando_airsupport_bomb_type: The class of a bomb type ammo or the special type "SADARM". "Bo_GBU12_LGB" is used by default.
   mando_airsupport_bomb_alt: The base flying altitude for the bomb runs in m, default value is 150.
   mando_airsupport_bomb_altmax: The maximum base flying altitude for the bomb runs or reco in m, default value is 400, max is 1000.
   mando_airsupport_bomb_pos: Model coords position of a bomb spawned relative to the plane (the second bomb will be spawned at the opposite side). [2, 0, -2] by default.
   mando_airsupport_cmissile: Cruise missile launcher (requires mando missile initialized), default value is objNull.
   mando_airsupport_cmissile_pos = Model coordinates of the cruise missile launch position.
   mando_airsupport_cmissile_alt = cruise altitude for cruise missiles flying in inertial mode, default is 800m.

   mando_support_ingress_limits = Array with angles limiting the ingress arc [min, max], by default [-180,180] (any direction).
   mando_ingress_dir = Initial ingrees dir, between defined ingress limits, by default the half of the limits defined range.
   mando_reco_cam_filter = array [R,G,B,A] for reconnaissance and missile camera color filter, by default [0,0,0,0]
   mando_reco_cam_pos = model coordinates of reconnaissance camera, by default [0,3,-2]
   mando_last_plane_cam_pos = model coordinates of last mission plane camera (except reco), by default [0,1,-2.5]

   mando_no_default_map = if true, default map click behaviour will be disabled (overrides any onMapSingleClick active code, default is false).

   mando_airsupport_planes_delay = number of seconds after any mission activation (except missiles) to wait until the option is enabled again (default is 4).
   mando_airsupport_missile_delay = number of seconds after cruise missile attack to wait until the option is enabled again (default is 15).

   mando_support_enemy_sides = array of enemy sides for laser and gun ships support armed with mando missiles. (default = [east] for west, resistance and civilian players, [west] for east players.


   mando_airsupport_magz = array of pairs of [mag class, quantity] in case you want to change the default content of ammo boxes.
   mando_airsupport_weap = array of pairs of [weapon class, quantity] in case you want to change the default content of ammo boxes.

   mando_airsupport_re_switchable  = true if reinforcement units will be switchable/playable (default value is false).
   mando_airsupport_ab_switchable  = true if airborne assault units will be switchable/playable (default value is false).
   mando_airsupport_ab_action = code var receiving airborne assault group as argument, executed when infantry group is created.
   mando_airsupport_re_action = code var receiving reinforcements group as argument, executed when infantry group is created.


   mando_airsupport_armedrec = true if player can use reconnaissance planes to attack targets (requires mando missile), default value is false.
   mando_airsupport_armedrec_man = true if missiles fired from armed reco plane will have manual (TV) guidance, default is false
   mando_airsupport_rec_captive = true will set reconnaissance pilot captive (default is false).

   mando_airsupport_armedrec_max = number of attacks allowed per reco plane (requires mando missile), default value is 4.
   mando_airsupport_maxrecoscan = max distance to scan with camera (default value is 1500m).

   mando_airsupport_cams = read only array with the planes of the mission leaders currently flying commanded from this console.  (you may copy its content to a global per side and then publish it periodically so that other players might have remote cams for these planes)

   mando_airsupport_jump = true for JUMP, false for LAND (applies to reinforcements and airborne assault missions).

   mando_airsupport_nocomms = if set to 1, comms will not work and the console will become useless, default value is 0.
   mando_support_side = side for the console, if not defined it will be equal to side player
   mando_airsupport_info = Structured text with info that is displayed in the config/info dialog.
   mando_airsupport_opt1_text = Simple text for info/setup listbox1
   mando_airsupport_opt1_array = Array of texts for info/setup listbox1 contents
   mando_airsupport_opt1_action = Code variable with opt1 action when selected item changes (receives item text as argument)
   mando_airsupport_opt2_text = Simple text for info/setup listbox2
   mando_airsupport_opt2_array = Array of texts for info/setup listbox2 contents
   mando_airsupport_opt2_action = Code variable with opt2 action when selected item changes (receives item text as argument)
   mando_airsupport_opt3_text = Simple text for info/setup listbox3
   mando_airsupport_opt3_array = Array of texts for info/setup listbox3 contents
   mando_airsupport_opt3_action = Code variable with opt3 action when selected item changes (receives item text as argument)
   mando_airsupport_opt4_text = Simple text for info/setup listbox4
   mando_airsupport_opt4_array = Array of texts for info/setup listbox4 contents
   mando_airsupport_opt4_action = Code variable with opt4 action when selected item changes (receives item text as argument)
   mando_airsupport_opt5_text = Simple text for info/setup listbox5
   mando_airsupport_opt5_array = Array of texts for info/setup listbox5 contents
   mando_airsupport_opt5_action = Code variable with opt5 action when selected item changes (receives item text as argument)


   The following variables set to true disable corresponding buttons
   mando_support_no_cas: Disables Close Air Support button.
   mando_support_no_br: Disables Bomb run button.
   mando_support_no_ff: Disables Free fall bombs button.
   mando_support_no_sa: Disables SADARM button.
   mando_support_no_gs: Disables Gunships Support button.
   mando_support_no_ab: Disables Airborne assault button.
   mando_support_no_cm: Disables Cruise missile attack button.
   mando_support_no_sat: Disables Cruise missile saturation attack button.
   mando_support_no_rc: Disables reconnaissance button.
   mando_support_no_ev: Disables evacuation button.
   mando_support_no_la: Disables laser bombs button.
   mando_support_no_am: Disables ammo supply button.
   mando_support_no_ve: Disables vehicle supply button.
   mando_support_no_re: Disables Airborne reinforcements button.
   mando_support_no_cp: Disables Combat Air Patrol button.
   mando_support_no_cb: Disables carpet bombing button.


   The following variables may be set to radio resources to have radio chat messages.
   mando_console_radio_delay -> Delay in seconds between request and reply, by default 4.
   mando_radio_req_cas -> Request for CAS
   mando_radio_rep_cas -> Reply from CAS
   mando_radio_req_br -> Request for bomb run
   mando_radio_rep_br -> Reply from bomb run
   mando_radio_req_gs -> Request for gunships
   mando_radio_rep_gs -> Reply from gunships
   mando_radio_req_ab -> Request for airborne assault
   mando_radio_rep_ab -> Reply from airborne assault
   mando_radio_repr_ab -> Reply from airborne assault ready
   mando_radio_req_cm -> Request for cruise missile
   mando_radio_rep_cm -> Reply from cruise missile
   mando_radio_req_sa -> Request for saturation
   mando_radio_rep_sa -> Reply from saturation
   mando_radio_req_am -> Request for ammo supply
   mando_radio_rep_am -> Reply from ammo supply otw
   mando_radio_repr_am -> Reply from ammo supply ready
   mando_radio_req_ve -> Request for vehicle supply
   mando_radio_rep_ve -> Reply from vehicle supply otw
   mando_radio_repr_ve -> Reply from vehicle supply ready
   mando_radio_req_re -> Request for reinforcements
   mando_radio_rep_re -> Reply from reinforcements otw
   mando_radio_repr_re -> Reply from reinforcements ready
   mando_radio_req_cp -> Request for CAP
   mando_radio_rep_cp -> Reply from CAP otw
   mando_radio_req_rc -> Request for reconnaissance
   mando_radio_rep_rc -> Reply from reconnaissance otw
   mando_radio_req_ev -> Request for evacuation
   mando_radio_rep_ev -> Reply from evacuation otw
   mando_radio_repr_ev -> Reply from evacuation ready
   mando_radio_req_la -> Request for laser bombs
   mando_radio_rep_la -> Reply from laser bombs otw
   mando_radio_req_cb -> Request for carpet bombing
   mando_radio_rep_cb -> Reply from carpet bombing otw


   Before executing this script you may set the desired values for the previous variables, if you dont, default values will be used.

   Example:
   player addAction ["MMA Air Support console", "mando_missiles\mando_bombs\mando_airsupportdlg.sqf"];

   or
  
   []execVM"mando_missiles\mando_bombs\mando_airsupportdlg.sqf";

*********************************************************************************/

disableSerialization;

if (isNil "mando_console_switch") then
{
   mando_console_switch = 
   {
      private["_pos", "_i", "_ctrl", "_exclude"];
      _exclude = [23932,23938,23903,23939,23940,23942,23943,23946,23948,23949,23950,23951,23952,23953,23954,23959,23960,23962,23963];
      mando_console_pos = -mando_console_pos;
      for [{_i=23901},{_i<24000},{_i=_i+1}] do
      {
         if (!(_i in _exclude)) then
         {
            _ctrl = ((findDisplay 23900) displayCtrl _i);

            _pos = ctrlPosition _ctrl;
            _ctrl ctrlSetPosition [_pos select 0, (_pos select 1)+mando_console_pos, _pos select 2, _pos select 3];
         };

         _ctrl ctrlCommit 0;
      };
   };
};

if (isNil "MandoWorldToScreen2") then
{
   MandoWorldToScreen2 = 
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


private ["_event", "_params", "_display", "_i", "_nplanes", "_left", "_first", "_reco", "_marker_name"];

_first = false;
_reco  = false;
if (count _this == 0) then
{
   _first = true;
}
else
{
   if (typeName (_this select 0) != "STRING") then
   {
      if (typeName (_this select 0) == "BOOL") then
      {
         _reco = true;
      }
      else
      {
         _first = true;
      };
   }
   else
   {      
      _event = _this select 0;
      _params = _this select 1;
   };
};


if (isNil "mando_support_side") then
{
   mando_support_side = side player;
};


if (_reco) exitWith
{
   if (isNil "mando_reco_monitor") then
   {
      mando_reco_monitor = true;
      mando_reco_base = 0;
      mando_reco_num = 0;
      mando_reco_side = west;
      mando_reco_numrcm = -1;
      []spawn
      {
         disableSerialization;
         private["_num", "_side", "_base"];
         while {true} do
         {
            waitUntil {mando_reco_num != 0};
            _num = mando_reco_num;
            _side = mando_reco_side;
            _base = mando_reco_base; 
            mando_reco_num = 0;

            if (side player == _side) then
            {
               [_num, _side, _base] spawn
               {
                  disableSerialization;
                  private["_num", "_side", "_base", "_i", "_marker", "_pos", "_text"];
                  _num = _this select 0;
                  _side = _this select 1; 
                  _base = _this select 2;
                  [_side, "HQ"] sideChat "Receiving reconnaissance info";
                  for [{_i=0},{_i != _num},{_i = _i + 1}] do
                  {
                     _pos = markerPos format["mk_mando_rct_%1", _i + _base];
                     _text = markerText format["mk_mando_rct_%1", _i + _base];
                     _marker = createMarkerLocal [format["mk_mando_rctr_%1", _i + _base], _pos];
                     format["mk_mando_rctr_%1", _i + _base] setMarkerTypeLocal "Dot";
                     format["mk_mando_rctr_%1", _i + _base] setMarkerColorLocal "ColorWhite";
                     format["mk_mando_rctr_%1", _i + _base] setMarkerSizeLocal [0.25, 0.25];
                     format["mk_mando_rctr_%1", _i + _base] setMarkerTextLocal _text;
                     Sleep 0.25;
                  };
                  Sleep 120;
                  for [{_i=0},{_i != _num},{_i = _i + 1}] do
                  {
                     deleteMarkerLocal format["mk_mando_rctr_%1", _i + _base];
                  };               
               };
            }; 
         };
      };

      []spawn
      {
         disableSerialization;
         private["_num", "_side","_marker"];
         while {true} do
         {
            waitUntil {mando_reco_numrcm != -1};
            _num = mando_reco_numrcm;
            _side = mando_reco_side_rcm;
            mando_reco_numrcm = -1;

            if (side player == _side) then
            {               
               if (getMarkerColor format["mk_mandoairsupport_reco_%1",_num] != "ColorWhite") then
               {
                  _marker = createMarkerLocal [format["mk_mandoairsupport_reco_%1",_num], [mando_reco_x_rcm,mando_reco_y_rcm]];
                  format["mk_mandoairsupport_reco_%1",_num] setMarkerTypeLocal "Flag";
                  format["mk_mandoairsupport_reco_%1",_num] setMarkerColorLocal "ColorWhite";
                  format["mk_mandoairsupport_reco_%1",_num] setMarkerSizeLocal [0.25, 0.25];
                  format["mk_mandoairsupport_reco_%1",_num] setMarkerTextLocal format["RCM_%1", _num];
               }
               else
               {
                  format["mk_mandoairsupport_reco_%1",_num] setMarkerPosLocal [mando_reco_x_rcm,mando_reco_y_rcm];
               };
            }; 
         };
      };
   };
};


if (_first) exitWith
{
   mando_rec_flir = false;

   if (isNil "mando_airsupport_nocomms") then
   {
      mando_airsupport_nocomms = 0;
   };

   if (isNil "mando_last_plane_text") then
   {
      mando_last_plane_text = "";
   };

   if (isNil "mando_airsupport_info") then
   {
      mando_airsupport_info = "No additional info available for this mission";
   };

   if (isNil "mando_airsupport_opt1_text") then
   {
      mando_airsupport_opt1_text = "No options";
   };

   if (isNil "mando_airsupport_opt1_array") then
   {
      mando_airsupport_opt1_array = [];
   };

   if (isNil "mando_airsupport_opt1_action") then
   {
      mando_airsupport_opt1_action = {};
   };

   if (isNil "mando_airsupport_opt1_selected") then
   {
      mando_airsupport_opt1_selected = "";
   };

   if (isNil "mando_airsupport_opt2_text") then
   {
      mando_airsupport_opt2_text = "No options";
   };

   if (isNil "mando_airsupport_opt2_array") then
   {
      mando_airsupport_opt2_array = [];
   };

   if (isNil "mando_airsupport_opt2_action") then
   {
      mando_airsupport_opt2_action = {};
   };

   if (isNil "mando_airsupport_opt2_selected") then
   {
      mando_airsupport_opt2_selected = "";
   };

   if (isNil "mando_airsupport_opt3_text") then
   {
      mando_airsupport_opt3_text = "No options";
   };

   if (isNil "mando_airsupport_opt3_array") then
   {
      mando_airsupport_opt3_array = [];
   };

   if (isNil "mando_airsupport_opt3_action") then
   {
      mando_airsupport_opt3_action = {};
   };

   if (isNil "mando_airsupport_opt3_selected") then
   {
      mando_airsupport_opt3_selected = "";
   };

   if (isNil "mando_airsupport_opt4_text") then
   {
      mando_airsupport_opt4_text = "No options";
   };

   if (isNil "mando_airsupport_opt4_array") then
   {
      mando_airsupport_opt4_array = [];
   };

   if (isNil "mando_airsupport_opt4_action") then
   {
      mando_airsupport_opt4_action = {};
   };

   if (isNil "mando_airsupport_opt4_selected") then
   {
      mando_airsupport_opt4_selected = "";
   };

   if (isNil "mando_airsupport_opt5_text") then
   {
      mando_airsupport_opt5_text = "No options";
   };

   if (isNil "mando_airsupport_opt5_array") then
   {
      mando_airsupport_opt5_array = [];
   };

   if (isNil "mando_airsupport_opt5_action") then
   {
      mando_airsupport_opt5_action = {};
   };

   if (isNil "mando_airsupport_opt5_selected") then
   {
      mando_airsupport_opt5_selected = "";
   };

   if (isNil "mando_airsupport_ab_action") then
   {
      mando_airsupport_ab_action = {};
   };

   if (isNil "mando_airsupport_re_action") then
   {
      mando_airsupport_re_action = {};
   };

   if (isNil "mando_airsupport_jump") then
   {
      mando_airsupport_jump = true;
   };

   if (isNil "mando_support_lastpos") then
   {
      mando_support_lastpos = [0,0];
   };

   if (isNil "mando_console_radio_delay") then
   {
      mando_console_radio_delay = 4;
   };

   if (isNil "mando_airsupport_cmissile_alt") then
   {
      mando_airsupport_cmissile_alt = 800;
   };

   if (isNil "mando_airsupport_rec_captive") then
   {
      mando_airsupport_rec_captive = false;
   };

   if (isNil "mando_support_left_WEST") then
   {
      mando_support_left_WEST = 8;
   };

   if (isNil "mando_support_left_EAST") then
   {
      mando_support_left_EAST = 8;
   };

   if (isNil "mando_support_left_GUER") then
   {
      mando_support_left_GUER = 8;
   };

   if (isNil "mando_support_left_CIV") then
   {
      mando_support_left_CIV = 8;
   };

   if (isNil "mando_support_left_ca_WEST") then
   {
      mando_support_left_ca_WEST = 8;
   };

   if (isNil "mando_support_left_ca_EAST") then
   {
      mando_support_left_ca_EAST = 8;
   };

   if (isNil "mando_support_left_ca_GUER") then
   {
      mando_support_left_ca_GUER = 8;
   };

   if (isNil "mando_support_left_ca_CIV") then
   {
      mando_support_left_ca_CIV = 8;
   };

   if (isNil "mando_support_left_pa_WEST") then
   {
      mando_support_left_pa_WEST = 8;
   };

   if (isNil "mando_support_left_pa_EAST") then
   {
      mando_support_left_pa_EAST = 8;
   };

   if (isNil "mando_support_left_pa_GUER") then
   {
      mando_support_left_pa_GUER = 8;
   };

   if (isNil "mando_support_left_pa_CIV") then
   {
      mando_support_left_pa_CIV = 8;
   };

   if (isNil "mando_support_left_cm_WEST") then
   {
      mando_support_left_cm_WEST = 8;
   };

   if (isNil "mando_support_left_cm_EAST") then
   {
      mando_support_left_cm_EAST = 8;
   };

   if (isNil "mando_support_left_cm_GUER") then
   {
      mando_support_left_cm_GUER = 8;
   };

   if (isNil "mando_support_left_cm_CIV") then
   {
      mando_support_left_cm_CIV = 8;
   };

   if (isNil "mando_support_left_sa_WEST") then
   {
      mando_support_left_sa_WEST = 8;
   };

   if (isNil "mando_support_left_sa_EAST") then
   {
      mando_support_left_sa_EAST = 8;
   };

   if (isNil "mando_support_left_sa_GUER") then
   {
      mando_support_left_sa_GUER = 8;
   };

   if (isNil "mando_support_left_sa_CIV") then
   {
      mando_support_left_sa_CIV = 8;
   };

   if (isNil "mando_support_left_rc_WEST") then
   {
      mando_support_left_rc_WEST = 8;
   };

   if (isNil "mando_support_left_rc_EAST") then
   {
      mando_support_left_rc_EAST = 8;
   };

   if (isNil "mando_support_left_rc_GUER") then
   {
      mando_support_left_rc_GUER = 8;
   };

   if (isNil "mando_support_left_rc_CIV") then
   {
      mando_support_left_rc_CIV = 8;
   };

   if (isNil "mando_support_left_ev_WEST") then
   {
      mando_support_left_ev_WEST = 8;
   };

   if (isNil "mando_support_left_ev_EAST") then
   {
      mando_support_left_ev_EAST = 8;
   };

   if (isNil "mando_support_left_ev_GUER") then
   {
      mando_support_left_ev_GUER = 8;
   };

   if (isNil "mando_support_left_ev_CIV") then
   {
      mando_support_left_ev_CIV = 8;
   };

   if (isNil "mando_support_left_la_WEST") then
   {
      mando_support_left_la_WEST = 8;
   };

   if (isNil "mando_support_left_la_EAST") then
   {
      mando_support_left_la_EAST = 8;
   };

   if (isNil "mando_support_left_la_GUER") then
   {
      mando_support_left_la_GUER = 8;
   };

   if (isNil "mando_support_left_la_CIV") then
   {
      mando_support_left_la_CIV = 8;
   };

   if (isNil "mando_support_left_cb_WEST") then
   {
      mando_support_left_cb_WEST = 8;
   };

   if (isNil "mando_support_left_cb_EAST") then
   {
      mando_support_left_cb_EAST = 8;
   };

   if (isNil "mando_support_left_cb_GUER") then
   {
      mando_support_left_cb_GUER = 8;
   };

   if (isNil "mando_support_left_cb_CIV") then
   {
      mando_support_left_cb_CIV = 8;
   };


   if (isNil "mando_support_left_am_WEST") then
   {
      mando_support_left_am_WEST = 8;
   };

   if (isNil "mando_support_left_am_EAST") then
   {
      mando_support_left_am_EAST = 8;
   };

   if (isNil "mando_support_left_am_GUER") then
   {
      mando_support_left_am_GUER = 8;
   };

   if (isNil "mando_support_left_am_CIV") then
   {
      mando_support_left_am_CIV = 8;
   };

   if (isNil "mando_support_left_ve_WEST") then
   {
      mando_support_left_ve_WEST = 8;
   };

   if (isNil "mando_support_left_ve_EAST") then
   {
      mando_support_left_ve_EAST = 8;
   };

   if (isNil "mando_support_left_ve_GUER") then
   {
      mando_support_left_ve_GUER = 8;
   };

   if (isNil "mando_support_left_ve_CIV") then
   {
      mando_support_left_ve_CIV = 8;
   };

   if (isNil "mando_support_left_re_WEST") then
   {
      mando_support_left_re_WEST = 8;
   };

   if (isNil "mando_support_left_re_EAST") then
   {
      mando_support_left_re_EAST = 8;
   };

   if (isNil "mando_support_left_re_GUER") then
   {
      mando_support_left_re_GUER = 8;
   };

   if (isNil "mando_support_left_re_CIV") then
   {
      mando_support_left_re_CIV = 8;
   };

   if (isNil "mando_support_left_cp_WEST") then
   {
      mando_support_left_cp_WEST = 8;
   };

   if (isNil "mando_support_left_cp_EAST") then
   {
      mando_support_left_cp_EAST = 8;
   };

   if (isNil "mando_support_left_cp_GUER") then
   {
      mando_support_left_cp_GUER = 8;
   };

   if (isNil "mando_support_left_cp_CIV") then
   {
      mando_support_left_cp_CIV = 8;
   };


   {publicVariable _x} forEach ["mando_support_left_WEST", "mando_support_left_EAST","mando_support_left_GUER","mando_support_left_CIV","mando_support_left_ca_WEST", "mando_support_left_ca_EAST","mando_support_left_ca_GUER","mando_support_left_ca_CIV","mando_support_left_pa_WEST", "mando_support_left_pa_EAST","mando_support_left_pa_GUER","mando_support_left_pa_CIV","mando_support_left_cm_WEST", "mando_support_left_cm_EAST","mando_support_left_cm_GUER","mando_support_left_cm_CIV","mando_support_left_rc_WEST", "mando_support_left_rc_EAST","mando_support_left_rc_GUER","mando_support_left_rc_CIV","mando_support_left_am_WEST", "mando_support_left_am_EAST","mando_support_left_am_GUER","mando_support_left_am_CIV","mando_support_left_ve_WEST", "mando_support_left_ve_EAST","mando_support_left_ve_GUER","mando_support_left_ve_CIV","mando_support_left_re_WEST", "mando_support_left_re_EAST","mando_support_left_re_GUER","mando_support_left_re_CIV","mando_support_left_cp_WEST", "mando_support_left_cp_EAST","mando_support_left_cp_GUER","mando_support_left_cp_CIV","mando_support_left_sa_WEST", "mando_support_left_sa_EAST","mando_support_left_sa_GUER","mando_support_left_sa_CIV","mando_support_left_ev_WEST", "mando_support_left_ev_EAST","mando_support_left_ev_GUER","mando_support_left_ev_CIV","mando_support_left_la_WEST", "mando_support_left_la_EAST","mando_support_left_la_GUER","mando_support_left_la_CIV","mando_support_left_cb_WEST", "mando_support_left_cb_EAST","mando_support_left_cb_GUER","mando_support_left_cb_CIV"];

   if (isNil "mando_airsupport_cmissile") then
   {
      mando_airsupport_cmissile = objNull;
   };


   if (isNil "mando_no_default_map") then
   {
      mando_no_default_map = false;
   };


   if (isNil "mando_airsupport_type") then
   {
      if (mando_support_side != east) then
      {
         mando_airsupport_type = "AV8B2";      
      }
      else
      {
         mando_airsupport_type = "Su34";
      };
   };

   if (isNil "mando_airsupport_type_ca") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_ca = "Mi24_D";
         }
         else
         {
            mando_airsupport_type_ca = "AH1Z";
         };
      }
      else
      {
         mando_airsupport_type_ca = "Ka52";
      };
   };

   if (isNil "mando_airsupport_type_pa") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_pa = "MH60S";
         }
         else
         {
            mando_airsupport_type_pa = "MH60S";
         };
      }
      else
      {
         mando_airsupport_type_pa = "Mi17_rockets_RU";
      };
   };

   if (isNil "mando_airsupport_type_pal") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_pal = "MH60S";
         }
         else
         {
            mando_airsupport_type_pal = "MH60S";
         };
      }
      else
      {
         mando_airsupport_type_pal = "Mi17_rockets_RU";
      };
   };


   if (isNil "mando_airsupport_type_rc") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_rc = "AV8B";
         }
         else
         {
            mando_airsupport_type_rc = "AV8B";
         };
      }
      else
      {
         mando_airsupport_type_rc = "Su34";
      };
   };

   if (isNil "mando_airsupport_type_ev") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_ev = "MH60S";
         }
         else
         {
            mando_airsupport_type_ev = "MH60S";
         };
      }
      else
      {
         mando_airsupport_type_ev = "Mi17_rockets_RU";
      };
   };

   if (isNil "mando_airsupport_type_la") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_la = "AV8B";
         }
         else
         {
            mando_airsupport_type_la = "AV8B";
         };
      }
      else
      {
         mando_airsupport_type_la = "Su34";
      };
   };


   if (isNil "mando_airsupport_type_cb") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_cb = "AV8B";
         }
         else
         {
            mando_airsupport_type_cb = "AV8B";
         };
      }
      else
      {
         mando_airsupport_type_cb = "Su34";
      };
   };


   if (isNil "mando_airsupport_type_cp") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_cp = "AV8B";
         }
         else
         {
            mando_airsupport_type_cp = "AV8B";
         };
      }
      else
      {
         mando_airsupport_type_cp = "Su34";
      };
   };


   if (isNil "mando_airsupport_type_am") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_am = "MH60S";
         }
         else
         {
            mando_airsupport_type_am = "MH60S";
         };
      }
      else
      {
         mando_airsupport_type_am = "Mi17_rockets_RU";
      };
   };

   if (isNil "mando_airsupport_type_ambox") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_ambox = "LocalBasicWeaponsBox";
         }
         else
         {
            mando_airsupport_type_ambox = "USBasicWeaponsBox";
         };
      }
      else
      {
         mando_airsupport_type_ambox = "RUBasicWeaponsBox";
      };
   };

   if (isNil "mando_airsupport_type_ve") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_ve = "MH60S";
         }
         else
         {
            mando_airsupport_type_ve = "MH60S";
         };
      }
      else
      {
         mando_airsupport_type_ve = "Mi17_rockets_RU";
      };
   };

   if (isNil "mando_airsupport_type_vehicle") then
   {
      if (mando_support_side != east) then
      {
         if (mando_support_side == resistance) then
         {
            mando_airsupport_type_vehicle = "MTVR";
         }
         else
         {
            mando_airsupport_type_vehicle = "MTVR";
         };
      }
      else
      {
         mando_airsupport_type_vehicle = "Kamaz";
      };
   };


   if (isNil "mando_support_infantrytype") then
   {
      switch (mando_support_side) do
      {
         case west:
         {
            mando_support_infantrytype = ["USMC_Soldier_TL", "USMC_Soldier_Medic", "USMC_Soldier_AT","USMC_Soldier","USMC_Soldier","USMC_Soldier","USMC_Soldier","USMC_Soldier","USMC_Soldier","USMC_Soldier"];
         };

         case east:
         {
            mando_support_infantrytype = ["RU_Soldier_TL", "RU_Soldier_Medic", "RU_Soldier_AT","RU_Soldier","RU_Soldier","RU_Soldier","RU_Soldier","RU_Soldier","RU_Soldier","RU_Soldier"];
         };

         case resistance:
         {
            mando_support_infantrytype = ["Ins_Soldier_GL", "Ins_Soldier_Medic", "Ins_Soldier_AT","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1"];
         };

         case civilian:
         {
            mando_support_infantrytype = ["Worker1", "Worker2","Worker3","Worker4","Worker3","Worker2","Worker1","Worker2","Worker3","Worker4"];
         };
      };
   };


   if (isNil "mando_support_infantrytype_re") then
   {
      switch (mando_support_side) do
      {
         case west:
         {
            mando_support_infantrytype_re = ["USMC_Soldier_TL", "USMC_Soldier_Medic", "USMC_Soldier_AT","USMC_Soldier","USMC_Soldier","USMC_Soldier","USMC_Soldier","USMC_Soldier","USMC_Soldier","USMC_Soldier"];
         };

         case east:
         {
            mando_support_infantrytype_re = ["RU_Soldier_TL", "RU_Soldier_Medic", "RU_Soldier_AT","RU_Soldier","RU_Soldier","RU_Soldier","RU_Soldier","RU_Soldier","RU_Soldier","RU_Soldier"];
         };

         case resistance:
         {
            mando_support_infantrytype_re = ["Ins_Soldier_GL", "Ins_Soldier_Medic", "Ins_Soldier_AT","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1","Ins_Soldier_1"];
         };

         case civilian:
         {
            mando_support_infantrytype_re = ["Worker1", "Worker2","Worker3","Worker4","Worker3","Worker2","Worker1","Worker2","Worker3","Worker4"];
         };
      };
   };


   if (isNil "mando_airsupport_weap") then
   {
      mando_airsupport_weap = [];
   };

   if (isNil "mando_airsupport_magz") then
   {
      mando_airsupport_magz = [];
   };


   if (isNil "mando_support_enemy_sides") then
   {
      switch (mando_support_side) do
      {
         case west:
         {
            mando_support_enemy_sides = [east, sideEnemy];
         };

         case east:
         {
            mando_support_enemy_sides = [west, sideEnemy];
         };

         case resistance:
         {
            mando_support_enemy_sides = [east, sideEnemy];
         };

         case civilian:
         {
            mando_support_enemy_sides = [east, sideEnemy];
         };
      };
   };


   if (isNil "mando_airsupport_range") then
   {
      mando_airsupport_range = 4500;
   } 
   else
   {
      if (mando_airsupport_range < 4500) then
      { 
         mando_airsupport_range = 4500;
      }; 
   };

   if (isNil "mando_airsupport_range_he") then
   {
      mando_airsupport_range_he = mando_airsupport_range;
   } 
   else
   {
      if (mando_airsupport_range_he < 4500) then
      { 
         mando_airsupport_range_he = 4500;
      }; 
   };


   if (isNil "mando_airsupport_max_cas") then
   {
      mando_airsupport_max_cas = 2;
   };

   if (isNil "mando_airsupport_bomb_type") then
   {
      mando_airsupport_bomb_type = "Bo_GBU12_LGB";
   };

   if (isNil "mando_airsupport_bomb_altmax") then
   {
      mando_airsupport_bomb_altmax = 400;
   }
   else
   {
      if (mando_airsupport_bomb_altmax > 1000) then
      {
         mando_airsupport_bomb_alt = 1000;
      };
   };

   if (isNil "mando_airsupport_bomb_alt") then
   {
      mando_airsupport_bomb_alt = 150;
   }
   else
   {
      if (mando_airsupport_bomb_alt > mando_airsupport_bomb_altmax) then
      {
         mando_airsupport_bomb_alt = mando_airsupport_bomb_altmax;
      };
   };


   if (isNil "mando_airsupportdlg") then
   {
      mando_airsupportdlg = compile (preprocessFileLineNumbers "mando_missiles\mando_bombs\mando_airsupportdlg.sqf");
      mando_airsupportdlgsetup = compile (preprocessFileLineNumbers "mando_missiles\mando_bombs\mando_airsupportdlgsetup.sqf");
   };

   if (isNil "mando_airsupport_bomb_pos") then
   {
      mando_airsupport_bomb_pos = [2, 0, -2];
   };

   if (isNil "mando_support_no_cas") then
   {
      mando_support_no_cas = false;
   };

   if (isNil "mando_support_no_br") then
   {
      mando_support_no_br = false;
   };

   if (isNil "mando_support_no_ff") then
   {
      mando_support_no_ff = false;
   };

   if (isNil "mando_support_no_sa") then
   {
      mando_support_no_sa = false;
   };

   if (isNil "mando_support_no_gs") then
   {
      mando_support_no_gs = false;
   };

   if (isNil "mando_support_no_ab") then
   {
      mando_support_no_ab = false;
   };

   if (isNil "mando_support_no_cm") then
   {
      mando_support_no_cm = false;
   };

   if (isNil "mando_support_no_sat") then
   {
      mando_support_no_sat = false;
   };

   if (isNil "mando_support_no_rc") then
   {
      mando_support_no_rc = false;
   };

   if (isNil "mando_support_no_ev") then
   {
      mando_support_no_ev = false;
   };

   if (isNil "mando_support_no_la") then
   {
      mando_support_no_la = false;
   };

   if (isNil "mando_support_no_cb") then
   {
      mando_support_no_cb = false;
   };


   if (isNil "mando_support_no_am") then
   {
      mando_support_no_am = false;
   };

   if (isNil "mando_support_no_ve") then
   {
      mando_support_no_ve = false;
   };

   if (isNil "mando_support_no_re") then
   {
      mando_support_no_re = false;
   };

   if (isNil "mando_support_no_cp") then
   {
      mando_support_no_cp = false;
   };

   if (isNil "mando_support_ingress_limits") then
   {
      mando_support_ingress_limits = [-180, 180];
   };

   if (isNil "mando_reco_cam_filter") then
   {
      mando_reco_cam_filter = [0,0,0,0];
   };

   if (isNil "mando_reco_cam_pos") then
   {
      mando_reco_cam_pos = [0,3,-2];
   };

   if (isNil "mando_last_plane_cam_pos") then
   {
      mando_last_plane_cam_pos = [0,1,-2.3];
   };

   if (isNil "mando_num_reco_marks") then
   {
      mando_num_reco_marks = 0;
   };

   if (isNil "mando_airsupport_planes_delay") then
   {
      mando_airsupport_planes_delay = 4;
   };

   if (isNil "mando_airsupport_missile_delay") then
   {
      mando_airsupport_missile_delay = 15;
   };


   if (isNil "mando_airsupport_ab_switchable") then
   {
      mando_airsupport_ab_switchable = false;
   };

   if (isNil "mando_airsupport_re_switchable") then
   {
      mando_airsupport_re_switchable = false;
   };

   if (isNil "mando_airsupport_armedrec") then
   {
      mando_airsupport_armedrec = false;
   };

   if (isNil "mando_airsupport_armedrec_man") then
   {
      mando_airsupport_armedrec_man = false;
   };

   if (isNil "mando_airsupport_armedrec_max") then
   {
      mando_airsupport_armedrec_max = 4;
   };

   if (isNil "mando_airsupport_armedrec_num") then
   {
      if (mando_airsupport_armedrec) then
      {
         mando_airsupport_armedrec_num = mando_airsupport_armedrec_max;
      }
      else
      {
         mando_airsupport_armedrec_num = 0;
      };
   };

   if (isNil "mando_airsupport_pilon") then
   {
      mando_airsupport_pilon = 1;
   };

   if (isNil "mando_airsupport_maxrecoscan") then
   {
      mando_airsupport_maxrecoscan = 1500 + mando_airsupport_bomb_altmax;
   };


   if (isNil "mando_airsupport_cams") then
   {
      mando_airsupport_cams = [];
   };

   if (isNil "mando_airsupport_cur_cam") then
   {
      mando_airsupport_cur_cam = -1;
   };


// Radio chat
   if (isNil "mando_radio_req_cas") then
   {  
      mando_radio_req_cas = "";
   };

   if (isNil "mando_radio_rep_cas") then
   {
      mando_radio_rep_cas = "";
   };

   if (isNil "mando_radio_req_br") then
   {
      mando_radio_req_br = "";
   };

   if (isNil "mando_radio_rep_br") then
   {
      mando_radio_rep_br = "";
   };

   if (isNil "mando_radio_req_gs") then
   {  
      mando_radio_req_gs = "";
   };

   if (isNil "mando_radio_rep_gs") then
   {
      mando_radio_rep_gs = "";
   };

   if (isNil "mando_radio_req_ab") then
   {
      mando_radio_req_ab = "";
   };

   if (isNil "mando_radio_rep_ab") then
   {
      mando_radio_rep_ab = "";
   };

   if (isNil "mando_radio_repr_ab") then
   {
      mando_radio_repr_ab = "";
   };


   if (isNil "mando_radio_req_cm") then
   {
      mando_radio_req_cm = "";
   };

   if (isNil "mando_radio_rep_cm") then
   {
      mando_radio_rep_cm = "";
   };

   if (isNil "mando_radio_req_sa") then
   {
      mando_radio_req_sa = "";
   };

   if (isNil "mando_radio_rep_sa") then
   {
      mando_radio_rep_sa = "";
   };

   if (isNil "mando_radio_req_am") then
   {
      mando_radio_req_am = "";
   };

   if (isNil "mando_radio_rep_am") then
   {
      mando_radio_rep_am = "";
   };

   if (isNil "mando_radio_repr_am") then
   {
      mando_radio_repr_am = "";
   };

   if (isNil "mando_radio_req_ve") then
   {
      mando_radio_req_ve = "";
   };

   if (isNil "mando_radio_rep_ve") then
   {
      mando_radio_rep_ve = "";
   };

   if (isNil "mando_radio_repr_ve") then
   {
      mando_radio_repr_ve = "";
   };

   if (isNil "mando_radio_req_re") then
   {
      mando_radio_req_re = "";
   };

   if (isNil "mando_radio_rep_re") then
   {
      mando_radio_rep_re = "";
   };

   if (isNil "mando_radio_repr_re") then
   {
      mando_radio_repr_re = "";
   };

   if (isNil "mando_radio_req_cp") then
   {
      mando_radio_req_cp = "";
   };

   if (isNil "mando_radio_rep_cp") then
   {
      mando_radio_rep_cp = "";
   };

   if (isNil "mando_radio_req_rc") then
   {
      mando_radio_req_rc = "";
   };

   if (isNil "mando_radio_rep_rc") then
   {
      mando_radio_rep_rc = "";
   };

   if (isNil "mando_radio_req_ev") then
   {
      mando_radio_req_ev = "";
   };

   if (isNil "mando_radio_rep_ev") then
   {
      mando_radio_rep_ev = "";
   };

   if (isNil "mando_radio_repr_ev") then
   {
      mando_radio_repr_ev = "";
   };

   if (isNil "mando_radio_req_la") then
   {
      mando_radio_req_la = "";
   };

   if (isNil "mando_radio_rep_la") then
   {
      mando_radio_rep_la = "";
   };

   if (isNil "mando_radio_req_cb") then
   {
      mando_radio_req_cb = "";
   };

   if (isNil "mando_radio_rep_cb") then
   {
      mando_radio_rep_cb = "";
   };



   Sleep 0.5;

   []spawn
   {
      disableSerialization;
      private["_trigger"];
      _trigger = createTrigger ["EmptyDetector", [0, 0, 0]];
      _trigger setTriggerActivation ["NONE", "PRESENT", false];
      _trigger setTriggerArea [0, 0, 0, false];
      _trigger setTriggerType "NONE";
      _trigger setTriggerTimeout [0, 0, 0, false ];
      _trigger setTriggerStatements ["true", "res = [true]execVM""mando_missiles\mando_bombs\mando_airsupportdlg.sqf""", ""];
      Sleep 6;
      deleteVehicle _trigger;
   };


   _ok = createDialog "MandoAirSupportDlg";
};


if (mando_airsupport_nocomms == 1) then
{
   if (!(_event in ["onLoad","onCameraClick","onMapClick","onMouseMoving","onMouseZChanged","ZOOM_IN","ZOOM_OUT","INGRESS_CHANGE","INGRESS_ALT_CHANGE","FREE_FALL","SADARM","CALL_JUMP"])) then
   {
      _event = "";
      ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: No communication link active";
      mando_reco_cam = 0;
      mando_last_plane=objNull;
   };
};


switch (_event) do
{
   case "onLoad":
   {

   if (isNil "mandotarget_disp_on") then
   {
      mandotarget_disp_on = false;
   };
   mandotarget_disp_on_old = mandotarget_disp_on;
   mandotarget_disp_on = false;
   3 cutText["", "PLAIN"];

   playSound "mando_console_on";
   

      mando_cam_scale = 1;
      mando_take_pic = false;
      mando_take_pic_on = false;

      mando_recocam_scale = 1;
      mando_recocam_angles = [0,0];
      if (isNil "mando_last_reco") then
      {
         mando_last_reco = objNull;
      };

      mando_reco_cam = 0;
      mando_console_pos = 1.5;
      mando_reco_move = false;

      if (isNil "mando_last_missile") then
      {
         mando_last_missile = objNull;
      };

      if (isNil "mando_last_plane") then
      {
         mando_last_plane = objNull;
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
//      mando_support_display = _display;    


      (_display displayCtrl 25000) ctrlSetPosition [0,0,1,0];
      (_display displayCtrl 25000) ctrlCommit 1;

      if (mando_airsupport_jump) then
      {
         (_display displayCtrl 23961) ctrlSetText "JUMP";
      }
      else
      {
         (_display displayCtrl 23961) ctrlSetText "LAND";
      };


      _left = call compile format["mando_support_left_%1", mando_support_side];

      if (_left > 0) then
      {
         for [{_i=0},{_i< (_left min 4)},{_i=_i+1}] do
         {
            if (_i == 0) then
            {
               (_display displayCtrl 23901) lbAdd "Allocate 1 plane";
            }
            else
            {
               (_display displayCtrl 23901) lbAdd format["Allocate %1 planes", _i + 1];
            };
         };
         (_display displayCtrl 23901) lbSetCurSel 0;
      };      
      (_display displayCtrl 23902) ctrlSetText format["Planes available (CAS/BR): %1", _left];


      (_display displayCtrl 23920) sliderSetRange mando_support_ingress_limits;
      (_display displayCtrl 23920) sliderSetSpeed [5, 20];

      if (isNil "mando_ingress_dir") then
      {
         (_display displayCtrl 23920) sliderSetPosition ((mando_support_ingress_limits select 0)+((mando_support_ingress_limits select 1)-(mando_support_ingress_limits select 0))/2);
         mando_ingress_dir = sliderPosition (_display displayCtrl 23920);
      }
      else
      {
         (_display displayCtrl 23920) sliderSetPosition mando_ingress_dir;
      };



      if ((mando_airsupport_bomb_alt < 100) || (mando_airsupport_bomb_alt > mando_airsupport_bomb_altmax)) then
      {
         mando_airsupport_bomb_alt = 150;
      };

      (_display displayCtrl 23922) sliderSetRange [100, mando_airsupport_bomb_altmax];
      (_display displayCtrl 23922) sliderSetSpeed [5, 20];
      (_display displayCtrl 23922) sliderSetPosition (mando_airsupport_bomb_alt);
      (_display displayCtrl 23921) ctrlSetText format["Ingress min alt: %1m", floor mando_airsupport_bomb_alt];


      if ((isNil "mando_missile_init") || ((call compile format["mando_support_left_cm_%1", mando_support_side]) < 1)) then
      {
         (_display displayCtrl 23917) ctrlEnable false;
      };

      if ((isNil "mando_missile_init") || ((call compile format["mando_support_left_sa_%1", mando_support_side]) < 1)) then
      {
         (_display displayCtrl 23928) ctrlEnable false;
      };

      if (isNil "mando_support_laserlogic") then
      {
         mando_support_laserlogic = objNull;
      }
      else
      {
         if (!isNull mando_support_laserlogic) then
         {
            deleteVehicle mando_support_laserlogic;
         };
      };

      if (isNil "mando_support_laserlogic_target") then
      {
         mando_support_laserlogic_target = objNull;
      };


      (_display displayCtrl 23915) ctrlSetText format["GS (%1)", call compile format["mando_support_left_ca_%1", mando_support_side]];
      (_display displayCtrl 23916) ctrlSetText format["AB (%1)", call compile format["mando_support_left_pa_%1", mando_support_side]];
      (_display displayCtrl 23917) ctrlSetText format["CM (%1)", call compile format["mando_support_left_cm_%1", mando_support_side]];
      (_display displayCtrl 23923) ctrlSetText format["RC (%1)", call compile format["mando_support_left_rc_%1", mando_support_side]];
      (_display displayCtrl 23924) ctrlSetText format["AM (%1)", call compile format["mando_support_left_am_%1", mando_support_side]];
      (_display displayCtrl 23925) ctrlSetText format["VE (%1)", call compile format["mando_support_left_ve_%1", mando_support_side]];
      (_display displayCtrl 23926) ctrlSetText format["RE (%1)", call compile format["mando_support_left_re_%1", mando_support_side]];
      (_display displayCtrl 23927) ctrlSetText format["CP (%1)", call compile format["mando_support_left_cp_%1", mando_support_side]];
      (_display displayCtrl 23928) ctrlSetText format["SA (%1)", call compile format["mando_support_left_sa_%1", mando_support_side]];
      (_display displayCtrl 23941) ctrlSetText format["EV (%1)", call compile format["mando_support_left_ev_%1", mando_support_side]];
      (_display displayCtrl 23945) ctrlSetText format["LA (%1)", call compile format["mando_support_left_la_%1", mando_support_side]];
      (_display displayCtrl 23937) ctrlSetText format["CB (%1)", call compile format["mando_support_left_cb_%1", mando_support_side]];

      if ((call compile format["mando_support_left_ca_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23915) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_pa_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23916) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_cm_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23917) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_sa_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23928) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_rc_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23923) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_ev_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23941) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_la_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23945) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_cb_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23937) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_am_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23924) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_ve_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23925) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_re_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23926) ctrlEnable false;
      };

      if ((call compile format["mando_support_left_cp_%1", mando_support_side]) < 1) then
      {
         (_display displayCtrl 23927) ctrlEnable false;
      };


      if (mando_airsupport_bomb_type == "SADARM") then
      {
         (_display displayCtrl 23913) ctrlSetTextColor [0, 0, 0, 1];
         (_display displayCtrl 23914) ctrlSetTextColor [0, 1, 0, 1];
      }
      else
      {
         (_display displayCtrl 23913) ctrlSetTextColor [0, 1, 0, 1];
         (_display displayCtrl 23914) ctrlSetTextColor [0, 0, 0, 1];
      };

      (_display displayCtrl 23909) ctrlSetTooltip "Call for Close Air Support (fixed wing)";
      (_display displayCtrl 23910) ctrlSetTooltip "Call for Bomb Run (fixed wing)";
      (_display displayCtrl 23915) ctrlSetTooltip "Call for Gunships (attack choppers)";
      (_display displayCtrl 23916) ctrlSetTooltip "Call for airborne assault";
      (_display displayCtrl 23917) ctrlSetTooltip "Call for cruise missile attack";
      (_display displayCtrl 23923) ctrlSetTooltip "Call for reconnaissance";
      (_display displayCtrl 23924) ctrlSetTooltip "Call for ammo supply";
      (_display displayCtrl 23925) ctrlSetTooltip "Call for vehicle supply";
      (_display displayCtrl 23926) ctrlSetTooltip "Call for reinforcements";
      (_display displayCtrl 23927) ctrlSetTooltip "Call for Combat Air Patrol";
      (_display displayCtrl 23928) ctrlSetTooltip "Call for cruise missile saturation";
      (_display displayCtrl 23941) ctrlSetTooltip "Call for evacuation (shift + map click to change destination)";
      (_display displayCtrl 23945) ctrlSetTooltip "Call for laser guided bombs support (use laser designator and validate targets)";
      (_display displayCtrl 23929) ctrlSetTooltip "Remote camera on and next camera";
      (_display displayCtrl 23930) ctrlSetTooltip "Remote camera off";
      (_display displayCtrl 23937) ctrlSetTooltip "Call for carpet bombing, check mission info for recommended bombing altitudes";
      (_display displayCtrl 23961) ctrlSetTooltip "Troops disembarking or jumping";


      (_display displayCtrl 23931) ctrlSetBackgroundColor mando_reco_cam_filter;

      if (mando_support_no_cas) then
      {
         (_display displayCtrl 23909) ctrlEnable false;   
      };

      if (mando_support_no_br) then
      {
         (_display displayCtrl 23910) ctrlEnable false;   
      };

      if (mando_support_no_ff) then
      {
         (_display displayCtrl 23913) ctrlEnable false;   
      };

      if (mando_support_no_sa) then
      {
         (_display displayCtrl 23914) ctrlEnable false;   
      };

      if (mando_support_no_gs) then
      {
         (_display displayCtrl 23915) ctrlEnable false;   
      };

      if (mando_support_no_ab) then
      {
         (_display displayCtrl 23916) ctrlEnable false;   
      };

      if (mando_support_no_cm) then
      {
         (_display displayCtrl 23917) ctrlEnable false;   
      };

      if (mando_support_no_rc) then
      {
         (_display displayCtrl 23923) ctrlEnable false;   
      };

      if (mando_support_no_ev) then
      {
         (_display displayCtrl 23941) ctrlEnable false;   
      };

      if (mando_support_no_la) then
      {
         (_display displayCtrl 23945) ctrlEnable false;   
      };

      if (mando_support_no_cb) then
      {
         (_display displayCtrl 23937) ctrlEnable false;   
      };


      if (mando_support_no_am) then
      {
         (_display displayCtrl 23924) ctrlEnable false;   
      };

      if (mando_support_no_ve) then
      {
         (_display displayCtrl 23925) ctrlEnable false;   
      };

      if ((!mando_airsupport_armedrec) || (isNil "mando_missile_init")) then
      {
         (_display displayCtrl 23946) ctrlEnable false;   
      };

      if (mando_support_no_re) then
      {
         (_display displayCtrl 23926) ctrlEnable false;   
      };

      if (mando_support_no_cp) then
      {
         (_display displayCtrl 23927) ctrlEnable false;
      };

      if (mando_support_no_sat) then
      {
         (_display displayCtrl 23928) ctrlEnable false;
      };

      (_display displayCtrl 100) ctrlSetText (mando_missile_path+"mando_bombs\laptop.paa");
      (_display displayCtrl 23943) ctrlSetText (mando_missile_path+"mando_steer.paa");
      (_display displayCtrl 23938) ctrlSetText (mando_missile_path+"mandocamera_circle.paa");
      (_display displayCtrl 23940) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23948) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23949) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23950) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");

      if (getMarkerColor "mk_mandoairsupport" == "") then
      {
         if ((mando_support_lastpos distance [0,0]) > 50) then
         {
            _marker = createMarkerLocal ["mk_mandoairsupport", mando_support_lastpos];
         }
         else
         {
            _marker = createMarkerLocal ["mk_mandoairsupport", [getPos vehicle player select 0, getPos vehicle player select 1]];
            mando_support_lastpos = [getPos vehicle player select 0, getPos vehicle player select 1];
         };
         "mk_mandoairsupport" setMarkerShapeLocal "ELLIPSE";
         "mk_mandoairsupport" setMarkerColorLocal "ColorGreenAlpha";
         "mk_mandoairsupport" setMarkerSizeLocal [500, 500];

         _marker = createMarkerLocal ["mk_mandoairsupport_dot", mando_support_lastpos];
         "mk_mandoairsupport_dot" setMarkerTypeLocal "Destroy";
         "mk_mandoairsupport_dot" setMarkerColorLocal "ColorWhite";
         "mk_mandoairsupport_dot" setMarkerSizeLocal [0.5, 0.5];
         "mk_mandoairsupport_dot" setMarkerTextLocal "Support";

         _marker = createMarkerLocal ["mk_mandoairsupport_op", [getPos vehicle player select 0, getPos vehicle player select 1]];
         "mk_mandoairsupport_op" setMarkerTypeLocal "Arrow";
         "mk_mandoairsupport_op" setMarkerColorLocal "ColorGreen";
         "mk_mandoairsupport_op" setMarkerSizeLocal [0.5, 0.5];
         "mk_mandoairsupport_op" setMarkerTextLocal "Operator";
      };


      _marker_name = format["mk_mandoevac_%1", mando_support_side];
      if (getMarkerColor format["mk_mandoevac_%1", mando_support_side] == "") then
      {
         createMarkerLocal [format["mk_mandoevac_%1", mando_support_side], [0,0,0]];
         format["mk_mandoevac_%1", mando_support_side] setMarkerTypeLocal "End";
         format["mk_mandoevac_%1", mando_support_side] setMarkerColorLocal "ColorGreen";
         format["mk_mandoevac_%1", mando_support_side] setMarkerSizeLocal [0.35, 0.35];
         format["mk_mandoevac_%1", mando_support_side] setMarkerTextLocal "Evac dest";
      };


      []spawn
      {
         disableSerialization;
         private ["_cam", "_commdisplay", "_pos", "_posold", "_loglos", "_poslos", "_dirlos", "_i", "_dist", "_mando_cam_scale_old", "_mando_ingress_dir_old", "_angh", "_ratev", "_asl1", "_asl2", "_mando_reco_cam_old", "_warning"];

         showCinemaBorder false;
         mando_cam_con = "camera" camcreate [0, 0, 0];
         mando_cam_con cameraeffect ["internal", "back"];
         mando_cam_con camSetFov 1;
         mando_cam_con camCommit 0;
         _loglos = "logic" createVehicleLocal [0,0,0];

         _commdisplay = findDisplay 23900;
         _pos = [-1,-1];
         _posold = [-1,-1,-1];
         _mando_cam_scale_old = mando_cam_scale;
         _mando_ingress_dir_old = mando_ingress_dir;


         createMarkerLocal ["mando_ingress_dir", [0,0]];
         "mando_ingress_dir" setMarkerShapeLocal "RECTANGLE";
         "mando_ingress_dir" setMarkerColorLocal "ColorWhite";
         "mando_ingress_dir" setMarkerSizeLocal [2, 100];


         [_cam, _commdisplay]spawn
         {
            disableSerialization;

            private ["_cam", "_commdisplay","_mando_reco_cam_old", "_angles", "_dirlos", "_ratev", "_i", "_loglos", "_pos", "_poslos", "_dist", "_marker", "_screen", "_hscreen", "_vscreen", "_mark", "_rect", "_textdata", "_texthelp", "_zoom", "_endcolor", "_rangecolor","_mando_reco_cam_target", "_fire_button", "_flir_button", "_line", "_posm", "_poss", "_post", "_trigger", "_rects", "_texts", "_vdir", "_logasl", "_list", "_dirsc", "_range_to_target", "_plane", "_plane_old"];
            _cam = _this select 0;
            _commdisplay = _this select 1;
            _mando_reco_cam_old = 0;
            _mando_last_reco_old = objNull;
            _loglos  = "logic" createVehicleLocal [0,0,0];
            _logasl  = "logic" createVehicleLocal [0,0,0];

            _mark = _commdisplay displayCtrl 23938;
            _rect = _commdisplay displayCtrl 23940;
            _textdata = _commdisplay displayCtrl 23939;
            _fire_button = _commdisplay displayCtrl 23946;
            _flir_button = _commdisplay displayCtrl 23960;


            _fire_button ctrlShow false; 
            _flir_button ctrlShow false;


            _line = _commdisplay displayCtrl 23947;
            _rects = [];
            _rects = _rects + [_commdisplay displayCtrl 23948];
            _rects = _rects + [_commdisplay displayCtrl 23949];
            _rects = _rects + [_commdisplay displayCtrl 23950];
            _texts = [];
            _texts = _texts + [_commdisplay displayCtrl 23951];
            _texts = _texts + [_commdisplay displayCtrl 23952];
            _texts = _texts + [_commdisplay displayCtrl 23953];
            _texthelp = _commdisplay displayCtrl 23954;

            _dirsc = [];
            {
               _dirsc = _dirsc + [_commdisplay displayCtrl _x];
            } forEach [23955,23956,23957,23958];

            _warning = "none";
            _trigger = objNull;
            _plane = objNull;
            _plane_old = objNull;

            while {!isNull _commdisplay} do
            {
               if (mando_reco_cam != _mando_reco_cam_old) then
               {
                  if ((alive mando_last_reco) || (alive mando_last_plane) || (alive mando_last_missile)) then
                  {
                     if (!alive mando_last_missile) then
                     {
                        mando_recocam_angles = [0,0];
                        if (alive mando_last_reco) then 
                        {
                           _angles = [getDir mando_last_reco,0];
                           mando_recocam_angles = [0,0];
                        }
                        else
                        {
                           _angles = [getDir mando_last_plane,0];
                           mando_recocam_angles = [0,0];
                        };
                     }
                     else
                     {  
                        mando_recocam_angles = [0,0];
                        _angles = [0,0];                  
                     };
                  };
                  _mando_reco_cam_old = mando_reco_cam;
                  if (mando_reco_cam == 1) then
                  {
                     (_commdisplay displayCtrl 23904) ctrlSetBackgroundColor [0, 0, 0, 1];
                     (_commdisplay displayCtrl 23904) ctrlSetTextColor [0, 0, 0, 1];

                     (_commdisplay displayCtrl 23903) ctrlSetPosition [1.5, 1.5, 0.75, 1-0.04];
                     (_commdisplay displayCtrl 23903) ctrlCommit 0;
                     (_commdisplay displayCtrl 23959) ctrlSetPosition [0.007, 0.0015, 0.25*3/4, 0.25];
                     (_commdisplay displayCtrl 23959) ctrlCommit 0;


                     (_commdisplay displayCtrl 23932) ctrlSetPosition [0, 0, 0.75, 1];
                     (_commdisplay displayCtrl 23932) ctrlCommit 0;
                  }
                  else
                  {
                     (_commdisplay displayCtrl 23932) ctrlSetPosition [1.5, 1.5, 0.75, 1];
                     (_commdisplay displayCtrl 23932) ctrlCommit 0;

                     (_commdisplay displayCtrl 23903) ctrlSetPosition [0, 0, 0.75, 1-0.04];
                     (_commdisplay displayCtrl 23903) ctrlCommit 0;
                     (_commdisplay displayCtrl 23959) ctrlSetPosition [1.5, 1.5, 0.25*3/4, 0.25];
                     (_commdisplay displayCtrl 23959) ctrlCommit 0;

                     if (mando_console_pos < 0) then
                     {
                        call mando_console_switch;
                     };

                     mando_rec_flir = false;
                     setAperture -1;
                  };
               };

               if (mando_reco_cam == 1) then
               {
                  if ((alive mando_last_reco) || (alive mando_last_missile) || (alive mando_last_plane)) then
                  {


                     if (!isNull mando_support_laserlogic) then
                     {
                        if (!isNull mando_support_laserlogic_target) then
                        {
                           mando_support_laserlogic setPos getPos mando_support_laserlogic_target;
                        };
                     }; 


                     if (!isNull mando_last_missile) then
                     {
                        _plane = mando_last_missile;
                        (_commdisplay displayCtrl 23943) ctrlSetTextColor [0.5,0.5,0.5,1];

                        _texthelp ctrlSetStructuredText parseText "Camera steerable area (move the mouse in the area to guide the missile)";

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
                        _list = [];
                        {
                           if (fuel _x < 1) then
                           {
                              if (isEngineOn _x) then
                              {
                                 if ((getPos _x select 2) < 2) then
                                 {
                                    _list = _list + [_x];
                                 };
                              };
                           };
                        } forEach list _trigger;

                        _zoom = mando_recocam_scale;
                        if (count _list > 0) then
                        {
                           for [{_i=0},{_i<3},{_i=_i+1}] do
                           { 
                              if (_i < count _list) then
                              {
                                 _screen = [mando_last_missile, _list select _i, []] call MandoWorldToScreen2;

                                 _hscreen = 0.5 + (_screen select 0)/_zoom - 0.04/2;
                                 _vscreen = 0.5 - (_screen select 1)/_zoom - 0.05/2;

                                 _hscreen = _hscreen min (0.7-0.04);
                                 _hscreen = _hscreen max (0.3);

                                 _vscreen = _vscreen min (0.7-0.05);
                                 _vscreen = _vscreen max (0.3);

                                 _angh = _screen select 2;
                                 _angv = _screen select 3;
    
                                 if ((abs(_angh) < 5) && (abs(_angv) < 5)) then
                                 {
                                    (_rects select _i) ctrlSetTextColor [0.5, 1, 0.5, 1];
                                    (_texts select _i) ctrlSetTextColor [0.5, 1, 0.5, 1];
                                    (_texts select _i) ctrlSetText typeOf (_list select _i);
                                 }
                                 else
                                 {
                                    (_rects select _i) ctrlSetTextColor [0.25, 0.5, 0.25, 1];
                                    (_texts select _i) ctrlSetTextColor [0.25, 0.5, 0.25, 1];
                                    (_texts select _i) ctrlSetText "";
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
                        _flir_button ctrlShow true;
                        _line ctrlSetTextColor [0, 1, 0, 0];

                        _screen = [mando_last_missile, mando_last_target, []] call MandoWorldToScreen2;

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
                           _mark ctrlSetTextColor [0.5, 1, 0.5, 1];
                        }
                        else
                        {
                           _mark ctrlSetTextColor [0.25, 0.5, 0.25, 0.5];
                        };
 
                        _dist = floor (mando_last_missile distance mando_last_target);
                        if (_dist < 1500) then
                        {
                           _rect ctrlSetTextColor [0, 0.5, 0, 1];
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


                        (_commdisplay displayCtrl 23959) ctrlMapAnimAdd [0, 1, getPos mando_last_missile];
                        ctrlMapAnimCommit (_commdisplay displayCtrl 23959);

                        _textdata ctrlSetStructuredText parseText format["Missile range to target: %1 m<br />Missile endurance: %2 seconds<br />Missile altitude ASL: %3 m<br />Missile guidance:<t color='#ff0000'> Manual</t><br />Warning: %4<br />Zoom: %5", _rangecolor, _endcolor, floor(getPosASL mando_last_missile select 2),_warning, floor((1 - mando_recocam_scale)*100/0.99)];

//                        mando_last_missile_target setPos (mando_last_missile modelToWorld [sin((mando_recocam_angles select 0)*6)*500, cos ((mando_recocam_angles select 0)*6)*500, sin((mando_recocam_angles select 1)*5)*500]);


                        mando_last_missile_target setPos (mando_last_missile modelToWorld [sin((mando_recocam_angles select 0)*3)*500, cos ((mando_recocam_angles select 0)*3)*500, sin((mando_recocam_angles select 1)*3)*500]);

//                        mando_cam_con camSetPos (mando_last_missile modelToWorld [0,7,0]);
                        mando_cam_con camSetTarget (mando_last_missile modelToWorld [0,200,0]);
                     }
                     else
                     {
                        if (alive mando_last_reco) then
                        { 
                           _plane = mando_last_reco;


                           if (_plane != _plane_old) then
                           {
                              
                              _angles = [getDir _plane,0];
                              mando_recocam_angles = [0,0];

                              _plane_old = _plane;
                           }
                           else
                           {
                              _angles set [0, (_angles select 0)+(mando_recocam_angles select 0)];
      
                              if (abs((_angles select 1)+(mando_recocam_angles select 1)) < 89) then
                              {
                                 _angles set [1, (_angles select 1)+(mando_recocam_angles select 1)];
                              };
                           };




                           _texthelp ctrlSetStructuredText parseText "Camera steerable area (move the mouse in the area to move the camera)<br />L. click to mark/lock, R. click to hide console, SHIFT + L. click to change dest.";
                           if (isNull _trigger) then
                           {
                              _trigger = createTrigger ["EmptyDetector", [(getPos mando_last_reco select 0)+900*sin(getDir mando_last_reco),(getPos mando_last_reco select 1)+900*cos(getDir mando_last_reco), 0]];
                              _trigger setTriggerActivation ["ANY", "PRESENT", false];
                              _trigger setTriggerArea [750, 750, getDir mando_last_reco, true];
                              _trigger setTriggerType "NONE";
                              _trigger setTriggerStatements ["this", "", ""];
                              _trigger setTriggerTimeout [0, 0, 0, false ];
                           }
                           else
                           {
                              _trigger setPos [(getPos mando_last_reco select 0)+900*sin(getDir mando_last_reco),(getPos mando_last_reco select 1)+900*cos(getDir mando_last_reco), 0];
                              _trigger setTriggerArea [750, 750, getDir mando_last_reco, true];
                           };

                           (_commdisplay displayCtrl 23959) ctrlMapAnimAdd [0, 1, getPos mando_last_reco];
                           ctrlMapAnimCommit (_commdisplay displayCtrl 23959);

                           _mark ctrlSetTextColor [0.5, 0.5, 0.5, 0.5];
                           _rect ctrlSetTextColor [0, 0, 0, 0];
                           _fire_button ctrlShow true;
                           _flir_button ctrlShow true;

                           if (mando_lockedon == mando_last_reco) then
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
  
//                           mando_cam_con camSetPos (mando_last_reco modelToWorld mando_reco_cam_pos);

                           if (!mando_take_pic_on) then
                           {
//                              _mando_reco_cam_target = [(getPos mando_last_reco select 0)+sin((_angles select 0)+(getDir mando_last_reco))*mando_airsupport_maxrecoscan*cos(_angles select 1), (getPos mando_last_reco select 1)+cos((_angles select 0)+(getDir mando_last_reco))*mando_airsupport_maxrecoscan*cos(_angles select 1), (getPos mando_last_reco select 2)+sin(_angles select 1)*mando_airsupport_maxrecoscan];

                              _mando_reco_cam_target = [(getPos mando_last_reco select 0)+sin(_angles select 0)*mando_airsupport_maxrecoscan*cos(_angles select 1), (getPos mando_last_reco select 1)+cos(_angles select 0)*mando_airsupport_maxrecoscan*cos(_angles select 1), (getPos mando_last_reco select 2)+sin(_angles select 1)*mando_airsupport_maxrecoscan];

                              (_commdisplay displayCtrl 23943) ctrlSetTextColor [0.5,0.5,0.5,1];
                           }
                           else
                           { 
                              (_commdisplay displayCtrl 23943) ctrlSetTextColor [1,0,0,1];
                           };
                           if (!isNull mando_support_laserlogic_target) then
                           {
                              mando_cam_con camSetTarget mando_support_laserlogic_target;
                              _posm = mando_last_reco worldToModel (getPos mando_support_laserlogic_target);
                              _post = (getPos mando_support_laserlogic_target);
                           }
                           else
                           {
                              mando_cam_con camSetTarget _mando_reco_cam_target;
                              _posm = mando_last_reco worldToModel _mando_reco_cam_target;
                              _post = _mando_reco_cam_target;
                           };
                           _dist = mando_last_reco distance _post;
 
                           if (mando_take_pic_on) then
                           {
                              _range_to_target = format["<br />Range to target: %1 Km", floor (_dist/100)/10]; 
                           }
                           else
                           {
                              _range_to_target = "";
                           };
                           _textdata ctrlSetStructuredText parseText format["Warning: %1<br />Zoom: %2<br />Range to destination: %3 Km%4", _warning, floor((1 - mando_recocam_scale)*100/0.99), floor ((mando_last_reco distance waypointPosition [group driver mando_last_reco, 1])/100)/10, _range_to_target];


                           _line ctrlSetTextColor [0.5, 1, 0.5, 1];

                           _angv = -((_posm select 0) atan2 (_posm select 1));
                           _poss = [0.5+sin(_angv)*0.08*4/5, 0.5-cos(_angv)*0.08];
                           _line ctrlSetPosition [0.5, 0.5, (_poss select 0)-0.5, (_poss select 1)-0.5];

                           _line ctrlCommit 0;
                           _list = [];
                           {
                              if (fuel _x < 1) then
                              {
                                 if (isEngineOn _x) then
                                 {
                                    if ((getPos _x select 2) < 2) then
                                    {
                                       _list = _list + [_x];
                                    };
                                 };
                              };
                           } forEach list _trigger;


                           _logasl setPos _post;
                           _vdir = [((_post select 0)-(getPos mando_last_reco select 0))/_dist,((_post select 1)-(getPos mando_last_reco select 1))/_dist,((getPosASL _logasl select 2)-(getPosASL mando_last_reco select 2))/_dist];

                           _logasl setPos waypointPosition [group driver mando_last_reco, 1];

                           _screen = [mando_last_reco, _logasl, _vdir] call MandoWorldToScreen2;
                           _zoom = mando_recocam_scale;
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


                           if (count _list > 0) then
                           {
                              for [{_i=0},{_i<3},{_i=_i+1}] do
                              { 
                                 if (_i < count _list) then
                                 {
                                    _screen = [mando_last_reco, _list select _i, _vdir] call MandoWorldToScreen2;
                                    _hscreen = 0.5 + (_screen select 0)/(_zoom*1.5) - 0.04/2;
                                    _vscreen = 0.5 - (_screen select 1)/(_zoom*1.5) - 0.05/2;
                                    _hscreen = _hscreen min (0.7-0.04);
                                    _hscreen = _hscreen max (0.3);
   
                                    _vscreen = _vscreen min (0.7-0.05);
                                    _vscreen = _vscreen max (0.3);

                                    _angh = _screen select 2;
                                    _angv = _screen select 3;
       
                                    if ((abs(_angh) < 5) && (abs(_angv) < 5)) then
                                    {
                                       (_rects select _i) ctrlSetTextColor [0.5, 1, 0.5, 1];
                                       (_texts select _i) ctrlSetTextColor [0.5, 1, 0.5, 1];
                                       (_texts select _i) ctrlSetText typeOf (_list select _i);
                                    }
                                    else
                                    {
                                       (_rects select _i) ctrlSetTextColor [0.25, 0.5, 0.25, 1];
                                       (_texts select _i) ctrlSetTextColor [0.25, 0.5, 0.25, 1];
                                       (_texts select _i) ctrlSetText "";
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


                           if (mando_take_pic && (alive mando_last_reco)) then
                           {
                              mando_take_pic = false;
                              if (!mando_take_pic_on || mando_reco_move) then
                              { 
                                 _loglos setPos _mando_reco_cam_target;
                                 _pos = getPosASL _loglos;
                                 _loglos setPos (mando_last_reco modelToWorld mando_reco_cam_pos);
                                 _poslos = getPosASL _loglos;
   
                                 _dist = 0.001 + sqrt(((_poslos select 0) - (_pos select 0))^2 + ((_poslos select 1) - (_pos select 1))^2);
                                 _dirlos = ((_pos select 0)-(_poslos select 0)) atan2 ((_pos select 1)-(_poslos select 1));       
                                 _ratev = ((_pos select 2) - (_poslos select 2))/_dist;

                                 for [{_i = 20},{_i < _dist},{_i=_i + 3}] do
                                 {
                                    _loglos setPosASL [(_poslos select 0)+sin(_dirlos)*_i,(_poslos select 1)+cos(_dirlos)*_i, (_poslos select 2)+_ratev*_i];

//   drop ["\ca\data\koulesvetlo","","Billboard",100,2,[0,0,0],[0,0,0],0,1.27,1.0,0.05,[1],[[1,0,0,1]],[0],0,0,"","",_loglos];
                                    if ((getPos _loglos select 2) <= 0) then
                                    {             
                                       _mando_reco_cam_target = getPos _loglos;
                                       _i = 9999; 
                                    };
                                 };                           


                                 if (mando_take_pic_on && mando_reco_move) then
                                 {
                                    _i = 9999;
                                 };

                                 if (_i >= 9999) then
                                 {
                                    if (!mando_reco_move) then
                                    {
                                       mando_reco_x_rcm = getPos _loglos select 0;
                                       mando_reco_y_rcm = getPos _loglos select 1;
                                       mando_reco_side_rcm = mando_support_side;
                                       mando_reco_numrcm = mando_num_reco_marks;
                                       {publicVariable _x} forEach ["mando_reco_x_rcm", "mando_reco_y_rcm", "mando_reco_sidercm", "mando_reco_numrcm"];
      
                                       if (isNull mando_support_laserlogic) then
                                       {
//                                          mando_support_laserlogic = "logic" createVehicle [0,0,0];
                                          if (isNil "mando_support_laserlogic_center") then
                                          {
                                             mando_support_laserlogic_center = createCenter sideLogic;
                                             mando_support_laserlogic_group = createGroup mando_support_laserlogic_center;
                                          };

                                          mando_support_laserlogic =mando_support_laserlogic_group createUnit ["LOGIC", [0, 0, 0], [], 0, ""];


                                          mando_support_laserlogic setPos [mando_reco_x_rcm, mando_reco_y_rcm, 0];
                                          if (!isNil "mando_missile_init") then
                                          {
                                             [mando_support_side, mando_support_laserlogic]execVM "mando_missiles\units\mando_addremotetarget.sqf"
                                          };
                                       };

                                       if (count (nearestObjects [[mando_reco_x_rcm, mando_reco_y_rcm, 0], ["Ship", "LandVehicle"], 20]) > 0) then     
                                       {
                                          mando_support_laserlogic_target = (nearestObjects [[mando_reco_x_rcm, mando_reco_y_rcm, 0], ["Ship", "LandVehicle"], 20]) select 0;
                                       };
                                       mando_take_pic_on = true;


                                       [_commdisplay, mando_num_reco_marks] spawn
                                       {
                                          disableSerialization;
                                          ((_this select 0) displayCtrl 23942) ctrlSetText format["MSG: Reconnaissance position marked - RCM_%1",(_this select 1)];
                                          Sleep 3;
                                          ((_this select 0) displayCtrl 23942) ctrlSetText "MSG:";
                                       };
                                       mando_num_reco_marks = mando_num_reco_marks + 1;
                                       if (mando_num_reco_marks == 10) then
                                       {
                                          mando_num_reco_marks = 0;
                                       };
                                    }
                                    else
                                    {
                                       mando_reco_move = false;
                                       if ((count waypoints (driver mando_last_reco)) < 3) then
                                       {
                                          [_commdisplay] spawn
                                          {
                                             disableSerialization;
                                             ((_this select 0) displayCtrl 23942) ctrlSetText "MSG: Reconnaissance unit is already egressing";
                                             Sleep 3;
                                             ((_this select 0) displayCtrl 23942) ctrlSetText "MSG:";
                                          };
                                       }
                                       else
                                       {
                                          [_commdisplay] spawn
                                          {
                                             disableSerialization;
                                             ((_this select 0) displayCtrl 23942) ctrlSetText "MSG: New reconnaissance destination";
                                              Sleep 3;
                                             ((_this select 0) displayCtrl 23942) ctrlSetText "MSG:";
                                          };

                                          mando_last_reco flyinHeight mando_airsupport_bomb_alt;

                                          if (mando_take_pic_on) then
                                          {
                                             [group driver mando_last_reco, 1] setWaypointPosition [[_post select 0, _post select 1, 0], 0];
                                          }
                                          else
                                          {
                                             [group driver mando_last_reco, 1] setWaypointPosition [getPos _loglos, 0];
                                          };
                                       };
                                    };
                                 };         
                              }
                              else
                              {
                                 _pos = getPos mando_last_reco;
                                 _dirlos = ((_mando_reco_cam_target select 0)-(_pos select 0)) atan2 ((_mando_reco_cam_target select 1)-(_pos select 1));
                                 _loglos setPos _mando_reco_cam_target; 

                                 _angles set [0, _dirlos];
                                 _angles set [1, asin(((getPosASL _loglos select 2)-(getPosASL mando_last_reco select 2))/(mando_last_reco distance _mando_reco_cam_target))];

                                 mando_take_pic_on = false;
                                 (_commdisplay displayCtrl 23943) ctrlSetTextColor [0,0,0,1];
                                 if (!isNull  mando_support_laserlogic) then 
                                 {
                                    deleteVehicle mando_support_laserlogic;
                                 };
                                 if (!isNull  mando_support_laserlogic_target) then 
                                 {
                                    mando_support_laserlogic_target = objNull;
                                 };
                              };

                              mando_reco_move = false;
                           };
                        }
                        else
                        { 
                        // Last plane, no reco, no missile
                           _plane = mando_last_plane;
                           _texthelp ctrlSetStructuredText parseText (mando_last_plane getVariable "mando_last_plane_text");
                           mando_recocam_scale = 1;

                           if (mando_lockedon == mando_last_plane) then
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
                           _textdata ctrlSetStructuredText parseText format["Warning: %1<br />Zoom: N/A", _warning];


//                           mando_cam_con camSetPos (mando_last_plane modelToWorld mando_last_plane_cam_pos);

                           if (_plane != _plane_old) then
                           {

                              
                              _angles = [getDir _plane,0];
                              mando_recocam_angles = [0,0];

                              _plane_old = _plane;
                           }
                           else
                           {
                              _angles set [0, (_angles select 0)+(mando_recocam_angles select 0)];   
                              if (abs((_angles select 1)+(mando_recocam_angles select 1)) < 89) then
                              {
                                 _angles set [1, (_angles select 1)+(mando_recocam_angles select 1)];
                              };
                           };
                           _post = [(getPos mando_last_plane select 0)+sin(_angles select 0)*mando_airsupport_maxrecoscan*cos(_angles select 1), (getPos mando_last_plane select 1)+cos(_angles select 0)*mando_airsupport_maxrecoscan*cos(_angles select 1), (getPos mando_last_plane select 2)+sin(_angles select 1)*mando_airsupport_maxrecoscan];
                           mando_cam_con camSetTarget _post;

                           _angh = ((_post select 0)-(getPos mando_last_plane select 0)) atan2 ((_post select 1)-(getPos mando_last_plane select 1));
                           _i = 0;
                           {
                              _x ctrlSetPosition [(0.5+sin(_i-_angh)*0.1*5/6)-0.01, (0.5-cos(_i-_angh)*0.1)-0.01, 0.02, 0.02];
                              _x ctrlCommit 0;
                              _i = _i + 90;
                           } forEach _dirsc;
                           _mark ctrlSetTextColor [0, 0, 0, 0];
                           _rect ctrlSetTextColor [0, 0, 0, 0];
                           _line ctrlSetTextColor [0, 0, 0, 0];

                           {
                              _x ctrlSetTextColor [0, 0, 0, 0];
                           } forEach _rects;
                           {
                              _x ctrlSetTextColor [0, 0, 0, 0];
                           } forEach _texts;
                           
                           _fire_button ctrlShow false;
                           _flir_button ctrlShow false;
                           (_commdisplay displayCtrl 23959) ctrlMapAnimAdd [0, 1, getPos mando_last_plane];
                           ctrlMapAnimCommit (_commdisplay displayCtrl 23959);
                           (_commdisplay displayCtrl 23943) ctrlSetTextColor [0.5,0.5,0.5,1];
                        };
                     };

                     mando_cam_con camSetFov mando_recocam_scale;
                     mando_cam_con camCommit 0; 
                  }
                  else
                  {
                     mando_reco_cam = 0;
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
            deleteVehicle _logasl;
            mando_last_missile_target setPos (getPos mando_last_target);
            mando_rec_flir = false;
            setAperture -1;
         };


         _mando_reco_cam_old = -1;
         if (mando_no_default_map) then
         {    
            onMapSingleClick "true";
         };


         _cam_scr_center = ctrlPosition (_commdisplay displayCtrl 23904);
         _cam_scr_center = [(_cam_scr_center select 0)+(_cam_scr_center select 2)/2,(_cam_scr_center select 1)+(_cam_scr_center select 3)/2];

         _pos = [-10.1, -10.1, 10.1];
         _pos_mk_old = [-10.1, -10.1, 10.1];



         _last_cam_attached = objNull;
         while {!isNull _commdisplay} do
         {
            if (!alive player) then
            {
               CloseDialog 23900;
            };
            "mk_mandoairsupport_op" setMarkerPosLocal getPos vehicle player;
            "mk_mandoairsupport_op" setMarkerDirLocal getDir vehicle player;

            if (((_pos select 0) != (getMarkerPos "mk_mandoairsupport" select 0)) ||
                ((_pos select 1) != (getMarkerPos "mk_mandoairsupport" select 1)) ||
                ((getPos vehicle player select 0) != (_posold select 0)) ||
                ((getPos vehicle player select 1) != (_posold select 1)) ||
                ((getPos vehicle player select 2) != (_posold select 2)) ||
                (mando_cam_scale != _mando_cam_scale_old) ||
                (mando_ingress_dir != _mando_ingress_dir_old) ||
                (mando_reco_cam != _mando_reco_cam_old) ) then
            {
/*
               _mando_reco_cam_old = mando_reco_cam;
               _mando_ingress_dir_old = mando_ingress_dir;
               _mando_cam_scale_old = mando_cam_scale;
               _posold = getPos vehicle player;
*/
               _pos = [getMarkerPos "mk_mandoairsupport" select 0, getMarkerPos "mk_mandoairsupport" select 1, 0];
               _loglos setPos _pos;
               _pos set [2, getPosASL _loglos select 2];

               _poslos = [getPosASL (vehicle player) select 0,getPosASL (vehicle player) select 1,(getPosASL (vehicle player) select 2)+2];

               _angh =  mando_ingress_dir;
               "mando_ingress_dir" setMarkerPosLocal [(_pos select 0)+sin(_angh)*750, (_pos select 1)+cos(_angh)*750];
               "mando_ingress_dir" setMarkerDirLocal _angh;
               "mando_ingress_dir" setMarkerSizeLocal [6, 500/2];

                ((findDisplay 23900) displayCtrl 23911) ctrlSetText format["Ingress direction: %1 deg", floor mando_ingress_dir];

               _loglos setPosASL _poslos;
               _loglos setDir 0;

               _dist = 0.001 + sqrt(((_poslos select 0) - (_pos select 0))^2 + ((_poslos select 1) - (_pos select 1))^2);

               if ((_dist < 2000) && (mando_reco_cam == 0)) then
               {
                  (_commdisplay displayCtrl 23954) ctrlSetText "";

                  _dirlos = ((_pos select 0)-(_poslos select 0)) atan2 ((_pos select 1)-(_poslos select 1));                   
                  _ratev = ((_pos select 2) - (_poslos select 2))/_dist;

                  for [{_i = 20},{_i < (_dist - 25)},{_i=_i + 25}] do
                  {
                     _loglos setPosASL [(_poslos select 0)+sin(_dirlos)*_i,(_poslos select 1)+cos(_dirlos)*_i, (_poslos select 2)+_ratev*_i];

                     if ((getPos _loglos select 2) <= 0) then
                     {             
                        _i = 9999; 
                     };
                  };

                  if (_i < 9999) then
                  {
                     if ((_mando_reco_cam_old != mando_reco_cam) || 
                         ((_pos_mk_old select 0) != (getMarkerPos "mk_mandoairsupport" select 0)) ||
                         ((_pos_mk_old select 1) != (getMarkerPos "mk_mandoairsupport" select 1)) ||
                         (mando_cam_scale != _mando_cam_scale_old)) then
                     {                        
                        _loglos setPos [(_pos select 0)-230*mando_cam_scale, (_pos select 1)+160*mando_cam_scale, 0];
                        _asl1 = getPosASL _loglos select 2;
                        _loglos setPos [(_pos select 0), (_pos select 1), 0];
                        _asl2 = getPosASL _loglos select 2;
_last_cam_attached = objNull;

                        mando_cam_con camSetPos [(_pos select 0)-230*mando_cam_scale, (_pos select 1)+160*mando_cam_scale, 300*mando_cam_scale + (_asl2 - _asl1)];

                        mando_cam_con camSetTarget [(_pos select 0)-230*mando_cam_scale, (_pos select 1) + (160*mando_cam_scale) + 1, (_asl2 - _asl1)];
                        mando_cam_con camSetFov 1.0;
                        mando_cam_con camCommit 0;
                        waitUntil {camCommitted mando_cam_con};
                        Sleep 0.002;

                        _poscam = positionCameraToWorld [0,0,0];
                        _posworld = screenToWorld _cam_scr_center;

                        _poscam = [(_poscam select 0)+(_pos select 0) - (_posworld select 0),(_poscam select 1)+(_pos select 1) - (_posworld select 1), 300*mando_cam_scale];

                        mando_cam_con camSetPos _poscam;
                        mando_cam_con camSetTarget [_poscam select 0,(_poscam select 1)+1,0];
                        mando_cam_con camCommit 0;
                        _pos_mk_old = [_pos select 0, _pos select 1];
                     };
                     (_commdisplay displayCtrl 23904) ctrlSetBackgroundColor [0, 0.2, 0, 0];
                     (_commdisplay displayCtrl 23904) ctrlSetTextColor [0, 1, 0, 0];
                  }
                  else
                  {
                     (_commdisplay displayCtrl 23904) ctrlSetBackgroundColor [0, 0.2, 0, 1];
                     (_commdisplay displayCtrl 23904) ctrlSetTextColor [0, 1, 0, 1];
                  };
               }
               else
               {
               // Attached to a plane 
                  (_commdisplay displayCtrl 23904) ctrlSetBackgroundColor [0, 0.2, 0, 1];
                  (_commdisplay displayCtrl 23904) ctrlSetTextColor [0, 1, 0, 1];

                  if (isNull _last_cam_attached) then
                  {
         mando_cam_con cameraeffect ["terminate", "back"];
         camDestroy mando_cam_con;
         mando_cam_con = "camera" camcreate [0, 0, 0];
         mando_cam_con cameraeffect ["internal", "back"];
         mando_cam_con camSetFov 1;

                     _last_cam_attached = mando_last_plane;
                  };
               };

               _mando_reco_cam_old = mando_reco_cam;
               _mando_ingress_dir_old = mando_ingress_dir;
               _mando_cam_scale_old = mando_cam_scale;
               _posold = getPos vehicle player;
            };

            if (mando_reco_cam != 0) then
            {
           
                  if (alive mando_last_missile) then
                  {
                     mando_cam_con attachTo [mando_last_missile, [0,7,0]];
                  } 
                  else
                  {
                     if (alive mando_last_reco) then
                     {
                        _var = mando_last_reco getVariable "mando_support_cam_pos";
                        if (isNil "_var") then
                        {
                           mando_cam_con attachTo [mando_last_reco, mando_reco_cam_pos];
                        }
                        else
                        {
                           mando_cam_con attachTo [mando_last_reco, _var];
                        };
                     }
                     else
                     { 
                        _var = mando_last_plane getVariable "mando_support_cam_pos";
                        if (isNil "_var") then
                        {
                           mando_cam_con attachTo [mando_last_plane, mando_last_plane_cam_pos];
                        }
                        else
                        {
                           mando_cam_con attachTo [mando_last_plane, _var];
                        };
                     };
                  };
            };
            Sleep 0.1;
         };
         mando_cam_con cameraeffect ["terminate", "back"];
         camDestroy mando_cam_con;
         deleteVehicle _loglos;
         deleteMarkerLocal "mk_mandoairsupport";
         deleteMarkerLocal "mk_mandoairsupport_dot";
         deleteMarkerLocal "mk_mandoairsupport_op";
         deleteMarkerLocal "mando_ingress_dir";

         if (mando_no_default_map) then
         {
            onMapSingleClick "";
         };
         mandotarget_disp_on = true;
      };

      []spawn
      {
         disableSerialization;
         private ["_commdisplay", "_left", "_leftold", "_i", "_left_ca", "_leftold_ca", "_left_pa", "_leftold_pa", "_left_cm", "_leftold_cm", "_left_sa", "_leftold_sa", "_left_rc", "_leftold_rc", "_left_ev", "_leftold_ev", "_left_la", "_leftold_la", "_left_cb", "_leftold_cb","_left_am", "_leftold_am", "_left_ve", "_leftold_ve", "_left_re", "_leftold_re", "_left_cp", "_leftold_cp", "_total", "_nocomms_old"];
         _commdisplay = findDisplay 23900;
         _left = call compile format["mando_support_left_%1", mando_support_side];
         _leftold = _left;

         _left_ca = call compile format["mando_support_ca_left_%1", mando_support_side];
         _leftold_ca = _left_ca;

         _left_pa = call compile format["mando_support_pa_left_%1", mando_support_side];
         _leftold_pa = _left_pa;

         _left_cm = call compile format["mando_support_cm_left_%1", mando_support_side];
         _leftold_cm = _left_cm;

         _left_sa = call compile format["mando_support_sa_left_%1", mando_support_side];
         _leftold_sa = _left_sa;

         _left_rc = call compile format["mando_support_rc_left_%1", mando_support_side];
         _leftold_rc = _left_rc;

         _left_ev = call compile format["mando_support_ev_left_%1", mando_support_side];
         _leftold_ev = _left_ev;

         _left_la = call compile format["mando_support_la_left_%1", mando_support_side];
         _leftold_la = _left_la;

         _left_cb = call compile format["mando_support_cb_left_%1", mando_support_side];
         _leftold_cb = _left_cb;

         _left_am = call compile format["mando_support_am_left_%1", mando_support_side];
         _leftold_am = _left_am;

         _left_ve = call compile format["mando_support_ve_left_%1", mando_support_side];
         _leftold_ve = _left_ve;

         _left_re = call compile format["mando_support_re_left_%1", mando_support_side];
         _leftold_re = _left_re;

         _left_cp = call compile format["mando_support_cp_left_%1", mando_support_side];
         _leftold_cp = _left_cp;

         _nocomms_old = mando_airsupport_nocomms;


         while {!isNull _commdisplay} do
         {
            _left = call compile format["mando_support_left_%1", mando_support_side];
            if (_left != _leftold) then
            { 
               _leftold = _left;
               Sleep 0.5;
               _left = _left - lbSize (_commdisplay displayCtrl 23901);

               if (_left < 0) then
               {                 
                  for [{_i=0},{_i < abs(_left)},{_i=_i+1}] do
                  {
                     (_commdisplay displayCtrl 23901) lbDelete (lbSize (_commdisplay displayCtrl 23901)-1);
                  };
                  (_commdisplay displayCtrl 23901) lbSetCurSel 0;
               }
               else
               {
                  if (_left > 0) then
                  {
                     _left = _left min 4;
                     _total = lbSize (_commdisplay displayCtrl 23901);
                     for [{_i=0},{_i < _left},{_i=_i+1}] do
                     {
                        if (_i+_total == 0) then
                        {
                           (_commdisplay displayCtrl 23901) lbAdd "Allocate 1 plane";
                        }
                        else
                        {  
                           (_commdisplay displayCtrl 23901) lbAdd format["Allocate %1 planes", (_i + _total + 1)];
                        }; 
                     };
                  };
                  (_commdisplay displayCtrl 23901) lbSetCurSel 0;
               };


               (_commdisplay displayCtrl 23902) ctrlSetText format["Planes available (CAS/BR): %1", call compile format["mando_support_left_%1", mando_support_side]];
            };

            _left_ca = call compile format["mando_support_ca_left_%1", mando_support_side];
            if (_left_ca != _leftold_ca) then
            {
               _leftold_ca = _left_ca;
               (_commdisplay displayCtrl 23915) ctrlSetText format["GS (%1)", _left_ca];
            };       

            _left_pa = call compile format["mando_support_pa_left_%1", mando_support_side];
            if (_left_pa != _leftold_pa) then
            {
               _leftold_pa = _left_pa;
               (_commdisplay displayCtrl 23916) ctrlSetText format["AB (%1)", _left_pa];
            };       

            _left_cm = call compile format["mando_support_cm_left_%1", mando_support_side];
            if (_left_cm != _leftold_cm) then
            {
               _leftold_cm = _left_cm;
               (_commdisplay displayCtrl 23917) ctrlSetText format["CM (%1)", _left_cm];
            };       

            _left_sa = call compile format["mando_support_sa_left_%1", mando_support_side];
            if (_left_sa != _leftold_sa) then
            {
               _leftold_sa = _left_sa;
               (_commdisplay displayCtrl 23928) ctrlSetText format["SA (%1)", _left_cm];
            };       


            _left_rc = call compile format["mando_support_rc_left_%1", mando_support_side];
            if (_left_rc != _leftold_rc) then
            {
               _leftold_rc = _left_rc;
               (_commdisplay displayCtrl 23923) ctrlSetText format["RC (%1)", _left_rc];
            };       


            _left_ev = call compile format["mando_support_ev_left_%1", mando_support_side];
            if (_left_ev != _leftold_ev) then
            {
               _leftold_ev = _left_ev;
               (_commdisplay displayCtrl 23941) ctrlSetText format["EV (%1)", _left_ev];
            };       

            _left_la = call compile format["mando_support_la_left_%1", mando_support_side];
            if (_left_la != _leftold_la) then
            {
               _leftold_la = _left_la;
               (_commdisplay displayCtrl 23945) ctrlSetText format["LA (%1)", _left_la];
            };       

            _left_cb = call compile format["mando_support_cb_left_%1", mando_support_side];
            if (_left_cb != _leftold_cb) then
            {
               _leftold_cb = _left_cb;
               (_commdisplay displayCtrl 23937) ctrlSetText format["CB (%1)", _left_cb];
            };       


            _left_am = call compile format["mando_support_am_left_%1", mando_support_side];
            if (_left_am != _leftold_am) then
            {
               _leftold_am = _left_am;
               (_commdisplay displayCtrl 23924) ctrlSetText format["AM (%1)", _left_am];
            };       

            _left_ve = call compile format["mando_support_ve_left_%1", mando_support_side];
            if (_left_ve != _leftold_ve) then
            {
               _leftold_ve = _left_ve;
               (_commdisplay displayCtrl 23925) ctrlSetText format["VE (%1)", _left_am];
            };       

            _left_re = call compile format["mando_support_re_left_%1", mando_support_side];
            if (_left_re != _leftold_re) then
            {
               _leftold_re = _left_re;
               (_commdisplay displayCtrl 23926) ctrlSetText format["RE (%1)", _left_am];
            };       

            _left_cp = call compile format["mando_support_cp_left_%1", mando_support_side];
            if (_left_cp != _leftold_cp) then
            {
               _leftold_cp = _left_cp;
               (_commdisplay displayCtrl 23927) ctrlSetText format["CP (%1)", _left_am];
            };


            if (mando_airsupport_nocomms != _nocomms_old) then
            {
               _nocomms_old = mando_airsupport_nocomms;

               if (mando_airsupport_nocomms == 1) then
               {
                  mando_reco_cam = 0;
                  (_commdisplay displayCtrl 23942) ctrlSetText "MSG: No communication link active";
               }
               else
               {
                  (_commdisplay displayCtrl 23942) ctrlSetText "MSG: Communication link restored";
               };
            };
 

            Sleep 1;
         };
      };
   };



   case "onMouseMoving":
   {
      _temp_angles = [(((_this select 1) select 1)-0.5)/0.2,(0.5-((_this select 1) select 2))/0.2];
      if ((abs(_temp_angles select 0) <= 1) && (abs(_temp_angles select 1) <= 1)) then
      {
         mando_recocam_angles set [0, (_temp_angles select 0)*2*(mando_recocam_scale max 0.1)];
         mando_recocam_angles set [1, (_temp_angles select 1)*2*(mando_recocam_scale max 0.1)];
      }
      else
      {
         mando_recocam_angles = [0,0];
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
   
         if (mando_recocam_scale > 0.05) then
         {
            mando_recocam_scale = mando_recocam_scale - 0.05;
         };
      }
      else
      {
         if (mando_cam_scale < 1) then
         {
            mando_cam_scale = mando_cam_scale + 0.1;
         };

         if (mando_recocam_scale < 1) then
         {
            mando_recocam_scale = mando_recocam_scale + 0.05;
         };
      };
   };

   case "onCameraClick":
   {
      if (((_this select 1) select 1) == 0) then
      {
         if ((_this select 1) select 4) then
         {
            mando_reco_move = true;
         };
         mando_take_pic = true;
      }
      else
      {
         call mando_console_switch;
      };
   };


   case "onMapClick":
   {
      if (((_this select 1) select 1) == 0) then
      {
         if ((_this select 1) select 4) then
         {
            _marker_name = format["mk_mandoevac_%1", mando_support_side];
            if (getMarkerColor _marker_name == "") then
            {
               createMarkerLocal [_marker_name, (((_this select 1) select 0) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3])];
               _marker_name setMarkerTypeLocal "End";
               _marker_name setMarkerColorLocal "ColorGreen";
               _marker_name setMarkerSizeLocal [0.35, 0.35];
               _marker_name setMarkerTextLocal "Evac dest";
            }
            else 
            {
               _marker_name setMarkerPosLocal (((_this select 1) select 0) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3]);
            };
         }
         else
         {
            "mk_mandoairsupport" setMarkerPosLocal (((_this select 1) select 0) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3]);
            "mk_mandoairsupport" setMarkerSizeLocal [500, 500];

            "mk_mandoairsupport_dot" setMarkerPosLocal (((_this select 1) select 0) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3]) ;
            "mk_mandoairsupport_dot" setMarkerSizeLocal [0.5,0.5];

            mando_support_lastpos = getMarkerPos "mk_mandoairsupport";
         };
      };
   };


   case "CALL_BOMB_RUN":
   {
      _left = call compile format["mando_support_left_%1", mando_support_side];
      if (_left > 0) then
      {
         _nplanes = 1 + lbCurSel ((findDisplay 23900) displayCtrl 23901);
         if (mando_support_side == west) then
         { 
            mando_support_left_WEST = mando_support_left_WEST - _nplanes;
            publicVariable "mando_support_left_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_EAST = mando_support_left_EAST - _nplanes;
               publicVariable "mando_support_left_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_GUER = mando_support_left_GUER - _nplanes;
                  publicVariable "mando_support_left_GUER";
               }
               else
               {
                  mando_support_left_CIV = mando_support_left_CIV - _nplanes;
                  publicVariable "mando_support_left_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_%1", mando_support_side];

         _left = _left - lbSize ((findDisplay 23900) displayCtrl 23901);
         if (_left < 0) then
         {
            for [{_i=0},{_i < abs(_left)},{_i=_i+1}] do
            {
               ((findDisplay 23900) displayCtrl 23901) lbDelete (lbSize ((findDisplay 23900) displayCtrl 23901)-1);
            };
            ((findDisplay 23900) displayCtrl 23901) lbSetCurSel 0;
         };
         ((findDisplay 23900) displayCtrl 23902) ctrlSetText format["Planes available (CAS/BR): %1", call compile format["mando_support_left_%1", mando_support_side]];

         ((findDisplay 23900) displayCtrl 23909) ctrlEnable false;
         ((findDisplay 23900) displayCtrl 23910) ctrlEnable false;
         ((findDisplay 23900) displayCtrl 23912) ctrlSetText "Bomb run mission in progress";

         if (mando_radio_req_br != "") then
         { 
            player sideRadio mando_radio_req_br;
         };


         for [{_i=0},{_i < _nplanes},{_i = _i + 1}] do
         {
            [_i] spawn
            {
               disableSerialization;
               private["_plane", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_scr", "_logasl", "_speed", "_extrah", "_range"];

               _ang = random 359;
               _targetpos = [(getMarkerPos "mk_mandoairsupport" select 0)+sin(_ang)*10*(_this select 0),(getMarkerPos "mk_mandoairsupport" select 1)+cos(_ang)*10*(_this select 0)];
               _logasl = "logic" createVehicleLocal [0,0,0];
               _logasl setPos [_targetpos select 0, _targetpos select 1, 0];


               if (isNil "mando_airsupport_fixedpos") then
               {
                  _ang = mando_ingress_dir;

                  if (mando_airsupport_type isKindOf "Helicopter") then
                  {
                     _range = mando_airsupport_range_he;
                  }
                  else
                  {
                     _range = mando_airsupport_range;
                  };
               }
               else
               {
                  _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
                  _range = mando_airsupport_fixedpos distance _targetpos;
                  ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
                  mando_ingress_dir = _ang;
               };

               _spawnpos = [(_targetpos select 0) + sin(_ang)*((_range + mando_airsupport_bomb_alt) +(_this select 0)*200), (_targetpos select 1) + cos(_ang)*((_range + mando_airsupport_bomb_alt)+(_this select 0)*200)];


               _plane = createVehicle [mando_airsupport_type, _spawnpos, [], 0, "FLY"];
               _speed = speed _plane;

               _group = createGroup (mando_support_side);
               _driver = _group createUnit ["USMC_Soldier_Pilot",[0,0,30], [], 0, "FORM"];
               _driver setskill 0.5;
               _driver setCombatMode "BLUE";
               _driver setBehaviour "CARELESS";
               _driver moveInDriver _plane;
               _group selectLeader _driver;
/*
               if (!isNil "mando_missile_init") then
               {
                  _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
                  [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
                  processInitCommands;
               };
*/
               Sleep 0.1;

               _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
               if ((getPosASL _plane select 2) < ((getPosASL _logasl select 2) + mando_airsupport_bomb_alt)) then
               {
                  _plane setPosASL [_spawnpos select 0,_spawnpos select 1, (getPosASL _logasl select 2) + mando_airsupport_bomb_alt];
                  _extrah = (getPosASL _logasl select 2);
               };
               _plane setDir _ang;
               _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0];
               deleteVehicle _logasl;


               if ((_this select 0) == 0) then
               {
                  _plane setVariable ["mando_last_plane_text", "Bomb run leader camera"];
                  mando_airsupport_cams = mando_airsupport_cams - [objNull];
                  mando_airsupport_cams = mando_airsupport_cams + [_plane];
                  if ( mando_radio_rep_br != "") then
                  {
                     [_driver] spawn
                     {
                        Sleep mando_console_radio_delay;
                        (_this select 0) sideRadio mando_radio_rep_br;
                     };
                  };

                  if (!isNil "mando_airsupport_code_cas") then
                  {
                     [_group] spawn mando_airsupport_code_cas;
                  };
               };


               [_this select 0, _plane] spawn
               {
                  private ["_base", "_plane"];
                  _plane = _this select 1;
                  _base = floor (random 1000);      
                  _marker = createMarkerLocal [format["mk_mandoairsupport_p%1", _base], [getPos _plane select 0, getPos _plane select 1]];
                  format["mk_mandoairsupport_p%1", _base] setMarkerTypeLocal "Arrow";
                  format["mk_mandoairsupport_p%1", _base] setMarkerColorLocal "ColorGreen";
                  format["mk_mandoairsupport_p%1", _base] setMarkerSizeLocal [0.5, 0.5];
                  format["mk_mandoairsupport_p%1", _base] setMarkerTextLocal format["Plane%1", (_this select 0)+1];

                  while {alive _plane} do
                  {
                     format["mk_mandoairsupport_p%1", _base] setMarkerPosLocal getPos (_this select 1);
                     format["mk_mandoairsupport_p%1", _base] setMarkerDirLocal getDir (_this select 1);
                     Sleep 0.5;
                  };
                  deleteMarkerLocal format["mk_mandoairsupport_p%1", _base];
               };

               _scr = [_plane, _targetpos, false, mando_airsupport_bomb_pos, _extrah + mando_airsupport_bomb_alt+(_this select 0)*10,mando_airsupport_bomb_type]execVM"mando_missiles\mando_bombs\mando_bombs.sqf";
           
               while {!scriptDone _scr} do
               {
                  Sleep 0.5;
                  ((findDisplay 23900) displayCtrl (23905 + (_this select 0))) ctrlSetText format["Plane %1: %2", (_this select 0)+1, (_plane getVariable "mando_airsupport_state")];
                  ((findDisplay 23900) displayCtrl 23909) ctrlEnable false;
                  ((findDisplay 23900) displayCtrl 23910) ctrlEnable false;
                  ((findDisplay 23900) displayCtrl 23912) ctrlSetText "Bomb run mission in progress";
               };
               _plane doMove _spawnpos;
               Sleep 3;
               ((findDisplay 23900) displayCtrl (23905 + (_this select 0))) ctrlSetText format["Plane %1: ----", (_this select 0)+1];
               Sleep 60;
               if (alive _plane) then
               {
                  deleteVehicle _plane;
                  deleteVehicle _driver;
                  deleteGroup _group;
               };
            };
         };


         [] spawn
         {
            disableSerialization;
            Sleep 3;
            while {("Plane 1: ----" != ctrlText ((findDisplay 23900) displayCtrl 23905)) ||
                   ("Plane 2: ----" != ctrlText ((findDisplay 23900) displayCtrl 23906)) ||
                   ("Plane 3: ----" != ctrlText ((findDisplay 23900) displayCtrl 23907)) ||
                   ("Plane 4: ----" != ctrlText ((findDisplay 23900) displayCtrl 23908))} do
            {
               Sleep 1;
            };
            Sleep 4;
            if (!mando_support_no_cas) then
            {
               ((findDisplay 23900) displayCtrl 23909) ctrlEnable true;
            };

            if (!mando_support_no_br) then
            {
               ((findDisplay 23900) displayCtrl 23910) ctrlEnable true;
            };
            ((findDisplay 23900) displayCtrl 23912) ctrlSetText "";
         };
      }
      else
      {
         ((findDisplay 23900) displayCtrl 23902) ctrlSetText "No planes left!";
      };
   };


   case "CALL_CAS":
   {
      _left = call compile format["mando_support_left_%1", mando_support_side];
      if (_left > 0) then
      {
         _nplanes = 1 + lbCurSel ((findDisplay 23900) displayCtrl 23901);
         if (mando_support_side == west) then
         { 
            mando_support_left_WEST = mando_support_left_WEST - _nplanes;
            publicVariable "mando_support_left_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_EAST = mando_support_left_EAST - _nplanes;
               publicVariable "mando_support_left_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_GUER = mando_support_left_GUER - _nplanes;
                  publicVariable "mando_support_left_GUER";
               }
               else
               {
                  mando_support_left_CIV = mando_support_left_CIV - _nplanes;
                  publicVariable "mando_support_left_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_%1", mando_support_side];

         _left = _left - lbSize ((findDisplay 23900) displayCtrl 23901);
         if (_left < 0) then
         {
            for [{_i=0},{_i < abs(_left)},{_i=_i+1}] do
            {
               ((findDisplay 23900) displayCtrl 23901) lbDelete (lbSize ((findDisplay 23900) displayCtrl 23901)-1);
            };
            ((findDisplay 23900) displayCtrl 23901) lbSetCurSel 0;
         };
         ((findDisplay 23900) displayCtrl 23902) ctrlSetText format["Planes available: %1", call compile format["mando_support_left_%1", mando_support_side]];

         ((findDisplay 23900) displayCtrl 23909) ctrlEnable false;
         ((findDisplay 23900) displayCtrl 23910) ctrlEnable false;
         ((findDisplay 23900) displayCtrl 23912) ctrlSetText "CAS mission in progress";



         if (mando_radio_req_cas != "") then
         { 
            player sideRadio mando_radio_req_cas;
         };

         for [{_i=0},{_i < _nplanes},{_i = _i + 1}] do
         {
            [_i] spawn
            {
               disableSerialization;
               private["_plane", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_scr", "_list1", "_list2", "_ntarget", "_target", "_cas", "_logasl", "_speed", "_extrah", "_range", "_log_target"];

               _cas = 0;
               _list1 = nearestObjects [getMarkerPos "mk_mandoairsupport", ["Car","Tank", "StaticWeapon", "Ship"], 500];
               _list2 = []; 
               {
                  if ((side _x != mando_support_side) && (alive _x) && ((count crew _x)>0)) then
                  { 
                     _list2 = _list2 + [_x];
                  };
               } forEach _list1;
               _log_target = objNull;
               if (count _list2 == 0) then
               {
//                  _log_target = "logic" createVehicle [0,0,0];
                  _log_target = "logic" createVehicleLocal [0,0,0];
                  _ang = random 359;
                  _log_target setPos [(getMarkerPos "mk_mandoairsupport" select 0)+sin(_ang)*10*(_this select 0),(getMarkerPos "mk_mandoairsupport" select 1)+cos(_ang)*10*(_this select 0), 0];   
                  _list2 = _list2 + [_log_target];           
                  _list1 = _list1 + [_log_target];
               };

               _ntarget = random (count _list2);
               _ntarget = floor _ntarget;
               _target = _list2 select _ntarget;
               _targetpos = getPos _target;
               _logasl = "logic" createVehicleLocal [0,0,0];
               _logasl setPos [_targetpos select 0, _targetpos select 1, 0];

               if (isNil "mando_airsupport_fixedpos") then
               {
                  if (mando_airsupport_type isKindOf "Helicopter") then
                  {
                     _range = mando_airsupport_range_he;
                  }
                  else
                  {
                     _range = mando_airsupport_range;
                  };
                  _ang = mando_ingress_dir;
               }
               else
               {
                  _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
                  _range = mando_airsupport_fixedpos distance _targetpos;
                  ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
                  mando_ingress_dir = _ang;
               };

               _spawnpos = [(_targetpos select 0) + sin(_ang)*((_range + mando_airsupport_bomb_alt)+(_this select 0)*200), (_targetpos select 1) + cos(_ang)*((_range + mando_airsupport_bomb_alt)+(_this select 0)*200)];
               _plane = createVehicle [mando_airsupport_type, _spawnpos, [], 0, "FLY"];
               _speed = speed _plane;
               _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
               if ((getPosASL _plane select 2) < ((getPosASL _logasl select 2) + mando_airsupport_bomb_alt)) then
               {
                  _plane setPosASL [_spawnpos select 0,_spawnpos select 1, (getPosASL _logasl select 2) + mando_airsupport_bomb_alt + (_this select 0)*15];
                  _extrah = (getPosASL _logasl select 2);
               };

               _plane setDir _ang;
               _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 
               deleteVehicle _logasl;

               _group = createGroup (mando_support_side);
               _driver = _group createUnit ["USMC_Soldier_Pilot",[0,0,30], [], 0, "NONE"];
               _driver setskill 0.5;
               _driver setCombatMode "BLUE";
               _driver setBehaviour "CARELESS";
               _driver moveInDriver _plane;
               _group selectLeader _driver;
/*
               if (!isNil "mando_missile_init") then
               {
                  _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
                  [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
                  processInitCommands;
               };
*/
               if ((_this select 0) == 0) then
               {
                  _plane setVariable ["mando_last_plane_text", "CAS leader camera"];
                  

                  mando_airsupport_cams = mando_airsupport_cams - [objNull];
                  mando_airsupport_cams = mando_airsupport_cams + [_plane];

                  if (mando_radio_rep_cas != "") then
                  {
                     [_driver] spawn
                     {
                        Sleep mando_console_radio_delay;
                        (_this select 0) sideRadio mando_radio_rep_cas;
                     }; 
                  }; 

                  if (!isNil "mando_airsupport_code_cas") then
                  {
                     [_group] spawn mando_airsupport_code_cas;
                  };
               };


               Sleep 1;
               [_this select 0, _plane] spawn
               {
                  disableSerialization;
                  private ["_base", "_plane"];
                  _plane = _this select 1;
                  _base = floor (random 1000);      
                  _marker = createMarkerLocal [format["mk_mandoairsupport_p%1", _base], [getPos _plane select 0, getPos _plane select 1]];
                  format["mk_mandoairsupport_p%1", _base] setMarkerTypeLocal "Arrow";
                  format["mk_mandoairsupport_p%1", _base] setMarkerColorLocal "ColorGreen";
                  format["mk_mandoairsupport_p%1", _base] setMarkerSizeLocal [0.5, 0.5];
                  format["mk_mandoairsupport_p%1", _base] setMarkerTextLocal format["Plane%1", (_this select 0)+1];
   
                  while {alive _plane} do
                  {
                     format["mk_mandoairsupport_p%1", _base] setMarkerPosLocal getPos (_this select 1);
                     format["mk_mandoairsupport_p%1", _base] setMarkerDirLocal getDir (_this select 1);
                     Sleep 0.5;
                  };
                  deleteMarkerLocal format["mk_mandoairsupport_p%1", _base];
               };

               while {(count _list2 > 0) && (alive _plane)} do
               {
                  if (!isNull _log_target) then
                  {
                     _scr = [_plane, getPos _log_target, false, mando_airsupport_bomb_pos, _extrah + mando_airsupport_bomb_alt+(_this select 0)*15,mando_airsupport_bomb_type]execVM"mando_missiles\mando_bombs\mando_bombs.sqf";
                  }
                  else
                  { 
                     _scr = [_plane, _target, false, mando_airsupport_bomb_pos, _extrah + mando_airsupport_bomb_alt+(_this select 0)*15,mando_airsupport_bomb_type]execVM"mando_missiles\mando_bombs\mando_bombs.sqf";
                  };
           
                  while {!scriptDone _scr} do
                  {
                     Sleep 0.5;
                     ((findDisplay 23900) displayCtrl (23905 + (_this select 0))) ctrlSetText format["Plane %1: %2", (_this select 0)+1, (_plane getVariable "mando_airsupport_state")];
                     ((findDisplay 23900) displayCtrl 23909) ctrlEnable false;
                     ((findDisplay 23900) displayCtrl 23910) ctrlEnable false;
                     ((findDisplay 23900) displayCtrl 23912) ctrlSetText "CAS mission in progress";
                  };
                  Sleep 6;

                  if (!isNull _log_target) then
                  {
                     _list1 = _list1 - [_log_target];
                     deleteVehicle _log_target;
                  };

                  _list2 = [];
                  _cas = _cas + 1;                     
                  if (_cas < mando_airsupport_max_cas) then
                  {
                     {
                        if ((side _x != mando_support_side) && (alive _x)) then
                        { 
                           _list2 = _list2 + [_x];
                        };
    
                     } forEach _list1;
 
                     if (count _list2 > 0) then
                     {
                        _ntarget = random (count _list2);
                        _ntarget = floor _ntarget;
                        _target = _list2 select _ntarget;
                     };
                  };
               };
               _plane doMove _spawnpos;
               Sleep 15;
               if (alive _plane) then
               {
                  deleteVehicle _plane;
                  deleteVehicle _driver;
                  deleteGroup _group;
               };
               ((findDisplay 23900) displayCtrl (23905 + (_this select 0))) ctrlSetText format["Plane %1: ----", (_this select 0)+1];
            };
         };

         [] spawn
         {
            disableSerialization;
            Sleep 3;
            while {("Plane 1: ----" != ctrlText ((findDisplay 23900) displayCtrl 23905)) ||
                   ("Plane 2: ----" != ctrlText ((findDisplay 23900) displayCtrl 23906)) ||
                   ("Plane 3: ----" != ctrlText ((findDisplay 23900) displayCtrl 23907)) ||
                   ("Plane 4: ----" != ctrlText ((findDisplay 23900) displayCtrl 23908))} do
            {
               Sleep 1;
            };
            Sleep 4;
            if (!mando_support_no_cas) then
            {
               ((findDisplay 23900) displayCtrl 23909) ctrlEnable true;
            };

            if (!mando_support_no_br) then
            {
               ((findDisplay 23900) displayCtrl 23910) ctrlEnable true;
            };

            ((findDisplay 23900) displayCtrl 23912) ctrlSetText "";
         };
      }
      else
      {
         ((findDisplay 23900) displayCtrl 23902) ctrlSetText "No planes left!";
      };
   };


   case "CALL_CAS_CA":
   {
      ((findDisplay 23900) displayCtrl 23915) ctrlEnable false;
      _left = call compile format["mando_support_left_ca_%1", mando_support_side];
      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_ca_WEST = mando_support_left_ca_WEST - 1;
            publicVariable "mando_support_left_ca_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_ca_EAST = mando_support_left_ca_EAST - 1;
               publicVariable "mando_support_left_ca_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_ca_GUER = mando_support_left_ca_GUER - 1;
                  publicVariable "mando_support_left_ca_GUER";
               }
               else
               {
                  mando_support_left_ca_CIV = mando_support_left_ca_CIV - 1;
                  publicVariable "mando_support_left_ca_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_ca_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               disableSerialization;
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23915) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23915) ctrlSetText format["GS (%1)", _left];

         ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Gunships on the way";

         if (mando_radio_req_gs != "") then
         { 
            player sideRadio mando_radio_req_gs;
         };


         [_left] spawn
         {
            disableSerialization;
            private["_left", "_plane", "_planes", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_i", "_utype", "_speed", "_range"];
            _left = _this select 0;
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);

            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (mando_airsupport_type_ca isKindOf "Helicopter") then
               {
                  _range = mando_airsupport_range_he;
               }
               else
               {
                  _range = mando_airsupport_range;
               };
               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };

            _planes = [];
            for [{_i = 0},{_i < 2},{_i=_i+1}] do
            {
               _spawnpos = [(_targetpos select 0) + sin(mando_ingress_dir)*((_range + mando_airsupport_bomb_alt)+_i*50), (_targetpos select 1) + cos(mando_ingress_dir)*((_range + mando_airsupport_bomb_alt)+_i*50)];

               _plane = createVehicle [mando_airsupport_type_ca, _spawnpos, [], 0, "FLY"];
               _speed = speed _plane;   
               _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
               _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
               _plane setDir _ang;
               _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 
               _planes = _planes + [_plane];

               _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
               _driver setskill 0.5;
               _driver setCombatMode "RED";
               _driver setBehaviour "AWARE";
               if (_i == 0) then
               {
                  _driver setRank "CORPORAL";
                  _group selectLeader _driver;
                  _plane setVariable ["mando_last_plane_text", "Gunships leader camera"];

                  mando_airsupport_cams = mando_airsupport_cams - [objNull];
                  mando_airsupport_cams = mando_airsupport_cams + [_plane];

                  if (mando_radio_rep_gs != "") then
                  {
                     [_driver] spawn
                     {
                        Sleep mando_console_radio_delay;
                        (_this select 0) sideRadio mando_radio_rep_gs;
                     };
                  };

               }
               else
               {
                  _driver setRank "PRIVATE";

                  _plane setVariable ["mando_last_plane_text", "Gunships wingman camera"];

                  mando_airsupport_cams = mando_airsupport_cams - [objNull];
                  mando_airsupport_cams = mando_airsupport_cams + [_plane];

               };
               _driver moveInDriver _plane;
               _gunner = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
               _gunner setCombatMode "RED";
               _gunner setBehaviour "AWARE";
               _gunner setRank "PRIVATE";
               _gunner moveInGunner _plane;
               if (!(_gunner in _plane)) then
               {
                  deleteVehicle _gunner;
               };

               if (_plane isKindOf "Helicopter") then
               {
                  _plane flyinHeight (mando_airsupport_bomb_alt - _i*50) max 200;
               }
               else
               {
                  _plane flyinHeight (mando_airsupport_bomb_alt - _i*50);
               };

               if (!isNil "mando_missile_init") then
               {
/*
                  _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
                  [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
                  processInitCommands;
*/

/*
                  [_plane, 0, ["LandVehicle", "Ship"], 4, 500, 2500+mando_airsupport_bomb_alt, 4, [5, 8, -3], 50, 0, mando_support_enemy_sides, false, false, true, true]exec"mando_missiles\units\attackers\mando_basicag_unit.sqs";
                  Sleep 0.5;
*/
               };
            };
            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "FULL";
            [_group, 1] setWaypointType "SAD";
            _wp = _group addWaypoint [_spawnpos, 0];
            [_group, 2] showWaypoint "NEVER";
            [_group, 2] setWaypointSpeed "FULL";
            [_group, 2] setWaypointType "MOVE";


            if (!isNil "mando_airsupport_code_ca") then
            {
               [_group] spawn mando_airsupport_code_ca;
            };


            [_plane, _left] spawn
            { 
               disableSerialization;
               private["_plane", "_left", "_marker", "_group"];
               _group = group driver (_this select 0);
               _plane = vehicle leader _group;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_ca_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_ca_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_ca_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_ca_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_ca_%1", _left] setMarkerTextLocal "GS";
               while {alive _plane} do
               {
                  _plane = vehicle leader _group; 
                  format["mk_mando_ca_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_ca_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_ca_%1", _left];
            };

/*
            Sleep 4;
            while {!((unitReady leader _group) && (alive leader _group)) || ((!alive leader _group) && ({alive _x} count _planes > 0))} do
            {
               Sleep 2;
            };

            _group move _spawnpos;
            Sleep 4;
            while {!((unitReady leader _group) && (alive leader _group)) || ((!alive leader _group) && ({alive _x} count _planes > 0))} do
            {
               Sleep 2;
            };
*/
            Sleep 6;
            while {((currentWaypoint _group) < (count waypoints _group)) && (alive leader _group)} do
            {
               Sleep 2;
            };


            {
               if (alive vehicle _x) then
               {
                  deleteVehicle vehicle _x;
               };
            } forEach units _group;

            {
               if (alive _x) then
               {
                  deleteVehicle _x;
               };
            } forEach units _group;

            deleteGroup _group;
         };
      };
   };



   case "CALL_PARAS":
   {
      ((findDisplay 23900) displayCtrl 23916) ctrlEnable false;
      _left = call compile format["mando_support_left_pa_%1", mando_support_side];
      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_pa_WEST = mando_support_left_pa_WEST - 1;
            publicVariable "mando_support_left_pa_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_pa_EAST = mando_support_left_pa_EAST - 1;
               publicVariable "mando_support_left_pa_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_pa_GUER = mando_support_left_pa_GUER - 1;
                  publicVariable "mando_support_left_pa_GUER";
               }
               else
               {
                  mando_support_left_pa_CIV = mando_support_left_pa_CIV - 1;
                  publicVariable "mando_support_left_pa_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_pa_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               disableSerialization;
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23916) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23916) ctrlSetText format["AB (%1)", _left];
         ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Airborne assault on the way";


         if (mando_radio_req_ab != "") then
         { 
            player sideRadio mando_radio_req_ab;
         };

         [_left] spawn
         {
            disableSerialization;
            private["_left", "_plane", "_targetpos", "_spawnpos", "_group", "_group_i", "_driver", "_ang", "_i", "_utype", "_unit", "_speed", "_range"];

            _left = _this select 0;  
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);

            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };


            _jump = false;
            if ((ctrlText ((findDisplay 23900) displayCtrl 23961))=="JUMP") then
            { 
               _jump = true;
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (_jump) then
               {
                  if (mando_airsupport_type_pa isKindOf "Helicopter") then
                  {
                     _range = mando_airsupport_range_he;
                  }
                  else
                  {
                     _range = mando_airsupport_range;
                  };
               }
               else
               {
                  if (mando_airsupport_type_pal isKindOf "Helicopter") then
                  {
                     _range = mando_airsupport_range_he;
                  }
                  else
                  {
                  _range = mando_airsupport_range;
                  };
               };

               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };


            _spawnpos = [(_targetpos select 0) + sin(_ang)*_range, (_targetpos select 1) + cos(_ang)*_range];

            if (_jump) then
            {
               _plane = createVehicle [mando_airsupport_type_pa, _spawnpos, [], 0, "FLY"];
            }
            else
            {
               _plane = createVehicle [mando_airsupport_type_pal, _spawnpos, [], 0, "FLY"];
            };
            _speed = speed _plane;
            _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
            _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
            _plane setDir _ang;
            _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


            _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
            _driver setskill 0.5;
            _driver setCombatMode "BLUE";
            _driver setBehaviour "CARELESS";
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
            _driver moveInDriver _plane;

            if (_plane isKindOf "Helicopter") then
            {
               _plane flyinHeight mando_airsupport_bomb_alt max 200;
            }
            else
            {
               _plane flyinHeight mando_airsupport_bomb_alt;
            };



            if (mando_radio_rep_ab != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_rep_ab;
               };
            };

/*
            if (!isNil "mando_missile_init") then
            {
               _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
               [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
               processInitCommands;
            };
*/
            [_plane, _left] spawn
            { 
               disableSerialization;
               private["_plane", "_left", "_marker"];
               _plane = _this select 0;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_pa_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_pa_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_pa_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_pa_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_pa_%1", _left] setMarkerTextLocal "AB";
               while {alive _plane} do
               {
                  format["mk_mando_pa_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_pa_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_pa_%1", _left];
            };

            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "FULL";
            [_group, 1] setWaypointType "MOVE";

            _group_i = createGroup (mando_support_side);
            _i = 0;
            {
               if (_i == 0) then
               {
                  _unit = _group_i createUnit [_x,[0,0,30], [], 0, "NONE"];
                  _unit setCombatMode "RED";
                  _unit setBehaviour "AWARE";
                  _unit setRank "CORPORAL";
                  _group_i selectLeader _unit;
               }
               else
               {
                  _unit = _group_i createUnit [_x,[0,0,30], [], 0, "NONE"];
                  _unit setCombatMode "RED";
                  _unit setBehaviour "AWARE";
                  _unit setRank "PRIVATE";
               };

               if (mando_support_side == civilian) then
               {
                  _unit addMagazine "30Rnd_762x39_AK47";
                  _unit addMagazine "30Rnd_762x39_AK47";
                  _unit addMagazine "30Rnd_762x39_AK47";
                  _unit addWeapon "AK_47_M";
               };
               _unit setskill 0.5;
               _unit moveInCargo _plane;
               if (mando_airsupport_ab_switchable) then
               {
                  addSwitchableUnit _unit;
               };
               _i = _i + 1;
            } forEach mando_support_infantrytype;

            _wp = _group_i addWaypoint [_targetpos, 0];
            [_group_i, 1] showWaypoint "NEVER";
            [_group_i, 1] setWaypointType "SAD";
            _wp = _group_i addWaypoint [_targetpos, 0];
            [_group_i, 2] showWaypoint "NEVER";
            [_group_i, 2] setWaypointType "HOLD";


            if (!isNil "mando_airsupport_code_ab") then
            {
               [_group, _group_i] spawn mando_airsupport_code_ca;
            };


            if (!isNil "mando_airsupport_ab_action") then
            {
               [_group_i] spawn mando_airsupport_ab_action;
            };

            _plane setVariable ["mando_last_plane_text", "Airborne assault transport camera"];

            mando_airsupport_cams = mando_airsupport_cams - [objNull];
            mando_airsupport_cams = mando_airsupport_cams + [_plane];

            Sleep 4;
            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

            if (_jump) then
            {
               if (alive _plane) then
               {
                  {
                     if (alive _x) then
                     {
                        _x action ["EJECT", vehicle _x];
                     };
                     unassignVehicle _x;
                     Sleep 0.75;
                  } forEach units _group_i;

                  if (mando_radio_repr_ab != "") then
                  {
                     [_driver] spawn
                     {
                        Sleep mando_console_radio_delay;
                        (_this select 0) sideRadio mando_radio_repr_ab;
                     };
                  };
               };
            }
            else
            {
               _plane flyinHeight 0;
               _plane doMove _targetpos; 
               Sleep 3;
               waitUntil {(((getPos _plane select 2) < 2) && (alive leader _group)) || (!alive leader _group)};
               Sleep 2;
               if (alive _plane) then
               {
                  {
                     if (alive _x) then
                     {
                        _x action ["getOut", vehicle _x];
                     };
                     unassignVehicle _x;
                     Sleep 1;
                  } forEach units _group_i;

                  if (mando_radio_repr_ab != "") then
                  {
                     [_driver] spawn
                     {
                        Sleep mando_console_radio_delay;
                        (_this select 0) sideRadio mando_radio_repr_ab;
                     };
                  };
               };
               _plane flyinHeight mando_airsupport_bomb_alt max 100;
            };  
            Sleep 2;
            _group move _spawnpos;
            Sleep 4;

            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

            {
               if (alive vehicle _x) then
               {
                  deleteVehicle vehicle _x;
               };
            } forEach units _group;

            {
               if (alive _x) then
               {
                  deleteVehicle _x;
               };
            } forEach units _group;

            deleteGroup _group;
         };
      };
   };


   case "CALL_REINF":
   {
      ((findDisplay 23900) displayCtrl 23926) ctrlEnable false;
      _left = call compile format["mando_support_left_re_%1", mando_support_side];
      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_re_WEST = mando_support_left_re_WEST - 1;
            publicVariable "mando_support_left_re_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_re_EAST = mando_support_left_re_EAST - 1;
               publicVariable "mando_support_left_re_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_re_GUER = mando_support_left_re_GUER - 1;
                  publicVariable "mando_support_left_re_GUER";
               }
               else
               {
                  mando_support_left_re_CIV = mando_support_left_re_CIV - 1;
                  publicVariable "mando_support_left_re_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_re_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               disableSerialization;
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23926) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23926) ctrlSetText format["RE (%1)", _left];
         ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Reinforcements on the way";

         if (mando_radio_req_re != "") then
         { 
            player sideRadio mando_radio_req_re;
         };


         [_left] spawn
         {
            disableSerialization;
            private["_left", "_plane", "_targetpos", "_spawnpos", "_group", "_group_i", "_driver", "_ang", "_i", "_utype", "_unit", "_speed", "_range", "_leader"];
            _leader = player;
            _left = _this select 0;  
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);

            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };

            _jump = false;
            if ((ctrlText ((findDisplay 23900) displayCtrl 23961))=="JUMP") then
            { 
               _jump = true;
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (_jump) then
               {
                  if (mando_airsupport_type_pa isKindOf "Helicopter") then
                  {
                     _range = mando_airsupport_range_he;
                  }
                  else
                  {
                     _range = mando_airsupport_range;
                  };
               }
               else
               {
                  if (mando_airsupport_type_pal isKindOf "Helicopter") then
                  {
                     _range = mando_airsupport_range_he;
                  }
                  else
                  {
                     _range = mando_airsupport_range;
                  };
               };
               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };

            _spawnpos = [(_targetpos select 0) + sin(_ang)*_range, (_targetpos select 1) + cos(_ang)*_range];

            if (_jump) then 
            {
               _plane = createVehicle [mando_airsupport_type_pa, _spawnpos, [], 0, "FLY"];
            }
            else
            {
               _plane = createVehicle [mando_airsupport_type_pal, _spawnpos, [], 0, "FLY"];
            };

            _speed = speed _plane;
            _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
            _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
            _plane setDir _ang;
            _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


            _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
            _driver setskill 0.5;
            _driver setCombatMode "BLUE";
            _driver setBehaviour "CARELESS";
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
            _driver moveInDriver _plane;
            if (_plane isKindOf "Helicopter") then
            {
               _plane flyinHeight mando_airsupport_bomb_alt max 200;
            }
            else
            {
               _plane flyinHeight mando_airsupport_bomb_alt;
            };


/*
            if (!isNil "mando_missile_init") then
            {
               _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
               [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
               processInitCommands;
            };
*/
            if (mando_radio_rep_re != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_rep_re;
               };
            };


            [_plane, _left] spawn
            { 
               disableSerialization;
               private["_plane", "_left", "_marker"];
               _plane = _this select 0;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_re_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_re_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_re_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_re_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_re_%1", _left] setMarkerTextLocal "RE";
               while {alive _plane} do
               {
                  format["mk_mando_re_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_re_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_re_%1", _left];
            };

            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "FULL";
            [_group, 1] setWaypointType "MOVE";

            _group_i = createGroup (mando_support_side);
            _i = 0;
            {
               if (_i == 0) then
               {
                  _unit = _group_i createUnit [_x,[0,0,30], [], 0, "NONE"];
                  _unit setCombatMode "RED";
                  _unit setBehaviour "AWARE";
                  _unit setRank "CORPORAL";
                  _group_i selectLeader _unit;
               }
               else
               {
                  _unit = _group_i createUnit [_x,[0,0,30], [], 0, "NONE"];
                  _unit setCombatMode "RED";
                  _unit setBehaviour "AWARE";
                  _unit setRank "PRIVATE";
               };

               if (mando_support_side == civilian) then
               {
                  _unit addMagazine "30Rnd_545x39_AK";
                  _unit addMagazine "30Rnd_545x39_AK";
                  _unit addMagazine "30Rnd_545x39_AK";
                  _unit addWeapon "AK74";
               };

               _unit setskill 0.5;
               _unit moveInCargo _plane;
               if (mando_airsupport_re_switchable) then
               {
                  addSwitchableUnit _unit;
               };
               _i = _i + 1;
            } forEach mando_support_infantrytype_re;

            _wp = _group_i addWaypoint [_targetpos, 0];
            [_group_i, 1] showWaypoint "NEVER";
            [_group_i, 1] setWaypointType "MOVE";

            if (!isNil "mando_airsupport_code_re") then
            {
               [_group, _group_i] spawn mando_airsupport_code_re;
            };


            if (!isNil "mando_airsupport_re_action") then
            {
               [_group_i] spawn mando_airsupport_re_action;
            };

            _plane setVariable ["mando_last_plane_text", "Reinforcements transport camera"];
            mando_airsupport_cams = mando_airsupport_cams - [objNull];
            mando_airsupport_cams = mando_airsupport_cams + [_plane];

            Sleep 4;
            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

            if (_jump) then
            {
               if (alive _plane) then
               {
                  {
                     if (alive _x) then
                     {
                        _x action ["EJECT", vehicle _x];
                     };
                     unassignVehicle _x;
                     Sleep 0.75;
                  } forEach units _group_i;

                  if (mando_radio_repr_re != "") then
                  {
                     [_driver] spawn
                     {
                        Sleep mando_console_radio_delay;
                        (_this select 0) sideRadio mando_radio_repr_re;
                     };
                  };

               };     
            }
            else
            {
               _plane flyinHeight 0;
               _plane doMove _targetpos; 
               Sleep 3;
               waitUntil {(((getPos _plane select 2) < 2) && (alive leader _group)) || (!alive leader _group)};
               Sleep 2;
               if (alive _plane) then
               {
                  {
                     if (alive _x) then
                     {
                        _x action ["getOut", vehicle _x];
                     };
                     unassignVehicle _x;
                     Sleep 1;
                  } forEach units _group_i;

                  if (mando_radio_repr_re != "") then
                  {
                     [_driver] spawn
                     {
                        Sleep mando_console_radio_delay;
                        (_this select 0) sideRadio mando_radio_repr_re;
                     };
                  };
               };
               _plane flyinHeight mando_airsupport_bomb_alt max 100;
            };
            Sleep 2;
            _group move _spawnpos;


            Sleep 4;


            if ((({alive _x} count units _group_i) > 0) && (alive _leader)) then
            {
               (units _group_i) join group _leader;
            };

            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

            {
               if (alive vehicle _x) then
               {
                  deleteVehicle vehicle _x;
               };
            } forEach units _group;

            {
               if (alive _x) then
               {
                  deleteVehicle _x;
               };
            } forEach units _group;

            deleteGroup _group;
         };
      };
   };



   case "CALL_RECO":
   {
      ((findDisplay 23900) displayCtrl 23923) ctrlEnable false;
      _left = call compile format["mando_support_left_rc_%1", mando_support_side];
      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_rc_WEST = mando_support_left_rc_WEST - 1;
            publicVariable "mando_support_left_rc_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_rc_EAST = mando_support_left_rc_EAST - 1;
               publicVariable "mando_support_left_rc_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_rc_GUER = mando_support_left_rc_GUER - 1;
                  publicVariable "mando_support_left_rc_GUER";
               }
               else
               {
                  mando_support_left_rc_CIV = mando_support_left_rc_CIV - 1;
                  publicVariable "mando_support_left_rc_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_rc_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               disableSerialization;
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23923) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23923) ctrlSetText format["RC (%1)", _left];

         if (mando_radio_req_rc != "") then
         { 
            player sideRadio mando_radio_req_rc;
         };


         [_left] spawn
         {
            disableSerialization;
            private["_left", "_plane", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_i", "_utype", "_unit", "_speed", "_range", "_seconds"];
            _left = _this select 0;  
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);

            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (mando_airsupport_type_rc isKindOf "Helicopter") then
               {
                  _range = mando_airsupport_range_he;
               }
               else
               {
                  _range = mando_airsupport_range;
               };

               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };

            _spawnpos = [(_targetpos select 0) + sin(_ang)*(_range + mando_airsupport_bomb_alt), (_targetpos select 1) + cos(_ang)*(_range + mando_airsupport_bomb_alt)];

            _plane = createVehicle [mando_airsupport_type_rc, _spawnpos, [], 0, "FLY"];
            _speed = speed _plane;
            _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
            _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
            _plane setDir _ang;
            _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


            _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
            _driver setskill 0.5;
            _driver setCombatMode "BLUE";
            _driver setBehaviour "CARELESS";
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
            _driver moveInDriver _plane;

            if (mando_airsupport_rec_captive) then
            {
               _driver setCaptive true;
            };
            _plane flyinHeight mando_airsupport_bomb_alt max 100;
/*
            if (!isNil "mando_missile_init") then
            {
               _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
               [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
               processInitCommands;
            };
*/
            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Reconnaissance aircraft on the way";

            if (mando_radio_rep_rc != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_rep_rc;
               };
            };

            if (!isNil "mando_airsupport_code_rc") then
            {
               [_group] spawn mando_airsupport_code_rc;
            };


            [_plane, _left] spawn
            { 
               disableSerialization;
               private["_plane", "_left", "_marker"];
               _plane = _this select 0;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_rc_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_rc_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_rc_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_rc_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_rc_%1", _left] setMarkerTextLocal "RC";
               while {alive _plane} do
               {
                  format["mk_mando_rc_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_rc_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_rc_%1", _left];
            };

            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "LIMITED";
            [_group, 1] setWaypointType "HOLD";
            _wp = _group addWaypoint [[(_targetpos select 0)+sin(mando_ingress_dir)*4000,(_targetpos select 1)+cos(mando_ingress_dir)*4000], 0];
            [_group, 2] showWaypoint "NEVER";
            [_group, 2] setWaypointSpeed "FULL";
            [_group, 2] setWaypointType "MOVE";


            mando_airsupport_armedrec_num = mando_airsupport_armedrec_max;

            _plane setVariable ["mando_airsupport_armedrec_num", mando_airsupport_armedrec_num];

            _plane setVariable ["mando_last_plane_text", "reco"];
            mando_airsupport_cams = mando_airsupport_cams - [objNull];
            mando_airsupport_cams = mando_airsupport_cams + [_plane];


            [_plane] spawn
            {
               disableSerialization;
               private ["_plane", "_targets", "_array", "_i", "_base"];
               _plane = _this select 0;
               _targets = [];
               while {alive _plane} do
               {
                  _array = nearestObjects [[getPos _plane select 0,getPos _plane select 1,0], ["LandVehicle","Ship"], 400];
                  {
                     if (!(_x in _targets) && (_x != _plane) && (side _x != side _plane) && (alive _x)) then
                     {
                        _targets = _targets + [_x];
                     };
                  } forEach _array;
                  Sleep 1;
               };
               ((findDisplay 23900) displayCtrl 23912) ctrlSetText "Receiving reconnaissance data";
               ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Receiving reconnaissance data";

               []spawn
               {
                  private["_trigger"];
                  _trigger = createTrigger ["EmptyDetector", [0, 0, 0]];
                  _trigger setTriggerActivation ["NONE", "PRESENT", false];
                  _trigger setTriggerArea [0, 0, 0, false];
                  _trigger setTriggerType "NONE";
                  _trigger setTriggerTimeout [0, 0, 0, false ];
                  _trigger setTriggerStatements ["true", "res = [true]execVM""mando_missiles\mando_bombs\mando_airsupportdlg.sqf""", ""];
                  Sleep 6;
                  deleteVehicle _trigger;
               };
               

               Sleep 2;
               _base = random 200;
               _base = floor _base;
               _i = 0;
               {
                  _marker = createMarker [format["mk_mando_rct_%1", _i + _base], getPos _x];
                  format["mk_mando_rct_%1", _i + _base] setMarkerType "Empty";
                  format["mk_mando_rct_%1", _i + _base] setMarkerColor "ColorWhite";
                  format["mk_mando_rct_%1", _i + _base] setMarkerSize [0.25, 0.25];
                  format["mk_mando_rct_%1", _i + _base] setMarkerText typeOf _x;
                  _i = _i + 1;
                  Sleep 0.25;
               } forEach _targets;
               ((findDisplay 23900) displayCtrl 23912) ctrlSetText "reco data available for 2 mins";
               ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Reconnaissance data available for 2 mins";
               Sleep 2;


               mando_reco_side = mando_support_side;
               mando_reco_base = _base; 
               mando_reco_num = count _targets;
               publicVariable "mando_reco_side";
               publicVariable "mando_reco_base";
               publicVariable "mando_reco_num";
               Sleep 120;
               _i = 0;
               {
                  deleteMarker format["mk_mando_rct_%1", _i + _base];
                  _i = _i + 1;
               } forEach _targets;
               ((findDisplay 23900) displayCtrl 23912) ctrlSetText "Reconnaissance data cleared";
               ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Reconnaissance data cleared";
            };

            Sleep 6;

            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};
            Sleep 6;

            _seconds = 16;
            while {_seconds > 0} do
            {
               if (!alive _plane || (mando_last_plane != _plane)) then
               {
                  if (!alive _plane) then
                  {
                     _seconds = 0;
                     ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Reco plane destroyed";
                  }
                  else
                  {
                     _seconds = _seconds - 2;
                     ((findDisplay 23900) displayCtrl 23942) ctrlSetText format ["MSG: Reco, %1 seconds left without camera control before rtb", _seconds];
                  };
               }
               else
               {
                  _seconds = 16;
               };
               Sleep 2;
            };

            if (alive _plane) then
            {
               ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Reco plane egressing";
            };


            deleteWaypoint [_group, 1];
            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};
            Sleep 4;
            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};


            {
               if (alive vehicle _x) then
               {
                  deleteVehicle vehicle _x;
               };
            } forEach units _group;

            {
               if (alive _x) then
               {
                  deleteVehicle _x;
               };
            } forEach units _group;

            deleteGroup _group;
            deleteVehicle mando_support_laserlogic;
         };
      };
   };

////          disableSerialization HASTA AQUI
   case "CALL_EVAC":
   {
      _left = call compile format["mando_support_left_ev_%1", mando_support_side];
      if ((_left > 0) && ((getMarkerPos format["mk_mandoevac_%1", mando_support_side] select 0) > 1)) then
      {
         ((findDisplay 23900) displayCtrl 23941) ctrlEnable false;
         if (mando_support_side == west) then
         { 
            mando_support_left_ev_WEST = mando_support_left_ev_WEST - 1;
            publicVariable "mando_support_left_ev_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_ev_EAST = mando_support_left_ev_EAST - 1;
               publicVariable "mando_support_left_ev_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_ev_GUER = mando_support_left_ev_GUER - 1;
                  publicVariable "mando_support_left_ev_GUER";
               }
               else
               {
                  mando_support_left_ev_CIV = mando_support_left_ev_CIV - 1;
                  publicVariable "mando_support_left_ev_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_ev_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23941) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23941) ctrlSetText format["EV (%1)", _left];

         if (mando_radio_req_ev != "") then
         { 
            player sideRadio mando_radio_req_ev;
         };


         [_left] spawn
         {
            private["_left", "_plane", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_i", "_utype", "_unit", "_marker_name", "_wp", "_distance", "_range"];
            _left = _this select 0;  
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);

            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (mando_airsupport_type_ev isKindOf "Helicopter") then
               {
                  _range = mando_airsupport_range_he;
               }
               else
               {
                  _range = mando_airsupport_range;
               };

               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };

            _spawnpos = [(_targetpos select 0) + sin(_ang)*_range, (_targetpos select 1) + cos(_ang)*_range];
            _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
            _plane = createVehicle [mando_airsupport_type_ev, _spawnpos, [], 0, "FLY"];
            _plane setDir _ang;
            _marker_name = format["mk_mandoevac_%1", mando_support_side];

            _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
            _driver setskill 0.5;
            _driver setCombatMode "BLUE";
            _driver setBehaviour "CARELESS";
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
            _driver moveInDriver _plane;

            if (mando_radio_rep_ev != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_rep_ev;
               };
            };


            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] setWaypointStatements ["true", "if (!(surfaceIsWater getPos (vehicle this))) then{(vehicle this) flyinHeight 0;(vehicle this) land ""LAND""}else{(vehicle this) flyinHeight 3};if (mando_radio_repr_ev != """") then {this sideRadio mando_radio_repr_ev};"];
           
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "FULL";
            [_group, 1] setWaypointType "MOVE";

            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 2] setWaypointStatements ["count crew (vehicle this) > 1", "(vehicle this) flyinHeight 100"];
            [_group, 2] setWaypointTimeout [25, 25, 25];
            [_group, 2] showWaypoint "NEVER";
            [_group, 2] setWaypointSpeed "FULL";
            [_group, 2] setWaypointType "MOVE";

            _distance = _targetpos distance (getMarkerPos _marker_name);
            _ang = (((getMarkerPos _marker_name) select 0) - (_targetpos select 0)) atan2 (((getMarkerPos _marker_name) select 1) - (_targetpos select 1));
            _targetpos = [(_targetpos select 0)+sin(_ang)*_distance/2,(_targetpos select 1)+cos(_ang)*_distance/2];
            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 3] setWaypointStatements ["true", ""];
            [_group, 3] setWaypointTimeout [0, 0, 0];
            [_group, 3] showWaypoint "NEVER";
            [_group, 3] setWaypointSpeed "FULL";
            [_group, 3] setWaypointType "MOVE";
             
            _targetpos = getMarkerPos _marker_name;
            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 4] setWaypointStatements ["true", "(vehicle this) flyinHeight 0;(vehicle this) land ""LAND"""];
            [_group, 4] showWaypoint "NEVER";
            [_group, 4] setWaypointSpeed "FULL";
            [_group, 4] setWaypointType "MOVE";

            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 5] setWaypointStatements ["count crew (vehicle this) < 2", "(vehicle this) flyinHeight 100"];
            [_group, 5] setWaypointTimeout [0, 0, 0];
            [_group, 5] showWaypoint "NEVER";
            [_group, 5] setWaypointSpeed "FULL";
            [_group, 5] setWaypointType "MOVE";

            _targetpos = [(_targetPos select 0)+sin(_ang)*3000, (_targetPos select 1)+cos(_ang)*3000, 100];
            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 6] setWaypointStatements ["true", "deleteVehicle (vehicle this);deleteVehicle this"];
            [_group, 6] setWaypointTimeout [0, 0, 0];
            [_group, 6] showWaypoint "NEVER";
            [_group, 6] setWaypointSpeed "FULL";
            [_group, 6] setWaypointType "MOVE";

/*

            if (!isNil "mando_missile_init") then
            {
               _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
               [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
               processInitCommands;
            };
*/
            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Evacuation chopper on the way";

            if (!isNil "mando_airsupport_code_ev") then
            {
               [_group] spawn mando_airsupport_code_ev;
            };


            _plane setVariable ["mando_last_plane_text", "Evacuation transport camera"];
            mando_airsupport_cams = mando_airsupport_cams - [objNull];
            mando_airsupport_cams = mando_airsupport_cams + [_plane];

            [_plane, _left] spawn
            { 
               private["_plane", "_left", "_marker"];
               _plane = _this select 0;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_ev_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_ev_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_ev_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_ev_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_ev_%1", _left] setMarkerTextLocal "EV";
               while {alive _plane && ((count crew _plane) > 0)} do
               {
                  format["mk_mando_ev_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_ev_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_ev_%1", _left];
            };
         };
      };

      if ((getMarkerPos format["mk_mandoevac_%1", mando_support_side] select 0) <= 1) then
      {
         []spawn
         {
            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Select evac destination first. Left mouse click over map while pressing left shift";
            Sleep 7;
            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG:";
         };
      };
   };



   case "CALL_AMMO":
   {
      ((findDisplay 23900) displayCtrl 23924) ctrlEnable false;
      _left = call compile format["mando_support_left_am_%1", mando_support_side];
      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_am_WEST = mando_support_left_am_WEST - 1;
            publicVariable "mando_support_left_am_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_am_EAST = mando_support_left_am_EAST - 1;
               publicVariable "mando_support_left_am_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_am_GUER = mando_support_left_am_GUER - 1;
                  publicVariable "mando_support_left_am_GUER";
               }
               else
               {
                  mando_support_left_am_CIV = mando_support_left_am_CIV - 1;
                  publicVariable "mando_support_left_am_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_am_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23924) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23924) ctrlSetText format["AM (%1)", _left];

         if (mando_radio_req_am != "") then
         { 
            player sideRadio mando_radio_req_am;
         };

         [_left] spawn
         {
            private["_left", "_plane", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_i", "_utype", "_unit", "_speed", "_range"];
            _left = _this select 0;  
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);


            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (mando_airsupport_type_am isKindOf "Helicopter") then
               {
                  _range = mando_airsupport_range_he;
               }
               else
               {
                  _range = mando_airsupport_range;
               };

               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };



            _spawnpos = [(_targetpos select 0) + sin(_ang)*_range, (_targetpos select 1) + cos(_ang)*_range];

            _plane = createVehicle [mando_airsupport_type_am, _spawnpos, [], 0, "FLY"];
            _speed = speed _plane;
            _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
            _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
            _plane setDir _ang;
            _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


            _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
            _driver setskill 0.5;
            _driver setCombatMode "BLUE";
            _driver setBehaviour "CARELESS";
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
            _driver moveInDriver _plane;
            if (_plane isKindOf "Helicopter") then
            {
               _plane flyinHeight mando_airsupport_bomb_alt max 200;
            }
            else
            {
               _plane flyinHeight mando_airsupport_bomb_alt;
            };


/*
            if (!isNil "mando_missile_init") then
            {
               _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
               [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
               processInitCommands;
            };
*/
            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Ammo supply on the way";

            if (mando_radio_rep_am != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_rep_am;
               };
            };


            [_plane, _left] spawn
            { 
               private["_plane", "_left", "_marker"];
               _plane = _this select 0;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_am_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_am_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_am_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_am_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_am_%1", _left] setMarkerTextLocal "AM";
               while {alive _plane} do
               {
                  format["mk_mando_am_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_am_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_am_%1", _left];
            };

            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] setWaypointType "MOVE";
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "NORMAL";
            [_group, 1] setWaypointBehaviour "CARELESS";
            [_group, 1] setWaypointCombatMode "BLUE";

            if (!isNil "mando_airsupport_code_am") then
            {
               [_group] spawn mando_airsupport_code_am;
            };


            _plane setVariable ["mando_last_plane_text", "Ammo supply transport camera"];
            mando_airsupport_cams = mando_airsupport_cams - [objNull];
            mando_airsupport_cams = mando_airsupport_cams + [_plane];

            Sleep 2;
            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

            if ((alive _plane) && ((WaypointPosition[_group, 1] distance _plane) > 500)) then
            {
               ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Ammo supply failed to reach destination";
            };
              

            if (alive _plane) then
            {
               for [{_i=0},{_i < 2},{_i = _i + 1}] do
               { 
                  [_plane]spawn
                  {
                     private["_plane", "_para", "_box", "_pos", "_weaps"];
                     _plane = _this select 0;

                     _pos  = _plane modelToWorld [0,-6, -6];
                     _para = "ParachuteWest" createVehicle [0,0,0];
                     _para setPos _pos;
                     _box = mando_airsupport_type_ambox createVehicle [0,0,0];
                     _weaps = "";
                     if ((count mando_airsupport_magz) > 0) then
                     {
                        _weaps = "clearMagazineCargo this;";
                        {
                           _weaps = _weaps + format["this addMagazineCargo [""%1"", %2];", (_x select 0),(_x select 1)];
                        } forEach mando_airsupport_magz;
                     };

                     if ((count mando_airsupport_weap) > 0) then
                     {
                        _weaps = _weaps + "clearWeaponCargo this;";
                        {
                           _weaps = _weaps + format["this addWeaponCargo [""%1"", %2];", (_x select 0),(_x select 1)];
                        } forEach mando_airsupport_weap;
                     };

                     if (_weaps != "") then
                     {
                        _box SetVehicleInit _weaps;
                        processInitCommands;
                     };

                     while {(getPos _para select 2) > 2.5} do 
                     {
                        _box setPos (_para modelToWorld [0,0,-2]);
                        _box setVectorDir (vectorDir _para);
                        _box setVectorUp (vectorUp _para);
                        Sleep 0.002;
                     };
                     _box setDir 0;
                     _box setPos [getPos _para select 0, getPos _para select 1, 0];
                  };
                  Sleep 3;
               };
            };

            if (mando_radio_repr_am != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_repr_am;
               };
            };

            _group move _spawnpos;
            Sleep 4;

            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

            {
               if (alive vehicle _x) then
               {
                  deleteVehicle vehicle _x;
               };
            } forEach units _group;

            {
               if (alive _x) then
               {
                  deleteVehicle _x;
               };
            } forEach units _group;

            deleteGroup _group;
         };
      };
   };


   case "CALL_VEH":
   {
      ((findDisplay 23900) displayCtrl 23925) ctrlEnable false;
      _left = call compile format["mando_support_left_ve_%1", mando_support_side];
      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_ve_WEST = mando_support_left_ve_WEST - 1;
            publicVariable "mando_support_left_ve_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_ve_EAST = mando_support_left_ve_EAST - 1;
               publicVariable "mando_support_left_ve_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_ve_GUER = mando_support_left_ve_GUER - 1;
                  publicVariable "mando_support_left_ve_GUER";
               }
               else
               {
                  mando_support_left_ve_CIV = mando_support_left_ve_CIV - 1;
                  publicVariable "mando_support_left_ve_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_ve_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23925) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23925) ctrlSetText format["VE (%1)", _left];


         if (mando_radio_req_ve != "") then
         { 
            player sideRadio mando_radio_req_ve;
         };

         [_left] spawn
         {
            private["_left", "_plane", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_i", "_utype", "_unit", "_speed", "_truck", "_range"];
            _left = _this select 0;  
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);

            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (mando_airsupport_type_ve isKindOf "Helicopter") then
               {
                  _range = mando_airsupport_range_he;
               }
               else
               {
                  _range = mando_airsupport_range;
               };

               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };

            _spawnpos = [(_targetpos select 0) + sin(_ang)*_range, (_targetpos select 1) + cos(_ang)*_range];

            _plane = createVehicle [mando_airsupport_type_ve, _spawnpos, [], 0, "FLY"];
            _speed = speed _plane;
            _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
            _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
            _plane setDir _ang;
            _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 

            _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
            _driver setskill 0.5;
            _driver setCombatMode "BLUE";
            _driver setBehaviour "CARELESS";
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
            _driver moveInDriver _plane;
            if (_plane isKindOf "Helicopter") then
            {
               _plane flyinHeight mando_airsupport_bomb_alt max 200;
            }
            else
            {
               _plane flyinHeight mando_airsupport_bomb_alt;
            };

/*
            if (!isNil "mando_missile_init") then
            {
               _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
               [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
               processInitCommands;
            };
*/
            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Vehicle supply on the way";


            if (mando_radio_rep_ve != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_rep_ve;
               };
            };

            [_plane, _left] spawn
            { 
               private["_plane", "_left", "_marker"];
               _plane = _this select 0;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_ve_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_ve_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_ve_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_ve_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_ve_%1", _left] setMarkerTextLocal "VE";
               while {alive _plane} do
               {
                  format["mk_mando_ve_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_ve_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_ve_%1", _left];
            };

            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "FULL";
            [_group, 1] setWaypointType "MOVE";

            if (!isNil "mando_airsupport_code_ve") then
            {
               [_group] spawn mando_airsupport_code_ve;
            };

            Sleep 4;

            _plane setVariable ["mando_last_plane_text", "Vehicle supply transport camera"];
            mando_airsupport_cams = mando_airsupport_cams - [objNull];
            mando_airsupport_cams = mando_airsupport_cams + [_plane];

            _truck = mando_airsupport_type_vehicle createVehicle [0,0,0];
            _truck  attachTo [_plane, [0,-1,-10]];

            while {(alive _plane) && !(unitReady leader _group)} do
            {
               Sleep 1;
            };

            if (alive _plane) then
            {
               _plane flyinHeight 10;
               _plane doMove [getPos _plane select 0,getPos _plane select 1, 10];
               Sleep 2;

               while {(alive _plane) && (abs(velocity _plane select 2) > 0.2) && ((getPos _plane select 2) > 20)} do
               {
                  Sleep 1;
               };
            };
            detach _truck;

            if ((_truck isKindOf "StaticWeapon") || (_truck isKindOf "Static"))then
            {           
               [_truck, _plane modelToWorld [0,-1,-10]] spawn 
               {
                  private["_cargo", "_timeold", "_deltatime", "_vel", "_pos"]; 
                  _cargo = _this select 0;
                  _pos = _this select 1;
                  _timeold = time;
                  _vel = 0;

                  while {(_pos select 2) > 0} do
                  {
                     _deltatime = (time-_timeold) max 0.001;
                     _timeold = time;
                     _vel = _vel + 9.8*_deltatime;
                     _pos = [_pos select 0, _pos select 1, (_pos select 2) - _vel * _deltatime];
                     _cargo setPos _pos;
                     Sleep 0.001;
                  };
                  _cargo setPos [_pos select 0, _pos select 1, 0];
               };
            }; 

            _plane flyinHeight 100;
            _group move _spawnpos;
            Sleep 4;

            if (mando_radio_repr_ve != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_repr_ve;
               };
            };


            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

            {
               if (alive vehicle _x) then
               {
                  deleteVehicle vehicle _x;
               };
            } forEach units _group;

            {
               if (alive _x) then
               {
                  deleteVehicle _x;
               };
            } forEach units _group;

            deleteGroup _group;
         };
      };
   };


   case "CALL_CAP":
   {
      ((findDisplay 23900) displayCtrl 23927) ctrlEnable false;
      _left = call compile format["mando_support_left_cp_%1", mando_support_side];
      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_cp_WEST = mando_support_left_cp_WEST - 1;
            publicVariable "mando_support_left_cp_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_cp_EAST = mando_support_left_cp_EAST - 1;
               publicVariable "mando_support_left_cp_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_cp_GUER = mando_support_left_cp_GUER - 1;
                  publicVariable "mando_support_left_cp_GUER";
               }
               else
               {
                  mando_support_left_cp_CIV = mando_support_left_cp_CIV - 1;
                  publicVariable "mando_support_left_cp_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_cp_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23927) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23927) ctrlSetText format["CP (%1)", _left];


         ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Combat air patrol on the way";

         if (mando_radio_req_ca != "") then
         { 
            player sideRadio mando_radio_req_ca;
         };


         [_left] spawn
         {
            private["_left", "_plane", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_i", "_utype", "_speed", "_range"];
            _left = _this select 0;
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);

            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (mando_airsupport_type_cp isKindOf "Helicopter") then
               {
                  _range = mando_airsupport_range_he;
               }
               else
               {
                  _range = mando_airsupport_range;
               };
               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };


            for [{_i = 0},{_i < 2},{_i=_i+1}] do
            {
               _spawnpos = [(_targetpos select 0) + sin(_ang)*((_range + mando_airsupport_bomb_alt)+_i*50), (_targetpos select 1) + cos(_ang)*((_range + mando_airsupport_bomb_alt)+_i*50)];

               _plane = createVehicle [mando_airsupport_type_cp, _spawnpos, [], 0, "FLY"];
               _speed = speed _plane;
               _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
               _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
               _plane setDir _ang;
               _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 

               _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
               _driver setskill 0.5;
               _driver setCombatMode "RED";
               _driver setBehaviour "AWARE";
               if (_i == 0) then
               {
                  _driver setRank "CORPORAL";
                  _group selectLeader _driver;
                  if (mando_radio_rep_ve != "") then
                  {
                     [_driver] spawn
                     {
                        Sleep mando_console_radio_delay;
                        (_this select 0) sideRadio mando_radio_rep_ca;
                     };
                  };

                  _plane setVariable ["mando_last_plane_text", "CAP leader camera"];
                  mando_airsupport_cams = mando_airsupport_cams - [objNull];
                  mando_airsupport_cams = mando_airsupport_cams + [_plane];

                  if (!isNil "mando_airsupport_code_cp") then
                  {
                     [_group] spawn mando_airsupport_code_cp;
                  };

               }
               else
               {
                  _driver setRank "PRIVATE";
                  _plane setVariable ["mando_last_plane_text", "CAP wingman camera"];
                  mando_airsupport_cams = mando_airsupport_cams - [objNull];
                  mando_airsupport_cams = mando_airsupport_cams + [_plane];

               };
               _driver moveInDriver _plane;
               _plane flyinHeight mando_airsupport_bomb_alt max 100;
               if (!isNil "mando_missile_init") then
               {
/*
                  _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
                  [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
                  processInitCommands;
*/

                  [_plane, 0, ["Air"], 6, 500, 2900+mando_airsupport_bomb_alt, 15, [6, 5, -3], 50, 0, mando_support_enemy_sides, false, false, true, true]exec"mando_missiles\units\attackers\mando_aim120_fighter.sqs";
                  Sleep 0.5;
               };
            };
            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "FULL";
            [_group, 1] setWaypointType "HOLD";


            [_plane, _left] spawn
            { 
               private["_plane", "_left", "_marker", "_group"];
               _group = group driver (_this select 0);
               _plane = vehicle leader _group;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_cp_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_cp_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_cp_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_cp_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_cp_%1", _left] setMarkerTextLocal "CP";
               while {alive _plane} do
               {
                  format["mk_mando_cp_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_cp_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_cp_%1", _left];
            };
         };
      };
   };


   case "CALL_LASER":
   {
      ((findDisplay 23900) displayCtrl 23945) ctrlEnable false;
      _left = call compile format["mando_support_left_la_%1", mando_support_side];
      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_la_WEST = mando_support_left_la_WEST - 1;
            publicVariable "mando_support_left_la_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_la_EAST = mando_support_left_la_EAST - 1;
               publicVariable "mando_support_left_la_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_la_GUER = mando_support_left_la_GUER - 1;
                  publicVariable "mando_support_left_la_GUER";
               }
               else
               {
                  mando_support_left_la_CIV = mando_support_left_la_CIV - 1;
                  publicVariable "mando_support_left_la_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_la_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23945) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23945) ctrlSetText format["LA (%1)", _left];


         if (mando_radio_req_la != "") then
         { 
            player sideRadio mando_radio_req_la;
         };


         [_left] spawn
         {
            private["_left", "_plane", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_i", "_utype", "_unit", "_speed", "_range"];
            _left = _this select 0;  
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);

            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (mando_airsupport_type_la isKindOf "Helicopter") then
               {
                  _range = mando_airsupport_range_he;
               }
               else
               {
                  _range = mando_airsupport_range;
               };

               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };

            _spawnpos = [(_targetpos select 0) + sin(_ang)*(_range + mando_airsupport_bomb_alt), (_targetpos select 1) + cos(_ang)*(_range + mando_airsupport_bomb_alt)];

            _plane = createVehicle [mando_airsupport_type_la, _spawnpos, [], 0, "FLY"];
            _speed = speed _plane;
            _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
            _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
            _plane setDir _ang;
            _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


            _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
            _driver setskill 0.5;
            _driver setCombatMode "GREEN";
            _driver setBehaviour "CARELESS";
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
            _driver moveInDriver _plane;
            _plane flyinHeight mando_airsupport_bomb_alt max 100;

            if (mando_radio_rep_la != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_rep_la;
               };
            };


            if (!isNil "mando_missile_init") then
            {
/*
               _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
               [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
               processInitCommands;
*/

               [_plane, 0, ["REMOTE"], 2, 500, 2500+mando_airsupport_bomb_alt, 4, [4, 1, -4], 50, 0, [sideLogic]+mando_support_enemy_sides, false, false, true, true]exec"mando_missiles\units\attackers\mando_lgb.sqs";

            };

            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Laser guided bombs aircraft on the way";

            if (!isNil "mando_airsupport_code_la") then
            {
               [_group] spawn mando_airsupport_code_la;
            };

            _plane setVariable ["mando_last_plane_text", "Laser bombs support camera"];
            mando_airsupport_cams = mando_airsupport_cams - [objNull];
            mando_airsupport_cams = mando_airsupport_cams + [_plane];


            [_plane, _left] spawn
            { 
               private["_plane", "_left", "_marker"];
               _plane = _this select 0;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_la_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_la_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_la_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_la_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_la_%1", _left] setMarkerTextLocal "LA";
               while {alive _plane} do
               {
                  format["mk_mando_la_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_la_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_la_%1", _left];
            };


            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "LIMITED";
            [_group, 1] setWaypointType "MOVE";
            _wp = _group addWaypoint [[(_targetpos select 0)+sin(mando_ingress_dir)*4000,(_targetpos select 1)+cos(mando_ingress_dir)*4000], 0];
            [_group, 2] showWaypoint "NEVER";
            [_group, 2] setWaypointSpeed "LIMITED";
            [_group, 2] setWaypointType "MOVE";

            Sleep 4;
            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};
            Sleep 4;
            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};


            {
               if (alive vehicle _x) then
               {
                  deleteVehicle vehicle _x;
               };
            } forEach units _group;

            {
               if (alive _x) then
               {
                  deleteVehicle _x;
               };
            } forEach units _group;

            deleteGroup _group;
         };
      };
   };


   case "CALL_CARPET":
   {
      ((findDisplay 23900) displayCtrl 23937) ctrlEnable false;
      _left = call compile format["mando_support_left_cb_%1", mando_support_side];
      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_cb_WEST = mando_support_left_cb_WEST - 1;
            publicVariable "mando_support_left_cb_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_cb_EAST = mando_support_left_cb_EAST - 1;
               publicVariable "mando_support_left_cb_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_cb_GUER = mando_support_left_cb_GUER - 1;
                  publicVariable "mando_support_left_cb_GUER";
               }
               else
               {
                  mando_support_left_cb_CIV = mando_support_left_cb_CIV - 1;
                  publicVariable "mando_support_left_cb_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_cb_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               Sleep mando_airsupport_planes_delay;
               ((findDisplay 23900) displayCtrl 23937) ctrlEnable true;
            };
         };
         ((findDisplay 23900) displayCtrl 23937) ctrlSetText format["CB (%1)", _left];


         if (mando_radio_req_cb != "") then
         { 
            player sideRadio mando_radio_req_cb;
         };


         [_left] spawn
         {
            private["_left", "_plane", "_targetpos", "_spawnpos", "_group", "_driver", "_ang", "_i", "_utype", "_unit", "_speed", "_range"];
            _left = _this select 0;  
            _targetpos = getMarkerPos "mk_mandoairsupport";
            _group = createGroup (mando_support_side);

            switch (mando_support_side) do
            {
               case west:
               {
                  _utype = "USMC_Soldier_Pilot";
               };
               case east:
               {
                  _utype = "RU_Soldier_Pilot";
               };
               case resistance:
               {
                  _utype = "GUE_Soldier_Pilot";
               };
               case civilian:
               {
                  _utype = "RU_Citizen1";
               };
            };

            if (isNil "mando_airsupport_fixedpos") then
            {
               if (mando_airsupport_type_cb isKindOf "Helicopter") then
               {
                  _range = mando_airsupport_range_he;
               }
               else
               {
                  _range = mando_airsupport_range;
               };

               _ang = mando_ingress_dir;
            }
            else
            {
               _ang = ((mando_airsupport_fixedpos select 0)-(_targetpos select 0)) atan2 ((mando_airsupport_fixedpos select 1)-(_targetpos select 1));
               _range = mando_airsupport_fixedpos distance _targetpos;
               ((findDisplay 23900) displayCtrl 23920) sliderSetPosition _ang;
               mando_ingress_dir = _ang;
            };

            _spawnpos = [(_targetpos select 0) + sin(_ang)*(_range + mando_airsupport_bomb_alt), (_targetpos select 1) + cos(_ang)*(_range + mando_airsupport_bomb_alt)];

            _plane = createVehicle [mando_airsupport_type_cb, _spawnpos, [], 0, "FLY"];
            _speed = speed _plane;
            _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
            _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
            _plane setDir _ang;
            _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


            _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
            _driver setskill 0.5;
            _driver setCombatMode "BLUE";
            _driver setBehaviour "CARELESS";
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
            _driver moveInDriver _plane;
            _plane flyinHeight mando_airsupport_bomb_alt max 100;

            if (mando_radio_rep_cb != "") then
            {
               [_driver] spawn
               {
                  Sleep mando_console_radio_delay;
                  (_this select 0) sideRadio mando_radio_rep_cb;
               };
            };

/*
            if (!isNil "mando_missile_init") then
            {
               _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
               [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
               processInitCommands;
            };
*/

            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Carpet bombing aircraft on the way";

            if (!isNil "mando_airsupport_code_cb") then
            {
               [_group] spawn mando_airsupport_code_cb;
            };

            _plane setVariable ["mando_last_plane_text", "Carpet bombing camera"];
            mando_airsupport_cams = mando_airsupport_cams - [objNull];
            mando_airsupport_cams = mando_airsupport_cams + [_plane];


            [_plane, _left] spawn
            { 
               private["_plane", "_left", "_marker"];
               _plane = _this select 0;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_cb_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_cb_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_cb_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_cb_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_cb_%1", _left] setMarkerTextLocal "CB";
               while {alive _plane} do
               {
                  format["mk_mando_cb_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_cb_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 1;
               };
               deleteMarkerLocal format["mk_mando_cb_%1", _left];
            };


            if (!isNil "mando_airsupport_carpetcode") then
            {
               [_plane, _targetpos] spawn mando_airsupport_carpetcode;
            }; 

            _wp = _group addWaypoint [_targetpos, 0];
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "FULL";
            [_group, 1] setWaypointType "MOVE";
            _wp = _group addWaypoint [[(_targetpos select 0)+sin(mando_ingress_dir)*3000,(_targetpos select 1)+cos(mando_ingress_dir)*3000], 0];
            [_group, 2] showWaypoint "NEVER";
            [_group, 2] setWaypointSpeed "FULL";
            [_group, 2] setWaypointType "MOVE";

/*
            Sleep 4;
            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};
            Sleep 4;
            waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};
*/
            Sleep 6;
            while {((currentWaypoint _group) < (count waypoints _group)) && (alive leader _group)} do
            {
               Sleep 2;
            };



            {
               if (alive vehicle _x) then
               {
                  deleteVehicle vehicle _x;
               };
            } forEach units _group;

            {
               if (alive _x) then
               {
                  deleteVehicle _x;
               };
            } forEach units _group;

            deleteGroup _group;

         };
      };
   };



   case "CALL_CRUISEMISSILE":
   {
      ((findDisplay 23900) displayCtrl 23917) ctrlEnable false;
      _left = call compile format["mando_support_left_cm_%1", mando_support_side];

      if (!alive mando_airsupport_cmissile) then 
      {
         _left = 0;
         ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Cruise missile launcher not present";
      };

      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_cm_WEST = mando_support_left_cm_WEST - 1;
            publicVariable "mando_support_left_cm_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_cm_EAST = mando_support_left_cm_EAST - 1;
               publicVariable "mando_support_left_cm_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_cm_GUER = mando_support_left_cm_GUER - 1;
                  publicVariable "mando_support_left_cm_GUER";
               }
               else
               {
                  mando_support_left_cm_CIV = mando_support_left_cm_CIV - 1;
                  publicVariable "mando_support_left_cm_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_cm_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               Sleep mando_airsupport_missile_delay;
               ((findDisplay 23900) displayCtrl 23917) ctrlEnable true;
            };
         };

         if (mando_radio_req_cm != "") then
         { 
            player sideRadio mando_radio_req_cm;
         };

         [_left] spawn
         {
            private ["_target", "_target2", "_dir"];
            _target = "logic" createVehicleLocal [0,0,0];
            _target2 = "logic" createVehicleLocal [0,0,0];

            _target setPos [getMarkerPos "mk_mandoairsupport" select 0, getMarkerPos "mk_mandoairsupport" select 1, 0];
            _target2 setPos [getMarkerPos "mk_mandoairsupport" select 0, getMarkerPos "mk_mandoairsupport" select 1, 0];

            _dir = ((getPos _target select 0)-(getPos mando_airsupport_cmissile select 0)) atan2 ((getPos _target select 1)-(getPos mando_airsupport_cmissile select 1));

            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Cruise missile on the way";

            if (mando_radio_rep_cm != "") then
            {
               [] spawn
               {
                  Sleep mando_console_radio_delay;
                  [mando_support_side, "HQ"] sideRadio mando_radio_rep_cm;
               };
            };


            [mando_airsupport_cmissile, "CruiseMissile2", mando_airsupport_cmissile_pos, _dir, 80, 0, 250, 100, _target, 5, 2000, 0, mando_airsupport_cmissile_alt, "mando_missiles\warheads\mando_missilehead2a.sqf", "mando_missiles\exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 100, true, 5, 0, 0, true, true, "mando_missiles\launch\mando_scudlaunch.sqf", 10, 15, 1, true, 180, 180] execVM "mando_missiles\mando_missile.sqf";
               
            mando_last_missile_target = _target; 
            mando_last_target = _target2;
            waitUntil {!isNull mando_missile};
            mando_last_missile = mando_missile;


            [mando_missile, (_this select 0)] spawn
            { 
               private["_plane", "_left", "_marker"];
               _plane = _this select 0;
               _left = _this select 1;
               _marker = createMarkerLocal [format["mk_mando_cm_%1", _left], [getPos _plane select 0, getPos _plane select 1]];
               format["mk_mando_cm_%1", _left] setMarkerTypeLocal "Arrow";
               format["mk_mando_cm_%1", _left] setMarkerColorLocal "ColorGreen";
               format["mk_mando_cm_%1", _left] setMarkerSizeLocal [0.5, 0.5];
               format["mk_mando_cm_%1", _left] setMarkerTextLocal "CM";
               while {alive _plane} do
               {
                  format["mk_mando_cm_%1", _left] setMarkerDirLocal getDir _plane;
                  format["mk_mando_cm_%1", _left] setMarkerPosLocal getPos _plane;
                  Sleep 0.5;
               };
               deleteMarkerLocal format["mk_mando_cm_%1", _left];
            };

               
            Sleep 100;
            deleteVehicle _target;

            deleteVehicle _target2;

         };
         ((findDisplay 23900) displayCtrl 23917) ctrlSetText format["CM (%1)", _left];
      };
   };


   case "CALL_MISSILESAT":
   {
      ((findDisplay 23900) displayCtrl 23928) ctrlEnable false;
      _left = call compile format["mando_support_left_sa_%1", mando_support_side];

      if (!alive mando_airsupport_cmissile) then 
      {
         _left = 0;
         ((findDisplay 23900) displayCtrl 23912) ctrlSetText "Cruise missile launcher not present";
      };

      if (_left > 0) then
      {
         if (mando_support_side == west) then
         { 
            mando_support_left_sa_WEST = mando_support_left_sa_WEST - 1;
            publicVariable "mando_support_left_sa_WEST";
         }
         else
         {
            if (mando_support_side == east) then
            { 
               mando_support_left_sa_EAST = mando_support_left_sa_EAST - 1;
               publicVariable "mando_support_left_sa_EAST";
            }
            else
            {
               if (mando_support_side == resistance) then
               { 
                  mando_support_left_sa_GUER = mando_support_left_sa_GUER - 1;
                  publicVariable "mando_support_left_sa_GUER";
               }
               else
               {
                  mando_support_left_sa_CIV = mando_support_left_sa_CIV - 1;
                  publicVariable "mando_support_left_sa_CIV";
               };
            };
         };
   
         _left = call compile format["mando_support_left_sa_%1", mando_support_side];
         if (_left > 0) then
         {
            []spawn
            {
               Sleep mando_airsupport_missile_delay;
               ((findDisplay 23900) displayCtrl 23928) ctrlEnable true;
            };
         };

         if (mando_radio_req_sa != "") then
         { 
            player sideRadio mando_radio_req_sa;
         };

         [] spawn
         {
            private ["_target", "_dir", "_list1", "_list2", "_i", "_target2"];
            _list1 = nearestObjects [getMarkerPos "mk_mandoairsupport", ["Car","Tank", "StaticWeapon", "Ship"], 500];
            _list2 = []; 
            {
               if ((side _x != mando_support_side) && (alive _x) && ((count crew _x)>0)) then
               { 
                  _list2 = _list2 + [_x];
               };
            } forEach _list1;

            if (count _list2 == 0) then
            {
               _target2 = "logic" createVehicleLocal [0,0,0];
               _target2 setPos [getMarkerPos "mk_mandoairsupport" select 0,getMarkerPos "mk_mandoairsupport" select 1, 0];
               _list2 = _list2 + [_target2];
               [_target2]spawn
               {
                  Sleep 100;
                  deleteVehicle (_this select 0);
               };
            };

            if (count _list2 > 0) then
            {
               ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Cruise missiles on the way";

               if (mando_radio_rep_sa != "") then
               {
                  [] spawn
                  {
                     Sleep mando_console_radio_delay;
                     [mando_support_side, "HQ"] sideRadio mando_radio_rep_sa;
                  };
               };


               for [{_i = 0},{_i < ((count _list2) min 4)},{_i=_i+1}] do
               {
                  _target = _list2 select _i;
 
                  _dir = ((getPos _target select 0)-(getPos mando_airsupport_cmissile select 0)) atan2 ((getPos _target select 1)-(getPos mando_airsupport_cmissile select 1));

                  [mando_airsupport_cmissile, "CruiseMissile2", mando_airsupport_cmissile_pos, _dir, 89, 0, 300, 100, _target, 5, 2000, 0, 800, "mando_missiles\warheads\mando_missilehead2a.sqf", "mando_missiles\exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 100, true, 5, 0, 0, true, false, "mando_missiles\launch\mando_scudlaunch.sqf", 25, 35, 1, true, 180, 180] execVM "mando_missiles\mando_missile.sqf";
                  Sleep 2;  
                  [mando_airsupport_cmissile, "CruiseMissile2", mando_airsupport_cmissile_pos, _dir, 89, 0, 300, 100, _target, 5, 2000, 0, 800, "mando_missiles\warheads\mando_missilehead2a.sqf", "mando_missiles\exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 50, true, 5, 0, 0, true, false, "mando_missiles\launch\mando_scudlaunch.sqf", 25, 35, 1, true, 180, 180] execVM "mando_missiles\mando_missile.sqf";
                  Sleep 2;
               };
            }
            else
            {
               ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: No targets in the area";
            };
         };
         ((findDisplay 23900) displayCtrl 23928) ctrlSetText format["SA (%1)", _left];
      };
   };


   case "ZOOM_IN":
   {
      if (mando_cam_scale > 0.2) then
      {
         mando_cam_scale = mando_cam_scale - 0.1;
      };

      if (mando_recocam_scale > 0.1) then
      {
         mando_recocam_scale = mando_recocam_scale - 0.1;
      };
   };

   case "ZOOM_OUT":
   {
      if (mando_cam_scale < 1) then
      {
         mando_cam_scale = mando_cam_scale + 0.1;
      };

      if (mando_recocam_scale < 1) then
      {
         mando_recocam_scale = mando_recocam_scale + 0.1;
      };
   };

   case "INGRESS_CHANGE":
   {
      mando_ingress_dir = sliderPosition ((findDisplay 23900) displayCtrl 23920);
   };

   case "INGRESS_ALT_CHANGE":
   {
      mando_airsupport_bomb_alt = sliderPosition ((findDisplay 23900) displayCtrl 23922);
      ((findDisplay 23900) displayCtrl 23921) ctrlSetText format["Ingress min alt: %1m", floor mando_airsupport_bomb_alt];
   };


   case "FREE_FALL":
   {
      ((findDisplay 23900) displayCtrl 23913) ctrlSetTextColor [0, 1, 0, 1];
      ((findDisplay 23900) displayCtrl 23914) ctrlSetTextColor [0, 0, 0, 1];
      mando_airsupport_bomb_type = "Bo_GBU12_LGB";
   };

   case "SADARM":
   {
      ((findDisplay 23900) displayCtrl 23913) ctrlSetTextColor [0, 0, 0, 1];
      ((findDisplay 23900) displayCtrl 23914) ctrlSetTextColor [0, 1, 0, 1];
      mando_airsupport_bomb_type = "SADARM";
   };

   case "CALL_REC_FIRE":
   {
      if (alive mando_last_reco && !(isNil "mando_missile_init")) then
      {
         if (!isNull mando_support_laserlogic) then
         {
            if ((mando_last_reco getVariable "mando_airsupport_armedrec_num") > 0) then
            {
               if (!mando_airsupport_armedrec_man) then
               {
                  [mando_last_reco,"M_Maverick_AT", [-3*mando_airsupport_pilon,2,-3], getDir mando_last_reco, -3, 10, 278, 120, mando_support_laserlogic, 5, 3500, 1, 100, mando_missile_path+"warheads\mando_missilehead1a.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 20, false, 0.5, 0, 0.5, false, false, "", 70, 40, 1, true, 180, 90] execVM "mando_missiles\mando_missile.sqf";
               }
               else
               {
                  _target = "logic" createVehicleLocal [0,0,0];
                  _target2 = "logic" createVehicleLocal [0,0,0];

                  _target setPos (getPos mando_support_laserlogic);
                  _target2 setPos (getPos mando_support_laserlogic);

                  [mando_last_reco,"M_Maverick_AT", [-3*mando_airsupport_pilon,2,-3], getDir mando_last_reco, -3, 10, 278, 120, _target, 5, 3500, 1, 100, mando_missile_path+"warheads\mando_missilehead1a.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 20, false, 0.5, 0, 0, false, true, "", 20, 20, 1, true, 180, 90] execVM "mando_missiles\mando_missile.sqf";

                  [_target, _target2]spawn
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

               mando_airsupport_pilon = -mando_airsupport_pilon;

               mando_last_reco setVariable ["mando_airsupport_armedrec_num", (mando_last_reco getVariable "mando_airsupport_armedrec_num") - 1];
               ((findDisplay 23900) displayCtrl 23946) ctrlSetText format["Fire: %1", mando_last_reco getVariable "mando_airsupport_armedrec_num"]; 
            };
         };
      };
   };

   case "CALL_REC_FLIR":
   {  
      if (mando_rec_flir) then
      {
         mando_rec_flir = false;
         setAperture -1;
      }
      else
      {
         mando_rec_flir = true;
         setAperture 0.065;
      };
   };

   case "CALL_JUMP":
   {  
      if ((ctrlText ((findDisplay 23900) displayCtrl 23961))=="JUMP") then
      {
         ((findDisplay 23900) displayCtrl 23961) ctrlSetText "LAND";
         mando_airsupport_jump = false;
      }
      else
      {
         ((findDisplay 23900) displayCtrl 23961) ctrlSetText "JUMP";
         mando_airsupport_jump = true;
      };
   };
   
   case "CALL_RC_OFF":
   {
      mando_reco_cam = 0;
      mando_last_plane=objNull;
   };

   case "CALL_RC_ON":
   {  
      _i = 0;
      {
         if (!alive _x) then
         { 
            mando_airsupport_cams set [_i, objNull];
         };

         _i = _i + 1;
      } forEach mando_airsupport_cams;
      mando_airsupport_cams = mando_airsupport_cams - [objNull];
      if (alive mando_last_missile) then
      {
         mando_recocam_angles = [0,0];
         mando_reco_cam = 1;
      }
      else
      {
         if (count mando_airsupport_cams > 0) then
         {
            mando_airsupport_cur_cam = mando_airsupport_cur_cam + 1;
            if (mando_airsupport_cur_cam >= count mando_airsupport_cams) then
            {
               mando_airsupport_cur_cam = 0;
            };
            _plane = mando_airsupport_cams select mando_airsupport_cur_cam;
            _text = _plane getVariable "mando_last_plane_text";

            mando_recocam_angles = [0,0];

            if (!isNil "_text") then
            {
               if (_text == "reco") then
               {
                  mando_last_reco = mando_airsupport_cams select mando_airsupport_cur_cam;
                  if (mando_rec_flir) then
                  {
                      setAperture 0.065;
                  };
                  ((findDisplay 23900) displayCtrl 23946) ctrlSetText format["Fire: %1", _plane getVariable "mando_airsupport_armedrec_num"];
               }
               else
               {
                  if (mando_rec_flir) then
                  {
                     setAperture -1;
                  };
                  mando_last_reco = objNull;
               };
               mando_last_plane = mando_airsupport_cams select mando_airsupport_cur_cam;
               mando_reco_cam = 1;
            }
            else
            {
               mando_last_plane = objNull;
               mando_reco_cam = 0;
            };
         };
      };      
   };

   default {};
};

true