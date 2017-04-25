/*
mando_missileinit.sqf v2.3
April 2007 Mandoble

Execute this script before any other one related to mando missiles
For MP missions, make sure this script is executed in every client and server init.sqs or init.sqf

Here you may change the default keys uses to fire missiles too, and the minimum altitude of air units to be locked on by automatic missile launchers.

Parameters:
   Script suite = false / Addon version = true
   Minimum altitude of air targets over ground to be able to lock on them (this affects also AI mando missile units).
   Minimum extra distance between missile and target and missile and countermeasure to ensure the missile will be affected by the countermeasure.
   Maximum range to check LOS between launcher and potential target, targets farther than that will pass the LOS check without performing it.   
   
*/

private["_keys"];

if (!isNil "mando_missile_init") exitWith
{
//   hint "Mando Missile already initialized";
};

[]spawn
{
   if (!isDedicated) then
   {
      while {!alive player} do
      {
         Sleep 1;
      };
      Sleep 1;
      call compile format["mando_missile_init_%1 = true",getPlayerUID player];
      publicVariable format["mando_missile_init_%1", getPlayerUID player];
   };
};


mando_missile_init = true;
mando_missile_init_done = false;
if (isNil "mando_missile_stealth") then
{
   mando_missile_stealth = [];
};
// Path for scripts 
mando_missile_path = "mando_missiles\";
// Minimum altitude for Air units to be detected by radar
mando_minairalt = 10;
// If missile distance to target + mando_minchaffdist is less than missile distance to chaff/flares, the missile will  follow the target
mando_minchaffdist = 0;
// Maximum range to perform LOS checks
mando_loscheck_range = 3000;
// Maximum range to show enemies IDs on HUD
mando_max_dist_id = 2000;

if (isNil "echo_fallout_number") then
{
	echo_fallout_number = -1;
};

if (count _this > 0) then
{
   if (_this select 0) then
   {
      if(!isClass (configFile >> "CfgPatches" >> "Mando_Missile_Addon")) then
      {
         hint "Mando Missile Addon required!";         
      };

      mando_missile_path = "\mando_missiles\";
   }
   else
   {
      mando_missile_path = "mando_missiles\";
   };

   if (count _this > 1) then
   {
      mando_minairalt = _this select 1;
      if (count _this > 2) then
      {
         mando_minchaffdist = _this select 2;
         if (count _this > 3) then
         {
            mando_loscheck_range = _this select 3;
         };
      };
   };
}
else
{
   if(!isClass (configFile >> "CfgPatches" >> "Mando_Missile_Addon"))then
   {
       // The addon version is not present
       mando_missile_path = "mando_missiles\";
   }
   else
   {
       mando_missile_path = "\mando_missiles\";
   };
};

mando_main_display = 46;

// If true, any missile, even if not present into mando_replacemissile.sqf will be replaced by a generic mando one.
mando_replace_all_missiles = true;


// Actions for lock, flares, fire, mode, ecm, eject
_keys = actionKeys "NetworkStats";
if (count _keys > 0) then
{
   if ((_keys select 0) < 255) then
   {
      // SCORE KEY
      mando_keyscore = _keys select 0;
      mando_keyscorename = keyName mando_keyscore;
      mando_keyscore_temp = mando_keyscore;
      mando_keyscorename_temp = mando_keyscorename;
   };
};


_keys = actionKeys "lockTargets";
if (count _keys > 0) then
{
   if ((_keys select 0) < 255) then
   {
      // LOCKON KEY
      mando_keylock = _keys select 0;
      mando_keylockname = keyName mando_keylock;
      mando_keylock_temp = mando_keylock;
      mando_keylockname_temp = mando_keylockname;
   };
};

if (isNil "mando_keylock") then
{
   // Keys for lock target, fire missile and drop chaff/flare
   // TAB (15) by default
   mando_keylock = 15;
   mando_keylockname = keyName mando_keylock;
   mando_keylock_temp = mando_keylock;
   mando_keylockname_temp = mando_keylockname;
};


_keys = actionKeys "user16";
if (count _keys == 4) then
{
   if (((_keys select 0) == 30) && ((_keys select 1) == 48) && ((_keys select 2) == 46)) then
   {
      // FIRE KEY
      mando_keyfire = _keys select 3;
      mando_keyfirename = keyName mando_keyfire;
      mando_keyfire_temp = mando_keyfire;
      mando_keyfirename_temp = mando_keyfirename;
   };
};

if (isNil "mando_keyfire") then
{
   // L. WIN (219) by default
   mando_keyfire = 219;
   mando_keyfirename = keyName mando_keyfire;
   mando_keyfire_temp = mando_keyfire;
   mando_keyfirename_temp = mando_keyfirename;
};


