/* mando scripted missile
 mando_missile.sqf v2.41
 Jan 2009 Mandoble
 
 Purpose: Creates an scripted guided missile able to pursue and destroy assigned target.
 
 Arguments:
 Launcher, unit that fires the missile
 Class of missile's object (anything that accepts setVectorDir, setVectorUp and setVelocity commands)
 Initial firing position (if launcher is not null, relative to launcher, else, absolute position)
 Initial horizontal direction in degrees (usualy, the direction of the launcher)
 Initial vertical angle (-89 to 89). If out of limits, the angle will be calculated to point at target.
 Initial speed a launch time in m/s (launcher speed will be added to this)
 Speed to keep constant after initial acceleration in m/s
 Acceleration: value in m/s^2 or array with initial and final acceleration (final achieved after first second). Or array with initial acceleration for the first second and substained acceleration for rest of the flight
 Real target object (you may also fire against gamelogics)
 Range to target to explode in meters
 Missile inboard seeker range in meters (to track targets when missile is working in mode 2). 
 Initial operation mode: 0, 1 or 2
 0 - The missile climbs/dives until cruise altitude over target is reached, then it switches to mode 1.
 1 - The missile flies towards a pre-calculated position from where it may switch on its own seeker. 
 2 - Active pursuing. The target must be inside missile's seeker range.

 Average cruise altitude in meters, used if initial operation mode is 0 or 1 (inertial launches).
 SQF Script to create the explosion. Receives last missile position and target as arguments. "" if no explosion is required.
 SQF Script to create missile smoke trail. Receives missile object as argument. "" if no smoke.
 Missile sound resource name, "" if none.
 Missile sound duration in seconds (the duration of the indicated sound resource).
 Missile maximum endurance in seconds (after this time, the missile will be unpowered, while not unguided)
 Terrain avoidance in mode 1 (true/false). Terrain avoidance is off in modes 0 and 2.
 Frequency of mid-course corrections in seconds while in mode 1, any number above endurance for no corrections.
    NOTE: This is just to simulate launcher mid-course corrections while flying in inertial mode, like current AIM120 AMRAAM command mode.
 Time between creating the missile and switching on its engine in seconds (the missile will be in free fall during this period)
 Time between creating the missile and starting any guidance (usually use 0 or very small values). During this period the missile will keep flying straight in its original bearing and elevation.
 Detectable? true/false. Detectable missiles may be intercepted by other mando missiles and detected by MCCs.
 Debug data for missile dialog info (true/false)
 SQF script to be executed at launch time to add FX, receives missile object as single argument, "" if none.
 Horizontal agility level (0 min, 10 max, 3 is normal)
 Vertical agility level (0 min, 10 max, 3 is normal)
 Accuracy (0.001 min, 1 max)
 Interception mode true/false in active mode. true = interception course, false = collision course.
 Missile's seeker horizontal scan arc in degrees / 2 (65 is normal)
 Missile's seeker vertical scan arc in degrees / 2 (35 is normal)
 Z-offset in m above or below target (negative value), where the missile will point at
 Countermeasures extent, default value is 25. If distance between target and missile plus this value is larger than distance between missile and countermeasures, the missile will follow the countermeasures.
*/

private ["_launcher", "_type", "_posini", "_posiniasl", "_dirini", "_angvini", "_speedini", "_speedmax", "_accel","_accelfact", "_rtarget", "_proximity", "_radarrgn", "_modeini", "_cruisealt", "_boomscript", "_smokescript", "_sound", "_sounddur", "_endurance", "_terrain", "_corrections", "_droptime", "_controltime", "_detectable", "_debug", "_launchscript", "_hagility", "_vagility", "_accuracy", "_intercept", "_scanarch", "_scanarcv", "_velt", "_spdt", "_post", "_ang", "_vt", "_vr", "_dirt", "_dif", "_dir1", "_dif1", "_dir2", "_dif2", "_sig", "_ang1", "_dirmode0", "_tti", "_altmasl", "_alttasl", "_deltaalt", "_angmode0", "_radmode0", "_postmode0", "_postmode1", "_follow", "_dir", "_distance", "_angv", "_difang", "_difabs", "_climbdir", "_old_climbdir", "_turn", "_old_turn", "_emergency", "_dmg", "_dist","_distr","_distold", "_array", "_numitems", "_i", "_item", "_finish", "_missilelnum", "_missileid", "_chaff", "_chaffrgn", "_mis", "_maxclimbup", "_maxclimbdown", "_maxacqhor", "_maxacqver", "_vel", "_speed", "_mode", "_sealeveloffset", "_delay", "_hdegreessec01", "_vdegreessec01", "_hdegreessec2", "_vdegreessec2", "_deltah", "_deltav", "_log", "_ltarget", "_ground", "_target", "_posmini", "_posm", "_posmg","_postini", "_distanceini", "_correctionstime" , "_controltimeini", "_endurancetimeini","_timeleft", "_soundtimeini", "_side","_vz", "_vh", "_vx", "_vy", "_uz", "_ur", "_ux", "_uy", "_firstaim", "_dstchaff", "_deltatime", "_timeold", "_chaffdelta", "_event", "_rtargetlog", "_var", "_flares"];


