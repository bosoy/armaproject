/* mando_hud_key_handler.sqf
By Mandoble Oct 2009
*/

private ["_unit", "_list", "_pos", "_ttypes", "_delta", "_log", "_target", "_airtargets", "_structtargets","_mis", "_can_fire", "_fire", "_missparams", "_msg", "_log_target", "_dir", "_launcher", "_old_mode", "_t0", "_ecm", "_activer", "_firer1", "_firer2", "_time_to_fire", "_widx", "_continue", "_ammo", "_weapon"];


_maxscanrange = mando_loscheck_range;
_key = _this select 1;
mando_key_pressed = _key;


if ((_key == mando_keymode) && (mando_hud_num_modes > 0) &&  mandotarget_disp_on) then
{
   // Cycle through available modes

   
   _unit = vehicle player;
   _exit = false;
   if (typeName (_this select 0) == "DISPLAY") then
   {
      _old_mode = mando_hud_mode;
      _continue = true;

	  if ((dayTime * 3600 - mando_planemodetime) < 0.2) exitWith {_exit = true};
      mando_planemodetime = dayTime * 3600;
	  
	  
	  
//      hint format["%1", mando_missileidxbase];

      _dirkey = 1;
	  if (count _this > 2) then
	  {
	     if (_this select 2) then
	     {
	        _dirkey = -1;
	     };
      };
	  
      for [{_i=0},{(_i < count mando_hud_modes)&&(_continue)},{_i=_i+1}] do
      {
         mando_hud_mode = mando_hud_mode + _dirkey;
         if (mando_hud_mode == mando_hud_num_modes) then
         {
            mando_hud_mode = 0;
         };
         if (mando_hud_mode == -1) then
         {
            mando_hud_mode = mando_hud_num_modes - 1;
         };

         // Comprobar siguiente modo o saltar a siguiente valido
         _hudmis = (mando_hud_modes select mando_hud_mode) select 0;
         if (_hudmis >= 0) then
         {
            if (((mando_missileidxbase select _hudmis) select 1) != "") then
            {
               if (((mando_missileidxbase select _hudmis) select 1) in (weapons _unit)) then
               {
                  _continue = false;
               }
               else
               {
                  if (count (mando_missileidxbase select _hudmis) == 3) then
                  {
                     if (((mando_missileidxbase select _hudmis) select 2) in (weapons _unit)) then
                     {
                        _continue = false;
                     }
                  };
               };
            }
            else
            {
               _continue = false;
            };
         }
         else
         {
            _continue = false;
         };
      };

      if (_old_mode != mando_hud_mode) then
      {
         if (_old_mode >= 0) then
         {
            if (!((((mando_hud_modes select mando_hud_mode) select 3) select 0) in 
                ((mando_hud_modes select _old_mode) select 3))) then
            {
               _unit setVariable ["mando_current_target", objNull];
               mando_hud_targets = ["A"];
            };
         };
      };
   };

   if (_exit) exitWith {};
   
   mando_hud_missile = (mando_hud_modes select mando_hud_mode) select 0;
   mando_hud_keepgeo = (mando_hud_modes select mando_hud_mode) select 1;
   mando_hud_guidance = (mando_hud_modes select mando_hud_mode) select 2;  
   mando_time_to_lock = (mando_hud_modes select mando_hud_mode) select 10;


   _unit setVariable ["mando_target_types", (mando_hud_modes select mando_hud_mode) select 3];

   mando_circle_h_max = (mando_hud_modes select mando_hud_mode) select 4;
   mando_circle_h = mando_circle_h_max;

   if (!isNull (uiNameSpace getVariable "mandotarget_disp")) then
   {
      ((uiNameSpace getVariable "mandotarget_disp") displayCtrl 108) ctrlSetText ((mando_hud_modes select mando_hud_mode) select 5);
   };

   call mando_update_ammo;

   if (mando_hud_guidance == 4) then
   {
      [vehicle player] spawn
      {
         private["_continue", "_unit", "_tti", "_posu", "_vel", "_vfin", "_posfin", "_alt", "_log", "_log2"];
         _unit = _this select 0;
         _continue = true;
         _log = "Logic" createVehicleLocal [0,0,0];
         _log2 = "Logic" createVehicleLocal [0,0,0];
         _unit setVariable ["mando_current_target", _log];
         while {_continue} do
         {
            _posu = getPos _unit;
            _vel = velocity _unit;
            _vfin = sqrt((_Vel select 2)^2 + 2*9.8*(_posu select 2));
            _tti = (_vfin - -(_vel select 2))/9.8;
            _posfin = [(_posu select 0)+(_vel select 0)*_tti,(_posu select 1)+(_vel select 1)*_tti, 0];
            _log2 setPos _posfin;
            _alt = (getPosASL _unit select 2) - (getPosASL _log2 select 2);
            _vfin = sqrt((_Vel select 2)^2 + 2*9.8*_alt);
            _tti = (_vfin - -(_vel select 2))/9.8;
            if (!(finite ((_vfin - -(_vel select 2))/9.8))) then
            {
               _vfin = 1;
               _tti = 1;
            };

            _posfin = [(_posu select 0)+(_vel select 0)*_tti,(_posu select 1)+(_vel select 1)*_tti, 0];


            _log setPos _posfin;
            mando_ccip_time = floor _tti;
            mando_ccip_dist = floor (_log distance _unit);
            Sleep 0.01;

            if (mando_hud_guidance != 4) then
            {
               _continue = false;
            };
         };
         deleteVehicle _log;
         deleteVehicle _log2;
         _unit setVariable ["mando_current_target", objNull];
      };
   };
   
   
   

   if (mando_hud_missile >= 0) then
   {
      mando_missileidx = (mando_missileidxbase select mando_hud_missile) select 0;

      // Update thrusted range and active range on HUD
      if (!isNull (uiNameSpace getVariable "mandotarget_disp")) then
      {
         _speedmax = (mando_hud_misp select mando_hud_missile) select 6;
         if (_speedmax == 0) then
         {
            _speedmax = 1 max ((speed vehicle player)/3.6);
         };
         _acceleration = (mando_hud_misp select mando_hud_missile) select 7; // OJO, accel puede ser array
         _speedini = ((speed vehicle player)/3.6 + ((mando_hud_misp select mando_hud_missile) select 5)) max 1;
         _endurance = (mando_hud_misp select mando_hud_missile) select 17;
         if (_acceleration > 0) then
         {
            _t0 = ((mando_hud_misp select mando_hud_missile) select 21) min ((_speedmax - _speedini)/_acceleration);
            mando_minimumrange = _speedini * _t0 + 0.5*_acceleration*_t0^2;
            if (_t0 < ((mando_hud_misp select mando_hud_missile) select 21)) then
            {
               _t0 = ((mando_hud_misp select mando_hud_missile) select 21) - _t0;
               mando_minimumrange = mando_minimumrange + _speedmax * _t0;
            };


            _t0 = _endurance min ((_speedmax - _speedini)/_acceleration);
             mando_maxthrustedrange = _speedini * _t0 + 0.5*_acceleration*_t0^2;
            if (_t0 < _endurance) then
            {
               _t0 = _endurance - _t0;
               mando_maxthrustedrange =  mando_maxthrustedrange + _speedmax * _t0;
            };

            if ((mando_hud_guidance == 2) || (mando_hud_guidance == 1)) then
            {
               _activer = 0;
            }
            else
            {
               _activer = floor(((mando_hud_misp select mando_hud_missile) select 10)/100)/10;
            };
         }
         else
         {
            mando_maxthrustedrange = 0;
            mando_minimumrange = 0;
         };

         if (mando_maxthrustedrange > 0) then
         {
            ((uiNameSpace getVariable "mandotarget_disp") displayCtrl 113) ctrlSetText format["AR:%1Km / TR:%2Km / MR:%3m", _activer, floor (mando_maxthrustedrange/1000), floor (mando_minimumrange)];
         }
         else
         {
            ((uiNameSpace getVariable "mandotarget_disp") displayCtrl 113) ctrlSetText ""; 
         };
      };
   }
   else
   {
      if (!isNull (uiNameSpace getVariable "mandotarget_disp")) then
      {
         ((uiNameSpace getVariable "mandotarget_disp") displayCtrl 113) ctrlSetText ""; 
      };
   };
};



