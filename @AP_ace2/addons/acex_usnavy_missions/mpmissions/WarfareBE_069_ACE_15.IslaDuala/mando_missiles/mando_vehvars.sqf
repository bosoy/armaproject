/*
mando_vehvars.sqf v1.0
April 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

private ["_vehicle"];

mando_vehvar_vehiclew = objNull;
mando_vehvar_requestw = false;
mando_vehvar_valuew = 0;
mando_vehvar_w = "";

mando_vehvar_vehicler = objNull;
mando_vehvar_requestr = false;
mando_vehvar_r = "";

while {true} do
{
   waitUntil {mando_vehvar_requestw || mando_vehvar_requestr};
   if (mando_vehvar_requestw) then
   {  
//      titleText[format["\n%1\n%2\n%3\n%4\n%5", mando_vehvar_requestw, mando_vehvar_vehiclew, mando_vehvar_w, mando_vehvar_valuew], "PLAIN DOWN"];
      _vehicle = mando_vehvar_vehiclew;
      mando_vehvar_vehiclew setVariable [mando_vehvar_w, mando_vehvar_valuew];
      mando_vehvar_requestw = false;
   };

   if (mando_vehvar_requestr) then
   {   
      _vehicle = mando_vehvar_vehicler;
      if (isServer) then
      {
         mando_vehvar_vehiclew = _vehicle;
         mando_vehvar_valuew = _vehicle getVariable mando_vehvar_r;
         if (!isNil "mando_vehvar_valuew") then
         {
            mando_vehvar_w = mando_vehvar_r;
            mando_vehvar_requestw = true;
            {publicVariable _x} forEach ["mando_vehvar_vehiclew", "mando_vehvar_w", "mando_vehvar_valuew", "mando_vehvar_requestw"];
         };
      };
      mando_vehvar_requestr = false;
   };
};