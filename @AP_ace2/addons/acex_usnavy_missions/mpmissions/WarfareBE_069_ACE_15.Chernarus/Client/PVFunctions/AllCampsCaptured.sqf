Private ["_alertOtherSide","_camp","_camps","_count","_marker","_sideID","_town"];

_town = _this Select 0;
_sideID = _this Select 1;
_alertOtherSide = _this Select 2;

_camps = _town getVariable "camps";

for [{_count = count _camps - 1},{_count >= 0},{_count = _count - 1}] do {
	_camp = _camps select _count;
	_marker = Format["%1Camp%2",str _town,_camps find _camp];

	if (sideID == _sideID) then {
		_marker setMarkerColorLocal ("Friendly" Call GetMarkerColoration);
	} else	{
		if (_alertOtherSide || getMarkerColor _marker == ("Friendly" Call GetMarkerColoration)) then {
			_marker setMarkerColorLocal ("Enemy" Call GetMarkerColoration);
		};
	};
};