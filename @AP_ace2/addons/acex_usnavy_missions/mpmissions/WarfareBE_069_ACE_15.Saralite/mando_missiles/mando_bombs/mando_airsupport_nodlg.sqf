/*********************************************************************************
   mando_airsupport_nodlg.sqf v1.1
   by Mandoble, September 2008

   Call for different support missions without using the console.


   Parameters:
      Mission type:
         "CALL_GUNSHIPS" -> A pair of planes or choppers will come to seek and destroy over target position.
         "CALL_PARAS" -> A chopper or plane will drop an infantry group over target position, that group will SD and hold the position.
         "CALL_REINF" -> A chopper or plane will grop an infantry group and this group will join the provided leader
         "CALL_EVAC" -> A chopper will land at target position, will wait for units boarding it and then will take them to destination position
      
   "CALL_AMMO" -> A chopper or plane will aproach target position and will drop a pair of ammo boxes in chutes.
         "CALL_VEH" -> A chopper or plane will aproach target position and will drop the indicated empty vehicle type there.
         "CALL_CAP" -> A pair of planes will sweep the target postion and will keep holding this position.
         "CALL_LASER" -> A plane will aproach to target position and will provide laser guided bombs support.
         "CALL_CRUISEMISSILE" -> The missile launcher will fire a missile against target position.
         "CALL_MISSILESAT" -> The target area will be scanned and the missile launcher will fire two missiles per detected target.
      Target position: Map position, planes, choppers and missiles will go there.
      Start position: Where the planes and choppers will be spawned.
      Destination position: Destination position for evacuation missions, [0,0,0] for any other mission.
      Side: The friendly side of the mission.
      Leader: leader unit for reinforcement missions, else objNull or anyother unit.
      Vehicle class: Class of vehicle for CALL_VEH missions, else ""



   Examples:

   ["CALL_GUNSHIPS", getPos player, getMarkerPos "mk_start", [0,0,0], side player, objNull, ""]execVM"mando_missiles\mando_bombs\mando_airsupport_nodlg.sqf";


   ["CALL_REINF", getPos player, getMarkerPos "mk_start", [0,0,0],side player, player, ""]execVM"mando_missiles\mando_bombs\mando_airsupport_nodlg.sqf";


   ["CALL_CAP", getPos player, getMarkerPos "mk_start", getMarkerPos "mk_dest",side player, objNull, ""]execVM"mando_missiles\mando_bombs\mando_airsupport_nodlg.sqf";


   ["CALL_VEH", getPos player, getMarkerPos "mk_start", getMarkerPos "mk_dest",side player, objNull, "M113"]execVM"mando_missiles\mando_bombs\mando_airsupport_nodlg.sqf";



*********************************************************************************/
private["_mission", "_targetpos", "_side", "_leader", "_plane", "_spawnpos", "_group", "_group_i", "_driver", "_ang", "_i", "_utype", "_speed", "_range", "_distance", "_unit", "_para", "_weaps", "_box", "_truck", "_target", "_target2", "_dir", "_list1", "_list2", "_planes", "_jump"];