_launcher     = _this select 0;
_type         = _this select 1;
_posini       = _this select 2;
_dirini       = _this select 3;
_angvini      = _this select 4;
_speedini     = _this select 5;
_speedmax     = _this select 6;
_accel        = _this select 7;
_rtarget      = _this select 8;
_proximity    = _this select 9;
_radarrgn     = _this select 10;
_modeini      = _this select 11;
_cruisealt    = _this select 12;
_boomscript   = _this select 13;
_smokescript  = _this select 14;
_sound        = _this select 15;
_sounddur     = _this select 16;
_endurance    = _this select 17;
_terrain      = _this select 18;
_corrections  = _this select 19;
_droptime     = _this select 20;
_controltime  = _this select 21;
_detectable   = _this select 22;
_debug        = _this select 23;
_launchscript = _this select 24;
_hagility     = _this select 25;
_vagility     = _this select 26;
_accuracy     = _this select 27;
_intercept    = _this select 28;
_scanarch     = _this select 29;
_scanarcv     = _this select 30;


if (count _this > 31) then
{
   _sealeveloffset = _this select 31;
}
else
{
   _sealeveloffset = 1;
};

if (count _this > 32) then
{
   _chaffdelta = _this select 32;
}
else
{
   _chaffdelta = mando_minchaffdist;
};

if (typename _accel == "ARRAY") then
{
   _accelfact = _accel select 0;
}
else
{
   _accelfact = _accel;
};


_velt = [0,0,0];
_spdt = 0.0;

_post = [0,0,0];
_ang = 0.0;
_vt = 0.0;
_vr = 0.0;
_dirt = 0.0;
_dif = 0.0;
_dir1 = 0.0;
_dif1 = 0.0;
_dir2 = 0.0;
_dif2 = 0.0;
_sig = 0;
_ang1 = 0.0;
_dirmode0 = 0;
_tti = 0.0;
_altmasl = 0.0;
_deltaalt = 0.0;
_angmode0 = 0;
_radmode0 = 0;
_postmode0 = [0,0,0];
_postmode1 = [0,0,0];
_follow = false;
_dir = 0.0;
_distance = 0.0;
_angv = 0.0;
_difang = 0.0;
_difabs = 0.0;
_emergency = false;
_vz = 0.0;
_vh = 0.0;
_vx = 0.0;
_dmg = 0.0;
_dist = 0.0;
_distold = 0.0;
_array = [];
_numitems = 0;
_i = 0;
_item = [0, objNull, objNull];
_finish = false;
_missilelnum = 0;
_missileid = [0, objNull, objNull];
_chaff = objNull;
_chaffrgn = 1000;



if (!isNull _launcher) then
{
   _posini = _launcher modelToWorld _posini;
};

_rtargetlog = "logic" createVehicleLocal [0,0,0];
if (isNull _rtarget) then
{
   _rtargetlog setPos[(_posini select 0)+sin(_dirini)*2000,(_posini select 1)+cos(_dirini)*2000, (_posini select 2)+sin(_angvini)*2000];
   _rtarget = _rtargetlog;
};


_log = "Logic" createVehicleLocal [0,0,0];
_log setPos _posini;
_posiniasl = getPosASL _log;

_mis = _type createVehicle [0,0,50];
_mis setDir _dirini;
_distanceini = _rtarget distance _log;


