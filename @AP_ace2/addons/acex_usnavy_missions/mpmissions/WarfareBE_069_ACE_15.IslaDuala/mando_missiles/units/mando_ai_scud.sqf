/* mando_ai_scud.sqf
By Mandoble August 2010

Fires a SCUD from an AI SCUD launcher.
Execute it there where the launcher is local.


Syntax:
[scud_vehicle, warhead_type, target_position]execVM"mando_missiles\units\mando_ai_scud.sqf";

scud_vehicle: scud vehicle with an alive driver
warhead_type: 0 -> conventional, 1 -> Gigan nuclear, 2 -> E.Echo/Mando nuclear, 3 -> E.Echo/Mando nuclear airburst, 4 -> E.Echo/Mando 3 MIRVs nuclear, 5 -> E.Echo/Mando 3 MIRVs nuclear airburst
target_position: target position

Example:
if (local my_scud2) then
{
   [my_scud2, 2, getMarkerPos "mk_target"]execVM"mando_missiles\units\mando_ai_scud.sqf";
};

*/

private["_scud", "_scud_type", "_target_pos", "_target", "_to_lauch"];

   _scud = _this select 0; 
   _scud_type = _this select 1;
   _target_pos = _this select 2;

   _to_launch = false;
   if (alive driver _scud) then
   {
      driver _scud action ["scudLaunch", _scud];
      Sleep 15;	
      driver _scud action ["scudStart", _scud];
   };

   _scud setVariable ["mando_scud_type", _scud_type];
   _target = "logic" createVehicleLocal _target_pos;
   
   while {alive _scud && !_to_launch} do
   {
      Sleep 1;
      if ((scudstate _scud) > 3) then
      {
         if (((scudstate _scud) > 4) && (!_to_launch)) then
         {
            _to_launch = true;

            // Fire SCUD
            if (!isNull _target) then
            {
               _dir = ((getPos _target select 0) - (getPos _scud select 0)) atan2 ((getPos _target select 1) - (getPos _scud select 1));

               _var = _scud getVariable "mando_scud_type";
               if (!isNil "_var") then
               {
                  switch (_var) do
                  {
                     case 0: // Conventional
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\mando_scudconv.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 30, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };

                     case 1: // Nuclear GIGA
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\giga\mando_scudwarhead_giga.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 30, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };

                     case 2: // Nuclear ECHO/MANDO Ground
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\echo\w80.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 30, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };

                     case 3: // Nuclear ECHO/MANDO AirBurst
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 200, 3000, 1, 2000, mando_missile_path+"warheads\echo\w80_air.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 30, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };

                     case 4: // Nuclear Mirv ECHO/MANDO Ground
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 2000, 2500, 1, 2000, mando_missile_path+"warheads\echo\w80_mirv.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 120, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };

                     case 5: // Nuclear Mirv ECHO/MANDO Air
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 2000, 2500, 1, 2000, mando_missile_path+"warheads\echo\w80_mirv_air.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 120, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };

                     default 
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\mando_scudconv.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 30, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };
                  };
               }
               else
               {
                  [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\mando_scudconv.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 30, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
               };
            };
         };
      }
      else
      {
         _to_launch = false;
      };
   };

Sleep 200;
deleteVehicle _target;