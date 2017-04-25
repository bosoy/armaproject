/* mando_comallow_by_name.sqf
By Mandoble June 2007

Purpose:
   Waits until a player is in a vehicle which name is in the provided array, and then gives that vehicle MCC capability. 

Arguments: 
   Array of vehicle names
   Maximum number of missiles
   Current number of missiles left
   Target types array. Valid values inside that array are "RADAR", "REMOTE", "Air" and "Vehicles". [] for none.
   Text of the action to activate this MCC
   mcc script to be executed upon activation 
   missile launch position relative to the vehicle
   mcc camera position relative to the vehicle
   position of the player to activate this mcc: 0 - driver, 1 - gunner, 2 - commander
   Fixed direction of the missile launch relative to direction of the vehicle, or < 0 for any direction.
   Missile index number for the vehicle
   Background color array for the MCC console [R,G,B,A]
   Number of scans to get ready to fire again after a shot (scan frequency is configured in the selected mcc activation script.
   
   

Examples:

*/

private ["_names", "_maxmissiles", "_actmissiles", "_targettypes", "_actiontext", "_mcconscript", "_launchpos", "_camerapos", "_position", "_plane", "_var", "_inplane", "_position", "_fixeddir", "_driver", "_gunner", "_commander", "_vehiclename", "_actionidx", "_missileidx", "_backcolor", "_scanstoload"];


_names       = _this select 0;
_maxmissiles = _this select 1;
_actmissiles = _this select 2;
_targettypes = _this select 3;
_actiontext  = _this select 4;
_mcconscript = _this select 5;
_launchpos   = _this select 6;
_camerapos   = _this select 7;
_position    = _this select 8;
_fixeddir    = _this select 9;
_missileidx  = _this select 10;
_backcolor   = _this select 11;
_scanstoload = _this select 12;


while {true} do
{
   waitUntil {!isNull player};

   _inplane = false;

   while {!_inplane} do
   {
      Sleep 1;

      if ((vehicle player) != player) then
      {
         _vehiclename = vehicleVarName (vehicle player);

         if (_vehiclename in _names) then
         {
            _driver = driver vehicle player;
            _gunner = gunner vehicle player;
            _commander = commander vehicle _player;
            if (((_position == 0) && (_driver == player)) || 
                ((_position == 1) && (_gunner == player)) ||
                ((_position == 2) && (_commander == player))) then
            {
               _inplane = true;
               _plane = vehicle player;
            };
         };
      };
   };


   Sleep _missileidx/8;

   mando_vehvar_vehicler = _plane;
   mando_vehvar_r = format["mando_maxmissiles%1", _missileidx];
   mando_vehvar_requestr = true;
   {publicVariable _x} forEach ["mando_vehvar_vehicler", "mando_vehvar_r", "mando_vehvar_requestr"];
   Sleep 0.5;
   mando_vehvar_vehicler = _plane;
   mando_vehvar_r = format["mando_missilesleft%1", _missileidx];
   mando_vehvar_requestr = true;
   {publicVariable _x} forEach ["mando_vehvar_vehicler", "mando_vehvar_r", "mando_vehvar_requestr"];
   Sleep 0.5;


   _var = _plane getVariable format["mando_maxmissiles%1", _missileidx];
   if (isNil "_var") then
   {
      mando_vehvar_vehiclew = _plane;
      mando_vehvar_w = format["mando_maxmissiles%1", _missileidx];
      mando_vehvar_valuew = _maxmissiles;
      mando_vehvar_requestw = true;
      {publicVariable _x} forEach ["mando_vehvar_vehiclew", "mando_vehvar_w", "mando_vehvar_valuew", "mando_vehvar_requestw"];
      Sleep 0.5;
   };   

   _var = _plane getVariable format["mando_missilesleft%1", _missileidx];
   if (isNil "_var") then
   {
      mando_vehvar_vehiclew = _plane;
      mando_vehvar_w = format["mando_missilesleft%1", _missileidx];
      mando_vehvar_valuew = _actmissiles;
      mando_vehvar_requestw = true;
      {publicVariable _x} forEach ["mando_vehvar_vehiclew", "mando_vehvar_w", "mando_vehvar_valuew", "mando_vehvar_requestw"];
      Sleep 0.5;
   };

   _actionidx =  _plane addAction [_actiontext, _mcconscript, [_targettypes, _launchpos, _camerapos, _fixeddir,_missileidx,_backcolor,_scanstoload]];

   if (_position == 0) then
   {
      while {driver _plane == player} do
      {
         Sleep 1;
      };
   }
   else
   {
      if (_position == 1) then
      {
         while {gunner _plane == player} do
         {
            Sleep 1;
         };
      }
      else
      {
         while {commander _plane == player} do
         {
            Sleep 1;
         };
      };
   };
   _plane removeAction _actionidx;

   _inplane = false;

   Sleep 2;
};