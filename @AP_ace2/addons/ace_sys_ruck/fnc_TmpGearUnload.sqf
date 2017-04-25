//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_dummy", "_magGet", "_wepGet", "_magAry", "_wepAry", "_pshd", "_return"];

/*
    Temporary gear box
*/

_return = nil;

if ( ! isNil QGVAR(TmpGearBox) ) then {
    _dummy = GVAR(TmpGearBox);
    GVAR(TmpGearBox) = nil;
    _magGet = getMagazineCargo _dummy;
    _wepGet = getWeaponCargo _dummy;
    TRACE_2("Get",_magGet,_wepGet);
    //format getTocargo
    _magAry = [];
    for "_x" from 0 to ((count (_magGet select 0)) - 1) do {
        _pshd = [(_magGet select 0) select _x, (_magGet select 1) select _x];
        PUSH(_magAry,_pshd);
    };
    _wepAry = [];
    for "_x" from 0 to ((count (_wepGet select 0)) - 1) do {
        _pshd = [(_wepGet select 0) select _x, (_wepGet select 1) select _x];
        PUSH(_wepAry,_pshd);
    };
    //cleanup
    deleteVehicle _dummy;
    _return = [_magAry,_wepAry];
};

TRACE_1("",_return);

_return