if ((_key == mando_keylock) && ((dayTime * 3600 - mando_planelocktime)>0.5) && mandotarget_disp_on) then 
{
// L CTRL, get target
   mando_planelocktime = dayTime * 3600;

   _unit = vehicle player;
   _ttypes = _unit getVariable "mando_target_types";
   _target = objNull;

   _airtargets = "Air" in _ttypes;
   switch (_ttypes select 0) do
   {
      case "REMOTE":
      {
         switch (side player) do
         {
            case west:
            {
               if ((count mando_remote_targets_w) > 0) then
               {
                  mando_remote_selected = mando_remote_selected + 1; 
                  if (mando_remote_selected >= (count mando_remote_targets_w)) then
                  {
                     mando_remote_selected = 0;
                  };
                  _target = mando_remote_targets_w select mando_remote_selected;
               };
            };
     
            case east:
            {
               if ((count mando_remote_targets_e) > 0) then
               {
                  mando_remote_selected = mando_remote_selected + 1; 
                  if (mando_remote_selected >= (count mando_remote_targets_e)) then
                  {
                     mando_remote_selected = 0;
                  };
                  _target = mando_remote_targets_e select mando_remote_selected;
               };        
            };        

            case resistance:
            {
               if ((count mando_remote_targets_r) > 0) then
               {
                  mando_remote_selected = mando_remote_selected + 1; 
                  if (mando_remote_selected >= (count mando_remote_targets_r)) then
                  {
                     mando_remote_selected = 0;
                  };
                  _target = mando_remote_targets_r select mando_remote_selected;
               };        
            };        
         };
      };

      case "RADAR":
      {
         if ((count mando_radars) > 0) then
         {
            mando_radar_selected = mando_radar_selected + 1; 
            if (mando_radar_selected >= (count mando_radars)) then
            {
               mando_radar_selected = 0;
            };
            _target = mando_radars select mando_radar_selected;
         };
      };

      case "GROUND":
      {
         mando_ground_hud_target setPos (screenToWorld [0.5,0.5]);
         _target = mando_ground_hud_target;
      };

      case "LOCATIONS":
      {
         mando_get_vis_timed_target = false;
         mando_get_vis_target = false;
      };

      case "":
      {
         mando_get_vis_timed_target = false;
         mando_get_vis_target = false;
      };


      default 
      {
         mando_get_vis_timed_target = true;
      };
   };


   if (!isNull _target) then 
   {
      if (_target != vehicle player) then
      {
         if (count crew _target > 0) then
         {
            mando_lockedon=_target;
            publicVariable "mando_lockedon";
         };

         _unit setVariable ["mando_current_target", _target];
         playSound "mando_target1";
      };
   }
   else
   {
      if (((_ttypes select 0) != "LOCATIONS") && ((_ttypes select 0) != "")) then
      {
         _unit setVariable ["mando_current_target", objNull];
      };
   };

};