_mission = _this select 0;
_targetpos = _this select 1;
_startpos = _this select 2;
_destpos  = _this select 3;
_side = _this select 4;
_leader = _this select 5;
_type_vehicle = _this select 6;

   if (isNil "mando_airsupport_jump") then
   {
      mando_airsupport_jump = true;
   };


   if (isNil "mando_airsupport_cmissile") then
   {
      mando_airsupport_cmissile = objNull;
   };

   if (isNil "mando_airsupport_type") then
   {
      if (_side != east) then
      {
         mando_airsupport_type = "AV8B2";      
      }
      else
      {
         mando_airsupport_type = "Su34B";
      };
   };

   if (isNil "mando_airsupport_type_ca") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_ca = "AH6_RACS";
         }
         else
         {
            mando_airsupport_type_ca = "AH1W";
         };
      }
      else
      {
         mando_airsupport_type_ca = "KA50";
      };
   };

   if (isNil "mando_airsupport_type_pa") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_pa = "UH60MG";
         }
         else
         {
            mando_airsupport_type_pa = "UH60MG";
         };
      }
      else
      {
         mando_airsupport_type_pa = "Mi17_MG";
      };
   };

   if (isNil "mando_airsupport_type_rc") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_rc = "AV8B";
         }
         else
         {
            mando_airsupport_type_rc = "AV8B";
         };
      }
      else
      {
         mando_airsupport_type_rc = "Su34";
      };
   };

   if (isNil "mando_airsupport_type_ev") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_ev = "UH60MG";
         }
         else
         {
            mando_airsupport_type_ev = "UH60MG";
         };
      }
      else
      {
         mando_airsupport_type_ev = "Mi17_MG";
      };
   };

   if (isNil "mando_airsupport_type_la") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_la = "AV8B";
         }
         else
         {
            mando_airsupport_type_la = "AV8B";
         };
      }
      else
      {
         mando_airsupport_type_la = "Su34B";
      };
   };


   if (isNil "mando_airsupport_type_cp") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_cp = "AV8B";
         }
         else
         {
            mando_airsupport_type_cp = "AV8B";
         };
      }
      else
      {
         mando_airsupport_type_cp = "Su34";
      };
   };


   if (isNil "mando_airsupport_type_am") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_am = "UH60MG";
         }
         else
         {
            mando_airsupport_type_am = "UH60MG";
         };
      }
      else
      {
         mando_airsupport_type_am = "Mi17_MG";
      };
   };

   if (isNil "mando_airsupport_type_ambox") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_ambox = "WeaponBoxGuer";
         }
         else
         {
            mando_airsupport_type_ambox = "WeaponBoxWest";
         };
      }
      else
      {
         mando_airsupport_type_ambox = "WeaponBoxEast";
      };
   };

   if (isNil "mando_airsupport_type_ve") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_ve = "UH60MG";
         }
         else
         {
            mando_airsupport_type_ve = "UH60MG";
         };
      }
      else
      {
         mando_airsupport_type_ve = "Mi17_MG";
      };
   };

   if (isNil "mando_airsupport_type_vehicle") then
   {
      if (_side != east) then
      {
         if (_side == resistance) then
         {
            mando_airsupport_type_vehicle = "Truck5t";
         }
         else
         {
            mando_airsupport_type_vehicle = "Truck5t";
         };
      }
      else
      {
         mando_airsupport_type_vehicle = "Ural";
      };
   };


   if (isNil "mando_support_infantrytype") then
   {
      switch (_side) do
      {
         case west:
         {
            mando_support_infantrytype = ["TeamLeaderW", "SoldierWMedic", "SoldierWAT","SoldierWB","SoldierWB","SoldierWB","SoldierWB","SoldierWB","SoldierWB","SoldierWB"];
         };

         case east:
         {
            mando_support_infantrytype = ["TeamLeaderE", "SoldierEMedic", "SoldierEAT","SoldierEB","SoldierEB","SoldierEB","SoldierEB","SoldierEB","SoldierEB","SoldierEB"];
         };

         case resistance:
         {
            mando_support_infantrytype = ["TeamLeaderG", "SoldierGMedic", "SoldierGAT","SoldierGB","SoldierGB","SoldierGB","SoldierGB","SoldierGB","SoldierGB","SoldierGB"];
         };

         case civilian:
         {
            mando_support_infantrytype = ["Civilian11", "Civilian2","Civilian3","Civilian4","Civilian5","Civilian6","Civilian7","Civilian8","Civilian9","Civilian10"];
         };
      };
   };


   if (isNil "mando_support_infantrytype_re") then
   {
      switch (_side) do
      {
         case west:
         {
            mando_support_infantrytype_re = ["TeamLeaderW", "SoldierWMedic", "SoldierWAT","SoldierWB","SoldierWB","SoldierWB","SoldierWB","SoldierWB","SoldierWB","SoldierWB"];
         };

         case east:
         {
            mando_support_infantrytype_re = ["TeamLeaderE", "SoldierEMedic", "SoldierEAT","SoldierEB","SoldierEB","SoldierEB","SoldierEB","SoldierEB","SoldierEB","SoldierEB"];
         };

         case resistance:
         {
            mando_support_infantrytype_re = ["TeamLeaderG", "SoldierGMedic", "SoldierGAT","SoldierGB","SoldierGB","SoldierGB","SoldierGB","SoldierGB","SoldierGB","SoldierGB"];
         };

         case civilian:
         {
            mando_support_infantrytype_re = ["Civilian11", "Civilian2","Civilian3","Civilian4","Civilian5","Civilian6","Civilian7","Civilian8","Civilian9","Civilian10"];
         };
      };
   };


   if (isNil "mando_airsupport_weap") then
   {
      mando_airsupport_weap = [];
   };

   if (isNil "mando_airsupport_magz") then
   {
      mando_airsupport_magz = [];
   };


   if (isNil "mando_support_enemy_sides") then
   {
      switch (_side) do
      {
         case west:
         {
            mando_support_enemy_sides = [east, sideEnemy];
         };

         case east:
         {
            mando_support_enemy_sides = [west, sideEnemy];
         };

         case resistance:
         {
            mando_support_enemy_sides = [east, sideEnemy];
         };

         case civilian:
         {
            mando_support_enemy_sides = [east, sideEnemy];
         };
      };
   };


   if (isNil "mando_airsupport_range") then
   {
      mando_airsupport_range = 4500;
   } 
   else
   {
      if (mando_airsupport_range < 4500) then
      { 
         mando_airsupport_range = 4500;
      }; 
   };

   if (isNil "mando_airsupport_range_he") then
   {
      mando_airsupport_range_he = mando_airsupport_range;
   } 
   else
   {
      if (mando_airsupport_range_he < 4500) then
      { 
         mando_airsupport_range_he = 4500;
      }; 
   };


   if (isNil "mando_airsupport_max_cas") then
   {
      mando_airsupport_max_cas = 2;
   };

   if (isNil "mando_airsupport_bomb_type") then
   {
      mando_airsupport_bomb_type = "Bo_GBU12_LGB";
   };

   if (isNil "mando_airsupport_bomb_alt") then
   {
      mando_airsupport_bomb_alt = 150;
   };

   if (isNil "mando_airsupportdlg") then
   {
      mando_airsupportdlg = compile (preprocessFileLineNumbers "mando_missiles\mando_bombs\mando_airsupportdlg.sqf");
      mando_airsupportdlgsetup = compile (preprocessFileLineNumbers "mando_missiles\mando_bombs\mando_airsupportdlgsetup.sqf");
   };

   if (isNil "mando_airsupport_bomb_pos") then
   {
      mando_airsupport_bomb_pos = [2, 0, -2];
   };


   if (isNil "mando_airsupport_planes_delay") then
   {
      mando_airsupport_planes_delay = 4;
   };

   if (isNil "mando_airsupport_missile_delay") then
   {
      mando_airsupport_missile_delay = 15;
   };


   if (isNil "mando_airsupport_ab_switchable") then
   {
      mando_airsupport_ab_switchable = false;
   };

   if (isNil "mando_airsupport_re_switchable") then
   {
      mando_airsupport_re_switchable = false;
   };


