//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"
/* ace_sys_ruck (.pbo) | (c) 2009 by tcp */

ADDON = false;
LOG(MSG_INIT);

FUNC(detIFAK) = {
	private ["_fac","_usifak","_usifakn","_gerifak","_gerifakn","_ruifak","_ruifakn","_civifak","_civifakn","_ifak_types","_ifak_names"];
	PARAMS_1(_unit);
	// El stupido factions
	_fac = faction _unit;
	_usifak = ["USMC","BIS_US","BIS_UN","BIS_CIV_special","BIS_BAF","PMC_BAF"];
	_gerifak = ["BIS_GER"];
	_ruifak = ["CDF","RU","BIS_CZ","BIS_TK"];
	// Do insurgents carry medical stuff at all?
	_insifak = ["INS","GUE","BIS_TK_INS","BIS_TK_GUE"];
	_civifak = ["CIV_RU","BIS_TK_CIV","CIV"];
		
	switch (true) do {
		case (_fac in _usifak): { _ifak_types = __IFAK_TYPES_US; _ifak_names = __IFAK_NAMES_US };
		case (_fac in _gerifak): { _ifak_types = __IFAK_TYPES_GER; _ifak_names = __IFAK_NAMES_GER };
		case (_fac in _ruifak): { _ifak_types = __IFAK_TYPES_RU; _ifak_names = __IFAK_NAMES_RU };
		case (_fac in _insifak): { _ifak_types = __IFAK_TYPES_INS; _ifak_names = __IFAK_NAMES_INS };
		case (_fac in _civifak): { _ifak_types = []; _ifak_names = __IFAK_NAMES_CIV };
		default { _ifak_types = __IFAK_TYPES_GER; _ifak_names = __IFAK_NAMES_GER };
	};

	[_ifak_types,_ifak_names]
};

PREP(AddMagToRuck);
PREP(AddWepToRuck);
PREP(FitsInRucksack);
PREP(GearWeight);
PREP(HasFreeMagSlot);
PREP(HasFreeWepSlot);
PREP(IsRuck);
PREP(ParseTypeSlots);
PREP(RemoveMagFromRuck);
PREP(RemoveWepFromRuck);
PREP(RuckInventorySize);
PREP(RuckInventoryWeight);
PREP(RuckMagazines);
PREP(RuckWeapons);
PREP(brcWeight);
PREP(lnbWep);
PREP(boxCount);
PREP(cycleUnit);


PREP(uiGetCallingUnit);
PREP(uiGetSelectedInventoryType);
PREP(uiPutWeaponInHands);
PREP(uiPutWeaponOnBack);
PREP(uiUpdateRuckDisplay);
PREP(uiUpdateWOBDisplay);
PREP(uiHighlightSlots);
PREP(uiUpdateItemDisplay);
PREP(uiUpdateTotals);
PREP(uiUpdateTotalsDelayed);
PREP(uiIFAKupdate);
PREP(DropIFAK);
PREP(reqWeight);

//access ruck
PREP(AccessRuck);
PREP(AccessUnload);
PREP(RuckNet);
PREP(RuckNetUnload);
PREP(TmpGear);
PREP(TmpGearUnload);
PREP(RuckLock);
PREP(RuckCancel);
PREP(GearClose);
FUNC(RuckBusy) = {
    PARAMS_1(_unit);
    _lock = _unit getVariable ["ACE_Ruck_Lock", ""];
    !( _lock == "" || {_lock == "Squad"} || {_lock == "Team"} )
};
FUNC(RuckLockAI) = {
    PARAMS_1(_unit);
    //squad unlock for AI
    if ( local _unit && {!isPlayer _unit} && {isNil {_unit getVariable "ACE_Ruck_Lock"}}) then {
        [_unit, 1] call FUNC(RuckLock);
    };
};

//killed,drop ruck
PREP(killedEH);
PREP(respawnEH);
PREP(contRuck);
PREP(acsRuck);
PREP(opnRuck);
PREP(glbRuckAR);
PREP(DropRuck);
PREP(glbRuckAct);

//API
PREP(FindRuck);
PREP(HasRadio);
PREP(HasRuck);
PREP(PackMagazine);
PREP(PackWeapon);
PREP(PutWeaponOnBack);
PREP(RuckMagazinesList);
PREP(RuckWeaponsList);
PREP(WeaponOnBackName);
PREP(RemoveGear);
PREP(HasWeapon);
PREP(RemWeapon);
PREP(PackIFAK);

PREP(handleGear);
PREP(unloadGear);

// OA2ACE
PREP(convertRuck);
GVAR(toConvert) = [];
FUNC(initConvert) = {
	TRACE_2("initRuck",_this,GVAR(no_ruck_conversion));
	if (isNil QGVAR(no_ruck_conversion)) then {
		if (CBA_MISSION_START) then {
			TRACE_1("initRuck-direct",_this);
			_this call FUNC(convertRuck);
		} else {
			TRACE_1("initRuck-delayed",_this);
			PUSH(GVAR(toConvert),_this);
		};
	};
};
["CBA_MISSION_START", {if (isNil QGVAR(no_ruck_conversion)) then { {_x call FUNC(convertRuck)} forEach GVAR(toConvert)} }] call CBA_fnc_addEventHandler;

//feature #25669
PREP(initRuckFromConfig);

// Workaround for RuckContent not working in MP
// TODO: Perhaps could be properly fixed differently (so that gear actually appears during briefing)?
// TODO: Combine initFromConfig and ConvertRuck processing?
GVAR(config_ar) = [];
FUNC(initFromConfig) = { if (_this call ACE_fnc_HasRuck) then {_this call FUNC(initRuckFromConfig)} };
FUNC(eh_init_from_config) = {
	if (CBA_MISSION_START) then {
		_this call FUNC(initFromConfig);
	} else {
		PUSH(GVAR(config_ar), _this);
	};
};
["CBA_MISSION_START", { if (isNil QGVAR(noRuckFromConfig)) then { { _x call FUNC(initFromConfig) } forEach GVAR(config_ar) } }] call CBA_fnc_addEventHandler;

[QGVAR(acsRuck), { _this call FUNC(acsRuck) }] call CBA_fnc_addEventHandler;
[QGVAR(glbRuckAR), { _this call FUNC(glbRuckAR) }] call CBA_fnc_addEventHandler;
[QGVAR(brcwgt), { _this call FUNC(brcWeight) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(glbRuckAct), { _this call FUNC(glbRuckAct) }] call CBA_fnc_addEventHandler;
[QGVAR(RuckNet), { _this call FUNC(RuckNet) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(RuckNetUnload), { _this call FUNC(RuckNetUnload) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(gear_unload), { _this call FUNC(AccessUnload) }] call CBA_fnc_addEventHandler;
[QGVAR(GearClose), { _this call FUNC(GearClose) }] call ACE_fnc_addReceiverOnlyEventhandler;

FUNC(addMagazineAR) = {
	if (productVersion select 3 >= 94918) then {
		(_this select 0) addMagazine (_this select 1);
		true
	} else {
		(_this select 0) addMagazine ((_this select 1) select 0);
		false
	};
};

ADDON = true;
