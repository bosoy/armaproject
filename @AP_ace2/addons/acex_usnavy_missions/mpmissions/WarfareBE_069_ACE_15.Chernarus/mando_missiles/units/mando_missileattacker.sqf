/* 
 mando missile armed AI unit main handler
 mando_missileattacker.sqf v2.36
 August 2009 Mandoble
 

The purpose is to add an automatic lock on/missile fire system for a unit
More than 1 system may be added to a single unit (but not at the same firing place).
Execute this script only on the server, or execute it using a helper script like these present in "attackers" folder (which should be executed also only on the server).

NOTE: Automatic launchers with firing unit in "BLUE" combat comde will cease fire.

Syntax:
[disp, unitpos, ttype, quantity, min range, max range, rate of fire, firing pos, scan arc or scan array, minknows, enemy sides, antimissile?, radar initially ON?, Radio Messsages?, missile params, radar on sound, radar off sound] exec"mando_missileattacker.sqf"

 disp: Missile armed vehicle
 unitpos: Missile armed unit position inside vehicle: 0 driver, 1 gunner, 2 commander, anyother value = no unit.
 missile target types array: ["Air"] or ["LandVehicle"] or ["Air", "LandVehicle", "Ship"],etc. "REMOTE" target type may be used to indicate this unit may target targets locked by other units.    
 quantity: number of missiles loaded into this unit.
 min range: closer than that, the system will not attack units.
 max range: farther than that, the system will not attack units
 rate of fire: maximum number of missiles launched per minute.
 firing position: model coordinates of the missile firing position relative to the launcher, 
                  or four elements array array with model coordinates and radius.
                  If radius is provided, the center will be the first 3 elements of the array and the firing position
                  will be calculated starting from this center, and considering the provided radius and firing direction.
 scan arc: arc in front of the firing unit where targets may be locked, 90 means from -45 degrees to the left to
           +45 degrees to the right, 360 will lock on any target in range, 180 will lock on any target in front 
           of the firing unit (from -90 to the left to +90 to the right).
           or
           array with arc and delta. Delta is an angle to add to the direction of the firing unit. For example, a gun 
           able to engange targets to the left of the firing unit in an arc of 90 degrees [90,270]. 
 minimum knowledge: Minimum knowledge of the target to attack it from 0 (nothing, STANDOFF attacks) to 4 (everything).
 enemy sides: array with sides considered enemy (west, east, resistance, sideLogic, sideEnemy and/or civilian), leave it as empty array for automatic enemy sides detection ([]).
              note: empty units side is civilian
              note: if you include the side of the launcher, it may launch a missile to itself.
              note: if the side of the launcher is civilian and this array is empty, it will attack any other side 

 Able to track and fire against incomming detectable missiles? (true/false)
 Its "launcher" is fixed to the direction of the vehicle? true/false. If false, the missile will be fired already oriented towards the target, else using the launcher's direction.
 Initially active: true/false. If false, the unit may be activated writing a true into its "mando_missileattacker_on" variable.
                   You may use mando_attackeronoff.sqf to activate/deactivate one or more units.
 Radio initially on: true/false. If false, it may be turned on when needed writing a true into its "mando_missileattacker_radio" variable.
 Array of missile paramters (same as used for mando_missile.sqf script)
 Radar ON sound resource name, "" if none.
 Radar OFF sound resource name, "" if none.
 Radar name (text string, same as used for mando_radar), this parameter is optional, if used then the launcher will use the provided radar and not its own one.


 Example of init field for a AG missile armed unit with a single missile system:

 this as missile armed unit
 Firing unit position: 1 (gunner)
 Target Type = 1 (ground/sea)
 8 missiles left
 Range from 500 to 2000m
 firing up to 10 missiles per minute
 Firing place 3m ahead and 3m above firing unit's vehicle position
 Searching for targets in an arc of 90 degress in from the of the launching vehicle
 The target needs to be known minimally by the firing unit
 Will attack only east side units
 Not able to track and fire against incomming missiles
 The missile will be launched with launcher dir
 Initially active
 Transmitting targets and shots by radio
 [this, 1, 1, 8, 500, 2000, 10, [0,3,3], 90, 1, [east], false, false, true, true, _mymissileparams, "", ""]execVM"mando_missiles\units\mando_missileattacker.sqf"


 Example to turn on an existing missile system:
 sam1 setVariable ["mando_missileattacker_on", true]

 Example to turn off an existing missile system:
 sam1 setVariable ["mando_missileattacker_on", false]

 Example to turn on radio messages of an existing missile system:
 sam1 setVariable ["mando_missileattacker_radio", true]

 Example to turn off radio messages of an existing missile system:
 sam1 setVariable ["mando_missileattacker_radio", false]
*/

