//input: part type (engine,turret,gun,ltrack,rtrack,hull)
//output: selection name (motor,vez,zbran,pas_l,pas_p,telo)

#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

#define __hullcfg(value) __unitcfg>>"hitpoints">>("hit"+##value)>>"name"
#define __turcfg(value) __unitcfg>>"Turrets">>"MainTurret">>"hitpoints">>("hit"+##value)>>"name"

PARAMS_2(_unit,_part);
private["_name"];

/*
// reserve method
if (_part in ["turret","gun"]) then
{
	_name = tolower getText(__turcfg(_part));
} else {
	_name = tolower getText(__hullcfg(_part));
};
_name
*/

_unit getvariable ("ace_name_" + _part)