if ((count _this) < 1) exitWith {debugLog "Log: [returnVehicleTurrets] Function requires at least 1 parameter!"; []};

private ["_entry"];
_entry = _this select 0;

//Validate parameters
if ((typeName _entry) != (typeName configFile)) exitWith {debugLog "Log: [returnVehicleTurrets] Entry (0) must be a Config!"; []};

private ["_turrets", "_turretIndex"];
_turrets = [];
_turretIndex = 0;

//Explore all turrets and sub-turrets recursively.
for "_i" from 0 to ((count _entry) - 1) do
{
	private ["_subEntry"];
	_subEntry = _entry select _i;
	
	if (isClass _subEntry) then
	{
		private ["_hasGunner","_primaryCom","_primaryGun"];
		_hasGunner = [_subEntry, "hasGunner"] call BIS_fnc_returnConfigEntry;
		
		_primaryGun = [_subEntry, "primaryGunner"] call BIS_fnc_returnConfigEntry;
		_primaryCom = [_subEntry, "primaryObserver"] call BIS_fnc_returnConfigEntry;
		
		if !(isNil "_primaryGun") then {if (_primaryGun == 1) then {vhasGunner = true}};
		if !(isNil "_primaryCom") then {if (_primaryCom == 1) then {vhasCommander = true}};
		
		//Make sure the entry was found.
		if !(isNil "_hasGunner") then 
		{
			if (_hasGunner == 1) then 
			{
				_turrets = _turrets + [_turretIndex];
				
				//Include sub-turrets, if present.
				if (isClass (_subEntry >> "Turrets")) then 
				{
					_turrets = _turrets + [[_subEntry >> "Turrets"] Call Compile preprocessFile "Common\Functions\Common_GetConfigVehicleTurretsReturn.sqf"];
				} 
				else 
				{
					_turrets = _turrets + [[]];
				};
			};
		};

		_turretIndex = _turretIndex + 1;
	};
};

_turrets