private["_disp", "_unitpos", "_quantityini", "_missidx", "_minrange", "_maxrange", "_rof", "_firingpos", "_arc", "_deltaarc", "_minknow", "_enemysides", "_enemysides_org", "_antimissile", "_fixeddir", "_active", "_radio", "_missparams", "_radaronsound", "_radaroffsound", "_unit", "_wait", "_i", "_blanco", "_espera", "_disparado", "_list", "_knows", "_know", "_angulos", "_posl", "_mindir", "_minang", "_minangi", "_enemigo", "_posfoe", "_altenemigo","_altenemigoasl", "_bandoenemigo", "_ang", "_angv", "_difang", "_dist", "_endofunits", "_targetmissile", "_mccstate", "_vdir", "_mindist", "_quantity", "_ammos", "_trigger", "_airpresent", "_vehiclespresent", "_createtrigger", "_refresh_state", "_posdisp", "_posfoe", "_blancos", "_los_log", "_los_ok", "_los_check", "_pos_asl", "_launchpos", "_ratev", "_remote_start", "_remote_end", "_dird", "_count", "_maxtalt", "_mintalt", "_maxtaltasl", "_found", "_unitposs", "_code", "_min_firing_alt", "_firingrad", "_angi", "_last_target", "_radar", "_external_radar", "_max_jumps"];


_disp          = _this select 0; 
_unitpos       = _this select 1;
_ttypes        = _this select 2;
_quantityini   = _this select 3;
_minrange      = _this select 4;
_maxrange      = _this select 5;
_rof           = _this select 6;
_firingpos     = _this select 7;
if (typeName (_this select 8) == "ARRAY") then
{
   _arc = (_this select 8) select 0;
   _deltaarc = (_this select 8) select 1;
}
else
{
   _arc           = _this select 8;
   _deltaarc      = 0;
};
_minknow       = _this select 9;
_enemysides_org= _this select 10;
_antimissile   = _this select 11;
_fixeddir      = _this select 12;
_active        = _this select 13;
_radio         = _this select 14;
_missparams    = _this select 15;
_radaronsound  = _this select 16;
_radaroffsound = _this select 17;
_external_radar = false;
if (count _this > 18) then
{
   _radar = _this select 18;
   _external_radar = true;
};

_last_target = objNull;
if (isNull _disp) exitWith {};


if (count _firingpos == 4) then
{
   _firingrad = _firingpos select 3;
   _firingpos = [_firingpos select 0, _firingpos select 1,_firingpos select 2];
}
else
{
   _firingrad = 0;
};

_disp setVariable ["mando_auto_fired", objNull, true];
_var = _disp getVariable "mando_auto_allowed";
if (isNil "_var") then
{
	_disp setVariable ["mando_auto_allowed", true, true];
};

_var = _disp getVariable "mando_target_auto";
if (isNil "_var") then
{
   _disp setVariable ["mando_target_auto", objNull, true];
};

_var = _disp getVariable "mando_attacker_auto";
if (isNil "_var") then
{
   _disp setVariable ["mando_attacker_auto", true, true];
};


_unit     = objNull;
_wait     = 60.0 / _rof;
_arc      = _arc / 2;