if ((_key == mando_keyfire) && mandotarget_disp_on) then
{ 
// L Windows, firing missile
   if (mando_hud_missile >= 0) then
   {
      _launcher = vehicle player;

      if (count (mando_missileidxbase select mando_hud_missile) == 3) then
      {
         if (((mando_missileidxbase select mando_hud_missile) select 1) in (weapons _launcher)) then
         {
            _weapon = (mando_missileidxbase select mando_hud_missile) select 1;
         }
         else
         {
            _weapon = (mando_missileidxbase select mando_hud_missile) select 2;
         };
      }
      else
      {
         _weapon = (mando_missileidxbase select mando_hud_missile) select 1;
      };

      if (_weapon != "") then
      {
         _widx = [_launcher, _weapon] call mando_weaponindex;
         if (mando_hud_guidance == 4) then
         {
            _time_to_fire = getNumber(configFile>>"cfgWeapons" >> _weapon >> "reloadTime");
         }
         else
         {
            _time_to_fire = 2 max getNumber(configFile>>"cfgWeapons" >> _weapon >> "reloadTime");
         };
      }
      else
      {
         _time_to_fire = 2;
      };

      if ((dayTime * 3600 - mando_planefiretime)>_time_to_fire) then
      {
         _can_fire = true;
         if (mando_missileidx >= 0) then 
         {
            if ((vehicle player getVariable format["mando_missilesleft%1", mando_missileidx]) <= 0) then
            {
               _can_fire = false;
            };
         }
         else
         {
            if ((vehicle player ammo _weapon) <= 0) then
//            if ((vehicle player ammo ((mando_missileidxbase select mando_hud_missile) select 1)) <= 0) then
            {
               _can_fire = false;
            }; 
         };


         if (_can_fire && mando_ihavemissiles) then
         {
            _fire = false;
            _target =  vehicle player getVariable "mando_current_target";


//            if (!isNull _target || ((vehicle player getVariable "mando_target_types") select 0 == "")) then

//            if (!isNull _target || (mando_hud_guidance == 4) || (mando_hud_guidance == 5)) then
// Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual, 4 CCIP, 5 LOAL
//            if (!isNull _target || (mando_hud_guidance > 4)) then
            if (!isNull _target || (mando_hud_guidance > 2)) then
            {
               mando_planefiretime = dayTime * 3600;

               [_time_to_fire]spawn
               {

                  mando_hud_colors set [3, [((mando_hud_colors select 0) select 0)/2, ((mando_hud_colors select 0) select 1)/2,((mando_hud_colors select 0) select 2)/2]];
                  Sleep (_this select 0);            
                  mando_hud_colors set [3, [(mando_hud_colors select 0) select 0, (mando_hud_colors select 0) select 1,(mando_hud_colors select 0) select 2]];
               }; 


               _dir = 0;
               _vangle = 0;
      

               _ttypes = _launcher getVariable "mando_target_types";

               _missparams = [];
               _missparams = _missparams + (mando_hud_misp select mando_hud_missile);


               if (mando_missileidx >= 0) then
               {
                  // Virtual missile (update pos, _dir y _vangle)

                  if (_weapon == "") then 
                  {
                     _dir           = getDir _launcher;
                     _vangle        = 0;
                     mando_firingpos set [0, (mando_firingpos select 0)*mando_pilon];
                     mando_pilon = mando_pilon * -1;
                  }
                  else
                  {
                     _dir = ((_launcher weaponDirection _weapon) select 0) atan2 ((_launcher weaponDirection _weapon) select 1);
                     _vangle = asin((_launcher weaponDirection _weapon) select 2) - asin(vectorDir _launcher select 2)
                  };

                  _pos = [mando_firingpos select 0, mando_firingpos select 1, mando_firingpos select 2];
                  if (count mando_firingpos > 3) then
                  {
                     _pos = [(_pos select 0)+sin(_dir - (getDir _launcher))*(mando_firingpos select 3), (_pos select 1)+cos(_dir - (getDir _launcher))*(mando_firingpos select 3),(_pos select 2)+sin(_vangle)*(mando_firingpos select 3)];
                  };

                  _missparams set [2, _pos];
                  _missparams set [3, _dir];
                  _missparams set [4, _vangle];
                  _missparams set [8, _target];

                  _fire = true;
               }
               else
               {
                  // BIS Missile (update body, pos, _dir, _speedini y _vangle)

                  if (player == driver _launcher) then
                  {
                     _firer1 = driver _launcher;
                     _firer2 = gunner _launcher;
                  } 
                  else
                  {
                     _firer1 = gunner _launcher;
                     _firer2 = driver _launcher;
                  };                 



                  mando_firing = true;
                  if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
                  {
                     call compile format["_handle = (vehicle player) fireAtTarget [objNull, '%1']", _weapon];
                  }
                  else
                  {
                     _launcher action ["useWeapon",_launcher, _firer1, _widx];
                  };

                  _ammo = _launcher ammo _weapon;
                  if (mando_hud_guidance != 4) then
                  {
                     Sleep 0.1;
                     _mis = _launcher getVariable "mando_bis_missile_fired";

                     if (isNull _mis) then
                     {
                        if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
                        {
                           call compile format["_handle = (vehicle player) fireAtTarget [objNull, '%1']", _weapon];
                        }
                        else
                        {
                           _launcher action ["useWeapon", _launcher, _firer2, _widx];
                        };
                        Sleep 0.1;
                        _mis = _launcher getVariable "mando_bis_missile_fired";
                     };
                  }
                  else
                  {
                     _mis = (getPos _launcher) nearestObject "BombCore";
                     if (isNull _mis) then
                     {
                        if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
                        {
                           call compile format["_handle = (vehicle player) fireAtTarget [objNull, '%1']", _weapon];
                        }
                        else
                        {
                           _launcher action ["useWeapon", _launcher, _firer2, _widx];
                        };
                     };
                     _mis = objNull;
                  };
Sleep 0.1;

                  if (!isNull _mis) then
                  {
                     _missilebody = typeOf _mis;					 
					 
                     if ((_missparams select 6) == 0) then
                     {
                        _missparams set [6, (speed _launcher)/3.6];
                     };
//                     _speedini = (((speed _mis)/3.6 - (speed _launcher)/3.6) + (_missparams select 5)) min (_missparams select 6);
                     _speedini = (((speed _mis)/3.6 - (speed _launcher)/3.6) + (_missparams select 5)) min 200;

                     if (!mando_hud_keepgeo) then
                     {
                        _pos = _launcher worldToModel (getPos _mis);


                        if ((getPos _launcher select 2) > 10) then         
                        {
                        // Plane
                           if (((_pos select 2) > -2) && ((_mis distance _launcher) < 15)) then
                           {
                           // 2m minimum separation with plane
                              _pos set [2, mando_firingpos select 2];
                           };
                        };                 

                        _dir = getDir _mis;

                        if (_weapon == "") then 
                        {
//                           _vangle = 0;
                           _vangle        = asin (vectorDir _mis select 2) - asin(vectorDir _launcher select 2);
                        }
                        else
                        {
//                           _vangle        = asin(vectorDir _mis select 2) - asin(vectorDir _launcher select 2);
//                           _vangle        = 0;   // <--------------- OJO
//                             _vangle = asin (vectorDir _mis select 2);

                           _vangle        = asin (vectorDir _mis select 2) - asin(vectorDir _launcher select 2);

                        };                 
                     }
                     else
                     {

                        if (_weapon == "") then 
                        {
                           _dir = getDir _launcher;
                           _vangle = 0;
                           mando_firingpos set [0, (mando_firingpos select 0)*mando_pilon];
                           mando_pilon = mando_pilon * -1;
                        }
                        else
                        {
                           _dir = ((_launcher weaponDirection _weapon) select 0) atan2 ((_launcher weaponDirection _weapon) select 1);
                           _vangle = asin((_launcher weaponDirection _weapon) select 2) - asin(vectorDir _launcher select 2);
                        };

                        _pos = [mando_firingpos select 0, mando_firingpos select 1, mando_firingpos select 2];
                     };

                     if (count mando_firingpos > 3) then
                     {
                        _pos = [(_pos select 0)+sin(_dir - (getDir _launcher))*(mando_firingpos select 3), (_pos select 1)+cos(_dir - (getDir _launcher))*(mando_firingpos select 3),(_pos select 2)+sin(_vangle)*(mando_firingpos select 3)];
                     };

 		             _mis setPos [60000,60000,60000];
                     [_mis] spawn
                     {
                        _missile = _this select 0;            
                        Sleep 6;
                        if (alive _missile) then
                        { 
                           deleteVehicle _missile;
                        };
                     };					 

                     if ((_missparams select 1) == "") then
                     {
                        _missparams set [1, _missilebody];
                     };
                     _missparams set [2, _pos];
                     _missparams set [3, _dir];
                     _missparams set [4, _vangle];
                     _missparams set [5, _speedini];
                     _missparams set [8, _target];

                     _fire = true;
                  }
                  else
                  {
                     // Virtual missile (update pos, _dir y _vangle)
                     if ((mando_hud_guidance != 4) && ((_launcher ammo _weapon) < _ammo))then
                     {
                        if (_weapon == "") then 
                        {
                           _dir           = getDir _launcher;
                           _vangle        = 0;
                           mando_firingpos set [0, (mando_firingpos select 0)*mando_pilon];
                           mando_pilon = mando_pilon * -1;
                        }
                        else
                        {
                           _dir = ((_launcher weaponDirection _weapon) select 0) atan2 ((_launcher weaponDirection _weapon) select 1);
                           _vangle = asin((_launcher weaponDirection _weapon) select 2) - asin(vectorDir _launcher select 2)
                        };

                        _pos = [mando_firingpos select 0, mando_firingpos select 1, mando_firingpos select 2];
                        if (count mando_firingpos > 3) then
                        {
                           _pos = [(_pos select 0)+sin(_dir - (getDir _launcher))*(mando_firingpos select 3), (_pos select 1)+cos(_dir - (getDir _launcher))*(mando_firingpos select 3),(_pos select 2)+sin(_vangle)*(mando_firingpos select 3)];
                        };

                        _magazines = getArray(configFile>>"cfgWeapons" >> _weapon >> "magazines");
                        if (count _magazines > 0) then
                        {
                           _missparams set [1, getText(configFile>>"CfgMagazines" >> (_magazines select 0) >> "ammo")];
                        }
                        else
                        {
                           _missparams set [1, "M_Sidewinder_AA"];
                        };

                        _missparams set [2, _pos];
                        _missparams set [3, _dir];
                        _missparams set [4, _vangle];
                        _missparams set [8, _target];
   
                        _fire = true;
                     }; 
                  };
               };


               if (_fire) then
               {
                  _ecm = _target getVariable "mando_ecm_on";
                  if (isNil "_ecm") then 
                  {
                     _ecm = false;
                     _target setVariable ["mando_ecm_on", false];
                  };


                  switch (mando_hud_guidance) do
                  {
                     case 0:  // Active rdr mode, target remains the same
                     {
                        _delta = ((mando_hud_misp select mando_hud_missile) select 27) - ((mando_hud_modes select mando_hud_mode) select 6);

                        _missparams set [27, ((mando_hud_misp select mando_hud_missile) select 27) - _delta*mando_dec_acc_factor];
                     };

                     case 1:  // IR mode, if headon vs air unit, accuracy greatly reduced
                     {
                        _delta = ((mando_hud_misp select mando_hud_missile) select 27) - ((mando_hud_modes select mando_hud_mode) select 6);

                        _missparams set [27, ((mando_hud_misp select mando_hud_missile) select 27) - _delta*mando_dec_acc_factor];

                     };

                     case 2:  // SARH mode, target is the plane's target at each time
                     {
                        _log_target = "Logic" createVehicleLocal (getPos _target);
                        _missparams set [8, _log_target];
                     };

                     case 3:  // Manual mode, target moves ahead of the missile with weapon or sight direction
                     {
                        _weapon = _launcher getVariable "mando_weapon_name";
                        if (_weapon != "") then
                        {
                           if (_weapon == "sight") then
                           {
                              _pos = positionCameraToWorld [0,0,100];
                              _pos0 = positionCameraToWorld [0,0,0];
                              _dir = [((_pos select 0)-(_pos0 select 0))/100,((_pos select 1)-(_pos0 select 1))/100,((_pos select 2)-(_pos0 select 2))/100];
                           }
                           else
                           {
                              _dir = _launcher weaponDirection _weapon;
                           };
                        } 
                        else
                        {
                           _dir = vectorDir _launcher;
                        };
                        _pos = [(getPos _launcher select 0)+(_dir select 0)*100,(getPos _launcher select 1)+(_dir select 1)*100,(getPos _launcher select 2)+(_dir select 2)*100];
                        _log_target = "Logic" createVehicleLocal _pos;
                        _log_target setPos _pos;
                        _missparams set [8, _log_target];
                     };

                     case 5:  // LOAL mode, target moves ahead until a target is selected
                     {
                        if (!isNull (vehicle player getVariable "mando_current_target")) then
                        {
                           _pos = getPos _target;
                        }
                        else
                        {
                           _pos = [(getPos _launcher select 0)+sin(getdir _launcher)*4000,(getPos _launcher select 1)+cos(getdir _launcher)*4000,0];
                        };
                        _log_target = "Logic" createVehicleLocal _pos;
                        _log_target setPos _pos;
                        _missparams set [8, _log_target];
                     };

                  };

                  if (typeName ((mando_hud_misp select mando_hud_missile) select 8) == "STRING") then
                  {
                      [_launcher, _missparams select 2, _missparams select 8] execVm ((mando_hud_misp select mando_hud_missile) select 8);
                  }
                  else
                  {
                     _missparams execVM mando_missile_path+"mando_missile.sqf";
                  };

                  switch (mando_hud_guidance) do
                  {
                     case 0:  // Active mode, target remains the same
                     {
                     };

                     case 1:  // IR mode, target remains the same
                     {
                     };

                     case 2:  // SARH mode, target is the plane's target at each time
                     {
                        Sleep 0.2;
//                        _mis = (getPos _launcher) nearestObject (_missparams select 1);
                        _mis = objNull;
                        while {(isNull _mis) || (isNil "_mis")} do
                        {
                           _mis = _launcher getVariable "mando_missile_fired";
                           Sleep 0.05;
                        };

                        [_log_target, _mis, _launcher] spawn
                        {
                           private["_log", "_mis", "_launcher", "_pos", "_target", "_ecm"];
                           _log = _this select 0;
                           _mis = _this select 1;
                           _launcher = _this select 2;
                           _target = _launcher getVariable "mando_current_target";

                           // Triger a missile launch warning
                           mando_missileincomming = _mis;
                           mando_missiletarget = _target;
                           mando_missilerequest = true;

                           publicVariable "mando_missileincomming";publicVariable "mando_missiletarget";publicVariable "mando_missilerequest";
                           _target setVariable ["mando_missileincomming", _mis, true];


                           while {alive _mis && alive _launcher} do
                           {
                              _target = (_launcher getVariable "mando_current_target");

                              if (alive _target) then
                              {
                                 _ecm = _target getVariable "mando_ecm_on";
                                 if (isNil "_ecm") then 
                                 {
                                    _ecm = false;
                                    _target setVariable ["mando_ecm_on", false];
                                 };
                        
                                 if ((_ecm && ((random 100) > 90)) || !_ecm) then
                                 {
                                    _dist = _target distance _mis;
                                    _tti = (_dist / (((speed _mis)/3.6) max 100)) min 1;

//                                    _twpos = _target modelToWorld [0,0,0];
                                    _twpos = [getPos _target select 0,getPos _target select 1, (getPos _target select 2)+0.25];

                                    _tvel = velocity _target;
                                    _twpos = [(_twpos select 0)+(_tvel select 0)*_tti,(_twpos select 1)+(_tvel select 1)*_tti,(_twpos select 2)+(_tvel select 2)*_tti];
                                    _log setPos _twpos;
                                 };
                              };
                              Sleep 0.003;
                           };
                           Sleep 6;
                           deleteVehicle _log;
                        };
                     };

                     case 3:  // Manual mode, target moves ahead of the missile with weapon direction
                     {
                        Sleep 0.2;
                        _mis = (getPos _launcher) nearestObject (_missparams select 1);

                        [_log_target, _mis, _launcher, _weapon] spawn
                        {
                           private["_log", "_mis", "_launcher", "_weapon", "_dist", "_pos", "_vdir"];
                           _log = _this select 0;
                           _mis = _this select 1;
                           _launcher = _this select 2;
                           _weapon = _this select 3;

                           while {alive _mis && alive _launcher} do
                           {
                              _vdir = _launcher weaponDirection _weapon;        
                              _dist = (_launcher distance _mis)+60;
                              _pos = positionCameraToWorld [0,0,_dist];
                              _log setPos _pos;
                              Sleep 0.005;
                           };
                           Sleep 2;
                           deleteVehicle _log;
                        };
                     };


                     case 5:  // LOAL mode, target is locked on after launch
                     {
                        Sleep 0.2;
                        _mis = (getPos _launcher) nearestObject (_missparams select 1);
                        [_log_target, _mis, _launcher] spawn
                        {
                           private["_log", "_mis", "_launcher", "_pos", "_target", "_ecm"];
                           _log = _this select 0;
                           _mis = _this select 1;
                           _launcher = _this select 2;


                           while {alive _mis && alive _launcher} do
                           {
                              _target = (_launcher getVariable "mando_current_target");
                              if (!isNull _target) then
                              { 
                                 _pos = getPosASL _target;
                                 _log setPosASL [_pos select 0,_pos select 1,(_pos select 2)+0.2];
                                 Sleep 0.02;
                              }
                              else
                              {
                                 Sleep 0.1;
                              };
                           };
						   Sleep 6;
                           deleteVehicle _log;
                        };
                     };



                  };             
               };


               if (mando_missileidx >= 0) then
               {
                  vehicle player setVariable [format["mando_missilesleft%1", mando_missileidx], (vehicle player getVariable format["mando_missilesleft%1", mando_missileidx]) - 1, true];
               };

               if (!isNull (uiNameSpace getVariable "mandotarget_disp")) then
               {
                  call mando_update_ammo;
               };
            }
            else
            {
               titleRsc["mandonolock", "PLAIN"];
            };
         }
         else
         {
//            titleRsc["mandonomissiles", "PLAIN"];
         };

         Sleep(2);
         titleText["", "PLAIN DOWN"];
      }
      else
      {
         playSound "mando_denied";
      };
   };
};