if (!isNull _launcher) then
{
   _vel = velocity _launcher;
   if (_launcher isKindOf "Air") then
   {
      if (_droptime > 0) then
      {
         _mis setVectorUp vectorUp _launcher;
      };
   };

   if (_angvini <= 89) then
   {
      _angvini = _angvini + asin(vectorDir _launcher select 2); 
      if (_angvini > 89) then
      {
         _angvini = 89;
      }
      else
      {
         if (_angvini < -45) then
         {
            if (isPlayer driver _launcher) then
            {
               _angvini = -45;
            }
            else
            {
               _angvini = -35;
            };
         };
      };
   }
   else
   {
      _vel = [0,0,0];
      _altmasl = _posiniasl select 2;
      _alttasl = getPosASL _rtarget select 2;
      _angvini = asin((_alttasl - _altmasl)/_distanceini);
   };

   [_mis, _dirini, _angvini] call mando_setVDirAndUp;
   _var = _launcher getVariable "mando_mis_extrah";
   if (!isNil "_var") then
   {
      _mis setPosASL [_posiniasl select 0, _posiniasl select 1, (_posiniasl select 2)-_var];
   }
   else
   {
      _mis setPosASL _posiniasl;
   };



   _mis setVelocity velocity _launcher;
}
else
{
   [_mis, _dirini, _angvini] call mando_setVDirAndUp;
   _mis setPosASL _posiniasl;
};

// Aplicar aquí velocidad inicial, de haberla Y AÑADIR VELOCIDAD DE LANZADOR
_mis setVelocity [(_vel select 0)+(vectorDir _mis select 0)*_speedini, (_vel select 1)+(vectorDir _mis select 1)*_speedini,(_vel select 2)+(vectorDir _mis select 2)*_speedini];


if (!isNull _launcher) then
{
   _launcher setVariable["mando_missile_fired", _mis];
   _launcher spawn
   {
      Sleep 1;
      _this setVariable ["mando_missile_fired", objNull];
   };
};


if (_launchscript != "") then 
{  
   _res = [_mis]execVM _launchscript;
   mando_launch_mis = _mis;
   mando_launch_script = _launchscript;
   mando_launch_req = true;
   publicVariable "mando_launch_mis";publicVariable "mando_launch_script";publicVariable "mando_launch_req";
};


_side = side _rtarget;


if (_detectable) then
{
   mando_detmissileowner = _launcher;
   mando_detmissile = _mis;
   mando_detmissilereq = true;
   publicVariable "mando_detmissileowner";publicVariable "mando_detmissile";publicVariable "mando_detmissilereq";
};


if (_debug) then 
{
   mando_missile = _mis;
};

sleep _droptime;


_maxclimbup = 89;
_maxclimbdown = -89;
_maxacqhor = _scanarch;
_maxacqver = _scanarcv;

_vel = velocity _mis;
//_speed = _speedini + sqrt((_vel select 0)^2 + (_vel select 1)^2);
_speed = sqrt((_vel select 0)^2 + (_vel select 1)^2 + (_vel select 2)^2);
_mode  = _modeini;

//_delay = 0.002;
_delay = 0.001;


_hdegreessec01 = _hagility * 1.0;
_hdegreessec2 = _hagility;
_vdegreessec01 = _vagility * 1.0;
_vdegreessec2 = _vagility;


_deltah = 0.0;
_deltav = 0.0;


_ltarget = "logic" createVehicleLocal [0,0,0];
_ground = "logic" createVehicleLocal [0,0,0];


_distold = 999999;


_target      = _rtarget;
_posmini     = getPos _mis;
_posm        = _posmini;
_pomsg       = _posmini;
_postini     = getPos _target;

_turn = 0;
_old_turn = -1;

_dir = _dirini;
_climbdir = 0;
_old_climbdir = -1;

_correctionstime  = dayTime * 3600;
_controltimeini   = dayTime * 3600;
_endurancetimeini = dayTime * 3600;
_timeleft         = _endurance;
_soundtimeini     = dayTime * 3600;

if (_distanceini < _radarrgn) then {_mode = 2;};