_i = 0;
_blanco=objNull;
_espera = 1.0;
_disparado = false;
_list = [];
_knows = [];
_angulos = [];
_posl = [0,0,0];
_midir = 0;
_minang = 9999.0;
_minangi = -1;
_enemigo = objNull;
_posfoe = [0,0,0];
_altenemigo = 0;
_bandoenemigo = east;
_know = 0.0;
_ang  = 999.9;
_angv = 0.0;
_difang = 0.0;
_dist = 0;
_endofunits = 0;
_targetmissile = false;
_mccstate = false;
_i = 0;
_vdir = [0,0,0];
_mindist = 99999;
if (typeName _quantityini == "ARRAY") then
{
	_missidx = _quantityini select 0;
	_quantityini = _quantityini select 1;
}
else
{
	_missidx = -1;
	for [{_i=7},{_i>0},{_i=_i-1}] do
	{
		if (_missidx == -1) then
		{
			_var = _disp getVariable (format["mando_maxmissiles%1",_i]);
			if (!isNil "_var") then
			{
				_missidx = _i;
			};
		};
	};
	
	if (_missidx == -1) then
	{
		_missidx = 7;
	};
};
_quantity = _quantityini;
_disp setVariable [format["mando_maxmissiles%1",_missidx], _quantity, true];
_ammos = [];
_trigger = objNull;
_airpresent = false;
_vehiclespresent = false;
_createtrigger = false;


if (isNil "_disp") exitWith {hint "mando_missileattacker.sqf: NULL unit provided";};
if (isNull _disp) exitWith {hint "mando_missileattacker.sqf: NULL unit provided";};

Sleep 0.5 + random 3;

if ("Air" in _ttypes) then
{
   _airpresent = true;
   _createtrigger = true;
};


_mintalt = -100;
_maxtalt = 9.9;
_maxtaltasl = 2;


if (("LandVehicle" in _ttypes) || ("Ship" in _ttypes)) then
{

   if ("LandVehicle" in _ttypes) then
   {
      _maxtaltasl = 40000;
   };

   _vehiclespresent = true;
   _createtrigger = true;
};


if (_airpresent || _antimissile) then
{
   _maxtalt = 40000;
   _maxtaltasl = 40000;
   if ((count _ttypes == 1) && ("Air" in _ttypes)) then
   {
      _mintalt = mando_minairalt;
   };
};

_remote  = false;
if ("REMOTE" in _ttypes) then
{
   _maxtaltasl = 40000;
   _remote = true;
   _ttypes = _ttypes - ["REMOTE"];
};


if (_unitpos == 0) then
{
   _unit = driver _disp;
}
else
{
   if (_unitpos == 1) then
   {
      _unit = gunner _disp;
   }
   else
   {
      if (_unitpos == 2) then
      {
         _unit = commander _disp;
      }
      else
      {
         _unit = _disp;
      };
   };
};


_los_log = "Logic" createVehicleLocal [0,0,0];

if (!_radio) then 
{
   _disp setVariable ["mando_missileattacker_radio", false];
}
else
{
   _disp setVariable ["mando_missileattacker_radio", true];
};


if (_unitpos == 0) then
{
   _unitposs = "driver";
}
else
{
   if (_unitpos == 1) then
   {
      _unitposs = "gunner";
   } 
   else
   {
      if (_unitpos == 2) then
      {
         _unitposs = "commander";
      } 
      else
      {
         _unitposs = "";
      };
   };
};
 
if (_unitposs != "") then
{
   _code = compile format["%1 _disp", _unitposs];
   _unit = call _code;
};

