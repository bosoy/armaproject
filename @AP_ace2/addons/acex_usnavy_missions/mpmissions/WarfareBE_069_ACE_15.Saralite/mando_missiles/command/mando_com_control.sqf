/* 
 mando_com_comtrol.sqf

 Sep 2007 Mandoble
*/

private ["_params", "_commanded", "_range", "_unit", "_sam", "_selected", "_map", "_commdisplay", "_wps", "_dist", "_ang", "_pos"];

_params = (_this select 3);
_commanded = _params select 0;
_range = _params select 1;

_unit = vehicle player;

mando_command_idx = -1;
_mando_command_idx = -1;
mando_com_coords = [0,0,0];
_mando_com_coords = [0,0,0];
mando_command_on = false;
mando_command_off = false;

mando_command_own_off = false;
mando_command_own_on = false;

_wps = [];
{_wps = _wps + [[-1,-1]]} forEach _commanded;


_ok = createDialog "DlgMissileCommand";

[_commanded]execVM mando_missile_path+"command\mando_com_camera.sqf";
[_unit, _range]execVM mando_missile_path+"command\mando_com_radar.sqf";

_commdisplay = findDisplay 23900;


_map = ((findDisplay 23900) displayCtrl 23903);

for [{_i=0},{_i < count _commanded},{_i=_i+1}] do
{
   _mkname = format["mando_commanded_rgn%1", _i];
   createMarkerLocal [_mkname, getPos ((_commanded select _i) select 0)];
   _mkname setMarkerColorLocal "ColorGreenAlpha";
   _mkname setMarkerBrushLocal "Horizontal";
   _mkname setMarkerShapeLocal "ELLIPSE";
   _mkname setMarkerSizeLocal [0,0];
};


for [{_i=0},{_i < count _commanded},{_i=_i+1}] do
{
   _mkname = format["mando_commanded_%1", _i];

   lbAdd [23902, _mkname];

   createMarkerLocal [_mkname, getPos ((_commanded select _i) select 0)];
   _mkname setMarkerColorLocal "ColorBlue";
   _mkname setMarkerTypeLocal "Select";
   _mkname setMarkerTextLocal _mkname;
   _mkname setMarkerSizeLocal [1, 1];
};


for [{_i=0},{_i < count _commanded},{_i=_i+1}] do
{
   _mkname = format["mando_commanded_wp%1", _i];
   createMarkerLocal [_mkname, getPos ((_commanded select _i) select 0)];
   _mkname setMarkerColorLocal "ColorBlue";
   _mkname setMarkerShapeLocal "RECTANGLE";
   _mkname setMarkerSizeLocal [0,0];
};


_selected = (_commanded select 0) select 0;
mando_command_idx = 0;

while {!isNull _commdisplay} do
{
   if (mando_command_own_on) then
   {
      mando_command_own_on = false;
      mando_command_radar = 1;
   };

   if (mando_command_own_off) then
   {
      mando_command_own_off = false;
      mando_command_radar = 0;
   };


   if (mando_command_idx != _mando_command_idx) then
   {
      format["mando_commanded_%1", _mando_command_idx] setMarkerColorLocal "ColorBlue";
      _mando_command_idx = mando_command_idx;
      _selected = (_commanded select _mando_command_idx) select 0;
      format["mando_commanded_%1", _mando_command_idx] setMarkerColorLocal "ColorYellow";
      _map ctrlMapAnimAdd [0.01, 1, getPos _selected];
      ctrlMapAnimCommit _map;     
   };

   if (((mando_com_coords select 0) != (_mando_com_coords select 0)) || ((mando_com_coords select 1) != (_mando_com_coords select 1))) then
   {
      _mando_com_coords = [mando_com_coords select 0, mando_com_coords select 1];
      if (_mando_command_idx >= 0) then
      {
/*
         (driver _selected) setBehaviour "SAFE";
         (driver _selected) doMove mando_com_coords;
*/

         mando_remote_command = format["if (local %1) then {%1 commandMove %2}", _selected, mando_com_coords];
         publicVariable "mando_remote_command";


         (_selected) Move mando_com_coords;

         _wps set [_mando_command_idx,_mando_com_coords];
      };
   };
   
   if (mando_command_on) then
   {
      mando_command_on = false;
      if (!isNull _selected) then
      {
         [_selected, true]execVM mando_missile_path+"units\mando_attackeronoff.sqf";
      };
   };

   if (mando_command_off) then
   {
      mando_command_off = false;
      if (!isNull _selected) then
      {
         [_selected, false]execVM mando_missile_path+"units\mando_attackeronoff.sqf";
      };
   };


   for [{_i = 0},{_i < count _commanded},{_i = _i + 1}] do
   {
      _sam = (_commanded select _i) select 0;
      format["mando_commanded_%1", _i] setMarkerPosLocal getPos _sam;
      format["mando_commanded_rgn%1", _i] setMarkerPosLocal getPos _sam;

      if (_sam in mando_radars) then
      {
         format["mando_commanded_rgn%1", _i] setMarkerSizeLocal [(_commanded select _i) select 1, (_commanded select _i) select 1];
         format["mando_commanded_%1", _i] setMarkerTypeLocal "Select";
      }
      else
      {
         format["mando_commanded_rgn%1", _i] setMarkerSizeLocal [0, 0];
         format["mando_commanded_%1", _i] setMarkerTypeLocal "Dot";
      };


      if (((_wps select _i) select 0) > 0) then
      {
         _pos = _wps select _i;
         _dist = _sam distance _pos;
         _ang = ((_pos select 0)-(getPos _sam select 0)) atan2 ((_pos select 1)-(getPos _sam select 1));

         format["mando_commanded_wp%1", _i] setMarkerPosLocal [(getPos _sam select 0)+sin(_ang)*_dist/2, (getPos _sam select 1)+cos(_ang)*_dist/2];
         format["mando_commanded_wp%1", _i] setMarkerDirLocal _ang;
         format["mando_commanded_wp%1", _i] setMarkerSizeLocal [4, _dist/2];
      };
   };

   Sleep 0.2;

   if (damage _unit > 0.5) then
   {
      CloseDialog 23900;
   };
};
