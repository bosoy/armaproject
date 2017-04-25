Private ['_isOnMap','_timeToKill'];

_timeToKill = 'WFBE_OFFMAPMAXTIME' Call GetNamespace;
paramBoundariesRunning = true;

while {true} do {
	sleep 1;
	_isOnMap = Call BoundariesIsOnMap;
	if !(_isOnMap) then {
		hint parseText(Format[localize 'STR_WF_OffmapWarning',_timeToKill]);
		_timeToKill = _timeToKill - 1;
	};
	if (_timeToKill < 0 || _isOnMap || !(alive player)) exitWith {
		if !(_isOnMap && alive player) then {(vehicle player) setDamage 1};
		paramBoundariesRunning = false;
	};
};