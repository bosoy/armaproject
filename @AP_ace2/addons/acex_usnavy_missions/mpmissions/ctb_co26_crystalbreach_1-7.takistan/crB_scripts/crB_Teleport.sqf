//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Contact: http://creobellum.org
// Purpose: Teleport group to map click loc
///////////////////////////////////////////////////////////////////
if(isServer && !(local player)) exitWith{};
if (typeName _this == "ARRAY") then {
	_unit = _this select 1;
	_obj = (_this select 3) select 0;
	_pos = getPosASL _obj;
	_RandX = (random 20) - 10;
	_RandY = (random 20) - 10;
	_unit setPosASL [(_pos select 0) + _RandX, (_pos select 1) + _RandY, (_pos select 2)];
} else {
	if(player == _this) then {
		titleText ["Click on map to teleport your group", "PLAIN"];
		player onMapSingleClick "{_x setPos _pos;} forEach units _this;";
	};
};