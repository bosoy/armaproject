/* ace_sys_explosives (.pbo)| Hiding tripwire stakes | (c) 2008, 2009, 2010, 2011 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private "_camo";

_stake = _this;
_pos = getPosATL _stake;
_surface = surfaceType _pos;

_surface_string = ([_surface, "#"] call CBA_fnc_split) select 1;
_camo_possible_type = getText(configFile >> "CfgSurfaces" >> _surface_string >> "soundEnviron");

diag_log _camo_possible_type;

// TODO: Get more types donw, depending on stuff missing
switch (_camo_possible_type) do {
	case "gravel": { _camo = "ACE_pileOfGravel" };
	case "gravel2": { _camo = "ACE_pileOfGravel" };
	case "dirt": { _camo = "ACE_pileOfGrass" };
	case "grass": { _camo = "ACE_pileOfGrass" };
	case "drygrass": { _camo = "ACE_pileOfGrass" };
	case "forest": { _camo = "ACE_pileOfGrass" };
	
	case "sand": { _camo = "ACE_pileOfSand" };
	
	case "rock": { _camo = "ACE_pileOfRocks" };
	
	default { _camo = "ACE_pileOfPiles" };
};

diag_log _camo;

gg = _camo createVehicle _pos;
gg setPos [_pos select 0, _pos select 1, 0];

// Todo: Link camo with stake, so when mine becomes killed, stake becomes killed and camo becomes killed
