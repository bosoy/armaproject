/*
 mando missile center dialog handler
 mando_missilecenterdlg.sqf v2.3
 Feb 2008 Mandoble

 Purpose: Handles the controls and text info of the missile center left and right panels.


 This script is executed automatically by mando_missilecenter.sqs
*/

disableSerialization;

MCC_DLGMISSILECENTER	=21900;
MCC_FRAME		=21901;
MCC_MAP			=21902;
MCC_CONTACTLIST		=21903;
MCC_CONTACT		=21904;
MCC_TRACK		=21905;
MCC_NOMAP		=21906;
MCC_MAPCONTACT		=21907;
MCC_MAPTARGET		=21908;
MCC_CLOSECONTROL	=21909;
MCC_TARGET		=21910;
MCC_DISTANCE		=21911;
MCC_TTI			=21912;
MCC_ASLT		=21913;
MCC_SPEEDT		=21914;
MCC_DIRT		=21915;
MCC_ANGDT		=21916;
MCC_TYPET		=21917;
MCC_MISSILESLEFT	=21918;
MCC_ACTIVERADAR		=21919;
MCC_ENDURANCE		=21920;
MCC_MAXSPEED		=21921;
MCC_FIREMISSILE		=21922;
MCC_MODE0ALT		=21923;
MCC_MODE0ALTE		=21924;
MCC_CAMERAONOFF		=21925;
MCC_MODE 		=21926;
MCC_FOLLOW1		=21927;
MCC_FOLLOW2		=21928;
MCC_FOLLOW3		=21929;
MCC_DISTANCEM		=21930;
MCC_SPEEDM		=21931;
MCC_ALTITUDEM		=21932;
MCC_ENGINEON		=21933;
MCC_ENGINEOFF		=21934;
MCC_ENDURANCEM		=21935;
MCC_GROUNDNO		=21936;
MCC_GROUNDYES		=21937;
MCC_BACKLEFT            =21938;
MCC_BACKRIGHT           =21939;
MCC_AIMCIRCLE           =21940;
MCC_INRGN               =21943;
MCC_HELP                =21944;

private["_launcher", "_targettypes", "_scanrange", "_scanfreq", "_antimissile", "_missileparams", "_sounds", "_fixeddir", "_missileidx", "_backcolor", "_scanstoreload", "_radaroffsound", "_gettargetsound", "_scansound", "_noammosound1", "_noammosound2", "_posrellaunch", "_mando_target", "_mando_contact", "_radarpresent", "_remotepresent", "_airpresent", "_vehiclespresent", "_createtrigger", "_maxscanrange", "_speedmax", "_maxrange", "_cruisealt", "_endurance", "_scanarch", "_mintargetalt", "_maxtargetalt", "_wait", "_targetpresent", "_mando_contact_present", "_currentcontact", "_currentcontactidx", "_scansleft", "_mccdisplay", "_ctrlcircle", "_inrng", "_trigger", "_refresh_state", "_continue", "_launchpos", "_list", "_endofair", "_endofmissiles", "_endofremote", "_contacts", "_contact", "_distance", "_contactstr1", "_contactstr2", "_index", "_image", "_los_log", "_los_ok", "_pos_contact", "_ratev", "_pos_asl", "_check_los", "_maxtaltasl","_posrelcontrol", "_firingrad", "_posl", "_mcc_pilon", "_ecm"];


_launcher       = _this select 0;
_targettypes    = _this select 1;
_scanrange      = _this select 2;
_scanfreq       = _this select 3;
_antimissile    = _this select 4;
_missileparams  = _this select 5;
_sounds         = _this select 6;
_fixeddir       = _this select 7;
_missileidx     = _this select 8;
_backcolor      = _this select 9;
_scanstoreload  = _this select 10;
_posrelcontrol  = _this select 11;

//;_scanstoreload  = 3

_radaroffsound  = _sounds select 1;
_gettargetsound = _sounds select 2;
_scansound      = _sounds select 3;
_noammosound1   = _sounds select 4;
_noammosound2   = _sounds select 5;

