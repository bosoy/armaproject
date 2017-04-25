/* 
mando_mccallow_by_type.sqf v2.35
By Mandoble Jan 2009

Purpose:
   Waits until a player is in a vehicle which type is in the provided array, and then gives that vehicle MCC capability. 

Arguments: 
   Array of vehicle types
   Maximum number of missiles
   Current number of missiles left
   Target types array. Valid values inside that array are "RADAR", "REMOTE", "Air", "Ships" and "Vehicles". [] for none.
   Text of the action to activate this MCC
   mcc script to be executed upon activation 
   missile launch position relative to the vehicle
   mcc camera position relative to the vehicle
   position of the player to activate this mcc: 0 - driver, 1 - gunner, 2 - commander OR string with array of assigned role, for example "[""Turret"",[0]]" for the gunner of an AH1W
   Fixed direction of the missile launch relative to direction of the vehicle, or < 0 for any direction.
   Missile index number for the vehicle
   Background color array for the MCC console [R,G,B,A]
   Number of scans to get ready to fire again after a shot (scan frequency is configured in the selected mcc activation script).
   Vertical launch angle (>= -89 <= 89), if not between these values, vertical angle is calculated dinamically.   
   

Examples:

*/

private ["_planetypes", "_maxmissiles", "_actmissiles", "_targettypes", "_actiontext", "_mcconscript", "_launchpos", "_camerapos", "_position", "_positioncode", "_plane", "_var", "_inplane", "_fixeddir", "_missileidx", "_driver", "_gunner", "_commander", "_class", "_actionidx", "_backcolor", "_scanstoload", "_vangle"];


_planetypes  = _this select 0;
_maxmissiles = _this select 1;
_actmissiles = _this select 2;
_targettypes = _this select 3;
_actiontext  = _this select 4;
_mcconscript = _this select 5;
_launchpos   = _this select 6;
_camerapos   = _this select 7;

if (({isClass (configFile >> "CfgVehicles" >> _x)} count _planetypes) == 0) exitWith {};

if (typeName(_this select 8) == "CODE") then
{
   _position = -1;
   _positioncode = _this select 8;
}
else
{
   _position = _this select 8;
   _positioncode = {};
};

_fixeddir    = _this select 9;
_missileidx  = _this select 10;


_backcolor   = _this select 11;
_scanstoload = _this select 12;
if (count _this > 13) then
{
   _vangle = _this select 13;
   if ((_vangle > 89) || (_vangle < -89)) then
   {
      _vangle = -100;
   };
}
else
{
   _vangle = -100;
};

while {true} do
{
   waitUntil {!isNull player};

   _inplane = false;

   while {!_inplane} do
   {
      Sleep 1;

      if ((vehicle player) != player) then
      {
         _plane = vehicle player;
         _class = typeOf _plane;

         if ((count _planetypes) == 1) then
         {
            if (_class isKindOf ((_planetypes) select 0)) then
            {
               _driver = driver _plane;
               _gunner = gunner _plane;
               _commander = commander _plane;

               if (_position >= 0) then
               { 
                  if (((_position == 0) && (_driver == player)) || 
                      ((_position == 1) && (_gunner == player)) ||
                      ((_position == 2) && (_commander == player))) then
                  {
                     _inplane = true;
                     _plane = vehicle player;
                  };
               }
               else
               {
                  if (call (_positioncode)) then
                  {
                     _inplane = true;
                     _plane = vehicle player;
                  };
               }; 
            };
         }
         else
         {
            if (_class in _planetypes) then
            {
               _driver = driver _plane;
               _gunner = gunner _plane;
               _commander = commander _plane;

               if (_position >= 0) then
               { 
                  if (((_position == 0) && (_driver == player)) || 
                      ((_position == 1) && (_gunner == player)) ||
                      ((_position == 2) && (_commander == player))) then
                  {
                     _inplane = true;
                     _plane = vehicle player;
                  };
               }
               else
               {
                  if (call (_positioncode)) then
                  {
                     _inplane = true;
                     _plane = vehicle player;
                  };
               }; 
            };
         };
      };
   };


   if (typeName _missileidx == "SCALAR") then
   {
      if (_missileidx >= 0) then
      {
         _var = _plane getVariable format["mando_maxmissiles%1", _missileidx];
         if (isNil "_var") then
         {
            _plane setVariable [format["mando_maxmissiles%1", _missileidx], _maxmissiles, true];
         };
         _var = _plane getVariable format["mando_missilesleft%1", _missileidx];
         if (isNil "_var") then
         {
            _plane setVariable [format["mando_missilesleft%1", _missileidx], _actmissiles, true];
         };
      };
   };
   _plane setVariable ["mando_rearm_allow", true];
//   _actionidx =  _plane addAction [_actiontext, _mcconscript, [_targettypes, _launchpos, _camerapos, _fixeddir, _missileidx, _backcolor,_scanstoload, _vangle], 101, false, true];

   _actionidx =  _plane addAction ["<t color=""#00ffff"">"+_actiontext, "mando_missiles\mcc\mando_mcc_activation.sqf", [_mcconscript, [_targettypes, _launchpos, _camerapos, _fixeddir, _missileidx, _backcolor,_scanstoload, _vangle]], 101, false, true];



   if (_position >= 0) then
   {
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
   }
   else
   {      
      while {call (_positioncode)} do 
      {
         Sleep 1;
      };
   };


   _plane removeAction _actionidx;

   _inplane = false;

   Sleep 2;
};