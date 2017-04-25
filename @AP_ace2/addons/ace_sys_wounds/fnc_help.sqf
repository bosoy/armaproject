#include "script_component.hpp"

private ["_p1", "_p2", "_dir", "_unit", "_isMedic", "_exit", "_vars", "_bnnnd", "_otherBnnnd", "_bleed"];
PARAMS_2(_toHelp,_unit);

if (vehicle _toHelp != _toHelp) exitWith {};
if ([_unit] call FUNC(occupied)) exitWith { TRACE_1("Busy",_unit) };
_unit setVariable ["ace_w_busy", true, true];

if (_unit != _toHelp) then {
	if ([_toHelp] call FUNC(occupied)) exitWith { TRACE_1("Busy",_toHelp) };
	_toHelp setVariable ["ace_w_busy", true, true];
};

if (random 1 < GVAR(smoke_probab) && !isPlayer _unit) then {
	[_unit] call FUNC(throwSmoke);
};

if (_unit != _toHelp) then {
	_p1 = position _unit;
	_p2 = position _tohelp;
	_dir = ((_p2 select 0) - (_p1 select 0)) atan2 ((_p2 select 1) - (_p1 select 1)) % 360;
	_unit setDir _dir;
};
_isMedic = [_unit] call FUNC(isMedic);
_nearMedicFacility = [_toHelp] call FUNC(nearMedicalFacility);
_allowed = !(!_isMedic && !isNil QGVAR(medics_only) && !_nearMedicFacility);


_exit = false;

_bleed = _toHelp getVariable "ace_w_bleed";
if (isNil "_bleed") then { _bleed = 0 };
_bnnnd = if (_bleed > 0.5) then { LRGBND } else { BND };
_otherBnnnd = if (_bnnnd == LRGBND) then { BND } else { LRGBND }; // Used for fallback
if (local _toHelp) then {
	if ((_toHelp getVariable "ace_w_bleed") > 0) then {
		if (_isMedic) then {
			_unit playMove "AinvPknlMstpSlayWrflDnon_medic";
			sleep 8;
			if (_unit call FUNC(isUncon) || {!(alive _unit)} || {!isNull(_toHelp getVariable ["ace_w_carry", objNull])}) exitWith { _exit = true };
			if ((_toHelp getVariable "ace_w_bleed") > 0 && {alive _tohelp} && {alive _unit}) then {
				[_tohelp,_bnnnd] call FUNC(RemoveBleed); // AI always sets to 0
			};
		} else {
			_allowed = false;
			if ([_toHelp, _unit, _bnnnd] call FUNC(takeItem)) then { _allowed = true } else { if ([_toHelp, _unit, _otherBnnnd] call FUNC(takeItem)) then { _allowed = true } };
			if (_allowed) then {
				_unit playMove "AinvPknlMstpSlayWrflDnon_medic";
				sleep 8;
				if (_unit call FUNC(isUncon) || {!(alive _unit)} || {!isNull(_toHelp getVariable ["ace_w_carry", objNull])}) exitWith { _exit = true };
				if ((_toHelp getVariable "ace_w_bleed") > 0 && {alive _tohelp} && {alive _unit}) then {
					[_tohelp,_bnnnd] call FUNC(RemoveBleed);
				};
			};
		};
	};

	if (_exit) exitWith {TRACE_1("Exiting",nil)};

	if (_allowed) then {
		if ((_toHelp getVariable "ace_w_pain") > 0) then {
			if ([_toHelp, _unit, MOR] call FUNC(takeItem)) then {
				_tohelp call FUNC(RemovePain);
			};
		};
		if ((_toHelp getVariable "ace_w_epi") > 0) then {
			if ([_toHelp, _unit, EPI] call FUNC(takeItem)) then {
				_tohelp call FUNC(RemoveUncon);
			};
		};
	};

	_curDamage = [_toHelp] call ace_sys_wounds_fnc_getDamage;
	_needHeal = [_toHelp] call FUNC(canHeal);
	TRACE_7("Heal?",_toHelp,_unit,_nearMedicFacility,_isMedic,_curDamage,_needHeal,_allowed);

	if (_needHeal && {(_isMedic || {_nearMedicFacility})}) then {
		if ([_toHelp, _unit, KIT] call FUNC(takeItem)) then {
			_leftdamagemodifier = [_unit] call FUNC(getBestNearestMedicalFacility);
			//_vars = [_toHelp];
			//if (_nearMedicFacility) then { PUSH(_vars,0) }; // && _isMed ?? Perhaps in the 'hard-core' version (option)
			//_vars call FUNC(heal);
			[_toHelp,_leftdamagemodifier] call FUNC(heal);
		};
	};
} else {
	// TODO: Support medkit healing
	// TODO: Support checking units for their status, so we don't waste medical items on units that don't need it
	// That's pretty hard though, considering most values needed, are only getable on request..

	if (_isMedic) then {
		_unit playMove "AinvPknlMstpSlayWrflDnon_medic";
		sleep 8;
		if (_unit call FUNC(isUncon) || {!(alive _unit)} || {!isNull(_toHelp getVariable ["ace_w_carry", objNull])}) exitWith { _exit = true };
		if (alive _tohelp) then {
			[_tohelp,0,_bnnnd] call FUNC(animator2);
		};
	} else {
		_allowed = false;
		if ([_toHelp, _unit, _bnnnd] call FUNC(takeItem)) then { _allowed = true } else { if ([_toHelp, _unit, _otherBnnnd] call FUNC(takeItem)) then { _allowed = true } };
		if (_allowed) then {
			_unit playMove "AinvPknlMstpSlayWrflDnon_medic";
			sleep 8;
			if (_unit call FUNC(isUncon) || {!(alive _unit)} || {!isNull(_toHelp getVariable ["ace_w_carry", objNull])}) exitWith { _exit = true }; // TODO: Give back da bandage hmzzzzzz
			if (alive _tohelp) then {
				[_tohelp,0,_bnnnd] call FUNC(animator2);
				if !(_isMedic && {GVAR(medical_oasis)}) then { ["ace_sys_wounds_remove_mag", [_tohelp,_bnnnd]] call ACE_fnc_receiverOnlyEvent };
			};
		};
	};

	if (_exit) exitWith {TRACE_1("Exiting",nil)};

	if (_allowed) then {
		if ([_toHelp, _unit, MOR] call FUNC(takeItem)) then {
			[_tohelp, 1] call FUNC(animator2);
		};
		if ([_toHelp, _unit, EPI] call FUNC(takeItem)) then {
			[_tohelp, 2] call FUNC(animator2);
		};
	};
};

TRACE_2("Setting unbusy",_unit,_toHelp);
_unit setVariable ["ace_w_busy", false, true];
_toHelp setVariable ["ace_w_busy", false, true];
if !(_unit call FUNC(isUncon)) then {
	_unit enableAI "MOVE";
};
