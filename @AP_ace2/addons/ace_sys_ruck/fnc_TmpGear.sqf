//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_unit,_magL,_wepL);
private ["_unitpos", "_dummy"];

/*
    Temporary gear box
*/

if ( isNil QGVAR(TmpGearBox) ) then {
    //create empty gear box
    _unitpos = position _unit;
    _dummy = "ACE_EmptyBox" createVehicleLocal [_unitpos select 0, _unitpos select 1, 0];
    _dummy setPos [_unitpos select 0, _unitpos select 1, -5]; //hide underground
    //param via GVAR
    GVAR(TmpGearBox) = _dummy;
    _unit reveal _dummy; // Handles delays in MP?
    clearMagazineCargo _dummy;
    clearWeaponCargo _dummy;
    _dummy allowDamage false;

    //fill
    {_dummy addMagazineCargo [_x select 0, _x select 1]} forEach _magL;
    {_dummy addWeaponCargo _x} forEach _wepL;
    //open dialog
    _unit action ["GEAR",_dummy];
};