_posrellaunch  = _missileparams select 2;
if (count _posrellaunch  == 4) then
{
   _firingrad = _posrellaunch select 3;
   _posrellaunch  = [_posrellaunch  select 0, _posrellaunch select 1, _posrellaunch select 2];
}
else
{
   _firingrad = 0;
};

if ((_missileparams select 1) == "") then
{
   if ((typeName _missileidx) == "SCALAR") then
   {
      _missileparams set [1, "Bo_GBU12_LGB"];
   }
   else
   {
      _magazines = getArray (configFile>>"cfgWeapons" >> _missileidx >> "magazines");
      _ammo_class = getText (configFile>>"CfgMagazines" >> (_magazines select 0) >> "ammo");
      _missileparams set [1, _ammo_class];
   };
};


if (isNil "mandotarget_disp_on") then
{
   mandotarget_disp_on = false;
};
mandotarget_disp_on_old = mandotarget_disp_on;
mandotarget_disp_on = false;
3 cutText["", "PLAIN"];


if (damage _launcher > 0.5) exitWith 
{
   cutText["MCC system damaged", "PLAIN DOWN"];
         mandotarget_disp_on = mandotarget_disp_on_old;
         mandotarget_disp_on = true;
         if (!isNil "mando_last_onmapsclick") then
         {
            onMapSingleClick mando_last_onmapsclick;
         }
         else
         {
            onMapSingleClick "";
         };
};

_mando_target = objNull;
_mando_contact = objNull;


if (count _targettypes == 0) then
{
   _maxtaltasl = 40000;
}
else
{
   _maxtaltasl = 2;
};

_radarpresent = false;
if ("RADAR" in _targettypes) then
{
   _radarpresent = true;
   _maxtaltasl = 40000;
};

_remotepresent = false;
if ("REMOTE" in _targettypes) then
{
   _remotepresent = true;
   _maxtaltasl = 40000;
};

_airpresent = false;
if ("Air" in _targettypes) then
{
   _airpresent = true;
   _maxtaltasl = 40000;
};

_vehiclespresent = false;
if ("Vehicles" in _targettypes) then
{
   _maxtaltasl = 40000;
   _vehiclespresent = true;
};

if ("Ships" in _targettypes) then
{
   _vehiclespresent = true;
};

_createtrigger = false;
if (_airpresent || _vehiclespresent) then 
{
   _createtrigger = true;
};


_maxscanrange = _scanrange;


_speedmax  = _missileparams select 6;
_maxrange  = _missileparams select 10;
_cruisealt = _missileparams select 12;
_endurance = _missileparams select 17;
_scanarch  = _missileparams select 29;

_mintargetalt = -100;
_maxtargetalt = mando_minairalt;
if (_airpresent) then
{
   _maxtargetalt = 40000;
};

if ((count _targettypes==1) && _airpresent) then
{
   _mintargetalt=mando_minairalt;
};

Sleep 1;
_wait = 0;
_refreshcontacts   = false;
_targetpresent     = false;
_currentcontact    = "";
_currentcontactidx = -1;

_scansleft = 0;

if ((typeName _missileidx) == "SCALAR") then
{
   ctrlSetText [MCC_MISSILESLEFT,format["Weapons left: %1",_launcher getVariable format["mando_missilesleft%1", _missileidx]]];
}
else
{
   ctrlSetText [MCC_MISSILESLEFT, format["Weapons left: %1",_launcher ammo _missileidx]];
};

ctrlSetText [MCC_ACTIVERADAR,format["Weapon active seeker range: %1 m",_maxrange]];
ctrlSetText [MCC_ENDURANCE,format["Weapon endurance: %1 secs",_endurance]];
ctrlSetText [MCC_MAXSPEED,format["Weapon max speed: %1 m/s",_speedmax]];

if ((_missileparams select 11) == 2) then
{
   ctrlEnable [MCC_MODE0ALTE, false];
   ctrlSetText [MCC_MODE0ALTE, format["%1",0]];
}
else
{
   ctrlSetText [MCC_MODE0ALTE, format["%1",_cruisealt]];
};
ctrlSetText [MCC_AIMCIRCLE, mando_missile_path+"mcc\aimcircle.paa"];


