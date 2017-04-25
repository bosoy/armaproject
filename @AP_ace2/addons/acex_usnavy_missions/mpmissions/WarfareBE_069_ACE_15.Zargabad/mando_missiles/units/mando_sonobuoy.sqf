/* mando_sonobuoy.sqf
By Mandoble Feb 2008

Drops a sonobuoy which will provide remote surface and underwater targets 
Use it as action menu script
*/

private["_veh", "_buoy", "_posrel", "_pos", "_trigger", "_side"];
_veh    = _this select 0;
_posrel = _this select 1;
_side   = side _veh;

_pos = _veh modelToWorld _posrel;
_buoy = "BuoySmall" createVehicle _pos;
_buoy setPos _pos;
_buoy setVectorDir vectorDir _veh;
_buoy setVectorUp vectorUp _veh;
_buoy setVelocity velocity _veh;

waitUntil {(getPos _buoy select 2)< 0.1};
if (!surfaceIsWater (getPos _buoy)) exitWith {};


_trigger = createTrigger ["EmptyDetector", getPos _buoy];
_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerArea [1000, 1000, 0, false];
_trigger setTriggerType "NONE";
_trigger setTriggerStatements ["this", "", ""];
_trigger setTriggerTimeout [0, 0, 0, false ];

titleText["Sonobuoy transmitting", "PLAIN DOWN"];
while {alive _buoy} do
{
   Sleep 1;
   {
      if ((getPosASL _x select 2) <= 1) then
      {
         if (_x != _buoy) then
         {
            if (_x isKindOf "Ship") then
            {
               [_side, _x]execVM mando_missile_path+"units\mando_addremotetarget.sqf";
               Sleep 1;
            };
         };
      };

   } forEach list _trigger;
   Sleep 5;
};

deleteVehicle _trigger;
