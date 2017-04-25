/* 
 mando basic missile defense system
 mando_missileecm_by_type.sqf v2.35
 August 2009 Mandoble
 

The purpose is to add an automatic missile defense system for all the units of indicated classes (chaff or flares).
The units will use them automatically when needed. 
Execute this script only on the sever.

Parameters:

- Array of vehicle classes that will use this setup for flares/claff, [] for any
- Minimum distance beetween incomming missile and the unit to drop flares or chaff
- Type: 0 - Chaff, 1 - Flares
- Number of chaff or flares packs, each usage substracs one to this initial quantity
- radio: true/false, if unit sends radio messages indicating a missile incomming, chaff or flares dropped, missile evaded, etc.
- reactiontime (optional): The unit will wait a random number of seconds between 0 and this value before dropping - countermeasures. This parameter is optional, if not provided the reaction delay time will be 0 seconds.
- Active only if pilot is not human (true, false): Optional parameter, default is true. If false, then while pilot is human automatic countermeasures are deactivated.

Example AV8B with a chaff system (10 chaff packets). The system might locate the missile when closer than 800m and the pilot has a maximim reaction time of 2 seconds. This is set to be active only if pilot is not human.
[harrier1, 800, 0, 10, true, 2, false]execVM"mando_missiles\units\mando_missileecm.sqf"
*/

private ["_unitsecm", "_unitecm", "_mindistecm", "_typeecm", "_numecm", "_radio", "_reactiontime", "_distlaunch", "_misecm", "_numecmini", "_ammos", "_only_ai"];

_unitsecm    = _this select 0;
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


if (!isServer) exitWith {};


_distlaunch = 0;
_misecm = objNul;
_numecmini = _numecm;


while {true} do
{
   if (mando_missilerequest) then
   { 
      if (((typeOf mando_missiletarget) in _unitsecm) || ((count _unitsecm == 0) && (typeOf mando_missiletarget != "Logic") && ((getPos mando_missiletarget select 2) > 5))) then
      {
         _misecm = mando_missileincomming;
         _unitecm = mando_missiletarget;
/*
         if ((!_only_ai && isPlayer (driver _unitecm)) || (_only_ai))then
         {
            mando_missilerequest = false;
         };
*/
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
      _numecm = _unitecm getVariable "mando_flaresleft";
      if (isNil "_numecm") then
      {
         _unitecm setVariable ["mando_maxflares", _numecmini, true];
         _unitecm setVariable ["mando_flaresleft", _numecmini, true];
      };

      if ((_unitecm getVariable "mando_flaresleft") > 0) then
      {
         if ((_only_ai && !isPlayer (driver _unitecm)) || (!_only_ai)) then
         {
            [_misecm, _radio, _unitecm, _mindistecm, _reactiontime, _typeecm] spawn
            {
               private["_misecm", "_radio", "_unitecm", "_mindistecm", "_reactiontime", "_typeecm", "_to_wait"];
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
                  _to_wait = random (_reactiontime / ((skill _unitecm) max 0.5));
                  _to_wait = _to_wait max 0.5;


                  Sleep (_to_wait);
                  _unitecm setVariable ["mando_flaresleft", (_unitecm getVariable "mando_flaresleft") - 1, true];
                  [_unitecm, _typeecm] spawn mando_chaffflares;
                  _distlaunch = _unitecm distance _misecm;

                  if (_radio && (_typeecm == 0)) then {driver _unitecm sideChat "CHAFF! CHAFF! CHAFF!";};
                  if (_radio && (_typeecm == 1)) then {driver _unitecm sideChat "FLARES! FLARES! FLARES!";};
                  if (_radio && ((_unitecm getVariable "mando_flaresleft") == 0) && (_typeecm == 0)) then {driver _unitecm sideChat "We ran out of chaff!";};
                  if (_radio && ((_unitecm getVariable "mando_flaresleft") == 0) && (_typeecm == 1)) then {driver _unitecm sideChat "We ran out of flares!";};

                  if ((_unitecm getVariable "mando_flaresleft") < 1) then
                  {
                     [_unitecm] spawn
                     {
                        private["_unitecm"];
                        _unitecm = _this select 0;

                        while {(alive _unitecm) && ((_unitecm getVariable "mando_flaresleft") < 1)} do
                        {
                           if (alive driver _unitecm) then
                           {
                              _ammos = nearestObjects [_unitecm, ["MtvrReammo", "KamazReammo", "UralReammo_INS", "UralReammo_CDF", "WarfareReammoTruck_USMC","WarfareReammoTruck_RU","WarfareReammoTruck_Gue"], 12];

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
                  };

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
      };
      _misecm = objNull;
   };
   Sleep 0.25;
};