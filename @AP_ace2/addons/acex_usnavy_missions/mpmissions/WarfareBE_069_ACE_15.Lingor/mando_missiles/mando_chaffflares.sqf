/*
   mando chaffflares
   mando_chaffflares.sqf v1.0
   Sep 2009 Mandoble

   Sends the global order to genenerate a chaff or flares "clouds" able to attract mando_missile missiles aproaching in mode 2 (active mode)

   Parameters:
      Launcher unit
      Chaff (0) or Flares (1)
*/
private["_launcherecm", "_typeecm", "_posecm", "_chaffflare", "_flare", "_var", "_flares"];

_launcherecm = _this select 0;
_typeecm     = _this select 1;
_posecm = _launcherecm modelToWorld [0,-8,-2];

// _chaffflare = "Roadcone" createVehicle [0,0,1002];
_chaffflare = "Baseball" createVehicle [0,0,1002];

_chaffflare setPos _posecm;
_chaffflare setVelocity [-(vectorDir _launcherecm select 0)*30 + (velocity _launcherecm select 0),-(vectorDir _launcherecm select 1)*30 + (velocity _launcherecm select 1),-(vectorDir _launcherecm select 2)*30 +(velocity _launcherecm select 2)]; 

mando_missilechafflauncher = _launcherecm;
mando_missilechaff = _chaffflare;
mando_missilechaffdraw = _typeecm;
{publicVariable _x} forEach ["mando_missilechaff","mando_missilechafflauncher","mando_missilechaffdraw"];

_flares = [];
_var = _launcherecm getVariable "mando_alive_flares";
if (!isNil "_var") then
{
   _flares = +_var;
   _flares = _flares - [objNull];
   _flares = _flares + [_chaffflare];
   _launcherecm setVariable ["mando_alive_flares", _flares, true];
}
else
{
   _launcherecm setVariable ["mando_alive_flares", [_chaffflare], true];
};


Sleep 4;
deleteVehicle _chaffflare;
deleteVehicle _flare;
