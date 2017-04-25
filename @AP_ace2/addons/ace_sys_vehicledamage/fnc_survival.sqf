// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define SUBMERGED -2
#define ALMOST_SUBMERGED 0.2
#define CREW_CHECK 5

// Usage for e.g hummers; don't blow up in the water... allow to be towed out.
private["_r", "_pos", "_surfaceIsWater", "_eject_time", "_crew"];
PARAMS_5(_unit,_selectionName,_damage,_source,_projectile);

if !(alive _unit) exitwith {
	_hdehv = _unit getVariable QGVAR(hdeh);
	// remove hd eh because it still triggers even for dead objects
	if (!isNil "_hdehv") then {_unit removeEventHandler ["handleDamage", _hdehv]};
	false
};

_r = _damage;
// if !(local _unit) exitWith { _r };

_pos = getPos _unit;
_surfaceIsWater = surfaceIsWater _pos;

// TODO: Verify movement speed, and perhaps height; when flying into the water... still damage
// TODO: Handle some sort of repairable or unrepairable damage depending on conditions
if ((_projectile == "") && {(_unit == vehicle _source)} && {_surfaceIsWater}) then {
	_prevDamage = _unit getVariable ["ace_vd_"+_selectionName, 0];

	// almost submerged
	if (_pos select 2 <= ALMOST_SUBMERGED) then {
		/*
		// Penalty?
		if (fuel _unit > 0) then {
			_unit setFuel 0;
		};
		*/

		// Eject crew
		_crew = crew _unit;
		if (count _crew > 0) then {
			// Prevent rapid event calling due to constant handleDamage event
			_eject_time = _unit getVariable [QGVAR(ejected), 0];
			if (_eject_time < (time - CREW_CHECK)) then {
				TRACE_2("Ejecting",_unit,_crew);
				[QGVAR(eject), [_unit, _crew]] call CBA_fnc_globalEvent;
				_unit setVariable [QGVAR(ejected), time];
			};
		};
	};

	// Fully submerged
	if (_pos select 2 <= SUBMERGED) exitWith {
		// Apply normal damage
		_r;
	};

	// TODO: Perhaps still apply a % of damage? So vehicles in water for a very long time break down eventually?
	_r = _prevDamage;
};

TRACE_3("Returning damage",_r,_pos,_surfaceIsWater);
_unit setVariable ["ace_vd_"+_selectionName, _r];
//[_unit,_part,objNull] spawn FUNC(tank_analyzedamage);
_r;
