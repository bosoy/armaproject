_varName = _this select 0;
_basePos = markerPos (_this select 1);

waitUntil {!isNil "_varName"};

while {true} do
{
	_unit = missionNameSpace getVariable _varName;
	waitUntil {!alive (missionNameSpace getVariable _varName)};
	if (_unit distance _basePos > 70) then
	{
		deleteVehicle _unit;
	};
	waitUntil {alive (missionNameSpace getVariable _varName)};
};