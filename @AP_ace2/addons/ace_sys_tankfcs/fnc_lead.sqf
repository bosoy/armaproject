#include "script_component.hpp"
#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __maxlead getNumber(__vehcfg >> "ace_tankfcs_maxlead")

PARAMS_4(_veh,_wpn,_range,_flighttime);

private ["_a","_weapondir","_wx","_wy","_wz","_weapondirang","_weaponazimuth",
"_weaponelevation","_azimuthspeed","_tankvel","_timearray","_avgtime","_newweaponazimuth",
"_trackangle1","_trackangle2","_trackangledelta","_tankvelx","_tankvely","_targetx1","_targetx2",
"_targety1","_targety2","_targetvelx","_targetvely","_predictedx","_predictedy",
"_predictedazimuth","_tankspeed","_targetspeed","_lead","_maxlead"];

if (__maxlead <= 0 ) exitwith {0};

_weapondir = _veh weaponDirection _wpn;
_wx = _weapondir select 0;
_wy = _weapondir select 1;
_wz = _weapondir select 2;
_weapondirang = [_wx atan2 _wy, sqrt(_wy*_wy + _wx*_wx) atan2 (-_wz)];
_weaponazimuth = _weapondirang select 0;
_weaponelevation = _weapondirang select 1;

_azimuthspeed = ((_veh getVariable "ace_turret_speed") select 0) * 180/pi; // average turret rotation speed (in world coordinates)
_tankvel = _veh getVariable "ace_avg_tank_velocity"; // average tank velocity (in world coordinates)
//if (_azimuthspeed < 0.05) exitwith {0};

_timearray = _veh getVariable "ace_turret_time";
_avgtime = -(_timearray select 0) + (_timearray select (count _timearray - 1));

_newweaponazimuth = _weaponazimuth - _azimuthspeed*_avgtime;

_trackangle1 = [sin(_weaponelevation) * sin(_newweaponazimuth), sin(_weaponelevation) * cos(_newweaponazimuth), - cos(_weaponelevation)];
_trackangle2 = _weapondir;

_trackangledelta = [(_trackangle2 select 0)-(_trackangle1 select 0),(_trackangle2 select 1)-(_trackangle1 select 1)];

_tankvelx = (_tankvel select 0);
_tankvely = (_tankvel select 1);

_targetx1 = (_trackangle1 select 0) * _range - _tankvelx * _avgtime;
_targety1 = (_trackangle1 select 1) * _range - _tankvely * _avgtime;

_targetx2 = (_trackangle2 select 0) * _range;
_targety2 = (_trackangle2 select 1) * _range;

_targetvelx = (_targetx2 - _targetx1) / _avgtime;
_targetvely = (_targety2 - _targety1) / _avgtime;

_predictedx = _targetx2 + _targetvelx * _flighttime;
_predictedy = _targety2 + _targetvely * _flighttime;

_predictedazimuth = _predictedx atan2 _predictedy;

_tankspeed = sqrt( _tankvelx^2 + _tankvely^2 );
_targetspeed = sqrt( _targetvelx^2 + _targetvely^2 );

_predictedazimuth = _predictedazimuth call CBA_fnc_simplifyAngle;
_weaponazimuth = _weaponazimuth call CBA_fnc_simplifyAngle;

_lead = (_predictedazimuth - _weaponazimuth);

// hint format ["Azimuth change: %1\nOwn speed: %2\nTarget speed: %3\nTarget position: [%4,%5]\nPredicted position: [%6,%7]\nLead: %8",_trackangledelta,_tankspeed,_targetspeed,_targetx2,_targety2,_predictedx,_predictedy,_lead];
_maxlead = __maxlead;
//if (_lead > _maxlead || {_lead < -_maxlead} ) then { _lead = 0 };

_lead = (-_maxlead) max (_maxlead min _lead);

_lead