if (_mode != 2) then
{
   _ang = ((_posmini select 0)-(_postini select 0)) atan2 ((_posmini select 1)-(_postini select 1));
   if (_ang < 0) then {_ang = 360 + _ang;};

   _vt = (speed _rtarget) / 3.6;
   _vr = _speedmax;

   _dirt = getDir _rtarget;

   _dif = abs(_ang - _dirt);
   if (_dif > 180) then {_dif = 360 - _dif;};

   _dir1 = _dirt + 2;
   if (_dir1 > 360) then {_dir1 = _dir1 - 360;};

   _dif1 = abs(_ang - _dir1);
   if (_dif1 > 180) then {_dif1 = 360 - _dif1;};

   _dir2 = _dirt - 2;
   if (_dir2 < 0) then {_dir2 = 360 - _dir2;};

   _dif2 = abs(_ang - _dir2);
   if (_dif2 > 180) then {_dif2 = 360 - _dif2;};

   _sig = 1;
   if (_dif2 < _dif1) then {_sig = -1;};

   _angi1 = asin((_vt/_vr)*sin(_dif));
   _dirmode0 = (_ang + 180) + _sig*_angi1;

   _tti = _distanceini / ((_vt*cos(_dif)+_vr*cos(_angi1))+0.0001);


   _altmasl = getPosASL _mis select 2;
   _deltaalt = (getPosASL _rtarget select 2) + _cruisealt - _altmasl;

   _angmode0 = _angvini;
   _radmode0 = abs(_deltaalt);

   if (_deltaalt < 0) then 
   {
      _radmode0 = ((abs(_deltaalt)*6.0) max 500) min 2000;
   };

   _postmode0 = [(_posmini select 0)+sin(_dirmode0)*_radmode0, (_posmini select 1)+cos(_dirmode0)*_radmode0, 0];
   _ltarget setPos _postmode0;
//   _postmode0 = [_postmode0 select 0, _postmode0 select 1, _cruisealt - (getPosASL _ltarget select 2)];

   _postmode0 = [_postmode0 select 0, _postmode0 select 1, _cruisealt + (getPosASL _rtarget select 2)];

   if (abs((_posmini select 2) - (getPosASL _rtarget select 2)) < (_rtarget distance _mis)/2) then
   {
      _postmode1 = [(_posmini select 0)+sin(_dirmode0)*(((_speedmax*_tti)-(_radarrgn/1.2)) max 200),(_posmini select 1)+cos(_dirmode0)*(((_speedmax*_tti)-(_radarrgn/1.2)) max 100), 0];
   }
   else
   {
      _ltarget setPosASL [_posmini select 0,_posmini select 1,getPosASL _rtarget select 2];

      _postmode1 = [(_posmini select 0)+sin(_dirmode0)*(((_ltarget distance _rtarget)-(_radarrgn/1.2)) max 100),(_posmini select 1)+cos(_dirmode0)*(((_ltarget distance _rtarget)-(_radarrgn/1.2)) max 200), 0];
   };

   if (_terrain) then
   {
      _ltarget setPos _postmode1;
      _postmode1 = [_postmode1 select 0, _postmode1 select 1, _cruisealt + (getPosASL _rtarget select 2)];
   }
   else
   {
      _ltarget setPos _postmode1;
      _postmode1 = [_postmode1 select 0, _postmode1 select 1, _cruisealt + (getPosASL _rtarget select 2)];
   };

   if ((_postmode1 distance _rtarget) > (_postmode0 distance _rtarget)) then
   {
      _postmode1 = _postmode0;
   };
};

_proximitytemp = _proximity;

if (_mode == 0) then
{
   _ltarget setPosASL _postmode0;
   _log setPosASL _postmode0;
   _target = _ltarget;
//   _angvini = _angmode0;
   _proximitytemp = 300;
};


if (_mode == 1) then 
{
   _ltarget setPosASL _postmode1;
   _target = _ltarget;
   _proximitytemp = 50;
};

/*
if (abs(_angvini) > 89) then 
{
   _altmasl = getPosASL _mis select 2;
   _alttasl = getPosASL _target select 2;
   _angvini = asin((_alttasl - _altmasl)/_distanceini);
};
*/


// Poner el que tenga el misil en ese momento, NO _angvini
//_climb = _angvini;
_climb = asin((vectorDir _mis) select 2);


if (_sound != "") then {_mis say3D _sound;};

