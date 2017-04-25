// Contains menu defs for treating yourself or another person.
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_menuName", "_menuRsc", "_menus",
	"_bleed", "_pain", "_epi", "_state", "_inVehicle", "_playerIsUncon",
	"_playerIsBusy", "_capable", "_sys_wounds_enabled", "_hasBandage", "_hasMorphine", "_hasEPI", "_damage", "_rec_heal", "_can_heal", "_rec_stabilize", "_remoteRuckMags","_otherHasCATApplied"];

PARAMS_2(_target,_params);

_menuName = "";
_menuRsc = "popup";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__]};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};
//-----------------------------------------------------------------------------
/* Special states:
	state 800 = bleeding signs, pain
	state 801 = blackouts every now and then, bleeding signs, pain
	state 802 = complete blackout
*/
#define _state_blackingOut 801
#define _state_completeBlackout 802

_remoteRuckMags = [];
// if target is player or local AI, then read their state variables directly from local object.
if (local _target) then {
	// variables are often nil at start of mission
	_bleed = _target getVariable ["ace_w_bleed", 0];
	_pain = _target getVariable ["ace_w_pain", 0];
	_epi = _target getVariable ["ace_w_epi", 0];
	_state = _target getVariable ["ace_w_state", 0];
	_damage = [_target] call FUNC(getDamage);
	_rec_heal = _target getVariable ["ace_w_healing_r", false];
	_can_heal = [_target] call FUNC(canHeal);
	_bleedAdd = _target getVariable ["ace_w_bleed_add", 0]; // Bloodloss rate (TBD). Used for determining CAT usage
	_rec_stabilize = _target getVariable ["ace_w_stabilizing_r", false];
	//_remoteRuckMags - Fake entry
	_mor_dosage = _target getVariable ["ace_w_mor_dosage",0];
	_otherHasCATApplied = _target getVariable ["ace_w_cat",false];
} else { // else if target is !local (eg: MP player), then read their state variables from a networked answer variable.
	if (count GVAR(recAnswer) >= 7) then {
		//GVAR(recAnswer) is (_receiver,_sender,_state,_epi,_bleed,_pain,_stabilized)
		_state = GVAR(recAnswer) select 2;
		_epi = GVAR(recAnswer) select 3;
		_bleed = GVAR(recAnswer) select 4;
		_pain = GVAR(recAnswer) select 5;
		_damage = GVAR(recAnswer) select 7;
		_rec_heal = GVAR(recAnswer) select 8;
		_can_heal = GVAR(recAnswer) select 9;
		_bleedAdd = GVAR(recAnswer) select 10;
		_rec_stabilize = GVAR(recAnswer) select 11;
		_remoteRuckMags = GVAR(recAnswer) select 12;
		_mor_dosage = GVAR(recAnswer) select 13;
		_otherHasCATApplied = GVAR(recAnswer) select 14;
	} else {
		_bleed = 0;
		_pain = 0;
		_epi = 0;
		_state = 0;
		_damage = 0;
		_rec_heal = false;
		_can_heal = false;
		_bleedAdd = 0;
		_rec_stabilize = false;
		//_remoteRuckMags - Fake entry
		_mor_dosage = 0;
		_otherHasCATApplied = false;
	};
};

TRACE_1("",_remoteRuckMags);

// just in case...
if (isNil "_remoteRuckMags") then {
	_remoteRuckMags = [];
	WARNING(str(_target) + " may be using a wrong ACE version, no remoteRuckMags defined"); 
};

cba_ui_target setVariable [QGVAR(remoteRuckMags), _remoteRuckMags];

_stable = _bleed == 0 && {_pain == 0} && {_epi == 0};
_heavyDamage = _damage > LOW_DAMAGE_CEIL;
_reviveEnabled = !isNil "ace_wounds_prevtime";

_healing = player getVariable ["ace_w_healing", false];
_stabilizing = player getVariable ["ace_w_stabilizing", false];

_nearMedicFacility = [_target] call FUNC(nearMedicalFacility);

