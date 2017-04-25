//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// read the vehicles config, see if it has GBU or hellfire in its mag config
private["_mags", "_ret", "_turrets", "_childConfig", "_i"];
//_vehicleClass = _this select 0;
PARAMS_1(_vehicleClass);

_ret = false;

FUNC(searchMags) = {
	private["_s", "_laserGuidedMunitionStrings", "_mags", "_ret"];
	_ret = false;
	_mags = _this select 0;
	
	_laserGuidedMunitionStrings = ["GBU", "Hellfire", "DAGR"];
	{
		_s = _x;
		{
			if( ( [_s, _x] call CBA_fnc_find ) > -1) exitWith {
				_ret = true;
			};
		} forEach _laserGuidedMunitionStrings;
		if(_ret) exitWith { _ret = true; };
	} forEach _mags;

	_ret
};

_mags = getArray (configFile >> "CfgVehicles" >> _vehicleClass >> "magazines");
_ret = [_mags] call FUNC(searchMags);

if(!_ret) then {
	// annnd pull the turrets
	_i = 0;
	while { _i < (count ( configFile >> "CfgVehicles" >> _vehicleClass >> "Turrets" ) ) } do {
		private["_childConfig"];
		_childConfig = ( ( configFile >> "CfgVehicles" >> _vehicleClass >> "Turrets") select _i );

		_mags = getArray ( _childConfig >> "magazines");
		_ret = [_mags] call FUNC(searchMags);
		
		_i = _i + 1;
	};
};

TRACE_1("FINAL", _ret);
_ret
