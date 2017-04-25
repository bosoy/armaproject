// Missile parameters
private [
	"_pos",
	"_target",
	"_side",
	"_launcher",
	"_handle"
];

_pos = _this select 0;
_target = _this select 1;
_side = _this select 2;
_launcher = _this select 3;

if (!local _launcher) exitWith {};

_post = getPos _target;
_targets = [];

_firingdir = ((_post  select 0)-(getPos _launcher select 0)) atan2 ((_post select 1)-(getPos _launcher select 1));
_firingdir = _firingdir - 120;
for [{_i=0},{_i<3},{_i=_i+1}] do
{
	_log = "logic" createVehicleLocal [0,0,0];
	_log setPos [(_post select 0)+sin(_firingdir)*(1600 + random 300),(_post select 1)+cos(_firingdir)*(1600 + random 300),0];
	_targets = _targets + [_log];

	_launcher         = objNull;
	_target           = _log;
	_missilebody      = "M_Sidewinder_AA";
	_firingpos        = _pos;
	_vangle           = -45.0;
	_speedini         = 10;
	_speedmax         = 400;
	_acceleration     = 200;
	_boomrange        = 250;
	_activerange      = 4000;
	_modeinit         = 2;
	_cruisealt        = 100;
	_boomscript       = "mando_missiles\warheads\echo\w80_air.sqf"; 
	_smokescript      = "mando_missiles\exhausts\mando_missilesmoke1a.sqf";
	_soundrsc         = "mando_missile1";
	_sounddur         = 29;
	_endurance        = 30;
	_terrainavoidance = false;
	_updatefreq       = 1;
	_delayinit        = 0;
	_controltime      = 0;
	_detectable       = true;
	_debug            = false;
	_launchscript     = "";
	_hagility         = 55;
	_vagility         = 90;
	_accuracy         = 1;
	_intercept        = true;
	_scanarch         = 180;
	_scanarcv         = 180;
	_zoffset          = 0;
	_cextent          = 1;

	[_launcher, _missilebody, _firingpos, _firingdir, _vangle, _speedini, _speedmax, _acceleration, _target, _boomrange, _activerange, _modeinit, _cruisealt, _boomscript, _smokescript, _soundrsc, _sounddur, _endurance, _terrainavoidance, _updatefreq, _delayinit, _controltime, _detectable, _debug, _launchscript, _hagility, _vagility, _accuracy, _intercept, _scanarch, _scanarcv, _zoffset, _cextent] execVM "mando_missiles\mando_missile.sqf";	

	_firingdir        = _firingdir + 120;
	Sleep 0.1;


};

Sleep 30;
{deleteVehicle _x} forEach _targets;