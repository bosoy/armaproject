private ["_defense", "_side", "_sideID", "_turret", "_closestTown", "_reload", "_buildings", "_mhq", "_magazine"];

_defense = _this select 0;
_side = _this select 1;
_sideID = _side Call GetSideID;

if(!isArray(configFile >> "CfgVehicles" >> (typeOf _defense) >> "Turrets" >> "MainTurret" >> "weapons")) exitWith { };

_turret = getArray(configFile >> "CfgVehicles" >> (typeOf _defense) >> "Turrets" >> "MainTurret" >> "weapons") select 0;
_closestTown = [_defense] Call GetClosestLocation;

if(isNull _closestTown || _closestTown distance _defense > 400) then
{
	_closestTown = ObjNull;
};

// 0: no auto reloading
if(paramDefenseReloading == 0) exitWith { };

while { alive _defense } do
{
	sleep 10;
	if((_defense ammo _turret) == 0) then
	{
		_reload = false;
		
		// 3: Reload everywhere
		if(paramDefenseReloading == 3) then
		{
			_reload = true;
		};
		
		// 2: Reload near towns or base/HQ
		if(!_reload && paramDefenseReloading == 2) then
		{
			_reload = false;
			if(!isNull _closestTown && (_closestTown getVariable "sideID") == _sideID) then
			{
				_reload = true;
			};
		};
		
		// 1: Reload near base/HQ
		if(!_reload && (paramDefenseReloading == 1 || paramDefenseReloading == 2)) then
		{
			_buildings = (str _side) Call GetSideStructures;
			_mhq = call compile format ["%1MHQ", str _side];
			
			if(!isNil "_mhq") then
			{
				_buildings = _buildings + [ _mhq ];
			};
			
			{
				if(_defense distance _x < 200) exitWith
				{
					_reload = true;
				}
			} forEach(_buildings);
		};
		
		if(_reload) then
		{
			_magazine = (_defense magazinesTurret [0]) select 0;
			if(!isNil "_magazine") then
			{
				["ACE_sys_crewserved_remadd", [_defense, _magazine, 1]] call CBA_fnc_globalEvent;
			};
		};
	};
};