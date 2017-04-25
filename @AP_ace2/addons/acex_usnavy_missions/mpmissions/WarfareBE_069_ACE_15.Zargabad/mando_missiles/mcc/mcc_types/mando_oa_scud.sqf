_wait_for_launch = 
{
   _scud = _this select 0; 
   _to_launch = false;
   while {alive _scud && !_to_launch && (driver _scud == player)} do
   {
      Sleep 1;
      if ((scudstate _scud) > 3) then
      {
         if (((scudstate _scud) > 4) && (!_to_launch)) then
         {
            _to_launch = true;

            // Fire SCUD

            _target = vehicle player getVariable "mando_current_target";
            if (!isNull _target) then
            {
               _target = "logic" createVehicleLocal [0,0,0];
               _target setPos getPos (vehicle player getVariable "mando_current_target");
	       [_target] spawn
               {
                  private["_target"];
                  _target = _this select 0;
                  Sleep 300;
                  deleteVehicle _target;
               };
               _dir = ((getPos _target select 0) - (getPos _scud select 0)) atan2 ((getPos _target select 1) - (getPos _scud select 1));

               _var = _scud getVariable "mando_scud_type";
               if (!isNil "_var") then
               {
                  switch (_var) do
                  {
                     case 0: // Conventional
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\mando_scudconv.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 120, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };

                     case 1: // Nuclear GIGA
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\giga\mando_scudwarhead_giga.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 120, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };

                     case 2: // Nuclear ECHO/MANDO Ground
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\echo\w80.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 120, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };

                     case 3: // Nuclear ECHO/MANDO Air Burst
                     {
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 200, 3000, 1, 2000, mando_missile_path+"warheads\echo\w80_air.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 120, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
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
                        [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\mando_scudconv.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 120, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
                     };
                  };
               }
               else
               {
                  [_scud, "Bo_GBU12_LGB", [0,0,2000], _dir, 30, 100, 700, 100, _target, 0, 3000, 1, 2000, mando_missile_path+"warheads\mando_scudconv.sqf", mando_missile_path+"exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 120, false, 999, 0, 0, true, false, "", 20, 35, 1, false, 180, 180] execVM mando_missile_path+"mando_missile.sqf";
               };

               Sleep 0.1;
               _missile = _scud getVariable "mando_missile_fired";

	       if (!isNil "_missile") then
               {
                  if (player == driver _scud) then
                  {
                     call compile "true SetCamUseTi 5";
              
                     _missile switchCamera "INTERNAL";

                     while {alive _missile} do
                     {
                        sleep 2;
                     };
     
                     call compile "false SetCamUseTi 2";
  
                     vehicle player switchCamera "EXTERNAL";
                  };

               };	
            };
         };
      }
      else
      {
         _to_launch = false;
      };
   };
};

_var = vehicle player getVariable "mando_current_target";
if (isNil "_var") then
{
   vehicle player setVariable ["mando_current_target", objNull];
};

_var = vehicle player getVariable "mando_check_scud_sts";
if (isNil "_var") then 
{
   vehicle player setVariable ["mando_check_scud_sts", true];
   [vehicle player] spawn _wait_for_launch;
};

if (isNil "mando_ground_hud_target") then
{
   mando_ground_hud_target = "logic" createVehicleLocal [0,0,0];
};

if (isNull mando_ground_hud_target) then
{
   mando_ground_hud_target = "logic" createVehicleLocal [0,0,0];
};

mando_exit_hud = false;
mando_key_pressed = mando_keyspecial;
vehicle player setVariable ["mando_target_types", ["GROUND"], true];
[""]execVm"mando_missiles\huds\custom\custom_hud_maptgt.sqf";
Sleep 1;
mando_exit_hud = true;