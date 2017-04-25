/* ace_fx_explosions | (c) 2008 by rocko */

#include "script_component.hpp"

/* ace_fx_explosions function for replaced ordonance

	WIP

  I dont know if this works ;D

  rocko
 -------------------------

   how to:
   create your replacement via

   _replace_type = "ACE_BOMBWhatever";
   _replace = _replace_type createVehicle _pos_wherever;

   then call on the replacement

   [_replace,_replace_type] call ACE_FX_EXPLOSIONS_Replace;

*/

private["_delay","_ammo","_object","_ammoStrength","_multiplier","_ammoSim","_indirectHitRange"];
PARAMS_2(_object,_ammo);

/* SAFE MODE, if you accidentally call on low hit and low indirect hit range ammunition */

_ammoSim = getText(configFile>>"CfgAmmo">>_ammo>>"simulation");
if (_ammoSim in ["shotTimeBomb","shotPipeBomb","shotMine","shotIlluminating","shotSmoke"])exitWith {};  // DISABLE non explosives
_ammoStrength = getNumber(configFile>>"CfgAmmo">>_ammo>>"indirectHit");
if (_ammoStrength < 2)exitWith {}; 	// DISABLE for low indirect hit ammunition
_indirectHitRange = getNumber(configFile>>"CfgAmmo">>_ammo>>"indirectHitRange");
if (_indirectHitRange < 2)exitWith {};  // DISABLE for low indirecthitrange ammunition

_delay = getNumber(configFile>>"CfgAmmo">>_ammo >> "ACE_FX_EXPLOSIONS_DELAY");
/* SAFE MODE END */

_multiplier = switch (true) do {
	case (_ammostrength > 500): {5.5};
	case (_ammostrength > 250): {4.5};
	case (_ammostrength > 100): {3};
	default {2};
};
[_object,_indirectHitRange*_multiplier,_ammo,_multiplier,_delay] spawn FUNC(track);

TRACE_1("",_ammo);
