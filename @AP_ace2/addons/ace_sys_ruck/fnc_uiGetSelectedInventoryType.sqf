/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

PARAMS_2(_unit,_IDC);

private["_testIDC","_minIDC","_type","_TypeCount","_testType","_testCount","_typeInv","_classInv","_numammo","_magidx"];

_typeInv = "";
_classInv = "";
_numammo = 0;
_magidx = -1;

if ( !isNil "_IDC" ) then {
	switch (_IDC) do {
		case CA_GEAR_SLOT_PRIMARY_IDC: {
			_type = __Type_SlotPrimary;
			_minIDC = CA_GEAR_SLOT_PRIMARY_IDC;
			_classInv = "weapon";
			_typeInv = primaryWeapon _unit;
		};

		case CA_GEAR_SLOT_SECONDARY_IDC: {
			_type = __Type_SlotSecondary;
			_minIDC = CA_GEAR_SLOT_SECONDARY_IDC;
			_classInv = "weapon";
			_typeInv = secondaryWeapon _unit;
		};

		case CA_GEAR_SLOT_HANDGUN_IDC: {
			_type = __Type_SlotHandGun;
			_minIDC = CA_GEAR_SLOT_HANDGUN_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_ITEM1_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM1_IDC;
		};

		case CA_GEAR_SLOT_ITEM2_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM2_IDC;
		};

		case CA_GEAR_SLOT_ITEM3_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM3_IDC;
		};

		case CA_GEAR_SLOT_ITEM4_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM4_IDC;
		};

		case CA_GEAR_SLOT_ITEM5_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM5_IDC;
		};

		case CA_GEAR_SLOT_ITEM6_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM6_IDC;
		};

		case CA_GEAR_SLOT_ITEM7_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM7_IDC;
		};

		case CA_GEAR_SLOT_ITEM8_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM8_IDC;
		};

		case CA_GEAR_SLOT_ITEM9_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM9_IDC;
		};

		case CA_GEAR_SLOT_ITEM10_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM10_IDC;
		};

		case CA_GEAR_SLOT_ITEM11_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM11_IDC;
		};

		case CA_GEAR_SLOT_ITEM12_IDC: {
			_type = __Type_SlotPrimaryItem;
			_minIDC = CA_GEAR_SLOT_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_ITEM12_IDC;
		};

		case CA_GEAR_SLOT_HANDGUN_ITEM1_IDC: {
			_type = __Type_SlotHandGunItem;
			_minIDC = CA_GEAR_SLOT_HANDGUN_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_HANDGUN_ITEM1_IDC;
		};

		case CA_GEAR_SLOT_HANDGUN_ITEM2_IDC: {
			_type = __Type_SlotHandGunItem;
			_minIDC = CA_GEAR_SLOT_HANDGUN_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_HANDGUN_ITEM2_IDC;
		};

		case CA_GEAR_SLOT_HANDGUN_ITEM3_IDC: {
			_type = __Type_SlotHandGunItem;
			_minIDC = CA_GEAR_SLOT_HANDGUN_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_HANDGUN_ITEM3_IDC;
		};

		case CA_GEAR_SLOT_HANDGUN_ITEM4_IDC: {
			_type = __Type_SlotHandGunItem;
			_minIDC = CA_GEAR_SLOT_HANDGUN_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_HANDGUN_ITEM4_IDC;
		};

		case CA_GEAR_SLOT_HANDGUN_ITEM5_IDC: {
			_type = __Type_SlotHandGunItem;
			_minIDC = CA_GEAR_SLOT_HANDGUN_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_HANDGUN_ITEM5_IDC;
		};

		case CA_GEAR_SLOT_HANDGUN_ITEM6_IDC: {
			_type = __Type_SlotHandGunItem;
			_minIDC = CA_GEAR_SLOT_HANDGUN_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_HANDGUN_ITEM6_IDC;
		};

		case CA_GEAR_SLOT_HANDGUN_ITEM7_IDC: {
			_type = __Type_SlotHandGunItem;
			_minIDC = CA_GEAR_SLOT_HANDGUN_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_HANDGUN_ITEM7_IDC;
		};

		case CA_GEAR_SLOT_HANDGUN_ITEM8_IDC: {
			_type = __Type_SlotHandGunItem;
			_minIDC = CA_GEAR_SLOT_HANDGUN_ITEM1_IDC;
			_classInv = "magazine";
			_numammo = gearIDCAmmoCount CA_GEAR_SLOT_HANDGUN_ITEM8_IDC;
		};

		case CA_GEAR_SLOT_SPECIAL1_IDC: {
			_type = __Type_SlotBinocular;
			_minIDC = CA_GEAR_SLOT_SPECIAL1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_SPECIAL2_IDC: {
			_type = __Type_SlotBinocular;
			_minIDC = CA_GEAR_SLOT_SPECIAL1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY1_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY2_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY3_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY4_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY5_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY6_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY7_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY8_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY9_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY10_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY11_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		case CA_GEAR_SLOT_INVENTORY12_IDC: {
			_type = __Type_SlotSmallItems;
			_minIDC = CA_GEAR_SLOT_INVENTORY1_IDC;
			_classInv = "weapon";
		};

		default {
			_type = __Type_SlotSecondary;
			_minIDC = CA_GEAR_SLOT_SECONDARY_IDC;
			_classInv = "weapon";
		};
	};

	if ( _typeInv == "" ) then {
		if ( _classInv == "weapon" ) then {
			_testIDC = _minIDC;
			{
				scopeName "ScanWeps";

				_TypeCount = (getNumber(configFile >> "CfgWeapons" >> _x >> "type")) call FUNC(ParseTypeSlots);
				_testType  = _TypeCount select 0;
				_testCount = _TypeCount select 1;

				if ( _testType == _type ) then {
					if ( _testIDC == _IDC ) then {
						_typeInv = _x;
						breakOut "ScanWeps";
					} else {
						_testIDC = _testIDC + _testCount;
					};
				};
			} forEach weapons _unit;
		};

		if ( _classInv == "magazine" ) then {
			_testIDC = _minIDC;
			{
				scopeName "ScanMags";

				_TypeCount = (getNumber(configFile >> "CfgMagazines" >> _x >> "type")) call FUNC(ParseTypeSlots);
				_testType  = _TypeCount select 0;
				_testCount = _TypeCount select 1;

				if ( _testType == _type ) then {
					if ( _testIDC == _IDC ) then {
						_typeInv = _x;
						_magidx = _forEachIndex;
						breakOut "ScanMags";
					} else {
						_testIDC = _testIDC + _testCount;
					};
				};
				TRACE_4("type",_TypeCount,_type,_testIDC,_IDC);
			} forEach magazines _unit;
		};
	};
};

[_typeInv, _classInv, _numammo, _magidx]
