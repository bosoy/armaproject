/* mando_assignvehicle_by_name.sqf
By Mandoble June 2007

Purpose:
   Waits until a player is in a vehicle which name is in the provided array, and then gives that vehicle missile and/or flare/chaff capability. Missiles and chaff/flares will work manually, controlled by the player. This script must be executed in every machine where there is a player.

Arguments: 
   Array of vehicle names ["name1", "name2", ...]
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


private ["_names", "_plane", "_aa", "_ag", "_af", "_ar", "_ara", "_ao", "_ak", "_var", "_maxmissiles", "_actmissiles", "_maxflares", "_actflares", "_keyscript", "_ttypes", "_inplane", "_position", "_weapon", "_ctrlscript", "_gvtargets", "_airtargets", "_structargets", "_remottargets", "_firingpos", "_hudopenh", "_hudopenv", "_deltav", "_driver", "_gunner", "_vehiclename", "_missileidx", "_radartargets", "_hudtype", "_zoom", "_res"];

_names         = _this select 0;
_position      = _this select 1;
_weapon        = _this select 2;
_maxmissiles   = _this select 3;
_actmissiles   = _this select 4;
_maxflares     = _this select 5;
_actflares     = _this select 6;
_ctrlscript    = _this select 7;
_gvtargets     = _this select 8;
_airtargets    = _this select 9;
_structargets  = _this select 10;
_remottargets  = _this select 11;
_firingpos     = _this select 12;
_keyscript     = _this select 13;
_hudopenh      = _this select 14;
_hudopenv      = _this select 15;
_deltav        = _this select 16;
_missileidx    = _this select 17;

if (count _this > 18) then
{
   _radartargets  = _this select 18;
}
else
{
   _radartargets = false;
};

if (count _this > 19) then
{
   _hudtype = _this select 19;
}
else
{
   _hudtype = 0;
};

if (count _this > 20) then
{
   _zoom = _this select 20;
}
else
{
   _zoom = -1;
};


_plane = objNull;
_ttypes = [];
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
            if (((_position == 0) && (_driver == player)) || ((_position == 1) && (_gunner == player))) then
            {
               _inplane = true;
               _plane = vehicle player;
            };
         };
      };
   };

   cutRsc["mandosystems", "PLAIN DOWN"];
   Sleep 2;
   for [{_i = 0},{_i < (count _maxmissiles)},{_i = _i + 1}] do
   {
      if ((_missileidx select _i) >= 0) then
      {
         _var = _plane getVariable format["mando_maxmissiles%1",(_missileidx select _i)];
         if (isNil "_var") then
         {
            _plane setVariable [format["mando_maxmissiles%1",(_missileidx select _i)], _maxmissiles select _i, true];
         };

         _var = _plane getVariable format["mando_missilesleft%1",(_missileidx select _i)];
         if (isNil "_var") then
         {
            _plane setVariable [format["mando_missilesleft%1",(_missileidx select _i)], _actmissiles select _i, true];
         };
      };
   };

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



   mando_ihavemissiles = false;
   mando_ihaveflares   = false;
   _msg = "";

   for [{_i = 0},{_i < count _maxmissiles},{_i = _i + 1}] do
   {
      if ((_maxmissiles select _i) > 0) then
      {
         mando_ihavemissiles = true;
         if ((_missileidx select _i) >= 0) then
         {
            _msg = _msg + format["Max Missiles type%1: %2, Missiles Left type%3: %4\n", _missileidx select _i, _plane getVariable format["mando_maxmissiles%1",_missileidx select _i], _missileidx select _i, _plane getVariable format["mando_missilesleft%1",_missileidx select _i]];
         };
      };
   };

   if (_maxflares > 0) then
   {
      mando_ihaveflares = true;
      _msg = _msg + format["Max Flares:%1, Flares Left:%2", _plane getVariable "mando_maxflares", _plane getVariable "mando_flaresleft"];
   };   
   cutText[_msg, "PLAIN DOWN"];

   mando_missileidxbase = _missileidx;

   if (mando_ihavemissiles) then
   {
      if (_airtargets) then
      {
         _aa = _plane addAction ["Switch to AA targets", mando_missile_path+"units\AAmode.sqf","",100,false];
         _ttypes = ["Air"];
         mando_missileidx = mando_missileidxbase;
      };

      if (_gvtargets) then
      {
         _ag = _plane addAction ["Switch to AG targets", mando_missile_path+"units\AGmode.sqf","",99,false];
         if (count _ttypes == 0) then
         {
            _ttypes = ["LandVehicle", "Ship"];
            mando_missileidx = mando_missileidxbase + 1;
         };
      };

      if (_structargets) then
      {
         _af = _plane addAction ["Switch to structures", mando_missile_path+"units\ABmode.sqf","",98,false];
         if (count _ttypes == 0) then
         {
            _ttypes = ["House"];
            mando_missileidx = mando_missileidxbase + 1;
         };
      };

      if (_remottargets) then
      {
         _ar = _plane addAction ["Switch to remote", mando_missile_path+"units\ARmode.sqf","",97,false];
         if (count _ttypes == 0) then
         {
            _ttypes = ["REMOTE"];
            mando_missileidx = mando_missileidxbase + 1;
         };
      };

      if (_radartargets) then
      {
         _ara = _plane addAction ["Switch to anti-radar", mando_missile_path+"units\ARADmode.sqf","",96,false];
         if (count _ttypes == 0) then
         {
            _ttypes = ["RADAR"];
            mando_missileidx = mando_missileidxbase + 1;
         };
      };
   };

   _ah = _plane addAction ["Toggle MMA HUD", mando_missile_path+"units\mando_togglemissilehud.sqf","",95,false];  

   if (mando_ihavemissiles || mando_ihaveflares) then
   {
      _ao = _plane addAction ["Show ordenance", mando_missile_path+"units\mando_showordenance.sqf","",94,false];  
      _ak = _plane addAction ["Mando Missile Keys", mando_missile_path+"units\mando_keyconfig.sqf","",93,false];  
   };
  
   _plane setVariable ["mando_rearm_allow", true];
   _res = [_plane, _ttypes, _weapon, _firingpos, _keyscript, _deltav, _position, _hudopenh, _hudopenv, _hudtype, _zoom]execVm _ctrlscript;


   if (_position == 0) then
   {
      while {driver _plane == player} do
      {
         Sleep 1;
      };
   }
   else
   {
      while {gunner _plane == player} do
      {
         Sleep 1;
      };
   };


   if (mando_ihavemissiles) then
   {
      if (_airtargets) then
      {
         _plane removeAction _aa;   
      }; 
 
      if (_gvtargets) then
      {
         _plane removeAction _ag;
      };

      if (_structargets) then
      {
         _plane removeAction _af;
      };

      if (_remottargets) then
      {
         _plane removeAction _ar;
      };

      if (_radartargets) then
      {
         _plane removeAction _ara;
      };
   };

   if (mando_ihavemissiles || mando_ihaveflares) then
   {
      _plane removeAction _ao;
      _plane removeAction _ak;
   };
   _inplane = false;

   Sleep 2;
};