if (_smokescript != "") then 
{
   _res = [_mis]execVM _smokescript;
   mando_missilesmoke_mis = _mis;
   mando_missilesmoke_script = _smokescript;
   mando_missilesmoke = true;
   publicVariable "mando_missilesmoke_mis";publicVariable "mando_missilesmoke_script";publicVariable "mando_missilesmoke";
};


/* Se lanza tras crear el misil
if (_launchscript != "") then 
{  
   _res = [_mis]execVM _launchscript;
   mando_launch_mis = _mis;
   mando_launch_script = _launchscript;
   mando_launch_req = true;
   publicVariable "mando_launch_mis";publicVariable "mando_launch_script";publicVariable "mando_launch_req";
};
*/

if ((count crew _rtarget) > 0) then
{
   mando_missileincomming = _mis;
   mando_missiletarget = _rtarget;
   mando_missilerequest = true;

   publicVariable "mando_missileincomming";publicVariable "mando_missiletarget";publicVariable "mando_missilerequest";

   _rtarget setVariable ["mando_missileincomming", _mis, true];
};

[_launcher, _mis, _boomscript, _side, _rtarget, 
_proximity] spawn
{
	private["_launcher","_mis", "_boomscript", "_side", "_rtarget", "_proximity", "_posmg"];
	_launcher = _this select 0;
	_mis = _this select 1;
	_boomscript = _this select 2;
	_side = _this select 3;
	_rtarget = _this select 4;
	_proximity = _this select 5;

	while {alive _mis} do
	{
		_posmg = getPos _mis;
		
		if ((_mis distance _rtarget) < _proximity) then
		{
			deleteVehicle _mis;
		};

		Sleep 0.001;
	};

	if (_boomscript != "") then 
	{ 
		mando_deton_x = _posmg select 0;
		mando_deton_y = _posmg select 1;
		mando_deton_z = _posmg select 2;
		mando_deton_target = _rtarget;
		mando_deton_side = _side;
		mando_deton_launcher = _launcher;
		mando_deton_script = _boomscript;
		mando_deton_req = true;

        publicVariable "mando_deton_x";publicVariable "mando_deton_y";publicVariable "mando_deton_z";publicVariable "mando_deton_target";publicVariable "mando_deton_side";publicVariable "mando_deton_launcher";publicVariable "mando_deton_script";publicVariable "mando_deton_req";
	};
};

