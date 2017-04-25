/* 
 mando basic missile defense system
 mando_missileecm.sqf v2.35
 August 2009 Mandoble
 

The purpose is to add an automatic missile defense system for a unit (chaff or flares).
The unit will use them automatically when needed. 
Execute this script only on the sever.

Parameters:

Unit that has the CHAFF or FLARES packs
Minimum distance beetween incomming missile and the unit to drop flares or chaff
Type: 0 - Chaff, 1 - Flares
Number of chaff or flares packs, each usage substracs one to this initial quantity
radio: true/false, if unit sends radio messages indicating a missile incomming, chaff or flares dropped, missile evaded, etc.
reactiontime (optional): The unit will wait a random number of seconds between 0 and this value before dropping countermeasures. This parameter is optional, if not provided the reaction delay time will be 0 seconds.
Active only if pilot is not human (true, false): Optional parameter, default is true. If false, then while pilot is human automatic countermeasures are deactivated.

Example AV8B with a chaff system (10 chaff packets). The system might locate the missile when closer than 800m and the pilot has a maximim reaction time of 2 seconds. This is set to be active only if pilot is not human.
[harrier1, 800, 0, 10, true, 2, false]execVM"mando_missiles\units\mando_missileecm.sqf"
*/

private ["_unitecm", "_mindistecm", "_typeecm", "_numecm", "_radio", "_reactiontime", "_distlaunch", "_misecm", "_continue", "_numecmini", "_ammos", "_only_ai"];

_unitecm    = _this select 0;
_mindistecm = _this select 1;
_typeecm    = _this select 2;
_numecm     = _this select 3;
_radio      = _this select 4;
if (count _this > 5) then
{
   _reactiontime = _this select 5;
}
else
{
   _reactiontime = 0;
};

if (count _this > 6) then
{
   _only_ai = _this select 6;
}
else
{
   _only_ai= true;
};



if (isNil "_unitecm") exitWith {};

if ((!isServer) || !(_unitecm isKindOf "Air")) exitWith {};

_unitecm setVariable ["mando_maxflares", _numecm, true];
_unitecm setVariable ["mando_flaresleft", _numecm, true];

_distlaunch = 0;
_misecm = objNul;
_numecmini = _numecm;

_continue = true;
while {_continue} do
{
   while {(alive _unitecm)&&((_unitecm getVariable "mando_flaresleft") > 0)&&!(isNull _unitecm)} do
   {
      if (mando_missilerequest) then
      { 
         if (mando_missiletarget == _unitecm) then
         {
            _misecm = mando_missileincomming;
            mando_missilerequest = false;
            if (({isPlayer _x} count crew _unitecm) > 0) then
            {
               mando_warning = _unitecm;
               publicVariable "mando_warning";
            };
         };
      };

      if (!isNull _misecm) then
      {
         if ((_only_ai && !isPlayer (driver _unitecm)) || (!_only_ai)) then
         {
            [_misecm, _radio, _unitecm, _mindistecm, _reactiontime, _typeecm] spawn
            {
               private["_misecm", "_radio", "_unitecm", "_mindistecm", "_reactiontime", "_typeecm"];
               _misecm       = _this select 0;
               _radio        = _this select 1;
               _unitecm      = _this select 2;
               _mindistecm   = _this select 3;
               _reactiontime = _this select 4;
               _typeecm      = _this select 5;

               if (_radio) then {driver _unitecm sideChat "Missile incomming!";};

               waitUntil {(isNull _misecm) || ((_misecm distance _unitecm) < _mindistecm)};
   
               if (!isNull _misecm) then
               {
                  Sleep (random _reactiontime);
                  _unitecm setVariable ["mando_flaresleft", (_unitecm getVariable "mando_flaresleft") - 1, true];
                  [_unitecm, _typeecm] spawn mando_chaffflares;

                  _distlaunch = _unitecm distance _misecm;

                  if (_radio && (_typeecm == 0)) then {driver _unitecm sideChat "CHAFF! CHAFF! CHAFF!";};
                  if (_radio && (_typeecm == 1)) then {driver _unitecm sideChat "FLARES! FLARES! FLARES!";};
                  if (_radio && ((_unitecm getVariable "mando_flaresleft") == 0) && (_typeecm == 0)) then {driver _unitecm sideChat "We ran out of chaff!";};
                  if (_radio && ((_unitecm getVariable "mando_flaresleft") == 0) && (_typeecm == 1)) then {driver _unitecm sideChat "We ran out of flares!";};

                  Sleep 4;

                  if ((isNull _misecm) || ((_misecm distance _unitecm) > _distlaunch)) then
                  {
                     if (_radio && (!isNull _misecm) && (alive driver _unitecm)) then
                     {
                        driver _unitecm sideChat "Missile evaded!";
                        Sleep(1);
                     }; 
                     _misecm = objNull;
                  };
               };
            };
         };
         _misecm = objNull;
      };
      Sleep 0.25;
   };

   if (!alive _unitecm) then
   {
      _continue = false;
   }
   else
   { 
      if (((_unitecm getVariable "mando_flaresleft") == 0) && (alive _unitecm) && (alive driver _unitecm)) then
      {
         _ammos = nearestObjects [_unitecm, ["Truck5tReammo", "UralReammo"], 12];

         if (count _ammos > 0) then
         {
            if (damage (_ammos select 0) < 0.5) then 
            {
               if (_radio) then
               {
                  if (alive driver _unitecm) then
                  {
                     driver _unitecm sideChat "Reloading countermeasures";
                  };
               };
               Sleep 5;
               _unitecm setVariable ["mando_flaresleft", _unitecm getVariable "mando_maxflares", true];
               if (_radio) then
               {
                  if (alive driver _unitecm) then
                  {
                     driver _unitecm sideChat "Countermeasures reloaded";
                  };
               };
            };
         }; 
      };
      Sleep 3;
   };
};