if (!mando_missile_camera) then
{
   ctrlSetText [MCC_CAMERAONOFF,"Weapon Camera is OFF"];
}
else
{
   ctrlSetText [MCC_CAMERAONOFF,"Weapon Camera is ON"];
};

ctrlSetText [MCC_FRAME, format["Contacts (%1 m.)    Press F1 for help", _maxscanrange]];

_mccdisplay = findDisplay MCC_DLGMISSILECENTER;
if (count _backcolor == 4) then 
{
   (_mccdisplay displayCtrl MCC_BACKLEFT) ctrlSetBackgroundColor _backcolor;
   (_mccdisplay displayCtrl MCC_BACKRIGHT) ctrlSetBackgroundColor _backcolor;
};
_ctrlcircle = _mccdisplay displayCtrl MCC_AIMCIRCLE;
_inrng = _mccdisplay displayCtrl MCC_INRGN;

if (_createtrigger) then
{
   _trigger = createTrigger ["EmptyDetector", getPos _launcher];
   _trigger setTriggerActivation ["ANY", "PRESENT", false];
   _trigger setTriggerArea [_maxscanrange, _maxscanrange, 0, false];
   _trigger setTriggerType "NONE";
   _trigger setTriggerStatements ["this", "", ""];
   _trigger setTriggerTimeout [0, 0, 0, false ];

   if ((getPos _launcher select 2) < 10) then
   {
      mando_radar_on = _launcher;
      publicVariable "mando_radar_on";
   };
};

_los_log = "logic" createVehicleLocal [0,0,0];

_refresh_state = 0;
_continue = true;

_mcc_pilon = 1;

_log_dir = "logic" createVehicleLocal [0,0,0];

