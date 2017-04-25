// #define DEBUG_MODE_FULL
#define CFGA configFile >> "CfgAmmo" >> _ammo
#define CFGV configFile >> "CfgVehicles" >> (typeOf _unit)
#define CFGW configFile >> "CfgVehicles" >> _who
#include "script_component.hpp"

PARAMS_3(_who,_unit,_laserObj);

// TODO: Possibly have to check for (gunner _who), incase of vehicle, instead ?
// Changed to local to the vehicle driver only. This will be server for AI / no driver, or the local driver
if !(local _unit) exitWith { _unit setVariable ["ace_targeted_time",time]; TRACE_1("Abort. Unit not local", _unit) };
if (isNull _laserObj) exitWith { TRACE_1("Abort. LaserObje Null", _unit) };

// WIP
// Vehicle Protections
// - SHTORA
// - Smoke ?

// Weapon (Ammo??) lockon types
// - Laser
// - Wire / Saclos

if (getNumber(CFGV >> QGVAR(shtora)) == 1) exitWith { _this spawn FUNC(shtora_targeted) };