switch (_mission) do
{
   case "CALL_GUNSHIPS":
   {
      _group = createGroup (_side);
      switch (_side) do
      {
         case west:
         {
            _utype = "SoldierWPilot";
         };
         case east:
         {
            _utype = "SoldierEPilot";
         };
         case resistance:
         {
            _utype = "SoldierGPilot";
         };
         case civilian:
         {
             _utype = "Civilian2";
         };
      };

      if (mando_airsupport_type_ca isKindOf "Helicopter") then
      {
         _range = mando_airsupport_range_he;
      }
      else
      {
         _range = mando_airsupport_range;
      };

      _planes = [];
      for [{_i = 0},{_i < 2},{_i=_i+1}] do
      {
         _ang = ((_targetpos select 0)-(_startpos select 0)) atan2 ((_targetpos select 1)-(_startpos select 1));
         _spawnpos = [(_startpos select 0) + sin(_ang)*(_i*50), (_startpos select 1) + cos(_ang)*(_i*50)];

         _plane = createVehicle [mando_airsupport_type_ca, _spawnpos, [], 0, "FLY"];
         _speed = speed _plane;   
         _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
         _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
         _plane setDir _ang;
         _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 
         _planes = _planes + [_plane];

         _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
         _driver setskill 0.5;
         _driver setCombatMode "RED";
         _driver setBehaviour "AWARE";
         if (_i == 0) then
         {
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
         }
         else
         {
            _driver setRank "PRIVATE";
         };
         _driver moveInDriver _plane;
         _gunner = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
         _gunner setCombatMode "RED";
         _gunner setBehaviour "AWARE";
         _gunner setRank "PRIVATE";
         _gunner moveInGunner _plane;
         if (!(_gunner in _plane)) then
         {
            deleteVehicle _gunner;
         };
         _plane flyinHeight mando_airsupport_bomb_alt max 100;
         if (!isNil "mando_missile_init") then
         {
            _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
            [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
            processInitCommands;

            [_plane, 0, ["LandVehicle", "Ship"], 2, 500, 2500, 4, [5, 2, -4], 50, 0, mando_support_enemy_sides, false, false, true, true]exec"mando_missiles\units\attackers\mando_basicag_unit.sqs";
            Sleep 0.5;
         };
      };
      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 1] showWaypoint "NEVER";
      [_group, 1] setWaypointSpeed "FULL";
      [_group, 1] setWaypointType "SAD";

      [_side, "HQ"] sideChat "Gunships support OTW";

      Sleep 4;
      while {!((unitReady leader _group) && (alive leader _group)) || ((!alive leader _group) && ({alive _x} count _planes > 0))} do
      {
         Sleep 2;
      };

      _group move _spawnpos;
      Sleep 4;
      while {!((unitReady leader _group) && (alive leader _group)) || ((!alive leader _group) && ({alive _x} count _planes > 0))} do
      {
         Sleep 2;
      };


      {
         if (alive vehicle _x) then
         {
            deleteVehicle vehicle _x;
         };
      } forEach units _group;

      {
         if (alive _x) then
         {
            deleteVehicle _x;
         };
      } forEach units _group;
      deleteGroup _group;
   };


   case "CALL_PARAS":
   {
      _group = createGroup (_side);

      switch (_side) do
      {
         case west:
         {
            _utype = "SoldierWPilot";
         };
         case east:
         {
            _utype = "SoldierEPilot";
         };
         case resistance:
         {
            _utype = "SoldierGPilot";
         };
         case civilian:
         {
            _utype = "Civilian2";
         };
      };

      if (mando_airsupport_type_pa isKindOf "Helicopter") then
      {
         _range = mando_airsupport_range_he;
      }
      else
      {
         _range = mando_airsupport_range;
      };

      _jump = mando_airsupport_jump;

      _spawnpos = _startpos;

      _plane = createVehicle [mando_airsupport_type_pa, _spawnpos, [], 0, "FLY"];
      _speed = speed _plane;
      _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
      _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
      _plane setDir _ang;
      _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


      _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
      _driver setskill 0.5;
      _driver setCombatMode "BLUE";
      _driver setBehaviour "CARELESS";
      _driver setRank "CORPORAL";
      _group selectLeader _driver;
      _driver moveInDriver _plane;
      _plane flyinHeight mando_airsupport_bomb_alt max 100;

      if (!isNil "mando_missile_init") then
      {
         _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
         [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
         processInitCommands;
      };

      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 1] showWaypoint "NEVER";
      [_group, 1] setWaypointSpeed "FULL";
      [_group, 1] setWaypointType "MOVE";

      _group_i = createGroup (_side);
      _i = 0;
      {
         if (_i == 0) then
         {
            _unit = _group_i createUnit [_x,[0,0,30], [], 0, "NONE"];
            _unit setCombatMode "RED";
            _unit setBehaviour "AWARE";
            _unit setRank "CORPORAL";
            _group_i selectLeader _unit;
         }
         else
         {
            _unit = _group_i createUnit [_x,[0,0,30], [], 0, "NONE"];
            _unit setCombatMode "RED";
            _unit setBehaviour "AWARE";
            _unit setRank "PRIVATE";
         };

         if (_side == civilian) then
         {
            _unit addMagazine "30Rnd_545x39_AK";
            _unit addMagazine "30Rnd_545x39_AK";
            _unit addMagazine "30Rnd_545x39_AK";
            _unit addWeapon "AK74";
         };
         _unit setskill 0.5;
         _unit moveInCargo _plane;
         if (mando_airsupport_ab_switchable) then
         {
            addSwitchableUnit _unit;
         };
         _i = _i + 1;
      } forEach mando_support_infantrytype;

      _wp = _group_i addWaypoint [_targetpos, 0];
      [_group_i, 1] showWaypoint "NEVER";
      [_group_i, 1] setWaypointType "SAD";
      _wp = _group_i addWaypoint [_targetpos, 0];
      [_group_i, 2] showWaypoint "NEVER";
      [_group_i, 2] setWaypointType "HOLD";

      [_side, "HQ"] sideChat "Airborne assault OTW";

      Sleep 4;
      waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};
/*
      if (alive _plane) then
      {
         {
            _x action ["EJECT", vehicle _x];
            unassignVehicle _x;
            Sleep 0.75;
         } forEach units _group_i;
      };     
*/

      if (_jump) then
      {
         if (alive _plane) then
         {
            {
               if (alive _x) then
               {
                  _x action ["EJECT", vehicle _x];
               };
               unassignVehicle _x;
               Sleep 0.75;
            } forEach units _group_i;
         };     
      }
      else
      {
         _plane flyinHeight 0;
         _plane doMove _targetpos; 
         Sleep 3;
         waitUntil {(((getPos _plane select 2) < 2) && (alive leader _group)) || (!alive leader _group)};
         Sleep 2;
         if (alive _plane) then
         {
            {
               if (alive _x) then
               {
                  _x action ["getOut", vehicle _x];
               };
               unassignVehicle _x;
               Sleep 1;
            } forEach units _group_i;
         };
         _plane flyinHeight mando_airsupport_bomb_alt max 100;
      };




      Sleep 2;
      _group move _spawnpos;
      Sleep 4;

      waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

      {
         if (alive vehicle _x) then
         {
            deleteVehicle vehicle _x;
         };
      } forEach units _group;

      {
         if (alive _x) then
         {
            deleteVehicle _x;
         };
      } forEach units _group;

      deleteGroup _group;
   };


   case "CALL_REINF":
   {
      _group = createGroup (_side);

      switch (_side) do
      {
         case west:
         {
            _utype = "SoldierWPilot";
         };
         case east:
         {
            _utype = "SoldierEPilot";
         };
         case resistance:
         {
            _utype = "SoldierGPilot";
         };
         case civilian:
         {
            _utype = "Civilian2";
         };
      };

      if (mando_airsupport_type_pa isKindOf "Helicopter") then
      {
         _range = mando_airsupport_range_he;
      }
      else
      {
         _range = mando_airsupport_range;
      };

      _jump = mando_airsupport_jump;

      _spawnpos = _startpos;

      _plane = createVehicle [mando_airsupport_type_pa, _spawnpos, [], 0, "FLY"];
      _speed = speed _plane;
      _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
      _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
      _plane setDir _ang;
      _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


      _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
      _driver setskill 0.5;
      _driver setCombatMode "BLUE";
      _driver setBehaviour "CARELESS";
      _driver setRank "CORPORAL";
      _group selectLeader _driver;
      _driver moveInDriver _plane;
      _plane flyinHeight mando_airsupport_bomb_alt max 100;

      if (!isNil "mando_missile_init") then
      {
         _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
         [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
         processInitCommands;
      };

      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 1] showWaypoint "NEVER";
      [_group, 1] setWaypointSpeed "FULL";
      [_group, 1] setWaypointType "MOVE";

      _group_i = createGroup (_side);
      _i = 0;
      {
         if (_i == 0) then
         {
            _unit = _group_i createUnit [_x,[0,0,30], [], 0, "NONE"];
            _unit setCombatMode "RED";
            _unit setBehaviour "AWARE";
            _unit setRank "CORPORAL";
            _group_i selectLeader _unit;
         }
         else
         {
            _unit = _group_i createUnit [_x,[0,0,30], [], 0, "NONE"];
            _unit setCombatMode "RED";
            _unit setBehaviour "AWARE";
            _unit setRank "PRIVATE";
         };

         if (_side == civilian) then
         {
            _unit addMagazine "30Rnd_545x39_AK";
            _unit addMagazine "30Rnd_545x39_AK";
            _unit addMagazine "30Rnd_545x39_AK";
            _unit addWeapon "AK74";
         };
         _unit setskill 0.5;
         _unit moveInCargo _plane;
         if (mando_airsupport_re_switchable) then
         {
            addSwitchableUnit _unit;
         };
         _i = _i + 1;
      } forEach mando_support_infantrytype_re;

      _wp = _group_i addWaypoint [_targetpos, 0];
      [_group_i, 1] showWaypoint "NEVER";
      [_group_i, 1] setWaypointType "MOVE";

      [_side, "HQ"] sideChat "Reinforcements OTW";

      Sleep 4;
      waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};


      if (_jump) then
      {
         if (alive _plane) then
         {
            {
               if (alive _x) then
               {
                  _x action ["EJECT", vehicle _x];
               };
               unassignVehicle _x;
               Sleep 0.75;
            } forEach units _group_i;
         };     
      }
      else
      {
         _plane flyinHeight 0;
         _plane doMove _targetpos; 
         Sleep 3;
         waitUntil {(((getPos _plane select 2) < 2) && (alive leader _group)) || (!alive leader _group)};
         Sleep 2;
         if (alive _plane) then
         {
            {
               if (alive _x) then
               {
                  _x action ["getOut", vehicle _x];
               };
               unassignVehicle _x;
               Sleep 1;
            } forEach units _group_i;
         };
         _plane flyinHeight mando_airsupport_bomb_alt max 100;
      };




  
      Sleep 2;
      _group move _spawnpos;
      Sleep 4;
      if ((({alive _x} count units _group_i) > 0) && (alive _leader)) then
      {
         (units _group_i) join group _leader;
      };

      waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

      {
         if (alive vehicle _x) then
         {
            deleteVehicle vehicle _x;
         };
      } forEach units _group;

      {
         if (alive _x) then
         {
            deleteVehicle _x;
         };
      } forEach units _group;

      deleteGroup _group;
   };     

   case "CALL_EVAC":
   {
      _group = createGroup (_side);
      switch (_side) do
      {
         case west:
         {
            _utype = "SoldierWPilot";
         };
         case east:
         {
            _utype = "SoldierEPilot";
         };
         case resistance:
         {
            _utype = "SoldierGPilot";
         };
         case civilian:
         {
            _utype = "Civilian2";
         };
      };

      if (mando_airsupport_type_ev isKindOf "Helicopter") then
      {
         _range = mando_airsupport_range_he;
      }
      else
      {
         _range = mando_airsupport_range;
      };

      _spawnpos = _startpos;
      _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
      _plane = createVehicle [mando_airsupport_type_ev, _spawnpos, [], 0, "FLY"];
      _plane setDir _ang;

      _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
      _driver setskill 0.5;
      _driver setCombatMode "BLUE";
      _driver setBehaviour "CARELESS";
      _driver setRank "CORPORAL";
      _group selectLeader _driver;
      _driver moveInDriver _plane;

      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 1] setWaypointStatements ["true", "if (!(surfaceIsWater getPos (vehicle this))) then{(vehicle this) flyinHeight 0;(vehicle this) land ""LAND""}else{(vehicle this) flyinHeight 3}"];
      [_group, 1] showWaypoint "NEVER";
      [_group, 1] setWaypointSpeed "FULL";
      [_group, 1] setWaypointType "MOVE";
      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 2] setWaypointStatements ["count crew (vehicle this) > 1", "(vehicle this) flyinHeight 100"];
      [_group, 2] setWaypointTimeout [25, 25, 25];
      [_group, 2] showWaypoint "NEVER";
      [_group, 2] setWaypointSpeed "FULL";
      [_group, 2] setWaypointType "MOVE";

      _distance = _targetpos distance _destpos;
      _ang = ((_destpos select 0) - (_targetpos select 0)) atan2 ((_destpos select 1) - (_targetpos select 1));
      _targetpos = [(_targetpos select 0)+sin(_ang)*_distance/2,(_targetpos select 1)+cos(_ang)*_distance/2];
      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 3] setWaypointStatements ["true", ""];
      [_group, 3] setWaypointTimeout [0, 0, 0];
      [_group, 3] showWaypoint "NEVER";
      [_group, 3] setWaypointSpeed "FULL";
      [_group, 3] setWaypointType "MOVE";
             
      _targetpos = _destpos;
      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 4] setWaypointStatements ["true", "(vehicle this) flyinHeight 0;(vehicle this) land ""LAND"""];
      [_group, 4] showWaypoint "NEVER";
      [_group, 4] setWaypointSpeed "FULL";
      [_group, 4] setWaypointType "MOVE";

      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 5] setWaypointStatements ["count crew (vehicle this) < 2", "(vehicle this) flyinHeight 100"];
      [_group, 5] setWaypointTimeout [0, 0, 0];
      [_group, 5] showWaypoint "NEVER";
      [_group, 5] setWaypointSpeed "FULL";
      [_group, 5] setWaypointType "MOVE";

      _targetpos = [_targetPos select 0, (_targetPos select 1)+3000, 100];
      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 6] setWaypointStatements ["true", "deleteVehicle (vehicle this);deleteVehicle this"];
      [_group, 6] setWaypointTimeout [0, 0, 0];
      [_group, 6] showWaypoint "NEVER";
      [_group, 6] setWaypointSpeed "FULL";
      [_group, 6] setWaypointType "MOVE";


      [_side, "HQ"] sideChat "Transport chopper OTW";


      if (!isNil "mando_missile_init") then
      {
         _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
         [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
         processInitCommands;
      };
   };


   case "CALL_AMMO":
   {
      _group = createGroup (_side);

      switch (_side) do
      {
         case west:
         {
            _utype = "SoldierWPilot";
         };
         case east:
         {
            _utype = "SoldierEPilot";
         };
         case resistance:
         {
            _utype = "SoldierGPilot";
         };
         case civilian:
         {
            _utype = "Civilian2";
         };
      };

      if (mando_airsupport_type_am isKindOf "Helicopter") then
      {
         _range = mando_airsupport_range_he;
      }
      else
      {
         _range = mando_airsupport_range;
      };

      _spawnpos = _startpos;

      _plane = createVehicle [mando_airsupport_type_am, _spawnpos, [], 0, "FLY"];
      _speed = speed _plane;
      _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
      _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
      _plane setDir _ang;
      _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


      _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
      _driver setskill 0.5;
      _driver setCombatMode "BLUE";
      _driver setBehaviour "CARELESS";
      _driver setRank "CORPORAL";
      _group selectLeader _driver;
      _driver moveInDriver _plane;
      _plane flyinHeight mando_airsupport_bomb_alt max 100;

      if (!isNil "mando_missile_init") then
      {
         _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
         [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
         processInitCommands;
      };

      (mando_support_display displayCtrl 23942) ctrlSetText "MSG: Ammo supply on the way";

      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 1] showWaypoint "NEVER";
      [_group, 1] setWaypointSpeed "FULL";
      [_group, 1] setWaypointType "MOVE";

      [_side, "HQ"] sideChat "Ammo supply OTW";

      Sleep 4;
      waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};
      if (alive _plane) then
      {
         for [{_i=0},{_i < 2},{_i = _i + 1}] do
         { 
            [_plane]spawn
            {
               private["_plane", "_para", "_box", "_pos", "_weaps"];
               _plane = _this select 0;
               _pos  = _plane modelToWorld [0,-6, 0];
               _para = "ParachuteWest" createVehicle [0,0,0];
               _para setPos _pos;
               _box = mando_airsupport_type_ambox createVehicle [0,0,0];
               _weaps = "";
               if ((count mando_airsupport_magz) > 0) then
               {
                  _weaps = "clearMagazineCargo this;";
                  {
                     _weaps = _weaps + format["this addMagazineCargo [""%1"", %2];", (_x select 0),(_x select 1)];
                  } forEach mando_airsupport_magz;
               };

               if ((count mando_airsupport_weap) > 0) then
               {
                  _weaps = _weaps + "clearWeaponCargo this;";
                  {
                     _weaps = _weaps + format["this addWeaponCargo [""%1"", %2];", (_x select 0),(_x select 1)];
                  } forEach mando_airsupport_weap;
               };

               if (_weaps != "") then
               {
                  _box SetVehicleInit _weaps;
                  processInitCommands;
               };

               while {(getPos _para select 2) > 2.5} do 
               {
                  _box setPos (_para modelToWorld [0,0,-2]);
                  _box setVectorDir (vectorDir _para);
                  _box setVectorUp (vectorUp _para);
                  Sleep 0.002;
               };
               _box setDir 0;
               _box setPos [getPos _para select 0, getPos _para select 1, 0];
            };
            Sleep 3;
         };
      };

      _group move _spawnpos;
      Sleep 4;

      waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};
      {
         if (alive vehicle _x) then
         {
            deleteVehicle vehicle _x;
         };
      } forEach units _group;

      {
         if (alive _x) then
         {
            deleteVehicle _x;
         };
      } forEach units _group;

      deleteGroup _group;
   };


   case "CALL_VEH":
   {
      _group = createGroup (_side);

      switch (_side) do
      {
         case west:
         {
            _utype = "SoldierWPilot";
         };
         case east:
         {
            _utype = "SoldierEPilot";
         };
         case resistance:
         {
            _utype = "SoldierGPilot";
         };
         case civilian:
         {
            _utype = "Civilian2";
         };
      };

      if (mando_airsupport_type_ve isKindOf "Helicopter") then
      {
         _range = mando_airsupport_range_he;
      }
      else
      {
         _range = mando_airsupport_range;
      };

      _spawnpos = _startpos;

      _plane = createVehicle [mando_airsupport_type_ve, _spawnpos, [], 0, "FLY"];
      _speed = speed _plane;
      _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
      _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
      _plane setDir _ang;
      _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 

      _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
      _driver setskill 0.5;
      _driver setCombatMode "BLUE";
      _driver setBehaviour "CARELESS";
      _driver setRank "CORPORAL";
      _group selectLeader _driver;
      _driver moveInDriver _plane;
      _plane flyinHeight mando_airsupport_bomb_alt max 100;

      if (!isNil "mando_missile_init") then
      {
         _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
         [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
         processInitCommands;
      };


      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 1] showWaypoint "NEVER";
      [_group, 1] setWaypointSpeed "FULL";
      [_group, 1] setWaypointType "MOVE";


      [_side, "HQ"] sideChat "Vehicle supply OTW";

      Sleep 4;
      if (_type_vehicle == "") then
      {
         _type_vehicle = mando_airsupport_type_vehicle;
      };
      _truck = _type_vehicle createVehicle [0,0,0];
      while {(alive _plane) && !(unitReady leader _group)} do
      {
         _truck setPos (_plane modelToWorld [0,-1,-10]);
         _truck setVectorDir (vectorDir _plane);
         _truck setVectorUp (vectorUP _plane);
         _truck setVelocity [0,0,0];
         Sleep 0.002;
      };

      if (alive _plane) then
      {
         _plane flyinHeight 10;
         _plane doMove [getPos _plane select 0,getPos _plane select 1, 10];
         while {(alive _plane) && ((getPos _plane select 2) > 12)} do
         {
            _truck setPos (_plane modelToWorld [0,-1,-10]);
            _truck setVectorDir (vectorDir _plane);
            _truck setVectorUp (vectorUP _plane);
            _truck setVelocity [0,0,0];
            Sleep 0.002;
         };
      };

      if ((_truck isKindOf "StaticWeapon") || (_truck isKindOf "Static"))then
      {           
         [_truck, _plane modelToWorld [0,-1,-10]] spawn 
         {
            private["_cargo", "_timeold", "_deltatime", "_vel", "_pos"]; 
            _cargo = _this select 0;
            _pos = _this select 1;
            _timeold = time;
            _vel = 0;

            while {(_pos select 2) > 0} do
            {
               _deltatime = (time-_timeold) max 0.001;
               _timeold = time;
               _vel = _vel + 9.8*_deltatime;
               _pos = [_pos select 0, _pos select 1, (_pos select 2) - _vel * _deltatime];
               _cargo setPos _pos;
               Sleep 0.001;
            };
            _cargo setPos [_pos select 0, _pos select 1, 0];
         };
      }; 

      _plane flyinHeight 100;
      _group move _spawnpos;
      Sleep 4;

      waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};

      {
         if (alive vehicle _x) then
         {
            deleteVehicle vehicle _x;
         };
      } forEach units _group;

      {
         if (alive _x) then
         {
            deleteVehicle _x;
         };
      } forEach units _group;

      deleteGroup _group;
   };


   case "CALL_CAP":
   {
      _group = createGroup (_side);

      switch (_side) do
      {
         case west:
         {
            _utype = "SoldierWPilot";
         };
         case east:
         {
            _utype = "SoldierEPilot";
         };
         case resistance:
         {
            _utype = "SoldierGPilot";
         };
         case civilian:
         {
            _utype = "Civilian2";
         };
      };

      if (mando_airsupport_type_cp isKindOf "Helicopter") then
      {
         _range = mando_airsupport_range_he;
      }
      else
      {
         _range = mando_airsupport_range;
      };


      for [{_i = 0},{_i < 2},{_i=_i+1}] do
      {
         _ang = ((_targetpos select 0)-(_startpos select 0)) atan2 ((_targetpos select 1)-(_startpos select 1));
         _spawnpos = [(_startpos select 0) + sin(_ang)*(_i*50), (_startpos select 1) + cos(_ang)*(_i*50)];
         _plane = createVehicle [mando_airsupport_type_cp, _spawnpos, [], 0, "FLY"];
         _speed = speed _plane;
         _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
         _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
         _plane setDir _ang;
         _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 

         _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
         _driver setskill 0.5;
         _driver setCombatMode "RED";
         _driver setBehaviour "AWARE";
         if (_i == 0) then
         {
            _driver setRank "CORPORAL";
            _group selectLeader _driver;
         }
         else
         {
            _driver setRank "PRIVATE";
         };
         _driver moveInDriver _plane;
         _plane flyinHeight mando_airsupport_bomb_alt max 100;
         if (!isNil "mando_missile_init") then
         {
            _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
            [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
            processInitCommands;

            [_plane, 0, ["Air"], 8, 500, 2900, 15, [4, 1, -2], 50, 0, mando_support_enemy_sides, false, false, true, true]exec"mando_missiles\units\attackers\mando_aim120_fighter.sqs";
            Sleep 0.5;
         };
      };
      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 1] showWaypoint "NEVER";
      [_group, 1] setWaypointSpeed "FULL";
      [_group, 1] setWaypointType "HOLD";


      [_side, "HQ"] sideChat "CAP fighters OTW";
   };


   case "CALL_LASER":
   {
      _group = createGroup (_side);

      switch (_side) do
      {
         case west:
         {
            _utype = "SoldierWPilot";
         };
         case east:
         {
            _utype = "SoldierEPilot";
         };
         case resistance:
         {
            _utype = "SoldierGPilot";
         };
         case civilian:
         {
            _utype = "Civilian2";
         };
      };

      if (mando_airsupport_type_la isKindOf "Helicopter") then
      {
         _range = mando_airsupport_range_he;
      }
      else
      {
         _range = mando_airsupport_range;
      };


      _spawnpos = _startpos;
      _plane = createVehicle [mando_airsupport_type_la, _spawnpos, [], 0, "FLY"];
      _speed = speed _plane;
      _ang = ((_targetpos select 0)-(_spawnpos select 0)) atan2 ((_targetpos select 1)-(_spawnpos select 1));
      _plane setPos [_spawnpos select 0,_spawnpos select 1, mando_airsupport_bomb_alt max 100];
      _plane setDir _ang;
      _plane setVelocity [sin(_ang)*_speed/3.6,cos(_ang)*_speed/3.6,0]; 


      _driver = _group createUnit [_utype,[0,0,30], [], 0, "FORM"];
      _driver setskill 0.5;
      _driver setCombatMode "GREEN";
      _driver setBehaviour "CARELESS";
      _driver setRank "CORPORAL";
      _group selectLeader _driver;
      _driver moveInDriver _plane;
      _plane flyinHeight mando_airsupport_bomb_alt max 100;

      if (!isNil "mando_missile_init") then
      {
         _plane SetVehicleInit "res = [This] execVM ""mando_missiles\units\mando_onlymandoones.sqf""";
         [_plane, 800, 1, 5, false, 0]execVM"mando_missiles\units\mando_missileecm.sqf";
         processInitCommands;

         [_plane, 0, ["REMOTE"], 2, 500, 2500, 4, [4, 1, -4], 50, 0, [sideLogic]+mando_support_enemy_sides, false, false, true, true]exec"mando_missiles\units\attackers\mando_lgb.sqs";

      };

      (mando_support_display displayCtrl 23942) ctrlSetText "MSG: Laser guided bombs aircraft on the way";


      _wp = _group addWaypoint [_targetpos, 0];
      [_group, 1] showWaypoint "NEVER";
      [_group, 1] setWaypointSpeed "LIMITED";
      [_group, 1] setWaypointType "MOVE";
      _wp = _group addWaypoint [_startpos, 0];
      [_group, 2] showWaypoint "NEVER";
      [_group, 2] setWaypointSpeed "LIMITED";
      [_group, 2] setWaypointType "MOVE";


      [_side, "HQ"] sideChat "Laser guided bombs support OTW";

      Sleep 4;
      waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};
      Sleep 4;
      waitUntil {((unitReady leader _group) && (alive leader _group)) || (!alive leader _group)};


      {
         if (alive vehicle _x) then
         {
            deleteVehicle vehicle _x;
         };
      } forEach units _group;

      {
         if (alive _x) then
         {
            deleteVehicle _x;
         };
      } forEach units _group;

      deleteGroup _group;
   };


   case "CALL_CRUISEMISSILE":
   {
      if (alive mando_airsupport_cmissile) then
      {
         if (isNil "mando_airsupport_cmissile_pos") then
         {
            [_side, "HQ"] sideChat "Cruise missile firing position undefined!";
         }  
         else
         {
            _target = "logic" createVehicleLocal [0,0,0];
            _target2 = "logic" createVehicleLocal [0,0,0];

            _target setPos [_targetpos select 0, _targetpos select 1, 0];
            _target2 setPos [_targetpos select 0, _targetpos select 1, 0];

            _dir = ((getPos _target select 0)-(getPos mando_airsupport_cmissile select 0)) atan2 ((getPos _target select 1)-(getPos mando_airsupport_cmissile select 1));


            [mando_airsupport_cmissile, "Bo_GBU12_LGB", mando_airsupport_cmissile_pos, _dir, 89, 0, 250, 100, _target, 5, 2000, 0, 500, "mando_missiles\warheads\mando_missilehead2a.sqf", "mando_missiles\exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 100, true, 5, 0, 0, true, true, "mando_missiles\launch\mando_scudlaunch.sqf", 10, 15, 1, true, 180, 180] execVM "mando_missiles\mando_missile.sqf";
               
            [_side, "HQ"] sideChat "Cruise missile launched";

            mando_last_missile_target = _target; 
            mando_last_target = _target2;
            waitUntil {!isNull mando_missile};
            mando_last_missile = mando_missile;
               
            Sleep 100;
            deleteVehicle _target;

            deleteVehicle _target2;

         };
      }
      else
      {
         [_side, "HQ"] sideChat "No cruise missile launcher present";
      };
   };


   case "CALL_MISSILESAT":
   {
      if (alive mando_airsupport_cmissile) then
      {
         if (isNil "mando_airsupport_cmissile_pos") then
         {
            [_side, "HQ"] sideChat "Cruise missile firing position undefined!";
         }  
         else
         {
            _list1 = nearestObjects [_targetpos, ["Car","Tank", "StaticWeapon", "Ship"], 500];
            _list2 = []; 
            {
               if ((side _x != _side) && (alive _x) && ((count crew _x)>0)) then
               { 
                  _list2 = _list2 + [_x];
               };
            } forEach _list1;


            if (count _list2 > 0) then
            {
               [_side, "HQ"] sideChat "Executing cruise missile saturation attack";
               for [{_i = 0},{_i < ((count _list2) min 4)},{_i=_i+1}] do
               {
                  _target = _list2 select _i;
                 _dir = ((getPos _target select 0)-(getPos mando_airsupport_cmissile select 0)) atan2 ((getPos _target select 1)-(getPos mando_airsupport_cmissile select 1));

                  [mando_airsupport_cmissile, "Bo_GBU12_LGB", mando_airsupport_cmissile_pos, _dir, 89, 0, 300, 100, _target, 5, 2000, 0, 500, "mando_missiles\warheads\mando_missilehead2a.sqf", "mando_missiles\exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 100, true, 5, 0, 0, true, false, "mando_missiles\launch\mando_scudlaunch.sqf", 25, 35, 1, true, 180, 180] execVM "mando_missiles\mando_missile.sqf";
                  Sleep 2;  
                  [mando_airsupport_cmissile, "Bo_GBU12_LGB", mando_airsupport_cmissile_pos, _dir, 89, 0, 300, 100, _target, 5, 2000, 0, 500, "mando_missiles\warheads\mando_missilehead2a.sqf", "mando_missiles\exhausts\mando_missilesmoke1a.sqf", "mando_missile1", 29, 50, true, 5, 0, 0, true, false, "mando_missiles\launch\mando_scudlaunch.sqf", 25, 35, 1, true, 180, 180] execVM "mando_missiles\mando_missile.sqf";
                  Sleep 2;
               };
            }
            else
            {   
               [_side, "HQ"] sideChat "No targets for cruise missile saturation attack";
            };
         };
      }
      else
      {
         [_side, "HQ"] sideChat "No cruise missile launcher present";
      };      
   };

};