_keys = actionKeys "user17";
if (count _keys == 4) then
{
   if (((_keys select 0) == 30) && ((_keys select 1) == 48) && ((_keys select 2) == 46)) then
   {
      // FLARES KEY
      mando_keyflare = _keys select 3;
      mando_keyflarename = keyName mando_keyflare;
      mando_keyflare_temp = mando_keyflare;
      mando_keyflarename_temp = mando_keyflarename;
   };
};

if (isNil "mando_keyflare") then
{
   // L. SHIFT (42)
   mando_keyflare = 42;
   mando_keyflarename = keyName mando_keyflare;
   mando_keyflare_temp = mando_keyflare;
   mando_keyflarename_temp = mando_keyflarename;
};

_keys = actionKeys "user18";
if (count _keys == 4) then
{
   if (((_keys select 0) == 30) && ((_keys select 1) == 48) && ((_keys select 2) == 46)) then
   {
      // HUD MODE KEY
      mando_keymode = _keys select 3;
      mando_keymodename = keyName mando_keymode;
      mando_keymode_temp = mando_keymode;
      mando_keymodename_temp = mando_keymodename;
   };
};

if (isNil "mando_keymode") then
{
   // L CONTROL (29) by default
   mando_keymode = 29;
   mando_keymodename = keyName mando_keymode;
   mando_keymode_temp = mando_keymode;
   mando_keymodename_temp = mando_keymodename;
};


_keys = actionKeys "user19";
if (count _keys == 4) then
{
   if (((_keys select 0) == 30) && ((_keys select 1) == 48) && ((_keys select 2) == 46)) then
   {
      // ECM KEY
      mando_keyecm = _keys select 3;
      mando_keyecmname = keyName mando_keyecm;
      mando_keyecm_temp = mando_keyecm;
      mando_keyecmname_temp = mando_keyecmname;
   };
};

if (isNil "mando_keyecm") then
{
   // R (19) by default
   mando_keyecm = 19;
   mando_keyecmname = keyName mando_keyecm;
   mando_keyecm_temp = mando_keyecm;
   mando_keyecmname_temp = mando_keyecmname;
};


_keys = actionKeys "user20";
if (count _keys == 4) then
{
   if (((_keys select 0) == 30) && ((_keys select 1) == 48) && ((_keys select 2) == 46)) then
   {
      // Special KEY
      mando_keyspecial = _keys select 3;
      mando_keyspecialname = keyName mando_keyspecial;
      mando_keyspecial_temp = mando_keyspecial;
      mando_keyspecialname_temp = mando_keyspecialname;
   };
};

if (isNil "mando_keyspecial") then
{
   // G (34) by default
   mando_keyspecial = 34;
   mando_keyspecialname = keyName mando_keyspecial;
   mando_keyspecial_temp = mando_keyspecial;
   mando_keyspecialname_temp = mando_keyspecialname;
};


mando_scorefunc = compile (preprocessFileLineNumbers (mando_missile_path+"mando_score.sqf"));
mando_keyconfighandlerfunc = compile (preprocessFileLineNumbers (mando_missile_path+"units\mando_keyconfighandlerfunc.sqf"));
mando_keyhandler = compile (preprocessFileLineNumbers (mando_missile_path+"units\mando_keyhandler.sqf"));
mando_mccmousemap = compile (preprocessFileLineNumbers (mando_missile_path+"mcc\mando_mccmousemap.sqf"));
mando_check_los = compile (preprocessFileLineNumbers (mando_missile_path+"mando_check_los.sqf"));
mando_missile_replaced = compile (preprocessFileLineNumbers (mando_missile_path+"mando_replacemissile.sqf"));
mando_setVDirAndUp = compile (preprocessFileLineNumbers (mando_missile_path+"mando_SetVDirAndUp.sqf"));
mando_chaffflares = compile (preprocessFileLineNumbers (mando_missile_path+"mando_chaffflares.sqf"));
mando_hud_key_handler = compile (preprocessFileLineNumbers (mando_missile_path+"units\mando_hud_key_handler.sqf"));
mando_weaponindex = compile (preprocessFileLineNumbers (mando_missile_path+"mando_weaponindex.sqf"));
mando_missile_rearm = compile (preprocessFileLineNumbers (mando_missile_path+"units\mando_rearm_vehicle.sqf"));

// Add here any class that has any initial zoom level for gunner to correct the optics
mando_optics = ["ZSU","BMP2","BRDM2", "BRDM2_ATGM", "Stryker_ICV_M2", "Stryker_ICV_MK19", "Stryker_TOW", "T72", "M1Abrams", "RHIB", "RHIB2Turret", "HMMWV50", "HMMWVMK", "HMMWVTOW", "Truck5tMG", "LandroverMG", "UAZMG", "UAZ_AGS30"];


mando_weapons_forbidden = ["ACE_B61BombLauncher"];
mando_rearm_sources_classes = ["MtvrReammo", "KamazReammo", "UralReammo_INS", "UralReammo_CDF", "WarfareReammoTruck_USMC","WarfareReammoTruck_RU","WarfareReammoTruck_Gue", "DFReammo_Base"];

