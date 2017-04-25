// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_crate);
private["_ar", "_weapons", "_magazines", "_pos"];
if (isDedicated) exitWith {};

_pos = getPos _crate;
// deleteVehicle _crate; // Disabled due to the crate now being a Logic :-)


// TODO: Change side player to var set
//_crate = ([GVAR(sides_weaponboxes), side player] call CBA_fnc_has hGet) createVehicleLocal _pos;
_crate = "ACE_AmmoPallet" createVehicleLocal _pos;
TRACE_2("",_crate,_pos);

clearMagazineCargo _crate; clearWeaponCargo _crate;

_ar = [player] call ace_fnc_enum;
_weapons = []; {
	{ PUSH(_weapons,_x select 0) } forEach _x;
} forEach (_ar select 0);
{ _crate addWeaponCargo [_x, GVAR(magicbox_weapons_count)] } forEach _weapons;

_ar = [_weapons + ["Throw", "Put"]] call ace_fnc_enumMagazines;
_magazines = []; {
	{ PUSH(_magazines,_x select 0) } forEach _x;
} forEach (_ar select 0);
{ _crate addMagazineCargo [_x, GVAR(magicbox_magazines_count)] } forEach _magazines;
