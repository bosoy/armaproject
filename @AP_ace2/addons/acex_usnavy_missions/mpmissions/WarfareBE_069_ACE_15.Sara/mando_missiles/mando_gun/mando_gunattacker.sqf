/* 
 mando_gunattacker.sqf v1.2
 August 2007 Mandoble 
 

The purpose is to add an automatic lock on/gun fire system for a unit
More than 1 system may be added to a single unit (but not at the same firing place.


 Sintax:
[disp, unitpos, ttype, quantity, min range, max range, muzzle velocity, rounds per salvo, rate of fire, max dispersion array, time to aim, detonate?, firing gun, ammo type, firing pos, gun barrel length, scan arc, minknows, enemy sides, antimissile?, gun initially ON?, Radio Messsages?, radar on sound, radar off sound, shot sound] exec"mando_gunattacker.sqf"

 disp: gun armed vehicle
 unitpos: gun armed unit position inside vehicle: 0 driver, 1 gunner, 2 commander.
 gun target types array: ["Air"] or ["LandVehicle"] or ["Men"] or ["Air", "LandVehicle", "Ship"],etc. "REMOTE" target type may be used to indicate this unit may target targets locked by other units.    
 quantity: number of salvos loaded into this unit.
 min range: closer than that, the system will not attack units.
 max range: farther than that, the system will not attack units
 muzzle velocity: Muzzle velocity in m/s
 rounds per salvo: number of shots per salvo.
 rate of fire: maximum number of salvos fired per minute.
 max dispersion array: [hor, vert] in degrees, max dispersion at 400m.
 time to aim: time needed to aim to the target in seconds.
 detonate?: true/false, if true an small explosion will happen when round if close to the target.
 firing gun: The gun class which will fire, "" if none.
 ammo type: ammo class use to fire, for example "B_23mm_AA", "B_20mm_AA", "B_30mmA10_AP", "B_30mm_HE", "B_127x99_Ball", etc.
 firing position: relative firing position of the salvo to the launcher (vehicle or unit parameter).
 gun barrel length: aproximate length of the gun in meters (number) or barrel end model selection name (string)
 scan arc: arc in front of the firing unit where targets may be locked, 90 means from -45 degrees to the left to
           +45 degrees to the right, 360 will lock on any target in range, 180 will lock on any target in front 
           of the firing unit (from -90 to the left to +90 to the right).
           or
           array with arc and delta. Delta is an angle to add to the direction of the firing unit. For example, a gun 
           able to engange targets to the left of the firing unit in an arc of 90 degrees [90,270]. 

 minimum knowledge: Minimum knowledge of the target from 0 (nothing, STANDOFF attacks) to 4 (everything).
 enemy sides: array with sides considered enemy (west, east, resistance, sideEnemy and/or civilian)
              note: empty units side is civilian
 Able to track and fire against incomming missiles? (true/false)
 Initially active: true/false. If false, the unit may be activated writing a true into its "mando_gunattacker_on" variable.
 Radio initially on: true/false. If false, it may be turned on when needed writing a true into its "mando_gunattacker_radio" variable.
 Radar ON sound resource name (defined in description.ext), "" if none.
 Radar OFF sound resource name (defined in description.ext), "" if none.
 Shot sound resource name (defined in description.ext).
 Animation code (optional).
*/

private["_disp", "_unitpos", "_quantityini", "_minrange", "_maxrange", "_rof", "_maxdisp", "_detonate", "_firinggun", "_ammotype", "_firingpos", "_arc", "_deltaarc", "_minknow", "_enemysides", "_antimissile",  "_active", "_radio", "_radaronsound", "_radaroffsound", "_unit", "_wait", "_i", "_blanco", "_espera", "_disparado", "_list", "_knows", "_know", "_angulos", "_posl", "_mindir", "_minang", "_minangi", "_enemigo", "_posfoe", "_altenemigo", "_bandoenemigo", "_know", "_ang", "_difang", "_dist", "_endofunits", "_targetmissile", "_mccstate", "_vdir", "_mindist", "_quantity", "_ammos", "_trigger", "_airpresent", "_vehiclespresent", "_menpresent", "_createtrigger", "_refresh_state", "_posdisp", "_posfoe", "_barrellength", "_timeini", "_salvosound","_muzzlevel","_aimtime","_rounds_salvo", "_effects", "_towait", "_animcode", "_log_sound", "_tti", "_vel"];