if (!_active) then 
{
   _disp setVariable ["mando_missileattacker_on", false];
}
else
{
   _disp setVariable ["mando_missileattacker_on", true];
   _mccstate = true;


   if (
       (((_unitpos == 0) && !(isNull driver _disp) && (alive driver _disp) && !(isPlayer driver _disp)) ||
       ((_unitpos == 1) && !(isNull gunner _disp) && (alive gunner _disp) && !(isPlayer gunner _disp)) ||
       ((_unitpos == 2) && !(isNull commander _disp) && (alive commander _disp) && !(isPlayer commander _disp)) ||          (_unitpos > 2)) &&
       (alive _disp) && !(isNull _disp)) then
   {
      if (_radaronsound != "") then 
	  {
			if (_disp getVariable "mando_attacker_auto") then
			{
				_disp say3d _radaronsound;
			};	  
	  };

      if ((_disp getVariable "mando_missileattacker_radio") && !(isNull _unit))then
      {
         if (!isNull _unit) then
         {
            _unit sideChat format["%1 switching on MCC", _disp];
         };
      };


      if (!(_disp isKindOf "Air") && _createtrigger) then
      {
         if (!_external_radar) then
         {
			if (_disp getVariable "mando_attacker_auto") then
			{
				mando_radar_on = _disp;publicVariable "mando_radar_on";
			};
         };
      };
   };
};

if (_createtrigger) then
{
   if (!_external_radar) then
   {
      _trigger = createTrigger ["EmptyDetector", getPos _disp];
      _trigger setTriggerActivation ["ANY", "PRESENT", false];
      _trigger setTriggerArea [_maxrange, _maxrange, 0, false];
      _trigger setTriggerType "NONE";
      _trigger setTriggerStatements ["this", "", ""];
      _trigger setTriggerTimeout [0, 0, 0, false ];
   }
   else
   {
      _trigger = call compile _radar;
   };
};

_refresh_state = 0;

_min_firing_alt = -200;
if (_disp isKindOf "Air") then
{
   _min_firing_alt = 10;
};

_disp setVariable ["mando_enemy_sides", _enemysides_org];