if ((_key == mando_keyflare) && mandotarget_disp_on) then 
{ 
// L shift (launching flares)
   if ((dayTime * 3600 - mando_planechafftime)>1) then
   {

      mando_planechafftime = dayTime * 3600;
      []spawn
      {
         mando_hud_colors set [4, [((mando_hud_colors select 0) select 0)/2, ((mando_hud_colors select 0) select 1)/2,((mando_hud_colors select 0) select 2)/2]];
         Sleep 0.5;
         mando_hud_colors set [4, [(mando_hud_colors select 0) select 0, (mando_hud_colors select 0) select 1,(mando_hud_colors select 0) select 2]];
      }; 

      if (((vehicle player getVariable "mando_flaresleft") > 0) && mando_ihaveflares) then
      {
         [vehicle player, 1] spawn mando_chaffflares;

         vehicle player setVariable ["mando_flaresleft", (vehicle player getVariable "mando_flaresleft") - 1, true];
         titleText[format["\n\n%1 flares left", (vehicle player getVariable "mando_flaresleft")], "PLAIN DOWN"];

         _unit = vehicle player;
         call mando_update_flares;
      }
      else
      {
         if (mando_ihaveflares) then
         {
            titleRsc["mandonoflares", "PLAIN"];
         };
      };
   }
   else
   {
      if (mando_ihaveflares) then
      {
         playSound "mando_denied";
      };
   };
};


