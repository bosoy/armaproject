/* 
 mando_com_radar.sqf
 Sep 2007 Mandoble
*/

private ["_unit", "_range", "_commdisplay", "_map", "_valid", "_veh", "_pos", "_posu", "_list", "_los_log", "_los_ok", "_dist", "_ncontacts", "_pos_asl", "_ang", "_ratev", "_timeini", "_command_radar"];

_unit = _this select 0;
_range = _this select 1;

_commdisplay = findDisplay 23900;

_los_log = "logic" createVehicleLocal [0,0,0];
_posu = [getPos _unit select 0,getPos _unit select 1,(getPos _unit select 2)+15];

_ncontacts = 0;
_timeini = dayTime * 3600;
mando_command_radar = 0;
_command_radar = mando_command_radar;

while {!isNull _commdisplay} do
{   
   if (_command_radar != mando_command_radar) then
   {
      _command_radar = mando_command_radar;

      if (_command_radar != 0) then
      {
         mando_radar_on = _unit;
         publicVariable "mando_radar_on";
      }
      else
      {
         mando_radar_off = _unit;
         publicVariable "mando_radar_off";
      };
   };

   if ((_command_radar > 0) && (dayTime * 3600 > (_timeini + 6))) then
   {
      mando_radar_on = _unit;
      publicVariable "mando_radar_on";
   };

   if (_command_radar > 0) then
   {
      for [{_i = 0},{_i < _ncontacts},{_i = _i + 1}] do
      {
         deleteMarkerLocal format["mando_com_cont%1",_i];
      };

      _ncontacts = 0;
      _list = [];
      _list = _list + vehicles;

      for [{_i = 0},{_i < count _list},{_i = _i + 1}] do
      {
         _veh = _list select _i;
         _pos = getPos _veh;

         if ((_pos select 2) > mando_minairalt) then
         {
            _dist = _veh distance _unit;
            if (_dist < _range) then
            {
               _los_log setPos _posu;
               _pos_asl = getPosASL _los_log;
               _ang = ((_pos select 0)-(_posu select 0)) atan2 ((_pos select 1)-(_posu select 1));
               _ratev = ((getPosASL _veh select 2) - (_pos_asl select 2))/_dist;
               _los_ok = true;

               for [{_j = 20},{(_j < ((_dist - 75) min 3000)) && _los_ok},{_j=_j + 50}] do
               {
                  _los_log setPosASL [(_pos_asl select 0)+sin(_ang)*_j,(_pos_asl select 1)+cos(_ang)*_j, (_pos_asl select 2)+_ratev*_j];
                  if ((getPos _los_log select 2) < 0.1) then
                  {
                     _los_ok = false;
                  };
               };
               Sleep 0.005;

               if (_los_ok) then
               {
                  _mkname = format["mando_com_cont%1",_ncontacts];
                  createMarkerLocal [_mkname, _pos];
                  if (side _veh != side _unit) then
                  {
                     _mkname setMarkerColorLocal "ColorRedAlpha";
                  }
                  else
                  {
                     _mkname setMarkerColorLocal "ColorBlue";
                  };
                  _mkname setMarkerTypeLocal "Arrow";
                  _mkname setMarkerTextLocal format["%1 km/h", speed _veh];
                  _mkname setMarkerSizeLocal [0.5,0.5];
                  _mkname setMarkerDirLocal getDir _veh;
                  _ncontacts = _ncontacts + 1;
               };
            };
         };
      };
   };
   Sleep 2;
};

for [{_i = 0},{_i < _ncontacts},{_i = _i + 1}] do
{
   deleteMarkerLocal format["mando_com_cont%1",_i];
};

Sleep 1;
mando_radar_off = _unit;
publicVariable "mando_radar_off";