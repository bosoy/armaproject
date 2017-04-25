/*********************************************************************************
   mando_deploy_sadarm.sqf v1.0
   by Mandoble, March 2008

   Purpose:
      Deploys a ground SADARM. Use this script as menu action script to provide players SADARM manual deployment capability. Number of SADARMs should be provided as third argument of the add action script.

      These SADARMs have a scanning device and a rocket, when the scanning device detects a potential target inside its searching area (150m radius), the rocket is ignited and climbs over 100m to deploy a real SADARM.


   Note: This script requires the presence of mando_bombs_sadarm.sqf and mando_bombs_effects.sqf.

   mando_sadarm_action global variable keeps (if any) the action id of player's sadarm deployment action.
   if number of sadarms left is 0, action is removed and mando_sadarm_action returns to -1

   Example:
      // A player able to deploy 3 SADARMs.
      player addAction ["Deploy SADARM (3 left)", "mando_missiles\mando_bombs\mando_deploy_sadarm.sqf", 3];

*********************************************************************************/

private["_pos", "_barrel", "_radio", "_ang", "_timeold", "_list1", "_speed", "_deltatime", "_ammoleft"];

_ammoleft = (_this select 0) getVariable "mando_sadarms_left";
if (isNil "_ammoleft") then
{
   (_this select 0) setVariable ["mando_sadarms_left", (_this select 3)];
   _ammoleft = _this select 3;
};

(_this select 0) removeAction (_this select 2);

if (_ammoleft == 0) exitWith {};
_ammoleft = _ammoleft - 1;
if (_ammoleft > 0) then
{
   mando_sadarm_action = (_this select 0) addAction [format["Deploy SADARM (%1 left)", _ammoleft], "mando_missiles\mando_bombs\mando_deploy_sadarm.sqf"];  
}
else
{
   mando_sadarm_action = -1;
};

(_this select 0) setVariable ["mando_sadarms_left", _ammoleft];

_pos = (_this select 0) modelToWorld [0,1,0];
_barrel = "Barrel4" createVehicle _pos;
_barrel setPos _pos;
_radio = "Vysilacka" createVehicle [0,0,30];
_radio setPos [_pos select 0, _pos select 1, (_pos select 2) + 0.84];

[]spawn
{
   private ["_trigger"];
   _trigger = createTrigger ["EmptyDetector", [0, 0, 0]];
   _trigger setTriggerActivation ["NONE", "PRESENT", false];
   _trigger setTriggerArea [0, 0, 0, false];
   _trigger setTriggerType "NONE";
   _trigger setTriggerTimeout [0, 0, 0, false ];
   _trigger setTriggerStatements ["true", "res = []execVM""mando_missiles\mando_bombs\mando_bombs_effects.sqf""", ""];
   Sleep 6;
   deleteVehicle _trigger;
};


_ang = getDir _radio;
_timeold = time;
_list1 = [];
_speed = 0;
while {alive _radio} do
{
   _ang = _ang + 1;
   _radio setDir _ang;
   if (_ang > 359) then {_ang = 0};
   _deltatime = (time-_timeold) max 0.001;
   if (_deltatime > 1) then
   {
      _timeold = time;   

      _list1 = nearestObjects [[getPos _radio select 0,getPos _radio select 1, 0], ["Car","Tank", "StaticWeapon", "Ship"], 150];

      if (({(side _x != side player) && (alive _x) && ((count crew _x)>0)} count _list1) > 0) then
      {
         mando_sadarm_rocket = _barrel;
         publicVariable "mando_sadarm_rocket";

         while {(getPos _radio select 2) < 100} do
         {
            if (_speed < 0.8) then {_speed = _speed + 0.008};
            _radio setPos [getPos _radio select 0, getPos _radio select 1, (getPos _radio select 2)+_speed];
            _barrel setPos [getPos _radio select 0, getPos _radio select 1, (getPos _radio select 2)-0.84];
            Sleep 0.005;
         };

         _barrel setVelocity [2,2,20];

         while {_speed > 0} do
         {
            _speed = _speed - 0.02;
            _radio setPos [getPos _radio select 0, getPos _radio select 1, (getPos _radio select 2)+_speed];
            Sleep 0.005;
         };

         _pos = getPos _radio;
         deleteVehicle _radio;    
         [objNull, _pos]execVM"mando_missiles\mando_bombs\mando_bombs_sadarm.sqf"
      };      
   };

   Sleep 0.02;
};
