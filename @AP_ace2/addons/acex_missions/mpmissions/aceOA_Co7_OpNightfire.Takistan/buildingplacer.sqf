//buildingplacer.sqf
_dude = _this select 0;
_dude setunitpos "UP";
_building = nearestbuilding _dude;
_buildingposcount = 0;
while { str(_building buildingPos _buildingposcount) != "[0,0,0]" } do {_buildingposcount = _buildingposcount + 1};
if (_buildingposcount > 0) then {_dude setpos (_building buildingPos round random _buildingposcount)};