         mando_airsupport_type_cb = "AV8B";
         mando_airsupport_carpetcode = 
         {
            private["_plane", "_targetpos", "_widx"];
            _plane = _this select 0;
            _targetpos = _this select 1;
            while {(([getPos _plane select 0, getPos _plane select 1, 0] distance _targetpos) > 2000) && (alive _plane)} do
            {
               Sleep 1;
            };

            if (alive _plane) then
            {
               _widx = [_plane, "BombLauncher"] call mando_weaponindex;
               for [{_i=0}, {_i<6}, {_i=_i+1}] do
               {
                  _plane action ["useWeapon",_plane,driver _plane, _widx];
                  Sleep 0.4;
               };
            };
         };
