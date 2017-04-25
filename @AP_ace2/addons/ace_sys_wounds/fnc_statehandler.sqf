//#define DEBUG_MODE_FULL
//#define DEBUG_MODE_STATUS
#include "script_component.hpp"
#define DELAY (7 + random 8)
#define CYCLE_TIME 0.15

private ["_unit", "_oldstate", "_nextcrytime", "_state", "_bleed", "_pain", "_btime", "_doexit", "_etime",
	"_whichsound", "_ranval", "_spaction", "_withPMR", "_painExtra", "_bleedExtra", "_lastRequest", "_setSkilled", "_skill","_pun"];

PARAMS_1(_unit);

if (!local _unit) exitWith {};

TRACE_1("statehandler started",_unit);

_oldstate = -1;
_nextcrytime = -1;

waitUntil {(_unit getVariable ["ace_w_state", 0]) > 0 || {!alive _unit}};

if (!alive _unit) exitWith {_unit setVariable ["ace_w_fsm",0]};

if (!isMultiplayer) then {
	_spaction = _unit getVariable ["ace_w_spaction", -9999];
	if (_spaction == -9999) then {
		_spaction = _unit addAction [format[localize "STR_ACE_UA_SPHEAL",name _unit], QPATHTO_C(spheal.sqf), _unit, -1, false, true];
		_unit setVariable ["ace_w_spaction", _spaction];
	};
};

if ((_unit getVariable "ace_w_bleed_add") > 0) then {
	_unit setVariable ["ace_w_bleed", (_unit getVariable ["ace_w_bleed", 0]) max SH_INIT_MIN_BLEED];
};
if ((_unit getVariable "ace_w_pain_add") > 0) then {
	_unit setVariable ["ace_w_pain", (_unit getVariable ["ace_w_pain", 0]) max SH_INIT_MIN_PAIN];
};

_withpmr = false;

if (isPlayer _unit && {!isNil "ace_wounds_prevtime"}) then {
	_withpmr = true;
};

