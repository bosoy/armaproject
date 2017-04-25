         mando_airsupport_type_ca = "C130J";

         mando_airsupport_code_ca = 
         {
            private["_group", "_planes", "_targetpos", "_ang", "_i", "_spawn_pos"];
            _group = _this select 0;
            _targetpos = getMarkerPos "mk_mandoairsupport";

            _planes = [];
            {
               if (!((vehicle _x) in _planes)) then
               { 
                  _planes = _planes + [vehicle _x];
                  (vehicle _x) setVariable ["mando_support_cam_pos", [-3, 0, -3]];
               };
            } forEach units _group;

            _plane = _planes select 0;
            _spawn_pos = getPos _plane;

            Sleep 2;
            _group setCombatMode "GREEN";
            deleteWaypoint [_group, 2];
            deleteWaypoint [_group, 1];
            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Spectre on the way";



            _ang = getDir _plane;

            _wp = _group addWaypoint [[(_targetpos select 0)+sin(_ang+180)*1200,(_targetpos select 1)+cos(_ang+180)*1200], 0];
            [_group, 1] showWaypoint "NEVER";
            [_group, 1] setWaypointSpeed "NORMAL";
            [_group, 1] setWaypointType "MOVE";


            for [{_i=0},{_i<13},{_i=_i+1}] do
            {
               if (_i < 12) then
               {
                  _wp = _group addWaypoint [[(_targetpos select 0)+sin(_ang)*1200,(_targetpos select 1)+cos(_ang)*1200], 0];
                  [_group, _i+2] showWaypoint "NEVER";
                  [_group, _i+2] setWaypointSpeed "LIMITED";
                  [_group, _i+2] setWaypointType "MOVE";
                  _ang = _ang - 60;
               }
               else
               {
                  _wp = _group addWaypoint [_spawn_pos, 0];
                  [_group, _i+2] showWaypoint "NEVER";
                  [_group, _i+2] setWaypointSpeed "FULL";
                  [_group, _i+2] setWaypointType "MOVE";
               };
            };

            {
               _x setVariable ["mando_last_plane_text", "Spectre camera"];
               [_x, 3, ["LandVehicle"], 200, 100, 2500, 1000, 2, 3, [0.6,0.6], 1, false, "", "Sh_122_HE", [-4,2,-5], 7, [100, 270], 0,[east], false, true, false, "","", "mando_gun2"]execVM"mando_missiles\mando_gun\mando_gunattacker.sqf";
               Sleep 1;

               [_x, 3, ["LandVehicle", "Men"], 200, 100, 2000, 1000, 17, 20, [0.6,0.6], 1, false, "", "G_40mm_HE", [-4,0,-5], 7, [100, 270], 0,[east], false, true, false, "","", "mando_gun"]execVM"mando_missiles\mando_gun\mando_gunattacker.sqf";
            } forEach _planes;

         };
