         mando_airsupport_type_cb = "C130J";
         mando_airsupport_carpetcode = 
         {
            private["_plane", "_targetpos", "_pos1", "_pos2", "_mines"];
            _plane = _this select 0;
            _targetpos = _this select 1;
            _plane setVariable ["mando_support_cam_pos", [-3, 0, -3]];
            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Mining plane on the way";
            _plane setVariable ["mando_last_plane_text", "Mining plane camera"]; 

            while {(([getPos _plane select 0, getPos _plane select 1, 0] distance _targetpos) > 1500) && (alive _plane)} do
            {
               Sleep 1;
            };
            if (alive _plane) then
            {
               _mines = [];
               for [{_i=0}, {_i<150}, {_i=_i+1}] do
               {
                  _pos1 = _plane modelToWorld [0,2,-4];
                  if ((_i % 2)==0) then
                  {
                     _pos2 = _plane modelToWorld [-4, 2, -4];
                  }
                  else
                  {
                     _pos2 = _plane modelToWorld [4, 2, -4];
                  };
                  _vel = [(velocity _plane select 0)/10+((_pos2 select 0)-(_pos1 select 0))/4*1.5,
                          (velocity _plane select 1)/10+((_pos2 select 1)-(_pos1 select 1))/4*1.5,
                          (velocity _plane select 2)/10+((_pos2 select 2)-(_pos1 select 2))/4*1.5];
                  _ball = "MetalBucket" createVehicle _pos2;
                  _ball setPos _pos2;
                  _ball setVelocity _vel;
                  _mines = _mines + [_ball];  
                  Sleep 0.07;
               };
            };

            Sleep 10;  
            _i = 0;
            {
               _pos1 = getPos _x; 
               deleteVehicle _x;
               createMine ["MineMine", [_pos1 select 0, _pos1 select 1, 0], [], 0];

               _marker = createMarkerLocal [format["mk_mando_mine_%1", _i], _pos1];
               format["mk_mando_mine_%1", _i] setMarkerTypeLocal "Dot";
               format["mk_mando_mine_%1", _i] setMarkerColorLocal "ColorWhite";
               format["mk_mando_mine_%1", _i] setMarkerSizeLocal [0.25, 0.25];
               format["mk_mando_mine_%1", _i] setMarkerTextLocal "m";

               _i = _i + 1;

            } forEach _mines;
            ((findDisplay 23900) displayCtrl 23942) ctrlSetText "MSG: Minefield deployed";
            Sleep 40;
            for [{_i=0}, {_i<150}, {_i=_i+1}] do
            {
               deleteMarkerLocal format["mk_mando_mine_%1", _i];
            };
         };