if (_key == mando_keyecm) then 
{ 
   if ((vehicle player getVariable "mando_ecm_sts" == 0) &&
       (vehicle player getVariable "mando_ecm_time" > 0)) then
   {
      playSound "mando_ecm_on";
      vehicle player setVariable ["mando_ecm_sts", 1];
      []spawn
      {
         private["_continue", "_unit", "_playerpos"];
         _unit = vehicle player;
         if (driver _unit == player) then
         {
            _playerpos = 0;
         }
         else
         {
            _playerpos = 1;
         };

         _unit setVariable ["mando_ecm_on", true, true];
         _unit setVariable ["mando_ecm_time", _unit getVariable "mando_ecm_max_time"];
         _continue = true;
         while {_continue} do
         { 
            Sleep 1;
            // Condicion de salida total
            if (!(alive _unit) || (isNull _unit) || ((_playerpos == 0) && (driver _unit != player)) || ((_playerpos == 1) && (gunner _unit != player))) then
            {
               _continue = false;
            };

            if (_continue) then
            {
               _unit setVariable ["mando_ecm_time", (_unit getVariable "mando_ecm_time") - 1];
               if ((_unit getVariable "mando_ecm_time") == 0) then
               {            
                  if ((_unit getVariable "mando_ecm_sts") == 1) then
                  {
                     _unit setVariable ["mando_ecm_sts", 2];
                     _unit setVariable ["mando_ecm_on", false, true];
                     _unit setVariable ["mando_ecm_time", _unit getVariable "mando_ecm_max_time"];
                  }
                  else
                  {
                     _unit setVariable ["mando_ecm_sts", 0];
                     _unit setVariable ["mando_ecm_time", _unit getVariable "mando_ecm_max_time"];
                     _continue = false;
                  };
               };

               if ((_unit getVariable "mando_ecm_time") == 5) then
               {
                  playSound "mando_ecm_off";
               };

               call mando_update_flares;
            };
         };
    
         // Condicion de salida total
         if (!(alive _unit) || (isNull _unit) || ((_playerpos == 0) && (driver _unit != player)) || ((_playerpos == 1) && (gunner _unit != player))) then
         {
            _unit setVariable ["mando_ecm_on", false, true];
         };
      };
   }
   else
   {
      if (_unit getVariable "mando_ecm_max_time" > 0) then
      {
         playSound "mando_denied";
      };
   };
};