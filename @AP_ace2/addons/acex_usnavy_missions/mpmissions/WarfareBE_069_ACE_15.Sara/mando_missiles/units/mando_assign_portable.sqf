/* mando_assignvehicle_by_type.sqf
By Mandoble June 2007

Purpose:
   Waits until a player is in a vehicle which type is in the provided array, and then gives that vehicle missile and/or flare/chaff capability. Missiles and chaff/flares will work manually, controlled by the player.
This script must be executed in every machine where there is a player.

Arguments: 
   Array of vehicle types ["Su34", "Su34B", ...]
   Player's position inside the vehicle: 0 = driver, 1 = gunner
   Name of the vehicle's weapon used to fire and aim the missiles, "" if none (aiming with the vehicle's nose)
   Maximum number of missiles array [AA missiles, AG missiles]
   Current number of missiles array [AA missiles, AG missiles]
   Maximum number of flares/chaff
   Current number of flares/chaff
   Control script name (mando_missilevehicle.sqf or any other similar to that one)
   Is the vehicle able to fire against vehicles or ships? true/false
   Is the vehicle able to fire against air targets? true/false
   Is the vehicle able to fire against buildings? true/false
   Is the vehicle able to fire against remote targets (acquired by others)? true/false
   Firing position in vehicle coordinates from where the missiles will be fired
   Keyboard control script (the missile parameters are customized there)
   HUD horizontal arc in degrees
   HUD vertical arc in degrees
   Weapon sight vertical delta (aproximate height of the sight of the selected weapon, distance over the center of the unit).
   Array with missile index numbers: [x,y]. x for AA targets, y for the rest.
       missile indexes >= 0 are for virtual missiles, < 0 for BIS loaded missiles (abs(index)+1)

   Is the vehicle able to fire against active radar targets? true/false
   HUD type (0 complete, 1 map only, 2 targeting only, 3 only quantities of missiles and flares)
   Zoom (-1 or >0). If the units for the indicated position have initially zoomed in optics set this to a value > 0. This parameter is optional, if not provided to zoom will be calculated based on unit types.
*/


private ["_plane", "_aa", "_ag", "_af", "_ar", "_ara", "_ao", "_ak", "_ah", "_var", "_maxmissiles", "_actmissiles", "_maxflares", "_actflares", "_ttypes", "_inplane", "_planetype", "_position", "_weapon", "_ctrlscript", "_gvtargets", "_airtargets", "_structargets", "_remottargets", "_firingpos", "_keyscript", "_hudopenh", "_hudopenv", "_driver", "_gunner", "_class", "_missileidx", "_radartargets", "_hudtype", "_zoom", "_res", "_maxecm"];

_planetypes    = _this select 0;
_position      = _this select 1;
_weapon        = _this select 2;
_maxmissiles   = _this select 3;
_actmissiles   = _this select 4;
_maxflares     = _this select 5;
_actflares     = _this select 6;
_maxecm        = _this select 7;
_firingpos     = _this select 8;
_keyscript     = _this select 9;
_hudopenh      = _this select 10; // Ajuste X de hud
_hudopenv      = _this select 11; // Ajuste Y de hud
_missileidx    = _this select 12;
_hudtype       = _this select 13; // HUD type



_plane = objNull;
_ttypes = [];
while {true} do
{
   waitUntil {!isNull player};

   while {((currentWeapon vehicle player) != _weapon) || (!alive player)} do
   {
      Sleep 1;
   };

   _plane = vehicle player;


   _var = _plane getVariable "mando_maxflares";
   if (isNil "_var") then 
   {
      _plane setVariable ["mando_maxflares",_maxflares ,true];
   };

   _var = _plane getVariable "mando_flaresleft";
   if (isNil "_var") then 
   {
      _plane setVariable ["mando_flaresleft",_actflares ,true];
   };

   _plane setVariable ["mando_ecm_max_time", _maxecm];

   mando_missileidxbase = _missileidx;
  
   mando_ihavemissiles = false;
   mando_ihaveflares   = false;

   Sleep 1;
   mando_hud_heartbeat = 0;
   _res = [_plane, _ttypes, _weapon, _firingpos, _keyscript, _position, _hudopenh, _hudopenv, _hudtype, _zoom]execVm mando_missile_path+"units\mando_missile_hud_portable.sqf";
   Sleep 2;
   _old_heart_beat = -1;
   while {((currentWeapon vehicle player) == _weapon) && (alive player) && !(vehicle player isKindOf "Air")} do
   {
      Sleep 1;
      if (mando_hud_heartbeat == _old_heart_beat) then
      {
         Sleep 1;
         if (!mando_exit_hud) then
         { 
            mando_exit_hud = true;
            Sleep 2;
            _old_heart_beat = -1;
            mando_hud_heartbeat = 0;
         
            _res = [_plane, _ttypes, _weapon, _firingpos, _keyscript, _position, _hudopenh, _hudopenv, _hudtype, _zoom]execVm mando_missile_path+"units\mando_missile_hud_portable.sqf";

            Sleep 2;
         };
      }
      else
      {
         _old_heart_beat = mando_hud_heartbeat;
      };

   };

   Sleep 2;
};