TRACE_8("Target",_target,_bleed,_pain,_epi,_state,_damage,_can_heal,_heavyDamage);

_playerIsBusy = player getVariable ["ace_w_busy", false];
if (isNil "_playerIsBusy") then {_playerIsBusy = false};
_capable = ACE_SELFINTERACTION_POSSIBLE;
_isMed = [player] call FUNC(isMedic);

_medicOnly = (!isNil "ace_sys_wounds_medics_only" && {!_nearMedicFacility} && {!_isMed});

_sys_wounds_enabled = (!isNil QGVAR(enabled));
if (_sys_wounds_enabled) then {_sys_wounds_enabled = GVAR(enabled)};

TRACE_4("Player",_capable,_playerIsBusy,_isMed,_nearMedicFacility);

_hasBandage = BND in magazines player || {[player, BND] call FUNC(hasRuckMagazine)};
_hasLargeBandage = LRGBND in magazines player || {[player, LRGBND] call FUNC(hasRuckMagazine)};
_hasMorphine = MOR in magazines player || {[player, MOR] call FUNC(hasRuckMagazine)};
_hasEPI = EPI in magazines player || {[player, EPI] call FUNC(hasRuckMagazine)};
_hasMedKit = KIT in magazines player || {[player, KIT] call FUNC(hasRuckMagazine)};
_hasCAT= CAT in magazines player || {[player, CAT] call FUNC(hasRuckMagazine)};

TRACE_6("",_hasBandage,_hasLargeBandage,_hasMorphine,_hasEPI,_hasCAT,_hasMedKit);

_otherHasBandage = BND in magazines cba_ui_target || {(!local cba_ui_target && {BND in _remoteRuckMags})} || {(local cba_ui_target && {([cba_ui_target, BND] call FUNC(hasRuckMagazine))})};
_otherHasLargeBandage = LRGBND in magazines cba_ui_target || {(!local cba_ui_target && {LRGBND in _remoteRuckMags})} || {(local cba_ui_target && {([cba_ui_target, LRGBND] call FUNC(hasRuckMagazine))})};
_otherHasMorphine = MOR in magazines cba_ui_target || {(!local cba_ui_target && {MOR in _remoteRuckMags})} || {(local cba_ui_target && {([cba_ui_target, MOR] call FUNC(hasRuckMagazine))})};
_otherHasEPI = EPI in magazines cba_ui_target || {(!local cba_ui_target && {EPI in _remoteRuckMags})} || {(local cba_ui_target && {([cba_ui_target, EPI] call FUNC(hasRuckMagazine))})};
_otherHasCAT = CAT in magazines cba_ui_target || {(!local cba_ui_target && {CAT in _remoteRuckMags})} || {(local cba_ui_target && {([cba_ui_target, CAT] call FUNC(hasRuckMagazine))})};
_otherHasMedKit = KIT in magazines cba_ui_target || {(!local cba_ui_target && {KIT in _remoteRuckMags})} || {(local cba_ui_target && {([cba_ui_target, KIT] call FUNC(hasRuckMagazine))})};

TRACE_8("",_otherHasBandage,_otherHasLargeBandage,_otherHasMorphine,_otherHasEPI,_otherHasCAT,_otherHasMedKit,_rec_heal,_rec_stabilize);

// TODO: Not sure about the MedKit..
//_noMedicalGear = !_hasBandage && !_hasLargeBandage && !_hasMorphine && /*!_hasEPI &&*/ !_hasCAT && !_hasMedKit && !_otherHasBandage && !_otherHasLargeBandage && !_otherHasMorphine && /*!_otherHasEPI &&*/ !_otherHasCAT && !_otherHasMedKit;

_hasCATApplied = player getVariable ["ace_w_cat",false]; // Player has a CAT applied?

#define __actionStatus(_hasCondition,_hasTreatment) (if (_hasCondition) then {if (_hasTreatment) then {""}else{": N/A"}} else {""})

