mando_rwr = 
{
   private["_misecm", "_incoming_missiles", "_unit", "_i", "_posc", "_posm", "_dist", "_angh", "_posu"];

   _unit = _this select 0;

   mando_hud_rwr_overriden = true;

   _unit setVariable ["mando_missileincomming", objNull];
   _incoming_missiles = [];
   while {!mando_exit_hud} do
   {
      _misecm = _unit getVariable "mando_missileincomming";
      if (!isNull _misecm) then
      {   
         if (!(_misecm in _incoming_missiles)) then
         {
            if (count _incoming_missiles < 3) then
            {
               _incoming_missiles = _incoming_missiles + [_misecm];
            }
            else
            {
               _incoming_missiles set [2, _incoming_missiles select 1]; 
               _incoming_missiles set [1, _incoming_missiles select 0]; 
               _incoming_missiles set [0, _misecm]; 
            };
            mando_warning = _unit;
            publicVariable "mando_warning";
         };
         _unit setVariable ["mando_missileincomming", objNull];
      }; 



      if (count _incoming_missiles > 0) then
      {
         _posu = getPosASL _unit;

         for [{_i = 0},{_i < 3},{_i = _i + 1}] do
         {
            if (_i < count _incoming_missiles) then
            {
               _misecm =  _incoming_missiles select _i;
            } 
            else
            {
               _misecm = objNull;
            };


            if (!isNull _misecm) then
            {            
               _posm = getPos _misecm;

               _angh = ((_posm select 0) - (_posu select 0)) atan2 ((_posm select 1) - (_posu select 1));
               _angh = _angh - getDir _unit;      

               if (((_misecm worldToModel _posu) select 1) > 0) then
               {
                  _unit animate [format["Stretch_rwr%1", _i+1], ((_misecm distance _unit) min 1000)/1000];
                  _unit animate [format["Rotate_rwr_%1", _i+1], (_angh-90)/360];

               }
               else
               { 
                  _unit animate [format["Stretch_rwr%1", _i+1], 0];
                  _incoming_missiles set [_i, objNull];
               };
            }
            else
            {
               _unit animate [format["Stretch_rwr%1", _i+1], 0];
            };
         };
         _incoming_missiles = _incoming_missiles - [objNull];
      };

      Sleep(0.03);
   };
};



/* Customized MMA HUD Radar */

private ["_veh", "_list", "_max_h", "_max_y", "_orgx_s", "_orgy_s", "_i", "_list", "_pos", "_dist", "_angh", "_log", "_scale", "_old_scale", "_contact", "_dir", "_target", "_got_a_target"];


_veh = Vehicle player;
_orgx_s =0.5;
_max_h = 1;
_orgy_s = 1;
_log = "logic" CreateVehicleLocal [0, 0, 0];
_old_scale = 1;

[_veh] spawn mando_rwr;

while {!mando_exit_hud} do 
{
   _list = +mando_hud_targets;
   if ((count _list > 1) && ("A" in _list) && (_veh getVariable "MFD_READY")) then 
   {
      _max_y = 0;
      {
         if (TypeName _x == "Object") then 
         {
            _dist = _veh Distance _x;
            if (_dist > _max_y) then 
            {
               _max_y = _dist;
            };
         };
      } foreach _list;
      _max_y = Floor((_max_y + 3000) / 3000);
      _scale = (_max_y Min 4);

      if (_scale != _old_scale) then 
      {
         // Change Background paa (_scale goes from 1 to 4, being 1 3Km and 4 12Km)
         switch (_scale) do 
         {
            case 1: 
            { 
               _veh setObjectTexture [3, "mando_missiles\huds\custom\images\radar\radar3km_nb.paa"];
            };

            case 2: 
            { 
               _veh setObjectTexture [3, "mando_missiles\huds\custom\images\radar\radar6km_nb.paa"];
            };

            case 3: 
            { 
               _veh setObjectTexture [3, "mando_missiles\huds\custom\images\radar\radar9km_nb.paa"];
            };

            case 4:
            { 
               _veh setObjectTexture [3, "mando_missiles\huds\custom\images\radar\radar12km_nb.paa"];
            };
         };
         _old_scale = _scale;
      };

      _max_y = _max_y * 3000;
      _posu = GetPos _veh;
      _log SetPos _posu;
      switch (_veh GetVariable "mando_weapon_name") do 
      {
         case "": 
         {
            _log SetDir GetDir _veh;
         };

         case "sight": 
         {
            _pos = PositionCameraToWorld [0,0,100];
            _dir = ((_pos select 0) - (_posu select 0)) atan2 ((_pos select 1) - (_posu select 1));
            _log SetDir _dir;
         };

         default 
         {
            _dir = ((_unit WeaponDirection (_veh GetVariable "mando_weapon_name")) select 0) atan2 ((_unit weaponDirection (_veh getVariable "mando_weapon_name")) select 1);
            _log SetDir GetDir _veh;
         };
      };

      _target = (_veh GetVariable "mando_current_target");

      _got_a_target = false;
      for [{_i = 0}, {_i < 6}, {_i = _i + 1}] do 
      { 
         if (_i < ((count _list) - 1)) then 
         {
            _contact = (_list select _i);
            if (!IsNull _contact) then 
            {
               if (TypeName _contact != "LOCATION") then 
               {
                  _pos = _log WorldToModel GetPos _contact;
                  _dist = (_veh Distance _contact) * _max_h / _max_y;
               } 
               else 
               {
                  _pos = _log WorldToModel LocationPosition _contact;
                  _dist = (_veh Distance (LocationPosition _contact)) * _max_h / _max_y;
               };

               _dist = _dist Min _max_h;
               _angh = (_pos select 0) atan2 (_pos select 1);
               if (Abs _angh < 60) then 
               {
                  _veh animate [format["moveMFDcontact%1_hor", _i+1], _orgx_s + sin(_angh) * _dist];
                  _veh animate [format["moveMFDcontact%1_vert", _i+1], _orgy_s - cos(_angh) * _dist]; 

                  if (!IsNull _target) then 
                  {
                     if (TypeName _contact != "LOCATION") then 
                     {
                        if (_target == _contact) then 
                        {
                           _dir = (GetDir _contact) - (GetDir _veh);

                           _dir = (GetDir _veh) - (GetDir _contact) + 180;
                           _log SetDir _dir;

                           _got_a_target = true;

                           _veh animate ["moveMFDcontact7_hor",_orgx_s + sin(_angh) * _dist];
                           _veh animate ["moveMFDcontact7_vert",_orgy_s - cos(_angh) * _dist];
                           _veh animate ["mma_targetvector", (getDir _log)/360];
                        };
                     };
                  };
               } 
               else
               {
                  _veh animate [format["moveMFDcontact%1_hor", _i+1], -0.1];
               };
            }
            else
            {
               _veh animate [format["moveMFDcontact%1_hor", _i+1], -0.1];
            };
         }
         else
         {
            _veh animate [format["moveMFDcontact%1_hor", _i+1], -0.1];
         };
      };

      if (!_got_a_target) then
      {
         _veh animate ["moveMFDcontact7_hor",-0.1];
      };
   }
   else
   {
      {
         _veh animate [format["moveMFDcontact%1_hor", _x+1], -0.1];
      } foreach [0, 1, 2, 3, 4, 5, 6];
   };
   sleep 0.01;
};

DeleteVehicle _log;