_setSkilled = false;
_lastRequest = time + DELAY;
while {true} do {
	_state = _unit getVariable ["ace_w_state", 0];
	if (isNil "_state") then { _state = 0 };
	_bleed = _unit getVariable ["ace_w_bleed", 0];
	if (isNil "_bleed") then { _bleed = 0 };
	_pain = _unit getVariable ["ace_w_pain", 0];
	if (isNil "_pain") then { _pain = 0 };
	
	#ifdef DEBUG_MODE_STATUS
		diag_log format ["State %1 - Bleed %2 - Pain %3",_state,_bleed,_pain];
	#endif	
	
	_bleedAdd = _unit getVariable ["ace_w_bleed_add", 0];
	if (isNil "_bleedAdd") then { _bleedAdd = 0 };
	_painAdd = _unit getVariable ["ace_w_pain_add", 0];				// This is the pain added every frame for the wounding, since we only use pain once (when shot), we use this as base for calculations
	if (isNil "_painAdd") then { _painAdd = 0 };

	#ifdef DEBUG_MODE_STATUS
		diag_log format ["BleedAdd %1 - PainAdd %2",_bleedAdd,_painAdd];
	#endif	
	
	// Tourniquet stuff
	_CATapplied = _unit getVariable ["ace_w_cat",false]; 		// Check for CAT, if CAT is true, player suffers from increasing pain
	if(isNil "_CATapplied")then{_CATapplied = false;}; //пользовательские переменные, установленные в nil, не возвращают значение по-умолчанию, а возвращают nil
	_CATtime = _unit getVariable ["ace_w_cat_time",0];			// Time when the CAT was applied
	if(isNil "_CATtime")then{_CATtime = 0;}; //пользовательские переменные, установленные в nil, не возвращают значение по-умолчанию, а возвращают nil
	// The pain from wearing the CAT should not start right away, but should start ~ 5 minutes later
	_painCATAdd = if (_CATapplied && {time - _CATtime > CAT_INDUCED_PAIN_DELAY}) then { _painAdd * 0.55 } else { 0 };

	#ifdef DEBUG_MODE_STATUS
		diag_log format ["CAT applied %1 - CAT Time %2 - CAT Pain %3",_CATapplied,_CATtime,_painCATAdd];
	#endif
	
	// Morphine stuff
	// Morphine can cause low pulse (less _bleedAdd), breath shortage (impact on Stamina)
	_MORintoxication = (_unit getVariable ["ace_w_mor_dosage",0])/3 > 3;
	
	_bleedExtra = 0; 	// Extra bloodloss by movement
	_painExtra = 0;		// Extra pain by movement

	// Bloodloss && Pain when moving
	_spd = (velocity _unit) call ACE_fnc_magnitude;
	_veh = (vehicle _unit != _unit) && {isNull (_unit getVariable ["ace_w_carry",objNull])};	
	
	if (_spd > 0.1 && {_spd < 20} && {!_veh}) then {
		if ((GVAR(player_movement_bloodloss) && {isPlayer _unit}) || {GVAR(ai_movement_bloodloss) && {!isPlayer _unit}}) then {
			_bleedExtra = _bleedAdd * _spd * BLOSS_MOVE_COEF; // TODO: This should be default to add bloodloss when moving 
		};
		// Pain added when wearing a CAT is added here aswell
		_painExtra = _painAdd * _spd * PAIN_MOVE_COEF * 3;
	};

	#ifdef DEBUG_MODE_FULL
		_curDam = [_unit] call FUNC(getDamage);
		_body = _unit getVariable ["ace_w_body", 0];
		_head = _unit getVariable ["ace_w_head_hit", 0];
		_hands = _unit getVariable ["ace_w_hands", 0];
		_legs = _unit getVariable ["ace_w_legs", 0];
	#endif
	#define DAMM _body, _head, _hands, _legs
	#define BLEED _bleed, _bleedAdd, _bleedExtra
	#define PAIN _pain, _painAdd
	//TRACE_8("",_unit,alive _unit,_state,damage _unit, _curDam,[BLEED],[PAIN],[DAMM]);
	TRACE_5("",_unit,alive _unit,_state,damage _unit,_curDam);
	TRACE_2("",[BLEED],[PAIN]);
	TRACE_1("",[DAMM]);
	TRACE_2("CAT",_CATapplied,_CATtime);

	// We need a high bloodloss value, but overall bleed should be lower so you have more time to do stuff
	#define __BLEEDXTRAMOD 8
	_unit setVariable ["ace_w_bleed",_bleed + ((_bleedAdd + _bleedExtra)/__BLEEDXTRAMOD)];
	
	_pain = _unit getVariable ["ace_w_pain", 0];
	if (isNil "_pain") then { _pain = 0 };
	_painAdd = _unit getVariable ["ace_w_pain_add", 0]; // TODO: Pain raises too fast
	if (isNil "_painAdd") then { _painAdd = 0 };

	if (_pain < 1) then {
		if (_unit getVariable ["ace_w_mor_dosage",0] == 0) then {
			// Add pain only when moving, i.e moving while being wounded, every step hurts or when a CAT is used
			_unit setVariable ["ace_w_pain", (_pain + _painCATAdd + _painExtra)];
			TRACE_1("MOR active?","No");
		} else {
			//When morphin is active it reduces 0.5 pain that is gained after first morphine dosage, i.e pain from next hit..
			// TODO: Influence morphine metabolism, so morphine looses its effectiveness over time
			// Note: Morphine has no ceiling effect, that means that more morphine does not reduce more pain!
			_unit setVariable ["ace_w_pain", ((_pain + _painCATAdd + _painExtra - .5) max 0)];
			TRACE_1("MOR active?","Yes");
		};
	};

	if (_state >= 800) then {
		if (!_setSkilled && {GVAR(ai_skill_handicap)} && {!isPlayer _unit}) then {
			_setSkilled = true;
			_unit setVariable [QGVAR(skill), skill _unit];
			_skill = (skill _unit) * AI_SKILL_COEF;
			_unit setSkill _skill;
			TRACE_2("SetSkill",_unit,_skill);
		};
	};

	// TODO: Currently this needs 'rebalance', there should be two cases of being uncon:
	//	Uncon by bloodloss
	// 	Uncon by pain (pain should have valuable impact on player: -hard to play under pain, stamina, sideeffects)
	//  Pain > Treshold && Bleed < Treshold should have major impact on gameplay
	// 	Pain < Treshold && Bleed > Treshold -> Uncon = Needs revive
	switch (_state) do {
		case 800: { // bleeding
			if (_state == 800 && {(_bleed > SH_STATE_800_MAX_BLEED || {_pain > SH_STATE_800_MAX_PAIN})}) exitWith {
				_unit setVariable ["ace_w_state",801];
			};
			if (_nextcrytime == -1) then {
				_btime = if (_bleed == 0) then {
					((1 - _pain) * 200) + random 30
				} else {
					((1 - _bleed) * 200) + random 30
				};
				_nextcrytime = time + _btime;
			};
			if (_oldstate != _state && {_unit getVariable "ace_w_state" == 800}) then {_oldstate = _state};
		};
		case 801: { // blackouts every now and then
			if (_state == 801 && {_bleed > SH_STATE_801_MAX_BLEED}) exitWith { // Transition to permanent unconsciousness only caused by bloodloss...
				_unit setVariable ["ace_w_epi",1];
				_unit setVariable ["ace_w_state",802];
			};
			if (_nextcrytime == -1) then {
				_btime = if (_bleed == 0 && {_pain > 0}) then {
					((1 - _pain) * 200) + random 30
				} else {
					if (_pain == 0 && {_bleed > 0}) then {
						((1 - _bleed) * 200) + random 30
					} else {
						100 + random 30
					}
				};
				_nextcrytime = time + _btime;
			};
			if (_unit getVariable "ace_w_state" == 801) then {
				if (time > (_unit getVariable "ace_w_nextuncon") && {!(_unit call FUNC(isUncon))} && {!(_unit getVariable ["ace_w_bout", false])}) then {
					[_unit, 30 + random 30] call FUNC(goUncon);
				};
			};
			if (_oldstate != _state && {_unit getVariable "ace_w_state" == 801}) then {
				_oldstate = _state;
			};
		};
		case 802: { // completely unconscious
			if (_nextcrytime == -1) then {
				if (_bleed > 0.79) then {
					_btime = 3 + (random 3);
					_nextcrytime = time + _btime;
				} else {
					_nextcrytime = -1;
				};
			};
			if (_oldstate != _state && {_unit getVariable "ace_w_state" == 802}) then {
				TRACE_1("Entering 802 State",_unit);
				if !(_unit call FUNC(isUncon)) then {
					[_unit, MAX_UNC_TIME] call FUNC(goUncon);
					if (_withPMR) then {
						if (isPlayer _unit) then {
							if (vehicle _unit == _unit) then {
								_sl = [position _unit, 1] call FUNC(GetSlope);
								if (_sl >= 0.78) then {[position _unit, _sl, _unit] call FUNC(DoSlope)};
							};
						};
					};
				} else {
					_unit setVariable ["ace_w_unconlen", MAX_UNC_TIME];
				};

				if (_withPMR) then {
					if (ace_wounds_prevtime > 0 && {isPlayer _unit}) then {
						if (_unit getVariable "ace_w_revive" == -1) then {
							_unit setVariable ["ace_w_revive", time + ace_wounds_prevtime];
							[QGVAR(rev), [_unit]] call CBA_fnc_localEvent;
						};
					};
				};
				_oldstate = _state;
			};
		};
	};

	_doexit = false;
	if !(_withPMR) then {
		if (_bleed >= 1 || {_MORintoxication} || {!alive _unit}) then {
			if (alive _unit) then {_unit setDamage 1};
			_unit setVariable ["ace_w_state",10000]; // 10000 = dead
			_doexit = true;
		};
	} else {
		if (ace_wounds_prevtime > 0 && {isPlayer _unit}) then {
			_etime = _unit getVariable "ace_w_revive";
			_evactime = _unit getVariable ["ace_w_evactime",0];
			_ropos = position _unit;

			if (isNil QGVAR(no_rpunish)) then {
				_pun = true;
			} else {
				_pun = if (typeName GVAR(no_rpunish) == "BOOL") then { !GVAR(no_rpunish) } else { true };
			};
			if (_etime > -1 && {(time + 5) < _etime} && {!alive _unit} && {!surfaceIsWater _ropos} && {isMultiplayer} && {_pun}) then { // player has hit respawn button == punish him :), no punishment over water surface
				_rdir = direction _unit;
				_rof = _unit distance _ropos;
				_ropos = [_ropos select 0, _ropos select 1, _rof];
				_nrt = (_etime - time) + 5 + _evactime;
				_rhh = _unit getvariable "ace_w_head_hit";
				_rbo = _unit getvariable "ace_w_body";
				_rha = _unit getvariable "ace_w_hands";
				_rle = _unit getvariable "ace_w_legs";
				waitUntil {alive player};
				titleText ["", "BLACK OUT", 3];
				waitUntil {!isNil QGVAR(playerrespawned)};
				GVAR(playerrespawned) = nil;
				_unit = player;
				_unit setVariable ["ace_w_state", 802];
				_unit setVariable ["ace_w_bleed", 0.99];
				_unit setVariable ["ace_w_bleed_add", 0];
				_unit setVariable ["ace_w_pain", 0.99];
				_unit setVariable ["ace_w_pain_add", 0];
				_unit setVariable ["ace_w_epi",1];
				_unit setvariable ["ace_w_head_hit", _rhh];
				_unit setvariable ["ace_w_body", _rbo];
				_unit setvariable ["ace_w_hands", _rha];
				_unit setvariable ["ace_w_legs", _rle];
				_unit setVariable ["ace_w_revive", time + _nrt];
				_unit setVariable ["ace_w_mor_dosage",0]; // cheaters die
				[QGVAR(rev), [_unit]] call CBA_fnc_localEvent;
				_unit setDamage MAX_PMR_DAM;
				_unit setVariable ["ace_w_overall", MAX_PMR_DAM];
				[_unit, MAX_UNC_TIME] call FUNC(goUncon);
				titleText ["", "BLACK IN", 0.5];
				_unit setDir _rdir;
				_unit setPos _rpos;
				_oldstate = 802;
			} else {
				if ((_etime > -1 && {time >= _etime}) || {_MORintoxication} || {!alive _unit}) then {
					if (alive _unit) then {_unit setDamage 1};
					_unit setVariable ["ace_w_state",10000]; // 10000 = dead
					_unit setVariable ["ace_w_revive", -1];
					[QGVAR(rev2), [_unit]] call CBA_fnc_localEvent;
					_doexit = true;
				};
			};
			if (_bleed >= 1) then {
				_unit setVariable ["ace_w_bleed", 0.99];
				_unit setVariable ["ace_w_bleed_add", 0];
			};
			if (_pain >= 1) then {
				_unit setVariable ["ace_w_pain", 0.99];
				_unit setVariable ["ace_w_pain_add", 0];
			};
		} else {
			if (_bleed >= 1 || {_MORintoxication} || {!alive _unit}) then {
				_unit setDamage 1;
				_unit setVariable ["ace_w_state",10000]; // 10000 = dead
				_doexit = true;
			};
		};
	};

	if (_doexit || {_state == 0} || {!(local _unit)}) exitWith { _unit setVariable ["ace_w_fsm",0] };

	if (GVAR(auto_assist) && {time > _lastRequest}) then {
		if (_unit getVariable ["ace_w_requested_help", false]) exitWith {};
		_unit setVariable ["ace_w_requested_help", true];

		switch _state do {
			//case 0: {};
			//case 800: {};
			case 801: {
				if (_unit call FUNC(isUncon)) then {_lastRequest = time + DELAY; [_unit] spawn FUNC(requestAssist)} else {_unit setVariable ["ace_w_requested_help", false]};
			};
			case 802: {
				_lastRequest = time + DELAY; [_unit] spawn FUNC(requestAssist);
			};
			default {
				_unit setVariable ["ace_w_requested_help", false];
			};
		};
	};

	if (_nextcrytime != -1 && {time > _nextcrytime}) then {
		_whichsound = "";
		_ranval = -1;
		if (_unit call FUNC(isUncon)) then { //TODO: Remove the vanilla sounds, when someone is wounded...
			if !(_state in [802]) then {
				_whichsound = "ACE_Suffering%1";
				_ranval = 16;
			} else {
				if (_bleed > 0.8) then {
					_whichsound = "ACE_Drattle%1";
					_ranval = 5;
				};
			};
		} else {
			if (_pain < 0.6) then {
				_whichsound = "ACE_Scream%1";
				_ranval = 333;
			} else {
				_whichsound = "ACE_BrutalScream%1";
				_ranval = 15;
			}
		};
		if (_ranval != -1) then {
			[[_unit], format [_whichsound, ceil(random _ranval)]] call CBA_fnc_globalSay;
		};
		_nextcrytime = -1;
	};
	sleep CYCLE_TIME;
};

if (!isMultiplayer) then {
	if (_spaction != -9999) then {
		if (!isNull _unit) then {
			_unit removeAction _spaction;
			_unit setVariable ["ace_w_spaction", -9999];
		};
	};
};

if (_setSkilled && {alive _unit}) then {
	_skill = _unit getVariable [QGVAR(skill), 0.66];
	_unit setSkill _skill;
	TRACE_2("SetSkill Returned",_unit,_skill);
};

TRACE_1("statehandler exit",_unit);