_menus = [];
//-----------------------------------------------------------------------------
if (_menuName == "main") then {
	_menus set [count _menus,
		[
			["main", localize "STR_ACE_DIA_MEDICALSELF", _menuRsc],
			[
				//Examine > // Self
				[localize "STR_ACE_DIA_MEDICALSELF" + " >", "", "", "",
					[QPATHTO_F(fnc_menuDef_Self), "treatSelf", 1],
					DIK_T, 1, !_playerIsBusy && {_sys_wounds_enabled} && {ACE_SELFINTERACTION_RESTRICTED}],
				// Unpack stretcher	
				[localize "STR_ACE_UA_STRETCHER_AUSPACKEN",
					{ player spawn FUNC(drop_stretcher) },
					"", "", "", -1, 1, ("ACE_Stretcher" in (weapons player) && {_sys_wounds_enabled} && {!_playerIsBusy} && {ACE_SELFINTERACTION_RESTRICTED})],
				// Heal %1 if medic
				[format [localize "str_action_heal_soldier",(getText(configFile >> "CfgVehicles" >> typeOf player >> "displayName"))],
					{ player setDamage 0; player playmove "AinvPknlMstpSlayWrflDnon_medic" },
					"", "", "", -1, 1, alive player && {isNil QGVAR(enabled)} && {damage player > 0} && {(getNumber(configFile >> "CfgVehicles" >> typeOf player >> "attendant")==1)} && {(player isKindOf "CaManBase")}]
			]
		]
	];
};
//-----------------------------------------------------------------------------
if (_menuName == "treatSelf") then {
	#define __STOPBLEED (localize "STR_ACE_UA_STOPBLEED")
	#define __STOPBLEEDLARGE (localize "STR_ACE_UA_STOPBLEEDLARGE")
	#define __STOPBLEEDVERYLARGE (localize "STR_ACE_UA_STOPBLEEDFUCKINGVERYLARGE")
	#define __USEMORPHI (localize "STR_ACE_UA_USEMORPHI")
	#define __USEEPI (localize "STR_ACE_UA_USEEPI")
	#define __REMOVECAT (localize "STR_ACE_UA_REMOVECAT")
	
	_bbandage_gauze = _capable && {_bleed > 0} && {_hasBandage} && {!(!_isMed && {_heavyDamage} && {isMultiplayer})};
	_bbandage_kit = _capable && {_bleed > 0} && {_hasLargeBandage} && {!(!_isMed && {_heavyDamage} && {isMultiplayer})};
	_bcat = _capable && {_bleed > 0} && {_hasCAT} && {!_hasCATApplied} && {!(!_isMed && {_heavyDamage} && {isMultiplayer})};
	_bremove_cat = _capable && {_hasCATApplied};
	_bmorphine = _capable && {_pain > 0} && {_hasMorphine} && {!_medicOnly};
	_bepi = _capable && {_epi > 0} && {_hasEPI} && {!_medicOnly}; //TODO: signs for needing epi missing.
	_bfirstaid = !_healing && {!_rec_heal} && {_hasMedKit} && {_capable} && {_stable} && {_can_heal} && {(_isMed || {(_nearMedicFacility && {!isMultiplayer})})};
	
	_bdoempty = _bbandage_gauze || {_bbandage_kit} || {_bcat} || {_bremove_cat} || {_bmorphine} || {_bepi} || {_bfirstaid};
	
	_menus set [count _menus,
		[
			["treatSelf", localize "STR_ACE_DIA_MEDICALSELF", _menuRsc, QPATHTO_C(data\equip\)],
			[
			// Bandage (Gauze)
				[__STOPBLEED+__actionStatus(_bleed > 0,_hasBandage),
					{ [cba_ui_target, player, nil, 'ACE_Bandage'] spawn COMPILE_FILE(self_bandage) },
					"m_bandage_ca.paa",
					"", 
					"", 
					DIK_B,
					1, _bbandage_gauze],
			// Bandage Kit
				[__STOPBLEEDLARGE+__actionStatus(_bleed > 0,_hasLargeBandage),
					{ [cba_ui_target, player, nil, 'ACE_LargeBandage'] spawn COMPILE_FILE(self_bandage) },
					"m_traumabandage_ca.paa", 
					"", 
					"", 
					DIK_K,
					1, _bbandage_kit],
			// CAT
				[__STOPBLEEDLARGE+__actionStatus(_bleed > 0,_hasLargeBandage),
					{ [cba_ui_target, player, nil, 'ACE_Tourniquet'] spawn COMPILE_FILE(self_bandage) },
					"m_cat_ca.paa", 
					"",
					"",
					DIK_T,
					1, _bcat],
			// Remove CAT
				[__REMOVECAT,
					{ player spawn COMPILE_FILE(self_CATremove) },
					"m_cat_ca.paa", 
					"", 
					"", 
					DIK_T,
					1, _bremove_cat],
			// Morphine
				[__USEMORPHI + __actionStatus(_pain > 0,_hasMorphine),
					{ [cba_ui_target, player] spawn COMPILE_FILE(self_morphine) },
					"m_morphine_ca.paa", 
					"", 
					"", 
					DIK_M,
					1, _bmorphine],
			// Epi
				[__USEEPI + __actionStatus(_epi > 0,_hasEPI),
					{ [cba_ui_target, player] spawn COMPILE_FILE(self_epi) },
					"m_epi_ca.paa", 
					"", 
					"", 
					DIK_E,
					1, _bepi],
			// First Aid
				[localize "STR_ACE_UA_FIRSTAID",
					format['[cba_ui_target, player, %1] spawn FUNC(treat_heal)', _damage],
					"m_medkit_ca.paa", 
					"", 
					"", 
					DIK_H,
					1, _bfirstaid],
			// No Option info
				[localize "STR_ACE_WOUNDS_ROCKO",
					{},
					"", 
					"", 
					"", 
					-1,
					0, !_bdoempty]
			]
		]
	];
};
//-----------------------------------------------------------------------------
if (_menuName == "treat person") then {
	if (local cba_ui_target) then {
		[cba_ui_target] spawn FUNC(examine);
	};

	#define __STOPBLEED (localize "STR_ACE_UA_STOPBLEED")
	#define __STOPBLEEDLARGE (localize "STR_ACE_UA_STOPBLEEDLARGE")
	#define __STOPBLEEDVERYLARGE (localize "STR_ACE_UA_STOPBLEEDFUCKINGVERYLARGE")
	#define __USEMORPHI (localize "STR_ACE_UA_USEMORPHI")
	#define __USEEPI (localize "STR_ACE_UA_USEEPI")
	#define __REMOVECAT (localize "STR_ACE_UA_REMOVECAT")
	#define __DRAG (localize "BC_ADDACTIONS.SQF13")

	GVAR(receiver) = cba_ui_target;
	GVAR(recstate) = _state;
	GVAR(bleed) = _bleed;
	
	_bbandagegauze = alive GVAR(receiver) && {_capable} && {_bleed > 0} && {(_hasBandage || {_otherHasBandage})} && {!_playerIsBusy};
	_bbandagekit = alive GVAR(receiver) && {_capable} && {_bleed > 0} && {(_hasLargeBandage || {_otherHasLargeBandage})} && {!_playerIsBusy};
	_bcat = alive GVAR(receiver) && {_capable} && {_bleed > 0} && {(_hasCAT || {_otherHasCAT})} && {!_playerIsBusy} && {!_otherHasCATApplied};
	_bremovecat = alive GVAR(receiver) && {_capable} && {_otherHasCATApplied} && {!_playerIsBusy};
	
	// Morphine/Epi application: Automatic for unconscious casulty / with accept action for conscious casulty 
	_bmorphine = alive GVAR(receiver) && {_capable} && {(_hasMorphine || {(_state >= _state_blackingOut && {_otherHasMorphine})})} && {!_playerIsBusy} && {!_medicOnly};
	_bepi = alive GVAR(receiver) && {_capable} && {(_hasEPI || {(_state >= _state_blackingOut && {_otherHasEPI})})} && {!_playerIsBusy} && {!_medicOnly};
	
	_bstabilize = !_rec_stabilize && {!_stabilizing} && {alive GVAR(receiver)} && {(_bleed > 0 || {_epi > 0} || {_pain > 0})} && {!_playerIsBusy} && {_state >= _state_blackingOut};
	_bcpr = alive GVAR(receiver) && {_reviveEnabled} && {_state >= _state_completeBlackout} && {!_playerIsBusy};
	_bfirstaid = !_healing && {!_rec_heal} && {(_hasMedKit || {_otherHasMedKit})} && {_capable} && {(_nearMedicFacility || {_isMed})} && {alive _target} && {_stable} && {_can_heal} && {!_playerIsBusy};
	
	_bdoempty = _bbandagegauze || {_bbandagekit} || {_bcat} || {_bremovecat} || {_bmorphine} || {_bepi} || {_bstabilize} || {_bcpr} || {_bfirstaid};

	_menus set [count _menus,
		[
			// Treat Other
			["treat person", localize "STR_ACE_DIA_MEDICAL", _menuRsc, QPATHTO_C(data\equip\)],
			[
			// Bandage (Gauze)
				[__STOPBLEED,
					{ [GVAR(receiver), GVAR(recstate), BND] spawn FUNC(bandage) },
					"m_bandage_ca.paa", 
					"", 
					"", 
					DIK_B,
					// Medic items should not be grayed out, you can only use whats available (in gear)
					1, _bbandagegauze],
			// Bandage Kit (Trauma bandage)
				[__STOPBLEEDLARGE,
					{ [GVAR(receiver), GVAR(recstate), LRGBND] spawn FUNC(bandage) },
					"m_traumabandage_ca.paa", 
					"", 
					"", 
					DIK_K,
					1, _bbandagekit],
			// CAT
				[__STOPBLEEDVERYLARGE,
					{ [GVAR(receiver), GVAR(recstate), CAT] spawn FUNC(bandage) },
					"m_cat_ca.paa", 
					"", 
					"", 
					DIK_T,
					1, _bcat],	
			// Remove CAT
				[__REMOVECAT,
					{ [GVAR(receiver), player] spawn FUNC(CATremove) },
					"m_cat_ca.paa", 
					"", 
					"", 
					DIK_T,
					1, _bremovecat],
			// Morphine
				[__USEMORPHI,
					{ [GVAR(receiver), GVAR(recstate)] spawn FUNC(morphine) },
					"m_morphine_ca.paa", 
					"", 
					"", 
					DIK_M,
					1, _bmorphine],
			// Epi
				[__USEEPI,
					{ [GVAR(receiver), GVAR(recstate)] spawn FUNC(epi) },
					"m_epi_ca.paa", 
					"", 
					"", 
					DIK_E,
					1, _bepi],
			// Stabilize
				[format [localize "STR_ACE_UA_STABILIZE", name cba_ui_target],
					{ [GVAR(receiver), GVAR(recstate)] spawn FUNC(treat_stabilize) },
					"menu_stabilize_ca.paa", 
					"", 
					"", 
					DIK_S,
					1, _bstabilize],
			// CPR - only with PMR
				["CPR",
					{ [GVAR(receiver),GVAR(bleed) ] spawn FUNC(cpr) },
					"menu_cpr_ca.paa", 
					"", 
					"", 
					DIK_C,
					1, _bcpr],
			// First Aid
				[localize "STR_ACE_UA_FIRSTAID",
					format['[cba_ui_target, player, %1] spawn FUNC(treat_heal)', _damage],
					"m_medkit_ca.paa",
					"", 
					"", 
					DIK_H,
					1, _bfirstaid],
			// No Option info
				[localize "STR_ACE_WOUNDS_ROCKO",
					{},
					"", 
					"", 
					"", 
					-1,
					0, !_bdoempty]
			]
		]
	];
};
//-----------------------------------------------------------------------------
_menuDef = [];
{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this} else {""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _params, __FILE__];
};

_menuDef
