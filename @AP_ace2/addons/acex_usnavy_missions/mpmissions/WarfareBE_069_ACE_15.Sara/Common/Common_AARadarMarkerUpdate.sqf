Private ["_height","_object","_markerName","_side","_zOffset"];

waitUntil {commonInitComplete};
sleep 2;

_object = _this select 0;
_side = _this select 1;

if (_side == side player || isNull _object ||!(alive _object)) exitWith {};

_markerName = Format ["unitMarker%1",unitMarker];
unitMarker = unitMarker + 1;

createMarkerLocal [_markerName,[0,0,0]];
_markerName setMarkerTypeLocal "Vehicle";
_markerName setMarkerColorLocal "ColorRed";
_markerName setMarkerSizeLocal [5,5];
_markerName setMarkerAlphaLocal 0;
_height = 'WFBE_ANTIAIRRADARDETECTION' Call GetNamespace;

while {alive _object && !(isNull _object)} do {
	if (antiAirRadarInRange) then {
		_zOffset = (getPos _object) select 2;
		if (_zOffset > _height) then {
			_markerName setMarkerAlphaLocal 1;
			_markerName setMarkerPosLocal (getPos _object);
		} else {
			_markerName setMarkerAlphaLocal 0;
		};
	};
	
	sleep 1;
};

deleteMarkerLocal _markerName;