while {_continue} do
{
   _launchpos = _launcher modelToWorld _posrellaunch;


   if (_createtrigger) then
   {
      _trigger setPos getPos _launcher;
   };

   Sleep 0.5;
   _wait = _wait + 0.5;
   if (_wait > _scanfreq) then
   {
      _wait = 0;
      if ((typeName _missileidx) == "SCALAR") then
      {
         ctrlSetText [MCC_MISSILESLEFT,format["Missiles left: %1",(_launcher getVariable format["mando_missilesleft%1", _missileidx])]];
      }
      else
      {
         ctrlSetText [MCC_MISSILESLEFT, format["Weapons left: %1",_launcher ammo _missileidx]];
      };

      if (damage _launcher > 0.5) then
      {
         _continue = false;
      };
//      _currentcontact = ctrlText MCC_CONTACT;
      _refresh_state = _refresh_state + 1;

      if (_refresh_state > 5) then
      {
         _refresh_state = 0;
         if (((getPos _launcher select 2) < 10) && _createtrigger) then 
         {
            mando_radar_on = _launcher;
            publicVariable "mando_radar_on";
         };
      };
      _list = [];


      _log_dir setPos (_launcher modelToWorld [0,0,0]);
      _log_dir setDir (getDir _launcher);
      if (_createtrigger) then
      { 
         {
            if ((getPos _x select 2) > 3) then
            {
               if ((isEngineOn _x) && !(_x isKindOf "Man")) then 
               {
                  if (!((typeOf _x) in mando_missile_stealth)) then
                  {
                     if (_fixeddir >= 0) then
                     {
                        _posw = _log_dir worldToModel (getPos _x);
                        if ((_posw select 1) > 0) then
                        {
                           if (abs((_posw select 0) / (_posw select 1)) < 2) then
                           {
                              _list = _list + [_x];
                           };
                        };
                     }
                     else
                     {
                        _list = _list + [_x];
                     };
                  };
               }; 
            }
            else
            {
               if ((driver _x != _x) && ((count crew _x) > 0)) then 
               {
                  if (_fixeddir >= 0) then
                  {
                     _posw = _log_dir worldToModel (getPos _x);
                     if ((_posw select 1) > 0) then
                     {
                        if (abs((_posw select 0) / (_posw select 1)) < 2) then
                        {
                           _list = _list + [_x];
                        };
                     };
                  }
                  else
                  {
                     _list = _list + [_x];
                  };
               };
            };
         } forEach list _trigger;
      };
 
      if ((!_createtrigger)&&((mando_mccmark distance _launcher) <_maxscanrange)) then
      {
         _list = _list + [mando_mccmark];
      };

      _endofair = count _list;

      // Missiles in flight are added to the list
      if (_antimissile) then
      {
         {if ((_x distance _launcher)<_maxscanrange) then {_list = _list + [_x]}} forEach mando_detmissiles;
         _endofmissiles = count _list;
      }
      else
      {
         _endofmissiles = _endofair;
      };

      if (_remotepresent) then
      {
         if ((side player) == west) then
         {
            _list = _list + mando_remote_targets_w;
         }
         else
         {
            if ((side player) == east) then
            {
               _list = _list + mando_remote_targets_e;
            }
            else
            {
               if ((side player) == resistance) then
               {
                  _list = _list + mando_remote_targets_r;
               };
            };
         };
      };

      _endofremote = count _list;
      if (_radarpresent) then
      {
         {if ((getPos _x select 2) < 20) then {_list = _list + [_x]}} forEach mando_radars;
      };

      if (_scansound != "") then
      {
         _launcher say _scansound;
      };

      _scansleft = _scansleft - 1;
      if (_scansleft < 1) then
      {
         _scansleft = 0;
         ctrlEnable [MCC_FIREMISSILE, true];
         ctrlSetText [MCC_FIREMISSILE, "FIRE MISSILE"];
      };

      lbClear MCC_CONTACTLIST;
      _contacts = [];
      _targetpresent = false;
      _mando_contact_present = false;

      _check_los = true;
      if ((getPosASL _launcher select 2) < -1) then
      {
         _check_los = false;
      };

      if (count _list > 0) then
      {
         for [{_i = 0},{_i < count _list},{_i = _i + 1}] do
         {
            _contact = _list select _i;
            _pos_contact = getPos _contact;
      
            if (((_pos_contact select 2) > _mintargetalt) && 
                ((_pos_contact select 2) < _maxtargetalt) &&
                ((getPosASL _contact select 2) < _maxtaltasl) && 
                (_contact != _launcher) && (!isNull _contact)) then
            {
               if ( ((_i < _endofair) && ((driver _contact != _contact) || (_contact == mando_mccmark))) || 
                    (_i >= _endofair)) then
               {
                  _distance = _contact distance _launcher;
 
                  _los_ok = true;
                  if ((_i < _endofair) && 
                      (_contact != mando_mccmark) && _check_los) then
                  {
                     _los_log setPos (_launcher modelToWorld _posrelcontrol);


                     _pos_asl = getPosASL _los_log;
                     _ang = ((_pos_contact select 0)-(_launchpos select 0)) atan2 ((_pos_contact select 1)-(_launchpos select 1));                   
                     _ratev = ((getPosASL _contact select 2) - (_pos_asl select 2))/_distance;

                     for [{_j = 20},{(_j < ((_distance - 75) min mando_loscheck_range))&& _los_ok},{_j=_j + 50}] do
                     {
                        _los_log setPosASL [(_pos_asl select 0)+sin(_ang)*_j,(_pos_asl select 1)+cos(_ang)*_j, (_pos_asl select 2)+_ratev*_j];
                        if ((getPos _los_log select 2) < -1) then
                        {
                           _los_ok = false;                 
                        };
                     };
                     Sleep 0.005;
                  };

                  if (_los_ok) then
                  {
                     _contactstr1 = format["Contact%1", _i];
                     if ((_i < _endofair)&&(_contact != mando_mccmark)) then
                     {
                        _contactstr2 = format["Contact%1 (%2), %3m", _i, side _contact, _distance]; 
                     };

                     if (_contact == mando_mccmark) then
                     {
                        _contactstr2 = format["Contact%1 (MAP MARK), %3m", _i, side _contact, _distance];
                     };
   
                     if ((_i > (_endofair - 1))&&(_i < _endofmissiles)) then
                     {
                        _contactstr2 = format["Missile, %1m", _distance];
                     };
   
                     if ((_i > (_endofmissiles - 1))&&(_i < (_endofremote))) then
                     {
                        _contactstr2 = format["Remote target, %1m", _distance]; 
                     };

                     if (_i > (_endofremote - 1)) then
                     {
                        _contactstr2 = format["Active surface Radar, %1m", _distance];
                     };

                     _index = lbAdd [MCC_CONTACTLIST, _contactstr2];
        
                     lbSetData [MCC_CONTACTLIST, _index, _contactstr1];
                     _image = mando_missile_path+"mcc\inertial.JPG";
                     if (_distance < _maxrange) then
                     {
                        _image = mando_missile_path+"mcc\active.JPG";
                     };
                     lbSetPicture [MCC_CONTACTLIST, _index, _image];
                     _contacts = _contacts + [_contact];


                     if (_contact == _mando_target) then
                     {
                        _targetpresent = true;
                     };
  
                     if (_contact == _mando_contact) then
                     {
                        _mando_contact_present = true;
                     };
                  };
               };
            };
/*
            else
            {
               titleText[format["NO PASA: %1, %2, %3, %4\n%5 %6 %7", (_pos_contact select 2),(getPosASL _contact select 2),_contact,typeOf _contact,_mintargetalt,_maxtargetalt,_maxtaltasl], "PLAIN"];
            };
*/
         };      
      };

      if (!_targetpresent) then
      {
         _mando_target = objNull;
         _launcher setVariable ["mando_target", objNull];
         _launcher setVariable ["current_targetmcc", objNull, true];
         _ctrlcircle ctrlSetTextColor [0, 0.5, 0, 0.5];
      };

      if (!_mando_contact_present) then
      {
         _mando_contact = objNull;
         _launcher setVariable ["mando_contact", _mando_contact];
         ctrlSetText [MCC_CONTACT,""];
      };
   };

   if (mando_getcontact) then
   {
      _currentcontactidx = lbCurSel MCC_CONTACTLIST;
      _currentcontact = lbData [MCC_CONTACTLIST, _currentcontactidx];
      ctrlSetText [MCC_CONTACT,_currentcontact];

      if (_currentcontact != "") then
      {
         _mando_contact = (_contacts select _currentcontactidx);
         _launcher setVariable ["mando_contact", _mando_contact];
      }
      else
      {
        _mando_contact = objNull;
        _launcher setVariable ["mando_contact", _mando_contact];
      };
      mando_getcontact = false;
   };


   if (mando_gettarget && !isNull _mando_contact) then
   {
      mando_gettarget = false;

      _mando_target = _mando_contact;
      _launcher setVariable ["mando_target",_mando_target];
      _launcher setVariable [ "current_targetmcc", _mando_target, true];
      playSound _gettargetsound;

      mando_lockedon= _mando_target;
      publicVariable "mando_lockedon";
   };



   if (!isNull _mando_target) then
   {
      ctrlShow [MCC_FIREMISSILE, true];

      _distanceini = _mando_target distance _launcher;
      _postini = getPos _mando_target;
      _ang = ((_launchpos select 0)-(_postini select 0)) atan2 ((_launchpos select 1)-(_postini select 1));
      if (_ang < 0) then
      {
         _ang = 360 + _ang;
      };

      _angfire = _ang-180;

      _vt = (speed _mando_target) / 3.6;
      _vr = _speedmax;

      _dirt = getDir _mando_target;
      _dif = abs(_ang - _dirt);
      if (_dif > 180) then
      {
         _dif = 360 - _dif;
      };

      // Now we get the angle deviation if missile turns 2 degrees to the right
      _dir1 = _dirt + 2;
      if (_dir1 > 360) then
      {
         _dir1 = _dir1 - 360;
      };
      _dif1 = abs(_ang - _dir1);
      if (_dif1 > 180) then
      {
         _dif1 = 360 - _dif1;
      };

      // Now we get the angle deviation if missile turns 2 degrees to the left
      _dir2 = _dirt - 2;
      if (_dir2 < 0) then
      {
         _dir2 = 360 - _dir2;
      };
      _dif2 = abs(_ang - _dir2);
      if (_dif2 > 180) then
      {
         _dif2 = 360 - _dif2;
      };

      // The smaller deviation wins (left or right)
      _sig = 1;
      if (_dif2 < _dif1) then
      {
         _sig = -1;
      };

      _angi1 = asin((_vt/_vr)*sin(_dif));
      _angi = (_ang + 180) + _sig*_angi1;

      // Time to impact
      _tti = _distanceini / ((_vt*cos(_dif)+_vr*cos(_angi1))+0.0001);
      "mk_ipoint" setMarkerPosLocal [(_launchpos select 0)+sin(_angi)*_vr*_tti,(_launchpos select 1)+cos(_angi)*_vr*_tti, 0];
      _tti = _tti + 3;

      ctrlSetText [MCC_TARGET,format["%1",_mando_target]];
      ctrlSetText [MCC_DISTANCE,format["Distance: %1 m",_distanceini]];
      ctrlSetText [MCC_TTI,format["Time To Impact: %1 Secs", _tti - (_tti mod 1)]];
      ctrlSetText [MCC_ASLT,format["ASL Alt: %1 m",(getPosASL _mando_target select 2) - ((getPosASL _mando_target select 2) mod 1)]];
      ctrlSetText [MCC_SPEEDT,format["Speed: %1 m/s",_vt - (_vt mod 1)]];
      _type = "----";
      if (_distanceini < 2000) then
      {
         _type = typeOf _mando_target;
      };
      ctrlSetText [MCC_TYPET,format["Type: %1",_type]];
      ctrlSetText [MCC_DIRT,format["Dir: %1 deg",_dirt - (_dirt mod 1)]];

      _cruisealt = parseNumber ctrlText MCC_MODE0ALTE;


      if (_tti < _endurance) then 
      {
         _inrng ctrlSetText "IN RANGE"
      }
      else
      {
         _inrng ctrlSetText ""
      };

      _ecm = _mando_target getVariable "mando_ecm_on";
      if (isNil "_ecm") then
      {
         _mando_target setVariable ["mando_ecm_on", false];
         _ecm = false;
      };


      if (_fixeddir < 0) then
      {
         if (_ecm) then
         {
            _ctrlcircle ctrlSetTextColor [0,0.75,1,0.9];
         }
         else
         {
            _ctrlcircle ctrlSetTextColor [0, 1, 0, 1];
         };
         ctrlSetText [MCC_ANGDT,"Ang: N/A"];
      }
      else
      {
         _dir = getDir _launcher;
         _ang = ((_postini select 0)-(_launchpos select 0)) atan2 ((_postini select 1)-(_launchpos select 1));
         _difh = (_ang - ((_dir + _fixeddir) mod 360));
         if (_difh < 0) then {_difh = 360 + _difh;};
         if (_difh > 180) then {_difh = _difh - 360;};

         if (abs(_difh) < _scanarch/2) then 
         {
            if (_ecm) then
            {
               _ctrlcircle ctrlSetTextColor [0,0.75,1,0.9];
            }
            else
            {
               _ctrlcircle ctrlSetTextColor [0, 1, 0, 1];
            };
         } 
         else
         {
            if (_ecm) then
            {
               _ctrlcircle ctrlSetTextColor [0,0.37,0.5,0.9];
            }
            else
            {
               _ctrlcircle ctrlSetTextColor [0, 0.5, 0, 0.5];
            };

         };
         ctrlSetText [MCC_ANGDT,format["Ang: %1 deg",_difh - (_difh mod 1)]];
      };



      if (mando_firemissile) then
      {
         mando_firemissile=false;
         if ((typeName _missileidx) == "SCALAR") then 
         {
            if ((_launcher getVariable format["mando_missilesleft%1", _missileidx]) > 0) then
            {
               _launcher setVariable [format["mando_missilesleft%1", _missileidx],(_launcher getVariable format["mando_missilesleft%1", _missileidx])-1];
               ctrlSetText [MCC_MISSILESLEFT,format["Weapons left: %1",(_launcher getVariable format["mando_missilesleft%1", _missileidx])]];

               if ((_launcher getVariable format["mando_missilesleft%1", _missileidx])==0) then
               {
                  _launcher say _noammosound1;
                  _launcher say _noammosound2;
               };

               _cruisealt = parseNumber ctrlText MCC_MODE0ALTE;
 
               _missileparams set [0,_launcher];

               if (abs(_missileparams select 4) < 90) then
               {
                  _angi = sin(_missileparams select 4);
               }
               else
               {
                  _angi = ((_launcher worldToModel _postini) select 2) / _distanceini;
               };
               _posl = [_mcc_pilon*(_posrellaunch select 0)+sin(_angfire - (getDir _launcher))*_firingrad, (_posrellaunch select 1)+cos(_angfire - (getDir _launcher))*_firingrad,(_posrellaunch select 2)+_angi*_firingrad];

               _missileparams set [2,_posl];
//            _missileparams set [2,_posrellaunch];

               _missileparams set [3,_angfire];
               if (_fixeddir >= 0) then
               {
                  _missileparams set [3,(getDir _launcher)+_fixeddir];
               };

               _missileparams set [8,_mando_target];
               _missileparams set [12,_cruisealt];
               _missileparams set [23,true];


               _mcc_pilon = -_mcc_pilon;
               _missileparams execVM mando_missile_path+"mando_missile.sqf";

               if ((getPos _launcher select 2) > 2) then
               {
                  _posrellaunch set [0, -(_posrellaunch select 0)];
                  _missileparams set [2, _posrellaunch];
               };
/*
               if (mando_missile_camera && !mando_mccpredicam) then
               {
                  [] spawn {
                     Sleep 0.1;
                     waitUntil {!isNull mando_missile};
                     [mando_missile, 1, 180, 0, 300, false]execVM mando_missile_path+"mcc\mando_mccpredicam.sqf";
                  };
   
               };
*/
               ctrlEnable [MCC_FIREMISSILE, false];
               ctrlSetText [MCC_FIREMISSILE, "Loading Missile"];
               _scansleft = _scanstoreload;
            };

         }
         else
         {
         // Weapon name (STRING)
            if ((_launcher ammo _missileidx) > 0) then
            {
               _cruisealt = parseNumber ctrlText MCC_MODE0ALTE;
 
               _firer1 = objNull;
               _firer2 = objNull; 
               _widx = [_launcher, _missileidx] call mando_weaponindex;
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

               if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
               {
                  call compile format["_handle = (vehicle player) fireAtTarget [objNull, '%1']", _missileidx];
               }
               else
               {
                  _launcher action ["useWeapon",_launcher, _firer1, _widx];
               };

               _mis = objNull;
               _ammo = _launcher ammo _weapon;

               _mis = (getPos _launcher) nearestObject "MissileBase";
               if (isNull _mis) then
               {
                  _mis = (getPos _launcher) nearestObject "LaserBombCore";
                  if (isNull _mis) then
                  {
                     _mis = (getPos _launcher) nearestObject "BombCore";
                  };
               };

               if (isNull _mis) then
               {
                  if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
                  {
                     call compile format["_handle = (vehicle player) fireAtTarget [objNull, '%1']", _missileidx];
                  }
                  else
                  {
                     _launcher action ["useWeapon", _launcher, _firer2, _widx];
                  };
                  _mis = (getPos _launcher) nearestObject "MissileBase";
                  if (isNull _mis) then
                  {
                     _mis = (getPos _launcher) nearestObject "LaserBombCore";
                     if (isNull _mis) then
                     {
                        _mis = (getPos _launcher) nearestObject "BombCore";
                     };
                  };
               };

               ctrlSetText [MCC_MISSILESLEFT, format["Weapons left: %1",_launcher ammo _missileidx]];
               if ((_launcher ammo _missileidx)==0) then
               {
                  _launcher say _noammosound1;
                  _launcher say _noammosound2;
               };

               Sleep 0.1;

               if (!isNull _mis) then
               {
                  _missilebody = typeOf _mis;
                  _speedini = (((speed _mis)/3.6 - (speed _launcher)/3.6) + (_missileparams select 5)) min (_missileparams select 6);

                  _pos = _launcher worldToModel (getPos _mis);
                  if ((getPos _launcher select 2) > 10) then
                  {
                     if ((_pos select 2) > -2) then
                     {
                        _pos set [2, ((_missileparams select 2) select 2)];
                     };
                  };

                  _dir = getDir _mis;
//                  _vangle        = 0;
                  _vangle        = asin (vectorDir _mis select 2) - asin(vectorDir _launcher select 2);
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

  
                  _missparams = [];
                  _missparams = _missparams + _missileparams;

                  _missparams set [0, _launcher];
                  _missparams set [1, _missilebody];
                  _missparams set [2, _pos];
                  _missparams set [3, _dir];
                  _missparams set [4, _vangle];
                  _missparams set [5, _speedini];
                  _missparams set [8, _mando_target];
                  _missparams set [12,_cruisealt];
                  _missparams set [23,true];
                  _missparams execVM mando_missile_path+"mando_missile.sqf";
               }; 

/*
               if (mando_missile_camera && !mando_mccpredicam) then
               {
                  [] spawn {
                     Sleep 0.1;
                     waitUntil {!isNull mando_missile};
                     [mando_missile, 1, 180, 0, 300, false]execVM mando_missile_path+"mcc\mando_mccpredicam.sqf";
                  };
   
               };
*/
               ctrlEnable [MCC_FIREMISSILE, false];
               ctrlSetText [MCC_FIREMISSILE, "Loading Missile"];
               _scansleft = _scanstoreload;
            };
         };
      };

      if (_ecm) then
      {
         if ((random 100) > 95) then
         {
            _mando_target = objNull;
         };
      };


   }
   else
   {
      ctrlShow [MCC_FIREMISSILE, false];
      ctrlSetText [MCC_TARGET,"----"];
      ctrlSetText [MCC_DISTANCE,"Distance: ---- m"];
      ctrlSetText [MCC_TTI,"Time To Impact: ---- Secs"];
      ctrlSetText [MCC_ASLT,"ASL Alt: ---- m"];
      ctrlSetText [MCC_SPEEDT,"Speed: ---- m/s"];
      ctrlSetText [MCC_TYPET,"Type: ----"];
      ctrlSetText [MCC_DIRT,"Dir: ---- deg"];
      ctrlSetText [MCC_ANGDT,"Ang: ---- deg"];
      _ctrlcircle ctrlSetTextColor [0, 0.5, 0, 0.5];
      _inrng ctrlSetText "";
   };



   if ((!ctrlVisible MCC_MCC_FRAME)||(damage _launcher > 0.5)) then
   {
      _continue = false;
   };
};

if ((getPos _launcher select 2) < 10) then
{
   mando_radar_off = _launcher;
   publicVariable "mando_radar_off";
};


mando_map=0;
mando_missile_camera=false;
mando_missile_camera_zoom = 1.0;
_launcher setVariable ["mando_contact", objNull];
_launcher setVariable ["mando_mccstate", 0];
if (_radaroffsound != "") then
{
   _launcher say _radaroffsound;
};

if ((typeName _missileidx) == "SCALAR") then
{
   _launcher setVariable [format["mando_missilesleft%1", _missileidx], (_launcher getVariable format["mando_missilesleft%1", _missileidx]), true];
};
Sleep 1;

_mccdisplay closeDisplay 0;

if (!isNil "mando_last_onmapsclick") then
{
   onMapSingleClick mando_last_onmapsclick;
}
else
{
   onMapSingleClick "";
};

if (_createtrigger) then
{
   deleteVehicle _trigger;
};
// deleteVehicle mando_mccmark;
deleteVehicle _los_log;
deleteVehicle _log_dir;

_launcher setVariable ["current_targetmcc", objNull, true];

mandotarget_disp_on = mandotarget_disp_on_old;
mandotarget_disp_on = true;
