// #define DEBUG_MODE_FULL
#define CFGA configFile >> "CfgAmmo" >> _ammo
#define CFGV configFile >> "CfgVehicles" >> (typeOf _unit)
#define CFGW configFile >> "CfgVehicles" >> _whoFired
#include "script_component.hpp"

PARAMS_3(_unit,_ammo,_whoFired);

// TODO: IM Event is global, we want to control the missile on the firers computer, probably ??
// TODO: Possibly have to check for (gunner _whoFired), incase of vehicle, instead ?
if !(local _whoFired) exitWith {};


// WIP
// Vehicle Protections
// - SHTORA
// - Smoke ?

// Weapon (Ammo??) lockon types
// - Laser
// - Wire / Saclos

if (getNumber(CFGV >> QGVAR(shtora)) == 1) exitWith { _this call FUNC(shtora) };