//No mando missile in debug mode in-flight
mando_missile=objNull;

//Detectable missiles array init
mando_missilearray = [];
mando_detmissiles = [];
mando_detowners = [];
mando_detmissilereq = false;
mando_detmissile = objNull;
mando_detmissileowner = objNull;

mando_hide_bis_hud = false; // BIS HUD covered by red bars by default
mando_hud_colors_idx = 0;
mando_hud_colors_sets = [
[[0.5,1,0.5],[0.5,1,0.5],[0.5,1,0.5],[0.5,1,0.5],[0.5,1,0.5],[0.5,1,0.5]],
[[1,0.5,0],[1,0.5,0],[1,0.5,0],[1,0.5,0],[1,0.5,0],[1,0.5,0]],
[[0.5,1,0.5],[0.5,1,0.5],[0.5,1,0.5],[0.5,1,0.5],[0.5,1,0.5],[0.5,1,0.5]],
[[0,0.7,0.5],[0,0.7,0.5],[0,0.7,0.5],[0,0.7,0.5],[0,0.7,0.5],[0,0.7,0.5]]
];
mando_hud_colors_toggled = false;
mando_show_hint_global = true;
mando_fire_exclusive = false;

mando_mccpredicam = false;

mando_missileincomming = objNull;
mando_missiletarget = objNull;
mando_missilerequest = false;

mando_missilechafflauncher = objNull;
mando_missilechaff = objNull;
mando_missilechaffdraw = -1;

mando_missilesmoke = false;
mando_missilesmoke_script = "";
mando_missilesmoke_mis = objNull;

mando_deton_req = false;
mando_deton_x = 0;
mando_deton_y = 0;
mando_deton_z = 0;
mando_deton_target = objNull;
mando_deton_side = civilian;
mando_deton_launcher = objNull;
mando_deton_script = "";

mando_launch_req = false;
mando_launch_mis = objNull;
mando_launch_script = "";

mando_lockedon = objNull;
mando_warning = objNull;

// Array with weapons considered laser designators
mando_lasers = ["Laserdesignator","Laserdesignator_mounted", "Kiowa_Laser", "MAF_nh90_laser"];

mando_commanded_west = [];
mando_commanded_east = [];
mando_commanded_res  = [];
mando_commanded_civ  = [];
/*
mando_rwrpos = [SafeZoneX+0.022, 0.1, 0.2, 0.2*4/3];
mando_rwrpos_full = [SafeZoneX, 0.1-0.030, 0.244, 0.244*4/3];
*/
mando_rwrpos = [SafeZoneX + 0.024, 0.15, 0.2, 0.2 * 4 / 3];
mando_rwrpos_full = [SafeZoneX, 0.15 - 0.032, 0.248, 0.248 * 4 / 3];


//[0.378, 0.746, 0.244, 0.244 * 4 / 3]
//[0.400, 0.776, 0.200, 0.200 * 4 / 3]

mando_rwrimg_west = mando_missile_path+"mandotarget_rwr_west.paa";
mando_rwrimg_east = mando_missile_path+"mandotarget_rwr_east.paa";


[]execVM mando_missile_path+"mando_launches.sqf";
[]execVM mando_missile_path+"mando_detonations.sqf";
[]execVM mando_missile_path+"mando_smokedraw.sqf";
[]execVM mando_missile_path+"mando_chaffflaredraw.sqf";
[]execVM mando_missile_path+"mando_detectables.sqf";

//[]execVM mando_missile_path+"mando_vehvars.sqf";

[]execVM mando_missile_path+"mando_remotes.sqf";
[]execVM mando_missile_path+"mando_remote_commands.sqf";
[]execVM mando_missile_path+"mando_radars.sqf";
[]execVM mando_missile_path+"mando_lockedon.sqf";
[]execVM mando_missile_path+"mando_warning.sqf";
[]execVM mando_missile_path+"mando_gun_lite\mando_guncheck_lite.sqf";

mando_score_cars = 0;
mando_score_planes = 0;
mando_score_choppers = 0;
mando_score_tanks = 0;
mando_score_ships = 0;
mando_score_static = 0;
mando_score_crews = 0;
mando_score_missiles = 0;

mando_missile_version = 2.4;
Sleep 1;
[]execVM mando_missile_path+"mando_giveme_score.sqf";
mando_missile_init_done = true;
if (isServer) then
{
   mando_missile_init_done_server = true;
   publicVariable "mando_missile_init_done_server";

   []spawn
   {
      private["_found"];
      while {true} do
      {
         Sleep 240;
         _found = false;
         {
            if (isPlayer _x) then
            {            
               if (isNil format["mando_missile_init_%1", getPlayerUID _x]) then
               {
                  _x setVehicleInit "if (local this) then {hintSilent ""Is Mando Missile missing client side?\nServer has it already initialized.""}";
                  _found = true;
               };
            };
         } forEach playableUnits;
  
         if (_found) then
         {
            processInitCommands;
         };
      };
   };
};