_disp          = _this select 0; 
_unitpos       = _this select 1;
_ttypes        = _this select 2;
_quantityini   = _this select 3;
_minrange      = _this select 4;
_maxrange      = _this select 5;
_muzzlevel     = _this select 6;
_rounds_salvo  = _this select 7;
_rof           = _this select 8;
_maxdisp       = _this select 9;
_aimtime       = _this select 10;
_detonate      = _this select 11;
_firinggun     = _this select 12;
_ammotype      = _this select 13;
_firingpos     = _this select 14;
_barrellength  = _this select 15;
if (typeName (_this select 16) == "ARRAY") then
{
   _arc = (_this select 16) select 0;
   _deltaarc = (_this select 16) select 1;
}
else
{
   _arc           = _this select 16;
   _deltaarc      = 0;
};
_minknow       = _this select 17;
_enemysides    = _this select 18;
_antimissile   = _this select 19;
_active        = _this select 20;
_radio         = _this select 21;
_radaronsound  = _this select 22;
_radaroffsound = _this select 23;
_salvosound    = _this select 24;

if ((count _this) > 25) then
{
   _animcode      = _this select 25;
}
else
{
   _animcode = {};
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
_quantity = _quantityini;
_ammos = [];
_trigger = objNull;
_airpresent = false;
_vehiclespresent = false;
_menpresent = false;
_createtrigger = false;

Sleep 2;
if ("Air" in _ttypes) then
{
   _airpresent = true;
   _createtrigger = true;
};

if ("Men" in _ttypes) then
{
   _menpresent = true;
   _createtrigger = true;  
};

if (("LandVehicle" in _ttypes) || ("Ship" in _ttypes) ) then
{
   _vehiclespresent = true;
   _createtrigger = true;
};


_mintalt = -100;
_maxtalt = 9.9;
if (_airpresent || _antimissile) then
{
   _maxtalt = 4000;
   if ((count _ttypes == 1) && ("Air" in _ttypes)) then
   {
      _mintalt = 10;
   };
};

_remote  = false;
if ("REMOTE" in _ttypes) then
{
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



if (!_radio) then 
{
   _disp setVariable ["mando_gunattacker_radio", false];
}
else
{
   _disp setVariable ["mando_gunattacker_radio", true];
};


_log_sound = "logic" createVehicleLocal (_disp modelToWorld _firingpos);

if (!_active) then 
{
   _disp setVariable ["mando_gunattacker_on", false];
}
else
{
   _disp setVariable ["mando_gunattacker_on", true];
   _mccstate = true;

   if (
       (((_unitpos == 0) && !(isNull driver _disp) && (alive driver _disp) && !(isPlayer driver _disp)) ||
       ((_unitpos == 1) && !(isNull gunner _disp) && (alive gunner _disp) && !(isPlayer gunner _disp)) ||
       ((_unitpos == 2) && !(isNull commander _disp) && (alive commander _disp) && !(isPlayer commander _disp)) ||
       (_unitpos > 2)) &&
       (alive _disp) && !(isNull _disp)) then
   {
      if (_radaronsound != "") then {_disp say _radaronsound;};

      if ((_disp getVariable "mando_gunattacker_radio") && !(isNull _unit))then
      {
         if (!isNull _unit) then
         {
            _unit sideChat format["%1 switching on GCC", _disp];
         };
      };
   
      if (_createtrigger) then
      {
         mando_radar_on = _disp;publicVariable "mando_radar_on";
      };
   };
};

if (_createtrigger) then
{
   _trigger = createTrigger ["EmptyDetector", getPos _disp];
   _trigger setTriggerActivation ["ANY", "PRESENT", false];
   _trigger setTriggerArea [_maxrange, _maxrange, 0, false];
   _trigger setTriggerType "NONE";
   _trigger setTriggerStatements ["this", "", ""];
   _trigger setTriggerTimeout [0, 0, 0, false ];
};

_refresh_state = 0;



while {(alive _disp)&&!(isNull _disp)} do
{

   if (!(_disp getVariable "mando_gunattacker_on") ||
       ((_unitpos == 0) && ((isNull driver _disp) || (!alive driver _disp) || (isPlayer driver _disp))) ||
       ((_unitpos == 1) && ((isNull gunner _disp) || (!alive gunner _disp) || (isPlayer gunner _disp))) ||
       ((_unitpos == 2) && ((isNull commander _disp) || (!alive commander _disp) || (isPlayer commander _disp)))) then 
   {
      if (_mccstate) then 
      {
         if (_radaroffsound != "") then 
         {
            _disp say _radaroffsound;
         };

         if (_createtrigger) then
         {
            mando_radar_off = _disp;publicVariable "mando_radar_off";
         };

         if (_disp getVariable "mando_gunattacker_radio") then
         {
            if ((alive _unit) && (_unit in _disp)) then
            {
               _unit sideChat format["%1 switching off GCC", _disp];
            };
         };
         _mccstate = false;
      };

      while {(!(_disp getVariable "mando_gunattacker_on") ||
             ((_unitpos == 0) && ((isNull driver _disp) || (!alive driver _disp) || (isPlayer driver _disp))) ||
             ((_unitpos == 1) && ((isNull gunner _disp) || (!alive gunner _disp) || (isPlayer gunner _disp))) ||
             ((_unitpos == 2) && ((isNull commander _disp) || (!alive commander _disp) || (isPlayer commander _disp)))) &&
             (alive _disp) && !(isNull _disp)} do
      {
         Sleep 2;
      };

      if ((!alive _disp) || (isNull _disp)) exitWith {};   

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
            };
         };
      };


      if (_radaronsound != "") then {_disp say _radaronsound;};

      if (_createtrigger) then
      {
         mando_radar_on = _disp;publicVariable "mando_radar_on";
      };


      if (_disp getVariable "mando_gunattacker_radio") then
      {
         _unit sideChat format["%1 switching on GCC", _disp];
      };
      _mccstate = true;      
   };

   if ((!alive _disp) || (isNull _disp)) exitWith {};   



   if (_disparado) then 
   {
      _disparado = false;
      _espera = (_wait - 4) max 1;
   }
   else
   {
      _espera = 1;
   };

   sleep _espera;

   if ((alive _unit) && (vehicle _unit == _disp) && (alive _disp) && (_quantity > 0) && (!isNull _disp) && (!isNull _unit) && !(combatMode _unit == "BLUE")) then 
   {

      //List of units affected by the scan area
      if ((!alive _disp) || (isNull _disp)) exitWith {};

      _refresh_state = _refresh_state + 1;
      if (_refresh_state > 5) then
      {
         if (_createtrigger) then
         {
            mando_radar_on = _disp;publicVariable "mando_radar_on";
         };
         _refresh_state = 0;
      };


      _list = [];
      if (_createtrigger) then
      {
         _trigger setPos getPos _disp;
         if (count _ttypes > 0) then
         {
//            {if (fuel _x < 1.0) then {_list = _list + [_x]}} forEach list _trigger;
            {if ((driver _x != _x) || (_menpresent)) then {_list = _list + [_x]}} forEach list _trigger;
         };
      };

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
         };
      };


      _log_sound setPos (_disp modelToWorld _firingpos);
      _endofunits = (count _list) - 1;
      if (_antimissile) then 
      {
         // missiles in flight in range against friendly units are added to the list

         _i = 0;
         {if ( (side (mando_detowners select _i) in _enemysides)&&((_x distance _disp)<_maxrange)) then {_list = _list + [_x]};_i=_i+1} forEach mando_detmissiles;
      };

      _blanco = objNull;
      if (count _list > 0) then 
      {
         //Heading of the vehicle (if any) of the firing unit
         _vdir = vectorDir _disp;
         _dird = (_vdir select 0) atan2 (_vdir select 1);
         /* I store the knowledges and angles of all units inside scan area that are not almost destroyed and of different side than the firing unit */

         _posdisp = getPos _disp;

         _mindist = 99999;
         _count = count _list;



         for [{_i = 0},{_i < _count},{_i = _i + 1}] do
         {
            _enemigo = _list select _i;
            _posfoe = getPos _enemigo;
            _altenemigo = _posfoe select 2;
            _bandoenemigo = side _enemigo;
            _know = 0.0;
            _ang  = 9999.0;
            _dist = _enemigo distance _disp;

            _targetmissile = false;            

            if ((_altenemigo >= _mintalt) && (_altenemigo <= _maxtalt) && 
                (_dist >= _minrange) && (_dist <= _maxrange) && 
                (alive _enemigo) && 
                ((_bandoenemigo in _enemysides)||(_i > _endofunits)) ) then 
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
                     _blanco = _enemigo;
                  }
                  else
                  {
                     if (_dist < _mindist) then 
                     {
                        if ((fuel _enemigo < 1) || (_enemigo isKindOf "Man")) then
                        {
                           _mindist = _dist;
                           _blanco = _enemigo;

                        };
                     };
                  };
               };
            };
         };


         //If a unit accomplish the requirements to be targeted
         if (!isNull _blanco) then 
         {
            //Now we have a target
            mando_lockedon=_blanco;
            publicVariable "mando_lockedon";

            if (_disp getVariable "mando_gunattacker_radio") then
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

            //Add here anyother target validation rule before firing the gun
         
            //gun is aimed
            _timeini = daytime * 3600;
            _towait = _aimtime + 1 - random 2;

_mcoords = _disp worldToModel (getPos _blanco);
//_anghanim = (_mcoords select 0) atan2 (_mcoords select 1);
_anghanim = ((_mcoords select 0) - (_firingpos select 0)) atan2 ((_mcoords select 1) - (_firingpos select 1));
_angvanim = asin (((_mcoords select 2) - (_firingpos select 2))/(_disp distance _blanco));
[_disp, _anghanim, _angvanim] spawn _animcode;
//_disp animate ["x_base", _anghanim/180];
//_disp animate ["y_base", _angvanim/-180];
Sleep 0.5;


            if (_unitpos == 1) then
            {
               gunner _disp doTarget _blanco;
               while {(daytime * 3600) < (_timeini + _towait)} do
               {
                  if (!isNull _blanco) then
                  {
                     gunner _disp dowatch getPos _blanco;
                  };
                  Sleep 0.1;
               };
            };

            //gun is fired
            if ((alive _disp) && (alive _unit) && (!isNull _blanco)) then 
            {
               mando_gun_sound = _salvosound;
               mando_gun = _log_sound;
               
               publicVariable "mando_gun_sound";
               publicVariable "mando_gun";

               for [{_j = 0},{_j < _rounds_salvo},{_j = _j + 1}] do
               {
                  _tti = ((_disp distance _blanco)/_muzzlevel)+(_j/_rounds_salvo)*0.5;
                  _posfoe = getPosASL _blanco;
                  _vel = velocity _blanco;

                  _posfoe = [(_posfoe select 0)+(_vel select 0)*_tti,(_posfoe select 1)+(_vel select 1)*_tti,(_posfoe select 2)+(_vel select 2)*_tti];
                      
                  _effects = false;
                  if ((_j mod 2) == 0) then
                  {
                     _effects = true;
                  };
                  if (!isNull _blanco) then
                  {
                     [_disp, _firingpos, _firinggun, _barrellength, [_posfoe select 0,_posfoe select 1,_posfoe select 2, _blanco], _maxdisp, _detonate, _ammotype, _muzzlevel, _effects, _animcode]execVM"mando_missiles\mando_gun\mando_gun.sqf";

//                     [_disp, _firingpos, _firinggun, _barrellength, _blanco, _maxdisp, _detonate, _ammotype, _muzzlevel, _effects, _animcode]execVM"mando_missiles\mando_gun\mando_gun.sqf";
                  };
                  Sleep 0.04;
               };

               _disparado = true;
               _quantity = _quantity - 1;
  
               if (_disp getVariable "mando_gunattacker_radio") then
               {
                  if (_quantity != 1) then
                  {
                     _unit sideChat format["%1 firing salvo! %2 salvos left", _disp, _quantity];
                  }
                  else
                  {
                     _unit sideChat format["%1 firing salvo! 1 salvos left", _disp];
                  };
               };
            };
         };
      };
   };

   if ((_quantity == 0) && (alive _disp) && (alive _unit)) then
   {
      _ammos = nearestObjects [_disp, ["Truck5tReammo", "UralReammo"], 12];


      if (count _ammos > 0) then
      {
         if (damage (_ammos select 0) < 0.5) then 
         {
            if (_disp getVariable "mando_gunattacker_radio") then
            {
               if (alive _unit) then
               {
                  _unit sideChat "Reloading ammo";
               };
            };
            Sleep 5;
            _quantity = _quantityini;
            if (alive _disp) then
            {
               if (_disp getVariable "mando_gunattacker_radio") then
               {
                  if (alive _unit) then
                  {
                     _unit sideChat "Ammo reloaded";
                  };
               };
            };
         };
      }; 
      Sleep 3;
   };
};

if (_disp getVariable "mando_gunattacker_radio") then
{
   if ((alive _unit) && (_unit in _disp)) then
   {
      _unit sideChat format["%1 switching off GCC", _disp];
   };
};

if (_createtrigger) then
{
   mando_radar_off = _disp;publicVariable "mando_radar_off";
};


if (_radaroffsound != "") then {_disp say _radaroffsound;};

if (_createtrigger) then
{
   deleteVehicle _trigger;
};

deleteVehicle _log_sound;