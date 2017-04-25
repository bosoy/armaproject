if (isServer && isNull player) exitWith {};
waitUntil {!isNull player};

_color="ColorRed";
if (side player == WEST) then
{
	_color="ColorBlue";
};

_infUnits = units group player;
_infMarkers = [];
for "_i" from 0 to 20 do {
	_currentMarker = createMarkerLocal [format ["mrki%1", _i], [1,1]];
	_currentMarker setMarkerShapeLocal "ICON";
	_currentMarker setMarkerTypeLocal "mil_triangle";
	_currentMarker setMarkerColorLocal _color;
	_currentMarker setMarkerSizeLocal [0.5,1];
	_infMarkers = _infMarkers + [_currentMarker];
};

while {true} do
{
	_infUnits = units group player;
	_i=0;
	while {_i<count _infUnits} do
	{		
		_currentUnit = _infUnits select _i;
		_currentMarker = _infMarkers select _i;
		
		if (alive _currentUnit && vehicle _currentUnit == _currentUnit) then
		{
			_currentMarker setMarkerAlphaLocal 1;
			_currentMarker setMarkerPosLocal [(getPos _currentUnit select 0),
						  	(getPos _currentUnit select 1)];
			_currentMarker setMarkerDirLocal (direction _currentUnit);
			if (getDammage _currentUnit > 0.1) then
			{
				_currentMarker setMarkerAlphaLocal 0.5;
			};
			if (player == _currentUnit) then
			{
				_currentMarker setMarkerColorLocal "ColorGreen";
			}
			else
			{
				_currentMarker setMarkerColorLocal _color;
			};
		}
		else
		{
			_currentMarker setMarkerAlphaLocal 0;
		};
		_i=_i+1;
	};
	
	while {_i<21} do
	{
		_currentMarker = _infMarkers select _i;
		_currentMarker setMarkerAlphaLocal 0;
		_i=_i+1;
	};
	
	sleep 1;
};