while {(alive _disp)&&!(isNull _disp)} do
{
   if (_unitposs != "") then
   {
      _unit = call _code;
   };

   if (!(_disp getVariable "mando_missileattacker_on") || ((getPos _disp select 2) < _min_firing_alt) ||
       ((_unitpos < 3) && (isNull _unit || isPlayer _unit || (combatMode _unit == "BLUE")))) then
   {
      if (_mccstate) then 
      {
         if (_radaroffsound != "") then 
         {
            _disp say3d _radaroffsound;
         };

         if (!(_disp isKindOf "Air") && _createtrigger) then
         {
            if (!_external_radar) then
            {
               mando_radar_off = _disp;
               publicVariable "mando_radar_off";
            };
         };

         if (_disp getVariable "mando_missileattacker_radio") then
         {
            if ((alive _unit) && (_unit in _disp)) then
            {
               _unit sideChat format["%1 switching off MCC", _disp];
            };
         };
         _mccstate = false;
      };

      _found = false;
      while {!_found && alive _disp && !isNull _disp} do
      {
         if (_unitposs != "") then
         {
            _unit = call _code;
            if (!isNull _unit) then
            {
               if ((alive _unit) && (!isplayer _unit)) then
               {
                  if ((_disp getVariable "mando_missileattacker_on") && !(combatMode _unit == "BLUE")) then
                  {
                     _found = true;
                  };
               };
            };
         }
         else
         {
            if (_disp getVariable "mando_missileattacker_on") then
            {
               _found = true;
            };
         };

         if ((getPos _disp select 2) < _min_firing_alt) then
         {
            _found = false;
         };

         Sleep 2;
      };

      if ((!alive _disp) || (isNull _disp)) exitWith {};   

      if (_radaronsound != "") then {_disp say3d _radaronsound;};


      if (!(_disp isKindOf "Air") && _createtrigger) then
      {
         if (!_external_radar) then
         {
            mando_radar_on = _disp;publicVariable "mando_radar_on";
         };
      };


      if (_disp getVariable "mando_missileattacker_radio") then
      {
         _unit sideChat format["%1 switching on MCC", _disp];
      };
      _mccstate = true;      
   };

   if ((!alive _disp) || (isNull _disp)) exitWith {};

   if (_disparado) then 
   {
      _disparado = false;
      _espera = _wait;
   }
   else
   {
      _espera = 1;
   };
   sleep _espera;

   if ((alive _unit) && (vehicle _unit == _disp) && (alive _disp) && (_quantity > 0) && (!isNull _disp) && (!isNull _unit) && !(combatMode _unit == "BLUE") && (_disp getVariable "mando_missileattacker_on")) then 
   {
      //List of units affected by the scan area
      if ((!alive _disp) || (isNull _disp)) exitWith {};

	  if (_disp getVariable "mando_attacker_auto") then
	  {
	  
      _refresh_state = _refresh_state + 1;
      if (_refresh_state > 5) then
      {
         if (!(_disp isKindOf "Air") && _createtrigger) then
         {
            if (_disp getVariable "mando_missileattacker_on") then
            {
               if (!_external_radar) then
               {
                  mando_radar_on = _disp;
                  publicVariable "mando_radar_on";
               };
            };
         };
         _refresh_state = 0;
      };

      _enemysides = _disp getVariable "mando_enemy_sides";
      if (count _enemysides == 0) then
      { 
         _enemysides = [];
         {
            if ((side _disp getFriend _x) < 0.2) then
            {
               _enemysides = _enemysides + [_x];
            }; 
         } forEach ([west, east, resistance, sideEnemy] - [side _disp]);
      };
	  _enemysides = _enemysides - [civilian];	  

      _list = [];
      if (_createtrigger) then
      {
         if (!_external_radar) then
         {
            _trigger setPos getPos _disp;
         };


         if (count _ttypes > 0) then
         {
            {
               if ((getPos _x select 2) > 3) then
               {
                  if ((isEngineOn _x) && !(_x isKindOf "Man") && !(captive _x)) then 
                  {
                     if (!((typeOf _x) in mando_missile_stealth)) then
                     {
                        if ((side _x) in _enemysides) then
                        {
                           _list = _list + [_x];
                        };
                     };
                  }; 
               }
               else
               {
                  if ((driver _x != _x)) then 
                  {
                     if ((side _x) in _enemysides) then
                     {
                        _list = _list + [_x];
                     };
                  };
               };
            } forEach list _trigger;
         };
      };

      _remote_start = (count _list);
      if (_remote) then
      {
         switch (side _disp) do
         {    
            case west:
            {
               _list = _list + mando_remote_targets_w;
            };

            case east:
            {
               _list = _list + mando_remote_targets_e;
            };

            case resistance:
            {
               _list = _list + mando_remote_targets_r;
            };
         };
      };
      _remote_end = (count _list) - 1;

      _endofunits = (count _list) - 1;

      if (_antimissile) then 
      {
         // Missiles in flight in range against friendly units are added to the list

         _i = 0;
         {
            if ( (side (mando_detowners select _i) in _enemysides)&&((_x distance _disp)<_maxrange)) then 
            {
               _list = _list + [_x]
            };
            _i=_i+1;
         } forEach mando_detmissiles;
      };

      _blanco = objNull;
// [target, missile, remote]
      _blancos = [[objNull, false, false],[objNull, false, false],[objNull, false, false]];


      if (count _list > 0) then 
      {
         //Heading of the vehicle (if any) of the firing unit
         _vdir = vectorDir _disp;
         _dird = (_vdir select 0) atan2 (_vdir select 1);

         _posdisp = getPos _disp;

         _mindist = 99999;
         _count = count _list;


         for [{_i = 0},{_i < _count},{_i = _i + 1}] do
         {
//            _enemigo = _list select _i;
            _enemigo = _list select (_count - _i - 1);
            _posfoe = getPos _enemigo;
            _altenemigo = _posfoe select 2;
            _altenemigoasl = getPosASL _enemigo select 2;
            _bandoenemigo = side _enemigo;
            _know = 0.0;
            _ang  = 9999.0;
            _dist = _enemigo distance _disp;

            _targetmissile = false;

            if ((_altenemigo >= _mintalt) && (_altenemigo <= _maxtalt) && (_altenemigoasl < _maxtaltasl) &&
                (_dist >= _minrange) && (_dist <= _maxrange) && 
                (alive _enemigo)) then
//                ((_bandoenemigo in _enemysides)||(_i > _endofunits)) ) then 
            {
               _know=_unit knowsAbout _enemigo;

               _ang = ((_posfoe select 0) - (_posdisp select 0)) atan2 ((_posfoe select 1) - (_posdisp select 1));
               _difang = (_ang - ((_dird + _deltaarc) mod 360));
               if (_difang < 0) then {_difang = 360 + _difang;};
               if (_difang > 180) then {_difang = _difang - 360;};
               _difang = abs(_difang);

               if ((_difang <= _arc) && (_know >= _minknow)) then 
               {
               // Suitable target
                  if (_i > _endofunits) then 
                  {
                     _mindist = 0;
                     _targetmissile = true;

                     _blancos set [2, [(_blancos select 1) select 0,(_blancos select 1) select 1,(_blancos select 1) select 2]];
                     _blancos set [1, [(_blancos select 0) select 0,(_blancos select 0) select 1,(_blancos select 0) select 2]];
                     _blancos set [0, [_enemigo, true, false]];
                  }
                  else
                  {
                     if (_dist < _mindist) then 
                     {
                        _mindist = _dist;

                        _blancos set [2, [(_blancos select 1) select 0,(_blancos select 1) select 1,(_blancos select 1) select 2]];
                        _blancos set [1, [(_blancos select 0) select 0,(_blancos select 0) select 1,(_blancos select 0) select 2]];


                        if (_i < _remote_start) then
                        {
                           _blancos set [0, [_enemigo, false, false]];
                        }
                        else
                        {
                           _blancos set [0, [_enemigo, false, true]];
                        };
                     };
                  };
               };
            };
         };

        
         _los_check = true;
         if ((getPosASL _disp select 2) < -1) then
         {
            _los_check = false;
         };


         _launchpos = _disp modelToWorld _firingPos;
         if (!_targetmissile) then
         {
            _max_jumps = floor random 3;
         }  
         else
         {
            _max_jumps = 0;
            _last_target = objNull;
         };

         for [{_i = 0},{_i < 3},{_i = _i + 1}] do
         {
            if ((!isNull((_blancos select _i) select 0)) && 
                ((isNull _blanco) || (_blanco == _last_target) || (_i < _max_jumps))) then
            {
               _enemigo = (_blancos select _i) select 0;
            // Check LOS
               _los_ok  = [_los_log, _disp, _enemigo, 50, 2] call mando_check_los;
			   
               if (_los_ok) then
               {
                  _blanco = _enemigo;
                  _targetmissile = (_blancos select _i) select 1;
               };                
            };
         };         
      }; // End List = []
	  
	  } // End	  if (_disp getVariable "mando_attacker_auto")
	  else
	  {
	     _blanco = _disp getVariable "mando_target_auto"; // El blanco lo da un tercero
	  };

      //If a unit accomplish the requirements to be targeted
      if (!isNull _blanco) then 
      {
         //Now we have a target
         mando_lockedon=_blanco;
         publicVariable "mando_lockedon";
         _last_target = _blanco;
         _disp setVariable ["mando_target_auto", _blanco];

         if (_disp getVariable "mando_missileattacker_radio") then
         {
            if (_targetmissile) then
            {
               _unit sideChat format["%1 lock on incomming missile!", _disp]; 
            }
            else
            { 
               _unit sideChat format["%1 lock on %2", _disp, typeOf _blanco];
            };
         };

         //Add here anyother target validation rule before launching the missile
      
         //Missile is fired
         _dird = getDir _disp;
         _posfoe = getPos _blanco;
         _posdisp = getPos _disp;

         if (!_fixeddir) then
         { 
            _ang = ((_posfoe select 0) - (_posdisp select 0)) atan2 ((_posfoe select 1) - (_posdisp select 1));
            _angv = _missparams select 4;
         }
         else
         {
            _ang = _dird;
            _angv = asin(vectorDir _disp select 2);  
         };


         if (abs(_angv) < 90) then
         {
            _angi = sin(_angv);
         }
         else
         {
            _angi = ((_disp worldToModel _posfoe) select 2) / (_disp distance _blanco);
         };

         if (_unitpos == 1) then
         {
            (gunner _disp) doWatch [(_posdisp select 0)+sin(_ang)*50,(_posdisp select 1)+cos(_ang)*50,(_posdisp select 2)+_angi*50];
            sleep 1;
         };
// Sleep between radar lock message and missile
         sleep 1;

                    

         _posl = [(_firingpos select 0)+sin(_ang - _dird)*_firingrad, (_firingpos select 1)+cos(_ang - _dird)*_firingrad,(_firingpos select 2)+_angi*_firingrad];

         if ((abs(_firingpos select 0) > 0) && ((_posdisp select 2) > 3)) then
         {
            _firingPos set [0, -(_firingpos select 0)];
         };

         if ((alive _disp) && (alive _unit) && (alive _blanco)) then 
         {
			if (_disp getVariable "mando_auto_allowed") then
			{	
				_missparams set [0,_disp];
				_missparams set [2,_posl];
				_missparams set [3,_ang];
				_missparams set [4,_angv];
				_missparams set [8,_blanco];
	//               _missparams set [12,(getPosASL _blanco select 2)];
				_missparams execVM mando_missile_path+"mando_missile.sqf";

				[_disp] spawn
				{
					Sleep 0.5;
					_mis = (_this select 0) getVariable "mando_missile_fired";
					(_this select 0) setVariable ["mando_auto_fired", _mis, true];
				};
				
				_disparado = true;
				_quantity = _quantity - 1;
				_disp setVariable [format["mando_maxmissiles%1",_missidx], _quantity, true];	  
				if (_disp getVariable "mando_missileattacker_radio") then
				{
				   if (_quantity != 1) then
				   {
					  _unit sideChat format["%1 Fox One! %2 missiles left", _disp, _quantity];
				   }
				   else
				   {
					  _unit sideChat format["%1 Fox One! 1 missile left", _disp];
				   };
				};
			};
         };
      }
	  else
	  {
         _disp setVariable ["mando_target_auto", objNull];	  
	  };
   };


   if ((_quantity == 0) && (alive _disp) && (alive _unit)) then
   {
      _ammos = nearestObjects [_disp, ["MtvrReammo", "KamazReammo", "UralReammo_INS", "UralReammo_CDF", "WarfareReammoTruck_USMC","WarfareReammoTruck_RU","WarfareReammoTruck_Gue"], 12];
      _disp setVariable ["mando_target_auto", objNull];
      Sleep 3;	  
	  
	  
	  
      if (count _ammos > 0) then
      {
         if (damage (_ammos select 0) < 0.5) then 
         {
            if (_disp getVariable "mando_missileattacker_radio") then
            {
               if (alive _unit) then
               {
                  _unit sideChat "Reloading missiles";
               };
            };
            Sleep 5;
            _quantity = _quantityini;
			_disp setVariable [format["mando_maxmissiles%1",_missidx], _quantity, true];			
            if (alive _disp) then
            {
               if (_disp getVariable "mando_missileattacker_radio") then
               {
                  if (alive _unit) then
                  {
                     _unit sideChat "Missiles reloaded";
                  };
               };
            };
         };
      }; 
   };
};

if (_disp getVariable "mando_missileattacker_radio") then
{
   if ((alive _unit) && (_unit in _disp)) then
   {
      _unit sideChat format["%1 switching off MCC", _disp];
   };
};

if (!(_disp isKindOf "Air") && _createtrigger) then
{
   if (!_external_radar) then
   {
      mando_radar_off = _disp;
      publicVariable "mando_radar_off";
   };
};


if (_radaroffsound != "") then 
{
   _disp say3d _radaroffsound;
};

deleteVehicle _los_log;
if (_createtrigger) then
{
   if (!_external_radar) then
   {
      deleteVehicle _trigger;
   };
};