_firstaim = true;
_follow = true;
_timeold = time;
_chaff = objNull;
_dist = _target distance _mis;
while {!_finish} do
{
   _follow = true;
   _deltatime = (time-_timeold) max 0.001;
   _timeold = time;

   if (_mode == 2) then
   {
      _target = _rtarget;
      _chaff = objNull;
      _var = _rtarget getVariable "mando_alive_flares";
      if (!isNil "_var") then
      {
         _flares = _var; 
      }
      else
      {
         _flares = [];
      };

      {
         if ((!isNull _x) && (isNull _chaff)) then 
         {
            _dstchaff = _mis distance _x;
            if (_dstchaff < _chaffrgn) then
            {
               if (_dstchaff < ((_mis distance _rtarget)+_chaffdelta)) then
               {
                  if (((_mis worldToModel (getPos _x)) select 1) > 0) then
                  {
                     _chaff = _x;
                     _target = _chaff; 
                  };
               };
            };
         };
      } forEach _flares;

      if (_dist > (_radarrgn+500)) then
      {
         _follow = false;
      };
   };


   _dir = getDir _mis;
   if ((_speed + _accelfact*_deltatime) < _speedmax) then 
   {
      _speed = _speed + ((_accelfact*_deltatime) min 10);
   }
   else
   {
      _speed = _speed - ((10*_deltatime) min 10);
//      _speed = _speedmax;
   };


   if (!isNull _mis) then 
   {
      _posm = getPosASL _mis;
      _posmg = getPos _mis;
   };

   _distance = _log distance _mis;
   if (_distance < 1000) then
   {
      if (count crew _rtarget == 0) then
      {
         _intercept = false;
      };
   };


   if (!isNull _target) then 
   {
      if (_firstaim || ((_accuracy - (random 1)) > 0) || (_mode != 2)) then
      {               
         _post = getPosASL _target;

         if (_intercept) then
         {
            if (!isNull _rtarget) then
            {
               _tti = ((_mis distance _target) / (_speed max _speedmax/2)) min 1;
               _post = [(_post select 0)+(velocity _target select 0)*_tti,(_post select 1)+(velocity _target select 1)*_tti,((_post select 2)+(velocity _target select 2)*_tti)+_sealeveloffset];
            }
            else
            { 
               _post = [(getPos _mis select 0)+sin(getDir _mis)*4000,(getPos _mis select 1)+cos(getDir _mis)*4000, 0];
            };

            if ((_post select 2) < 2) then
            {
               if (!isNull _rtarget) then
               {
                  _post = [(_post select 0),(_post select 1), (_post select 2)+ _sealeveloffset];
               }
               else
               {
                  _post = [(getPos _mis select 0)+sin(getDir _mis)*4000,(getPos _mis select 1)+cos(getDir _mis)*4000, 0];
               };
            };
         }
         else
         {
            if (!isNull _rtarget) then
            {
               _post = [(_post select 0),(_post select 1), (_post select 2)+ _sealeveloffset];
            }
            else
            {
               _post = [(getPos _mis select 0)+sin(getDir _mis)*4000,(getPos _mis select 1)+cos(getDir _mis)*4000, 0];
            };
         };

         if (_mode != 4) then
         {
            _log setPosASL _post;
         };
      };
      _dist = _target distance _mis;
   }
   else
   {
      _rtargetlog setPos (_mis modelToWorld [0,4000,0]);
	  _rtarget = _rtargetlog;
	  _target = _rtarget;
      _dist = _target distance _mis;	  
   };
   _distr = _rtarget distance _mis;



   _altmasl = getPosASL _mis select 2;

   _alttasl = getPosASL _log select 2;
   _distance = _log distance _mis;

   _angv = asin((_alttasl - _altmasl)/_distance);
   _difang = abs(_climb - _angv);

//   hint format["%1 %2 %3 %4\n%5", _angv, getPosASL _mis, _difang, _angv, _distance];

   _climbdir = 1;
   if (_angv - _climb < 0) then {_climbdir = -1;};

   if ((_difang > _maxacqver)&&(_mode == 2)) then 
   {
      _follow = false;
   };
   
   if ((_difang < 0.005)||!_follow) then {_climbdir = 0;};


   if (_mode == 1) then
   {
      if (_altmasl > (_cruisealt + _alttasl)) then
      {
         _angv = -12;
         _climbdir = -1;
      };
   };


   _ang = ((_post select 0)-(_posm select 0)) atan2 ((_post select 1)-(_posm select 1));
   _dif = (_ang - _dir);
   if (_dif < 0) then {_dif = 360 + _dif;};
   if (_dif > 180) then {_dif = _dif - 360;};
   _difabs = abs(_dif);
  
   if ((_difabs > _maxacqhor)&&(_mode == 2)) then 
   {
      _follow = false;
   };

//   hint format["DI: %1, DM:%2, DT:%3, DA:%4", _dirini,_dir,_ang, _difabs];

   if ((_difabs >= 0.005) && _follow) then
   {
      _turn = _dif/_difabs;
   }
   else
   {
      _turn = 0;
   };


   if (_mode == 2) then 
   {
      _firstaim = false;
      _dir = _dir + (_turn * (((_deltah * _deltatime) min 5) min _difabs));
   }
   else
   {
      _dir = _dir + (_turn * (((_deltah * _deltatime) min 5) min _difabs));
   };


   _emergency = false;
   if (_terrain) then
   {
      _ground setPos [(_posm select 0)+sin(_dir)*200, (_posm select 1)+cos(_dir)*200, 0];
      if ( (((getPosASL _ground select 2)+30) > _altmasl)&&(_mode == 1)) then 
      {
         _climbdir = 1;
         _emergency = true;
         _angv = 30;
      }
      else
      {
         _ground setPos [(_posm select 0)+sin(_dir)*100, (_posm select 1)+cos(_dir)*100, 0];
         if ( (((getPosASL _ground select 2)+30) > _altmasl)&&(_mode == 1)) then 
         {
            _climbdir = 1;
            _emergency = true;
            _angv = 30;
         };
      };
   };


   if (((_climbdir > 0) && (_climb < _maxclimbup) && ((_climb < _angv))) ||
       ((_climbdir < 0) && (_climb > _maxclimbdown) && (_climb > _angv)) ) then
   {
      _climb = _climb + (_climbdir * ((_deltav * _deltatime) min 5));
   };
   

   if ( ((_climbdir > 0) && (_climb > _angv) && _follow && !_emergency) ||
        ((_climbdir < 0) && (_climb < _angv) && _follow) ) then 
   {
      _climb = _angv;
   };

   _dmg = damage _mis;

   if ((_dmg == 0) || ((_dmg > 0) && (speed _mis > 600) && _follow && (_mode == 2))) then
   {
      _vz = (sin _climb)*_speed;
      _vh = (cos _climb)*_speed;
      _vx = (sin _dir)*_vh;
      _vy = (cos _dir)*_vh;

      _mis setVectorDir[_vx/_speed, _vy/_speed, _vz/_speed];
      _uz = sin(_climb+90);
      _ur = cos(_climb+90);
      _ux = sin(_dir)*_ur;
      _uy = cos(_dir)*_ur;
      _mis setVectorUp[_ux, _uy, _uz];
   }
   else
   { 
      _climb = asin(vectorDir _mis select 2);
      _dir = getDir _mis;
   };

   if (_old_clibmdir != _climbdir) then
   {
      _deltav = 0;
      _old_climbdir = _climbdir;
   }
   else
   {
      _deltav = (_deltav + 1) min _vdegreessec2;
   };

   if (_old_turn != _turn) then
   {
      _deltah = 0;
      _old_turn = _turn;
   }
   else
   {
      _deltah = (_deltah + 1) min _hdegreessec2;
   };



   if (_dmg == 0) then 
   {
      _mis setVelocity [_vx, _vy, _vz];
   };

   _event = false;
   if (_mode == 0) then
   {
      if ((abs(_altmasl - _alttasl)<6) || (_distr < _radarrgn)) then
      {
         _event = true;
      };
   }
   else
   {
      if (_mode == 1) then
      {
         if (sqrt(((getPos _target select 0)-(getPos _mis select 0))^2 + ((getPos _target select 1)-(getPos _mis select 1))^2) < 100) then
         {
            _event = true;
         }
         else
         {
            if (_distr < _radarrgn) then
            {
               _event = true;
            }; 
         };
      };
   };


   if ((isNull _mis) || (_dmg > 0.1)) then
   {
      _event = true;
   };

   if (!isNull _target) then
   {
      if (((_distance < _proximitytemp) && (_target != _chaff)) ||
          ((_dist > 500) && (_dist > _distold) && (_target != _chaff) && ((getPos _rtarget select 2)>15)) && !_follow) then
      {	  
         _event = true;
      };
   };


   if (_event) then
   {


// The missile reached target, cruise alt or a mid-course position
      if ((_mode == 0) && (!isNull _mis) && (_dmg <= 0.1)) then 
      {
         _mode = 1;
         _ltarget setPosASL _postmode1;
         _target = _ltarget;
      } 
      else
      {
         if ((_mode == 1) && (!isNull _mis) && (_dmg <= 0.1)) then 
         {
            _mode = 2;
            _target = _rtarget;
            _proximitytemp = _proximity;
         }
         else
         {
            deleteVehicle _ltarget;
            deleteVehicle _log;
            deleteVehicle _ground;
            deleteVehicle _rtargetlog;
            if (!isNull _mis) then 
			{
			   if (_dmg <= 0.1) then
			   {
			      deleteVehicle _mis;
			   }
			   else
			   {
			      [_mis] spawn
				  {
				     Sleep 1;
					 deleteVehicle (_this select 0);
				  };
			   };
			};
			
			
            if (abs(_posmg select 0) < 1) then 
            {
               _finish=true;
            }
            else
            {

               if (_distr < _proximity*2) then 
               {
                  _target setDamage (damage _target + 0.11);
               };

/*
               if (_boomscript != "") then 
               { 
                  mando_deton_x = _posmg select 0;
                  mando_deton_y = _posmg select 1;
                  mando_deton_z = _posmg select 2;
                  mando_deton_target = _rtarget;
                  mando_deton_side = _side;
                  mando_deton_launcher = _launcher;
                  mando_deton_script = _boomscript;
                  mando_deton_req = true;

                  publicVariable "mando_deton_x";publicVariable "mando_deton_y";publicVariable "mando_deton_z";publicVariable "mando_deton_target";publicVariable "mando_deton_side";publicVariable "mando_deton_launcher";publicVariable "mando_deton_script";publicVariable "mando_deton_req";
               };
*/
               _finish=true;        
            };
         };
      };
   };

   if (!_finish) then
   {
//      if ((_dist > (_radarrgn+500)) && (_mode == 2)) then {_follow = false};

      if ((_target != _chaff) && (_mode == 2)) then
      {
         _distold = _dist;
      }
      else
      {
         _distold = 999999;
      };

      if (_debug) then 
      {
         if (mando_missile == _mis) then
         {
            mando_missile_follow = _follow;
            mando_missile_mode = _mode;
            mando_missile_emergency = _emergency;
            mando_missile_distance = _dist;
            mando_missile_endurance = floor (_timeleft);
         };
      };

      sleep _delay;

      if ((dayTime * 3600) > (_correctionstime + _corrections)) then
      {
         _correctionstime = (dayTime * 3600);
         if (_mode == 1) then
         {
            _ang = ((_posm select 0)-(getPos _rtarget select 0)) atan2 ((_posm select 1)-(getPos _rtarget select 1));
            if (_ang < 0) then {_ang = 360 + _ang;};

            _vt = (speed _rtarget) / 3.6;
            _vr = _speedmax;

            _dirt = getDir _rtarget;
            _dif = abs(_ang - _dirt);
            if (_dif > 180) then {_dif = 360 - _dif;};


            _dir1 = _dirt + 2;
            if (_dir1 > 360) then {_dir1 = _dir1 - 360;};
            _dif1 = abs(_ang - _dir1);
            if (_dif1 > 180) then {_dif1 = 360 - _dif1;};


            _dir2 = _dirt - 2;
            if (_dir2 < 0) then {_dir2 = 360 - _dir2;};
            _dif2 = abs(_ang - _dir2);
            if (_dif2 > 180) then {_dif2 = 360 - _dif2;};


            _sig = 1;
            if (_dif2 < _dif1) then {_sig = -1;};

            _angi1 = asin((_vt/_vr)*sin(_dif));
            _angi = (_ang + 180) + _sig*_angi1;

            _dist = _mis distance _target;
            _tti = (_mis distance _rtarget) / ((_vt*cos(_dif)+_vr*cos(_angi1))+0.0001);


            if (_dist > _radarrgn/4.0) then
            {
               _postmode1 = [(_posm select 0)+sin(_angi)*(((_speedmax*_tti)-(_radarrgn/1.2)) max 200),(_posm select 1)+cos(_angi)*(((_speedmax*_tti)-(_radarrgn/1.2)) max 200), 0];

               if (_terrain) then
               {
                  _ltarget setPos _postmode1;
//                  _postmode1 = [_postmode1 select 0, _postmode1 select 1, _cruisealt + (getPosASL _ltarget select 2)];
                  _postmode1 = [_postmode1 select 0, _postmode1 select 1, _cruisealt + (getPosASL _rtarget select 2)];
               }
               else
               {
                  _ltarget setPos _postmode1;
//                  _postmode1 = [_postmode1 select 0, _postmode1 select 1, _cruisealt + (getPosASL _ltarget select 2)];
                  _postmode1 = [_postmode1 select 0, _postmode1 select 1, _cruisealt + (getPosASL _rtarget select 2)];

               };
               _target setPosASL _postmode1;
            };
         };
      };

      if ((dayTime * 3600) > (_controltimeini + _controltime)) then
      {
         _controltime = 99999;

         _deltah = _hdegreessec2;
         _deltav = _vdegreessec2;
      };

      if ((dayTime * 3600) < (_endurancetimeini + _endurance)) then
      {
         _timeleft =  ((_endurancetimeini + _endurance) - (dayTime * 3600));

         if (typename _accel == "ARRAY") then
         {
            if (_timeleft < (_endurance - 1)) then
            {
               _accelfact = _accel select 1;
            };
         };
      }
      else
      {
         if (_dmg == 0) then
         {
            _mis setDamage 0.05;
         };
         _timeleft = 0;
      };


      if (_sound != "") then 
      {
         if ( ((dayTime * 3600) > (_soundtimeini + _sounddur - 0.5)) && (_dmg == 0)) then
         {
            _soundtimeini = (dayTime * 3600);
            _mis say3D _sound;
         };
      };
   };
};