/* mando_airtorpedo.sqf
By Mandoble Fed 2008
*/


_launcher = _this select 0;
_pos      = _launcher modelToWorld (_this select 1);
_target   = _this select 2;
_torp = "mu90" createVehicle _pos;
_torp setPos _pos;

_torp setVectorDir vectorDir _launcher;
_torp setVectorUp vectorUp _launcher;
_torp setVelocity velocity _launcher;

waitUntil {(getPos _torp select 2) < 70};
_laspos = getPos _torp;
_lastdir = vectorDir _torp;
_lastvel = velocity _torp;
_lastup  = vectorUp _torp;
_torp setVelocity [0,0,0];

_torpchute = "ParachuteWest" createVehicle getPos _torp;
_torpchute setPos getPos _torp;
_torpchute setVectorDir _lastdir;
_torpchute setVectorUp _lastup;
_torpchute setVelocity _lastvel;


while {(getPos _torp select 2) > 0.1} do
{
   _torp setPos (_torpchute modelToWorld [0,0,-1]);
   _torp SetVectorUp (vectorUp _torpchute);
   sleep 0.01;
};

Sleep 2;

_launcher         = objNull;
_missilebody      = "mu90";
_vangle           = -1.5;
_speedini         = 15;
_speedmax         = 50;
_acceleration     = 15;
_boomrange        = 5;
_activerange      = 600;
_modeinit         = 1;
_cruisealt        = -4;
_boomscript       = mando_missile_path+"warheads\mando_missileheadtorp.sqf";
_smokescript      = mando_missile_path+"exhausts\mando_torpedowater1a.sqf";
_soundrsc         = "";
_sounddur         = 29;
_endurance        = 140;
_terrainavoidance = false;
_updatefreq       = 2;
_delayinit        = 2;
_controltime      = 0;
_detectable       = false;


_debug            = true;


_launchscript     = "";
_hagility         = 30;
_vagility         = 30;
_accuracy         = 1;
_intercept        = false;
_scanarch         = 180;
_scanarcv         = 90;
_offsety          = -5;
 
[_launcher, _missilebody, [getPos _torp select 0, getPos _torp select 1, getPos _torp select 2], getDir _torp, _vangle, _speedini, _speedmax, _acceleration, _target, _boomrange, _activerange, _modeinit, _cruisealt, _boomscript, _smokescript, _soundrsc, _sounddur, _endurance, _terrainavoidance, _updatefreq, _delayinit, _controltime, _detectable, _debug, _launchscript,_hagility, _vagility, _accuracy, _intercept, _scanarch, _scanarcv,_offsety] execVM mando_missile_path+"mando_missile.sqf";

deleteVehicle _torp;                
