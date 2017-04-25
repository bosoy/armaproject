Private ["_ainumber","_amount","_color","_finalNumber","_isMan","_markerName","_numbers","_params","_side","_size","_text","_txt","_type","_unit","_val","_val2"];
_unit = _this select 0;
_side = _this select 1;

if (isNull _unit) exitWith {};

waitUntil {commonInitComplete};
sleep 2;

_isMan = if (_unit isKindOf "Man") then {true} else {false};

if !(_isMan) then {
	if (('WFBE_INCOMINGMISSILEMAXRANGE' Call GetNamespace) != 0) then {_unit addEventHandler ['IncomingMissile', {_this Spawn HandleIncomingMissile}]};
	
	if !(WF_A2_Vanilla) then {
		if ('WFBE_THERMALIMAGING' Call GetNamespace < 2) then {Call Compile '_unit disableTIEquipment true;'};
	};
};

if (sideJoined != _side) exitWith {};

_type = "Vehicle";
_color = "ColorGreen";
_size = [5,5];
_txt = "";
if ((typeOf _unit) in (Format['WFBE_%1SUPPLYTRUCKS',str _side] Call GetNamespace)) then {_type = "SupplyVehicle";_size = [1,1]};
if ((typeOf _unit) in (Format['WFBE_%1REPAIRTRUCKS',str _side] Call GetNamespace)) then {_type = "RepairVehicle"};

unitMarker = unitMarker + 1;

_markerName = Format ["unitMarker%1",unitMarker];
_params = [];
if (_isMan) then {
	_color = "ColorYellow";
	_type = "mil_dot";
	_size = [0.5,0.5];
	if (group _unit == group player) then {
		_color = "ColorOrange";
		_txt = (_unit) Call GetAIDigit;
	};
	_params = [_type,_color,_size,_txt,_markerName,_unit,1,true,"DestroyedVehicle",_color,false,_side,[1,1]];
} else {
	if (local _unit && isMultiplayer) then {_color = "ColorOrange"};
	_params = [_type,_color,_size,_txt,_markerName,_unit,1,true,"DestroyedVehicle",_color,false,_side,[2,2]];
};

_params Spawn MarkerUpdate;