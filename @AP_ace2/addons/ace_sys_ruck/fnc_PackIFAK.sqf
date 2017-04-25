/*
Function: ACE_fnc_PackIFAK

Description:
	Pack IFAK items. Use this function instead of adding IFAK magazines manually.

Parameters:
	_unit - Unit owning IFAK to pack. [Object]
	_item1 - ACE_LargeBandage, number to pack ( may be 0 ). [Number]
	_item2 - ACE_Bandage, number to pack ( may be 0 ). [Number]
	_item3 - ACE_Tourniquet, number to pack ( may be 0 ). [Number]
    _reset - Set instead of add counts [Boolean] (optional)
Returns:
	"true" unless error. [Boolean]

Example:
	(begin example)
		_success = [BOB, 1, 0, 1] call ACE_fnc_PackIFAK;
	(end)

Author:
	tcp
*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);
DEFAULT_PARAM(1,_item1,0);
DEFAULT_PARAM(2,_item2,0);
DEFAULT_PARAM(3,_item3,0);
DEFAULT_PARAM(4,_reset,false);

private ["_packable", "_item_max", "_item_ary", "_def", "_ifak_ary", "_ifak_types", "_mag", "_m_total", "_total", "_new_total"];

_packable = true;

if !(_unit isKindOf "Man") exitWith { _packable = false };

_item_max = 1;
_item_ary = [_item_max min _item1 max 0, _item_max min _item2 max 0, _item_max min _item3 max 0];

_ifak_types = (_unit call FUNC(detIFAK)) select 0; //__IFAK_TYPES;
if (count _ifak_types == 0) exitWith { _packable = false };

if (_reset) exitWith {
    if (time < 0.1) then {
        _unit setVariable ["ACE_IFAK_Contents", _item_ary];
    } else {
        { // forEach
            _idx = _ifak_types find _x;
            if (_idx > -1) then { _item_ary set [_idx, (_item_ary select _idx) - 1] };
        } forEach (magazines _unit);

        { //forEach
            if (_x < 0) then {
                for "_i" from 1 to abs(_x) do { _unit removeMagazine (_ifak_types select _forEachIndex) };
            } else {
                for "_i" from 1 to _x do { _unit addMagazine (_ifak_types select _forEachIndex) };
            };
        } forEach _item_ary;
    };
    _packable
};

_def = [0,0,0];
__DEF_GETV(_ifak_ary,_unit,"ACE_IFAK_Contents",_def);

{ // forEach
    _mag = _ifak_types select _forEachIndex;

    _m_total = ( { _x == _mag } count (magazines _unit) );

    _total = ( _ifak_ary select _forEachIndex ) + _m_total;

    _new_total = ( ( _total + _x ) min _item_max ) - _m_total;

    if (time < 0.1) then {
        //use object variable for now, added to magazines on mission start
        _ifak_ary set [_forEachIndex, ( _new_total max 0 )];
    } else {
        for "_i" from 1 to _new_total do { _unit addMagazine _mag };
    };

} forEach _item_ary;

_packable
