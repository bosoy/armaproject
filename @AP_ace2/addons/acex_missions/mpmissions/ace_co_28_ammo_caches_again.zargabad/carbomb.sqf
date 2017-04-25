if (!isServer) exitWith {};
_driver = _this select 0;
_carBomb = vehicle _driver;
(group _driver) setBehaviour "CARELESS";
removeAllWeapons _driver;
_carBomb setVariable ["boom", false];

if (isNil "getCarbombTarget") then
{
	getCarbombTarget = 
	{
		_bestPrecision = 1000;
		_bestTargetPos = [1,1,1];
		{
			if (side _x == EAST || side _x == RESISTANCE) then
			{
				_targets = _x nearTargets 9999;
				{
					_pos = _x select 0;
					_side = _x select 2;
					_precision = _x select 5;
					_object = _x select 4;
					if (_side == WEST && _object isKindOf "LAND" && _object in (list trgTown)) then
					{
						if (_precision < _bestPrecision) then
						{
							_bestTargetPos = _pos;
							_bestPrecision = _precision;
						};
					};
				} forEach _targets;
			};
		} forEach allUnits;
			
		_bestTargetPos
	};
};

[_driver] spawn
{
	_driver = _this select 0;
	while {alive _driver} do
	{
		sleep 6 + random 6;
		_targetPos = [] call getCarbombTarget;
		if ((_targetPos select 0) != 1 || (_targetPos select 1) != 1 || (_targetPos select 2) != 1) then
		{
			_driver doMove _targetPos;
			(group _driver) setSpeedMode "FULL";
			(group _driver) setBehaviour "CARELESS";
		};
	};
};

[_carBomb, _driver] spawn
{
	_carBomb = _this select 0;
	_driver = _this select 1;
	waitUntil {_carBomb getVariable "boom" || getDammage _carBomb > 0.7 || vehicle _driver != _carBomb};
	if (!alive _driver) then
	{
		waitUntil {_carBomb getVariable "boom" || getDammage _carBomb > 0.7};
	};
	_bomb = createVehicle ["ARTY_Sh_81_HE", getPos _carBomb, [], 0, "NONE"];
	_bomb setPosASL getPosASL _carBomb;
	_driver setDammage 1;
	_carBomb setDammage 1;
};

_boom=false;
while {!_boom && _driver == driver _carBomb && alive _driver && getDammage _carBomb < 0.7 && getDammage _driver < 0.6} do
{
	sleep .5;
	_closeCount=0;
	_mediumCount=0;
	_farCount=0;
	_targets = _driver nearTargets 35;
	{
		_pos = _x select 0;
		_side = _x select 2;
		_precision = _x select 5;
		_object = _x select 4;
		if (_precision<1 && _side==WEST && _object isKindOf "LAND") then
		{
			_distance = _pos distance _driver;
			if (_distance<35) then
			{
				_farCount=_farCount+1;
			};
			if (_distance<28) then
			{
				_mediumCount=_mediumCount+1;
			};
			if (_distance<20) then
			{
				_closeCount=_closeCount+1;
			};
		};
	} forEach _targets;
	if (_farCount>2 || _mediumCount>1 || _closeCount>0) then
	{
		_boom=true;
	};
};

sleep .7;

if (alive _driver) then
{
	_carBomb setVariable ["boom", true];
};