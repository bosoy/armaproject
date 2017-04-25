/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_weight", "_ItemWeight", "_x", "_weapon_on_back", "_typesIFAK", "_ifakcnt", "_fnc", "_items", "_count", "_item_x", "_count_x", "_bis_bpc_weight", "_bis_bp_weight", "_oth"];
PARAMS_1(_unit);

if (isNull _unit) then {
	_weight = -1;
} else {
	if (local _unit) then {
		_weight = 0;
		ISNILS(GVAR(oversize),0);
		_weight = _weight + GVAR(oversize);

		{ // gear magazines
			_ItemWeight = getNumber(__CONF_MAGAZINES >> _x >> "ACE_Weight");
			_weight = _weight + _ItemWeight;
		} forEach (magazines _unit);

		{ // gear weapons
			_ItemWeight = getNumber(__CONF_WEAPONS >> _x >> "ACE_Weight");
			_weight = _weight + _ItemWeight;
		} forEach (weapons _unit);

		// weapon on back if present
		_weapon_on_back = _unit getVariable ["ACE_weapononback",""];
		if ( _weapon_on_back != "" && {isClass (__CONF_WEAPONS >> _weapon_on_back)} ) then {
			_ItemWeight = getNumber(__CONF_WEAPONS >> _weapon_on_back >> "ACE_Weight");
			_weight = _weight + _ItemWeight;
		};

		// IFAK contents
		_typesIFAK = (_unit call FUNC(detIFAK)) select 0; //__IFAK_TYPES;
		_ifakcnt = _unit getVariable ["ACE_IFAK_Contents",[0,0,0]];
		for "_x" from 0 to ((count _typesIFAK) - 1) do {
			_ItemWeight = getNumber(__CONF_MAGAZINES >> (_typesIFAK select _x) >> "ACE_Weight");
			_ItemWeight = _ItemWeight * (_ifakcnt select _x);
			_weight = _weight + _ItemWeight;
		};

		// Ruck Contents (ACE)
		if ( _unit call FUNC(HasRuck) || {[_unit] call FUNC(RuckBusy)} ) then {
			_weight = _weight + (_unit call FUNC(RuckInventoryWeight));
		};

		// Ruck Contents (BIS)
		_fnc = {
			private ["_item", "_itemWeight"];
			PARAMS_2(_items,_type);
			_item = _items select 0;
			if (count _item > 0) then {
				_count = _items select 1;
				for "_i" from 0 to (count _item - 1) do {
					_item_x = _item select _i;
					_count_x = _count select _i;
					// Berechnungsblabla
					// isMagazine ?
					_ItemWeight = switch _type do {
						// TODO: Disposable weapons carried as magazines, need to find the weight from weapon instead.
						// TODO: Consider adding the weight to the magazines instead, or
						// if (getNumber(__CONF_MAGAZINES >> _item_x >> "ace_disposable") == 1) then { getNumber(__CONF_WEAPONS >> _item_x >> "ACE_Weight") } else { getNumber(__CONF_MAGAZINES >> _item_x >> "ACE_Weight") }
						case "m": { getNumber(__CONF_MAGAZINES >> _item_x >> "ACE_Weight") };
						default { getNumber(__CONF_WEAPONS >> _item_x >> "ACE_Weight") };
					};
					_ItemWeight = _ItemWeight * _count_x;
					_bis_bpc_weight = _bis_bpc_weight + _ItemWeight;
				};
				_weight = _weight + _bis_bpc_weight;
			};
		};
		#define __BIS_BP (unitbackpack _unit)
		if !(isNull __BIS_BP) then {
			// BIS backpack weight
			_bis_bp_weight = getNumber(__CONF_WEAPONS >> typeof __BIS_BP >> "ACE_Weight");
			_weight = _weight + _bis_bp_weight;

			// Ruck Contents (BIS)
			_bis_bpc_weight = 0;
			[getMagazineCargo __BIS_BP, "m"] call _fnc;
			[getWeaponCargo __BIS_BP, "w"] call _fnc;
		};

	    //when gear is open, broadcast weight every 30 seconds
		ISNILS(GVAR(wgttim),0);
		if (time > GVAR(wgttim)) then {
			_unit setVariable ["ACE_GearWeight",_weight,true];
			GVAR(wgttim) = time + 30; //wait at least 30 seconds  between broadcasts of weight over network
		};
	} else {
	    //request broadcasted weight
	    [_unit] call FUNC(reqWeight);

	    //retrieve broadcast weight, not accurate until broadcast received
	    _weight = _unit getVariable ["ACE_GearWeight", nil];
	};
};

ISNILS(_weight,-1);
if ( (typeName _weight) != "SCALAR" ) then {_weight = -1};
if ( _weight == -1 ) then {WARNING("ace_sys_ruck: Failed to determine weight!")};

_weight
